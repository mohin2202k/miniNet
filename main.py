class Packet:
	def __init__(self, src, des, pay):
		self.Source = src
		self.Destination = des
		self.__Payload = pay
	def getData(self):
		return self.__Payload



#----------------------------------MAIN----------------------------------

packet = Packet("a", "b", "secret")

print(packet.getData())
print(packet.Source)
print(packet.Destination)
# print(packet.Payload)