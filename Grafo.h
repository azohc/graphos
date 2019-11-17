#include <iostream>
#include <vector>
#include <queue>
#include <assert.h>
using std::pair;
using std::vector;
using std::queue;

class grafo {
public:
    grafo (bool usandoMatrizDeAdyacencia) {
        if (usandoMatrizDeAdyacencia) {
            matriz = std::vector<std::vector<int>> ();
            
        } else {
            listas = std::vector<lista_ady> ();
        }
    }
    // ---------------------------------------------------
    // listas
    void insertar () {
        listas.push_back(lista_ady ());
    }
    
    void conectar (int a, int b, int coste) {
        assert (a < listas.size() &&  b < listas.size());
        listas.at(a).push_back(std::pair<int, int> (b, coste));
        listas.at(b).push_back(std::pair<int, int> (a, coste));
    }

    // ---------------------------------------------------
    // matrices


private:
    enum colors {
        white = 0,
        gray = 1,
        black = 2
    };

    typedef std::vector<std::pair<int, int>> lista_ady;
    std::vector<lista_ady> listas;    

    std::vector<std::vector<int>> matriz;
};


    // ---------------------------------------------------
    // ---------------------------------------------------
    // ---------------------------------------------------


class grafo_dirigido {
public:
    grafo_dirigido (bool usandoMatrizDeAdyacencia) {
        if (usandoMatrizDeAdyacencia) {
            matriz = std::vector<std::vector<int>> ();
            
        } else {
            listas = std::vector<lista_ady> ();
        }
    }
    // ---------------------------------------------------
    // listas
    void insertar () {
        listas.push_back(lista_ady ());
    }
    
    void conectar (int origen, int destino, int coste) {
        assert (origen < listas.size() &&  destino < listas.size());
        listas.at(origen).push_back(std::pair<int, int> (destino, coste));
    }

    pair<std::vector<int>, std::vector<int>> bfs () const {
        auto n = listas.size();
        auto v = std::vector<int>();
        auto dis = std::vector<int>(n);
        auto retVal = pair<std::vector<int>, std::vector<int>> (v, dis);
        auto col = std::vector<colors> (n);
        auto ver = 0;

        while (ver < n) {
            col[ver] = white;
            dis[ver++] = 0;
        }
        
        ver = 0;
        while (ver < n && col[ver] == white) {
            col[ver] = gray;
            v = bfs_aux (ver, col, v, dis);    
        }

        return retVal;
    }

    // ---------------------------------------------------
    // matrices


private:
    enum colors {
        white = 0,
        gray = 1,
        black = 2
    };

    std::vector<int> bfs_aux (
        int ver, 
        std::vector<colors>& col, 
        std::vector<int>& v, 
        std::vector<int>& dis) const {
        
        auto q = std::queue<int>();
        q.push(ver);
        
        while(!q.empty()) {
            ver = q.front();
            q.pop();
            v.push_back(ver);

            std::cout << "v: ";
            for (auto i = v.begin(); i != v.end(); i++) {
                std::cout << *i << " ";
            }
            std::cout << std::endl;

            auto adj = std::vector<std::pair<int,int>> (listas.at(ver));

            std::cout << "adj to " << ver << ": ";
            for (auto i = adj.begin(); i != adj.end(); i++) {
                std::cout << (*i).first << " ";
            }
            std::cout << std::endl;
            
            while (adj.size() > 0) {
                auto next = adj.front().first;
                if (col[next] == white) {
                    col[next] = gray;
                    dis[next] = dis[ver] + 1;
                    q.push(next);
                }
                adj.erase(adj.begin());
            }
            col[ver] = black;
        }
    }

    typedef std::vector<std::pair<int, int>> lista_ady;
    std::vector<lista_ady> listas;    

    std::vector<std::vector<int>> matriz;
};