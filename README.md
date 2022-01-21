# c2dme - console 2d matrix  engine

# Why?
* i was bored
* every time I want to make a 2d array-based game, I find myself rewriting code I've written multiple times before, so this is here as a boilerplate for myself

# Components
* [Map](src/Map.cpp)
    * [MapObject](src/MapObject.cpp)
* [MatrixVector](src/MatrixVector.cpp)
    * 2D
    * 3D
* [Utility](src/Utility.cpp)
    * Logger
    * Utility functions
* [Samples](src/samples)

# Run
The is a [Makefile](Makefile) included, but it's been written for and on Windows, so no testing has been done on other operating systems.
* Edit the 12th line of the Makefile with desired sample
* Run `make`
* Run `.\build\output.exe`