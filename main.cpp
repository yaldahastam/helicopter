#include"include/map.hpp"

using namespace std;

int main()
{
    Map map ;
    
    ifstream inFile("out.txt");

    if (inFile.is_open())
    {
        int user ;
        for (size_t i = 0; i < 4; i++)
        {
            inFile >> user;

            switch (i)
            {
                case 0:
                {
                    map.user_heli.location.first = user;
                    break;
                }
            
                case 1:
                {
                    map.user_heli.location.second = user;
                    break;
                }

                case 2:
                {
                    map.user_heli.heal = user;
                    break;
                }

                case 3:
                {
                    map.user_heli.point = user;
                    break;
                }
            }      
        }

        int size ;
        inFile >> size ;
        cout << size << endl;

        for (size_t i = 0; i < size ; i++)
        {
            int first ,second ,hit;
            inFile >> first >> second >> hit;
            Enemy_Helicopter temp ;
            temp.location.first = first ; temp.location.second = second;
            temp.hitPoint = hit;
            map.enemy_heli.push_back(temp);
        }
        
        char ch;

        for (size_t i = 0; i < SIZE; i++)
        {
            for (size_t j = 0; j < SIZE ; j++)
            {
                inFile >> ch;
                map.array[i][j] = ch;
            }
        }

        map.load_file = true;
    }

    map.Run();

    return 0;
}