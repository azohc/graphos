#include <iostream>
#include <vector>
#include <map>
#include <string>

using std::vector;
using std::map;
using std::multimap;
using std::pair;
using std::string;
using std::cout;

//adjacency list representation for a graph
//  associate each vertex in the graph with the collection of its neighboring vertices or edges.

struct vertex {
    multimap<int, vertex*> map_edges; //cost of edge, destination vertex
    string name;

    vertex(string s) : name(s) {}
};

class graph {
public:
    typedef map<string, vertex*> vmap;
    vmap grmap;

    void addvertex(const string &name) {
        vmap::iterator itr = grmap.find(name);
        if (itr == grmap.end()) {
            vertex *v;
            v = new vertex(name);
            grmap[name] = v;
        } else {
            cout << "\nVertex already exists!";
        }
    }
    void addedge(const string& from, const string& to, int cost) {
        vertex *f = grmap[from];
        vertex *t = grmap[to];
        f->map_edges.insert(pair<int, vertex*>(cost, t));
    }
};

