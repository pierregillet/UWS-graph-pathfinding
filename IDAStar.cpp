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
IDAStar::search(double currentNodeCost) const {
    auto currentNode = path.back();
    auto estimatedTotalCost {currentNodeCost + estimateCost(currentNode)};

    if (estimatedTotalCost > this->bound) {
        return {false, std::make_shared<double>(estimatedTotalCost)};
    }
    if (this->isGoal(currentNode)) {
        return {true};
    }

//    return SearchResult{true, std::make_shared<double>(12.34d)};
}

std::vector<vertex_descriptor>
IDAStar::findSuccessors(vertex_descriptor node) const {

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
