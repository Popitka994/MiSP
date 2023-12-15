/** @file
* @author Никитина М. А.
* @version 1.0
* @date 15.12.23
* @copyright ИБСТ ПГУ
* @brief Заголовочный файл для модуля по методу маршрутной перестановки
*/
#ifndef CIPHER_H
#define CIPHER_H
#include <string>
using namespace std;

/** 
* @brief Конструктор класса Cipher
* #param k Ключ для шифрования.
*/
class Cipher {
private:
    int key;
public:
    Cipher(int k);
    string encrypt(const string& msg);
    string decrypt(const string& zashifrovan);
};
#endif