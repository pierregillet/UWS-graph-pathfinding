#ifndef PATHFINDING_ASSIGNMENT_IDASTAR_H
#define PATHFINDING_ASSIGNMENT_IDASTAR_H

#include "UndirectedGraphHelper.h"


class IDAStar {
private:
    undirected_graph graph;

public:
    explicit IDAStar(undirected_graph & graph);

    void findPath(const std::string & vertexRoot);
    void estimateCost(const std::string & vertexRoot);

};


#endif //PATHFINDING_ASSIGNMENT_IDASTAR_H
