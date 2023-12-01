#include <iostream>
#include "cipher.h"
using namespace std;

void check (int key, const string& msg)
{
    try {
        if(key<=1) throw invalid_argument("Ключ должен быть целым числом больше единицы!");
        if(msg.empty()) throw invalid_argument("Исходный текст не может быть пустым!");
        Cipher cipher(key);
        string encrypted=cipher.encrypt(msg);
        string decrypted=cipher.decrypt(encrypted);
        cout<<"Зашифрованный текст: "<<encrypted<<endl;
        cout<<"Расшифрованный текст: "<<decrypted<<endl;
    } catch (const exception& e) {
        cerr<<"Error: "<<e.what()<<endl;
    }
}

int main ()
{
    string msg;
    int key;
    /*cout<<"Введи ключ (кол-во столбцов): ";
    cin>>key;
    cin.ignore();
    cout<<"Введите исходный текст: ";
    getline(cin, msg);*/
    check(2, "privet");
    check(1, "privet");
    check(2, "PRIVET");
    check(2, "");
    return 0;
}
