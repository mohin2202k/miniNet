# miniNet

A small C++ project that simulates the basic concepts of a computer network.

## About

**miniNet** is a learning project designed to model how devices communicate with each other through a network.

The project aims to simulate concepts such as:

* Network nodes/devices
* Routers
* Connections between devices
* IP addresses
* Packets
* Packet transmission
* Finding a destination device
* Routing packets through a network

The goal is to build the network simulation from scratch using C++ and object-oriented programming rather than relying on an existing networking library.

## Planned Structure

The project will use different classes to represent different parts of the network.

### Node

Represents an end device in the network.

A node can:

* Have an IP address
* Connect to the network
* Send packets
* Receive packets

### Router

Represents a router responsible for forwarding packets through the network.

A router can:

* Maintain connections to other nodes/routers
* Search for the appropriate destination
* Forward packets
* Act as an intermediary between devices

### Packet

Represents data being transmitted through the network.

A packet may contain information such as:

* Source IP
* Destination IP
* Data
* Other information required for transmission

### Network

Represents the overall network and manages the devices and their connections.

The network is responsible for tasks such as:

* Adding nodes and routers
* Maintaining connections
* Finding devices using their IP addresses
* Determining where packets should be sent

## Example

A simplified network could look like:

```text
       Node A
     192.168.1.2
          |
          |
       Router 1
          |
          |
       Router 2
          |
          |
       Node B
     192.168.2.2
```

When **Node A** sends a packet to **Node B**, the packet can travel through the routers until it reaches its destination.

```text
Node A
  |
  | Packet
  v
Router 1
  |
  | Forward
  v
Router 2
  |
  | Forward
  v
Node B
```

## Goals

The main goal of miniNet is to understand networking concepts by implementing a simplified version of them in C++.

Future improvements may include:

* Multiple routers
* Different network topologies
* Routing algorithms
* Packet loss
* Packet delays
* Network congestion
* Routing tables
* Packet tracing
* Network visualization
* Simulation of different types of network failures

## Technologies

* **C++**
* Object-Oriented Programming
* Data Structures and Algorithms
* Git / GitHub

## Project Status

🚧 **Work in Progress**

miniNet is currently being developed as a learning project. The architecture and features may change as the simulation becomes more complex.

## Author

**Mohin Kumar**
