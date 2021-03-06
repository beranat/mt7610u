/*
 *************************************************************************
 * Ralink Tech Inc.
 * 5F., No.36, Taiyuan St., Jhubei City,
 * Hsinchu County 302,
 * Taiwan, R.O.C.
 *
 * (c) Copyright 2002-2010, Ralink Technology, Inc.
 *
 * This program is free software; you can redistribute it and/or modify  *
 * it under the terms of the GNU General Public License as published by  *
 * the Free Software Foundation; either version 2 of the License, or     *
 * (at your option) any later version.                                   *
 *                                                                       *
 * This program is distributed in the hope that it will be useful,       *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 * GNU General Public License for more details.                          *
 *                                                                       *
 * You should have received a copy of the GNU General Public License     *
 * along with this program; if not, write to the                         *
 * Free Software Foundation, Inc.,                                       *
 * 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 *                                                                       *
 *************************************************************************/


#ifndef __RTMP_CMD_H__
#define __RTMP_CMD_H__

#include "rtmp_type.h"

struct rtmp_queue_elem {
	UINT command;
	void *buffer;
	ULONG bufferlength;
	bool SetOperation;
	struct rtmp_queue_elem *next;
};

struct rtmp_command_queue {
	UINT size;
	struct rtmp_queue_elem *head;
	struct rtmp_queue_elem *tail;
	u32 CmdQState;
};

#define EnqueueCmd(cmdq, cmdqelmt)		\
{										\
	if (cmdq->size == 0)				\
		cmdq->head = cmdqelmt;			\
	else								\
		cmdq->tail->next = cmdqelmt;	\
	cmdq->tail = cmdqelmt;				\
	cmdqelmt->next = NULL;				\
	cmdq->size++;						\
}

#define NDIS_OID	UINT

/* OS_RTCMDUp is only used in UTIL/NETIF module */
#define OS_RTCMDUp						RtmpOsCmdUp



/* RALINK command status code */
#define RTMP_IO_EINVAL							30000
#define RTMP_IO_EOPNOTSUPP						30001
#define RTMP_IO_EFAULT							30002
#define RTMP_IO_ENETDOWN						30003
#define RTMP_IO_E2BIG							30004
#define RTMP_IO_ENOMEM							30005
#define RTMP_IO_EAGAIN							30006
#define RTMP_IO_ENOTCONN						30007

enum {
	SHOW_CONN_STATUS = 4,
	SHOW_DRVIER_VERION = 5,
	SHOW_BA_INFO = 6,
	SHOW_DESC_INFO = 7,
	SHOW_RXBULK_INFO = 8,
	SHOW_TXBULK_INFO = 9,
	RAIO_OFF = 10,
	RAIO_ON = 11,
#ifdef QOS_DLS_SUPPORT
	SHOW_DLS_ENTRY_INFO = 20,
#endif /* QOS_DLS_SUPPORT */
	SHOW_CFG_VALUE = 21,
	SHOW_ADHOC_ENTRY_INFO = 22,
	SHOW_DEV_INFO = 26,
	SHOW_STA_INFO = 27,
};

#ifdef CONFIG_STA_SUPPORT

#ifdef WPA_SUPPLICANT_SUPPORT
#ifndef NATIVE_WPA_SUPPLICANT_SUPPORT
#define	RT_ASSOC_EVENT_FLAG                         0x0101
#define	RT_DISASSOC_EVENT_FLAG                      0x0102
#define	RT_REQIE_EVENT_FLAG                         0x0103
#define	RT_RESPIE_EVENT_FLAG                        0x0104
#define	RT_ASSOCINFO_EVENT_FLAG                     0x0105
#define RT_PMKIDCAND_FLAG                           0x0106
#define RT_INTERFACE_DOWN                           0x0107
#define RT_INTERFACE_UP                             0x0108
#endif /* NATIVE_WPA_SUPPLICANT_SUPPORT */
#endif /* WPA_SUPPLICANT_SUPPORT */
#endif /* CONFIG_STA_SUPPORT */

/* RALINK command handle ID */
/* ap commands */
typedef enum _CMD_RTPRIV_IOCTL_AP {

	/* general */
	CMD_RTPRIV_IOCTL_SET_WSCOOB = 0x0001,
	CMD_RTPRIV_IOCTL_GET_MAC_TABLE,
	CMD_RTPRIV_IOCTL_STATISTICS,
	CMD_RTPRIV_IOCTL_QUERY_BATABLE,
	CMD_RTPRIV_IOCTL_RF,
	CMD_RTPRIV_IOCTL_SET,
	CMD_RTPRIV_IOCTL_GET_AR9_SHOW,
	CMD_RTPRIV_IOCTL_CHID_2_FREQ,
	CMD_RTPRIV_IOCTL_FREQ_2_CHID,
	CMD_RTPRIV_IOCTL_GET_MAC_TABLE_STRUCT,

	/* mbss */
	CMD_RTPRIV_IOCTL_MBSS_BEACON_UPDATE,
	CMD_RTPRIV_IOCTL_MBSS_OPEN,
	CMD_RTPRIV_IOCTL_MBSS_CLOSE,
	CMD_RTPRIV_IOCTL_MBSS_INIT,
	CMD_RTPRIV_IOCTL_MBSS_REMOVE,

	/* wsc */
	CMD_RTPRIV_IOCTL_WSC_PROFILE,
	CMD_RTPRIV_IOCTL_WSC_INIT,

	/* apc */
	CMD_RTPRIV_IOCTL_APC_UP,
	CMD_RTPRIV_IOCTL_APC_DISCONNECT,
	CMD_RTPRIV_IOCTL_APC_INIT,
	CMD_RTPRIV_IOCTL_APC_OPEN,
	CMD_RTPRIV_IOCTL_APC_CLOSE,
	CMD_RTPRIV_IOCTL_APC_REMOVE,

	/* interface */
	CMD_RTPRIV_IOCTL_MAIN_OPEN,

	/* ioctl */
	CMD_RTPRIV_IOCTL_PREPARE,
	CMD_RTPRIV_IOCTL_AP_SIOCGIWAP,
	CMD_RTPRIV_IOCTL_AP_SIOCGIFHWADDR,
	CMD_RTPRIV_IOCTL_AP_SIOCGIWESSID,
	CMD_RTPRIV_IOCTL_AP_SIOCGIWRATEQ,
	CMD_RTPRIV_IOCTL_AP_SIOCSIWGENIE,

	/* can not exceed 0x5000 */
} CMD_RTPRIV_IOCTL_AP;

/* common commands */
typedef enum _CMD_RTPRIV_IOCTL_COMMON {

	/* general */
	CMD_RTPRIV_IOCTL_NETDEV_GET = 0x5000,
	CMD_RTPRIV_IOCTL_NETDEV_SET,
	CMD_RTPRIV_IOCTL_OPMODE_GET,
	CMD_RTPRIV_IOCTL_TASK_LIST_GET,
	CMD_RTPRIV_IOCTL_IRQ_INIT,
	CMD_RTPRIV_IOCTL_IRQ_RELEASE,
	CMD_RTPRIV_IOCTL_MSI_ENABLE,
	CMD_RTPRIV_IOCTL_NIC_NOT_EXIST,
	CMD_RTPRIV_IOCTL_MCU_SLEEP_CLEAR,
//#ifdef CONFIG_STA_SUPPORT
	CMD_RTPRIV_IOCTL_ADAPTER_SUSPEND_SET,
	CMD_RTPRIV_IOCTL_ADAPTER_SUSPEND_CLEAR,
	CMD_RTPRIV_IOCTL_ADAPTER_SEND_DISSASSOCIATE,
	CMD_RTPRIV_IOCTL_ADAPTER_SUSPEND_TEST,
	CMD_RTPRIV_IOCTL_ADAPTER_IDLE_RADIO_OFF_TEST,
	CMD_RTPRIV_IOCTL_ADAPTER_RT28XX_USB_ASICRADIO_OFF,
	CMD_RTPRIV_IOCTL_ADAPTER_RT28XX_USB_ASICRADIO_ON,
	CMD_RTPRIV_IOCTL_AP_BSSID_GET,
//#endif /* CONFIG_STA_SUPPORT */
	CMD_RTPRIV_IOCTL_SANITY_CHECK,
	CMD_RTPRIV_IOCTL_SANITY_CHECK_ON_SET_CMD,
#ifdef EXT_BUILD_CHANNEL_LIST
	CMD_RTPRIV_SET_PRECONFIG_VALUE,
#endif /* EXT_BUILD_CHANNEL_LIST */


	/* mesh */
	CMD_RTPRIV_IOCTL_MESH_INIT,
	CMD_RTPRIV_IOCTL_MESH_REMOVE,
	CMD_RTPRIV_IOCTL_MESH_OPEN_PRE,
	CMD_RTPRIV_IOCTL_MESH_OPEN_POST,
	CMD_RTPRIV_IOCTL_MESH_IS_VALID,
	CMD_RTPRIV_IOCTL_MESH_CLOSE,

	/* p2p */
	CMD_RTPRIV_IOCTL_P2P_INIT,
	CMD_RTPRIV_IOCTL_P2P_REMOVE,
	CMD_RTPRIV_IOCTL_P2P_OPEN_PRE,
	CMD_RTPRIV_IOCTL_P2P_OPEN_POST,
	CMD_RTPRIV_IOCTL_P2P_IS_VALID,
	CMD_RTPRIV_IOCTL_P2P_CLOSE,

	/* usb */
	CMD_RTPRIV_IOCTL_USB_CONFIG_INIT,
	CMD_RTPRIV_IOCTL_USB_SUSPEND,
	CMD_RTPRIV_IOCTL_USB_RESUME,

	/* pci */
	CMD_RTPRIV_IOCTL_PCI_SUSPEND,
	CMD_RTPRIV_IOCTL_PCI_RESUME,
	CMD_RTPRIV_IOCTL_PCI_CSR_SET,
	CMD_RTPRIV_IOCTL_PCIE_INIT,

	/* cfg80211 */
	CMD_RTPRIV_IOCTL_CFG80211_CFG_START,

	/* inf ppa */
	CMD_RTPRIV_IOCTL_INF_PPA_INIT,
	CMD_RTPRIV_IOCTL_INF_PPA_EXIT,

	/* wireless */
	CMD_RTPRIV_IOCTL_BEACON_UPDATE,
	CMD_RTPRIV_IOCTL_RXPATH_GET,
	CMD_RTPRIV_IOCTL_CHAN_LIST_NUM_GET,
	CMD_RTPRIV_IOCTL_CHAN_LIST_GET,
	CMD_RTPRIV_IOCTL_FREQ_LIST_GET,

	/* interface */
	CMD_RTPRIV_IOCTL_VIRTUAL_INF_UP,
	CMD_RTPRIV_IOCTL_VIRTUAL_INF_DOWN,
	CMD_RTPRIV_IOCTL_VIRTUAL_INF_GET,
	CMD_RTPRIV_IOCTL_INF_TYPE_GET,
	CMD_RTPRIV_IOCTL_INF_STATS_GET,
	CMD_RTPRIV_IOCTL_INF_IW_STATUS_GET,
	CMD_RTPRIV_IOCTL_INF_MAIN_CREATE,
	CMD_RTPRIV_IOCTL_INF_MAIN_CHECK,
	CMD_RTPRIV_IOCTL_INF_P2P_CHECK,

	/* ioctl */
	CMD_RTPRIV_IOCTL_SIOCGIWFREQ,
	CMD_RTPRIV_IOCTL_SIOCGIWNAME,

	/* wds */
	CMD_RTPRIV_IOCTL_WDS_INIT,
	CMD_RTPRIV_IOCTL_WDS_REMOVE,
	CMD_RTPRIV_IOCTL_WDS_STATS_GET,

	CMD_RTPRIV_IOCTL_MAC_ADDR_GET,

#ifdef RT_CFG80211_SUPPORT
	/* cfg802.11 */
	/* Note: All cfg commands must be continue. */
	CMD_RTPRIV_IOCTL_80211_START,
	CMD_RTPRIV_IOCTL_80211_CB_GET,
	CMD_RTPRIV_IOCTL_80211_CB_SET,
	CMD_RTPRIV_IOCTL_80211_CHAN_SET,
	CMD_RTPRIV_IOCTL_80211_VIF_CHG,
	CMD_RTPRIV_IOCTL_80211_SCAN,
	CMD_RTPRIV_IOCTL_80211_IBSS_JOIN,
	CMD_RTPRIV_IOCTL_80211_STA_LEAVE,
	CMD_RTPRIV_IOCTL_80211_STA_GET,
	CMD_RTPRIV_IOCTL_80211_KEY_ADD,
	CMD_RTPRIV_IOCTL_80211_KEY_DEFAULT_SET,
	CMD_RTPRIV_IOCTL_80211_CONNECT_TO,
	CMD_RTPRIV_IOCTL_80211_RFKILL,
	CMD_RTPRIV_IOCTL_80211_REG_NOTIFY_TO,
	CMD_RTPRIV_IOCTL_80211_UNREGISTER,
	CMD_RTPRIV_IOCTL_80211_BANDINFO_GET,
	CMD_RTPRIV_IOCTL_80211_SURVEY_GET,
	CMD_RTPRIV_IOCTL_80211_EXTRA_IES_SET,
	CMD_RTPRIV_IOCTL_80211_REMAIN_ON_CHAN_SET,
	CMD_RTPRIV_IOCTL_80211_MGMT_FRAME_REG,
	CMD_RTPRIV_IOCTL_80211_CHANNEL_LOCK,
	CMD_RTPRIV_IOCTL_80211_MGMT_FRAME_SEND,
	CMD_RTPRIV_IOCTL_80211_REMAIN_ON_CHAN_DUR_TIMER_INIT,
	CMD_RTPRIV_IOCTL_80211_CHANNEL_LIST_SET,
	CMD_RTPRIV_IOCTL_80211_ACTION_FRAME_REG,
	CMD_RTPRIV_IOCTL_80211_BEACON_ADD,
	CMD_RTPRIV_IOCTL_80211_BEACON_SET,
	CMD_RTPRIV_IOCTL_80211_BEACON_DEL,
	CMD_RTPRIV_IOCTL_80211_AP_KEY_ADD,
	CMD_RTPRIV_IOCTL_80211_CHANGE_BSS_PARM,
	CMD_RTPRIV_IOCTL_80211_AP_KEY_DEL,
	CMD_RTPRIV_IOCTL_80211_AP_PROBE_RSP,
	CMD_RTPRIV_IOCTL_80211_PORT_SECURED,
	CMD_RTPRIV_IOCTL_80211_AP_STA_DEL,
	CMD_RTPRIV_IOCTL_80211_CANCEL_REMAIN_ON_CHAN_SET,
	CMD_RTPRIV_IOCTL_80211_BITRATE_SET,
#ifdef RT_P2P_SPECIFIC_WIRELESS_EVENT
	CMD_RTPRIV_IOCTL_80211_SEND_WIRELESS_EVENT,
#endif /* RT_P2P_SPECIFIC_WIRELESS_EVENT */
	CMD_RTPRIV_IOCTL_80211_END,
#endif /* RT_CFG80211_SUPPORT */

	CMD_RTPRIV_IOCTL_ADAPTER_CSO_SUPPORT_TEST,
	CMD_RTPRIV_IOCTL_ADAPTER_TSO_SUPPORT_TEST,

	/* can not exceed 0xa000 */
	CMD_RTPRIV_IOCTL_80211_COM_LATEST_ONE,
} CMD_RTPRIV_IOCTL_COMMON;

#ifdef RT_CFG80211_SUPPORT
typedef struct __CMD_RTPRIV_IOCTL_80211_VIF_SET {
	INT  vifType;
	char vifName[IFNAMSIZ];
	INT  vifNameLen;
} CMD_RTPRIV_IOCTL_80211_VIF_SET;

typedef struct __CMD_RTPRIV_IOCTL_80211_BSS_PARM {
	INT   use_cts_prot;
	INT   use_short_preamble;
	INT   use_short_slot_time;
	u8 *basic_rates;
	u8 basic_rates_len;
	INT   ap_isolate;
	INT   ht_opmode;

} CMD_RTPRIV_IOCTL_80211_BSS_PARM;

typedef struct __CMD_RTPRIV_IOCTL_80211_BEACON {
        INT32 interval;
        INT32 dtim_period;
        u8 *beacon_head;
		u8 *beacon_tail;
        u32 beacon_head_len; /* Before TIM IE */
		u32 beacon_tail_len; /* After TIM IE */

	u8 *beacon_ies;
	u32 beacon_ies_len;
	u8 *proberesp_ies;
	u32 proberesp_ies_len;
	u8 *assocresp_ies;
	u32 assocresp_ies_len;
	u8 *probe_resp;
	u32 probe_resp_len;
	ULONG ssid_len;
	u8 hidden_ssid;
	struct cfg80211_crypto_settings crypto;
	bool privacy;
	u8 auth_type;
	INT32 inactivity_timeout;
} CMD_RTPRIV_IOCTL_80211_BEACON;

typedef struct __CMD_RTPRIV_IOCTL_80211_CHAN {

	u8 ChanId;

#define RT_CMD_80211_IFTYPE_STATION		0x00
#define RT_CMD_80211_IFTYPE_ADHOC		0x01
#define RT_CMD_80211_IFTYPE_MONITOR		0x02
	u8 IfType;

#define RT_CMD_80211_CHANTYPE_NOHT		0x00
#define RT_CMD_80211_CHANTYPE_HT20		0x01
#define RT_CMD_80211_CHANTYPE_HT40MINUS	0X02
#define RT_CMD_80211_CHANTYPE_HT40PLUS	0X03
	u8 ChanType;

	u32 MonFilterFlag;

} CMD_RTPRIV_IOCTL_80211_CHAN;

#define RT_CMD_80211_FILTER_FCSFAIL		0x01
#define RT_CMD_80211_FILTER_PLCPFAIL	0x02
#define RT_CMD_80211_FILTER_CONTROL		0x04
#define RT_CMD_80211_FILTER_OTHER_BSS	0x08

typedef struct __CMD_RTPRIV_IOCTL_80211_IBSS {
	u32 BeaconInterval;
	u8 *pSsid;
} CMD_RTPRIV_IOCTL_80211_IBSS;

typedef struct __CMD_RTPRIV_IOCTL_80211_STA {

	u8 MAC[6];
	ULONG DataRate;

#define RT_CMD_80211_TXRATE_LEGACY		0x01
#define RT_CMD_80211_TXRATE_BW_40		0x02
#define RT_CMD_80211_TXRATE_SHORT_GI	0x04
	u32 TxRateFlags;

	u32 TxRateMCS;
	INT32 Signal;
	u32 TxPacketCnt;
	u32 InactiveTime;
} CMD_RTPRIV_IOCTL_80211_STA;

/*typedef struct __CMD_RTPRIV_IOCTL_80211_KEY {

#define RT_CMD_80211_KEY_WEP			0x00
#define RT_CMD_80211_KEY_WPA			0x01
	u8 KeyType;
	u8 KeyBuf[50];
	u8 KeyId;
} CMD_RTPRIV_IOCTL_80211_KEY;*/

#define RT_CMD_80211_KEY_WEP40			0x00
#define RT_CMD_80211_KEY_WEP104			0x01
#define RT_CMD_80211_KEY_WPA			0x02
#ifdef DOT11W_PMF_SUPPORT
#define RT_CMD_80211_KEY_AES_CMAC	0x03
#endif /* DOT11W_PMF_SUPPORT */

typedef struct __CMD_RTPRIV_IOCTL_80211_KEY {
	u8 KeyType;
	u8 KeyBuf[50];
	u8 KeyId;
	bool bPairwise;
	u8 KeyLen;
	u32 cipher;
	u8 MAC[ETH_LENGTH_OF_ADDRESS];
} CMD_RTPRIV_IOCTL_80211_KEY;


#define RT_CMD_80211_CONN_ENCRYPT_NONE	0x01
#define RT_CMD_80211_CONN_ENCRYPT_WEP	0x02
#define RT_CMD_80211_CONN_ENCRYPT_TKIP	0x04
#define RT_CMD_80211_CONN_ENCRYPT_CCMP	0x08

typedef struct __CMD_RTPRIV_IOCTL_80211_CONNECT {

	u8 WpaVer;
	bool FlgIs8021x;
	u8 AuthType;
	//bool FlgIsAuthOpen;

	u8 PairwiseEncrypType;
	u8 GroupwiseEncrypType;

	u8 *Key;
	u32 KeyLen;
	u8 KeyIdx;

	u8 *pSsid;
	u32 SsidLen;




	u8 Bssid[ETH_ALEN];

	bool bWpsConnection;
#ifdef DOT11W_PMF_SUPPORT
	bool mfp;
#endif /* DOT11W_PMF_SUPPORT */

} CMD_RTPRIV_IOCTL_80211_CONNECT;

typedef struct __CMD_RTPRIV_IOCTL_80211_REG_NOTIFY {

	u8 Alpha2[2];
	void *pWiphy;
} CMD_RTPRIV_IOCTL_80211_REG_NOTIFY;

typedef struct __CMD_RTPRIV_IOCTL_80211_SURVEY {

	void *pCfg80211;
/*	UINT64 ChannelTime; */ /* idle + busy, not support */
	UINT64 ChannelTimeBusy;
	UINT64 ChannelTimeExtBusy;
} CMD_RTPRIV_IOCTL_80211_SURVEY;

#endif /* RT_CFG80211_SUPPORT */

/* station commands */
#ifdef CONFIG_STA_SUPPORT
typedef enum _CMD_RTPRIV_IOCTL_STATION {

	/* general */
	CMD_RTPRIV_IOCTL_SITESURVEY_GET  = 0xa000,
	CMD_RTPRIV_IOCTL_SITESURVEY,
	CMD_RTPRIV_IOCTL_ORI_DEV_TYPE_SET,
	CMD_RTPRIV_IOCTL_STA_SCAN_SANITY_CHECK,
	CMD_RTPRIV_IOCTL_STA_SCAN_END,

	/* wireless */
	CMD_RTPRIV_IOCTL_BSS_LIST_GET,

	/* standard ioctl */
	CMD_RTPRIV_IOCTL_STA_SIOCSIWFREQ,
	CMD_RTPRIV_IOCTL_STA_SIOCGIWFREQ,
	CMD_RTPRIV_IOCTL_STA_SIOCSIWMODE,
	CMD_RTPRIV_IOCTL_STA_SIOCGIWMODE,
	CMD_RTPRIV_IOCTL_STA_SIOCSIWAP,
	CMD_RTPRIV_IOCTL_STA_SIOCGIWAP,
	CMD_RTPRIV_IOCTL_STA_SIOCSIWSCAN,
	CMD_RTPRIV_IOCTL_STA_SIOCGIWSCAN,
	CMD_RTPRIV_IOCTL_STA_SIOCSIWESSID,
	CMD_RTPRIV_IOCTL_STA_SIOCGIWESSID,
	CMD_RTPRIV_IOCTL_STA_SIOCSIWNICKN,
	CMD_RTPRIV_IOCTL_STA_SIOCGIWNICKN,
	CMD_RTPRIV_IOCTL_STA_SIOCSIWRTS,
	CMD_RTPRIV_IOCTL_STA_SIOCGIWRTS,
	CMD_RTPRIV_IOCTL_STA_SIOCSIWFRAG,
	CMD_RTPRIV_IOCTL_STA_SIOCGIWFRAG,
	CMD_RTPRIV_IOCTL_STA_SIOCSIWENCODE,
	CMD_RTPRIV_IOCTL_STA_SIOCGIWENCODE,
	CMD_RTPRIV_IOCTL_STA_SIOCSIWMLME,
	CMD_RTPRIV_IOCTL_STA_SIOCSIWAUTH,
	CMD_RTPRIV_IOCTL_STA_SIOCGIWAUTH,
	CMD_RTPRIV_IOCTL_STA_SIOCSIWENCODEEXT,
	CMD_RTPRIV_IOCTL_STA_SIOCGIWENCODEEXT,
	CMD_RTPRIV_IOCTL_STA_SIOCSIWGENIE,
	CMD_RTPRIV_IOCTL_STA_SIOCGIWGENIE,
	CMD_RTPRIV_IOCTL_STA_SIOCSIWPMKSA,
	CMD_RTPRIV_IOCTL_STA_SIOCSIWRATE,
	CMD_RTPRIV_IOCTL_STA_SIOCGIWRATE,
	CMD_RTPRIV_IOCTL_STA_SIOCGIFHWADDR,
	CMD_RTPRIV_IOCTL_STA_SIOCSIWPRIVRSSI,

	CMD_RTPRIV_IOCTL_STA_IW_SET_WSC_U32_ITEM,
	CMD_RTPRIV_IOCTL_STA_IW_SET_WSC_STR_ITEM,
} CMD_RTPRIV_IOCTL_STATION;

#define RT_CMD_MODE_ADHOC								0x01
#define RT_CMD_MODE_INFRA								0x02
#define RT_CMD_MODE_MONITOR								0x03
#endif /* CONFIG_STA_SUPPORT */

/* when adding any new type, please also add codes in LINUX_WEVENT_TRANSLATE */
#define RT_WLAN_EVENT_CUSTOM							0x01
#define RT_WLAN_EVENT_CGIWAP							0x02
#define RT_WLAN_EVENT_ASSOC_REQ_IE						0x03
#define RT_WLAN_EVENT_SCAN								0x04
#define RT_WLAN_EVENT_EXPIRED							0x05
#define RT_WLAN_EVENT_SHOWPIN							0x06
#define RT_WLAN_EVENT_PIN							0x07

typedef struct __RT_CMD_RATE_SET {
	IN u32 Rate;
	IN u32 Fixed;
} RT_CMD_RATE_SET;

typedef struct __RT_CMD_PARAM_SET {
	IN char *pThisChar;
	IN char *pValue;
} RT_CMD_PARAM_SET;

typedef struct __RT_CMD_SHARED_KEY_ADD {
	IN u8 KeyIdx;
	IN bool FlgHaveGTK;
} RT_CMD_SHARED_KEY_ADD;

typedef struct __RT_CMD_MBSS_KICKOUT {
	IN INT BssId;
	IN USHORT Reason;
} RT_CMD_MBSS_KICKOUT;

typedef struct __RT_CMD_USB_DEV_CONFIG {
	u8 in_eps[2];
	u16 in_max_packet;
	u8 out_eps[6];
	u16 out_max_packet;
} RT_CMD_USB_DEV_CONFIG;

typedef struct __RT_CMD_CFG80211_CONFIG {
	IN void *pCfgDev;
	IN void(
	*CFG80211_Register) (
	IN void * pAd,
	IN void * pDev,
	IN void * pNetDev);
} RT_CMD_CFG80211_CONFIG;

typedef struct __RT_CMD_WAIT_QUEUE_LIST {
	OUT RTMP_OS_TASK *pMlmeTask;
	OUT RTMP_OS_TASK *pTimerTask;
	OUT RTMP_OS_TASK *pCmdQTask;
	OUT RTMP_OS_TASK *pWscTask;
} RT_CMD_WAIT_QUEUE_LIST;

typedef struct __RT_CMD_INF_UP_DOWN {

	IN	int (*rt28xx_open)(struct net_device *net_dev);
	IN	int (*rt28xx_close)(struct net_device *net_dev);
} RT_CMD_INF_UP_DOWN;

typedef struct __RT_CMD_STATS {
	IN struct net_device *pNetDev;
	OUT void *pStats;	/* point to pAd->stats */

	OUT unsigned long rx_packets;	/* total packets received       */
	OUT unsigned long tx_packets;	/* total packets transmitted */
	OUT unsigned long rx_bytes;	/* total bytes received         */
	OUT unsigned long tx_bytes;	/* total bytes transmitted      */
	OUT unsigned long rx_errors;	/* bad packets received         */
	OUT unsigned long tx_errors;	/* packet transmit problems     */
	OUT unsigned long multicast;	/* multicast packets received */
	OUT unsigned long collisions;

	OUT unsigned long rx_over_errors;	/* receiver ring buff overflow  */
	OUT unsigned long rx_crc_errors;	/* recved pkt with crc error    */
	OUT unsigned long rx_frame_errors;	/* recv'd frame alignment error */
	OUT unsigned long rx_fifo_errors;	/* recv'r fifo overrun                  */
} RT_CMD_STATS;

struct RT_CMD_IW_STATS {

	u32 priv_flags;
	u8 *dev_addr;

	struct iw_statistics *pStats;		/* point to pAd->iw_stats */

	u8 qual;
	u8 level;
	u8 noise;
	u8 updated;
};

typedef struct __RT_CMD_PCIE_INIT {

	IN void *pPciDev;
	IN u32 ConfigDeviceID;
	IN u32 ConfigSubsystemVendorID;
	IN u32 ConfigSubsystemID;
} RT_CMD_PCIE_INIT;

typedef struct __RT_CMD_AP_IOCTL_CONFIG {
	IN void *net_dev;
	IN ULONG priv_flags;
	IN char *pCmdData;
	IN INT32 CmdId_RTPRIV_IOCTL_SET;
	IN char *name;
	IN INT apidx;

	OUT INT32 Status;
} RT_CMD_AP_IOCTL_CONFIG;

typedef struct __RT_CMD_AP_IOCTL_SSID {
	IN ULONG priv_flags;
	IN INT apidx;

	OUT char *pSsidStr;
	OUT INT32 length;
} RT_CMD_AP_IOCTL_SSID;

typedef struct __RT_CMD_IOCTL_RATE {
	IN ULONG priv_flags;
	OUT u32 BitRate;
} RT_CMD_IOCTL_RATE;

#define RTMP_CMD_STA_MODE_AUTO			0x00
#define RTMP_CMD_STA_MODE_ADHOC			0x01
#define RTMP_CMD_STA_MODE_INFRA			0x02
#define RTMP_CMD_STA_MODE_MONITOR		0x03

typedef struct __RT_CMD_STA_IOCTL_FREQ {
	IN INT32 m;		/* Mantissa */
	IN INT16 e;		/* Exponent */
} RT_CMD_STA_IOCTL_FREQ;

typedef struct __RT_CMD_STA_IOCTL_BSS {
	OUT u8 Bssid[6];
	OUT u8 ChannelQuality;
	OUT CHAR Rssi;
	OUT CHAR Noise;
} RT_CMD_STA_IOCTL_BSS;

typedef struct __RT_CMD_STA_IOCTL_BSS_LIST {
	IN u32 MaxNum;
	OUT u32 BssNum;
	OUT RT_CMD_STA_IOCTL_BSS *pList;
} RT_CMD_STA_IOCTL_BSS_LIST;

typedef struct __RT_CMD_STA_IOCTL_SCAN {
	IN u8 FlgScanThisSsid;
	IN u32 SsidLen;
	IN CHAR *pSsid;
	OUT INT32 Status;
} RT_CMD_STA_IOCTL_SCAN;

typedef struct __RT_CMD_STA_IOCTL_BSS_TABLE {
	OUT u8 Bssid[6];
	OUT u8 Channel;
	OUT u8 BssType;
	OUT u8 HtCapabilityLen;

	OUT u8 SupRate[12];
	OUT u8 SupRateLen;
	OUT u8 ExtRate[12];
	OUT u8 ExtRateLen;

	OUT u8 SsidLen;
	OUT CHAR Ssid[32];

	OUT USHORT CapabilityInfo;
	OUT u8 ChannelWidth, ShortGIfor40, ShortGIfor20, MCSSet;

	OUT USHORT WpaIeLen;
	OUT u8 *pWpaIe;

	OUT USHORT RsnIeLen;
	OUT u8 *pRsnIe;

	OUT USHORT WpsIeLen;
	OUT u8 *pWpsIe;

	OUT u8 FlgIsPrivacyOn;

	OUT RT_CMD_STA_IOCTL_BSS Signal;
} RT_CMD_STA_IOCTL_BSS_TABLE;

typedef struct __RT_CMD_STA_IOCTL_SCAN_TABLE {
	IN ULONG priv_flags;
	OUT u32 BssNr;
	OUT RT_CMD_STA_IOCTL_BSS_TABLE *pBssTable;	/* must be freed by caller */
	OUT u8 MainSharedKey[4][16];
} RT_CMD_STA_IOCTL_SCAN_TABLE;

typedef struct __RT_CMD_STA_IOCTL_SSID {
	IN u8 FlgAnySsid;
	INOUT u32 SsidLen;
	INOUT CHAR *pSsid;
	OUT INT32 Status;
} RT_CMD_STA_IOCTL_SSID;

typedef struct __RT_CMD_STA_IOCTL_NICK_NAME {
	OUT UINT NameLen;
	OUT CHAR *pName;
} RT_CMD_STA_IOCTL_NICK_NAME;

typedef struct __RT_CMD_STA_IOCTL_SECURITY {
	INOUT CHAR *pData;
	INOUT UINT16 length;
	IN INT32 KeyIdx;
	IN INT32 MaxKeyLen;

#define RT_CMD_STA_IOCTL_SECURITY_ALG_NONE		0x01
#define RT_CMD_STA_IOCTL_SECURITY_ALG_WEP		0x02
#define RT_CMD_STA_IOCTL_SECURITY_ALG_TKIP		0x03
#define RT_CMD_STA_IOCTL_SECURITY_ALG_CCMP		0x04
	IN u32 Alg;

#define RT_CMD_STA_IOCTL_SECURTIY_EXT_SET_TX_KEY	0x01
#define RT_CMD_STA_IOCTL_SECURTIY_EXT_GROUP_KEY		0x02
	IN UINT16 ext_flags;

#define RT_CMD_STA_IOCTL_SECURITY_DISABLED		0x01
#define RT_CMD_STA_IOCTL_SECURITY_ENABLED		0x02
#define RT_CMD_STA_IOCTL_SECURITY_RESTRICTED	0x04
#define RT_CMD_STA_IOCTL_SECURITY_OPEN			0x08
#define RT_CMD_STA_IOCTL_SECURITY_NOKEY			0x10
#define RT_CMD_STA_IOCTL_SECURITY_MODE			0x20
	INOUT UINT16 flags;

	OUT INT32 Status;
} RT_CMD_STA_IOCTL_SECURITY;

typedef struct __RT_CMD_STA_IOCTL_WSC_U32_ITEM {
	IN u32 *pUWrq;
	OUT INT32 Status;
} RT_CMD_STA_IOCTL_WSC_U32_ITEM;

typedef struct __RT_CMD_STA_IOCTL_WSC_STR_ITEM {
	IN u32 Subcmd;
	IN CHAR *pData;
	IN u32 length;

	OUT INT32 Status;
} RT_CMD_STA_IOCTL_WSC_STR_ITEM;

typedef struct __RT_CMD_STA_IOCTL_SHOW {
	IN CHAR *pData;
	IN u32 MaxSize;
	IN u32 InfType;
} RT_CMD_STA_IOCTL_SHOW;

#define RT_CMD_STA_IOCTL_IW_MLME_DEAUTH		0x01
#define RT_CMD_STA_IOCTL_IW_MLME_DISASSOC	0x02

typedef struct __RT_CMD_STA_IOCTL_SECURITY_ADV {

#define RT_CMD_STA_IOCTL_WPA_VERSION					0x10
#define RT_CMD_STA_IOCTL_WPA_VERSION1				0x11
#define RT_CMD_STA_IOCTL_WPA_VERSION2				0x12

#define RT_CMD_STA_IOCTL_WPA_PAIRWISE					0x20
#define RT_CMD_STA_IOCTL_WPA_PAIRWISE_NONE			0x21
#define RT_CMD_STA_IOCTL_WPA_PAIRWISE_WEP40			0x22
#define RT_CMD_STA_IOCTL_WPA_PAIRWISE_WEP104		0x23
#define RT_CMD_STA_IOCTL_WPA_PAIRWISE_TKIP			0x24
#define RT_CMD_STA_IOCTL_WPA_PAIRWISE_CCMP			0x25

#define RT_CMD_STA_IOCTL_WPA_GROUP						0x30
#define RT_CMD_STA_IOCTL_WPA_GROUP_NONE				0x31
#define RT_CMD_STA_IOCTL_WPA_GROUP_WEP40			0x32
#define RT_CMD_STA_IOCTL_WPA_GROUP_WEP104			0x33
#define RT_CMD_STA_IOCTL_WPA_GROUP_TKIP				0x34
#define RT_CMD_STA_IOCTL_WPA_GROUP_CCMP				0x35

#define RT_CMD_STA_IOCTL_WPA_KEY_MGMT					0x40
#define RT_CMD_STA_IOCTL_WPA_KEY_MGMT_1X			0x41
#define RT_CMD_STA_IOCTL_WPA_KEY_MGMT_WPS			0x42

#define RT_CMD_STA_IOCTL_WPA_AUTH_RX_UNENCRYPTED_EAPOL	0x50
#define RT_CMD_STA_IOCTL_WPA_AUTH_PRIVACY_INVOKED		0x60
#define RT_CMD_STA_IOCTL_WPA_AUTH_DROP_UNENCRYPTED		0x70

#define RT_CMD_STA_IOCTL_WPA_AUTH_80211_AUTH_ALG		0x80
#define RT_CMD_STA_IOCTL_WPA_AUTH_80211_AUTH_ALG_SHARED		0x81
#define RT_CMD_STA_IOCTL_WPA_AUTH_80211_AUTH_ALG_OPEN		0x82
#define RT_CMD_STA_IOCTL_WPA_AUTH_80211_AUTH_ALG_LEAP		0x83

#define RT_CMD_STA_IOCTL_WPA_AUTH_WPA_ENABLED			0x90
	IN u32 flags;
	IN u32 value;
} RT_CMD_STA_IOCTL_SECURITY_ADV;

typedef struct __RT_CMD_STA_IOCTL_RSN_IE {
	INOUT u32 length;
	INOUT u8 *pRsnIe;
} RT_CMD_STA_IOCTL_RSN_IE;

typedef struct __RT_CMD_STA_IOCTL_PMA_SA {
#define RT_CMD_STA_IOCTL_PMA_SA_FLUSH					0x01
#define RT_CMD_STA_IOCTL_PMA_SA_REMOVE					0x02
#define RT_CMD_STA_IOCTL_PMA_SA_ADD						0x03
	IN u32 Cmd;
	IN u8 Bssid[ETH_ALEN];
	IN u8 Pmkid[IW_PMKID_LEN];
} RT_CMD_STA_IOCTL_PMA_SA;

#endif /* __RTMP_CMD_H__ */
