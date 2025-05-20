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

class HTTPHeaders:
	httpVersion = "1.1"
	status = 200
	raw = ""
	status_desc = ""
	
	def __init__(self, status):
		self.status = status
		self.generateHeaders()
		
	def __init__(self, httpVersion, status):
		self.httpVersion = httpVersion
		self.status = status
		self.generateHeaders()
		
	def getStatusDescription(self):
		self.status_desc = {
			200: "OK", 
			400: "Bad Request", 
			401: "Unauthorized", 
			402: "Payment Required", 
			403: "Forbidden", 
			404: "Not Found", 
			405: "Method Not Allowed", 
			406: "Not Acceptable"
		}
		
	def generateHeaders(self):
		self.raw = """\
HTTP/%s %d %s\r\nContent-Type: text/html\r\nConnection: close\r\n\r\n""" % (
									self.httpVersion, 
									self.status, 
									self.status_desc
						)
	def toRaw(self):
		return self.raw
		
	
