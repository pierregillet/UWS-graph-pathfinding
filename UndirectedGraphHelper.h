#ifndef PATHFINDING_ASSIGNMENT_UNDIRECTEDGRAPHHELPER_H
#define PATHFINDING_ASSIGNMENT_UNDIRECTEDGRAPHHELPER_H

#include <boost/graph/graphviz.hpp>


namespace {
    using namespace boost;

    typedef property<vertex_name_t, std::string> vertex_properties;
    typedef property<edge_weight_t, double> edge_properties;
    typedef property<graph_name_t, std::string> graph_properties;
    typedef adjacency_list<vecS, vecS, undirectedS, vertex_properties,
            edge_properties, graph_properties> undirected_graph;
    typedef graph_traits<undirected_graph>::vertex_iterator vertex_iterator;
}

class UndirectedGraphHelper {
public:
    static undirected_graph parseGraphFromFile(const std::string & graph_filename);

    static vertex_iterator findNode(undirected_graph & graph, const int & nodeLabel);
    static void printGraph(undirected_graph & graph);

private:
    UndirectedGraphHelper() = default;
};


#endif //PATHFINDING_ASSIGNMENT_UNDIRECTEDGRAPHHELPER_H
