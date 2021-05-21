/**
* @file ExceptionStroka.h
* @author Авдонин А.Д.
* @version 1.0
* @brief Описание класса ExceptionStroka
* @date 20.05.2021
* @copyright ИБСТ ПГУ
*/
#pragma once
#include "Exception.h"
///@brief Класс для исключений строки при шифрования или расшифрования
class ExceptionStroka : protected Exception
{
public:
    ///@brief Запрещающий конструктор без параметров
    ExceptionStroka() = delete;
    /**@brief Конструктор с параметрами
     * @param num - целочисленное число, хранящее информацию о коде ошибки.
     * @param error - строка, хранящая описание ошибки.
     * @param correction - строка, хранящая информацию об исправлении ошибки.
     */
    ExceptionStroka (const int &num,const string &error, const string& correction);
    
    string what () override;
    string fix () override;
    int code () override;
     /**@brief Статический метод, проверяющий строку при шифровании или расшифровании на наличие ошибки
     *@details Cтрока проверяются на пустату при помощи обычного условия. Если строка является пустой, то с помощью ключего слова
     * "throw" возбуждается исключение типа "ExceptionStroka".
     * @param data - std::string, строка, которую нужно проверить при шифровании или расшифровании.
     * @return значение "true", если проверка завершилась успешно.
     * @throw  ExceptionStroka, если строка, пришедшая на вход оказалось пустой.
     */
    static bool check_stroka (const string data);
};
