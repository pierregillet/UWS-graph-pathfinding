#include "IDAStar.h"

#include <boost/graph/graphviz.hpp>


IDAStar::IDAStar(undirected_graph & graph,
                 vertex_iterator root,
                 vertex_iterator goal)
        : graph(graph), root(root), goal(goal) {
    auto bound(estimateCost(*this->root));
    std::cout << bound << std::endl;

}

double
IDAStar::search(std::vector<vertex_iterator> path, const double & currentNodeCost,
                const double & bound) const {

}

std::vector<vertex_iterator>
IDAStar::findSuccessors(vertex_iterator node) const {

}

double
IDAStar::estimateCost(vertex_descriptor node) const {
    using namespace boost;

    auto edgeWeightMap(get(edge_weight, graph));
    out_edge_iterator it, end;
    tie(it, end) = out_edges(node, this->graph);
    double minimumCost = edgeWeightMap[*it];

    if (it != end) {
        ++it;
    }

    for ( ; it != end; ++it) {
        double weight = edgeWeightMap[*it];
        if (weight < minimumCost) {
            minimumCost = weight;
        }
    }

    return minimumCost;
}

//double
//IDAStar::calculateStepCost(vertex_iterator node, vertex_iterator successor) const {
//    for (auto it : this->path) {
//
//    }
//}

bool
IDAStar::isGoal(vertex_descriptor node) const {
    return node == *this->goal;
}
