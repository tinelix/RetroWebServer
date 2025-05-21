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

from SocketServer import BaseRequestHandler, TCPServer
import string
from rws import HTTPPage, HTTPHeaders

# RetroWebServer is a self-written HTTP server based on SocketServer 
# from Python 1.5 and 2.0. 
# Guaranteed to work on Windows 3.1.
# -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
# Since all of this was developed on ancient versions of Python, there may 
# of course be some vulnerabilities that were fixed in later versions or were 
# not documented, so we do NOT recommend using the implementation on a permanent 
# basis (unless you are running Python on Win2K and above).

class RetroHTTPHandler(BaseRequestHandler):
    def handle(self):
        self.data = self.request.recv(1024)
        if len(self.data) > 0:
            print "Request:", repr(self.data[:100])

            # This is example HTML page, wrapped in a HTTPPage class object
            response = HTTPPage(
                HTTPHeaders("1.1", 200), 
                "<HTML>\
                <BODY>\
                <H1>Hello World!</H1>\
                </BODY>\
                </HTML>"
            ).toRaw() 
            
            self.request.send(response)

if __name__ == "__main__":
    HOST, PORT = '', 80
    server = TCPServer((HOST, PORT), RetroHTTPHandler)
    print "Listening at %s:%d" % (HOST, PORT)
    # Ctrl+C stops server
    server.serve_forever()
