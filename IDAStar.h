#ifndef PATHFINDING_ASSIGNMENT_IDASTAR_H
#define PATHFINDING_ASSIGNMENT_IDASTAR_H

#include <boost/graph/graphviz.hpp>
#include <vector>

#include "UndirectedGraphHelper.h"


//namespace CostValue {
//    constexpr double INFINITY_COST = -1.0d;
//};

struct SearchResult {
    bool isFound = false;
    std::shared_ptr<double> cost = std::make_shared<double>();
};

class IDAStar {
private:
    undirected_graph graph;
    vertex_descriptor root;
    vertex_descriptor goal;
    std::vector<vertex_descriptor> path;

    bool pathFound;
    double bound;

    SearchResult search(const double currentNodeCost);

    std::vector<vertex_descriptor> findSuccessors(vertex_descriptor sourceNode);

    double estimateCost(vertex_descriptor node) const;
//    int calculateStepCost(vertex_iterator node, vertex_iterator successor) const;
    bool isGoal(vertex_descriptor vertexRoot) const;

public:
    IDAStar(undirected_graph & graph, vertex_descriptor root,
            vertex_descriptor goal);

    std::vector<vertex_descriptor> getPath() const;
};


#endif //PATHFINDING_ASSIGNMENT_IDASTAR_H
