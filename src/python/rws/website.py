import os
import sys

from httphds import HTTPHeaders

class Website:
	
	root = "..\\www"
	server_name = "localhost"
	server_port = 80
	
	def __init__(self, server_name, server_port):
		self.server_name = server_name
		self.server_port = server_port
		
	def setRootDir(self, root):
		self.root = root
		
	def findFile(self, path):
		files = self.walkDir()
		if len(files) > 0:
			return files[0]
		
		return None
		
	def walkDir(self):
		result = []
		stack = [self.root]
		index = 0
		
		while index < len(stack):
			current_dir = stack[0]
			index = index + 1
			
			try:
				entries = os.listdir(current_dir)
			except:
				continue
				
			for entry in entries:
				full_path = os.path.join(current_dir, entry)
				if os.path.isfile(full_path):
					result.append((current_dir, [], [entry]))
				elif os.path.isdir(full_path):
					stack.append(full_path)
				print "Entry:", full_path
					
		return result
		
	def getContentByFile(self, path):
		path = self.findFile(path)
		content = None
		return content