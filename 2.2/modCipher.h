#ifndef MODCIPHER_H
#define MODCIPHER_H

#include <string>
using namespace std;

class modCipher {
public:
    modCipher(int skey);
    string encrypt(string &text);
    string decrypt(string &text);

private:
    int key; 
};

#endif 
