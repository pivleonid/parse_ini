#ifndef CVECTOR_H
#define CVECTOR_H
#include "CString.h"

/**
 * @brief The CVector class
 *
 */
Сделать одну пузырьковую и одну на выбор
enum sort_
{
    buble_sort,
    Сортировка вставками
    Сортировка выбором
    быстрая
    сортировка слиянием
    блочная сортировка
}sort_variant

class CVector
{
private:



//    //массив, который хранит все слова
//    char *storage_words;
//    //ёмкость массива
//    int capacity_storage;
//    //массив хранящий номера, с которых слова начинаются
//    int *adress_words;
//    //номер с которого слово начинается текущее слово
//    int capacity_adress;
    unsigned int m_count;  0;1;2;3;4;5;6;7;8
    unsigned int m_counter;0;1;2;4;4;8;8;8;8;
    CString* container = new CString[m_counter];

    void push(const CString &str)
    {

        container[m_count] = str;
    }


public:
    CVector();
    //CVector();
    CVector(int);

    //добавление элемента в последний
    void push_back(const CString &str);
    void push_front
    int size(); //с 1
    bool is_empty();

    int at(int n);
    int front();
    int back();
    //
    int pop_front();//достает последний эл-т, удаляя его из вектора
    int pop_back();

    /*************************************************************
     * erase - удаляет символы m_word в диапазоне first - last и
               возвращает изменённый m_word
     *************************************************************
    */
    //[) () (]
    bool erase(int first, int last);

    /*************************************************************
     * compare - сравнивает два объекта, возвращает true
                 если совпали все символы
     *************************************************************
    */
    1.2.3.4.5
    3.1.2.4.5
    bool compare(const CVector &str);

    /*************************************************************
     * find - ищет s в m_word и возвращает его порядковый номер
     *************************************************************
    */
    int find( CString &s);
    int rfind( CString &str);

    bool clear();

    //int m_counter
    bool resize(int i);

    CVector& operator+=(const CVector &str);
    CVector& operator+=(CString s);
    CVector& operator+(const CVector &str);
    CVector& operator+(const CString &str);

    CVector& operator[](int i);

    bool operator!=(const CVector &str);
    bool operator==(const CVector &str);
    bool operator<=(const CVector &str);
    bool operator>=(const CVector &str);

    CVector vtr;
    vct.resize(50)

    //0 - пузырьковая
    //Сортировка вставкой
    //
    bool sort(sort_variant sort);


};
#endif // CVECTOR_H
