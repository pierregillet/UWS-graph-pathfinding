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
    typedef graph_traits<undirected_graph>::vertex_descriptor vertex_descriptor;
    typedef graph_traits<undirected_graph>::out_edge_iterator out_edge_iterator;
}

class UndirectedGraphHelper {
public:
    static undirected_graph parseGraphFromFile(const std::string & graph_filename);

    static vertex_descriptor findNode(undirected_graph & graph, const int & nodeLabel);

    static double getWeightOfEdge(undirected_graph & graph, vertex_descriptor sourceNode,
                                  vertex_descriptor targetNode);

    static void printGraph(undirected_graph & graph);
    static void printPath(undirected_graph graph, std::vector<vertex_descriptor> path);

private:
    UndirectedGraphHelper() = default;
};


#endif //PATHFINDING_ASSIGNMENT_UNDIRECTEDGRAPHHELPER_H
