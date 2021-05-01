#pragma once
#include <UnitTest++/UnitTest++.h>
#include "/home/student/TiMP/Lab1/2z/PermutationCipher.h"
#include "/home/student/TiMP/Lab1/2z/PermutationCipher.cpp"

SUITE(EncodeTest)
{
    const int key = 3;
    PermutationCipher test(key);
    TEST(Uppercase_Russian_letters) {
        wstring open_text = L"ПРИВЕТМИР";
        wstring result_correct = L"ПВМРЕИИТР";
        CHECK_EQUAL(true, result_correct == test.EncodePermutationCipher(test,open_text));
    }
     TEST(Lowercase_Russian_letters) {
        wstring open_text = L"приветмир";
        wstring result_correct = L"пвмреиитр";
        CHECK_EQUAL(true, result_correct == test.EncodePermutationCipher(test,open_text));
    }
    TEST(Uppercase_English_letters) {
        wstring open_text = L"HELLOWORLD";
        wstring result_correct = L"HLODEOR LWL";
        CHECK_EQUAL(true, result_correct == test.EncodePermutationCipher(test,open_text));
    }
    TEST(Lowercase_English_letters) {
        wstring open_text = L"helloworld";
        wstring result_correct = L"hlodeor lwl";
        CHECK_EQUAL(true, result_correct == test.EncodePermutationCipher(test,open_text));
    }
    TEST(mixt_of_English_and_Russian_letters_and_Space) {
        wstring open_text = L"hello мир world привет";
        wstring result_correct = L"hlм r итeoиwlпв l рodре";
        CHECK_EQUAL(true, result_correct == test.EncodePermutationCipher(test,open_text));
    }
    TEST(Special_Characters) {
        wstring open_text = L"?*()&!";
        wstring result_correct = L"?)*&(!";
        CHECK_EQUAL(true, result_correct == test.EncodePermutationCipher(test,open_text));
    }
    TEST(Numbers_Characters) {
        wstring open_text = L"0123456789";
        wstring result_correct = L"0369147 258";
        CHECK_EQUAL(true, result_correct == test.EncodePermutationCipher(test,open_text));
    }
    TEST(All_characters) {
        wstring open_text = L"Hello Мир 0123 *(){}[]";
        wstring result_correct = L"HlМ 2*{]eoи03(} l р1 )[";
        CHECK_EQUAL(true, result_correct == test.EncodePermutationCipher(test,open_text));
    }
}

SUITE(DecodeTest)
{
    const int key = 3;
    PermutationCipher test(key);
    TEST(Uppercase_Russian_letters) {
        wstring cipher_text = L"ПВМРЕИИТР";
        wstring result_correct = L"ПРИВЕТМИР";
        CHECK_EQUAL(true, result_correct == test.DecodePermutationCipher(test,cipher_text));
    }
     TEST(Lowercase_Russian_letters) {
        wstring cipher_text = L"пвмреиитр";
        wstring result_correct = L"приветмир";
        CHECK_EQUAL(true, result_correct == test.DecodePermutationCipher(test,cipher_text));
    }
    TEST(Uppercase_English_letters) {
        wstring cipher_text = L"HLODEOR LWL";
        wstring result_correct = L"HELLOWORLD ";
        CHECK_EQUAL(true, result_correct == test.DecodePermutationCipher(test,cipher_text));
    }
    TEST(Lowercase_English_letters) {
        wstring cipher_text = L"hlodeor lwl";
        wstring result_correct = L"helloworld ";
        CHECK_EQUAL(true, result_correct == test.DecodePermutationCipher(test,cipher_text));
    }
    TEST(mixt_of_English_and_Russian_letters_and_Space) {
        wstring cipher_text = L"hlм итeoипв l рре";
        wstring result_correct = L"hello мир привет ";
        CHECK_EQUAL(true, result_correct == test.DecodePermutationCipher(test,cipher_text));
    }
    TEST(Special_Characters) {
        wstring cipher_text = L"(%])| &[";
        wstring result_correct = L"()&%|[] ";
        CHECK_EQUAL(true, result_correct == test.DecodePermutationCipher(test,cipher_text));
    }
    TEST(Numbers_Characters) {
        wstring cipher_text = L"0369147 258";
        wstring result_correct = L"0123456789 ";
        CHECK_EQUAL(true, result_correct == test.DecodePermutationCipher(test,cipher_text));
    }
    TEST(All_characters) {
        wstring cipher_text = L"пв1 r(}ре2wl){ит3od| ";
      wstring result_correct = L"привет123 world()|}{ ";
        CHECK_EQUAL(true, result_correct == test.DecodePermutationCipher(test,cipher_text));
    }
}
