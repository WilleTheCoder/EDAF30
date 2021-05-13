
#include <iostream>
#include <cassert>
#include "ShortestPath.h"
#include "Node.h"

using std::cout;
using std::endl;

void test()
{
   Node lund{"lund"};
   Node dalby{"dalby"};
   Node sandby{"sodra sandby"};
   Node hallestad{"torna hallestad"};
   Node flyinge{"flyinge"};
   Node veberod{"veberod"};

   
   lund.addEdge(&dalby,12);
   lund.addEdge(&sandby,12);
   dalby.addEdge(&sandby,12);
   dalby.addEdge(&veberod,11);
   dalby.addEdge(&hallestad,5);
   sandby.addEdge(&lund,12);
   sandby.addEdge(&flyinge,4);
   hallestad.addEdge(&veberod,8);
   
   ShortestPath sp;
   sp.dijkstra(&lund);
  
   assert(lund.getValue() == 0);
   assert(dalby.getValue() == 12);
   assert(sandby.getValue() == 12);
   assert(hallestad.getValue() == 17);
   assert(veberod.getValue() == 23);
   assert(flyinge.getValue() == 16);
   

#ifdef info
   cout << "----\nall distances from lund:\n";

   for(auto& t : {lund, dalby, sandby, hallestad, veberod, flyinge}) {
       cout << t.getname() << " : " << t.getvalue() << " ";
       cout << endl;
   }
#endif
   cout << "test_dijkstra passed" << endl;
}


int main()
{
   test();
   return 0;
}
