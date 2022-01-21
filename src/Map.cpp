#include "include/Map.h"

Map::Map()
{
    this->size = MatrixVector2{0, 0};
}
Map::Map(MatrixVector2 size)
{
    this->size = size;
    map.resize(size.x);
    for (int i = 0; i < size.x; i++)
        map.at(i).resize(size.y);
}

MatrixVector2 Map::GetSize() { return size; }

bool Map::AddObject(MapObject obj)
{
    if (obj.GetPos().x >= size.x || obj.GetPos().y >= size.y)
        return false;
    map.at(obj.GetPos().x).at(obj.GetPos().y) = obj;
    return true;
}

MapObject Map::GetObject(MatrixVector2 pos)
{
    if (pos.x >= size.x || pos.y >= size.y)
        return MapObject();
    return map.at(pos.x).at(pos.y);
}

bool Map::UpdateObject(MapObject obj)
{
    MatrixVector2 pos = obj.GetPos();
    MatrixVector2 prev_pos = obj.GetPrevPos();
    MapObject new_obj = obj;

    if (obj.IsNull())
        return false;

    if (pos.x >= size.x || pos.y >= size.y)
        return false;
    
    if (!GetObject(pos).IsNull())
        return false;

    RemoveObject(GetObject(prev_pos));
    AddObject(new_obj);
    return true;
}

bool Map::RemoveObject(MapObject obj)
{
    if (obj.GetPos().x >= size.x || obj.GetPos().y >= size.y)
        return false;
    map.at(obj.GetPos().x).at(obj.GetPos().y) = MapObject();
    return true;
}

void Map::Print()
{
    std::ostringstream buf;
    for (int i = 0; i < size.x; i++)
    {
        for (int j = 0; j < size.y; j++)
        {
            MapObject obj = map.at(i).at(j);
            RGB bg = obj.GetBg();
            RGB fg = obj.GetFg();
            char c = obj.GetChar();

            std::string str =
                "\033[48;2;"
                + std::to_string(bg.x) + ";" + std::to_string(bg.y) + ";" + std::to_string(bg.z)
                + "m\033[38;2;"
                + std::to_string(fg.x) + ";" + std::to_string(fg.y) + ";" + std::to_string(fg.z)
                + "m" + c
                + "\033[0;00m";
            
            buf << str;
        }
        buf << "\n";
    }
    std::cout << "\033[0;0H" << buf.str();
}