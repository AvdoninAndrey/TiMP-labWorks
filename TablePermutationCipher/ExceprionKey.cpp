#include "ExceptionKey.h"

ExceptionKey::ExceptionKey (const int &num,const string &error, const string& correction)
{
    this->num = num;
    this->error = error;
    this->correction=correction;
    
}
void ExceptionKey::what ()
{
    cout << "Код ошибки: " << num <<endl << "Описание ошибки: " << error <<endl<< correction<< endl;
}

bool ExceptionKey::check_key ( const wstring &data,const int &key)
{
    try {
        const int dlinastroki = data.size();
        if (key > dlinastroki-1) {
            throw ExceptionKey(1,"некорректный ключ.","Ключ должен быть целым положительным числом и не превашать размера строки.");
        }
        return true;
    }

    catch (ExceptionKey &ex) {
        ex.what();
        return false;
    }
}
