#ifndef CVECTOR_H
#define CVECTOR_H
#include "CString.h"

enum type_sorting
{
    buble = 1,
    hairbrush = 2,
    //exit,
};

template <typename A>
class CVector
{
private:
    /*!
     * \brief m_count    - текущее количество элементов в векторе
     *        m_capacity - ёмкость вектора
     *        container  - указатель на вектор
     */
    unsigned int m_count;
    unsigned int m_capacity;
    A        * container;


public:

    CVector();
    CVector(int n);
    CVector(const A &vct);
    ~CVector();

    /*!
     * \brief push_back - добавляет объект типа А в конец CVector
     * \param str       - объект типа А
     */
    void push_back(const A &value);


    /*!
     * \brief size       - размер текущего объекта
     * \return           - возвращает m_capacity текущего объекта CVector, если объект пустой возвращет 0
     */
    unsigned size();

    /*!
     * \brief push_front - добавление объекта типа А в начало CVector
     * \param str        - добавляемый объект
     */
    void push_front(const A &str);

    /*!
     * \brief is_empty
     * \return           - возвращет true если пустой, иначе false
     */
    bool is_empty();

    /*!
     * \brief at - доступ к элементу массива по указанному номеру и демонстрация содержимого этого элемента
     * \param n  - номер элемента
     * \return   - возвращает указанный n-номер массива если n >= 0 или n <= m_count, возращает первый элемент если иначе
     */
    A &at(int n);

    /*!
     * \brief front - доступ к 1 элементу массива
     * \return      - возвращает объект типа А
     */
    A &front();

    /*!
     * \brief back - доступ к последнему элементу массива
     * \return     - возвращает объект типа А
     */
    A &back();

    /*!
     * \brief pop_front - доступ к 1 элементу массива с последующим его удалением
     * \return          - возвращает этот элемент
     */
    A pop_front();

    /*!
     * \brief pop_back - доступ к последнему элементу массива с последующим его удалением
     * \return         - возвращает этот элемент
     */
    A pop_back();

    /*!
     * \brief erase - удаляет объекты элементы массива с first по last функция предоставляет интерактивный выбор [) () (]
                      в командной строке
     * \param first - элемент с которого начинается удаление
     * \param last  - элемент на котором удаление заканчивается
     * \return      - возвращает изменённый объект CVector
     */
    CVector& erase(unsigned int first, unsigned int last);

    /*!
     * \brief resize - меняет ёмкость вектора (m_capacity)
     * \param n      - заданная ёмкость
     */
    unsigned resize(int n);

    /*!
     * \brief clear - откатывает вектор к начальному состоянию
     */
    void clear();

    /*!
     * \brief find  - поиск строки
     * \param str   - искомая строка
     * \return      - порядковый номер строки в массиве в первом вхождении
     */
    int find(A &str);

    /*!
     * \brief rfind - поиск строки в обратном порядке
     * \param str   - искомая строка
     * \return      - порядковый номер строки в массиве в первом вхождении
     */
    int rfind(A &str);

    /*!
     * \brief sorting - сортировка массива по величине размера объекта типа А
     * \return        - отсортированный объект CVector
     */
    CVector &sorting();


    CVector &operator=(const CVector &vct);
    CVector &operator=(const CVector *vct);

    CVector &operator+=(const CVector &vct);
    CVector &operator+=(const A &str);
    CVector operator+(const CVector &vct) const;
    CVector operator+(const A &str) const;

    A& operator[] (int n);

    bool operator!=(const CVector &vct);
    bool operator==(const CVector &vct);
    bool operator<=(const CVector &vct);
    bool operator>=(const CVector &vct);
    bool  operator>(const CVector &vct);
    bool  operator<(const CVector &vct);

};
#endif // CVECTOR_H















