#include "IDAStar.h"


IDAStar::IDAStar(undirected_graph & graph) : graph(graph) {

}

void IDAStar::findPath(const std::string & vertexRoot) {
    using namespace boost;
    property_map<undirected_graph, vertex_name_t>::type vertexMap(get(vertex_name, this->graph));
    graph_traits<undirected_graph>::vertex_iterator it, end;

//    for(tie(it, end) = vertices(this->graph); it != end; ++it) {
//        std::cout << vertexMap[*it] << std::endl;
//    }
}

void IDAStar::estimateCost(const std::string & vertexRoot) {

}
