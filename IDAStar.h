#ifndef PATHFINDING_ASSIGNMENT_IDASTAR_H
#define PATHFINDING_ASSIGNMENT_IDASTAR_H

#include <boost/graph/graphviz.hpp>
#include <vector>

#include "UndirectedGraphHelper.h"


class IDAStar {
private:
    undirected_graph graph;
    vertex_descriptor root;
    vertex_descriptor goal;
    double currentNodeCost
    std::vector<vertex_descriptor> path;

    double search(std::vector<vertex_descriptor> path, double & currentNodeCost,
                  double & bound) const;

    std::vector<vertex_descriptor> findSuccessors(vertex_descriptor node) const;

    double estimateCost(vertex_descriptor node) const;
//    int calculateStepCost(vertex_iterator node, vertex_iterator successor) const;
    bool isGoal(vertex_descriptor vertexRoot) const;

public:
    IDAStar(undirected_graph & graph, vertex_descriptor root,
            vertex_descriptor goal);
};


#endif //PATHFINDING_ASSIGNMENT_IDASTAR_H
