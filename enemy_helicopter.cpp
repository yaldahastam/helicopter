#include"../include/enemy_helicopter.hpp"

using namespace std;

void Enemy_Helicopter :: Set_Hit_Point(int point)
{
    hitPoint = point;
}


size_t Enemy_Helicopter :: Get_Hit_Point() const
{
    return hitPoint;
}


void Enemy_Helicopter :: Set_Location(int x, int y)
{
    location.first = x;
    location.second = y;
}