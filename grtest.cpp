#include <iostream>
#include "Grafo.h"

using std::cout;
using std::cin;
using std::endl;

int main() {

    grafo_dirigido g (false);
    
    for (auto i = 0; i < 10; i++) {
        g.insertar();
    }

    g.conectar(0, 4, -1);
    g.conectar(0, 8, -1);
    g.conectar(1, 0, -1);
    g.conectar(1, 2, -1);
    g.conectar(1, 5, -1);
    g.conectar(2, 5, -1);
    g.conectar(2, 6, -1);
    g.conectar(3, 2, -1);
    g.conectar(3, 7, -1);
    // g.conectar(3, 9, -1);
    g.conectar(4, 1, -1);
    g.conectar(5, 6, -1);
    g.conectar(6, 7, -1);
    g.conectar(7, 2, -1);
    g.conectar(8, 4, -1);

    std::pair<std::vector<int>, std::vector<int>> p = g.bfs();
    return 0;

    cout << "secuencia de vistas: ";
    for (auto i = p.first.begin(); i != p.first.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;

    cout << "vector de distancias: ";
    for (auto i = p.second.begin(); i != p.second.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;

    return 0;
}