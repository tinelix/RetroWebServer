#!/usr/bin/python

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

import sys
import string

# RetroWebServer is a self-written HTTP server based on SocketServer library.
# Compatible with Python 1.x and 2.0.
# Guaranteed to work on Windows 3.1 and Windows NT 3.5.
# -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
# Since all of this was developed on ancient versions of Python, there may 
# of course be some vulnerabilities that were fixed in later versions or were 
# not documented, so we do NOT recommend using the implementation on a permanent 
# basis (ONLY if you are using Python on Win2K and above).

if sys.version >= (1, 5):
	from SocketServer import BaseRequestHandler, TCPServer
	from rws import *
else:
	sys.path.append("./rws")
	from SocketSe import BaseRequestHandler, TCPServer
	from httperrp import HTTPErrorPage
	from httphds import HTTPHeaders
	from httppage import HTTPPage
	from website import Website
	from version import RWSVersion

class RetroHTTPHandler(BaseRequestHandler):
	def handle(self):
        	self.data = self.request.recv(1024)
        	if len(self.data) > 0:
            		print "Request:", repr(self.data[:100])

            		content = Website("localhost", 80).getContentByFile("index.html")
            
	    		if content == None:
                			response = HTTPErrorPage(
                    				HTTPHeaders("1.1", "text/html", 400)
                			).toRaw()
            		else:
                			response = HTTPPage(
                    				HTTPHeaders("1.1", "text/html", 200), 
                    				content
                			).toRaw()
            
            	self.request.send(response)

if __name__ == "__main__":
    	HOST, PORT = '', 80
    	server = TCPServer((HOST, PORT), RetroHTTPHandler)
    	print "Listening at %s:%d" % (HOST, PORT)
    	# Ctrl+C stops server
    	server.serve_forever()
