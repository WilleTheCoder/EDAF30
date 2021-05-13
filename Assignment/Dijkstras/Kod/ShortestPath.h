#ifndef SHORTESTPATH_H
#define SHORTESTPATH_H

#include "Node.h"
#include "NodeSet.h"
#include <vector>

class ShortestPath
{
public:
	ShortestPath();
	void dijkstra(Node* start);
	void general_Dijkstra(Node* start, int (*f)(const Edge&));
	void printResult(Node* dest);
	int result(Node* dest);
private:
	NodeSet set{};
};
#endif