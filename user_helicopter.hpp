#if !defined(USER_HELICOPTER)
#define USER_HELICOPTER

#include<iostream>

class User_Helicopter
{
    public :
    std::pair<int, int> location = {0, 0};
    size_t point = 0;
    int heal = 3;

    void Set_Location(int, int);
    void Add_Point(int);
    size_t Get_Point()const;
};



#endif // USER_HELICOPTER
