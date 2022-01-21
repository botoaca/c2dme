CXX = g++ --std=c++20
CXXFLAGS = -Wall

all: build build/output

build:
	mkdir build

build/output: build/main.o build/utility.o build/matrixvector.o build/mapobject.o build/map.o
	$(CXX) $(CXXFLAGS) $^ -o $@

build/main.o: src/samples/base.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

build/utility.o: src/Utility.cpp src/include/Utility.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

build/matrixvector.o: src/MatrixVector.cpp src/include/MatrixVector.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

build/mapobject.o: src/MapObject.cpp src/include/MapObject.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

build/map.o: src/Map.cpp src/include/Map.h
	$(CXX) $(CXXFLAGS) -c $< -o $@