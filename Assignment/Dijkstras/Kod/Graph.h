#ifndef GRAPH_H
#define GRAPH_H

#include "Node.h"

#include <vector>
#include <algorithm>
#include <istream>
#include <fstream>
#include <memory>

class Graph
{
public:
	Graph() = default;
	Graph(std::istream& in);
	Node* find(const std::string& name);
	void addNode(const std::string& name);
	void reset();

private: 
	std::vector<std::unique_ptr<Node>> vec;
};
#endif
