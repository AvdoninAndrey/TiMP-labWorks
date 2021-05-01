#pragma once
#include <UnitTest++/UnitTest++.h>
#include "/home/student/TiMP/Lab1/2z/ExceptionStroka.h"
#include "/home/student/TiMP/Lab1/2z/ExceptionStroka.cpp"
#include "/home/student/TiMP/Lab1/2z/ExceptionKey.cpp"
#include "/home/student/TiMP/Lab1/2z/ExceptionKey.h"

SUITE(ExceptionStrokaTest)
{
    TEST(StringOfRussianLetters) {
        CHECK_EQUAL(true, ExceptionStroka::check_stroka("русскаястрока"));
    }
    TEST(StringOfEnglishLetters) {
        CHECK_EQUAL(true, ExceptionStroka::check_stroka("hello"));
    }
    TEST(mixt_of_English_and_Russian_letters_andSpace) {
        CHECK_EQUAL(true, ExceptionStroka::check_stroka("русская строка hello world"));
    }
    TEST(All_characters) {
        CHECK_EQUAL(true, ExceptionStroka::check_stroka("русская hello 123 !()[}"));
    }
    TEST(Empty_Stroka) {
        CHECK_THROW(ExceptionStroka::check_stroka(""),ExceptionStroka);
    }
}

SUITE(ExceptionStrokaKeyTest)
{
    wstring test = L"hello world";
    TEST(Correct_key) {
        CHECK_EQUAL(true, ExceptionKey::check_key(test,"3"));
    }
    TEST(The_key_is_an_unnatural_number) {
        CHECK_THROW(ExceptionKey::check_key(test,"-2"),ExceptionKey);
    }
    TEST(A_key_that_is_greater_than_or_equal_to_the_size_of_the_string) {
        CHECK_THROW(ExceptionKey::check_key(test,"12"),ExceptionKey);
    }
    TEST(A_characters_in_the_key_instead_of_numbers) {
        CHECK_THROW(ExceptionKey::check_key(test,"hel()рул"),ExceptionKey);
    }
    TEST(The_key_contains_symbols_and_numbers) {
        CHECK_THROW(ExceptionKey::check_key(test,"3hel"),ExceptionKey);
    }
    TEST(Empty_key) {
        CHECK_THROW(ExceptionKey::check_key(test,""),ExceptionKey);
    }
}
