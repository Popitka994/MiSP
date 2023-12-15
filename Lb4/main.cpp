/** @file
* @brief Главный модуль программы
* @details Есть функция check и модульные тесты KeyTest, TextTest. 
*/
#include <iostream>
#include <UnitTest++/UnitTest++.h>
#include "cipher.h"
using namespace std;

/** @file
* @brief Функция check
* @details Функция была создана в ходе 2-ой лабораторной работы.
*/
string check(int key, const string& msg)
{
    try {
        cout << "Ключ: " << key << endl;
        if (key <= 1) throw invalid_argument("Ключ должен быть целым числом больше единицы!");
        if (msg.empty()) throw invalid_argument("Исходный текст не может быть пустым!");
        Cipher cipher(key);
        cout << "Исходный текст: " << msg << endl;
        string encrypted = cipher.encrypt(msg);
        cout << "Зашифрованный текст: " << encrypted << endl;
        string decrypted = cipher.decrypt(encrypted);
        cout << "Расшифрованный текст: " << decrypted << endl;
        return encrypted;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return "";
    }
}

/** @file
* @brief Модульные тесты
* @details KeyTest проверяют ключ на длины. TextTest проверяет исходный текст на регистр и наличие символов.
*/
int runTests()
{
    return UnitTest::RunAllTests();
}

//Проверка ключа
SUITE(KeyTest)
{
    TEST(ValidKey) {
        CHECK_EQUAL("rvtpie", check(2, "privet"));//Верный ключ
    }

    TEST(LongerKeyThanMessage) {
        CHECK_EQUAL("hello", check(10, "hello"));//Ключ больше, чем длина
    }

    TEST(KeyLessOne) {
        CHECK_THROW(check(1, "hello"), invalid_argument); //Ключ меньше 1
    }
}

//Проверка исходного текста
SUITE(TextTest) {
    TEST(UppercaseLetters) {
        CHECK_EQUAL("RVTPIE", check(2, "PRIVET"));//Прописные буквы
    }
    TEST(LowercaseLetters) {
        CHECK_EQUAL("rvtpie", check(2, "privet"));//Строчные
    }
    TEST(NonAlphabeticCharacters) {
        CHECK_THROW(check(2, "pri12!"), invalid_argument);//Есть неалфавитные символы
    }
    TEST(EmptyText) {
        CHECK_THROW(check(2, ""), invalid_argument);//Пустая строка
    }
    TEST(NonAlphabeticLetters) {
        CHECK_THROW(check(2, "123!@#"), invalid_argument);//Нет букв
    }
}

int main(int argc, char **argv)
{
    runTests();
    return 0;
}
