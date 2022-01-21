#pragma once
#include "MatrixVector.h"

class MapObject
{
    public:
        MapObject();
        MapObject(MatrixVector2 pos, char c, RGB bg, RGB fg);

        MatrixVector2 GetPos();
        MatrixVector2 GetPrevPos();
        char GetChar();
        RGB GetBg();
        RGB GetFg();
        bool IsNull();

        void SetPos(MatrixVector2 new_pos);
    
    private:
        MatrixVector2 pos;
        MatrixVector2 prev_pos;
        char c;
        RGB bg;
        RGB fg;

        bool is_null = false;
};