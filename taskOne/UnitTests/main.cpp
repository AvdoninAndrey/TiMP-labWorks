#include <UnitTest++/UnitTest++.h>
#include "/home/student/TiMP/Lab1/1z/modAlphaCipher.h"
#include "/home/student/TiMP/Lab1/1z/modAlphaCipher.cpp"
#include "/home/student/TiMP/Lab1/1z/Exception.h"
#include "/home/student/TiMP/Lab1/1z/Exception.cpp"

SUITE(KeyTest) // тесты для ключа
{
    TEST(Small_Russian_letters) {
        modAlphaCipher test(L"русскиемаленькие");
        CHECK(true);
    }
    TEST(Uppercase_Russian_letters) {
        modAlphaCipher test(L"БОЛЬШИЕБУКВЫ");
        CHECK(true);
    }
    TEST(Uppercase_and_written_Russian_letters) {
        modAlphaCipher test(L"БОЛмал");
        CHECK(true);
    }

    TEST(Empty_Key) {
        CHECK_THROW(modAlphaCipher test(L""), MyExceptions);
    }
    TEST(Key_with_a_space) {
        CHECK_THROW(modAlphaCipher test(L"р язык"), MyExceptions);
    }
    TEST(Key_with_invalid_characters_number) {
        CHECK_THROW(modAlphaCipher test(L"русс1кие"),MyExceptions);
    }
    TEST(Key_with_invalid_characters_special_character) {
        CHECK_THROW(modAlphaCipher test(L"УРА;"),MyExceptions);
    }
}

struct KeyAB_fixture { // Для тестов шифрования и расшифрования
    modAlphaCipher * pointer;
    KeyAB_fixture()
    {
        pointer = new modAlphaCipher(L"АВ");
    }
    ~KeyAB_fixture()
    {
        delete pointer;
    }
};

SUITE(EncryptTest) // Шифрование
{
    TEST_FIXTURE(KeyAB_fixture, Uppercase_Russian_letters) {
        wstring open_text = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
        wstring result_correct = L"АГВЕДЖЁИЗКЙМЛОНРПТСФУЦХШЧЪЩЬЫЮЭАЯ";
        CHECK_EQUAL(true, result_correct == pointer->encrypt(open_text));
    }
    TEST_FIXTURE(KeyAB_fixture, Small_russian_letters) {
        wstring open_text = L"абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
        wstring result_correct = L"АГВЕДЖЁИЗКЙМЛОНРПТСФУЦХШЧЪЩЬЫЮЭАЯ";
        CHECK_EQUAL(true, result_correct == pointer->encrypt(open_text));
    }
    TEST_FIXTURE(KeyAB_fixture, Uppercase_and_Lowercase_Russian_Letters) {
        wstring open_text = L"УраДЕЛАЕМлабу";
        wstring result_correct = L"УТАЁЕНАЖМНАГУ";
        CHECK_EQUAL(true, result_correct == pointer->encrypt(open_text));
    }

    TEST_FIXTURE(KeyAB_fixture, Empty_Text) {
        wstring open_text = L"";
        CHECK_THROW(pointer->encrypt(open_text),MyExceptions);
    }
    TEST_FIXTURE(KeyAB_fixture,Text_with_invalid_characters_numbers ) {
        wstring open_text = L"УРА12УРА";
        CHECK_THROW(pointer->encrypt(open_text),MyExceptions);
    }
    TEST_FIXTURE(KeyAB_fixture,Text_with_invalid_characters_special_character ) {
        wstring open_text = L"УРА|УРА";
        CHECK_THROW(pointer->encrypt(open_text),MyExceptions);
    }
    TEST_FIXTURE(KeyAB_fixture,Text_with_a_space ) {
        wstring open_text = L"УРА УРА";
        CHECK_THROW(pointer->encrypt(open_text),MyExceptions);
    }
    TEST(OtherKey) {
        wstring open_text = L"ПРИВетМИР";
        wstring result_correct = L"ОПЗБДСЛЗП";
        modAlphaCipher test(L"Я");
        CHECK_EQUAL(true, result_correct ==  test.encrypt(open_text));
    }

}
SUITE(DecryptTest) // расшифрование
{
   TEST_FIXTURE(KeyAB_fixture, Uppercase_Russian_letters) {
        wstring cipher_text = L"АГВЕДЖЁИЗКЙМЛОНРПТСФУЦХШЧЪЩЬЫЮЭАЯ";
        wstring result_correct = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
        CHECK_EQUAL(true, result_correct == pointer->decrypt(cipher_text));
    }
    TEST_FIXTURE(KeyAB_fixture, Small_russian_letters) {
        wstring cipher_text = L"агведжёизкймлонрптсфуцхшчъщьыюэая";
        wstring result_correct = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
        CHECK_EQUAL(true, result_correct == pointer->decrypt(cipher_text));
    }
    TEST_FIXTURE(KeyAB_fixture, Uppercase_and_Lowercase_Russian_Letters) {
        wstring cipher_text = L"УТаёенаЖМНАГУ";
        wstring result_correct = L"УРАДЕЛАЕМЛАБУ";
        CHECK_EQUAL(true, result_correct == pointer->decrypt(cipher_text));
    }

    TEST_FIXTURE(KeyAB_fixture, Empty_Text) {
        wstring cipher_text = L"";
        CHECK_THROW(pointer->decrypt(cipher_text),MyExceptions);
    }
    TEST_FIXTURE(KeyAB_fixture,Text_with_invalid_characters_number ) {
        wstring cipher_text = L"УРА12УРА";
        CHECK_THROW(pointer->decrypt(cipher_text),MyExceptions);
    }
    TEST_FIXTURE(KeyAB_fixture,Text_with_invalid_characters_special_character ) {
        wstring cipher_text = L"УРА*УРА";
        CHECK_THROW(pointer->decrypt(cipher_text),MyExceptions);
    }
    TEST_FIXTURE(KeyAB_fixture,Text_with_a_space ) {
        wstring cipher_text = L"ПРОБЕЛ УРА";
        CHECK_THROW(pointer->decrypt(cipher_text),MyExceptions);
    }
    TEST(OtherKey) {
        wstring cipher_text = L"ОПЗБдсЛЗП";
        wstring result_correct = L"ПРИВЕТМИР";
        modAlphaCipher test(L"Я");
        CHECK_EQUAL(true, result_correct ==  test.decrypt(cipher_text));
    } 
}
int main()
{
    return UnitTest::RunAllTests();
}
