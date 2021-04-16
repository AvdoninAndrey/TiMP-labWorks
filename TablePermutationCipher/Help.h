#pragma once
#include <string>
#include <iostream>
using namespace std;
class Help
{
private:
    const string help = "Справка о работе программы:\n"
                  " Encode - режим шифрования шифром табличной маршрутной перестановки.\n"
                  " Decode - режим расшифрования шифра табличной маршрутной перестановки.\n"
                  " exit - завершить работу программы.\n";
public:
    void PrintHelp ();

};
