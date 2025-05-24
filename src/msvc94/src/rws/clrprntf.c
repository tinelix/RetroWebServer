#include <windows.h>
#include <stdio.h>
#include <stdarg.h>
#include <rws/clrprntf.h>

void rws_clrprintf(int type, const char *fmt, ...) {
	HANDLE hCmd = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD origAttrs;
	va_list args;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	char fmt_start[30];
	int fmt_start_type = 0;

	GetConsoleScreenBufferInfo(hCmd, &csbiInfo);

	origAttrs = csbiInfo.wAttributes;

	switch(type) {
		case -1: 
			SetConsoleTextAttribute(hCmd, RWS_LOGCOLOR_RED);
			fmt_start_type = RWS_LOGTYPE_ERROR;
			break;
		case 0:
			SetConsoleTextAttribute(hCmd, origAttrs);
			fmt_start_type = RWS_LOGTYPE_DEBUG;
			break;
		case 1:
			SetConsoleTextAttribute(hCmd, RWS_LOGCOLOR_MAGENTA);
			fmt_start_type = RWS_LOGTYPE_CLIENT;
			break;
		case 2:
			SetConsoleTextAttribute(hCmd, RWS_LOGCOLOR_CYAN);
			fmt_start_type = RWS_LOGTYPE_SERVER;
			break;
		case 4:
			SetConsoleTextAttribute(hCmd, origAttrs);
			fmt_start_type = RWS_LOGTYPE_PADDING;
			break;
		case 5:
			SetConsoleTextAttribute(hCmd, origAttrs);
			fmt_start_type = RWS_LOGTYPE_PADDING;
			break;
		default:
			fmt_start_type = RWS_LOGTYPE_PADDING;
			break;
	}
	if(type < 4)
		fprintf(stdout, "%s ", fmt_start_type);
	else if(type == 4)
		fprintf(stdout, "%s %c%c ", fmt_start_type, 192, 196);
	else
		fprintf(stdout, "%s %c%c ", fmt_start_type, 195, 196);

	if(type != 0 && type < 4)
		SetConsoleTextAttribute(hCmd, RWS_LOGCOLOR_WHITE);

	va_start(args, fmt);
	vfprintf(stdout, fmt, args);
	va_end(args);

	SetConsoleTextAttribute(hCmd, origAttrs);
}
