#ifndef CVECTOR_H
#define CVECTOR_H
#include "CString.h"
class CVector
{
private:
    //массив, который хранит все слова
    char *storage_words;
    //ёмкость массива
    int capacity_storage;
    //массив хранящий номера, с которых слова начинаются
    int *adress_words;
    //номер с которого слово начинается текущее слово
    int capacity_adress;


public:
    CVector();

    //добавление элемента в последний
    void push(const CString &str);

    //получение размера вектора
    int size_vector();

    //добавление элемента в любой индекс
    void push(const char *new_word, int index);
};
#endif // CVECTOR_H
