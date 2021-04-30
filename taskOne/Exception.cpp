#include "Exception.h"

MyExceptions::MyExceptions(const string & error, const int &num, const string &fix) : invalid_argument(error)
{
    this->num = num;
    this->correction = fix;
}
int  MyExceptions::code()
{
    return num;
}
string MyExceptions::fix() {
    return correction;
    }