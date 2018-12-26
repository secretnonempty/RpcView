#ifndef _RPC_INTERNALS_H_
#define _RPC_INTERNALS_H_

#include <windows.h>
#include <Rpc.h>

static UINT64 RPC_CORE_RUNTIME_VERSION[] = {
	0x6000324D70000LL,	//6.3.9431.0000
	0x6000325804000LL,	//6.3.9600.16384
	0x6000325804340LL,	//6.3.9600.17216
	0x6000325804407LL,	//6.3.9600.17415
	0x60003258045FFLL,	//6.3.9600.17919
    0x6000325804774LL,	//6.3.9600.18292
	0x6000325804AE8LL,	//6.3.9600.19176

	0xA000028004000LL,	//10.0.10240.16384
	0xA00002800401CLL,  //10.0.10240.16412
	0xA0000295A0000LL,	//10.0.10586.0
	0xA0000295A0132LL,	//10.0.10586.306
	0xA0000380603E8LL,	//10.0.14342.1000
	0xA000038190000LL,	//10.0.14361.0
	0xA000038390000LL,	//10.0.14393.0
    0xA000038390052LL,	//10.0.14393.82
	0xA0000383906EALL,	//10.0.14393.1770
	0xA00003AD70000LL,  //10.0.15063.0
	0xA00003AD701BFLL,  //10.0.15063.447
	0xA00003AD702A2LL,  //10.0.15063.674
	0xA00003F6803E8LL,  //10.0.16232.1000
	0xA00003FAB000FLL,  //10.0.16299.15
	0xA00003FAB00C0LL,  //10.0.16299.192
	0xA00003FAB0135LL,  //10.0.16299.309
	0xA00003FAB0173LL,  //10.0.16299.371
    0xA00003FAB02D6LL,  //10.0.16299.726
    0xA0000427903E8LL,  //10.0.17017.1000
	0xA0000428103E8LL,  //10.0.17025.1000
	0xA000042B203EALL,  //10.0.17074.1002
	0xA000042EE0001LL,  //10.0.17134.1
	0xA000042EE0030LL,  //10.0.17134.48
	0xA000042EE0070LL,  //10.0.17134.112
	0xA000042EE00E4LL,  //10.0.17134.228
	0xA000042EE0197LL,  //10.0.17134.407
	0xA000042EE01D7LL,  //10.0.17134.471
	0xA000045630001LL,  //10.0.17763.1
	0xA000045630086LL,  //10.0.17763.134
	0xA0000456300C2LL   //10.0.17763.194
};

#define RPC_CORE_DESCRIPTION					"Windows 10 64bits runtime core"
#define RPC_CORE_IS_WOW64						FALSE

#define ULONG_PTR_T ULONG_PTR
#define PTR_T *

#include "../RpcInternalsCommon.h"

#pragma pack(1)
typedef struct _RPC_SERVER_T{
  MUTEX_T						Mutex;
  ULONG							__bIslistening;
  ULONG							bIsListening;
  ULONG							MinimumCallThreads;
  ULONG							Wait;
  ULONG							OutCalls;
  ULONG							Unk1;
  ULONG							InCalls;
  ULONG							Unk2;
  SIMPLE_DICT_T					AddressDict;
  ULONG							lAvailableCalls;
  ULONG							Unk3;
  SIMPLE_DICT_T					_ProtSeqQueue;
  ULONG							Unk4[8];
  ULONG							OutPackets;
  ULONG							Unk5;
  MUTEX_T						Mutex2;
  ULONG							MaxCalls;
  ULONG							Unk6;
  VOID PTR_T					hEvent;
  ULONG							Unk7[4];
  SIMPLE_DICT_T					InterfaceDict;
  ULONG							_bIsListening;
  ULONG							bIsMaxCalls1234;
  ULONG							Unk8[6];
  ULONG							InPackets;
  ULONG							Unk9;
  RPC_FORWARD_FUNCTION PTR_T	pRpcForwardFunction;
  ULONG							Unk10[6];
  SIMPLE_DICT_T					AuthenInfoDict;
  LIST_ENTRY_T					RpcIfGroupListEntry;
  ULONG	PTR_T					__SRWLock;
  LIST_ENTRY_T					field_1E0;
}RPC_SERVER_T, PTR_T PRPC_SERVER_T;

typedef struct _RPC_INTERFACE_T
{
  PRPC_SERVER_T				pRpcServer;
  ULONG						Flags;
  ULONG						Unk1;
  MUTEX_T					Mutex;
  ULONG						EpMapperFlags;
  ULONG						Unk2;
  RPC_MGR_EPV PTR_T			pMgrEpv;
  RPC_IF_CALLBACK_FN PTR_T	IfCallbackFn;
  RPC_SERVER_INTERFACE_T	RpcServerInterface;
  PMIDL_SYNTAX_INFO			pSyntaxInfo;
  VOID PTR_T				pTransfertSyntaxes;
  ULONG						TransfertSyntaxesCount;
  ULONG						__Field_C4;
  ULONG						NbTypeManager;
  ULONG						MaxRpcSize;
  UUID_VECTOR  PTR_T		pUuidVector;
  SIMPLE_DICT_T				RpcInterfaceManagerDict;
  UCHAR						Annotation[MAX_RPC_INTERFACE_ANNOTATION];
  ULONG						IsCallSizeLimitReached;
  ULONG						currentNullManagerCalls;
  ULONG						__Field_150;
  ULONG						__Field_154;
  ULONG						__Field_158;
  ULONG						SecurityCallbackInProgress;
  ULONG						SecurityCacheEntry;
  ULONG						field_164;
  VOID PTR_T				__SecurityCacheEntries[16];
  SIMPLE_DICT_T				FwEpDict;
  ULONG						Unk3[6];
  struct RPCP_INTERFACE_GROUP PTR_T pRpcpInterfaceGroup;
}RPC_INTERFACE_T, PTR_T PRPC_INTERFACE_T;
 
#define RPC_ADDRESS_TYPE_DG		0x400000
#define RPC_ADDRESS_TYPE_LRPC	0x800000
#define RPC_ADDRESS_TYPE_OSF	0x800

typedef struct _RPC_ADDRESS_T{
	VOID PTR_T				pVtable;
	ULONG					Magic;
	ULONG					TypeOfAddress;
	ULONG					ReferenceCounter;
	ULONG					Unk1[3];
	WCHAR PTR_T				Name;
	WCHAR PTR_T				Protocole;
	WCHAR PTR_T				Address;
	ULONG					bNamed;
	ULONG					EpAddAddressFlag;
	SIMPLE_DICT_T			__LRPCSassociationSimpleDict;
	ULONG					__Field_68;
	ULONG					Unk3;
	ULONG					NbActiveCalls;
	ULONG					__Field_74;
	ULONG					Unk4[6];
	ULONG					__Field_90;
	MUTEX_T					Mutex;
}RPC_ADDRESS_T;

#pragma pack()

#endif // _RPC_INTERNALS_H_
