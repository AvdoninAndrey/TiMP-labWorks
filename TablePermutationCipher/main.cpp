#include "PermutationCipher.h"
#include "ExceptionKey.h"
#include "ExceptionStroka.h"
#include "Help.h"
#include <locale>
#include <codecvt>
int main()
{

    bool isTrue = true;
    string mode,NeMode,str,str_key;
    cout << "Добро пожаловать в программу, которая реализует шифр табличной маршрутной перестановки." << endl;
    cout << "Чтобы завершить работу программу, введите \"exit\"." << endl;
    do {
        locale loc("ru_RU.UTF-8");
        locale::global(loc);
        cout << "Укажите режим работы:";
        getline(cin,mode);
        if (mode == "Encode") {
            cout << "Введите строку для шифрования:";
            getline(cin, str);
            try {
                ExceptionStroka::check_stroka(str);
                cout << "Введите ключ:";
                getline(cin, str_key);
                wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
                wstring wstren = codec.from_bytes(str);
                ExceptionKey::check_key(wstren, str_key);
                int key = stoi(str_key);
                PermutationCipher encode(key);
                cout<<codec.to_bytes(encode.EncodePermutationCipher(encode,wstren))<<endl;
            } catch(ExceptionKey & exKey) {
                cout << "Код ошибки:" << exKey.code()<< endl;
                cout<<exKey.what()<<endl;
                cout<<exKey.fix()<<endl;
            } catch(ExceptionStroka & exStr) {
                cout << "Код ошибки:" << exStr.code()<< endl;
                cout<<exStr.what()<<endl;
                cout<<exStr.fix()<<endl;
            }
        }

        if (mode == "Decode") {
            cout << "Введите строку для расшифрования:";
            getline(cin, str);
            try {
                ExceptionStroka::check_stroka(str);
                cout << "Введите ключ:";
                getline(cin, str_key);
                wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
                wstring wstren = codec.from_bytes(str);
                ExceptionKey::check_key(wstren, str_key);
                int key = stoi(str_key);
                PermutationCipher encode(key);
                cout<<codec.to_bytes(encode.EncodePermutationCipher(encode,wstren))<<endl;
            } catch(ExceptionKey & exKey) {
                cout << "Код ошибки:" << exKey.code()<< endl;
                cout<<exKey.what()<<endl;
                cout<<exKey.fix()<<endl;
            } catch(ExceptionStroka & exStr) {
                cout << "Код ошибки:" << exStr.code()<< endl;
                cout<<exStr.what()<<endl;
                cout<<exStr.fix()<<endl;
            }
        }
        if (mode == "exit") {
            cout << "Программа завершила работу." << endl;
            isTrue = false;
            break;
        }
        if ((mode != "Encode" && mode != "Decode" && mode != "exit")) {
            cout << "Чтобы воспользоваться справкой, введите \"help\"." << endl;
            cout << "Иначе введите любую текстовую последовательность символов, чтобы продолжить.\n";
            getline(cin,NeMode);
            if (NeMode == "help") {
                Help help;
                help.PrintHelp();
            }
        }

    } while (isTrue != false);
    return 0;
}
