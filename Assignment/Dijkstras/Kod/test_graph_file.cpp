
#include "Graph.h"
#include <fstream>
#include <istream>
#include <ostream>
#include <string>
#include <iostream>
#include "Shortestpath.h"
#include <cassert>

using std::cout;
using std::endl;

void test_graph_file() {
	std::ifstream read("graf.txt");


	if (read.is_open()) {
		Graph g(read);
		auto t1 = g.find("ankeborg");
		assert(t1 == nullptr);

		auto t2 = g.find("Lund");
		assert(t2 != nullptr);

		g.addNode("ankeborg");
		auto t3 = g.find("ankeborg");
		assert(t3 != nullptr);

		auto t4 = g.find("Lund")->getValue();
		assert(t4 == std::numeric_limits<int>::max());

		g.reset();

		cout << "test_graph_file passed" << endl;
	}
	else {
		cout << "could not find file" << endl;
	}
} 

int main(void) {
	test_graph_file();
}


