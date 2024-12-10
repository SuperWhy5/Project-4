

#include <iostream>
#include "Student.h"
#include "Course.h"
#include "RecommendationSystem.h"
using namespace std;

int main(int argc, char* argv[]) {

    RecommendationSystem rs("Bill");

    RecommendationSystem rs;
    rs.loadData(argv[1]);

    rs.outputRecommendations(cout);
    return 0;
}
