#if !defined(MAP)
#define MAP

#include"enemy_helicopter.hpp"
#include"user_helicopter.hpp"
#include<vector>
#include<ctime>
#include<random>
#include<fstream>

#define SIZE 10

// int time_start = time(nullptr);

class Map
{
    public :
    char array[SIZE][SIZE]{0}; // array of char for use in map
    User_Helicopter user_heli; // user helicopter information
    std::vector<Enemy_Helicopter> enemy_heli; // enemies helicopter information
    bool game_over = false; // game over
    bool load_file = false; // load from file

    void Create_User_Helicopter(); // create a user helicopter
    void Create_Enemy_Helicopter(); // create a enemy
    void Print() const; // print the map
    void Run(); // run the game
    bool Is_Game_Over() const; // check game over
    void Move_User(); // user can move up ,down ,left ,right
    void Move_Enemy(); // enemy just can move to left

    void Move_Right(); // move user right
    void Move_Left(); // move user left
    void Move_Up(); // move user up
    void Move_Down(); // move user down

    void Is_Damage_Taken(); // if enemy damaged we detect and remove enemy
    void Is_Out_Of_Range(); // if enemy reach to beginning of map , heal of user decrease 

    void Shot(); // if user move , helicopter shot to right
    void Move_Shot(); // move shot char '-' in the map
};


#endif // MAP
