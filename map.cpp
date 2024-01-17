#include"../include/map.hpp"

using namespace std;

void Map :: Create_User_Helicopter() // create a user helicopter in map
{
    default_random_engine eng(time(nullptr)); // for use in random engine
    std::uniform_int_distribution<unsigned> uni1(0 , SIZE - 1); // for use in random engine
    std::uniform_int_distribution<unsigned> uni2(0 , SIZE / 2 - 1); // for use in random engine

    user_heli.location.first = uni1(eng); // generate random location (row)
    user_heli.location.second = uni2(eng); // generate random location (column)

    array[user_heli.location.first][user_heli.location.second] = 'u'; // mark location as user 'u
}


void Map :: Create_Enemy_Helicopter() // create a enemy helicopter in map
{
    default_random_engine eng(time(nullptr)); // for use in random engine 
    std::uniform_int_distribution<unsigned> uni(0 , SIZE - 1); // for use in random engine

    if (enemy_heli.size() > SIZE / 2) // count of enemy helicopter must be under half of size
        return ;

    Enemy_Helicopter temp ; // instance of enemy
    std::uniform_int_distribution<unsigned> point_uni(1 ,10); // for use in random engine

    do // validate enemy location
    {
        temp.location.first = uni(eng);
        temp.location.second = SIZE - 1;

        if (array[temp.location.first][temp.location.second] == 0)
            break;

    } while (true);

    temp.Set_Hit_Point(point_uni(eng) * 10);
    enemy_heli.push_back(temp); // push to vector of enemy
    array[temp.location.first][temp.location.second] = 'e'; // mark enemy in map
}


void Map :: Print() const // print map
{
    for (size_t i = 0; i <= SIZE; i++)
    {
        for (size_t k = 0; k < 3 * SIZE + 11; k++)
            cout << "-" ;
        cout << endl;

        for (size_t j = 0; j < SIZE && i != SIZE; j++)
        {
            cout << (j == 0 ? "| " : " ");
            cout << (array[i][j] == 0 ? ' ' : array[i][j]) << " |";
        }
        cout << endl;
    }
}


bool Map :: Is_Game_Over() const // check if game over or not
{
    if (user_heli.heal <= 0)
        return true;

    return false;
}


void Map :: Move_Enemy() // enemies only can move left
{
    for (size_t i = 0; i < enemy_heli.size() ; i++)
    {
        if (array[0][i] == 'e')
            user_heli.heal--;

        if (array[enemy_heli[i].location.first][enemy_heli[i].location.second - 1] == 'u')
        {
            user_heli.heal--;
            array[enemy_heli[i].location.first][enemy_heli[i].location.second] = 0;
        }

        if (array[enemy_heli[i].location.first][enemy_heli[i].location.second - 1] == 0
            && enemy_heli[i].location.second - 1 >= 0)
        {
            array[enemy_heli[i].location.first][enemy_heli[i].location.second] = 0;
            enemy_heli[i].location.second--;
            array[enemy_heli[i].location.first][enemy_heli[i].location.second] = 'e';
        }
    }
}


void Map :: Move_Right() // user helicopter can move right
{
    if (user_heli.location.second + 1 < SIZE && array[user_heli.location.first][user_heli.location.second + 1] == 0)
    {
        array[user_heli.location.first][user_heli.location.second] = 0;
        user_heli.location.second++;
        array[user_heli.location.first][user_heli.location.second] = 'u';
    }
}

void Map :: Move_Left() // user helicopter can move left
{
    if (user_heli.location.second - 1 >= 0 && array[user_heli.location.first][user_heli.location.second - 1] == 0)
    {
        array[user_heli.location.first][user_heli.location.second] = 0;
        user_heli.location.second--;
        array[user_heli.location.first][user_heli.location.second] = 'u';
    }
}


void Map :: Move_Up() // user helicopter can move up
{
    if (user_heli.location.first - 1 >= 0 && array[user_heli.location.first - 1][user_heli.location.second] == 0)
    {
        array[user_heli.location.first][user_heli.location.second] = 0;
        user_heli.location.first--;
        array[user_heli.location.first][user_heli.location.second] = 'u';
    }
}


void Map :: Move_Down() // user helicopter can move down
{
    if (user_heli.location.first + 1 < SIZE && array[user_heli.location.first + 1][user_heli.location.second] == 0)
    {
        array[user_heli.location.first][user_heli.location.second] = 0;
        user_heli.location.first++;
        array[user_heli.location.first][user_heli.location.second] = 'u';
    }
}


void Map :: Move_User() // 4 direction management
{
    cout << "w : up , s : down , a : left , d : right (q : quit)" << endl;
    cout << "Enter Move Char : ";
    char ch;
    cin >> ch; // receive char from user
    cin.get();

    switch (ch)
    {
        case 'w':
        case 'W':
        {
            Move_Up();
            break;
        }
    
        case 's':
        case 'S':
        {
            Move_Down();
            break;
        }

        case 'a':
        case 'A':
        {
            Move_Left();
            break;
        }

        case 'd':
        case 'D':
        {
            Move_Right();
            break;
        }

        case 'q':
        case 'Q':
        {
            ofstream outFile("out.txt");

            if (!outFile.is_open())
            {
                cerr << "Error: Unable to open file for writing." << std::endl;
                exit(EXIT_FAILURE);
            }

            outFile << user_heli.location.first << ' ' ;
            outFile << user_heli.location.second << ' ' << user_heli.heal << ' ' << user_heli.point << endl;

            outFile << enemy_heli.size() << endl;

            for (size_t i = 0; i < enemy_heli.size() ; i++)
            {
                outFile << enemy_heli[i].location.first << ' ' ;
                outFile << enemy_heli[i].location.second << ' ' << enemy_heli[i].hitPoint << endl;
            }

            for (size_t i = 0; i < SIZE; i++)
            {
                for (size_t j = 0; j < SIZE ; j++)
                {
                    outFile << array[i][j] << ' ';
                }
                outFile << endl;
            }
            
            exit(EXIT_SUCCESS);
        }

        default:
        {
            cerr << "You Entered Invalid Character !!!" << endl;
            break;
        }
    }
}


void Map :: Is_Damage_Taken() // if enemy damaged . we detect that in this function and update map
{
    vector <Enemy_Helicopter> temp;

    for (size_t i = 0; i < enemy_heli.size() ; i++)
    {
        if (array[enemy_heli[i].location.first][enemy_heli[i].location.second - 1] == '-')
        {
                array[enemy_heli[i].location.first][enemy_heli[i].location.second - 1] = 0; // clear position in map
                array[enemy_heli[i].location.first][enemy_heli[i].location.second] = 0; // clear position in map
                user_heli.Add_Point(enemy_heli[i].Get_Hit_Point());
        }

        else
            temp.push_back(enemy_heli[i]);
    }

    enemy_heli = temp;
}


void Map :: Is_Out_Of_Range()
{
    vector <Enemy_Helicopter> temp ;

    for (size_t i = 0; i < enemy_heli.size() ; i++)
    {
        if (enemy_heli[i].location.second - 1 == 0)
        {
            user_heli.heal--;
            array[enemy_heli[i].location.first][enemy_heli[i].location.second] = 0;
            game_over = Is_Game_Over() ;

            if (game_over == true)
                return ;

            continue;
        }

        temp.push_back(enemy_heli[i]);   
    }

    enemy_heli = temp ;
}


void Map :: Run()
{
    if (load_file == false)
    {
        Create_User_Helicopter();

        for (size_t i = 0; i < SIZE / 2 - 1; i++)
            Create_Enemy_Helicopter();
    }

    while (!game_over)
    {
        system("cls");
        cout << "Health: " << user_heli.heal << endl;
        cout << "Point : " << user_heli.point << endl;
        Shot();
        Print();
        Move_User();
        system("cls");
        cout << "Health: " << user_heli.heal << endl;
        cout << "Point : " << user_heli.point << endl;
        Print();
        Move_Enemy();
        system("cls");
        cout << "Health: " << user_heli.heal << endl;
        cout << "Point : " << user_heli.point << endl;
        Print();
        Move_Shot();
        system("cls");
        cout << "Health: " << user_heli.heal << endl;
        cout << "Point : " << user_heli.point << endl;
        Print();
        system("cls");
        cout << "Health: " << user_heli.heal << endl;
        cout << "Point : " << user_heli.point << endl;
        Is_Out_Of_Range();

        if (enemy_heli.size() == 0)
            for (size_t i = 0; i < SIZE / 2 - 1; i++)
                Create_Enemy_Helicopter();
    }   
    
}



void Map :: Shot()
{
    if (array[user_heli.location.first][user_heli.location.second + 1] == 0)
    {
        array[user_heli.location.first][user_heli.location.second + 1] = '-';
    }

    if (array[user_heli.location.first][user_heli.location.second + 1] == 'e')
    {
        array[user_heli.location.first][user_heli.location.second] = '-';
        Is_Damage_Taken();
        array[user_heli.location.first][user_heli.location.second] = 'u';
    }
}



void Map :: Move_Shot()
{
    for (size_t i = 0; i < SIZE; i++)
    {
        for (int j = SIZE - 1 ; j >= 0 ; j--)
        {
            if (array[i][j] == '-')
            {
                if (j == SIZE - 1)
                    array[i][j] = 0;
                

                else if (array[i][j + 1] == 0)
                {
                    array[i][j] = 0;
                    array[i][j + 1] = '-';
                }

                else if (array[i][j + 1] == 'e')
                {
                    Is_Damage_Taken();
                }
            }
        }
    }
}
