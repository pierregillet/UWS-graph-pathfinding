#include "UndirectedGraphHelper.h"


int main(int argc, char * argv[]) {
    std::string graphFilename("random64_4_1485816605.dot");

    graph_t graph = UndirectedGraphHelper::parseGraphFromFile(graphFilename);

    UndirectedGraphHelper::printGraph(graph);

    return 0;
}
