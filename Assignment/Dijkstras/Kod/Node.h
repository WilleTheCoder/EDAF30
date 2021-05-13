#ifndef __NODE_H
#define __NODE_H

#include "Edge.h"
#include <string>
#include <vector>
#include <algorithm>

class Edge;

class Node
{
public:

    Node(const std::string& name);
    std::string getName() const;
    void setValue(int v);
    int getValue() const;
    void addEdge(Node* destination, int length);
    const std::vector<Edge>& getEdges() const;
    void setParent(Node*& node);
    Node* getParent();
    static const int max_value = std::numeric_limits<int>::max();

    private:
    std::string name;
    int value;
    Node* par;
    std::vector<Edge> vec;
};

#endif