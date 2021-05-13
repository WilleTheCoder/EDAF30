#include "NodeSet.h"

/*
* NodeSet Class
*/

//creates an empty Node set
NodeSet::NodeSet(): vec() {}

/*
* adds node to NodeSet
* unless it already exists
*/
void NodeSet::add(Node* node)
{
	if (!(find(vec.begin(), vec.end(), node) != vec.end())) {
		vec.push_back(node);
	}
}

/*
* returns true if NodeSet is empty
*/
bool NodeSet::isEmpty()
{
	return vec.empty();
}

/*
* returns and removes minumum value from NodeSet
* returns nullptr if NodeSet is empty
*/

Node* NodeSet::removeMin()
{
	Node* min_el = nullptr;
	int min = Node::max_value;
	int counter = -1;
	int index = 0;

	for (Node* node : vec) {
		counter++;
		if (node->getValue() < min) {
			min_el = node;
			min = node->getValue();
			index = counter;
		}
	}

	vec.erase(vec.begin() + index);

	return min_el;
}
