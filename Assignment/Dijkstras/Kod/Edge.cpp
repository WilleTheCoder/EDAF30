#include "Edge.h"

/*
* Edge class
*/

//creates a Edge to destination Node with length l
Edge::Edge(Node* destination, int l) : destination(destination), length(l) {}
/*
* returns Edge destination 
*/
Node* Edge::getDest() const
{
	return this->destination;
}

/*
* returns Edge length
*/
int Edge::getLength() const
{
	return this->length;
}

/*
* sets Edge length
*/
void Edge::setLenght(int length)
{
	this->length = length;
}
