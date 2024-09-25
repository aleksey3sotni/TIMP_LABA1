#include "modCipher.h"

// Добавьте объявление переменной key в заголовочный файл modCipher.h
int key;

modCipher::modCipher(int skey) {
    key = skey;
}

string modCipher::encrypt(string &text) {
    int k = 0;
    int simvoli = text.size();
    int stroki = (simvoli + key - 1) / key; // Исправлено: округление вверх
    char** tabl = new char*[stroki];
    for (int i = 0; i < stroki; i++)
        tabl[i] = new char[key];

    // Заполнение таблицы
    for (int i = 0; i < stroki; i++)
        for (int j = 0; j < key; j++) {
            if (k < simvoli) {
                tabl[i][j] = text[k];
                k++;
            } else {
                tabl[i][j] = '\0'; // Заполнение оставшихся ячеек
            }
        }

    k = 0;
    // Считывание из таблицы
    for (int j = key - 1; j >= 0; j--)
        for (int i = 0; i < stroki; i++) {
            if (k < simvoli) {
                text[k] = tabl[i][j];
                k++;
            }
        }
    return text;
}

string modCipher::decrypt(string &text) {
    int k = 0;
    int simvoli = text.size();
    int stroki = (simvoli + key - 1) / key; // Исправлено: округление вверх
    char** tabl = new char*[stroki];
    for (int i = 0; i < stroki; i++)
        tabl[i] = new char[key];

    // Заполнение таблицы
    for (int j = key - 1; j >= 0; j--)
        for (int i = 0; i < stroki; i++) {
            if (k < simvoli) {
                tabl[i][j] = text[k];
                k++;
            } else {
                tabl[i][j] = '\0'; // Заполнение оставшихся ячеек
            }
        }

    k = 0;
    // Считывание из таблицы
    for (int i = 0; i < stroki; i++)
        for (int j = 0; j < key; j++) {
            if (k < simvoli) {
                text[k] = tabl[i][j];
                k++;
            }
        }
    return text;
}
