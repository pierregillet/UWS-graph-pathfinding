#include "UndirectedGraphHelper.h"

#include <boost/graph/graphviz.hpp>
#include <iostream>


undirected_graph
UndirectedGraphHelper::parseGraphFromFile(const std::string & graph_filename) {
    auto graphFile = std::ifstream(graph_filename);

    undirected_graph graph(0);
    boost::dynamic_properties dp(boost::ignore_other_properties);

    auto name(get(boost::vertex_name, graph));
    dp.property("node_id", name);

    auto weight(get(boost::edge_weight, graph));
    dp.property("label",weight);

    boost::read_graphviz(graphFile, graph, dp, "node_id");

    return graph;
}

vertex_iterator
UndirectedGraphHelper::findNode(undirected_graph & graph, const int & nodeLabel) {
    using namespace boost;
    auto vertexNameMap(get(vertex_name, graph));
    vertex_iterator it, end;

    for(tie(it, end) = vertices(graph); it != end; ++it) {
        if (std::to_string(nodeLabel) == vertexNameMap[*it]) {
            return it;
        }
    }

    throw std::runtime_error("Vertex with label " + std::to_string(nodeLabel) + " not found");
}

void UndirectedGraphHelper::printGraph(undirected_graph & graph) {
    using namespace boost;

    auto vertexMap(get(vertex_name, graph));
    auto edgeWeightMap(get(edge_weight, graph));

    graph_traits<undirected_graph>::edge_iterator it, end;
    for(tie(it, end) = edges(graph); it != end; ++it) {
        std::cout << vertexMap[source(*it, graph)]
                  << " -> "
                  << vertexMap[target(*it, graph)]
                  << " weight : "
                  << edgeWeightMap[*it]
                  << std::endl;
    }
}
