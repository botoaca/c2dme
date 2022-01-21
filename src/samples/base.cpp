#include "../include/Utility.h"
#include "../include/MatrixVector.h"
#include "../include/MapObject.h"
#include "../include/Map.h"
#include <conio.h>

#define KEY_UP      72
#define KEY_DOWN    80
#define KEY_LEFT    75
#define KEY_RIGHT   77
#define KEY_CTRL_C  3

#define Tree(x, y) MapObject{MatrixVector2{x, y}, 't', RGB{0, 92, 0}, RGB{0, 180, 0}}
#define Rock(x, y) MapObject{MatrixVector2{x, y}, 'r', RGB{80, 80, 80}, RGB{127, 127, 127}}

void draw_boundaries(Map& map)
{
    for (int i = 0; i < map.GetSize().x; i++)
        for (int j = 0; j < map.GetSize().y; j++)
            if (i == 0 || i == map.GetSize().x - 1 || j == 0 || j == map.GetSize().y - 1)
                map.AddObject(Tree(i, j));
}
void generate_rock_formation(Map& map, int x, int y, int size)
{
    if (size == 0)
        return;

    int half_size = size / 2;
    int half_size_x = x + half_size;
    int half_size_y = y + half_size;

    map.AddObject(Rock(x, y));
    map.AddObject(Rock(x + size, y));
    map.AddObject(Rock(x, y + size));
    map.AddObject(Rock(x + size, y + size));

    generate_rock_formation(map, x, y, half_size);
    generate_rock_formation(map, x + size, y, half_size);
    generate_rock_formation(map, x, y + size, half_size);
    generate_rock_formation(map, x + size, y + size, half_size);

    generate_rock_formation(map, half_size_x, half_size_y, half_size);
    generate_rock_formation(map, half_size_x, half_size_y, half_size);
    generate_rock_formation(map, half_size_x, half_size_y, half_size);
    generate_rock_formation(map, half_size_x, half_size_y, half_size);
}

int main()
{
    MatrixVector2 map_size = {20, 40};
    MatrixVector2 half_map_size = map_size / 2;
    Map map(map_size);
    MapObject player(MatrixVector2{10, 10}, '@', RGB{145, 68, 0}, RGB{235, 137, 52});
    map.AddObject(player);
    Logger logger;

    draw_boundaries(map);
    generate_rock_formation(map, 2, 2, 1);
    generate_rock_formation(map, 6, 21, 4);
    clear_screen();

    int frame = 0;
    bool movement_success = true;
    bool Quit = false;
    while (!Quit)
    {
        logger.Clear();
        
        map.Print();
        if (!movement_success)
        {
            player.SetPos(player.GetPrevPos());
            std::string m = "YOU CAN'T MOVE THERE";
            MatrixVector2 m_pos{(int)(half_map_size.y - m.size() / 2), half_map_size.x};
            std::string str =
                "\033[" + std::to_string(m_pos.y)
                + ";" + std::to_string(m_pos.x) + "H\033[48;2;255;0;0m\033[38;2;255;255;255m"
                + m + "\033[0;00m" + "\033[" + std::to_string(map_size.x + 1) + ";0H";
            std::cout << str;
        }

        MatrixVector2 dir;
        int __c = _getch();
        if (__c == KEY_CTRL_C) Quit = true;
        if (__c == 0 || __c == 224) 
        {
            switch (_getch()) 
            {
                case KEY_LEFT:  dir = {0, -1}; break;
                case KEY_UP:    dir = {-1, 0}; break;
                case KEY_RIGHT: dir = {0, 1}; break;
                case KEY_DOWN:  dir = {1, 0}; break;
            }
        }

        logger.AddLog("dir: " + dir.str());
        logger.AddLog("pos: " + player.GetPos().str());
        logger.AddLog("prev_pos: " + player.GetPrevPos().str());
        
        player.SetPos(player.GetPos() + dir);
        movement_success = map.UpdateObject(player);
        
        frame++;
        logger.AddLog("frame: " + std::to_string(frame));
        logger.Print();
    }

    clear_screen();
    return 0;
}