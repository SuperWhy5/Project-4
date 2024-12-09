CXX = g++
OPTIONS = -Wall
PROGRAM = main.exe

all: $(PROGRAM)

run: $(PROGRAM)
	./$(PROGRAM)

$(PROGRAM): main.cpp course.cpp student.cpp recommendationSystem.cpp 
	$(CXX) $(OPTIONS) main.cpp course.cpp student.cpp recommendationSystem.cpp  -o $(PROGRAM) 

clean:
	rm -f $(PROGRAM)