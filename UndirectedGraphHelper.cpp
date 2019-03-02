#include "UndirectedGraphHelper.h"

#include <boost/graph/graphviz.hpp>
#include <iostream>


undirected_graph
UndirectedGraphHelper::parseGraphFromFile(const std::string & graph_filename) {
    std::ifstream graphFile {graph_filename};
    undirected_graph graph {0};
    boost::dynamic_properties dp {boost::ignore_other_properties};

    auto name {get(boost::vertex_name, graph)};
    dp.property("node_id", name);

    auto weight {get(boost::edge_weight, graph)};
    dp.property("label",weight);

    boost::read_graphviz(graphFile, graph, dp, "node_id");

    return graph;
}

vertex_descriptor
UndirectedGraphHelper::findNode(undirected_graph & graph, const int & nodeLabel) {
    using namespace boost;
    auto vertexNameMap {get(vertex_name, graph)};
    vertex_iterator it, end;

    for(tie(it, end) = vertices(graph); it != end; ++it) {
        if (std::to_string(nodeLabel) == vertexNameMap[*it]) {
            return *it;
        }
    }

    throw std::runtime_error("Vertex with label " + std::to_string(nodeLabel) + " not found");
}

double
UndirectedGraphHelper::getWeightOfEdge(undirected_graph & graph,
                                       vertex_descriptor sourceNode,
                                       vertex_descriptor targetNode) {
    using namespace boost;
    auto edgeWeightMap {get(edge_weight, graph)};

    auto currentEdge {edge(sourceNode, targetNode, graph)};
    if (!currentEdge.second) {
        throw std::runtime_error("Edge not found.");
    }

    return edgeWeightMap[currentEdge.first];
}

void UndirectedGraphHelper::printGraph(undirected_graph & graph) {
    using namespace boost;

    auto vertexMap {get(vertex_name, graph)};
    auto edgeWeightMap {get(edge_weight, graph)};

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


void
UndirectedGraphHelper::printPath(undirected_graph graph,
                                 std::vector<vertex_descriptor> path) {
    using namespace boost;

    auto vertexNameMap {get(vertex_name, graph)};
    auto edgeWeightMap {get(edge_weight, graph)};

    if (path.size() < 2) {
        throw std::runtime_error("Path too short to print");
    }

    for (auto i {0}; i < path.size() - 1; ++i) {
        auto currentEdge {edge(path[i], path[i + 1], graph)};
        if (!currentEdge.second) {
            throw std::runtime_error("Cannot print path : edge not found.");
        }
        std::cout << vertexNameMap[source(currentEdge.first, graph)]
                  << " -> "
                  << vertexNameMap[target(currentEdge.first, graph)]
                  << " weight : "
                  << edgeWeightMap[currentEdge.first]
                  << std::endl;
    }
}
