#include "UndirectedGraphHelper.h"

#include <iostream>


graph_t UndirectedGraphHelper::parseGraphFromFile(const std::string & graphFilename) {
    auto graphFile = std::ifstream(graphFilename);

    graph_t graph(0);
    boost::dynamic_properties dp(boost::ignore_other_properties);

    boost::property_map<graph_t, boost::vertex_name_t>::type name =
            get(boost::vertex_name, graph);
    dp.property("node_id", name);

    boost::property_map<graph_t, boost::edge_weight_t>::type weight =
            get(boost::edge_weight, graph);
    dp.property("label",weight);

    boost::read_graphviz(graphFile, graph, dp, "node_id");

    return graph;
}

void UndirectedGraphHelper::printGraph(graph_t graph) {
    boost::graph_traits<graph_t>::edge_iterator it, end;
    for(tie(it, end) = edges(graph); it != end; ++it) {
        std::cout << get(boost::vertex_name, graph)[source(*it, graph)]
                  << " -> "
                  << get(boost::vertex_name, graph)[target(*it, graph)]
                  << std::endl;
    }
}
