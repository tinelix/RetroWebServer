#include <rws/version.h>
#include <rws/httperrp.h>

char* rws_gen_http_error_page(int status) {
	char page[3528];

	RWS_VERSION rws_ver;
	char* rws_short_name = rws_get_branding_short_name();

	rws_ver = rws_get_version();

	sprintf(page, ""
			"<HTML>\r\n"
			"	<HEAD>\r\n"
			"		<TITLE>%d %s</TITLE>\r\n"
			"	<BODY>\r\n"
			"		<H1><CENTER>%d %s</CENTER></H1>\r\n"
			"		<HR></HR>"
			"		<CENTER>%s/%d.%d</CENTER>"
			"	</BODY>\r\n"
			"</HTML>",
			status, rws_get_http_status_desc(status), 
			status, rws_get_http_status_desc(status),
			rws_short_name, rws_ver.major, rws_ver.minor
	);

	return page;
}
