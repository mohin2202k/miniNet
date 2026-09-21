#include <bits/stdc++.h>
using namespace std;

class Packet {
	string Source;
	string Destination;
	string Payload;
public:
	Packet(string src, string des, string payload):  Source(src), Destination(des), Payload(payload) {}
	string getData(){
		return Payload;
	}
};

class Node {
      string Name;
      string IP;
	vector<Node*> Connections;
	string Data;
public:
	Node(string name, string ip): Name(name), IP(ip), Connections({}) {
		cout << "Created node " << Name << " [" << IP << "]" << endl; 
	}
	string getName(){
		return Name;
	}
	string getIP(){
		return IP;
	}
	vector<Node*> getConnections(){
		return Connections;
	} 
		
	void connect(Node& node){
		Connections.push_back(&node);
		cout << Name << " connected to " << node.getName() << "on IP: [" << node.getIP() << ']'<< endl;
	}
	// void send(Packet packet){
	// 	if(Connection->receive(packet.getData())==1){
	// 		cout << "Data sent successfully." << endl;
	// 	}else{
	// 		cout << "Error! Data not sent successfully" << endl;
	// 	}
	// }
	// int receive(string payload){
	// 	if(payload!=""){
	// 		Data=payload;
	// 		cout << "Data received successfully." << endl;
	// 		return 1;
	// 	}else{
	// 		cout << "No data received." << endl;
	// 		return -1;
	// 	}
	// }
};

class Network{
	string Name;
	vector<Node*> Nodes;
public:
	Network(): Nodes({}) {}
	void addNode(Node& node){
		for(Node* i:Nodes){
			if(i->getIP()==node.getIP()){
				cout << "Node with IP:[" << node.getIP() << "] already exists." << endl << "Node not added." << endl;
				return;
			}
		}
		Nodes.push_back(&node);
		cout << "Added node " << node.getName() << " with IP: [" << node.getIP() << ']' << endl;
	}
	Node* findNodeByIp(string ip){
		for(Node* i : Nodes){
			if(i->getIP()==ip) return i;
		}
		return nullptr;
	}
	vector<Node*> findNodeByName(string name){
		vector<Node*> nodes;
		for(Node* i : Nodes){
			if(i->getName()==name) nodes.push_back(i);
		}
		return nodes;
	}
	void connect(Node& n1, Node& n2){
		for(Node* i : n1.getConnections()){
			if(i->getIP()==n2.getIP()){
				cout << "Connection already exists." << endl;
				return;
			}
		}
		n1.connect(n2);
		n2.connect(n1);
		cout << "Connected " << n1.getName() << " to " << n2.getName() << endl;
	}
};

int main() {
	Network network;
	Node cloudfare("Cloudfare", "1.1.1.1");
	Node google("Google", "8.8.8.8");
	Packet topSecret("1.1.1.1", "8.8.8.8", "");
	network.addNode(cloudfare);
	network.addNode(google);
	network.connect(cloudfare, google);
}