CXX = g++
OPTIONS = -Wall
PROGRAM = main.exe

all: $(PROGRAM)

run: $(PROGRAM)
	./$(PROGRAM)

$(PROGRAM): main.cpp Course.cpp Student.cpp RecommendationSystem.cpp 
	$(CXX) $(OPTIONS) main.cpp Course.cpp Student.cpp RecommendationSystem.cpp  -o $(PROGRAM) 

clean:
	rm -f $(PROGRAM)