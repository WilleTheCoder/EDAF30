
#include "Node.h"
#include "ShortestPath.h"
#include <iostream>
#include <cassert>

using std::cout;
using std::endl;

void test_gen_false()
{
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
   
   ShortestPath sp;

   sp.general_Dijkstra(&lund, [](const Edge& e) -> int { return e.getLength();});

   auto t1 = sp.result(&veberod);
   assert(t1 == 23);

   sp.general_Dijkstra(&dalby, [](const Edge& e) -> int { return e.getLength(); });
   auto t2 = sp.result(&flyinge);
   assert(t2 == 16);
   
   cout << "Test_general_false passed" << endl;
}

void test_gen_true()
{
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
   
   ShortestPath sp;
   sp.general_Dijkstra(&lund, [](const Edge& e) -> int { return 1; });

   auto t1 = sp.result(&veberod);
   assert(t1 == 2);

   sp.general_Dijkstra(&lund, [](const Edge& e) -> int { return 1;});
   auto t2 = sp.result(&sandby);
   assert(t2 == 1);


   cout << "Test_general_true passed" << endl;
}
int main(void)
{
   test_gen_true();
   test_gen_false();

}
