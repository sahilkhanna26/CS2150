#Sahil Khanna; Tuesday 12:30PM

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -std=c++11# Enable all warnings
DEBUG=-g

a.out: puzzleSolver.o
	$(CXX) $(DEBUG) puzzleSolver.o
	@echo "CS2150 is a lotta work bro" 
	@doxygen

puzzleSolver.o: puzzleSolver.cpp

.PHONY: clean
clean:
	-rm -f *.o a.out