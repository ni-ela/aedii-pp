#include <list>
#include <iostream>

using namespace std;

// Define os tipos Vertex e Weight como inteiro sem sinal e ponto flutuante, respectivamente.
typedef unsigned int Vertex, Weight;

/* Classe GraphAM (graph by adjacency matrix ) */
template<typename G>
class GraphAM {
    private:
        unsigned int num_vertices;
        unsigned int num_edges;
        list<unsigned int> adj;
    public:
        GraphAM(unsigned int num_vertices); // ok
        ~GraphAM(); // ok
        void add_edge(Vertex u, Vertex v, Weight w);
        void remove_edge(Vertex u, Vertex v);
        unsigned int get_num_vertices;
        Vertex get_adj(Vertex v);
        Weight get_weight(Vertex u, Vertex v);

};

template <typename G>
GraphAM<G>::~GraphAM() {
	for (unsigned int u = 0; u < num_vertices; ++u) {
		adj[u].clear();
	}
	delete[] adj;
	adj = nullptr;
	num_vertices = num_edges = 0;
}

template<typename G>
void GraphAM<G>::add_edge(Vertex u, Vertex v, Weight w) {
    if(!already_exists(u, v)) {
        adj[u].push_back(v);
        adj[v].push_back(u);

        num_edges++;
    }
}

template<typename G>
void GraphAM<G>::remove_edge(Vertex u, Vertex v) {
    if(already_exists(u, v)) {
        adj[u].remove(v);
        adj[v].remove(u);

        num_edges--;
    }
}

// Verifica se a aresta já existe antes de incluí-la ou removê-la
template<typename G>
bool already_exists(Vertex u, Vertex v) {
    if(G.adj[u].find(v) != G.adj[u].end()) {
        return true;
    }
}

template<typename G>
void print_graph(GraphAM<G> G) {
    cout << 'num_vertices: ';
    cout << 'num_edges: ';

    for (unsigned int i = 0; i < G.get_num_vertices; i++)
    {
        cout << i << ': ';
    }
}

template<typename G>
void input_graph() {
    unsigned int num_vertices, num_edges;
    cin >> num_vertices >> num_edges;

    GraphAM<G> G(num_vertices);

    for (unsigned int i = 0; i < num_vertices; i++) {
        Vertex u, v;
        Weight w;
        cin >> u >> v >> w;
        G.add_edge(u, v, w);
    }
}