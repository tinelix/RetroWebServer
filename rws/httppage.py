from httphds import HTTPHeaders

class HTTPPage:	

	response = ""

	def __init__(self, headers, html):
		self.headers = headers
		self.html = self.generateHTML(html)
		self.response = """%s%s""" % (self.headers.toRaw(), self.html)
		
	def generateHTML(self, html):
		html = "%s\r\n" % html
		return html
		
	def toRaw(self):
		return self.response