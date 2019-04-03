#include <iostream>
#include "Graph.h"

using std::cout;
using std::cin;
using std::endl;

int main() {

    graph g;
    
    g.addvertex("A");
    g.addvertex("B");
    g.addvertex("C");

    g.addedge("A", "B", 3);
    g.addedge("A", "C", 6);
    
    


    return 0;
}