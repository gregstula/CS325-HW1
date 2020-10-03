CXX=g++
CXXFLAGS=-Wall -std=c++14 -g

all:
	$(CXX) $(CXXFLAGS) -o mergesort mergesort.cpp
	$(CXX) $(CXXFLAGS) -o insertsort insertsort.cpp

clean:
	@rm -f mergesort merge.out
	@rm -f insertsort insert.out
	@rm -f *.o
format:
	clang-format --verbose --sort-includes -i *.cpp *.hpp
