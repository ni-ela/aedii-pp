// https://www.algotree.org/algorithms/adjacency_list/graph_as_adjacency_list_c++/

/* Includes and definitions */
#include <iostream>
#include <list>
#include <string>

namespace TYPE
{
    typedef unsigned int Z;
}

using namespace std;
using namespace TYPE;

/* Vertex struct */
template <typename T>
class Vertex
{
private:
    string label; // position name. Ex: a1, h2, d3, ...
    T id;

public:
    Vertex(string label, T id);
    // bool operator<(const Vertex &n) const;
    bool operator==(const Vertex &n) const;

    void Display() const
    {
        cout << label << " ";
    }

    void DisplayId() const
    {
        cout << label << id;
    }
};

/* Default Functions */
template <typename T>
Vertex<T>::Vertex(string label, T id) : label(label), id(id)
{
}

/*
template <typename T>
bool Vertex<T>::operator<(const Vertex &n) const
{
    return label < n.label;
}
 */

template <typename T>
bool Vertex<T>::operator==(const Vertex &n) const
{
    return label == n.label && id == n.id;
}

template <typename T>
class ChessBoard
{
private:
    Z num_vertices; // number pieces from the board
    Z num_edges;    // number of moves from the pieces
    list<pair<Vertex<T>, list<Vertex<T>>>> adj;

public:
    ChessBoard(Z num_vertices);
    ~ChessBoard();
    void add_edge(Vertex<T> &src, list<Vertex<T>> &adj);
    void iterate(Vertex<T> src);
    Z get_num_vertices();
};

/* Default Functions */
template <typename T>
ChessBoard<T>::ChessBoard(Z num_vertices) : num_vertices(num_vertices), num_edges(0)
{
}

template <typename T>
ChessBoard<T>::~ChessBoard()
{
    adj.clear();
    num_vertices = num_edges = 0;
}

template <typename T>
void ChessBoard<T>::add_edge(Vertex<T> &src, list<Vertex<T>> &adj_list)
{
    adj.push_back({src, adj_list});
    num_edges++;
}

template <typename T>
Z ChessBoard<T>::get_num_vertices()
{
    return num_vertices;
}

template <typename T>
void ChessBoard<T>::iterate(Vertex<T> src)
{
    src.DisplayId();
    cout << " : ";

    for (const auto &VertexPair : adj)
    {
        if (VertexPair.first == src)
        {
            for (const auto &Vertex : VertexPair.second)
            {
                Vertex.Display();
            }
            break;
        }
    }
    cout << endl;
}

template <typename T>
void input_graph(ChessBoard<T> &g, Z num_edges)
{
    list<Vertex<Z>> vertex_list;

    //for (Z i = 0; i < num_edges; i++)
    //{
        string position;
        cin >> position;

        Vertex<Z> v(position, g.get_num_vertices()+1);
        vertex_list.push_back(v);

        g.add_edge(v, vertex_list);
        //}
        g.iterate(v);
}

int main()
{
    /* chessboard initialization */
    Z num_vertices = 5;
    ChessBoard<Z> chess_board(num_vertices);

    /* plays */
    Z num_plays;
    cin >> num_plays;

    list<Vertex<Z>> k_list;

    /* pieces */
    for (Z i = 0; i < num_vertices; i++)
    {
        /* position */
        string position;
        cin >> position;
        Vertex<Z> k(position, i);
        k_list.push_back(k);
    }

    //input_graph(chess_board, num_plays);

    return 0;
}
