#include "Graph.h"
#include <sstream>
#include <iostream>

using std::string;
using std::vector;
using std::istream;
/*
* Graph class
*/


/*
* finds Node* with string name 
* returns nullptr if name doesnt exist
* otherwise returns Node*
*/
Node* Graph::find(const string& name)
{
	Node* n = 0;
	for (std::unique_ptr<Node>& node : vec) {
		if (node->getName() == name) {
			n = node.get();
		}
	}
	return n;

}

/*
* adds node with string name if node doesnt already exist in graph
* returns node with string name
*/
void Graph::addNode(const std::string& name) {

	if (find(name) == nullptr) {
		vec.push_back(std::unique_ptr<Node> (new Node(name)));
	}
}

/*
* resets graph
*/
void Graph::reset()
{
	for (std::unique_ptr<Node>& node : vec) node->setValue(node->max_value);	
}

/*
* graph constructor, input from file
* e.g Lund: 12 Dalby
*/
Graph::Graph(std::istream& in) {
	string line, s1, s2;
	int dist{};

	while (std::getline(in, line)) {
		std::istringstream ss(line);
		std::getline(ss, s1, ':');
		ss >> dist;
		std::getline(ss, s2, '\0');
		s2.erase(0,1);

		//std::cout <<"Source: " << s1 <<" | Destination: "<< s2 <<" | Distance: " << dist <<std::endl;

		addNode(s1);
		addNode(s2);

		Node* src = find(s1);
		Node* dest = find(s2);
	
		src->addEdge(dest, dist);
	}

}
