#include "PermutationCipher.h"
#include "ExceptionKey.h"
#include "Help.h"
#include <locale>
#include <codecvt>
int main()
{
    bool isTrue = true;
    string mode,NeMode,str;
    cout << "Добро пожаловать в программу, которая реализует шифр табличной маршрутной перестановки." << endl;
    cout << "Чтобы завершить работу программу, введите \"exit\"." << endl;
    do {
        locale loc("ru_RU.UTF-8");
        locale::global(loc);
        cout << "Укажите режим работы:";
        cin >> mode;
        if (mode == "Encode") {
            cout << "Введите строку для шифрования:";
            cin.get();
            getline(cin, str);
            int key;
            cout << "Введите ключ:";
            cin >> key;

            PermutationCipher encode(key);
            wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
            wstring wstren = codec.from_bytes(str);
            if (ExceptionKey::check_key(wstren, key)) {
                cout<<codec.to_bytes(encode.EncodePermutationCipher(encode,wstren))<<endl;
            }
        }
        if (mode == "Decode") {
            cout << "Введите строку для расшифрования:";
            cin.get();
            getline(cin, str);
            int key;
            cout << "Введите ключ:";
            cin >> key;
            PermutationCipher decode(key);
            wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
            wstring wstrdec = codec.from_bytes(str);
            if (ExceptionKey::check_key(wstrdec, key)) {
                cout<<codec.to_bytes(decode.DecodePermutationCipher(decode,wstrdec))<<endl;
            }
        }
        if (mode == "exit") {
            cout << "Программа завершила работу." << endl;
            isTrue = false;
            break;
        }
        if (mode != "Encode" && mode != "Decode" && mode != "exit") {
            cout << "Чтобы воспользоваться справкой, введите \"help\"." << endl;
            cout << "Иначе введите любую текстовую последовательность символов, чтобы продолжить.\n";
            cin >> NeMode;
            if (NeMode == "help") {
                Help help;
                help.PrintHelp();
            }

        }

    } while (isTrue != false);
    return 0;
}
