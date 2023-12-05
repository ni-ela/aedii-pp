#include <iostream>
#include <vector>
#include <list>

// Define o tipo Vertex como inteiro sem sinal
typedef unsigned int Vertex;

/* Classe GraphAL (graph by adjacency list) */
template<typename G>
class GraphAL {
    private:
        unsigned int num_vertices;
        unsigned int num_edges;
        list<unsigned int> *adj;
    public:
        GraphAL(unsigned int num_vertices);
        ~GraphAL();
        void add_edge(Vertex u, Vertex v);
        void remove_edge(Vertex u, Vertex v);
        unsigned int get_num_vertices;
        Vertex get_adj(Vertex v);
};

template <typename Vertex>
GraphAL<Vertex>::GraphAL(unsigned int num_vertices) : num_vertices(num_vertices), num_edges(0) {
    adj = new list<Vertex>[num_vertices];
}

template <typename G>
GraphAL<G>::~GraphAL() {
	for (unsigned int u = 0; u < num_vertices; ++u) {
		adj[u].clear();
	}
	delete[] adj;
	adj = nullptr;
	num_vertices = num_edges = 0;
}

template<typename G>
void GraphAL<G>::add_edge(Vertex u, Vertex v) {
    if(!already_exists(u, v)) {
        adj[u].push_back(v);
        adj[v].push_back(u);

        num_edges++;
    }
}

template<typename G>
void GraphAL<G>::remove_edge(Vertex u, Vertex v) {
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
void input_graph() {
    unsigned int num_vertices, num_edges;
    cin >> num_vertices >> num_edges;

    GraphAL<G> Graph(num_vertices);

    for (unsigned int i = 0; i < num_vertices; i++) {
        Vertex u, v;
        cin >> u >> v;
        Graph.add_edge(u, v);
    }
}

// Lembrar de verificar se a aresta já existe antes de incluí-la

