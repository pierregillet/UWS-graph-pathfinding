#include "IDAStar.h"

#include <boost/graph/graphviz.hpp>


IDAStar::IDAStar(undirected_graph & graph,
                 vertex_descriptor root,
                 vertex_descriptor goal)
        : graph{graph}, root{root}, goal{goal} {

    this->bound = this->estimateCost(this->root);
    this->path.push_back(this->root);
    while (true) {
        auto searchResult {this->search(0.0d)};
        if (searchResult.isFound
            || !searchResult.cost) {
            this->pathIsFound = searchResult.isFound;
            break;
        }
        bound = *searchResult.cost;
    }
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

    for (vertex_descriptor successor : this->findSuccessors(currentNode)) {
        if (std::find(path.begin(), path.end(), successor) != path.end()) {
            this->path.push_back(successor);

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
              [sourceNode, edgeWeightMap, this](vertex_descriptor i, vertex_descriptor j) {
                  auto iEdge {edge(sourceNode, i, this->graph)};
                  auto jEdge {edge(sourceNode, j, this->graph)};
                  if (!iEdge.second || !jEdge.second) {
                          throw std::runtime_error("Edge not found.");
                  }
                  return edgeWeightMap[iEdge.first] < edgeWeightMap[jEdge.first];
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
