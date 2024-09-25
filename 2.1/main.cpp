#include <iostream>
#include <string>
#include <locale>
#include "modAlphaCipher.h"

using namespace std;

bool isKeyValid(const wstring& key) {
    for (const auto& character : key) {
        if (!iswalpha(character) || !iswupper(character)) {
            return false;
        }
    }
    return true;
}

void displayMenu() {
    wcout << "Cipher operational. Choose an action (0 - exit, 1 - encrypt, 2 - decrypt): ";
}

int main() {
    locale::global(locale("ru_RU.UTF-8"));
    wstring cipherKey, inputText;
    unsigned action;

    wcout << "Cipher initialized. Please enter the key: ";
    wcin >> cipherKey;

    if (!isKeyValid(cipherKey)) {
        wcerr << "Invalid key entered.\n";
        return 1;
    }

    wcout << "Key successfully loaded.\n";
    modAlphaCipher cipher(cipherKey);

    do {
        displayMenu();
        wcin >> action;

        if (action > 2) {
            wcout << "Error: Invalid action selected.\n";
        } else if (action > 0) {
            wcout << "Please enter the text to process: ";
            wcin >> inputText;

            if (isKeyValid(inputText)) {
                if (action == 1) {
                    wcout << "Result of encryption: " << cipher.encrypt(inputText) << endl;
                } else {
                    wcout << "Result of decryption: " << cipher.decrypt(inputText) << endl;
                }
            } else {
                wcout << "Operation canceled: text is invalid.\n";
            }
        }
    } while (action != 0);

    return 0;
}
