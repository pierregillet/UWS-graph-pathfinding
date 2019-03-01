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

    double search(std::vector<vertex_iterator> path, const double & currentNodeCost,
               const double & bound) const;

    std::vector<vertex_iterator> findSuccessors(vertex_iterator node) const;

    double estimateCost(vertex_descriptor node) const;
//    int calculateStepCost(vertex_iterator node, vertex_iterator successor) const;
    bool isGoal(vertex_descriptor vertexRoot) const;

public:
    IDAStar(undirected_graph & graph, vertex_iterator root,
            vertex_iterator goal);
};


#endif //PATHFINDING_ASSIGNMENT_IDASTAR_H
