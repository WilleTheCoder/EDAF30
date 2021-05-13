#include <iostream>
#include "ShortestPath.h"
#include "Node.h"
#include <vector>


int main(void) {

	Node lund{ "Lund" };
	Node dalby{ "Dalby" };
	Node sandby{ "Sodra Sandby" };
	Node hallestad{ "Torna Hallestad" };
	Node flyinge{ "Flyinge" };
	Node veberod{ "Veberod" };

	lund.addEdge(&dalby, 12);
	lund.addEdge(&sandby, 12);
	dalby.addEdge(&sandby, 12);
	dalby.addEdge(&veberod, 11);
	dalby.addEdge(&hallestad, 5);
	sandby.addEdge(&lund, 12);
	sandby.addEdge(&flyinge, 4);
	hallestad.addEdge(&veberod, 8);

	std::vector<std::pair<int,Node*>> vec{};
	
	vec.push_back(std::make_pair(0, &lund));
	vec.push_back(std::make_pair(1, &dalby));
	vec.push_back(std::make_pair(2, &sandby));
	vec.push_back(std::make_pair(3, &hallestad));
	vec.push_back(std::make_pair(4, &flyinge));
	vec.push_back(std::make_pair(5, &veberod));

	int start, end;
	Node* srcNode{};
	Node* destNode{};
	int operation;
	std::cout << "Hello Traveler!" << "\n\n";
	std::cout << "Places in database:" << "\n\n";

	int count = 0;
	for (auto n : vec) {
	std::cout <<count<< ": " <<n.second->getName() << std::endl;
	count++;
	}

	std::cout << "\nSelect a start point: (0-5) " << std::endl;
	std::cin >> start;

		for (auto it : vec) {
			if (it.first == start) {
				srcNode = it.second;
			}
		}

		std::cout << "\nSelect a destination: (0-5) " << std::endl;
		std::cin >> end;

		for (auto it : vec) {
			if (it.first == end) {
				destNode = it.second;
			}
		}
		
			if (srcNode != nullptr && destNode != nullptr) {

				std::cout << "\nChoose Optimization algoritm: " << std::endl;
				std::cout << "0: for fewest number of cities optimization" << std::endl;
				std::cout << "1: for least distance optimization" << std::endl;

				std::cin >> operation;
				ShortestPath sp;

				switch (operation) {
				case 0: 
					sp.general_Dijkstra(srcNode, [](const Edge& e) -> int { return 1; });
					break;
				case 1: 
					sp.general_Dijkstra(srcNode, [](const Edge& e) -> int { return e.getLength(); });
					break;
				}

				if (sp.result(destNode) == Node::max_value || sp.result(destNode)==0) {
					std::cout << "\nThere is no path from given src to destination." << std::endl;
				}
				else {
					sp.printResult(destNode);
				}
			}
			else {
				std::cout << "\nNot in database." << std::endl;
			}
			
			std::cout << "\n--------------------------------" << std::endl;
			std::cin.get();
		}

