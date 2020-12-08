#pragma once
#include "Role.hpp"
#include <iostream>
using namespace std;


class User
{
public:
    int Id;
    string Fname;
    string Lname;
    string userName;
    Role Role;
    
    //No values in function will be changed
    bool operator == (const User &user) const
    {
        // check If username and user input in  matches 
        if(userName.compare(user.userName) == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

};

