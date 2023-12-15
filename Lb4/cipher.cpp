/** @file
* @brief Модуль cipher.cpp
* @details Реализация методов класса Cipher для шифрования и дешифрования методом маршрутной перестановки.
*/
#include "cipher.h"
#include <string>
using namespace std;

Cipher::Cipher(int k) : key(k) {}

/** @file
* @brief Шифрование
* @param msg Исходный текст для шифрования.
* @return Зашифрованный текст.
*/
string Cipher::encrypt(const string& msg) {
    int kolvo_strok = (msg.length() + key - 1) / key;
    size_t index = 0;
    char table[kolvo_strok][key];

    for (int i = 0; i < kolvo_strok; i++) {
        for (int j = 0; j < key; j++) {
            if (index < msg.length()) {
                table[i][j] = msg[index];
                index++;
            } else {
                table[i][j] = ' ';
            }
        }
    }

    string encrypted;
    for (int j = key - 1; j < key && j >= 0; j = j - 1) {
        for (int i = 0; i < kolvo_strok; i++) {
            encrypted += table[i][j];
        }
    }
    return encrypted;
}

/** @file
* @brief Дешифрование
* @param encrypted Зашифрованный текст.
* @return Расшифрованный текст.
*/
string Cipher::decrypt(const string& encrypted) {
    int kolvo_strok = encrypted.length() / key;
    size_t index = 0;
    char table[kolvo_strok][key];

    for (int j = key - 1; j < key && j >= 0; j = j - 1) {
        for (int i = 0; i < kolvo_strok; i++) {
            table[i][j] = encrypted[index];
            index++;
        }
    }

    string msg;
    for (int i = 0; i < kolvo_strok; i++) {
        for (int j = 0; j < key; j++) {
            msg += table[i][j];
        }
    }
    return msg;
}
