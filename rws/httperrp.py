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