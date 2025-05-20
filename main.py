# -*- coding: utf-8 -*-

from SocketServer import BaseRequestHandler, TCPServer
import string
from rws import HTTPPage, HTTPHeaders

class RetroHTTPHandler(BaseRequestHandler):
    def handle(self):
        self.data = self.request.recv(1024)
        if len(self.data) > 0:
            print "Request:", repr(self.data[:100])

            response = HTTPPage(
                HTTPHeaders("1.1", 200), 
                "<HTML>\
                <BODY>\
                <H1>Hello World from Windows 3.1!</H1>\
                </BODY>\
                </HTML>"
            ).toRaw()
            
            self.request.send(response)

if __name__ == "__main__":
    HOST, PORT = '', 80
    server = TCPServer((HOST, PORT), RetroHTTPHandler)
    print "Listening at %s:%d" % (HOST, PORT)
    server.serve_forever()