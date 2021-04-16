#pragma once
#include "Exception.h"
class ExceptionKey : protected Exception
{
public:
ExceptionKey (const int &num,const string &error, const string& correction);
void what ();
static bool check_key (const wstring &data, const int &key);
};
