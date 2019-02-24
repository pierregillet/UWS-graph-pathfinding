#ifndef PATHFINDING_ASSIGNMENT_UNDIRECTEDGRAPHHELPER_H
#define PATHFINDING_ASSIGNMENT_UNDIRECTEDGRAPHHELPER_H

#include <boost/graph/graphviz.hpp>

// Vertex properties
typedef boost::property<boost::vertex_name_t, std::string> vertex_p;

// Edge properties
typedef boost::property<boost::edge_weight_t, double> edge_p;

// Graph properties
typedef boost::property<boost::graph_name_t, std::string> graph_p;

// adjacency_list-based type
typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS,
        vertex_p, edge_p, graph_p> graph_t;


class UndirectedGraphHelper {
public:
    static graph_t parseGraphFromFile(const std::string & graphFilename);

    static void printGraph(graph_t graph);

private:
    UndirectedGraphHelper() = default;
};


#endif //PATHFINDING_ASSIGNMENT_UNDIRECTEDGRAPHHELPER_H
