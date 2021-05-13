#ifndef EDGE_H
#define EDGE_H

#include "Node.h"

class Node;

class Edge
{
public:
	Edge(Node* destination, int length);
	Node* getDest() const;
	int getLength() const;
	void setLenght(int length);

private:
	Node* destination;
	int length;
};
#endif

