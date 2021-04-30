#include <iostream>
#include "modAlphaCipher.h"
#include "Exception.h"
#include <codecvt>
using namespace std;

int main ()
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    bool isTrue = true;
    wstring mode,NeMode,wstr,wstr_key;
    cout << "Добро пожаловать в программу!" << endl;
    cout << "Cправка о работе программы:" << endl;
    cout << "Encode - режим шифрования шифром  русскоязычных сообщений методом Гронсвельда.\n";
    cout << "Decode - режим расшифрования шифра  русскоязычных сообщений методом Гронсвельда.\n";
    cout << "Примечание - зашифрованная или расшифровання строка всегда будет состоять из прописных букв русского алфавита.\n";
    cout << "exit - завершить работу программы.\n";
    do {
        cout << "Укажите режим работы:";
        wcin >> mode;
        if (mode == L"Encode") {
            cout << "Введите строку для шифрования:";
            wcin.get();
            getline(wcin,wstr);
            cout << "Введите ключ:";
            getline(wcin,wstr_key);
            try {
                modAlphaCipher cipher(wstr_key);
                wstring cipherText = cipher.encrypt(wstr);
                wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
                cout<<codec.to_bytes(cipherText)<<endl;
            } catch (MyExceptions & ex) {
                cout << "Код ошибки: "<<ex.code() << endl;
                cout << "Описание ошибки: "<<ex.what() << endl;
                cout << ex.fix() << endl;
            }
        }
        if (mode == L"Decode") {
            cout << "Введите строку для расшифрования:";
            wcin.get();
            getline(wcin,wstr);
            cout << "Введите ключ:";
            getline(wcin,wstr_key);
            try {
                modAlphaCipher cipher(wstr_key);
                wstring OpenText = cipher.decrypt(wstr);
                wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
                cout<<codec.to_bytes(OpenText)<<endl;
            } catch (MyExceptions & ex) {
                cout << "Код ошибки: "<<ex.code() << endl;
                cout << "Описание ошибки: "<<ex.what() << endl;
                cout << ex.fix() << endl;
            }
        }
        if (mode == L"exit") {
            cout << "Программа завершила работу." << endl;
            isTrue = false;
            break;
        }
        if ((mode != L"Encode" && mode != L"Decode" && mode != L"exit")) {
            cout << "Cправка о работе программы:" << endl;
            cout << "Encode - режим шифрования шифром  русскоязычных сообщений методом Гронсвельда.\n";
            cout << "Decode - режим расшифрования шифра  русскоязычных сообщений методом Гронсвельда.\n";
            cout << "Примечание - зашифрованная или расшифровання строка всегда будет состоять из прописных букв русского алфавита.\n";
            cout << "exit - завершить работу программы.\n";
        }

    } while (isTrue != false);
    return 0;

}
