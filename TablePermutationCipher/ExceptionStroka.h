#pragma once
#include "Exception.h"
class ExceptionStroka : protected Exception
{
public:
    ExceptionStroka() = delete;
    ExceptionStroka (const int &num,const string &error, const string& correction);
    string what () override;
    string fix () override;
    int code () override;
    static bool check_stroka (const string data);
};
