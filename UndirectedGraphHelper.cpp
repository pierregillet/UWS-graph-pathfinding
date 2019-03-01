#include "UndirectedGraphHelper.h"

#include <boost/graph/graphviz.hpp>
#include <iostream>


undirected_graph
UndirectedGraphHelper::parseGraphFromFile(const std::string & graph_filename) {
    auto graphFile = std::ifstream(graph_filename);

    undirected_graph graph(0);
    boost::dynamic_properties dp(boost::ignore_other_properties);

    boost::property_map<undirected_graph, boost::vertex_name_t>::type name =
            get(boost::vertex_name, graph);
    dp.property("node_id", name);

    boost::property_map<undirected_graph, boost::edge_weight_t>::type weight =
            get(boost::edge_weight, graph);
    dp.property("label",weight);

    boost::read_graphviz(graphFile, graph, dp, "node_id");

    return graph;
}

vertex_iterator
UndirectedGraphHelper::findNode(undirected_graph & graph, const int & nodeLabel) {
    using namespace boost;
    property_map<undirected_graph, vertex_name_t>::type vertexMap(get(vertex_name, graph));
    vertex_iterator it, end;

    tie(it, end) = vertices(graph);

    for(tie(it, end) = vertices(graph); it != end; ++it) {
        if (std::to_string(nodeLabel) == vertexMap[*it]) {
            return it;
        }
    }

    throw std::runtime_error("Vertex with label " + std::to_string(nodeLabel) + " not found");
}

void UndirectedGraphHelper::printGraph(undirected_graph & graph) {
    boost::property_map<undirected_graph, boost::vertex_name_t>::type vertexMap(get(boost::vertex_name, graph));
    boost::property_map<undirected_graph, boost::edge_weight_t>::type edgeWeightMap(get(boost::edge_weight, graph));

    boost::graph_traits<undirected_graph>::edge_iterator it, end;
    for(tie(it, end) = boost::edges(graph); it != end; ++it) {
        std::cout << vertexMap[source(*it, graph)]
                  << " -> "
                  << vertexMap[target(*it, graph)]
                  << " weight : "
                  << edgeWeightMap[*it]
                  << std::endl;
    }
}
