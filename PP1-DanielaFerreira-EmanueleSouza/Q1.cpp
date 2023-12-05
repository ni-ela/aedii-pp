#include <iostream>
#include <vector>
#include <list>

// Z representa os inteiros sem sinal
namespace TYPE
{
    typedef unsigned int Z;
}

using namespace std;
using namespace TYPE;

// Define o tipo Vertex como inteiro sem sinal
typedef Z Vertex;

/* Classe GraphAL (graph by adjacency list) */
template <typename G>
class GraphAL
{
private:
    Z num_vertices;
    Z num_edges;
    list<Vertex> *adj;

public:
    GraphAL(Z num_vertices);
    ~GraphAL();
    void add_edge(Vertex u, Vertex v);
    void remove_edge(Vertex u, Vertex v);
    Z get_num_vertices();
    Z get_num_edges();
    list<Vertex> get_adj(Vertex v);
};

template <typename G>
GraphAL<G>::GraphAL(Z num_vertices) : num_vertices(num_vertices), num_edges(0)
{
    adj = new list<Vertex>[num_vertices];
}

template <typename G>
GraphAL<G>::~GraphAL()
{
    for (Z u = 0; u < num_vertices; ++u)
    {
        adj[u].clear();
    }
    delete[] adj;
    adj = nullptr;
    num_vertices = num_edges = 0;
}

bool already_exists(const list<Vertex>& adj, Vertex u, Vertex v) {
    for (const auto& neighbor : adj) {
        if (neighbor == v) {
            return true;
        }
    }
    return false;
}

template <typename G>
void GraphAL<G>::add_edge(Vertex u, Vertex v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);

    num_edges++;
}

template <typename G>
void GraphAL<G>::remove_edge(Vertex u, Vertex v)
{
    adj[u].remove(v);
    adj[v].remove(u);

    num_edges--;
}

template <typename G>
unsigned int GraphAL<G>::get_num_vertices()
{
    return num_vertices;
}

template <typename G>
std::list<Vertex> GraphAL<G>::get_adj(Vertex v)
{
    return adj[v];
}

template <typename G>
void print_graph(GraphAL<G> &g)
{
    for (Z v = 0; v < g.get_num_vertices(); ++v)
    {
        cout << v << ": ";
        for (const auto &neighbor : g.get_adj(v))
        {
            cout << neighbor << ", ";
        }
        cout << endl;
    }
}

template <typename G>
void input_graph(GraphAL<G> &g, Z num_edges)
{
    for (Z i = 0; i < num_edges; i++)
    {
        Vertex u, v;
        cin >> u >> v;
        if(!already_exists(g.get_adj(u), u, v)) {
            g.add_edge(u, v);
        }
    }
}

int main()
{
    Z num_vertices, num_edges;
    cin >> num_vertices >> num_edges;

    GraphAL<Z> g(num_vertices);
    input_graph(g, num_edges);
    print_graph(g);

    return 0;
}
