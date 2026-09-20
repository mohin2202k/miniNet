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
	Node *Connection;
	string Data;
public:
	Node(string name, string ip): Name(name), IP(ip), Connection(nullptr) {
		cout << "Created node " << Name << " [" << IP << "]" << endl; 
	}
	string getName(){
		return Name;
	}
	string getIP(){
		return IP;
	}
	void connect(Node& connection){
		Connection=&connection;
		cout << Name << " connected to " << Connection->getName() << "on IP: [" << Connection->getIP() << ']'<< endl;
	}
	void send(Packet packet){
		if(Connection->receive(packet.getData())==1){
			cout << "Data sent successfully." << endl;
		}else{
			cout << "Error! Data not sent successfully" << endl;
		}
	}
	int receive(string payload){
		if(payload!=""){
			Data=payload;
			cout << "Data received successfully." << endl;
			return 1;
		}else{
			cout << "No data received." << endl;
			return -1;
		}
	}
};


int main() {
	Node cloudfare("Cloudfare", "1.1.1.1");
	Node google("Google", "8.8.8.8");
	Packet topSecret("1.1.1.1", "8.8.8.8", "");
	cloudfare.connect(google);
	cloudfare.send(topSecret);
}