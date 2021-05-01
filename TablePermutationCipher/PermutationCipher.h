#pragma once
#include <string>
using namespace std;
class PermutationCipher
{
private:
    int key;
public:
    PermutationCipher() = delete;
    PermutationCipher(int k);
    wstring EncodePermutationCipher(PermutationCipher key, wstring &data);
    wstring DecodePermutationCipher(PermutationCipher key, wstring &data);
};
