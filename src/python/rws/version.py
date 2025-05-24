import sys

class RWSVersion:

	def createInstance():
		return RWSVersion()

	def getBrandingName(self):
		return "TinelixRWS"
		
	def getDefaultFooter(self):
		return "%s" % RWSVersion.getVersion(self)
	
	def getVersion(self):
		return "%s/0.0.1" % RWSVersion.getBrandingName(self)
		
	def getOSVersion(self):
		pass
		
	def getPythonVersion(self):
		# The Python system version, truncated to its first component.
		return "Python/" + string.split(sys.version)[0]