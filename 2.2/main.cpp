#include <iostream>
#include <string>
#include "modCipher.h"

using namespace std;

bool isValid(const int k, string &text) {
    int razm = text.size();
    return k <= razm; // Можно упростить
}

int main() {
    string text;
    int key;
    unsigned vibor;

    cout << "Введите текст: ";
    cin >> text;
    cout << "Введите кол-во столбцов: ";
    cin >> key;

    if (!isValid(key, text)) {
        cout << "Ключ не корректен\n";
        return 1;
    }

    cout << "Ключ загружен\n";

    // Убедитесь, что используете правильное имя класса
    modCipher shifr(key); // Измените modShifr на modCipher, если это необходимо

    do {
        cout << "Шифратор готов. Выберите операцию (Выход-0, Шифровка-1, Расшифровка-2): ";
        cin >> vibor;

        if (vibor > 2) {
            cout << "Неверная операция!\n" << endl;
        } else if (vibor > 0) {
            if (vibor == 1)
                cout << shifr.encrypt(text) << endl;
            else
                cout << shifr.decrypt(text) << endl;
        }
    } while (vibor != 0);

    return 0;
}


