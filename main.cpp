#include "UndirectedGraphHelper.h"
#include "IDAStar.h"


int main(int argc, char * argv[]) {
    std::string graphFilename("random64_4_1485816605.dot");

    undirected_graph graph = UndirectedGraphHelper::parseGraphFromFile(graphFilename);

//    UndirectedGraphHelper::printGraph(graph);

    IDAStar pathFinder = IDAStar(graph);
    pathFinder.findPath("2");

    return 0;
}
