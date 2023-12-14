#ifndef CIPHER_H
#define CIPHER_H
#include <string>
using namespace std;
class Cipher {
private:
    int key;
public:
    Cipher(int k);
    string encrypt(const string& msg);
string decrypt(const string& zashifrovan);
};
#endif