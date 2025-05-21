# Copyright (C) 2025 Dmitry Tretyakov <tinelix@mail.ru>
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import os
import sys

from httppage import HTTPPage
from httphds import HTTPHeaders
from version import RWSVersion

class HTTPErrorPage(HTTPPage):	

	response = ""
	rwsVer = RWSVersion()

	def __init__(self, headers):
		HTTPPage.__init__(self, headers, None)
		if headers.status >= 400:
			self.headers = headers
		else:
			self.headers = HTTPHeaders("1.1", "text/html", 400)

		self.html = HTTPErrorPage.generateHTML(self)

		self.response = "%s%s" % (self.headers.toRaw(), self.html)

	def createInstance(headers):
		return HTTPErrorPage(headers)
		
	def generateHTML(self):
		self.html = """<HTML>
<BODY>
<H1><CENTER>%d %s</CENTER></H1>
<HR></HR>
<CENTER>%s</CENTER>
</BODY>
</HTML>""" % 	(
			self.headers.status, 
			self.headers.getStatusDescription(),
			self.rwsVer.getDefaultFooter()
	        )
		return self.html
		
	def toRaw(self):
		return self.response