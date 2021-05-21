/**
* @file Exception.h
* @author Авдонин А.Д.
* @version 1.0
* @brief Описание абстрактного класса Exception
* @date 20.05.2021
* @copyright ИБСТ ПГУ
*/
#pragma once
#include <string>
#include <iostream>
using namespace std;
///@brief Абстрактный класс для иcключений
class Exception
{
protected:
    string error;  ///< @brief атрибут, хранящий описание ошибки
    int num;    ///< @brief атрибут, хранящий информацию о коде ошибки
    string correction;  ///< @brief атрибут, хранящий информацию об исправлении ошибки
public:
    ///@brief Предназначен для вывода описания ошибки.
    virtual string what () = 0;
    ///@brief Чисто виртуальный метод. Предназначен для вывода кода ошибки. 
    virtual int code () = 0;
    ///@brief Чисто виртуальный метод. Предназначен для вывода информации об исправлении ошибки.
    virtual string fix () = 0;
};


