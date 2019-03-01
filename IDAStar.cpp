#include "IDAStar.h"

#include <boost/graph/graphviz.hpp>


IDAStar::IDAStar(undirected_graph & graph,
                 vertex_descriptor root,
                 vertex_descriptor goal)
        : graph{graph}, root{root}, goal{goal} {

    this->bound = this->estimateCost(this->root);
    this->path.push_back(this->root);
    SearchResult searchResult;
    while (true) {
        std::cout << "new bound : " << this->bound << std::endl;
        searchResult = this->search(0.0);
        if (searchResult.isFound || !searchResult.cost) {
            break;
        }
        bound = *searchResult.cost;
    }
    this->pathFound = searchResult.isFound;
}

SearchResult
IDAStar::search(const double currentNodeCost) {
    auto currentNode = this->path.back();
    auto estimatedTotalCost {currentNodeCost + this->estimateCost(currentNode)};

    if (estimatedTotalCost > this->bound) {
        return {false, std::make_shared<double>(estimatedTotalCost)};
    }
    if (this->isGoal(currentNode)) {
        return {true};
    }

    SearchResult searchResult {};

//    ////////////////////// DEBUG ///////////////////////////
//    auto successors {this->findSuccessors(currentNode)};
//
//    auto vertexMap {get(vertex_name, graph)};
//    auto edgeWeightMap {get(edge_weight, graph)};
//
//    for (vertex_descriptor successor : this->findSuccessors(currentNode)) {
//        std::cout << vertexMap[successor]
////                  << " weight : "
////                  << edgeWeightMap[*it]
//                  << std::endl;
//    }
//
//    ////////////////////// END OF DEBUG ///////////////////////////

    for (vertex_descriptor successor : this->findSuccessors(currentNode)) {
        if (std::find(path.begin(), path.end(), successor) == path.end()) {
            this->path.push_back(successor);
            auto weightToSuccessor {UndirectedGraphHelper::getWeightOfEdge(this->graph, currentNode, successor)};
            auto newSearchResult {this->search(currentNodeCost + weightToSuccessor)};
            if (newSearchResult.isFound) {
                return newSearchResult;
            }

//            ////////////////////// DEBUG ///////////////////////////
//            auto vertexMap {get(vertex_name, graph)};
//            auto edgeWeightMap {get(edge_weight, graph)};
//
//            for (vertex_descriptor successor : this->findSuccessors(currentNode)) {
//                std::cout << vertexMap[successor]
//                          //                  << " weight : "
//                          //                  << edgeWeightMap[*it]
//                          << std::endl;
//            }
//
//            ////////////////////// END OF DEBUG ///////////////////////////

            if (newSearchResult.cost && (!searchResult.cost
                                         || newSearchResult.cost < searchResult.cost)) {
                searchResult.cost = newSearchResult.cost;
            }
            this->path.pop_back();
        }
    }

    return searchResult;
}

std::vector<vertex_descriptor>
IDAStar::findSuccessors(vertex_descriptor sourceNode) {
    using namespace boost;
    auto edgeWeightMap {get(edge_weight, this->graph)};

    std::vector<vertex_descriptor> orderedNodes;

    graph_traits<undirected_graph>::adjacency_iterator it, end;

    for(tie(it, end) = adjacent_vertices(sourceNode, this->graph); it != end; ++it) {
        orderedNodes.push_back(*it);
    }
    std::sort(orderedNodes.begin(), orderedNodes.end(),
              [sourceNode, this](vertex_descriptor i, vertex_descriptor j) {
                  return UndirectedGraphHelper::getWeightOfEdge(this->graph, sourceNode, i)
                         < UndirectedGraphHelper::getWeightOfEdge(this->graph, sourceNode, j);
              }
    );

    return orderedNodes;
}

double
IDAStar::estimateCost(vertex_descriptor node) const {
    using namespace boost;

    auto edgeWeightMap {get(edge_weight, graph)};
    out_edge_iterator it, end;
    tie(it, end) = out_edges(node, this->graph);
    auto minimumCost {edgeWeightMap[*it]};

    if (it != end) {
        ++it;
    }

    for ( ; it != end; ++it) {
        double weight {edgeWeightMap[*it]};
        if (weight < minimumCost) {
            minimumCost = weight;
        }
    }

    return minimumCost;
}

bool
IDAStar::isGoal(vertex_descriptor node) const {
    return node == this->goal;
}

std::vector<vertex_descriptor>
IDAStar::getPath() const {
    return this->path;
}
