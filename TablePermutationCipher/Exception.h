#pragma once
#include <string>
#include <iostream>
using namespace std;
class Exception
{
protected:
    string error;
    int num;
    string correction;
public:
    virtual void what () = 0;
};


