/**
* @file Help.h
* @author Авдонин А.Д.
* @version 1.0
* @brief Описание класса Help
* @date 20.05.2021
* @copyright ИБСТ ПГУ
*/
#pragma once
#include <string>
#include <iostream>
using namespace std;
///@brief Справка о режимах работы программы
class Help
{
private:
    ///@brief атрибут, хранящий справку о режимах работы программы
    const string help = "Справка о работе программы:\n Encode - режим шифрования шифром табличной маршрутной перестановки.\n Decode - режим расшифрования шифра табличной маршрутной перестановки.\n exit - завершить работу программы.\n";
public:
///@brief Выводит справку о режимах работы программы, если она понадобится пользователю.
    void PrintHelp ();

};
