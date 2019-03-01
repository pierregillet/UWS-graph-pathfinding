#include "IDAStar.h"

#include <boost/graph/graphviz.hpp>


IDAStar::IDAStar(undirected_graph & graph,
                 const vertex_iterator & root,
                 const vertex_iterator & goal)
        : graph(graph), root(root), goal(goal) {

}

int
IDAStar::search(std::vector<vertex_iterator> path, const int & currentNodeCost,
                const int & bound) const {

}

std::vector<vertex_iterator>
IDAStar::findSuccessors(vertex_iterator node) const {

}

int
IDAStar::estimateCost(vertex_iterator node) const {

}

bool
IDAStar::isGoal(vertex_iterator node) const {
    return node == this->goal;

}
