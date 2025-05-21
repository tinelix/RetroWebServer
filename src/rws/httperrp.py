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

from httppage import HTTPPage
from httphds import HTTPHeaders

class HTTPErrorPage(HTTPPage):	

	response = ""

	def __init__(self, headers, html):
		self.headers = headers
		self.html = self.generateHTML(html)
		self.response = "%s%s" % (self.headers.toRaw(), self.html)
		print "Response:", response
		
	def generateHTML(self, html):
		html = "\ %s\r\n" % html
		print "Response HTML:", html
		return html
