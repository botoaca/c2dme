#pragma once
#include <sstream>
#include "MatrixVector.h"
#include "MapObject.h"

class Map
{
    public:
        Map();
        Map(MatrixVector2 size);

        MatrixVector2 GetSize();
        bool AddObject(MapObject obj);
        MapObject GetObject(MatrixVector2 pos);
        bool UpdateObject(MapObject obj);
        bool RemoveObject(MapObject obj);
        void Print();

    private:
        MatrixVector2 size;
        std::vector<std::vector<MapObject>> map;
};