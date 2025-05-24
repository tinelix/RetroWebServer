#ifndef _RWS_CLRPRINTF_H
#define _RWS_CLRPRINTF_H

#define RWS_LOGTYPE_ERROR 		"[ERR ]"
#define RWS_LOGTYPE_INFO  		"[INFO]"
#define RWS_LOGTYPE_CLIENT 		"[RWSC]"
#define RWS_LOGTYPE_SERVER		"[RWSS]"
#define RWS_LOGTYPE_DEBUG		"[DBG ]"
#define RWS_LOGTYPE_PADDING		"      "
#define RWS_LOGTYPE_SUBLINE		"       %c%c"

#define RWS_LOGCOLOR_RED		FOREGROUND_RED   | FOREGROUND_INTENSITY
#define RWS_LOGCOLOR_GREEN		FOREGROUND_GREEN | FOREGROUND INTENSITY
#define RWS_LOGCOLOR_MAGENTA	FOREGROUND_BLUE  | FOREGROUND_RED       | FOREGROUND_INTENSITY
#define RWS_LOGCOLOR_CYAN       FOREGROUND_BLUE  | FOREGROUND_GREEN     | FOREGROUND_INTENSITY
#define RWS_LOGCOLOR_WHITE      FOREGROUND_RED   | FOREGROUND_GREEN     | FOREGROUND_BLUE      | FOREGROUND_INTENSITY


// rws_cprintf => colorized printf for RWS

// @param type -> -1 = error, 
//             ->  0 = debug,
//             ->  1 = info, 
//             ->  2 = rwsc,
//             ->  3 = rwss

void rws_clrprintf(int type, const char *fmt, ...);

#endif
