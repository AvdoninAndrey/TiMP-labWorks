#pragma once
#include <stdexcept>
#include <string>
using namespace std;
class MyExceptions : public invalid_argument
{
private:
    int num;
    string correction;
public:
    MyExceptions (const string & error, const int &num, const string &fix);
    string fix ();
    int code ();
};
