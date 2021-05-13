#include "Node.h"
#include <iostream>

using std::string;
using std::vector;
using std::cout;

/*
* Node class
*/

//creates a node object with string name and maximal value
Node::Node(const string& name): name(name), value(max_value), par(nullptr) {}
/*
* returns Node name
*/
string Node::getName() const
{
	return this->name;
}

/*
* sets node value to v
*/
void Node::setValue(int v)
{
	this->value = v;
}

/*
* returns node value
*/
int Node::getValue() const
{
	return this->value;
}

/*
* adds edge from this node to Node* destination with length l
*/
void Node::addEdge(Node* dest, int l)
{
	vec.emplace_back(dest, l);
}

/*
* returns edges linked to this node
*/
const vector<Edge>& Node::getEdges() const
{
	return this->vec;
}

/*
* returns parent node
*/
void Node::setParent(Node*& node)
{
	this->par = node;
}

/*
* sets parent node
*/
Node* Node::getParent()
{
	return this->par;
}