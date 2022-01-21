#include "../include/Utility.h"
#include "../include/MatrixVector.h"
#include "../include/MapObject.h"
#include "../include/Map.h"
#include <conio.h>

#define KEY_UP      72
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

int main()
{
    MatrixVector2 map_size = {20, 40};
    MatrixVector2 half_map_size = map_size / 2;
    Map map(map_size);
    MapObject player(MatrixVector2{map.GetSize().x - 2, 10}, '@', RGB{145, 68, 0}, RGB{235, 137, 52});
    map.AddObject(player);
    Logger logger;

    draw_boundaries(map);
    
    map.AddObject(Rock(map_size.x - 2, 20));
    map.AddObject(Rock(map_size.x - 3, 20));
    map.AddObject(Rock(map_size.x - 4, 20));

    map.AddObject(Rock(map_size.x - 2, 18));
    map.AddObject(Rock(map_size.x - 3, 18));

    clear_screen();

    int frame = 0;
    bool movement_success = true;
    bool Quit = false;

    int jump_frames = 0;
    bool can_jump = true;
    bool is_jumping = false;

    MatrixVector2 down = {1, 0};
    MatrixVector2 up = {-1, 0};

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

        if (!map.GetObject(player.GetPos() + down).IsNull() && !is_jumping)
        {
            jump_frames = 0;
            can_jump = true;
        }

        if (is_jumping && jump_frames < 3)
        {
            jump_frames++;
            player.SetPos(player.GetPos() + up);
            movement_success = map.UpdateObject(player);
            continue;
        }
        else
        {
            jump_frames = 0;
            is_jumping = false;
        }

        MatrixVector2 dir;
        int __c = _getch();
        if (__c == KEY_CTRL_C) Quit = true;
        if (__c == 0 || __c == 224) 
        {
            switch (_getch()) 
            {
                case KEY_LEFT:  dir = {0, -1}; break;
                case KEY_UP:    { if (can_jump) { is_jumping = true; can_jump = false; } break; } 
                case KEY_RIGHT: dir = {0, 1}; break;
                default: break;
            }
        }

        logger.AddLog("dir: " + dir.str());
        logger.AddLog("pos: " + player.GetPos().str());
        logger.AddLog("prev_pos: " + player.GetPrevPos().str());

        if (map.GetObject(player.GetPos() + down).IsNull() && !is_jumping)
        {
            player.SetPos(player.GetPos() + down);
            if (!map.GetObject(player.GetPos() + down).IsNull())
            {
                can_jump = true;
            }   
        }
        
        movement_success = map.UpdateObject(player);
        player.SetPos(player.GetPos() + dir);
        movement_success = map.UpdateObject(player);
        
        frame++;
        logger.AddLog("frame: " + std::to_string(frame));
        logger.Print();
    }

    clear_screen();
    return 0;
}