#ifndef NODESET_H
#define NODESET_H

#include "Node.h"
#include <algorithm>

class NodeSet
{
public:
	NodeSet();
	void add(Node* node);
	bool isEmpty();
	Node* removeMin();

private:
	std::vector<Node*> vec;

};
#endif
