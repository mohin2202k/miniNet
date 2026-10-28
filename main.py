class Packet:
	def __init__(self, source, destination, payload):
		self.source = source
		self.destination = destination
		self.__payload = payload
	
	def get_data(self):
		return self.__payload


class Node:
	def __init__(self, name, ip):
		self.name = name
		self.ip = ip
		self.connections=[]
	
	def get_name(self):
		return self.name
	
	def get_ip(self):
		return self.ip
	
	def connect(self, node):
		self.connections.append(node)
		print(f"{self.name} connected to {node.name} on IP: {node.get_ip()}.")
	
	def get_connections(self):
		return self.connections





#----------------------------------MAIN----------------------------------

# packet = Packet("a", "b", "secret")

# print(packet.get_data())
# print(packet.source)
# print(packet.destination)

cloudflare = Node("Cloudfare", "1.1.1.1")
google = Node("Google", "8.8.8.8")
cloudflare.connect(google)
top_secret = Packet("1.1.1.1", "8.8.8.8", "secret")

for i in cloudflare.get_connections():
	print(f"{i.get_name()} on IP: {i.get_ip()}\n")
	