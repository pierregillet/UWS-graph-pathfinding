#ifndef PATHFINDING_ASSIGNMENT_IDASTAR_H
#define PATHFINDING_ASSIGNMENT_IDASTAR_H

#include <boost/graph/graphviz.hpp>
#include <vector>

#include "UndirectedGraphHelper.h"


class IDAStar {
private:
    undirected_graph graph;
    vertex_iterator root;
    vertex_iterator goal;
    std::vector<vertex_iterator> path;

    int search(std::vector<vertex_iterator> path, const int & currentNodeCost,
               const int & bound) const;

    std::vector<vertex_iterator> findSuccessors(vertex_iterator node) const;

    int estimateCost(vertex_iterator node) const;
    bool isGoal(vertex_iterator vertexRoot) const;

public:
    IDAStar(undirected_graph & graph, const vertex_iterator & root,
            const vertex_iterator & goal);
};


#endif //PATHFINDING_ASSIGNMENT_IDASTAR_H
