#ifndef CVECTOR_H
#define CVECTOR_H
#include "CString.h"

enum type_sorting
{
    buble = 1,
    hairbrush = 2,
    //exit,
};


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
    CString  *container;


public:

    CVector();
    CVector(int n);
    CVector(const CVector &vct);
    ~CVector();

    CVector& operator=(const CVector &vct);
    CVector& operator=(const CVector *vct);

    CVector& operator+=(const CVector &vct);
    CVector& operator+=(const CString &str);
    CVector operator+(const CVector &vct) const;
    CVector operator+(const CString &str) const;

    CString& operator[] (int n);

    bool operator!=(const CVector &vct);
    bool operator==(const CVector &vct);
    bool operator<=(const CVector &vct);
    bool operator>=(const CVector &vct);

    /*!
     * \brief push_back - добавляет объект CString в конец массива
     * \param str       - объект CString
     */
    void push_back(const CString &str);

    /*!
     * \brief show       - демонтсрация содержимого объекта
     */
    void show();

    /*!
     * \brief size       - размер текущего объекта
     * \return           - возвращает m_capacity текущего объекта CVector, если объект пустой возвращет 0
     */
    unsigned size();

    /*!
     * \brief push_front - добавление объекта CString в начало массива
     * \param str        - добавляемый объект
     */
    void push_front(const CString &str);

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
    CString& at(int n);

    /*!
     * \brief front - доступ к 1 элементу массива
     * \return      - возвращает объект CString
     */
    CString& front();

    /*!
     * \brief back - доступ к последнему элементу массива
     * \return     - возвращает объект CString
     */
    CString& back();

    /*!
     * \brief pop_front - доступ к 1 элементу массива с последующим его удалением
     * \return          - возвращает этот элемент
     */
    CString pop_front();

    /*!
     * \brief pop_back - доступ к последнему элементу массива с последующим его удалением
     * \return         - возвращает этот элемент
     */
    CString pop_back();

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
    int find(CString &str);

    /*!
     * \brief rfind - поиск строки в обратном порядке
     * \param str   - искомая строка
     * \return      - порядковый номер строки в массиве в первом вхождении
     */
    int rfind(CString &str);

    /*!
     * \brief sorting - сортировка массива по величине размера объекта CString
     * \return        - отсортированный объект CVector
     */
    CVector& sorting();


};
#endif // CVECTOR_H















