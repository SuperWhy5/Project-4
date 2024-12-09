#include <iostream>
#include <fstream>
#include "course.h"
#include "student.h"
#include "recommendationSystem.h"

using namespace std;

int main(){
    std::ifstream myFile("Test_c_1.txt");

    RecommendationSystem recommend;
    
    recommend.loadData(myFile);

    recommend.outputRecommendations(std::cout);
    return 0;
}