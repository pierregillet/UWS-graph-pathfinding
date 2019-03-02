#ifndef PATHFINDING_ASSIGNMENT_IDASTAR_H
#define PATHFINDING_ASSIGNMENT_IDASTAR_H

#include <boost/graph/graphviz.hpp>
#include <vector>

#include "UndirectedGraphHelper.h"


struct SearchResult {
    bool isFound {false};
    std::shared_ptr<double> cost {nullptr};
};

class IDAStar {
private:
    undirected_graph graph;
    vertex_descriptor root;
    vertex_descriptor goal;
    std::vector<vertex_descriptor> path;
    property_map<undirected_graph, vertex_name_t>::type vertexNameMap;
    bool pathFound;
    double bound;

    SearchResult search(const double currentNodeCost);
    std::vector<vertex_descriptor> findSuccessors(vertex_descriptor sourceNode);
    double estimateCost(vertex_descriptor node, vertex_descriptor parentNode) const;
    bool isGoal(vertex_descriptor vertexRoot) const;

public:
    IDAStar(undirected_graph & graph, vertex_descriptor root,
            vertex_descriptor goal);

    std::pair<std::vector<vertex_descriptor>, double> getPath() const;
};


#endif //PATHFINDING_ASSIGNMENT_IDASTAR_H
