#include <iostream>
#include "RecommendationSystem.h"

int main(int argc, char* argv[]) {

    RecommendationSystem rs;
    rs.loadData(argv[1]);

    rs.outputRecommendations(std::cout);
    return 0;
}
