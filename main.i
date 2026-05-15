#line 1 "C:\Users\abhis\Downloads\karma electric\try3\main.c"

#line 18 "C:\Users\abhis\Downloads\karma electric\try3\main.c"






#line 28 "C:\Users\abhis\Downloads\karma electric\try3\main.c"

#line 1 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"




typedef unsigned long	DWORD;
typedef DWORD		*PDWORD;
typedef unsigned long	ULONG;
typedef ULONG		*PULONG;
typedef unsigned short	WORD;
typedef WORD		*PWORD;
typedef unsigned int	UINT;
typedef UINT		*PUINT;
typedef unsigned short	USHORT;
typedef USHORT		*PUSHORT;
typedef unsigned int	BOOL;
typedef BOOL		*PBOOL;
typedef unsigned char	UCHAR;


typedef WORD wchar_t, WCHAR, *WCHAR_P, *WSTR;


typedef struct tagCHAR2 {
	WORD TwoChars;
	} CHAR2, *CHAR2_P, *STR;


typedef const char cchar;
typedef cchar *cchar_p;
typedef cchar *cstr;


typedef unsigned long PTR32;






extern WORD _heap_start;

extern WORD _intram_size;

extern _dp0h;


extern WORD _crtP16_Version;
extern const char _crtP16_AppVersion[];




WORD _rdio(WORD port);
void _wrio(WORD port, WORD data);
void _orio(WORD port, WORD mask);
void _andio(WORD port, WORD mask);


WORD _rdtr0(void);
WORD _rdtr1(void);
WORD _rdt0(void);
WORD _rdt1(void);


WORD _rdfifo(WORD *data);


WORD _rotL(WORD value, WORD shift);
WORD _rotR(WORD value, WORD shift);


WORD _P16mul(WORD x, WORD y);


const typedef struct tagIRAM_WORD {
	WORD OnlyForReference;
	} _IRAM_WORD, *_IRAM_WORD_P;

WORD _rdiram(_IRAM_WORD_P address);
void _wriram(_IRAM_WORD_P address, WORD data);



WORD _rdxtmem(WORD page, WORD address);
void _wrxtmem(WORD page, WORD address, WORD data);
DWORD _rdxtmem32(WORD page, WORD address);
void _wrxtmem32(WORD page, WORD address, DWORD data);
DWORD _rdxtmemDw(WORD page, WORD address);
void _wrxtmemDw(WORD page, WORD address, DWORD data);


WORD _rdxtmemEx(DWORD Address);
void _wrxtmemEx(DWORD Address, WORD data);
DWORD _rdxtmem32Ex(DWORD Address);
void _wrxtmem32Ex(DWORD Address, DWORD data);
DWORD _rdxtmemDwEx(DWORD Address);
void _wrxtmemDwEx(DWORD Address, DWORD data);

PTR32 _ptr32(int a);

PTR32 _cptr32(const void *);







PTR32 _cptr32unsafe(const void *);
WORD _CODEPAGE(void);

void _writemem(PTR32 ptr, WORD data);
WORD _readmem(PTR32 ptr);



WORD _ffl(WORD val);
WORD _ffr(WORD val);
WORD _dffl(DWORD val);
WORD _dffr(DWORD val);
DWORD _swap(DWORD val);
DWORD _bswap(DWORD val);
long _smul(short a, short b);
DWORD _umul32(WORD a, WORD b);



#line 146 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"
typedef struct tagSEGMENT_MARKER { WORD Dummy; } *SEGMENT_MARKER;
typedef struct tagVOID_FAR_P { const void *p; SEGMENT_MARKER Segment; } VOID_FAR_P;
typedef struct tagCHAR_FAR_P { const char *p; SEGMENT_MARKER Segment; } CHAR_FAR_P;
typedef struct tagWORD_FAR_P { const WORD *p; SEGMENT_MARKER Segment; } WORD_FAR_P;
typedef struct tagDWORD_FAR_P { const DWORD *p; SEGMENT_MARKER Segment; } DWORD_FAR_P;




#line 161 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"
extern WORD _rdshortFar(WORD Offset, VOID_FAR_P *pFarRef);


extern DWORD _rdlongFar(WORD Offset, VOID_FAR_P *pFarRef);


extern DWORD _rdlongBeFar(WORD Offset, VOID_FAR_P *pFarRef);


extern WORD _rdshortFarC(WORD Offset, const VOID_FAR_P *pFarRef);


extern DWORD _rdlongFarC(WORD Offset, const VOID_FAR_P *pFarRef);


extern DWORD _rdlongBeFarC(WORD Offset, const VOID_FAR_P *pFarRef);


extern void _setFarPtr(VOID_FAR_P *pFarRef, PTR32 p32);
extern PTR32 _getFarPtr(VOID_FAR_P *pFarRef);
extern PTR32 _getFarPtrC(const VOID_FAR_P *pFarRef);
extern PTR32 _getFarPtr_type_CHAR(CHAR_FAR_P *pFarRef);

extern PTR32 _getFarPtrC_type_CHAR(const CHAR_FAR_P *pFarRef);

extern PTR32 _getFarPtr_type_WORD(WORD_FAR_P *pFarRef);

extern PTR32 _getFarPtrC_type_WORD(const WORD_FAR_P *pFarRef);

extern PTR32 _getFarPtr_type_DWORD(DWORD_FAR_P *pFarRef);

extern PTR32 _getFarPtrC_type_DWORD(const DWORD_FAR_P *pFarRef);



void _memcpy( void *dest, void *src, WORD nWord );
int  _memcmp( void *m1, void *m2, WORD nWord );
void _memclr( void *dest, WORD nWord );
void _memset( void *dest, WORD val, WORD nWord );
void _memswap( void *dest, void *src, WORD nWord );
void _lmemcpy( PTR32 dest, PTR32 src, WORD nWord );
void _lmemcpyEx( WORD DestPg, WORD DestOff, WORD SrcPg, WORD SrcOff, WORD nWord );
void _lmemset( PTR32 dest, WORD val, WORD nWord );
void _lmemsetEx( WORD DestPg, WORD DestOff, WORD val, WORD nWord );
void _lmemclr( PTR32 dest, WORD nWord );
void _lmemclrEx( WORD DestPg, WORD DestOff, WORD nWord );
int _lmemcmp( PTR32 m1, PTR32 m2, WORD nWord );
int _lmemcmpEx( WORD m1Pg, WORD m1Off, WORD m2Pg, WORD m2Off, WORD nWord );


#line 235 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"
DWORD _adler32(DWORD AdlerSum, void* Address, WORD nWord);
DWORD _adler32Ex(DWORD AdlerSum, PTR32 p32Address, WORD nWord);


#line 246 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"
typedef short (*_SYS_BSEARCHCB)(void* Key, PTR32 p32Value);
PTR32 _cptr32_type_SYSBSCB(_SYS_BSEARCHCB Cb);

extern void* _bsearch32(void* Key, void* Base, WORD Num, WORD Width, PTR32 CCompare);

extern PTR32 _bsearch32Ex(void* Key, PTR32 Base, WORD Num, WORD Width, PTR32 CCompare);


typedef short (*_SYS_QSORTCB)(PTR32 p32ValueA, PTR32 p32ValueB);
PTR32 _cptr32_type_SYSQSCB(_SYS_QSORTCB Cb);

extern void _qsort32(void* Base, WORD Num, WORD Width, PTR32 CCompare);

extern PTR32 _qsort32Ex(PTR32 Base, WORD Num, WORD Width, PTR32 CCompare);


void _Sys_ClearRAM( DWORD startaddr, WORD count );
void _Sys_ClearRAMex( DWORD startaddr, DWORD count );


WORD utos(STR Buf, WORD Value);
WORD ultos(STR Buf, DWORD Value);


void _Sys_1msPolling( void );


#line 276 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"
void _Sys_Reset( void );


#line 282 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"
void _Sys_RebootToFLASH( void );
void _Sys_RebootToRAM( void );




#line 299 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"
extern void FATALEx(PTR32 p32Msg);



#line 311 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"
typedef struct tagSYS_FATAL_CONTEXT {
	PTR32		p32Message;
	WORD		RegR0;
	WORD		RegR1;
	WORD		RegR2;
	WORD		RegR3;
	WORD		RegR4;
	WORD		RegR5;
	WORD		RegR6;
	WORD		RegR7;
	DWORD		RegDR4;
	DWORD		RegDR5;
	DWORD		RegDR6;
	DWORD		RegDR7;
	DWORD		RegDP0;
	DWORD		RegDP1;
	DWORD		RegIP;
	WORD		RegSP;
	WORD		RegBP;
	DWORD		RegXSP;
	} _SYS_FATAL_CONTEXT, *_SYS_FATAL_CONTEXT_P;

typedef void (*_SYS_FATAL_HANDLER)(_SYS_FATAL_CONTEXT_P ctx);
PTR32 _cptr32_type_SYSFATALCB(_SYS_FATAL_HANDLER Cb);


#line 341 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"
void _Sys_SetFatalHandlerEx(PTR32 p32SfHandler);



#line 347 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"
extern WORD _Sys_FatalContextExpand(WCHAR* MsgBuffer, WORD BufferSize, _SYS_FATAL_CONTEXT_P ctx);
extern WORD _Sys_FatalContextExpandMessageEx(WCHAR* MsgBuffer, WORD BufferSize, _SYS_FATAL_CONTEXT_P ctx, PTR32 p32Msg);



#line 354 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"


extern PTR32 _SysTab_bsearch32Ex(void* Key, PTR32 Base, PTR32 CCompare);




extern PTR32 _SysTab_IdFindEx(PTR32 Base, WORD Id);

extern WORD _SysTab_IdIndexEx(PTR32 Base, WORD Id);






typedef const struct tagSYSTAB_ID2STRING { WORD id; CHAR_FAR_P p32String; } _SYSTAB_ID2STRING;
typedef const struct tagSYSTAB_STRING2ID { CHAR_FAR_P p32String; WORD id; } _SYSTAB_STRING2ID;



PTR32 _cptr32_type_SYSCHARFARCP(CHAR_FAR_P const *p32String);




extern WORD _SysTab_IdentifierIndex32Ex(PTR32 Base, WORD CmpFlags, PTR32 p32String);











extern PTR32 _SysTab_IdentifierFind32Ex(PTR32 Base, WORD CmpFlags, PTR32 p32String);











extern WORD _SysTab_IdentifierGetId32Ex(PTR32 Base, WORD CmpFlags, PTR32 p32String);

PTR32 _cptr32_type_SYSTABS2ID(_SYSTAB_STRING2ID *p32String);











extern PTR32 _SysTab_StringFindEx(PTR32 Base, WORD Id);
PTR32 _cptr32_type_SysTabString(_SYSTAB_ID2STRING* StringTable);


typedef struct tagSYSTAB_STARTUPFUNC_FAR_P { void (*func)(void); SEGMENT_MARKER Segment; } _SYSTAB_STARTUPFUNC_FAR_P;
extern const _SYSTAB_STARTUPFUNC_FAR_P __systable_StartupFunc[];



WORD _SysTab_GetCountEx(PTR32 Base);


WORD _SysTab_ElementSizeEx(PTR32 Base);


void _SysTab_RunStartup(void);


#line 478 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"





typedef struct tagSYSCRC16 {
	WORD	CRC16;
	WORD	Flags;
	WORD	Lookup[256];
	} _SYS_CRC16, *_SYS_CRC16_P;

extern void _Sys_CRC16_Init(_SYS_CRC16_P pCRC16, WORD CrcFlags, WORD Polynomial);
extern void _Sys_CRC16_InitEx(PTR32 p32CRC16, WORD CrcFlags, WORD Polynomial);
extern void _Sys_CRC16_Begin(_SYS_CRC16_P pCRC16);
extern void _Sys_CRC16_BeginEx(PTR32 p32CRC16);
extern void _Sys_CRC16_UpdateByte(_SYS_CRC16_P pCRC16, WORD Byte);
extern void _Sys_CRC16_UpdateByteEx(PTR32 p32CRC16, WORD Byte);
extern void _Sys_CRC16_UpdateBlock(_SYS_CRC16_P pCRC16, WORD* pData, WORD NumBytes);
extern void _Sys_CRC16_UpdateBlockEx(PTR32 p32CRC16, PTR32 p32Data, DWORD NumBytes);
extern void _Sys_CRC16_End(_SYS_CRC16_P pCRC16);
extern void _Sys_CRC16_EndEx(PTR32 p32CRC16);
extern WORD _Sys_CRC16_Block(_SYS_CRC16_P pCRC16, WORD* pData, WORD NumBytes);
extern WORD _Sys_CRC16_BlockEx(PTR32 p32CRC16, PTR32 p32Data, DWORD NumBytes);

typedef struct tagSYSCRC32 {
	DWORD	CRC32;
	WORD	Flags;
	WORD	Lookup[2*256];
	} _SYS_CRC32, *_SYS_CRC32_P;

extern void _Sys_CRC32_Init(_SYS_CRC32_P pCRC32, WORD CrcFlags, DWORD Polynomial);
extern void _Sys_CRC32_InitEx(PTR32 p32CRC32, WORD CrcFlags, DWORD Polynomial);
extern void _Sys_CRC32_Begin(_SYS_CRC32_P pCRC32);
extern void _Sys_CRC32_BeginEx(PTR32 p32CRC32);
extern void _Sys_CRC32_UpdateByte(_SYS_CRC32_P pCRC32, WORD Byte);
extern void _Sys_CRC32_UpdateByteEx(PTR32 p32CRC32, WORD Byte);
extern void _Sys_CRC32_UpdateBlock(_SYS_CRC32_P pCRC32, WORD* pData, WORD NumBytes);
extern void _Sys_CRC32_UpdateBlockEx(PTR32 p32CRC32, PTR32 p32Data, DWORD NumBytes);
extern void _Sys_CRC32_End(_SYS_CRC32_P pCRC32);
extern void _Sys_CRC32_EndEx(PTR32 p32CRC32);
extern DWORD _Sys_CRC32_Block(_SYS_CRC32_P pCRC32, WORD* pData, WORD NumBytes);
extern DWORD _Sys_CRC32_BlockEx(PTR32 p32CRC32, PTR32 p32Data, DWORD NumBytes);

typedef struct tagSYSCRC64 {
	DWORD	CRC64Low;
	DWORD	CRC64High;
	WORD	Flags;
	WORD	Lookup[4*256];
	} _SYS_CRC64, *_SYS_CRC64_P;

extern void _Sys_CRC64_Init(_SYS_CRC64_P pCRC64, WORD CrcFlags, DWORD PolynomialHigh, DWORD PolynomialLow);
extern void _Sys_CRC64_InitEx(PTR32 p32CRC64, WORD CrcFlags, DWORD PolynomialHigh, DWORD PolynomialLow);
extern void _Sys_CRC64_Begin(_SYS_CRC64_P pCRC64);
extern void _Sys_CRC64_BeginEx(PTR32 p32CRC64);
extern void _Sys_CRC64_UpdateByte(_SYS_CRC64_P pCRC64, WORD Byte);
extern void _Sys_CRC64_UpdateByteEx(PTR32 p32CRC64, WORD Byte);
extern void _Sys_CRC64_UpdateBlock(_SYS_CRC64_P pCRC64, WORD* pData, WORD NumBytes);
extern void _Sys_CRC64_UpdateBlockEx(PTR32 p32CRC64, PTR32 p32Data, DWORD NumBytes);
extern void _Sys_CRC64_End(_SYS_CRC64_P pCRC64);
extern void _Sys_CRC64_EndEx(PTR32 p32CRC64);
extern void _Sys_CRC64_Block(_SYS_CRC64_P pCRC64, WORD* pData, WORD NumBytes);
extern void _Sys_CRC64_BlockEx(PTR32 p32CRC64, PTR32 p32Data, DWORD NumBytes);




typedef PTR32 _SYS_CCB_USER_P;





typedef WORD (*_SYS_CCALLBACKFUNC)(_SYS_CCB_USER_P UserPtr, WORD DataByte);



typedef PTR32 _SYS_CCALLBACKFUNC_P;
typedef PTR32 _SYS_ASMHANDLER_P;
extern PTR32 _cptr32_type_CCBCB(_SYS_CCALLBACKFUNC p);







typedef struct tagSYS_CCBWRAPPER {
	_SYS_CCALLBACKFUNC_P Handler;
	_SYS_CCB_USER_P UserPtr;
	} _SYS_CCBWRAPPER, *_SYS_CCBWRAPPER_P;









struct tag_SYS_STREAMHEAD;
typedef struct tag_SYS_STREAMHEAD {
	WORD	StreamMagic;
	WORD	StreamLen;
	WORD	StreamSize;
	WORD	StreamReadPtr;
	WORD	StreamWritePtr;
	WORD	StreamUser;
	_SYS_ASMHANDLER_P StreamFlush;
	} _SYS_STREAMHEAD, *_SYS_STREAMHEAD_P;

void _Sys_StreamInit(_SYS_STREAMHEAD_P Stream, WORD StreamWordSize, _SYS_CCBWRAPPER_P FlushCallback);
void _Sys_StreamReset(_SYS_STREAMHEAD_P Stream);
WORD _Sys_StreamWriteByte(_SYS_STREAMHEAD_P Stream, WORD DataByte);
int _Sys_StreamReadByte(_SYS_STREAMHEAD_P Stream);


struct tag_SYS_STREAMEX;
typedef struct tag_SYS_STREAMEX {
	struct tag_SYS_STREAMEX_HEAD {
		WORD	StreamMagic;
		DWORD	StreamLen;
		DWORD	StreamSize;
		DWORD	StreamReadPtr;
		DWORD	StreamWritePtr;
		} h;
	PTR32	p32Buffer;
	} _SYS_STREAMEX, *_SYS_STREAMEX_P;

void _Sys_StreamExInit(_SYS_STREAMEX_P Stream, PTR32 p32StreamBase, DWORD StreamWordSize);
void _Sys_StreamExReset(_SYS_STREAMEX_P Stream);
WORD _Sys_StreamExWriteByte(_SYS_STREAMEX_P Stream, WORD DataByte);
int _Sys_StreamExReadByte(_SYS_STREAMEX_P Stream);





































































WORD _Sys_GetFSPinState( void );
void _Sys_SetCrystalFS(WORD SystemFS);
DWORD _Sys_GetCrystalFreq( void );
DWORD _Sys_GetSystemFreq( void );
WORD _Sys_GetPllMultiplier( void );
DWORD _Sys_GetSamplingRate( void );
void _Sys_InvalidateSamplingRate(void);
WORD _Sys_CalcTimerReload(DWORD Baudrate);
WORD _Sys_CalcTimerReloadForFrequency(DWORD Baudrate, DWORD SystemFreq);
DWORD _Sys_GetBitrateFromReload( WORD TmrReload );


DWORD _Sys_GetTimer2Rate16(void);
DWORD _Sys_GetTimer2Rate(void);































#line 738 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"
typedef unsigned long _SYS_TIMESTAMP;
WORD _Sys_TimestampInit(WORD uDsp, WORD offCounter);
WORD _Sys_TimestampInitDspEx(WORD uDsp);
WORD _Sys_TimestampInitDsp(void);
void _Sys_TimestampSrChanged(void);
_SYS_TIMESTAMP _Sys_Timestamp(void);
DWORD _Sys_TimestampDeltaToUSec(_SYS_TIMESTAMP Timestamp);
DWORD _Sys_TimestampDeltaToTime(_SYS_TIMESTAMP Timestamp, DWORD TimeScale);
DWORD _Sys_TimestampElapsedUSec(_SYS_TIMESTAMP* pTimestamp);
DWORD _Sys_TimestampElapsedTime(_SYS_TIMESTAMP* pTimestamp, DWORD TimeScale);















WORD _Sys_McSetFifo(WORD *FifoAddress, WORD FifoSize);
WORD _Sys_McSetChannelHandler(WORD uChn, _SYS_ASMHANDLER_P Handler, void *UserPtr);
WORD _Sys_McSetStreamHandler(WORD uChn, _SYS_STREAMHEAD_P Stream);
WORD _Sys_McSetCallbackHandler(WORD uChn, _SYS_CCBWRAPPER_P CCallback);
WORD _Sys_McPoll(WORD MaxBytesToPoll);

WORD _Sys_UartEnable(WORD bEnable);
WORD _Sys_MpuEnable(WORD bEnable, WORD bFifo);





WORD _Sys_UartFlushStream(_SYS_STREAMHEAD_P Stream);
WORD _Sys_MpuFlushStream(_SYS_STREAMHEAD_P Stream, WORD ID);









void _Sys_Uart2Enable(WORD bEnableConfig);
WORD _Sys_Uart2FlushStream(_SYS_STREAMHEAD_P Stream);




#line 823 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"

typedef struct tagSYS_INFLATE_SCRATCH {
	WORD OpaqueData[700];
	} _SYS_INFLATE_SCRATCH;

WORD _Sys_Inflate(_SYS_INFLATE_SCRATCH *InfWork, DWORD ImageAddr, DWORD TargetAddr, WORD WordWidth);

typedef WORD (*_SYS_INFLATEFILL)(WORD* Buffer, WORD WordCount);
typedef PTR32 _SYS_INFLATEFILL_P;
extern PTR32 _cptr32_type_INFLATEFILL(_SYS_INFLATEFILL p);
WORD _Sys_InflateBufEx(_SYS_INFLATE_SCRATCH *InfWork, _SYS_INFLATEFILL_P FillBufferCallback, WORD* Buffer, WORD BufferSize, DWORD TargetAddr, WORD WordWidth);





extern DWORD _Sys_InflateWrittenBytes(_SYS_INFLATE_SCRATCH *InfWork);
extern DWORD _Sys_InflateExpectedBytes(_SYS_INFLATE_SCRATCH *InfWork);


WORD _Sys_IsInflatedImage(DWORD ImageAddr);
DWORD _Sys_InflateExpandedSize(DWORD ImageAddr);
DWORD _Sys_InflateCompressedSize(DWORD ImageAddr);


#line 858 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"
extern void _Sys_LoadAndRun(DWORD DfuKernelAddress);
extern void _Sys_DecompressAndRun(DWORD DfuKernelAddress);


#line 868 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"
extern void _Sys_SpiLoadAndRun(WORD FlashCsFunction[], WORD DfuSpiStartPage, WORD DfuSpiStartByteOffset);


#line 875 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"


#line 890 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"
extern void _Sys_DfInit(WORD TimerValue, WORD IoPort, WORD ControlBitMask, WORD EnableBits, WORD DisableBits, WORD PageSize);


#line 907 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"
typedef struct tagSYS_DFINFO {
	WORD PageByteSize;
	WORD NumberOfPages;
	WORD bIsBinaryMode;
	} _SYS_DFINFO, *_SYS_DFINFO_P;

extern WORD _Sys_DfDetectAndInit(WORD TimerValue, WORD IoPort, WORD ControlBitMask, WORD EnableBits, WORD DisableBits, _SYS_DFINFO_P DfInfo);


#line 926 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"
extern void _Sys_DfBinaryMode(void);

extern void _Sys_DfDisable(void);
extern void _Sys_DfEnable(void);
extern WORD _Sys_DfStatus(void);
extern void _Sys_DfWaitNotBusy(void);


#line 943 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"
extern void _Sys_DfContRead(WORD PageAddress, WORD FirstByteAddress);
extern void _Sys_DfBufferRead(WORD BufferAddress);
extern WORD _Sys_DfReadByte(void);
extern WORD _Sys_DfReadWord(void);
extern void _Sys_DfReadBlock(WORD *Buffer, WORD BlockSize);

extern void _Sys_DfReadBlockEx(PTR32 p32Buffer, WORD BlockSize);


extern void _Sys_DfErasePages(WORD StartPage, WORD NumPages);


#line 959 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"
extern void _Sys_DfBufferWrite(WORD BufferAddress);
extern void _Sys_DfBufferToPage(WORD PageAddress);
extern void _Sys_DfWriteToPageWithErase(WORD PageAddress, WORD BufferAddress);
extern void _Sys_DfWriteByte(WORD ByteValue);
extern void _Sys_DfWriteWord(WORD WordValue);
extern void _Sys_DfWriteBlock(WORD *Buffer, WORD BlockSize);

extern void _Sys_DfWriteBlockEx(PTR32 p32Buffer, WORD BlockSize);



#line 975 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"
extern WORD _Sys_DfVerifyFirmware(WORD PageAddress, WORD SignatureWord);



#line 982 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"
extern WORD _Sys_DfDownloadAndRunFirmware(WORD PageAddress, WORD SignatureWord);


#line 987 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"
extern WORD _Sys_VerifyFirmware(WORD Page, WORD Offset, WORD SignatureWord);
extern WORD _Sys_VerifyFirmwareEx(DWORD FlatAddress, WORD SignatureWord);


#line 995 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"
extern WORD _Sys_VerifyAndRunFirmware(WORD SignatureWord);


#line 1004 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"
extern WORD _Sys_VerifyAndRunFromRAM(WORD SignatureWord);


#line 1010 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"
extern WORD _Sys_VerifyDownloadAndRunFirmware(WORD Page, WORD Offset, WORD SignatureWord);
extern WORD _Sys_VerifyDownloadAndRunFirmwareEx(DWORD FlatAddress, WORD SignatureWord);
extern WORD _Sys_DownloadAndRunFirmware(WORD Page, WORD Offset, WORD SignatureWord);
extern WORD _Sys_DownloadAndRunFirmwareEx(DWORD FlatAddress, WORD SignatureWord);


#line 1021 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"
extern WORD _Sys_NandVerifyAndDownloadBootsector(WORD Page, WORD Offset, WORD SignatureWord);
extern WORD _Sys_NandVerifyAndDownloadBootsectorEx(DWORD FlatAddress, WORD SignatureWord);





#line 1040 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"


#line 1046 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"
typedef struct tagSYS_QSPIDEVINFO {
	DWORD	DeviceAddress;
	WORD	ManufacturerID;
	WORD	DeviceID;
	WORD	DeviceSize;
	WORD	BufferWords;
	WORD	BufferPerErase;
	WORD	EraseReg1;
	WORD	EraseReg2;
	WORD	ProgramReg1;
	WORD	ProgramReg2;
	} _SYS_QSPIDEVINFO, *_SYS_QSPIDEVINFO_P;


#line 1072 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"
extern WORD _Sys_QspiDetect(PTR32 DeviceAddress, _SYS_QSPIDEVINFO_P DevInfo);


#line 1079 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"
extern WORD _Sys_QspiDetectSpansion(PTR32 DeviceAddress, _SYS_QSPIDEVINFO_P DevInfo);


#line 1086 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"
extern WORD _Sys_QspiSetup4k128MBit(PTR32 DeviceAddress, _SYS_QSPIDEVINFO_P DevInfo);


#line 1094 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"
extern WORD _Sys_QspiSetup4k256MBit(PTR32 DeviceAddress, _SYS_QSPIDEVINFO_P DevInfo);


#line 1105 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"
extern WORD _Sys_QspiProgram(_SYS_QSPIDEVINFO_P DevInfo, WORD* pBuffer, WORD BufferSize);
extern WORD _Sys_QspiProgramEx(_SYS_QSPIDEVINFO_P DevInfo, PTR32 p32Buffer, WORD BufferSize);


#line 1121 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"
extern void _Sys_QspiReadTable(PTR32 DeviceAddress, WORD* Buffer, WORD BufferSize, WORD CmdOpts);
extern void _Sys_QspiReadTable_RDID(PTR32 DeviceAddress, WORD* Buffer, WORD BufferSize);
extern void _Sys_QspiReadTable_SFDP(PTR32 DeviceAddress, WORD* Buffer, WORD BufferSize);





#line 1169 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"
extern WORD _Sys_I2CInit(WORD DelayValue, WORD IoPort, WORD SdaBit, WORD SclBit);
extern WORD _Sys_I2CInitBr(WORD DelayValue, WORD BrDir, WORD SdaBit, WORD SclBit);
extern WORD _Sys_I2CInitMk(WORD DelayValue, WORD MkDir, WORD SdaBit, WORD SclBit);

extern WORD _Sys_I2CWriteByteRegister(WORD Addr, WORD Register, WORD ByteVal);
extern WORD _Sys_I2CWriteWord(WORD Addr, WORD Word);
extern WORD _Sys_I2CWriteBytes(WORD Addr, WORD *pBytes, WORD uCount);
extern WORD _Sys_I2CWriteRegisterBytes(WORD Addr, WORD Register, WORD *pBytes, WORD uCount);

extern WORD _Sys_I2CReadRegisterByte(WORD Addr, WORD Register);
extern WORD _Sys_I2CReadBytes(WORD Addr, WORD *Buf, WORD NumBytes);
extern WORD _Sys_I2CReadRegisterBytes(WORD Addr, WORD Register, WORD *Buf, WORD NumBytes);




#line 1198 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"


#line 1204 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"
void _Sys_FarHeapInitEx(PTR32 HeapStart, DWORD HeapWordSize);


#line 1215 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"
PTR32 _Sys_FarHeapAlloc(WORD Size);


#line 1222 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"
void _Sys_FarHeapFree(PTR32 Ptr);


#line 1248 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"

typedef void (*_SYS_TASK_CALLBACK)(void);
typedef PTR32 _SYS_TASK_CALLBACK_P;
extern PTR32 _cptr32_type_SYSTASKCB(_SYS_TASK_CALLBACK P);



#line 1264 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"
typedef struct tagSYSTASK {
	_SYS_TASK_CALLBACK_P Callback_Far;
	struct tagSYSTASK *next;
	WORD ReloadValue;
	WORD tmo;
	} _SYS_TASK, *_SYS_TASK_P;

typedef struct tagSYSIDLETASK {
	_SYS_TASK_CALLBACK_P Callback_Far;
	struct tagSYSIDLETASK *next;
	} _SYS_IDLE_TASK, *_SYS_IDLE_TASK_P;

void _Sys_SchedSetResolution(WORD uSecPerTick);
WORD _Sys_SchedGetDelta(void);


void _Sys_SchedRtInit(WORD FreqHz, WORD *CStack, WORD CStackSize);
void _Sys_SchedRtSpreadSpectrum(WORD SpreadAmount);
WORD _Sys_SchedGetTicks(void);
WORD _Sys_SchedPollTicks(void);
void _Sys_SchedTick(void);

void _Sys_SchedRegisterIdleEx(_SYS_IDLE_TASK_P pTask, _SYS_TASK_CALLBACK_P pFunc);








void _Sys_SchedRegisterEx(_SYS_TASK_P pTask, _SYS_TASK_CALLBACK_P pFunc, WORD mSecReload);

void _Sys_SchedRegisterNoRepeatEx(_SYS_TASK_P pTask, _SYS_TASK_CALLBACK_P pFunc, WORD mSecReload);




void _Sys_SchedRegisterUSecEx(_SYS_TASK_P pTask, _SYS_TASK_CALLBACK_P pFunc, DWORD uSecReload);

void _Sys_SchedRegisterNoRepeatUSecEx(_SYS_TASK_P pTask, _SYS_TASK_CALLBACK_P pFunc, WORD uSecReload);





void _Sys_SchedRegisterRateEx(_SYS_TASK_P pTask, _SYS_TASK_CALLBACK_P pFunc, WORD RateReload);

void _Sys_SchedRegisterNoRepeatRateEx(_SYS_TASK_P pTask, _SYS_TASK_CALLBACK_P pFunc, WORD RateReload);


typedef const struct tagSYS_ASM_TASK_CALLBACK { WORD SysTaskCbID; } _SYS_ASM_TASK_CALLBACK[];
typedef PTR32 _SYS_ASM_TASK_CALLBACK_P;
extern PTR32 _cptr32_type_SYSASMTASKCB(_SYS_ASM_TASK_CALLBACK P);


WORD _Sys_SchedRtGetTicks(void);
void _Sys_SchedRtRegisterEx(_SYS_TASK_P pTask, _SYS_TASK_CALLBACK_P pFunc, DWORD uSecReload);

void _Sys_SchedRtRegisterAsmEx(_SYS_TASK_P pTask, _SYS_TASK_CALLBACK_P pFunc, DWORD uSecReload);




typedef void (*_SYS_SCHEDHOOK)(PTR32 SchedNext, _SYS_TASK_P pTask);
extern PTR32 _cptr32_type_SYSSCHEDHOOK(_SYS_SCHEDHOOK HookCb);
void _Sys_SchedSetHookEx(PTR32 p32HookCb);


typedef void (*_SYS_APC_CALLBACK)(WORD Count, WORD UserParm);
typedef PTR32 _SYS_APC_CALLBACK_P;
extern PTR32 _cptr32_type_SYSAPCCB(_SYS_APC_CALLBACK P);


typedef struct tagSYSAPC {
	DWORD ApcFunc_Far;
	struct tagSYSAPC *ApcNext;
	WORD ApcCount;
	WORD ApcUser;
	WORD ApcTimeout;
	} _SYS_APC, *_SYS_APC_P;
WORD _Sys_SchedRtApcIsBusy(_SYS_APC_P pApc);
WORD _Sys_SchedRtApcAbort(_SYS_APC_P pApc);


#line 1357 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"
WORD _Sys_SchedRtApcCallbackEx(_SYS_APC_P pApc, _SYS_APC_CALLBACK_P pFunc, WORD UserParam);

WORD _Sys_SchedRtApcCallbackDeferEx(_SYS_APC_P pApc, _SYS_APC_CALLBACK_P pFunc, WORD UserParam, WORD msTimeout);





void _Sys_TogglePortRt( WORD mHzFreq, WORD Port, WORD Bit );











#line 1 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\sys5000.h"


#line 1 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\sysP24.h"



#line 5 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\sysP24.h"




















































































































































void _DSPresetAll( void );
WORD _DSPalloc( WORD DSPcount );
void _DSPunload( WORD DSPid );
void _StartDSP( WORD DSPid );
void _DSPstart( WORD DSPid );
void _DSPpause( WORD DSPid );
void _DSPresume( WORD DSPid );


void _DSProutIN( WORD DSPid, WORD in1, WORD in2, WORD in3, WORD in4 );
void _DSProut( WORD DSPid, WORD out1, WORD out2, WORD out3, WORD out4 );
void _DSProutInEx( WORD DSPid, WORD routings[8] );
void _DSProutEx( WORD DSPid, WORD routings[8] );


DWORD _rdmem24( WORD page, WORD address );
void _wrmem24( WORD page, WORD address, DWORD data );


#line 4 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\sys5000.h"


extern WORD _data24_page, _data24_start;



PTR32 _Sys_GetData24Base(void);












































































































































































































typedef enum {
	SAM5XXX_PWM_EVSEL_NONE=0,
	SAM5XXX_PWM_EVSEL_SPDIF=1,
	SAM5XXX_PWM_EVSEL_USB0=2,
	SAM5XXX_PWM_EVSEL_USB1=3,
	SAM5XXX_PWM_EVSEL_SOFT=4,
	SAM5XXX_PWM_EVSEL_XWSBD0=5,
	} eSAM5XXX_PWM_EVSEL;

typedef enum {
	SAM5XXX_SPDIF_TX_CONTROL=0x0E00,
	SAM5XXX_SPDIF_RX_CONTROL=0x0E20,
	SAM5XXX_SPDIF_TX_FIFO=0x0E40,
	SAM5XXX_SPDIF_RX_FIFO=0x0E60,
	SAM5XXX_SPDIF_PWM=0x0E80
	} eSAM5XXX_SPDIF_BASE;

typedef enum {
	SAM5XXX_SPDIF_CTRL_REG  = 0x8000,
	SAM5XXX_SPDIF_INTR_REG  = 0x8002,
	SAM5XXX_SPDIF_CTRL_FIFO = 0x8004,
	SAM5XXX_SPDIF_STAT_REG	= 0x8006
	} eSAM5XXX_SPDIF_REG;





















































#line 295 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\sys5000.h"
typedef enum {
	SAM5XXX_SPDIFOUT_P2_15=0x00A1,
	SAM5XXX_SPDIFOUT_P7_10=0x00A2,

	SAM5XXX_SPDIFOUT_P2_0=0x01C1,
	SAM5XXX_SPDIFOUT_P7_11=0x01C2,
	SAM5XXX_SPDIFOUT_P7_13=0x01C3,

	} eSAM5XXX_SPDIFOUT_Pin;


#line 310 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\sys5000.h"
typedef enum {
	SAM5XXX_SPDIFIN_P2_0=0x00C1,
	SAM5XXX_SPDIFIN_P7_11=0x00C2,
	SAM5XXX_SPDIFIN_P7_13=0x00C3,

	SAM5XXX_SPDIFIN_P2_15=0x01A1,
	SAM5XXX_SPDIFIN_P7_10=0x01A2,

	} eSAM5XXX_SPDIFIN_Pin;

typedef enum {
	_SPDIFEV_IDLE,
	_SPDIFEV_NEW_SR,
	_SPDIFEV_FIFO_REF,
	} _eSPDIF_EVENT;


typedef WORD (*_SPDIF_EVENT_HANDLER)(_eSPDIF_EVENT EventType, WORD ParamLo, WORD ParamHi);
typedef PTR32 _SPDIF_EVENT_HANDLER_P;
extern PTR32 _cptr32_type_SPDIFEV(_SPDIF_EVENT_HANDLER P);




#line 336 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\sys5000.h"

typedef const WORD eSAM5XXX_INTERRUPT_HANDLER[];
typedef PTR32 eSAM5XXX_INTERRUPT_HANDLER_P;















typedef enum {
	intINT_0,
	intINT_1,
	intINT_2,
	intINT_3,
	intAUDIO_FRAME,
	intADC_EOC,
	intEXT_A,
	intHOST_IN,
	intHOST_OUT,
	intMIDI_IN_1,
	intMIDI_IN_2,
	intMIDI_OUT_1,
	intMIDI_OUT_2,
	intTIMER32,
	intINT_4,
	intINT_5,
	intEXT_B,
	intUSB_DEVICE,
	intETH,
	intSPDIF,
	intUSB_OTG,
	intTIMER_0,
	intTIMER_1,
	intINT_6,
	intINT_7,
	intUSB_OTG_WU,
	intEXT_C,
	intNAND,
	intQSPI_UNI,
	intQSPI_NOR,
	intQSPI_SRAM,
	int_MAX
	} eSAM5XXX_INTERRUPT_LEVEL;

void _Sys_IsrSet5xxx(eSAM5XXX_INTERRUPT_LEVEL eIL, eSAM5XXX_INTERRUPT_HANDLER_P IsrHandler, WORD IntFlags);


void _Sys_DmaConfig( WORD bDir, WORD mode );


void _Sys_DmaEnable( WORD bEnable );
void _Sys_DmaSetBufferAddr( WORD wDMApage, WORD wDMAaddr );



















void _TestSAM5000( WORD sinevol );








void _Sys_SwitchPll5xxx(WORD PllConfig, WORD bUseOsc2);


#line 441 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\sys5000.h"
typedef PTR32 _SYS_OSCSWITCHFUNC_P;
typedef void (*_SYS_OSCSWITCHFUNC)(WORD OscCmd, WORD UserParam);
PTR32 _cptr32_type_OSCSW(_SYS_OSCSWITCHFUNC p);



#line 456 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\sys5000.h"
void _Sys_ClockInit(WORD DefaultSamplerate4, _SYS_OSCSWITCHFUNC_P OscSwitchFunc);


#line 461 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\sys5000.h"
WORD _Sys_ClockGetSamplingRate(void);


#line 466 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\sys5000.h"
void _Sys_ClockSetSamplingRate(WORD SamplingRate4, WORD ClockFuncUserParam);


#line 471 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\sys5000.h"
WORD _Sys_P24CyclesPerFrame(void);


#line 479 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\sys5000.h"
typedef enum {
	SAM5XXX_PWMOUT_NONE=0,
	SAM5XXX_PWMOUT_P2_1=0x1A1,
	SAM5XXX_PWMOUT_P7_12=0x2B6,
	SAM5XXX_PWMOUT_P7_14=0x3B4,
	} eSAM5XXX_PWMOUT_Pin;


#line 491 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\sys5000.h"
void _Sys_PwmInit(eSAM5XXX_PWMOUT_Pin PwmPin);


#line 546 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\sys5000.h"
void _Sys_PwmSetReference(eSAM5XXX_PWM_EVSEL EvSelector, WORD EvDivide, WORD msEventDuration);
void _Sys_PwmSetReferenceUSec(eSAM5XXX_PWM_EVSEL EvSelector, WORD EvDivide, WORD usEventDuration);
void _Sys_PwmSetReferenceCycles(eSAM5XXX_PWM_EVSEL EvSelector, WORD EvDivide, DWORD SysClkPerEvent);


#line 559 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\sys5000.h"
void _Sys_PwmTune(signed FifoFill);


#line 576 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\sys5000.h"
void _Sys_PwmWriteCorrEx(PTR32 CorrTab);



#line 1378 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\system.h"









WORD _TestRAM( WORD startpage, WORD startaddress, WORD size );





WORD _TestROM( void );








WORD _Sys_CheckSoundBank( WORD page );






extern WORD _Sys_SbGetName(WORD SbPage, WORD *NameBuffer, WORD BufSize);
extern WORD _Sys_SbGetNameEx(PTR32 SbAddress, WORD *NameBuffer, WORD BufSize);


extern WORD _Sys_SbGetVersion(WORD SbPage, WORD *NameBuffer, WORD BufSize);
extern WORD _Sys_SbGetVersionEx(PTR32 SbAddress, WORD *NameBuffer, WORD BufSize);

WORD _TestFir( void );






WORD _TestTone_InitEx( WORD BaseAmplitude );

void _TestTone_Vol( WORD DSPid, WORD value );

void _TestTone_Freq( WORD DSPid, WORD value );


void _TestTone_Mix( WORD DSPid, WORD mix1, WORD mix2, WORD mix3, WORD mix4 );

void _TestTone_FreqMix( WORD DSPid, WORD Index, WORD FreqHz, WORD Mix );






#line 30 "C:\Users\abhis\Downloads\karma electric\try3\main.c"
#line 1 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\DreamBoards.h"



#line 19 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\DreamBoards.h"























#line 50 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\DreamBoards.h"
extern void _Board_InitAK4384(WORD PortAndPin);


#line 55 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\DreamBoards.h"












#line 69 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\DreamBoards.h"









#line 81 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\DreamBoards.h"



#line 86 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\DreamBoards.h"























#line 112 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\DreamBoards.h"



#line 117 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\DreamBoards.h"














#line 141 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\DreamBoards.h"


#line 145 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\DreamBoards.h"



































#line 182 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\DreamBoards.h"









#line 193 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\DreamBoards.h"











#line 206 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\DreamBoards.h"



#line 211 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\DreamBoards.h"


#line 215 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\DreamBoards.h"











































#line 260 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\DreamBoards.h"
















#line 278 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\DreamBoards.h"


















#line 298 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\DreamBoards.h"













#line 313 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\DreamBoards.h"


















#line 335 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\DreamBoards.h"












































































#line 31 "C:\Users\abhis\Downloads\karma electric\try3\main.c"



#line 1 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\libusb.h"



extern WORD _libusb_GetVersion(void);


#line 14 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\libusb.h"











#line 27 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\libusb.h"

typedef PTR32 _USB_CALLBACK_P;
typedef PTR32 _USB_DDE_P;
typedef PTR32 _USB_DESC_P;
typedef const struct { WORD UsbCbID; } _USB_CALLBACK[];
typedef const struct { WORD UsbDdeID; } _USB_DDE[];
extern PTR32 _cptr32_type_USBCB(_USB_CALLBACK p);
extern PTR32 _cptr32_type_USBDDE(_USB_DDE p);
extern PTR32 _cptr32_type_USBDESC(const unsigned short* p);













extern _USB_DDE _USBDDE_MidiClass;
extern _USB_DDE _USBDDE_AudioClass;



typedef const struct {
	WORD HwConfig;
	} _USBDDE_ISP1181_PARAM;

typedef const struct {
	WORD HwConfig;
	WORD uDsp;
	} _USBDDE_ISP1181AC_PARAM;




extern _USB_DDE _USBDDE_ISP1181;


extern _USB_DDE _USBDDE_ISP1181AC;




extern _USB_DDE _USBDDE_ISP1582;


extern _USB_DDE _USBDDE_ISP1582AC;




extern _USB_DDE _USBDDE_SAM3x16;


extern _USB_DDE _USBDDE_SAM3x16AC;










extern WORD _USBDDE_SAM5xxx_IOCTL(WORD uUsbDevice, WORD IoCtl, WORD Param);


extern _USB_DDE _USBDDE_SAM5xxx;


extern _USB_DDE _USBDDE_SAM5xxxAC;




extern _USB_DDE _USBDDE_SAM5xxxAC16;








extern _USB_DDE _USBDDE_SAM5xxxAC24;





extern _USB_DDE _USBDDE_SAM5xxxAC_SRC;


extern void _USB_Initialize(void);

extern void _USB_InitRegisterEntry(_USB_DDE_P DDE, DWORD wUser);



extern void _USB_InitRegisterDfuDetachHandler(_USB_CALLBACK_P cbDfuDetachProc, WORD bWillDetach);







extern WORD _USB_GetStatus(void);








#line 159 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\libusb.h"
typedef enum {
	USBHOOK_MIDI_OUT_PUSH=0x4D03,
	USBHOOK_MIDI_IN_PUSH=0x4D06,
	USBHOOK_AUDIO_SETOUTVOLUME=0x4109,
	USBHOOK_AUDIO_SETOUTMUTE=0x410A,
	USBHOOK_AUDIO_SETINVOLUME=0x410B,
	USBHOOK_AUDIO_SETMASTERVOLUME=0x410C,
	USBHOOK_AUDIO_GETOUTPEAK=0x4108,
	USBHOOK_AUDIO_SET_SR=0x4107,
	} eUSB_DRIVER_HOOK;


#line 175 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\libusb.h"
extern _USB_CALLBACK_P _USB_SetDriverHook(eUSB_DRIVER_HOOK HookID, _USB_CALLBACK_P DriverHookFunction);


extern WORD _USB_InitStartupEx(_USB_DESC_P UsbDesc, PTR32 UsbBaseAddress, WORD IntPort, WORD IntBit);










extern WORD _USB_Poll(void);
extern void _USB_SetPowerState(WORD bBusPowered);



#line 210 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\libusb.h"
typedef WORD (*_USB_VENDOR_CALLBACK)(WORD bRequestType, WORD bRequest, WORD wValue, WORD wLength, WORD wIndex, PTR32 p32FromHostData);
extern PTR32 _cptr32_type_USB_VENDOR_CALLBACK(_USB_VENDOR_CALLBACK cbFunc);


extern void _USB_SetVendorRequestHandlerEx(PTR32 p32VendorProc);



#line 226 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\libusb.h"
extern WORD _USB_SetControlPacketRxBuffer(WORD *FromHostBuffer, WORD FromHostBufferWordSize);
extern WORD _USB_SetControlPacketRxBufferEx(PTR32 p32FromHostBuffer, WORD FromHostBufferWordSize);


#line 234 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\libusb.h"
extern WORD _USB_SendControlPacket(WORD *Content, WORD BytesToSend);
extern WORD _USB_SendControlPacketEx(PTR32 p32Content, WORD BytesToSend);




















#line 267 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\libusb.h"

typedef struct {
	WORD *BufPtr;
	WORD Index;
	WORD RequestSize;
	} *_USB_DESCRIPTOR_P;

typedef enum {
	USBEVH_VOID,
	USBEVH_DESCRIPTOR_HANDLER,
	USBEVH_SET_SAMPLINGRATE,
	USBEVH_GET_SAMPLINGRATE,
	USBEVH_FIFO_DELTA,
	USBEVH_CONFIGURED,
	USBEVH_SUSPENDED,

	USBEVH_MAX
	} eUSB_EVENT_HOOK;

typedef enum {
	USBEVHS_DEFAULT,
	USBEVHS_HANDLED
	} eUSB_EVENT_STATUS;

typedef PTR32 _USB_EVENTHOOK_P;
typedef eUSB_EVENT_STATUS (*_USB_EVENTHOOK)(eUSB_EVENT_HOOK Event, WORD Param);
extern PTR32 _cptr32_type_USBEVH(_USB_EVENTHOOK p);


extern void _USB_SetEventHook(_USB_EVENTHOOK_P UsbEventFunction);

typedef void (*_USB_MIDICALLBACKFUNC)(DWORD MidiEvent);
typedef PTR32 _USB_MIDICALLBACKFUNC_P, _USBHOST_MIDICALLBACKFUNC_P;
extern PTR32 _cptr32_type_UCBMIDI(_USB_MIDICALLBACKFUNC p);






extern void _USBAC_OutputVolume(WORD value);
extern void _USBAC_OutputVolumeEx(WORD value, WORD ChnMask);
extern void _USBAC_SetDefaultSamplingRate(WORD Rate4);
extern WORD _USBAC_GetOutputPeak(WORD channel);





extern void _USBAC_SetHostOutputVolume(WORD Channel, WORD Volume);











extern void _USBAC_SetFeature(WORD FeatureBits);



extern void _USBAC_EnableClockManager(void);


extern void _USBMC_Send( WORD data );
extern WORD _USBMC_SendMidiEvent(DWORD Event);
extern WORD _USBMC_PollMidiEvent(DWORD *Event);



extern WORD _USBMC_PollMidiQueue(PTR32 *pMidiQueue);


extern void _USBMC_FlushMidiQueue(void);


#line 355 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\libusb.h"
extern void _USBMC_ProcessMidiQueueEx(_USB_MIDICALLBACKFUNC_P Callback);



#line 368 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\libusb.h"
extern void _USBMC_InitSetBuffer(WORD *InAddr, WORD cwInSize, WORD *OutAddr, WORD cwOutSize);



#line 388 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\libusb.h"


extern void _USBDDE_SAM5xxx_RpcEnable(void);





typedef struct {
	WORD RpcBuffer[256];
	} _USBDDE_SAM5xxxRPCBUFFER_S, *_USBDDE_SAM5xxxRPCBUFFER_P;
extern void _USBDDE_SAM5xxxAC_RpcEnable(_USBDDE_SAM5xxxRPCBUFFER_P RpcBuffer);


typedef enum {
	USBRPCPROTOCOL_VERSION=0x0110,
	USBRPCPROTO_SYSTEM_FIRST=0x0F00,
	USBRPCPROTO_SYSTEM_GET_VERSION=0x0F00,
	USBRPCPROTO_SYSTEM_GET_PROTOCOL_LIST=0x0F01,
	USBRPCPROTO_SYSTEM_LAST=0x0F0F,

	USBRPCPROTO_UXUPDATE_FIRST=0x1000,
	USBRPCPROTO_UXUPDATE_GET_RANGES=0x1000,
	USBRPCPROTO_UXUPDATE_START_PROGRAMMING=0x1001,
	USBRPCPROTO_UXUPDATE_END_PROGRAMMING=0x1002,
	USBRPCPROTO_UXUPDATE_PROGRAM=0x1003,
	USBRPCPROTO_UXUPDATE_SYNC=0x1004,
	USBRPCPROTO_UXUPDATE_FINALIZE=0x1005,
	USBRPCPROTO_UXUPDATE_VERIFY=0x1006,
	USBRPCPROTO_UXUPDATE_STATE=0x1007,
	USBRPCPROTO_UXUPDATE_UI=0x1008,
	USBRPCPROTO_UXUPDATE_LAST=0x1008,

	USBRPCPROTO_PCMTFR_FIRST=0x1010,
	USBRPCPROTO_PCMTFR_GET_SYSTEM_INFO=0x1010,
	USBRPCPROTO_PCMTFR_READ_BLOCK=0x1011,
	USBRPCPROTO_PCMTFR_WRITE_BLOCK=0x1012,
	USBRPCPROTO_PCMTFR_PLAYBACK=0x1013,
	USBRPCPROTO_PCMTFR_RECORD_START=0x1014,
	USBRPCPROTO_PCMTFR_STOP=0x1015,
	USBRPCPROTO_PCMTFR_LAST=0x1018,

	USBRPCPROTO_CUSTOM=0x2000
	} _eUSBRPC_PROTOCOL;

typedef enum {
	USBRPCSTATUS_SUCCESS=0,
	USBRPCSTATUS_UXUPDATE_FINALIZE_FAILED=0x1005,
	USBRPCSTATUS_UXUPDATE_VERIFY_FAILED=0x1006,

	USBRPCSTATUS_INVALID_PROTOCOL=0xFFFE,
	USBRPCSTATUS_UNKNOWN_ERROR=0xFFFF
	} _eUSBRPC_STATUS;

typedef struct {
	WORD	RequestID;
	WORD	ParameterCount;
	WORD	FragmentSize;
	WORD	FragmentCount;
	WORD	ParameterArray[1];
	} _USBRPC_REQUEST, *_USBRPC_REQUEST_P;

typedef eUSB_EVENT_STATUS (*_USBRPC_PROTOCOL_HANDLER_P)(_USBRPC_REQUEST_P Request);
typedef struct { _USBRPC_PROTOCOL_HANDLER_P Handler; SEGMENT_MARKER Segment; } _USBRPC_PROTOCOL_HANDLER_DEF;


typedef struct {
	PTR32	FragmentData;
	WORD	FragmentSize;
	WORD	FragmentCountRemaining;
	DWORD	_ReservedLong;
	WORD	_ReservedShort;
	} _USBRPC_FRAGMENT_INFO, *_USBRPC_FRAGMENT_INFO_P;

typedef PTR32 _USBRPC_FRAGMENT_HANDLER_P;
typedef eUSB_EVENT_STATUS (*_USBRPC_FRAGMENT_HANDLER)(_USBRPC_FRAGMENT_INFO_P Tfr);
extern PTR32 _cptr32_type_USBRPCFRAG(_USBRPC_FRAGMENT_HANDLER p);


typedef struct _tagUSBRPC_PROTOCOL {
	_USBRPC_PROTOCOL_HANDLER_DEF UsbRpcRequestHandler;
	WORD	ProtocolBegin, ProtocolEnd;
	struct _tagUSBRPC_PROTOCOL *up_next;
	} _USBRPC_PROTOCOL, *_USBRPC_PROTOCOL_P;




extern void _USBRPC_RegisterProtocol(_USBRPC_PROTOCOL_P Proto);


#line 483 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\libusb.h"
extern void _USBRPC_ReceiveDataEx(PTR32 Buffer32, WORD WordSize, _USBRPC_FRAGMENT_HANDLER_P UsbRpcFragmentHandler);
extern void _USBRPC_ReceiveData(WORD *Buffer, WORD WordSize, _USBRPC_FRAGMENT_HANDLER_P UsbRpcFragmentHandler);


#line 497 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\libusb.h"
extern void _USBRPC_SendReplyEx(WORD ReplyStatus, PTR32 p32ReplyData, WORD ReplyWordSize);
extern void _USBRPC_SendReply(WORD ReplyStatus, WORD *ReplyData, WORD ReplyWordSize);



#line 507 "C:\Users\abhis\AppData\Local\Programs\DREAM\SamVS-C\include\libusb.h"



extern void _USBHOST_Drv5xxxSetPort(WORD UsbPort);
extern void _USBHOST_Init(void);
extern void _USBHOST_StorageRegister(void);
extern void _USBHOST_MidiRegister(_USB_MIDICALLBACKFUNC_P Callback);
extern void _USBHOST_Poll(void);
extern DWORD _USBHOST_DeviceConnected(void);
extern void _USBHOST_Startup(void);
extern void _USBHOST_StartupFullSpeed(void);
extern WORD _USBHOST_IsConnected(void);


extern void _USBHOST_Send( WORD data );

extern WORD _USBHOST_SendMidi(DWORD MidiEvent);


struct tagDISK;
extern void _USBHOST_DiskSetup(struct tagDISK *pDisk);
extern DWORD _USBHOST_DiskGetSizeMB(void);









#line 35 "C:\Users\abhis\Downloads\karma electric\try3\main.c"

#line 1 "C:\Users\abhis\Downloads\karma electric\try3\dspDesigner.h"





typedef struct biquadTag
{	struct _tagFILTER_PARAM *filterParameters;
	WORD *type;
	WORD *xoverType;
	DWORD *frequency;
	int numberOfBand;
	int channel;
} BiquadParameters;

typedef struct biquadParamsTabTag
{	WORD nrpn;
	WORD functionId;
	BiquadParameters *parametersTable;
} BiquadParamsTable;

typedef struct biquadCommandParamsTabTag
{	WORD command;
	BiquadParameters *parametersTable;
} BiquadCommandParamsTable;

typedef struct UpdateCoeffCallback_tag
{
	PTR32 BIQUAD_FlatFuncPtr;
	PTR32 BIQUAD_UpdateCoeffFuncPtr;
} UpdateCoeffCallback;

void dspDesigner_InitAndRoute (void);
void dspDesigner_InitNrpnFunction (void);
WORD dichotomicSearch( PTR32 table, WORD rowSize, WORD itemIndex, WORD tableLen, WORD valueToSearch );
WORD dspNrpnHandlerCallback ( PTR32 FunctionPointer32, WORD nrpn, WORD dspId, WORD processId, DWORD value, WORD format );
extern WORD dsp[4];

WORD dsp1InitAndRoute(void);
extern WORD dsp1pcs[6];


extern const WORD nrpn1List[0x000D][2];
extern WORD dsp1NrpnHandler( WORD nrpn, WORD dspId, WORD processId, DWORD value, WORD format );

WORD dsp2InitAndRoute(void);
extern WORD dsp2pcs[5];


extern const WORD nrpn2List[0x000E][2];
extern WORD dsp2NrpnHandler( WORD nrpn, WORD dspId, WORD processId, DWORD value, WORD format );

WORD dsp3InitAndRoute(void);
extern WORD dsp3pcs[6];


extern const WORD nrpn3List[0x000D][2];
extern WORD dsp3NrpnHandler( WORD nrpn, WORD dspId, WORD processId, DWORD value, WORD format );

WORD dsp4InitAndRoute(void);
extern WORD dsp4pcs[5];


extern const WORD nrpn4List[0x000E][2];
extern WORD dsp4NrpnHandler( WORD nrpn, WORD dspId, WORD processId, DWORD value, WORD format );


#line 37 "C:\Users\abhis\Downloads\karma electric\try3\main.c"
#line 1 "C:\Users\abhis\Downloads\karma electric\try3\midictrl.h"



WORD dspDesigner_HandleMidiEvent( DWORD Ev );
WORD dspDesigner_HandleNRPN( WORD ch, WORD nrpn, DWORD v, WORD format );

#line 17 "C:\Users\abhis\Downloads\karma electric\try3\midictrl.h"












typedef struct
{
	WORD pnt;
	WORD Buffer[32];
} SysEx;

void sendSysExMessage( WORD id, unsigned char msg );
DWORD swapDword(DWORD data);



#line 38 "C:\Users\abhis\Downloads\karma electric\try3\main.c"







extern const unsigned short UsbDescriptorInfo[];












WORD UsbMidiInBuf[64], UsbMidiOutBuf[348];


#line 65 "C:\Users\abhis\Downloads\karma electric\try3\main.c"
const unsigned short UsbDescriptorInfo[140] = {
    0x0112, 0x0008, 0x0082, 0x0000, 0x0000, 0x0002, 0x0000, 0x0000,
    0x0004, 0x000D, 0x0011, 0x001E, 0x0031, 0x0308, 0x006E, 0x002F,
    0x0061, 0x031A, 0x0044, 0x0052, 0x0045, 0x0041, 0x004D, 0x0020,
    0x0053, 0x002E, 0x0041, 0x002E, 0x0053, 0x002E, 0x0326, 0x0053,
    0x0041, 0x004D, 0x0035, 0x0030, 0x0030, 0x0030, 0x0020, 0x0045,
    0x0076, 0x0061, 0x006C, 0x0020, 0x0042, 0x006F, 0x0061, 0x0072,
    0x0064, 0x0322, 0x0046, 0x0075, 0x006C, 0x006C, 0x0053, 0x0070,
    0x0065, 0x0065, 0x0064, 0x0020, 0x0043, 0x006F, 0x006E, 0x0066,
    0x0069, 0x0067, 0x0012, 0x0112, 0x0101, 0x0000, 0x4000, 0x2485,
    0x433D, 0x0100, 0x0302, 0x0100, 0x0065, 0x0209, 0x0065, 0x0102,
    0x8004, 0x0932, 0x0004, 0x0000, 0x0101, 0x0000, 0x2409, 0x0001,
    0x0901, 0x0100, 0x0901, 0x0104, 0x0200, 0x0301, 0x0300, 0x2407,
    0x0001, 0x4101, 0x0600, 0x0224, 0x0101, 0x0603, 0x0224, 0x0202,
    0x0903, 0x0324, 0x0301, 0x0201, 0x0301, 0x2409, 0x0203, 0x0104,
    0x0101, 0x0903, 0x0305, 0x4002, 0x0000, 0x0000, 0x2505, 0x0101,
    0x0901, 0x8305, 0x4002, 0x0000, 0x0000, 0x2505, 0x0101, 0x0003,
    0x0502, 0x0006, 0x0042, 0x0000, 0x004C, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0080
    };



void InitUSB( void )
{
    if( UsbDescriptorInfo[3] != 0 )
        _USBDDE_SAM5xxx_IOCTL(0,1,0x6E | 0x00);
    else
        _USBDDE_SAM5xxx_IOCTL(0,1,0x6E | 0x80);
    _USBDDE_SAM5xxx_IOCTL(0,2, 0);
    _USB_Initialize();







    _USB_InitRegisterEntry(_cptr32_type_USBDDE(_USBDDE_SAM5xxx), 0);
    _USB_InitRegisterEntry(_cptr32_type_USBDDE(_USBDDE_MidiClass), 0);
    _USB_InitStartupEx(_cptr32_type_USBDESC(UsbDescriptorInfo),0x0B000000,0x93,((21-1)-16));
    _USBMC_InitSetBuffer(UsbMidiInBuf, sizeof(UsbMidiInBuf), UsbMidiOutBuf, sizeof(UsbMidiOutBuf));

    _USBDDE_SAM5xxx_IOCTL(0,2, 1);
}


void main (void)
{
    DWORD midi_event;
    WORD activity_counter;

{ if((_rdio(0x01)& 0x0004)==0) _andio(0x08,~(1<<4)), _orio(0x70, 1<< 15); };
 _orio(0xE0, 1<< 15);
 _orio(0x0A, 0x8101);;
;

    _DSPresetAll();
    dspDesigner_InitAndRoute();
    dspDesigner_InitNrpnFunction();






#line 137 "C:\Users\abhis\Downloads\karma electric\try3\main.c"
    _Sys_SwitchPll5xxx( 0xD10C, 0 );





    InitUSB();
    _wrio(0x04, _Sys_CalcTimerReload(31250));
    _orio(0x01,0x0800 );

    _wrio(0x02,0x10000-(0.00987* 31250 *16) );
    _orio(0x01,0x0200 );

    activity_counter = 0;

    while (1)
    {




        _USB_Poll();
        if(_USBMC_PollMidiEvent(&midi_event))

        {
            dspDesigner_HandleMidiEvent( midi_event );
            if( !activity_counter ) activity_counter = 20;
        }

        if( _rdtr0())
        {
            if( activity_counter > 0 )
            {
                if( --activity_counter > 10 )_andio(0xE0, ~(1<< 15));
                else _orio(0xE0, 1<< 15);
            }
        }
    }
}

void Send( UCHAR data )
{



    _USBMC_Send( data );

}
