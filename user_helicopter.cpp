#include"../include/user_helicopter.hpp"

using namespace std;

void User_Helicopter ::Set_Location(int x, int y)
{
    location.first = x;
    location.second = y;
}

void User_Helicopter ::Add_Point(int point)
{
    this->point += point;
}

size_t User_Helicopter :: Get_Point() const
{
    return point ;
}