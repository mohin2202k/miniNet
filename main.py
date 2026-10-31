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
	
	def get_connections(self):
		return self.connections


class Network:
	def __init__(self):
		self.nodes={}
	
	def add_node(self, node):
		if node.get_ip() in self.nodes:
			print(f"Node with IP [{node.get_ip()}] already exists!")
			return
			# if i.get_ip() == node1.get_ip():
			# 	print(f"{node1.get_name()} is already connected to {node2.get_name()}")
			# 	return
		
		self.nodes[node.get_ip()] = node
		print(f"added node {node.get_name()} with ip: [{node.get_ip()}]")
		# node1.connect(node2)
		# node2.connect(node1)
		# print(f"connected {node1.get_name()} to {node2.get_name()}")
	
	def find_node_by_ip(self, ip):
		for node in self.nodes:
			if node.get_ip()==ip:
				return node
		return None
	def find_nodes_by_name(self, name):
			nodes = []
			for node in self.nodes:
				if node.get_name()==name:
					nodes.append(node)
			return nodes
	
	def connect(self, node1, node2):
		if node1.get_ip() == node2.get_ip():
			print("Cannot connect nodes with the same IP")
			return
		for node in node1.get_connections():
			if node.get_ip() == node2.get_ip():
				print(f"node with ip: [{node2.get_ip()}] is already connected to {node1.get_name()}")
				return
		node1.connect(node2)
		node2.connect(node1)
		print(f"connected {node1.get_name()} to {node2.get_name()}")


#----------------------------------MAIN----------------------------------

# packet = Packet("a", "b", "secret")

# print(packet.get_data())
# print(packet.source)
# print(packet.destination)
network = Network()

cloudflare = Node("Cloudfare", "1.1.1.1")
google = Node("Google", "8.8.8.8")

top_secret = Packet("1.1.1.1", "8.8.8.8", "secret")

network.add_node(cloudflare)
network.add_node(google)
network.connect(cloudflare, google)
network.connect(google, cloudflare)