/****************************************************************************
*                                                                           *
*  File Name:           ieee802dot11.h                                      *
*  Used By:                                                                 *
*                                                                           *
*  Operating System:                                                        *
*  Purpose:                                                                 *
*                                                                           *
*  Comments:                                                                *
*                                                                           *
*  Author:              Larry Simmons                                       *
*                       lsimmons@avantcom.com                               *
*                       www.avantcom.com                                    *
*                                                                           *
*  Creation Date:       09/02/03                                            *
*                                                                           *
*   Ver    Date   Inits Modification                                        *
*  ----- -------- ----- ------------                                        *
*  0.0.1 09/02/03  LRS  created                                             *
*  0.0.2 09/24/03  LRS  wouldn't build after fresh ./configure              *
****************************************************************************/
/* This file was generated by mib2c and is intended for use as a mib module
  for the ucd-snmp snmpd agent. */
#ifndef _MIBGROUP_IEEE802DOT11_H
#define _MIBGROUP_IEEE802DOT11_H
/* we may use header_generic and header_simple_table from the util_funcs module */

/****************************************************************************
*                               Includes                                    *
****************************************************************************/
#include <sys/queue.h>

/****************************************************************************
*                             Linked List Defines                           *
****************************************************************************/
// here are some Linked List MACROS I wanted to use, 
// but curiously were not in /usr/includes/sys/queue.h

#ifndef LIST_EMPTY
  #define	LIST_EMPTY(head)	((head)->lh_first == NULL)
#endif

#ifndef LIST_NEXT
  #define	LIST_NEXT(elm, field)	((elm)->field.le_next)
#endif

#ifndef LIST_INSERT_BEFORE
  #define	LIST_INSERT_BEFORE(listelm, elm, field) do {			\
	  (elm)->field.le_prev = (listelm)->field.le_prev;		\
	  LIST_NEXT((elm), field) = (listelm);				\
	  *(listelm)->field.le_prev = (elm);				\
	  (listelm)->field.le_prev = &LIST_NEXT((elm), field);		\
  } while (0)
#endif

#ifndef LIST_FIRST
  #define	LIST_FIRST(head)	((head)->lh_first)
#endif

/****************************************************************************
*                             802.11 MIB Defines                            *
****************************************************************************/
#define SYS_STRING_LEN                     256
#define MACADDR_LEN                        ( 6 * 2 ) + 5
#define OPER_RATE_SET_LEN                  126
#define MAN_OUI_LEN                        ( 3 * 2 ) + 2
#define WEP_STR_LEN                         64
#define SNMP_STR_LEN                       128
#define TEXT_LEN                            80
#define IFINDEX_LEN                          4
#define IFNAME_LEN                          16
#define MAX_WEP_KEYS                         4

#define AUTHENICATION_ALGORITHMS_INDEX_LEN   4
#define WEP_DEFAULT_KEY_INDEX_LEN            4
#define WEP_KEY_MAPPING_INDEX_LEN            4
#define GROUP_ADDRESS_INDEX_LEN              4
#define REG_DOMAIN_SUPPORT_INDEX_LEN         4
#define ANTENNA_LIST_INDEX_LEN               4
#define SUPPORTED_DATA_RATES_TX_INDEX_LEN    4
#define SUPPORTED_DATA_RATES_RX_INDEX_LEN    4

#define SC_UID_LEN  IFINDEX_LEN
#define AA_UID_LEN  IFINDEX_LEN + AUTHENICATION_ALGORITHMS_INDEX_LEN
#define DF_UID_LEN  IFINDEX_LEN + WEP_DEFAULT_KEY_INDEX_LEN
#define KM_UID_LEN  IFINDEX_LEN + WEP_KEY_MAPPING_INDEX_LEN
#define PR_UID_LEN  IFINDEX_LEN
#define OP_UID_LEN  IFINDEX_LEN
#define CO_UID_LEN  IFINDEX_LEN
#define GA_UID_LEN  IFINDEX_LEN + GROUP_ADDRESS_INDEX_LEN
#define RI_UID_LEN  IFINDEX_LEN
#define PO_UID_LEN  IFINDEX_LEN
#define PA_UID_LEN  IFINDEX_LEN
#define PT_UID_LEN  IFINDEX_LEN
#define PF_UID_LEN  IFINDEX_LEN
#define PD_UID_LEN  IFINDEX_LEN
#define PI_UID_LEN  IFINDEX_LEN
#define RD_UID_LEN  IFINDEX_LEN + REG_DOMAIN_SUPPORT_INDEX_LEN
#define AL_UID_LEN  IFINDEX_LEN + ANTENNA_LIST_INDEX_LEN
#define RT_UID_LEN  IFINDEX_LEN + SUPPORTED_DATA_RATES_TX_INDEX_LEN
#define RR_UID_LEN  IFINDEX_LEN + SUPPORTED_DATA_RATES_RX_INDEX_LEN

/****************************************************************************
*                           Linked List Structure                           *
****************************************************************************/
static struct avNode {  
  LIST_ENTRY ( avNode ) nodes; 
  char *data;                                 // pointer to data
};

typedef LIST_HEAD ( , avNode ) avList_t;

/****************************************************************************
*                          802.11 MIB structures                            *
****************************************************************************/
/****************************************************************************
*                             dot11Smt Group                                *
****************************************************************************/
/****************************************************************************
*                          dot11StationConfigTable                          *
****************************************************************************/
static struct scTbl_data {

  char  UID       [ SC_UID_LEN + 1 ];               // unique ID
  char  ifName    [ IFNAME_LEN + 1 ];               // ifName of card

  long  ifIndex;                                    // ifindex of card

  char  stationID [ MACADDR_LEN + 1 ];              // Default actual MacAddr
  long  mediumOccupancyLimit;
  long  CFPPollable;
  long  CFPPeriod;
  long  maxDuration;
  long  authenticationResponseTimeOut;
  long  privacyOptionImplemented;
  long  powerManagementMode;
  char  desiredSSID             [ SNMP_STR_LEN + 1 ];
  long  desiredBSSType;
  char  operationalRateSet      [ OPER_RATE_SET_LEN + 1];
  long  beaconPeriod;
  long  DTIMPeriod;
  long  associationResponseTimeOut;
  long  disAssociationReason;
  char  disAssociationStation   [ MACADDR_LEN + 1 ];
  long  deAuthenticationReason;
  char  deAuthenticationStation [ MACADDR_LEN + 1 ];
  long  authenticateFailStatus;
  char  authenticateFailStation [ MACADDR_LEN + 1 ];

  long  haveStationID;
  long  haveMediumOccupancyLimit;
  long  haveCFPPollable;
  long  haveCFPPeriod;
  long  haveMaxDuration;
  long  haveAuthenticationResponseTimeOut;
  long  havePrivacyOptionImplemented;
  long  havePowerManagementMode;
  long  haveDesiredSSID;
  long  haveDesiredBSSType;
  long  haveOperationalRateSet;
  long  haveBeaconPeriod;
  long  haveDTIMPeriod;
  long  haveAssociationResponseTimeOut;
  long  haveDisAssociationReason;
  long  haveDisAssociationStation;
  long  haveDeAuthenticationReason;
  long  haveDeAuthenticationStation;
  long  haveAuthenticateFailStatus;
  long  haveAuthenticateFailStation;

} nSc, *sc = &nSc;

static avList_t scList;

/****************************************************************************
*                    dot11AuthenticationAlgorithmsTable                     *
****************************************************************************/
static struct aaTbl_data {

  char  UID       [ AA_UID_LEN + 1 ];
  char  ifName    [ IFNAME_LEN + 1 ];               // ifName of card

  long  ifIndex;                                    // ifindex of card
  long  authenticationAlgorithmsIndex;

  long  authenticationAlgorithm;
  long  authenticationAlgorithmsEnable;

  long  haveAuthenticationAlgorithm;
  long  haveAuthenticationAlgorithmsEnable;

} nAa, *aa = &nAa;

static avList_t aaList;

/****************************************************************************
*                           dot11WEPDefaultKeysTable                        *
****************************************************************************/
static struct dfTbl_data {

  char  UID       [ DF_UID_LEN + 1 ];
  char  ifName    [ IFNAME_LEN + 1 ];

  long  ifIndex;                                    // ifindex of card
  long  WEPDefaultKeyIndex;

  char  WEPDefaultKeyValue [ WEP_STR_LEN + 1 ];
  long  haveWEPDefaultKeyValue;

} nDf, *df = &nDf;

static avList_t dfList;

/****************************************************************************
*                          dot11WEPKeyMappingsTable                         *
****************************************************************************/
static struct kmTbl_data {

  char  UID       [ KM_UID_LEN + 1 ];
  char  ifName    [ IFNAME_LEN + 1 ];

  long  ifIndex;
  long  WEPKeyMappingIndex;

  char  WEPKeyMappingAddress  [ MACADDR_LEN + 1 ];
  long  WEPKeyMappingWEPOn;
  char  WEPKeyMappingValue    [ WEP_STR_LEN + 1 ];
  long  WEPKeyMappingStatus;

  long  haveWEPKeyMappingIndex;
  long  haveWEPKeyMappingAddress;
  long  haveWEPKeyMappingWEPOn;
  long  haveWEPKeyMappingValue;
  long  haveWEPKeyMappingStatus;

} nKm, *km = &nKm;

static avList_t kmList;

/****************************************************************************
*                                dot11PrivacyTable                          *
****************************************************************************/
static struct prTbl_data {

  char          UID       [ PR_UID_LEN + 1 ];
  char          ifName    [ IFNAME_LEN + 1 ];

  long          ifIndex;

  long          privacyInvoked;
  long          WEPDefaultKeyID;
  long          WEPKeyMappingLength;
  long          excludeUnencrypted;
  unsigned long WEPICVErrorCount;
  unsigned long WEPExcludedCount;

  long          havePrivacyInvoked;
  long          haveWEPDefaultKeyID;
  long          haveWEPKeyMappingLength;
  long          haveExcludeUnencrypted;
  long          haveWEPICVErrorCount;
  long          haveWEPExcludedCount;

} nPr, *pr = &nPr;

static avList_t prList;

/****************************************************************************
*                               dot11Mac Group                              *
****************************************************************************/
/****************************************************************************
*                              dot11OperationTable                          *
****************************************************************************/
static struct opTbl_data {

  char  UID       [ OP_UID_LEN + 1 ];                 // unique ID
  char  ifName    [ IFNAME_LEN + 1 ];                 // ifName of card

  long  ifIndex;                                      // ifindex of card

  char  MACAddress      [ MACADDR_LEN + 1 ];
  long  RTSThreshold;
  long  shortRetryLimit;
  long  longRetryLimit;
  long  fragmentationThreshold;
  long  maxTransmitMSDULifetime;
  long  maxReceiveLifetime;
  char  manufacturerID  [ SNMP_STR_LEN + 1 ];
  char  productID       [ SNMP_STR_LEN + 1 ];

  long  haveMACAddress;
  long  haveRTSThreshold;
  long  haveShortRetryLimit;
  long  haveLongRetryLimit;
  long  haveFragmentationThreshold;
  long  haveMaxTransmitMSDULifetime;
  long  haveMaxReceiveLifetime;
  long  haveManufacturerID;
  long  haveProductID;

} nOp, *op = &nOp;

static avList_t opList;

/****************************************************************************
*                            dot11CountersTable                             *
****************************************************************************/
static struct coTbl_data {

  char          UID       [ CO_UID_LEN + 1 ];     // unique ID
  char          ifName    [ IFNAME_LEN + 1 ];     // ifName of card

  long          ifIndex;                          // ifindex of card

  unsigned long  transmittedFragmentCount;
  unsigned long  multicastTransmittedFrameCount;
  unsigned long  failedCount;
  unsigned long  retryCount;
  unsigned long  multipleRetryCount;
  unsigned long  frameDuplicateCount;
  unsigned long  RTSSuccessCount;
  unsigned long  RTSFailureCount;
  unsigned long  ACKFailureCount;
  unsigned long  receivedFragmentCount;
  unsigned long  multicastReceivedFrameCount;
  unsigned long  FCSErrorCount;
  unsigned long  transmittedFrameCount;
  unsigned long  WEPUndecryptableCount;

  long           haveTransmittedFragmentCount;
  long           haveMulticastTransmittedFrameCount;
  long           haveFailedCount;
  long           haveRetryCount;
  long           haveMultipleRetryCount;
  long           haveFrameDuplicateCount;
  long           haveRTSSuccessCount;
  long           haveRTSFailureCount;
  long           haveACKFailureCount;
  long           haveReceivedFragmentCount;
  long           haveMulticastReceivedFrameCount;
  long           haveFCSErrorCount;
  long           haveTransmittedFrameCount;
  long           haveWEPUndecryptableCount;

} nCo, *co = &nCo;

static avList_t coList;

/****************************************************************************
*                        dot11GroupAddressesTable                           *
****************************************************************************/
static struct gaTbl_data {

  char  UID       [ GA_UID_LEN + 1 ];
  char  ifName    [ IFNAME_LEN + 1 ];

  long  ifIndex;                                    // ifindex of card
  long  groupAddressesIndex;

  char  address   [ MACADDR_LEN + 1 ];
  long  groupAddressesStatus;

  long  haveAddress;
  long  haveGroupAddressesStatus;

} nGa, *ga = &nGa;

static avList_t gaList;

/****************************************************************************
*                               dot11Res Group                              *
****************************************************************************/
static char  resourceTypeIDName[] = "RTID";
static long  haveResourceTypeIDName = 1;

/****************************************************************************
*                           dot11ResourceInfoTable                          *
****************************************************************************/
static struct riTbl_data {

  char  UID       [ RI_UID_LEN + 1 ];               // unique ID
  char  ifName    [ IFNAME_LEN + 1 ];               // ifName of card

  long  ifIndex;                                    // ifindex of card

  char  manufacturerOUI            [ MAN_OUI_LEN    + 1 ];
  char  manufacturerName           [ SYS_STRING_LEN + 1 ];
  char  manufacturerProductName    [ SYS_STRING_LEN + 1 ];
  char  manufacturerProductVersion [ SYS_STRING_LEN + 1 ];

  char  haveManufacturerOUI;
  char  haveManufacturerName;
  char  haveManufacturerProductName;
  char  haveManufacturerProductVersion;

} nRi, *ri = &nRi;

static avList_t riList;

/****************************************************************************
*                               dot11Phy Group                              *
****************************************************************************/
/****************************************************************************
*                           dot11PhyOperationTable                          *
****************************************************************************/
static struct poTbl_data {

  char  UID       [ PO_UID_LEN + 1 ];               // unique ID
  char  ifName    [ IFNAME_LEN + 1 ];               // ifName of card

  long  ifIndex;                                    // ifindex of card

  long  PHYType;
  long  currentRegDomain;
  long  tempType;

  long  havePHYType;
  long  haveCurrentRegDomain;
  long  haveTempType;

} nPo, *po = &nPo;

static avList_t poList;

/****************************************************************************
*                           dot11PhyAntennaEntry                            *
****************************************************************************/
static struct paTbl_data {

  char  UID       [ PA_UID_LEN + 1 ];               // unique ID
  char  ifName    [ IFNAME_LEN + 1 ];               // ifName of card

  long  ifIndex;                                    // ifindex of card

  long  currentTxAntenna;
  long  diversitySupport;
  long  currentRxAntenna;

  long  haveCurrentTxAntenna;
  long  haveDiversitySupport;
  long  haveCurrentRxAntenna;

} nPa, *pa = &nPa;

static avList_t paList;

/****************************************************************************
*                             dot11PhyTxPowerTable                          *
****************************************************************************/
static struct ptTbl_data {

  char  UID       [ PT_UID_LEN + 1 ];               // unique ID
  char  ifName    [ IFNAME_LEN + 1 ];               // ifName of card

  long  ifIndex;                                    // ifindex of card

  long  numberSupportedPowerLevels;
  long  TxPowerLevel1;
  long  TxPowerLevel2;
  long  TxPowerLevel3;
  long  TxPowerLevel4;
  long  TxPowerLevel5;
  long  TxPowerLevel6;
  long  TxPowerLevel7;
  long  TxPowerLevel8;
  long  currentTxPowerLevel;

  long  haveNumberSupportedPowerLevels;
  long  haveTxPowerLevel1;
  long  haveTxPowerLevel2;
  long  haveTxPowerLevel3;
  long  haveTxPowerLevel4;
  long  haveTxPowerLevel5;
  long  haveTxPowerLevel6;
  long  haveTxPowerLevel7;
  long  haveTxPowerLevel8;
  long  haveCurrentTxPowerLevel ;

} nPt, *pt = &nPt;

static avList_t ptList;

/****************************************************************************
*                               dot11PhyFHSSTable                           *
****************************************************************************/
static struct pfTbl_data {

  char  UID       [ PF_UID_LEN + 1 ];              // unique ID
  char  ifName    [ IFNAME_LEN + 1 ];              // ifName of card

  long  ifIndex;                                    // ifindex of card

  long  hopTime;
  long  currentChannelNumber;
  long  maxDwellTime;
  long  currentDwellTime;
  long  currentSet;
  long  currentPattern;
  long  currentIndex;

  long  haveHopTime;
  long  haveCurrentChannelNumber;
  long  haveMaxDwellTime;
  long  haveCurrentDwellTime;
  long  haveCurrentSet;
  long  haveCurrentPattern;
  long  haveCurrentIndex;

} nPf, *pf = &nPf;

static avList_t pfList;

/****************************************************************************
*                              dot11PhyDSSSTable                            *
****************************************************************************/
static struct pdTbl_data {

  char  UID       [ PD_UID_LEN + 1 ];               // unique ID
  char  ifName    [ IFNAME_LEN + 1 ];               // ifName of card

  long  ifIndex;                                    // ifindex of card

  long  currentChannel;
  long  CCAModeSupported;
  long  currentCCAMode;
  long  EDThreshold;

  long  haveCurrentChannel;
  long  haveCCAModeSupported ;
  long  haveCurrentCCAMode;
  long  haveEDThreshold;

} nPd, *pd = &nPd;

static avList_t pdList;

/****************************************************************************
*                              dot11PhyIRTable                              *
****************************************************************************/
static struct piTbl_data {

  char  UID       [ PI_UID_LEN + 1 ];               // unique ID
  char  ifName    [ IFNAME_LEN + 1 ];               // ifName of card

  long  ifIndex;                                    // ifindex of card

  long  CCAWatchdogTimerMax;
  long  CCAWatchdogCountMax;
  long  CCAWatchdogTimerMin;
  long  CCAWatchdogCountMin;

  long  haveCCAWatchdogTimerMax;
  long  haveCCAWatchdogCountMax;
  long  haveCCAWatchdogTimerMin;
  long  haveCCAWatchdogCountMin;

} nPi, *pi = &nPi;

static avList_t piList;

/****************************************************************************
*                      dot11RegDomainsSupportedTable                        *
****************************************************************************/
static struct rdTbl_data {

  char  UID       [ RD_UID_LEN + 1 ];
  char  ifName    [ IFNAME_LEN + 1 ];

  long  ifIndex;                                    // ifindex of card
  long  regDomainsSupportIndex;

  long  regDomainsSupportValue;
  long  haveRegDomainsSupportValue;

} nRd, *rd = &nRd;

static avList_t rdList;

/****************************************************************************
*                             dot11AntennasListTable                        *
****************************************************************************/
static struct alTbl_data {

  char  UID       [ AL_UID_LEN + 1 ];
  char  ifName    [ IFNAME_LEN + 1 ];

  long  ifIndex;                                    // ifindex of card
  long  antennaListIndex;

  long  supportedTxAntenna;
  long  supportedRxAntenna;
  long  diversitySelectionRx ;

  long  haveSupportedTxAntenna;
  long  haveSupportedRxAntenna;
  long  haveDiversitySelectionRx ;

} nAl, *al = &nAl;

static avList_t alList;

/****************************************************************************
*                    dot11SupportedDataRatesTxTable                         *
****************************************************************************/
static struct rtTbl_data {

  char  UID       [ RT_UID_LEN + 1 ];
  char  ifName    [ IFNAME_LEN + 1 ];

  long  ifIndex;                                    // ifindex of card
  long  supportedDataRatesTxIndex;

  long  supportedDataRatesTxValue;
  long  haveSupportedDataRatesTxValue;

} nRt, *rt = &nRt;

static avList_t rtList;

/****************************************************************************
*                    dot11SupportedDataRatesRxTable                         *
****************************************************************************/
static struct rrTbl_data {

  char  UID       [ RR_UID_LEN + 1 ];
  char  ifName    [ IFNAME_LEN + 1 ];

  long  ifIndex;                                    // ifindex of card
  long  supportedDataRatesRxIndex;

  long  supportedDataRatesRxValue;
  long  haveSupportedDataRatesRxValue;

} nRr, *rr = &nRr;

static avList_t rrList;

/****************************************************************************
*                       Wireless Extensions Structures                      *
****************************************************************************/
static long wepCurrentKey;
static long haveWepCurrentKey;
static struct wepTbl_data {

  long len;
  char key [ WEP_STR_LEN + 1 ];
  long haveKey;

} wep[4];

/****************************************************************************
*                                                                           *
****************************************************************************/
config_require(util_funcs)

/* function prototypes */

void   init_ieee802dot11 ( void );
FindVarMethod var_ieee802dot11;
FindVarMethod var_dot11StationConfigTable;
FindVarMethod var_dot11AuthenticationAlgorithmsTable;
FindVarMethod var_dot11WEPDefaultKeysTable;
FindVarMethod var_dot11WEPKeyMappingsTable;
FindVarMethod var_dot11PrivacyTable;
FindVarMethod var_dot11OperationTable;
FindVarMethod var_dot11CountersTable;
FindVarMethod var_dot11GroupAddressesTable;
FindVarMethod var_dot11ResourceInfoTable;
FindVarMethod var_dot11PhyOperationTable;
FindVarMethod var_dot11PhyAntennaTable;
FindVarMethod var_dot11PhyTxPowerTable;
FindVarMethod var_dot11PhyFHSSTable;
FindVarMethod var_dot11PhyDSSSTable;
FindVarMethod var_dot11PhyIRTable;
FindVarMethod var_dot11RegDomainsSupportedTable;
FindVarMethod var_dot11AntennasListTable;
FindVarMethod var_dot11SupportedDataRatesTxTable;
FindVarMethod var_dot11SupportedDataRatesRxTable;

WriteMethod write_dot11StationID;
WriteMethod write_dot11MediumOccupancyLimit;
WriteMethod write_dot11CFPPeriod;
WriteMethod write_dot11CFPMaxDuration;
WriteMethod write_dot11AuthenticationResponseTimeOut;
WriteMethod write_dot11PowerManagementMode;
WriteMethod write_dot11DesiredSSID;
WriteMethod write_dot11DesiredBSSType;
WriteMethod write_dot11OperationalRateSet;
WriteMethod write_dot11BeaconPeriod;
WriteMethod write_dot11DTIMPeriod;
WriteMethod write_dot11AssociationResponseTimeOut;
WriteMethod write_dot11AuthenticationAlgorithmsEnable;
WriteMethod write_dot11WEPDefaultKeyValue;
WriteMethod write_dot11WEPKeyMappingAddress;
WriteMethod write_dot11WEPKeyMappingWEPOn;
WriteMethod write_dot11WEPKeyMappingValue;
WriteMethod write_dot11WEPKeyMappingStatus;
WriteMethod write_dot11PrivacyInvoked;
WriteMethod write_dot11WEPDefaultKeyID;
WriteMethod write_dot11WEPKeyMappingLength;
WriteMethod write_dot11ExcludeUnencrypted;
WriteMethod write_dot11RTSThreshold;
WriteMethod write_dot11ShortRetryLimit;
WriteMethod write_dot11LongRetryLimit;
WriteMethod write_dot11FragmentationThreshold;
WriteMethod write_dot11MaxTransmitMSDULifetime;
WriteMethod write_dot11MaxReceiveLifetime;
WriteMethod write_dot11Address;
WriteMethod write_dot11GroupAddressesStatus;
WriteMethod write_dot11CurrentRegDomain;
WriteMethod write_dot11CurrentTxAntenna;
WriteMethod write_dot11CurrentRxAntenna;
WriteMethod write_dot11CurrentTxPowerLevel;
WriteMethod write_dot11CurrentChannelNumber;
WriteMethod write_dot11CurrentDwellTime;
WriteMethod write_dot11CurrentSet;
WriteMethod write_dot11CurrentPattern;
WriteMethod write_dot11CurrentIndex;
WriteMethod write_dot11CurrentChannel;
WriteMethod write_dot11CurrentCCAMode;
WriteMethod write_dot11EDThreshold;
WriteMethod write_dot11CCAWatchdogTimerMax;
WriteMethod write_dot11CCAWatchdogCountMax;
WriteMethod write_dot11CCAWatchdogTimerMin;
WriteMethod write_dot11CCAWatchdogCountMin;
WriteMethod write_dot11SupportedTxAntenna;
WriteMethod write_dot11SupportedRxAntenna;
WriteMethod write_dot11DiversitySelectionRx;

#endif /* _MIBGROUP_IEEE802DOT11_H */
