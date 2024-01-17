#if !defined(ENEMY_HELICOPTER)
#define ENEMY_HELICOPTER

#include<iostream>

class Enemy_Helicopter
{
    public :
    size_t hitPoint = 0; // each enemy has own hit point
    std::pair<int ,int> location = {0,0}; // location of helicopter 

    void Set_Hit_Point(int); // set the hit point
    void Set_Location(int ,int); // set the location
    size_t Get_Hit_Point() const; // get the hit point

};



#endif // ENEMY_HELICOPTER
