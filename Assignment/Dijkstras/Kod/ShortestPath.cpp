#include "ShortestPath.h"
#include <iostream>
using std::string;
using std::vector;

/*
*Shortest Path algoritm class (dijkstras)
*/

//constructor
ShortestPath::ShortestPath(){}

/*
* dijkstra algoritm given startnode start
*/
void ShortestPath::dijkstra(Node* start)
{
	start->setValue(0);
	set.add(start);

	while (!set.isEmpty()) {

		Node* c_node = set.removeMin();

		for (Edge edge : c_node->getEdges())
		{
			int len = edge.getLength();
			Node* edge_node = edge.getDest();
			int val = c_node->getValue() + len;

			if (val < edge_node->getValue()) {
				edge_node->setValue(val);
				edge_node->setParent(c_node);
				set.add(edge_node);
			}
		}
	}

}

/*
* general djikstra algoritm with startnode start and functionsobject Edge
*/

void ShortestPath::general_Dijkstra(Node* start, int (*f)(const Edge&))
{
	start->setValue(0);
	set.add(start);

	while (!set.isEmpty()) {

		Node* c_node = set.removeMin();

		for (Edge edge : c_node->getEdges())
		{
			Node* edge_node = edge.getDest();
			int len = (*f)(edge); // length based on nbr of cities or weight
			int val = c_node->getValue() + len;

			if (val < edge_node->getValue()) {
				edge_node->setValue(val);
				edge_node->setParent(c_node);
				set.add(edge_node);
			}
		}
	}
}

/*
* prints out the path from source to destination and the total cost
*/
void ShortestPath::printResult(Node* dest)
{
	vector<Node*> it;
	Node* dest_org = dest;
	while (dest != nullptr) {
		it.push_back(dest);
		dest= dest->getParent();
	}
	reverse(it.begin(), it.end());

	string ap;

	for (auto n : it) {
		ap.append(n->getName() + " ");
	}
	ap.append(std::to_string(result(dest_org)));

	std::cout << ap;
}

/*
* returns the total cost
*/
int ShortestPath::result(Node* dest)
{
	return dest->getValue();
}
