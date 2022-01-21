#include "include/MapObject.h"

MapObject::MapObject()
{
    this->pos = MatrixVector2{0, 0};
    this->prev_pos = MatrixVector2{0, 0};
    this->c = ' ';
    this->bg = RGB{0, 0, 0};
    this->fg = RGB{0, 0, 0};
    this->is_null = true;
}
MapObject::MapObject(MatrixVector2 pos, char c, RGB bg, RGB fg)
{
    this->pos = pos;
    this->prev_pos = pos;
    this->c = c;
    this->bg = bg;
    this->fg = fg;
    this->is_null = false;
}

MatrixVector2 MapObject::GetPos()      { return pos; }
MatrixVector2 MapObject::GetPrevPos()  { return prev_pos; }
char MapObject::GetChar()              { return c; }
RGB MapObject::GetBg()                 { return bg; }
RGB MapObject::GetFg()                 { return fg; }
bool MapObject::IsNull()               { return is_null; }

void MapObject::SetPos(MatrixVector2 new_pos)
{
    prev_pos = pos;
    pos = new_pos;
}