#include "ExceptionStroka.h"

ExceptionStroka::ExceptionStroka (const int &num,const string &error, const string& correction)
{
    this->num = num;
    this->error = error;
    this->correction=correction;

}
string ExceptionStroka::what ()
{
    return "Описание ошибки: " + error;
}
int ExceptionStroka::code ()
{
    return num;
}
string ExceptionStroka::fix ()
{
    return correction;
}

bool ExceptionStroka::check_stroka ( const string data )
{
    
    try {
        if (data.empty()) 
            throw ExceptionStroka (1, "вы ввели пустую строку.", "При вводе используйте любые символы.");
        return true;
    }
    catch (ExceptionStroka &ex) {
        cout << "Код ошибки:" << ex.code()<< endl;
        cout<<ex.what()<<endl;
        cout<<ex.fix()<<endl;
        return false;
    }
}
