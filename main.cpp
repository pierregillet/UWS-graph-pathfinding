#include <boost/graph/graphviz.hpp>

#include "UndirectedGraphHelper.h"
#include "IDAStar.h"


std::string getline() {
    std::string str;
    std::getline(std::cin, str);
    return str;
}

template <typename T>
T getInputFromUser() {
    T input;
    std::istringstream iss{getline()};
    iss >> input >> std::ws;
    if(iss.fail() || !iss.eof()) {
        throw std::runtime_error("Input error.");
    }
    return input;
}

int main(int argc, char * argv[]) {
    using namespace boost;
    std::string graphFilename {"random64_4_1485816605.dot"};
    auto graph {UndirectedGraphHelper::parseGraphFromFile(graphFilename)};

//    UndirectedGraphHelper::printGraph(graph);

    std::cout << "Root node number:" << std::endl << "> ";
    auto rootNodeNumber {getInputFromUser<int>()};
    auto root {UndirectedGraphHelper::findNode(graph, rootNodeNumber)};
    std::cout << "Goal node number:" << std::endl << "> ";
    auto goalNodeNumber {getInputFromUser<int>()};
    auto goal {UndirectedGraphHelper::findNode(graph, goalNodeNumber)};

    IDAStar pathFinder {graph, root, goal};
    auto completePath {pathFinder.getPath()};

    std::cout << "Cost of the shortest path: " << completePath.second << std::endl;

    UndirectedGraphHelper::printPath(graph, completePath.first);

    return 0;
}
