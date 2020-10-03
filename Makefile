CXX=g++
CXXFLAGS=-Wall -std=c++14 -g
SRC=main.cpp

all:
	$(CXX) $(CXXFLAGS) -o mergesort $(SRC)

clean:
	@rm -f mergesort
	@rm -f *.o
format:
	clang-format --verbose --sort-includes -i *.cpp *.hpp
