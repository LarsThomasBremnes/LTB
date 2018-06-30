
#define LTB_Windows

/*
A companion piece to LTB.h, containing a fair amount of basic Win32 functions.
*/

#define _AMD64_

#ifdef __cplusplus
extern "C" {
#endif

#define CALLBACK			__stdcall
#define WINAPI				__stdcall
#define WINAPIV             __cdecl
#define APIENTRY			WINAPI
#define APIPRIVATE			__stdcall
#define PASCAL				__stdcall
#define DECLSPEC_IMPORT		__declspec(dllimport)
#define WINBASEAPI			DECLSPEC_IMPORT
#define WINMMAPI			DECLSPEC_IMPORT
#define WINGDIAPI			DECLSPEC_IMPORT
#define UNALIGNED


#ifdef UNICODE
#define MessageBox MessageBoxW
#else
#define MessageBox MessageBoxA
#endif // !UNICODE


#define PAGE_NOACCESS				0x01   
#define PAGE_READONLY				0x02   
#define PAGE_READWRITE				0x04
#define PAGE_WRITECOPY				0x08
#define PAGE_GUARD					0x100
#define PAGE_NOCACHE				0x200   
#define PAGE_WRITECOMBINE			0x400   
#define PAGE_REVERT_TO_FILE_MAP		0x80000000
#define MEM_COMMIT					0x1000
#define MEM_RESERVE					0x2000
#define MEM_DECOMMIT				0x4000
#define MEM_RELEASE					0x8000
#define MEM_FREE					0x10000
#define MEM_PRIVATE					0x20000
#define MEM_MAPPED					0x40000
#define MEM_RESET					0x80000
#define MEM_TOP_DOWN				0x100000
#define MEM_WRITE_WATCH				0x200000
#define MEM_PHYSICAL				0x400000
#define MEM_ROTATE					0x800000
#define MEM_DIFFERENT_IMAGE_BASE_OK 0x800000
#define MEM_RESET_UNDO				0x1000000
#define MEM_LARGE_PAGES				0x20000000
#define MEM_4MB_PAGES				0x80000000
#define SEC_FILE					0x800000
#define SEC_IMAGE					0x1000000
#define SEC_PROTECTED_IMAGE			0x2000000
#define SEC_RESERVE					0x4000000
#define SEC_COMMIT					0x8000000
#define SEC_NOCACHE					0x10000000
#define SEC_WRITECOMBINE			0x40000000
#define SEC_LARGE_PAGES				0x80000000
#define SEC_IMAGE_NO_EXECUTE (SEC_IMAGE | SEC_NOCACHE)   
#define MEM_IMAGE     SEC_IMAGE   
#define WRITE_WATCH_FLAG_RESET 0x01   
#define MEM_UNMAP_WITH_TRANSIENT_BOOST 0x01   


// Window Messages

#define WM_NULL								0x0000
#define WM_CREATE							0x0001
#define WM_DESTROY							0x0002
#define WM_MOVE								0x0003
#define WM_SIZE								0x0005

#define WM_ACTIVATE							0x0006
//WM_ACTIVATE state values
#define   WA_INACTIVE   0
#define   WA_ACTIVE    1
#define   WA_CLICKACTIVE 2

#define WM_SETFOCUS							0x0007
#define WM_KILLFOCUS						0x0008
#define WM_ENABLE							0x000A
#define WM_SETREDRAW						0x000B
#define WM_SETTEXT							0x000C
#define WM_GETTEXT							0x000D
#define WM_GETTEXTLENGTH					0x000E
#define WM_PAINT							0x000F
#define WM_CLOSE							0x0010
#ifndef _WIN32_WCE
	#define WM_QUERYENDSESSION				0x0011
	#define WM_QUERYOPEN					0x0013
	#define WM_ENDSESSION					0x0016
#endif
#define WM_QUIT								0x0012
#define WM_ERASEBKGND						0x0014
#define WM_SYSCOLORCHANGE					0x0015
#define WM_SHOWWINDOW						0x0018
#define WM_WININICHANGE						0x001A
#if(WINVER >= 0x0400)
#define WM_SETTINGCHANGE        WM_WININICHANGE
#endif // WINVER >= 0x0400 


#define WM_DEVMODECHANGE				0x001B
#define WM_ACTIVATEAPP					0x001C
#define WM_FONTCHANGE					0x001D
#define WM_TIMECHANGE					0x001E
#define WM_CANCELMODE					0x001F
#define WM_SETCURSOR					0x0020
#define WM_MOUSEACTIVATE				0x0021
#define WM_CHILDACTIVATE				0x0022
#define WM_QUEUESYNC					0x0023
#define WM_GETMINMAXINFO				0x0024

#define WM_NCCREATE                     0x0081
#define WM_NCDESTROY                    0x0082
#define WM_NCCALCSIZE                   0x0083
#define WM_NCHITTEST                    0x0084
#define WM_NCPAINT                      0x0085
#define WM_NCACTIVATE                   0x0086
#define WM_GETDLGCODE                   0x0087
#ifndef _WIN32_WCE
#define WM_SYNCPAINT                    0x0088
#endif
#define WM_NCMOUSEMOVE                  0x00A0
#define WM_NCLBUTTONDOWN                0x00A1
#define WM_NCLBUTTONUP                  0x00A2
#define WM_NCLBUTTONDBLCLK              0x00A3
#define WM_NCRBUTTONDOWN                0x00A4
#define WM_NCRBUTTONUP                  0x00A5
#define WM_NCRBUTTONDBLCLK              0x00A6
#define WM_NCMBUTTONDOWN                0x00A7
#define WM_NCMBUTTONUP                  0x00A8
#define WM_NCMBUTTONDBLCLK              0x00A9

#define WM_INPUT						0x00FF
#define WM_KEYFIRST						0x0100
#define WM_KEYDOWN						0x0100
#define WM_KEYUP						0x0101
#define WM_CHAR							0x0102
#define WM_DEADCHAR						0x0103
#define WM_SYSKEYDOWN					0x0104
#define WM_SYSKEYUP						0x0105
#define WM_SYSCHAR						0x0106
#define WM_SYSDEADCHAR					0x0107
#define WM_UNICHAR						0x0109
#define WM_KEYLAST						0x0109
#define UNICODE_NOCHAR					0xFFFF

#ifdef UNICODE
#define DefWindowProc DefWindowProcW
#else
#define DefWindowProc DefWindowProcA
#endif

#define PM_NOREMOVE			0x0000
#define PM_REMOVE			0x0001
#define PM_NOYIELD			0x0002
#define PM_QS_INPUT			(QS_INPUT << 16)
#define PM_QS_POSTMESSAGE	((QS_POSTMESSAGE | QS_HOTKEY | QS_TIMER) << 16)
#define PM_QS_PAINT			(QS_PAINT << 16)
#define PM_QS_SENDMESSAGE	(QS_SENDMESSAGE << 16)

#ifdef UNICODE
#define PeekMessage PeekMessageW
#else
#define PeekMessage PeekMessageA
#endif // !UNICODE

#define SW_HIDE					 0
#define SW_SHOWNORMAL			 1
#define SW_NORMAL				 1
#define SW_SHOWMINIMIZED		 2
#define SW_SHOWMAXIMIZED		 3
#define SW_MAXIMIZE				 3
#define SW_SHOWNOACTIVATE		 4
#define SW_SHOW					 5
#define SW_MINIMIZE				 6
#define SW_SHOWMINNOACTIVE		 7
#define SW_SHOWNA				 8
#define SW_RESTORE				 9
#define SW_SHOWDEFAULT			10
#define SW_FORCEMINIMIZE		11
#define SW_MAX					11

#ifdef UNICODE
#define DispatchMessage DispatchMessageW
#else
#define DispatchMessage DispatchMessageA
#endif // !UNICODE



#ifdef UNICODE
#define SetWindowLong SetWindowLongW
#else
#define SetWindowLong SetWindowLongA
#endif // !UNICODE

#define GWL_WNDPROC			( -4)
#define GWL_HINSTANCE		( -6)
#define GWL_HWNDPARENT		( -8)
#define GWL_STYLE			(-16)
#define GWL_EXSTYLE			(-20)
#define GWL_USERDATA		(-21)
#define GWL_ID				(-12)

#define CW_USEDEFAULT    ((int)0x80000000)


#define CS_VREDRAW					0x0001
#define CS_HREDRAW					0x0002
#define CS_DBLCLKS					0x0008
#define CS_OWNDC					0x0020
#define CS_CLASSDC					0x0040
#define CS_PARENTDC					0x0080
#define CS_NOCLOSE					0x0200
#define CS_SAVEBITS					0x0800
#define CS_BYTEALIGNCLIENT			0x1000
#define CS_BYTEALIGNWINDOW			0x2000
#define CS_GLOBALCLASS				0x4000

#ifdef UNICODE
#define GetWindowLong GetWindowLongW
#else
#define GetWindowLong GetWindowLongA
#endif // !UNICODE

#ifdef UNICODE
#define RegisterClass RegisterClassW
#else
#define RegisterClass RegisterClassA
#endif // !UNICODE


// Ternary raster operations
#define SRCCOPY			(DWORD)0x00CC0020 // dest = source          
#define SRCPAINT		(DWORD)0x00EE0086 // dest = source OR dest     
#define SRCAND			(DWORD)0x008800C6 // dest = source AND dest     
#define SRCINVERT		(DWORD)0x00660046 // dest = source XOR dest     
#define SRCERASE		(DWORD)0x00440328 // dest = source AND (NOT dest ) 
#define NOTSRCCOPY		(DWORD)0x00330008 // dest = (NOT source)      
#define NOTSRCERASE		(DWORD)0x001100A6 // dest = (NOT src) AND (NOT dest) 
#define MERGECOPY		(DWORD)0x00C000CA // dest = (source AND pattern)   
#define MERGEPAINT		(DWORD)0x00BB0226 // dest = (NOT source) OR dest  
#define PATCOPY			(DWORD)0x00F00021 // dest = pattern         
#define PATPAINT		(DWORD)0x00FB0A09 // dest = DPSnoo         
#define PATINVERT		(DWORD)0x005A0049 // dest = pattern XOR dest    
#define DSTINVERT		(DWORD)0x00550009 // dest = (NOT dest)       
#define BLACKNESS		(DWORD)0x00000042 // dest = BLACK         
#define WHITENESS		(DWORD)0x00FF0062 // dest = WHITE         

#define VK_LBUTTON    0x01
#define VK_RBUTTON    0x02
#define VK_CANCEL     0x03
#define VK_MBUTTON    0x04  // NOT contiguous with L & RBUTTON 

#if(_WIN32_WINNT >= 0x0500)
#define VK_XBUTTON1    0x05  // NOT contiguous with L & RBUTTON 
#define VK_XBUTTON2    0x06  // NOT contiguous with L & RBUTTON 
#endif // _WIN32_WINNT >= 0x0500 

// 0x07 : unassigned


#define VK_BACK		0x08
#define VK_TAB		0x09

// 0x0A - 0x0B : reserved


#define VK_CLEAR	0x0C
#define VK_RETURN	0x0D

#define VK_SHIFT	0x10
#define VK_CONTROL	0x11
#define VK_MENU		0x12
#define VK_PAUSE	0x13
#define VK_CAPITAL	0x14

#define VK_KANA      0x15
#define VK_HANGEUL    0x15 // old name - should be here for compatibility 
#define VK_HANGUL     0x15
#define VK_JUNJA     0x17
#define VK_FINAL     0x18
#define VK_HANJA     0x19
#define VK_KANJI     0x19

#define VK_ESCAPE     0x1B

#define VK_CONVERT    0x1C
#define VK_NONCONVERT   0x1D
#define VK_ACCEPT     0x1E
#define VK_MODECHANGE   0x1F

#define VK_SPACE     0x20
#define VK_PRIOR     0x21
#define VK_NEXT      0x22
#define VK_END      0x23
#define VK_HOME      0x24
#define VK_LEFT      0x25
#define VK_UP       0x26
#define VK_RIGHT     0x27
#define VK_DOWN      0x28
#define VK_SELECT     0x29
#define VK_PRINT     0x2A
#define VK_EXECUTE    0x2B
#define VK_SNAPSHOT    0x2C
#define VK_INSERT     0x2D
#define VK_DELETE     0x2E
#define VK_HELP      0x2F

// VK_0 - VK_9 are the same as ASCII '0' - '9' (0x30 - 0x39)
// 0x40 : unassigned
// VK_A - VK_Z are the same as ASCII 'A' - 'Z' (0x41 - 0x5A)

#define VK_LWIN      0x5B
#define VK_RWIN      0x5C
#define VK_APPS      0x5D


// 0x5E : reserved

#define VK_SLEEP     0x5F

#define VK_NUMPAD0    0x60
#define VK_NUMPAD1    0x61
#define VK_NUMPAD2    0x62
#define VK_NUMPAD3    0x63
#define VK_NUMPAD4    0x64
#define VK_NUMPAD5    0x65
#define VK_NUMPAD6    0x66
#define VK_NUMPAD7    0x67
#define VK_NUMPAD8    0x68
#define VK_NUMPAD9    0x69
#define VK_MULTIPLY    0x6A
#define VK_ADD      0x6B
#define VK_SEPARATOR   0x6C
#define VK_SUBTRACT    0x6D
#define VK_DECIMAL    0x6E
#define VK_DIVIDE     0x6F
#define VK_F1       0x70
#define VK_F2       0x71
#define VK_F3       0x72
#define VK_F4       0x73
#define VK_F5       0x74
#define VK_F6       0x75
#define VK_F7       0x76
#define VK_F8       0x77
#define VK_F9       0x78
#define VK_F10      0x79
#define VK_F11      0x7A
#define VK_F12      0x7B
#define VK_F13      0x7C
#define VK_F14      0x7D
#define VK_F15      0x7E
#define VK_F16      0x7F
#define VK_F17      0x80
#define VK_F18      0x81
#define VK_F19      0x82
#define VK_F20      0x83
#define VK_F21      0x84
#define VK_F22      0x85
#define VK_F23      0x86
#define VK_F24      0x87

// 0x88 - 0x8F : unassigned

#define VK_NUMLOCK    0x90
#define VK_SCROLL     0x91

// NEC PC-9800 kbd definitions
#define VK_OEM_NEC_EQUAL 0x92  // '=' key on numpad

// Fujitsu/OASYS kbd definitions
#define VK_OEM_FJ_JISHO  0x92  // 'Dictionary' key
#define VK_OEM_FJ_MASSHOU 0x93  // 'Unregister word' key
#define VK_OEM_FJ_TOUROKU 0x94  // 'Register word' key
#define VK_OEM_FJ_LOYA  0x95  // 'Left OYAYUBI' key
#define VK_OEM_FJ_ROYA  0x96  // 'Right OYAYUBI' key

// 0x97 - 0x9F : unassigned

// VK_L* & VK_R* - left and right Alt, Ctrl and Shift virtual keys.
// Used only as parameters to GetAsyncKeyState() and GetKeyState().
// No other API or message will distinguish left and right keys in this way.
#define VK_LSHIFT     0xA0
#define VK_RSHIFT     0xA1
#define VK_LCONTROL    0xA2
#define VK_RCONTROL    0xA3
#define VK_LMENU     0xA4
#define VK_RMENU     0xA5

// MessageBox() Flags

#define MB_OK            0x00000000L
#define MB_OKCANCEL         0x00000001L
#define MB_ABORTRETRYIGNORE     0x00000002L
#define MB_YESNOCANCEL       0x00000003L
#define MB_YESNO          0x00000004L
#define MB_RETRYCANCEL       0x00000005L
#if(WINVER >= 0x0500)
#define MB_CANCELTRYCONTINUE    0x00000006L
#endif // WINVER >= 0x0500 


#define MB_ICONHAND         0x00000010L
#define MB_ICONQUESTION       0x00000020L
#define MB_ICONEXCLAMATION     0x00000030L
#define MB_ICONASTERISK       0x00000040L

#if(WINVER >= 0x0400)
#define MB_USERICON         0x00000080L
#define MB_ICONWARNING       MB_ICONEXCLAMATION
#define MB_ICONERROR        MB_ICONHAND
#endif // WINVER >= 0x0400 

#define MB_ICONINFORMATION     MB_ICONASTERISK
#define MB_IconstOP         MB_ICONHAND

#define MB_DEFBUTTON1        0x00000000L
#define MB_DEFBUTTON2        0x00000100L
#define MB_DEFBUTTON3        0x00000200L
#if(WINVER >= 0x0400)
#define MB_DEFBUTTON4        0x00000300L
#endif // WINVER >= 0x0400 

#define MB_APPLMODAL        0x00000000L
#define MB_SYSTEMMODAL       0x00001000L
#define MB_TASKMODAL        0x00002000L
#if(WINVER >= 0x0400)
#define MB_HELP           0x00004000L // Help Button
#endif // WINVER >= 0x0400

#define MB_NOFOCUS         0x00008000L
#define MB_SETFOREGROUND      0x00010000L
#define MB_DEFAULT_DESKTOP_ONLY   0x00020000L

#if(WINVER >= 0x0400)
#define MB_TOPMOST         0x00040000L
#define MB_RIGHT          0x00080000L
#define MB_RTLREADING        0x00100000L

#endif // WINVER >= 0x0400 

#ifdef _WIN32_WINNT
#if (_WIN32_WINNT >= 0x0400)
#define MB_SERVICE_NOTIFICATION     0x00200000L
#else
#define MB_SERVICE_NOTIFICATION     0x00040000L
#endif
#define MB_SERVICE_NOTIFICATION_NT3X   0x00040000L
#endif

#define MB_TYPEMASK         0x0000000FL
#define MB_ICONMASK         0x000000F0L
#define MB_DEFMASK			0x00000F00L
#define MB_MODEMASK         0x00003000L
#define MB_MISCMASK         0x0000C000L

#define MONITOR_DEFAULTTONULL       0x00000000
#define MONITOR_DEFAULTTOPRIMARY    0x00000001
#define MONITOR_DEFAULTTONEAREST    0x00000002

#define DIB_RGB_COLORS			0		// color table in RGBs
#define DIB_PAL_COLORS			1		// color table in palette indices

#define BI_RGB    0L
#define BI_RLE8    1L
#define BI_RLE4    2L
#define BI_BITFIELDS 3L
#define BI_JPEG    4L
#define BI_PNG    5L

#define __int3264  __int32
#define VOID		void

#define GENERIC_READ              (0x80000000L)
#define GENERIC_WRITE             (0x40000000L)
#define GENERIC_EXECUTE           (0x20000000L)
#define GENERIC_ALL               (0x10000000L)

#define FILE_READ_DATA            (0x0001 )    // file & pipe
#define FILE_LIST_DIRECTORY       (0x0001 )    // directory

#define FILE_WRITE_DATA           (0x0002 )    // file & pipe
#define FILE_ADD_FILE             (0x0002 )    // directory

#define FILE_APPEND_DATA          (0x0004 )    // file
#define FILE_ADD_SUBDIRECTORY     (0x0004 )    // directory
#define FILE_CREATE_PIPE_INSTANCE (0x0004 )    // named pipe


#define FILE_READ_EA              (0x0008 )    // file & directory

#define FILE_WRITE_EA             (0x0010 )    // file & directory

#define FILE_EXECUTE              (0x0020 )    // file
#define FILE_TRAVERSE             (0x0020 )    // directory

#define FILE_DELETE_CHILD         (0x0040 )    // directory

#define FILE_READ_ATTRIBUTES      (0x0080 )    // all

#define FILE_WRITE_ATTRIBUTES     (0x0100 )    // all

#define FILE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0x1FF)

#define FILE_GENERIC_READ         (STANDARD_RIGHTS_READ     |\
                                   FILE_READ_DATA           |\
                                   FILE_READ_ATTRIBUTES     |\
                                   FILE_READ_EA             |\
                                   SYNCHRONIZE)


#define FILE_GENERIC_WRITE        (STANDARD_RIGHTS_WRITE    |\
                                   FILE_WRITE_DATA          |\
                                   FILE_WRITE_ATTRIBUTES    |\
                                   FILE_WRITE_EA            |\
                                   FILE_APPEND_DATA         |\
                                   SYNCHRONIZE)


#define FILE_GENERIC_EXECUTE      (STANDARD_RIGHTS_EXECUTE  |\
                                   FILE_READ_ATTRIBUTES     |\
                                   FILE_EXECUTE             |\
                                   SYNCHRONIZE)

#define FILE_SHARE_READ						0x00000001  
#define FILE_SHARE_WRITE					0x00000002  
#define FILE_SHARE_DELETE					0x00000004  
#define FILE_ATTRIBUTE_READONLY             0x00000001  
#define FILE_ATTRIBUTE_HIDDEN               0x00000002  
#define FILE_ATTRIBUTE_SYSTEM               0x00000004  
#define FILE_ATTRIBUTE_DIRECTORY            0x00000010  
#define FILE_ATTRIBUTE_ARCHIVE              0x00000020  
#define FILE_ATTRIBUTE_DEVICE               0x00000040  
#define FILE_ATTRIBUTE_NORMAL               0x00000080  
#define FILE_ATTRIBUTE_TEMPORARY            0x00000100  
#define FILE_ATTRIBUTE_SPARSE_FILE          0x00000200  
#define FILE_ATTRIBUTE_REPARSE_POINT        0x00000400  
#define FILE_ATTRIBUTE_COMPRESSED           0x00000800  
#define FILE_ATTRIBUTE_OFFLINE              0x00001000  
#define FILE_ATTRIBUTE_NOT_CONTENT_INDEXED  0x00002000  
#define FILE_ATTRIBUTE_ENCRYPTED            0x00004000  
#define FILE_ATTRIBUTE_INTEGRITY_STREAM     0x00008000  
#define FILE_ATTRIBUTE_VIRTUAL              0x00010000  
#define FILE_ATTRIBUTE_NO_SCRUB_DATA        0x00020000  
#define FILE_ATTRIBUTE_EA                   0x00040000  
#define FILE_NOTIFY_CHANGE_FILE_NAME		0x00000001   
#define FILE_NOTIFY_CHANGE_DIR_NAME			0x00000002   
#define FILE_NOTIFY_CHANGE_ATTRIBUTES		0x00000004   
#define FILE_NOTIFY_CHANGE_SIZE				0x00000008   
#define FILE_NOTIFY_CHANGE_LAST_WRITE		0x00000010   
#define FILE_NOTIFY_CHANGE_LAST_ACCESS		0x00000020   
#define FILE_NOTIFY_CHANGE_CREATION			0x00000040   
#define FILE_NOTIFY_CHANGE_SECURITY			0x00000100   
#define FILE_ACTION_ADDED                   0x00000001   
#define FILE_ACTION_REMOVED                 0x00000002   
#define FILE_ACTION_MODIFIED                0x00000003   
#define FILE_ACTION_RENAMED_OLD_NAME        0x00000004   
#define FILE_ACTION_RENAMED_NEW_NAME        0x00000005   
#define MAILSLOT_NO_MESSAGE					((DWORD)-1) 
#define MAILSLOT_WAIT_FOREVER				((DWORD)-1) 
#define FILE_CASE_SENSITIVE_SEARCH          0x00000001  
#define FILE_CASE_PRESERVED_NAMES           0x00000002  
#define FILE_UNICODE_ON_DISK                0x00000004  
#define FILE_PERSISTENT_ACLS                0x00000008  
#define FILE_FILE_COMPRESSION               0x00000010  
#define FILE_VOLUME_QUOTAS                  0x00000020  
#define FILE_SUPPORTS_SPARSE_FILES          0x00000040  
#define FILE_SUPPORTS_REPARSE_POINTS        0x00000080  
#define FILE_SUPPORTS_REMOTE_STORAGE        0x00000100  
#define FILE_VOLUME_IS_COMPRESSED           0x00008000  
#define FILE_SUPPORTS_OBJECT_IDS            0x00010000  
#define FILE_SUPPORTS_ENCRYPTION            0x00020000  
#define FILE_NAMED_STREAMS                  0x00040000  
#define FILE_READ_ONLY_VOLUME               0x00080000  
#define FILE_SEQUENTIAL_WRITE_ONCE          0x00100000  
#define FILE_SUPPORTS_TRANSACTIONS          0x00200000  
#define FILE_SUPPORTS_HARD_LINKS            0x00400000  
#define FILE_SUPPORTS_EXTENDED_ATTRIBUTES   0x00800000  
#define FILE_SUPPORTS_OPEN_BY_FILE_ID       0x01000000  
#define FILE_SUPPORTS_USN_JOURNAL           0x02000000  
#define FILE_SUPPORTS_INTEGRITY_STREAMS     0x04000000  
#define FILE_INVALID_FILE_ID				((LONGLONG)-1LL) 

#define CREATE_NEW          1
#define CREATE_ALWAYS       2
#define OPEN_EXISTING       3
#define OPEN_ALWAYS         4
#define TRUNCATE_EXISTING   5
#define	FILE_BEGIN 0
#define FILE_CURRENT 1
#define FILE_END 2

#define INVALID_FILE_SIZE ((DWORD)0xFFFFFFFF)
#define INVALID_SET_FILE_POINTER ((DWORD)-1)
#define INVALID_FILE_ATTRIBUTES ((DWORD)-1)

/* size of a device name string */
#define CCHDEVICENAME 32

/* size of a form name string */
#define CCHFORMNAME 32



/*
* Window Styles
*/
#define WS_OVERLAPPED       0x00000000L
#define WS_POPUP            0x80000000L
#define WS_CHILD            0x40000000L
#define WS_MINIMIZE         0x20000000L
#define WS_VISIBLE          0x10000000L
#define WS_DISABLED         0x08000000L
#define WS_CLIPSIBLINGS     0x04000000L
#define WS_CLIPCHILDREN     0x02000000L
#define WS_MAXIMIZE         0x01000000L
#define WS_CAPTION          0x00C00000L     /* WS_BORDER | WS_DLGFRAME  */
#define WS_BORDER           0x00800000L
#define WS_DLGFRAME         0x00400000L
#define WS_VSCROLL          0x00200000L
#define WS_HSCROLL          0x00100000L
#define WS_SYSMENU          0x00080000L
#define WS_THICKFRAME       0x00040000L
#define WS_GROUP            0x00020000L
#define WS_TABSTOP          0x00010000L

#define WS_MINIMIZEBOX      0x00020000L
#define WS_MAXIMIZEBOX      0x00010000L


#define WS_TILED            WS_OVERLAPPED
#define WS_ICONIC           WS_MINIMIZE
#define WS_SIZEBOX          WS_THICKFRAME
#define WS_TILEDWINDOW      WS_OVERLAPPEDWINDOW

/*
* Common Window Styles
*/
#define WS_OVERLAPPEDWINDOW (WS_OVERLAPPED     | \
                             WS_CAPTION        | \
                             WS_SYSMENU        | \
                             WS_THICKFRAME     | \
                             WS_MINIMIZEBOX    | \
                             WS_MAXIMIZEBOX)

#define WS_POPUPWINDOW      (WS_POPUP          | \
                             WS_BORDER         | \
                             WS_SYSMENU)

#define WS_CHILDWINDOW      (WS_CHILD)

/*
* Extended Window Styles
*/
#define WS_EX_DLGMODALFRAME     0x00000001L
#define WS_EX_NOPARENTNOTIFY    0x00000004L
#define WS_EX_TOPMOST           0x00000008L
#define WS_EX_ACCEPTFILES       0x00000010L
#define WS_EX_TRANSPARENT       0x00000020L

#if(WINVER >= 0x0400)
	#define WS_EX_MDICHILD          0x00000040L
	#define WS_EX_TOOLWINDOW        0x00000080L
	#define WS_EX_WINDOWEDGE        0x00000100L
	#define WS_EX_CLIENTEDGE        0x00000200L
	#define WS_EX_CONTEXTHELP       0x00000400L
#endif /* WINVER >= 0x0400 */

#if(WINVER >= 0x0400)
	#define WS_EX_RIGHT             0x00001000L
	#define WS_EX_LEFT              0x00000000L
	#define WS_EX_RTLREADING        0x00002000L
	#define WS_EX_LTRREADING        0x00000000L
	#define WS_EX_LEFTSCROLLBAR     0x00004000L
	#define WS_EX_RIGHTSCROLLBAR    0x00000000L

	#define WS_EX_CONTROLPARENT     0x00010000L
	#define WS_EX_STATICEDGE        0x00020000L
	#define WS_EX_APPWINDOW         0x00040000L


	#define WS_EX_OVERLAPPEDWINDOW  (WS_EX_WINDOWEDGE | WS_EX_CLIENTEDGE)
	#define WS_EX_PALETTEWINDOW     (WS_EX_WINDOWEDGE | WS_EX_TOOLWINDOW | WS_EX_TOPMOST)
#endif

#if(_WIN32_WINNT >= 0x0500)
	#define WS_EX_LAYERED           0x00080000
#endif

#if(WINVER >= 0x0500)
	#define WS_EX_NOINHERITLAYOUT   0x00100000L // Disable inheritence of mirroring by children
#endif

#if(WINVER >= 0x0602)
#define WS_EX_NOREDIRECTIONBITMAP 0x00200000L
#endif /* WINVER >= 0x0602 */

#if(WINVER >= 0x0500)
#define WS_EX_LAYOUTRTL         0x00400000L // Right to left mirroring
#endif /* WINVER >= 0x0500 */

#if(_WIN32_WINNT >= 0x0501)
#define WS_EX_COMPOSITED        0x02000000L
#endif /* _WIN32_WINNT >= 0x0501 */
#if(_WIN32_WINNT >= 0x0500)
#define WS_EX_NOACTIVATE        0x08000000L
#endif /* _WIN32_WINNT >= 0x0500 */



typedef int							INT_PTR, *PINT_PTR;
typedef unsigned int				UINT_PTR, *PUINT_PTR;
typedef long						LONG_PTR, *PLONG_PTR;
typedef unsigned long				ULONG_PTR, *PULONG_PTR;
typedef char						CHAR;
typedef short						SHORT;
typedef unsigned short				WORD;
typedef unsigned char				BYTE;
typedef long						LONG;
typedef int							INT;
typedef unsigned int				UINT;
typedef unsigned int				*PUINT;
typedef UINT_PTR					WPARAM;
typedef LONG_PTR					LPARAM;
typedef LONG_PTR					LRESULT;
typedef unsigned long				DWORD;
typedef int							BOOL;
typedef void*						LPVOID;
typedef ULONG_PTR					DWORD_PTR, *PDWORD_PTR;
typedef UINT						MMRESULT;
typedef __int64						LONGLONG;
typedef unsigned __int64			ULONGLONG;
typedef	ULONG_PTR					SIZE_T, *PSIZE_T;
typedef LONG_PTR					SSIZE_T, *PSSIZE_T;
typedef DWORD						*LPDWORD;
typedef void*						HGDIOBJ;
typedef WORD						ATOM;
typedef const void	*				LPCVOID;

//typedef wchar_t WCHAR;
typedef unsigned short WCHAR;
typedef WCHAR *PWCHAR, *LPWCH, *PWCH;
typedef const WCHAR *LPCWCH, *PCWCH;

typedef  WCHAR *NWPSTR, *LPWSTR, *PWSTR;
typedef  PWSTR *PZPWSTR;
typedef  const PWSTR *PCZPWSTR;
typedef  WCHAR UNALIGNED *LPUWSTR, *PUWSTR;
typedef  const WCHAR *LPCWSTR, *PCWSTR;
typedef  PCWSTR *PZPCWSTR;
typedef  const PCWSTR *PCZPCWSTR;
typedef  const WCHAR UNALIGNED *LPCUWSTR, *PCUWSTR;

typedef  WCHAR *PZZWSTR;
typedef  const WCHAR *PCZZWSTR;
typedef  WCHAR UNALIGNED *PUZZWSTR;
typedef  const WCHAR UNALIGNED *PCUZZWSTR;
typedef CHAR *PCHAR, *LPCH, *PCH;
typedef const CHAR *LPCCH, *PCCH;

typedef CHAR	*NPSTR, *LPSTR, *PSTR;
typedef PSTR	*PZPSTR;
typedef const	PSTR *PCZPSTR;
typedef const	CHAR *LPCSTR, *PCSTR, *LPCTSTR;
typedef PCSTR	*PZPCSTR;
typedef const	PCSTR *PCZPCSTR;
typedef char	TCHAR, *PTCHAR;
typedef CHAR	*PZZSTR;
typedef const	CHAR *PCZZSTR;
typedef WCHAR	*PNZWCH;
typedef const	WCHAR *PCNZWCH;
typedef WCHAR UNALIGNED *PUNZWCH;
typedef const WCHAR UNALIGNED *PCUNZWCH;


#define WINUSERAPI DECLSPEC_IMPORT
#define WINABLEAPI DECLSPEC_IMPORT

typedef int (WINAPI*FARPROC)();
typedef int (WINAPI*NEARPROC)();
typedef int (WINAPI*PROC)();

typedef void *HANDLE;
#define DECLARE_HANDLE(name) struct name##__{int unused;}; typedef struct name##__ *name
typedef HANDLE *PHANDLE;

#define max(a,b)			(((a) > (b)) ? (a) : (b))
#define min(a,b)			(((a) < (b)) ? (a) : (b))

DECLARE_HANDLE(HWND);
DECLARE_HANDLE(HHOOK);
DECLARE_HANDLE(HDC);
DECLARE_HANDLE(HBRUSH);
DECLARE_HANDLE(HBITMAP);
DECLARE_HANDLE(HINSTANCE);
DECLARE_HANDLE(HICON);
DECLARE_HANDLE(HMENU);
DECLARE_HANDLE(HPALETTE);
DECLARE_HANDLE(HPEN);
DECLARE_HANDLE(HMONITOR);

typedef HINSTANCE HMODULE;      /* HMODULEs can be used in place of HINSTANCEs */
typedef HICON HCURSOR;   // HICONs & HCURSORs are polymorphic
typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);

typedef struct tagRECT {
	LONG  left;
	LONG  top;
	LONG  right;
	LONG  bottom;
} RECT, *PRECT, *NPRECT, *LPRECT;

typedef struct _FILE_ID_128 {
	BYTE  Identifier[16];
} FILE_ID_128, *PFILE_ID_128;

typedef struct _SYSTEM_INFO {
	union {
		DWORD dwOemId;     // Obsolete field...do not use
		struct {
			WORD wProcessorArchitecture;
			WORD wReserved;
		} DUMMYSTRUCTNAME;
	} DUMMYUNIONNAME;
	DWORD dwPageSize;
	LPVOID lpMinimumApplicationAddress;
	LPVOID lpMaximumApplicationAddress;
	DWORD_PTR dwActiveProcessorMask;
	DWORD dwNumberOfProcessors;
	DWORD dwProcessorType;
	DWORD dwAllocationGranularity;
	WORD wProcessorLevel;
	WORD wProcessorRevision;
} SYSTEM_INFO, *LPSYSTEM_INFO;

typedef union _LARGE_INTEGER {
	struct {
		DWORD LowPart;
		LONG HighPart;
	} DUMMYSTRUCTNAME;
	struct {
		DWORD LowPart;
		LONG HighPart;
	} u;
	LONGLONG QuadPart;
} LARGE_INTEGER; typedef LARGE_INTEGER *PLARGE_INTEGER;

typedef struct _SECURITY_ATTRIBUTES {
	DWORD nLength;
	LPVOID lpSecurityDescriptor;
	BOOL bInheritHandle;
} SECURITY_ATTRIBUTES, *PSECURITY_ATTRIBUTES, *LPSECURITY_ATTRIBUTES;

typedef struct tagRGBQUAD {
	BYTE  rgbBlue;
	BYTE  rgbGreen;
	BYTE  rgbRed;
	BYTE  rgbReserved;
} RGBQUAD;

typedef struct tagBITMAPINFOHEADER {
	DWORD   biSize;
	LONG    biWidth;
	LONG    biHeight;
	WORD    biPlanes;
	WORD    biBitCount;
	DWORD   biCompression;
	DWORD   biSizeImage;
	LONG    biXPelsPerMeter;
	LONG    biYPelsPerMeter;
	DWORD   biClrUsed;
	DWORD   biClrImportant;
} BITMAPINFOHEADER, *LPBITMAPINFOHEADER, *PBITMAPINFOHEADER;

typedef struct tagBITMAPINFO {
	BITMAPINFOHEADER  bmiHeader;
	RGBQUAD       bmiColors[1];
} BITMAPINFO, *LPBITMAPINFO, *PBITMAPINFO;

typedef DWORD(WINAPI*PTHREAD_START_ROUTINE)(LPVOID lpThreadParameter);
typedef PTHREAD_START_ROUTINE LPTHREAD_START_ROUTINE;

typedef struct tagPIXELFORMATDESCRIPTOR {
	WORD nSize;
	WORD nVersion;
	DWORD dwFlags;
	BYTE iPixelType;
	BYTE cColorBits;
	BYTE cRedBits;
	BYTE cRedShift;
	BYTE cGreenBits;
	BYTE cGreenShift;
	BYTE cBlueBits;
	BYTE cBlueShift;
	BYTE cAlphaBits;
	BYTE cAlphaShift;
	BYTE cAccumBits;
	BYTE cAccumRedBits;
	BYTE cAccumGreenBits;
	BYTE cAccumBlueBits;
	BYTE cAccumAlphaBits;
	BYTE cDepthBits;
	BYTE cStencilBits;
	BYTE cAuxBuffers;
	BYTE iLayerType;
	BYTE bReserved;
	DWORD dwLayerMask;
	DWORD dwVisibleMask;
	DWORD dwDamageMask;
} PIXELFORMATDESCRIPTOR, *PPIXELFORMATDESCRIPTOR, *LPPIXELFORMATDESCRIPTOR;

typedef struct tagPAINTSTRUCT {
	HDC     hdc;
	BOOL    fErase;
	RECT    rcPaint;
	BOOL    fRestore;
	BOOL    fIncUpdate;
	BYTE    rgbReserved[32];
} PAINTSTRUCT, *PPAINTSTRUCT, *NPPAINTSTRUCT, *LPPAINTSTRUCT;


typedef struct tagPOINT {
	LONG x;
	LONG y;
} POINT, *PPOINT, *NPPOINT, *LPPOINT;

typedef struct tagMONITORINFO {
	DWORD cbSize;
	RECT  rcMonitor;
	RECT  rcWork;
	DWORD dwFlags;
} MONITORINFO, *LPMONITORINFO;

typedef struct tagMONITORINFOEX {
	DWORD cbSize;
	RECT  rcMonitor;
	RECT  rcWork;
	DWORD dwFlags;
	TCHAR szDevice[CCHDEVICENAME];
} MONITORINFOEX, *LPMONITORINFOEX;

typedef struct tagMSG {
	HWND    hwnd;
	UINT    message;
	WPARAM   wParam;
	LPARAM   lParam;
	DWORD    time;
	POINT    pt;
	#ifdef _MAC
	DWORD    lPrivate;
	#endif
} MSG, *PMSG, *NPMSG, *LPMSG;

typedef struct tagWNDCLASSEXA {
	UINT    cbSize;
	// Win 3.x
	UINT    style;
	WNDPROC   lpfnWndProc;
	int     cbClsExtra;
	int     cbWndExtra;
	HINSTANCE  hInstance;
	HICON    hIcon;
	HCURSOR   hCursor;
	HBRUSH   hbrBackground;
	LPCSTR   lpszMenuName;
	LPCSTR   lpszClassName;
	// Win 4.0 
	HICON    hIconSm;
} WNDCLASSEXA, *PWNDCLASSEXA, *NPWNDCLASSEXA, *LPWNDCLASSEXA;

typedef struct tagWNDCLASSEXW {
	UINT    cbSize;
	// Win 3.x 
	UINT    style;
	WNDPROC   lpfnWndProc;
	int     cbClsExtra;
	int     cbWndExtra;
	HINSTANCE  hInstance;
	HICON    hIcon;
	HCURSOR   hCursor;
	HBRUSH   hbrBackground;
	LPCWSTR   lpszMenuName;
	LPCWSTR   lpszClassName;
	// Win 4.0
	HICON    hIconSm;
} WNDCLASSEXW, *PWNDCLASSEXW, *NPWNDCLASSEXW, *LPWNDCLASSEXW;


typedef struct tagWNDCLASSA {
	UINT    style;
	WNDPROC   lpfnWndProc;
	int     cbClsExtra;
	int     cbWndExtra;
	HINSTANCE  hInstance;
	HICON    hIcon;
	HCURSOR   hCursor;
	HBRUSH   hbrBackground;
	LPCSTR   lpszMenuName;
	LPCSTR   lpszClassName;
} WNDCLASSA, *PWNDCLASSA, *NPWNDCLASSA, *LPWNDCLASSA;

typedef struct tagWNDCLASSW {
	UINT    style;
	WNDPROC   lpfnWndProc;
	int     cbClsExtra;
	int     cbWndExtra;
	HINSTANCE  hInstance;
	HICON    hIcon;
	HCURSOR   hCursor;
	HBRUSH   hbrBackground;
	LPCWSTR   lpszMenuName;
	LPCWSTR   lpszClassName;
} WNDCLASSW, *PWNDCLASSW, *NPWNDCLASSW, *LPWNDCLASSW;

#ifdef UNICODE
typedef WNDCLASSEXW WNDCLASSEX;
typedef PWNDCLASSEXW PWNDCLASSEX;
typedef NPWNDCLASSEXW NPWNDCLASSEX;
typedef LPWNDCLASSEXW LPWNDCLASSEX;
#else
typedef WNDCLASSEXA WNDCLASSEX;
typedef PWNDCLASSEXA PWNDCLASSEX;
typedef NPWNDCLASSEXA NPWNDCLASSEX;
typedef LPWNDCLASSEXA LPWNDCLASSEX;
#endif // UNICODE

#ifdef UNICODE
typedef WNDCLASSW WNDCLASS;
typedef PWNDCLASSW PWNDCLASS;
typedef NPWNDCLASSW NPWNDCLASS;
typedef LPWNDCLASSW LPWNDCLASS;
#else
typedef WNDCLASSA WNDCLASS;
typedef PWNDCLASSA PWNDCLASS;
typedef NPWNDCLASSA NPWNDCLASS;
typedef LPWNDCLASSA LPWNDCLASS;
#endif

typedef struct _OVERLAPPED {
	ULONG_PTR Internal;
	ULONG_PTR InternalHigh;
	union {
		struct {
			DWORD Offset;
			DWORD OffsetHigh;
		} DUMMYSTRUCTNAME;
		void* Pointer;
	} DUMMYUNIONNAME;
	HANDLE  hEvent;
} OVERLAPPED, *LPOVERLAPPED;

typedef struct _SYSTEMTIME {
	WORD wYear;
	WORD wMonth;
	WORD wDayOfWeek;
	WORD wDay;
	WORD wHour;
	WORD wMinute;
	WORD wSecond;
	WORD wMilliseconds;
} SYSTEMTIME, *PSYSTEMTIME, *LPSYSTEMTIME;



WINBASEAPI VOID WINAPI
GetSystemInfo(LPSYSTEM_INFO lpSystemInfo);

WINMMAPI MMRESULT WINAPI
timeBeginPeriod(UINT uPeriod);

WINMMAPI MMRESULT WINAPI
timeEndPeriod(UINT uPeriod);

WINBASEAPI BOOL WINAPI
QueryPerformanceCounter(LARGE_INTEGER * lpPerformanceCount);

WINBASEAPI BOOL WINAPI
QueryPerformanceFrequency(LARGE_INTEGER * lpFrequency);

WINBASEAPI HANDLE WINAPI
CreateThread(
	LPSECURITY_ATTRIBUTES lpThreadAttributes, SIZE_T dwStackSize, LPTHREAD_START_ROUTINE lpStartAddress, LPVOID lpParameter,
	DWORD dwCreationFlags, LPDWORD lpThreadId
);

WINBASEAPI VOID WINAPI
Sleep(DWORD dwMilliseconds);

WINUSERAPI int WINAPI
MessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType);
typedef int WINAPImessage_box(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType);

WINUSERAPI int WINAPI
MessageBoxW(HWND hWnd, LPCWSTR lpText, LPCWSTR lpCaption, UINT uType);

WINBASEAPI LPVOID WINAPI
VirtualAlloc(LPVOID lpAddress, SIZE_T dwSize, DWORD flAllocationType, DWORD flProtect);

WINBASEAPI BOOL WINAPI
VirtualFree(LPVOID lpAddress, SIZE_T dwSize, DWORD dwFreeType);

LPVOID WINAPI
HeapAlloc(HANDLE hHeap, DWORD  dwFlags, SIZE_T dwBytes);

BOOL WINAPI
HeapFree(HANDLE hHeap, DWORD  dwFlags, LPVOID lpMem);

HANDLE WINAPI
GetProcessHeap(void);

void WINAPI
RtlCopyMemory(LPVOID Destination, const VOID* Source, SIZE_T Length);
#define CopyMemory RtlCopyMemory

enum heap_alloc_flags {
	HEAP_NO_SERIALIZE			= 0x00000001,
	HEAP_GENERATE_EXCEPTIONS	= 0x00000004,
	HEAP_ZERO_MEMORY			= 0x00000008
};



DWORD WINAPI
GetLastError(void);

FARPROC WINAPI
GetProcAddress(HMODULE hModule, LPCSTR  lpProcName);

WINBASEAPI HMODULE WINAPI
LoadLibraryA(LPCSTR lpLibFileName);

WINBASEAPI HMODULE WINAPI
LoadLibraryW(LPCWSTR lpLibFileName);

#define LoadLibrary(a) LoadLibraryA(a)

HANDLE WINAPI
CreateFileA(
	LPCTSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes,
	DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile
);

#define CreateFile CreateFileA

BOOL WINAPI
WriteFile(
	HANDLE hFile, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite, 
	LPDWORD lpNumberOfBytesWritten, LPOVERLAPPED lpOverlapped
);

BOOL WINAPI
ReadFile(
	HANDLE hFile, LPVOID lpBuffer, DWORD nNumberOfBytesToRead, 
	LPDWORD lpNumberOfBytesRead, LPOVERLAPPED lpOverlapped
);

DWORD WINAPI
SetFilePointer(HANDLE hFile, LONG lDistanceToMove, LONG* lpDistanceToMoveHigh, DWORD dwMoveMethod);

VOID WINAPI
ExitProcess(UINT uExitCode);

DWORD WINAPI
GetFileSize(HANDLE  hFile, LPDWORD lpFileSizeHigh);

BOOL WINAPI
CloseHandle(HANDLE hObject);

void WINAPI
DebugBreak(void);

void WINAPI
GetSystemTime(LPSYSTEMTIME lpSystemTime);

HMODULE WINAPI
LoadLibraryEx(LPCTSTR lpFileName, HANDLE  hFile, DWORD   dwFlags);


#define BitScanReverse64 _BitScanReverse64
#define BitScanReverse _BitScanReverse

#ifdef __cplusplus
}
#endif