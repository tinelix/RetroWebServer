import os
import sys

sys.path.insert(0, '..')

from rws import HTTPErrorPage

class Website {
	
	root = "..\\www"
	server_name = "localhost"
	server_port = 80
	
	def __init__(self, server_name, server_port):
		self.server_name = server_name
		self.server_port = server_port
		
	def setRootDir(self, root):
		self.root = root
		
	def findFile(self, path):
		for root, dirs, files in os.walk(self.root):
			if filename in files:
				return os.path.join(root, filename)
		return None
		
	def getContentByFile(self, path):
		path = findFile(path)
		try:
            with open(path, 'r') as f:
                return f.read()
        except IOError:
            return None
}