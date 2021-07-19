#ifndef CVECTOR_H
#define CVECTOR_H
#include "CString.h"
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;
/*!
 * \brief The type_sorting - варианты сортировок
 */
enum type_sorting
{
    /*!
     * \brief buble - сортировка методом пузырька
     */
    buble = 1,
    /*!
     * \brief haibrush - сортировка методом расчёски
     */
    hairbrush = 2
};

template <typename A>
class CVector
{
private:
    /*!
     * \brief m_count     - текущее количество элементов в векторе
     */
    unsigned m_count;
    /*!
     * \brief m_capacity  - ёмкость вектора
     */
    unsigned m_capacity;
    /*!
     * \brief m_container - указатель на вектор
     */
    A *m_container;


public:

    CVector();
    CVector(int n);
    CVector(const A &vct);
    ~CVector();

    /*!
     * \brief size       - размер текущего объекта CVector
     * \return           - возвращает m_capacity текущего объекта CVector, если объект пустой возвращет 0
     */
    unsigned size();

    /*!
     * \brief resize - меняет размер текущего объекта СVector
     * \param n      - количество элементов
     */
    unsigned resize(int n);

    /*!
     * \brief resize - меняет размер текущего объекта СVector (делает его больше)
     * \param n      - количество элементов
     * \param str    - значение по умолчанию для заполнения пустых элементов
     */
    unsigned resize(int n, A);

    /*!
     * \brief push_front - добавление объекта типа А в начало CVector
     * \param value      - добавляемый объект
     */
    void push_front(const A &value);

    /*!
     * \brief push_back - добавляет объект типа А в конец CVector
     * \param value     - объект типа А
     */
    void push_back(const A &value);

    /*!
     * \brief is_empty   - проверяет пустой ли CVector
     * \return           - возвращет true если пустой, иначе false
     */
    bool is_empty();

    /*!
     * \brief at - доступ к элементу CVector по указанному номеру
     * \param n  - номер элемента
     * \return   - возвращает указанный n-номер массива если n >= 0 или n <= m_count, возращает первый элемент если иначе
     */
    A & at(int n);

    /*!
     * \brief data - возвращает указатель на m_container
     * \return     - указатель на m_container
     */
    const A * data();

    /*!
     * \brief front - доступ к 1 элементу объекта CVector
     * \return      - возвращает объект типа А
     */
    A & front();

    /*!
     * \brief back - доступ к последнему элементу объекта CVector
     * \return     - возвращает объект типа А
     */
    A & back();

    /*!
     * \brief pop_front - удаление первого элемента CVector
     */
    void pop_front();

    /*!
     * \brief pop_front - удаление последнего элемента CVector
     */
    void pop_back();

    /*!
     * \brief clear - откатывает CVector к начальному состоянию
     */
    void clear();

    /*!
     * \brief erase - удаляет элемент в CVector под номером n
     * \param n     - порядковый номер
     * \return      - изменённый CVector
     */
    CVector <A> & erase1(unsigned a);

    /*!
     * \brief erase - удаляет символы m_word в диапазоне first - last
     * \param first - символ с которого начинается удаление
     * \param last  - символ на котором заканчивается
     * \return      - изменённый CVector
     */
    CVector <A> & erase(int first = 0, int last = 1, char f = '[',  char l = ']');

    /*!
     * \brief find  - поиск объекта типа А
     * \param str   - искомый объект
     * \return      - порядковый номер объекта в CVector в первом вхождении
     */
    unsigned find(A &obj);

    /*!
     * \brief rfind - поиск объекта типа А
     * \param str   - искомый объект
     * \return      - порядковый номер объекта в CVector в первом вхождении
     */
    unsigned rfind(A &str);

    /*!
     * \brief sorting
     * \param n
     * \return
     */
    CVector & sorting(int n);

    CVector & operator=(const CVector &vct);
    CVector & operator=(const CVector *vct);


    CVector & operator+=(const CVector &vct);
    CVector & operator+=(const A &obj);

    CVector & operator+(const CVector &vct);
    CVector & operator+(const A &str);

    A & operator[] (int n);

    bool operator!=(const CVector &vct);
    bool operator==(const CVector &vct);

    bool operator<=(const CVector &vct);
    bool operator>=(const CVector &vct);

    bool  operator>(const CVector &vct);
    bool  operator<(const CVector &vct);
};
template <typename A>
CVector<A>::CVector()
{
    m_count      = 0;
    m_capacity   = 1;
    m_container  = new A[m_capacity];
}

template <typename A>
CVector<A>::CVector(int n)
{
    m_count      = 0;
    m_capacity   = n;
    m_container  = new A[m_capacity];
}

template <typename A>
CVector<A>::CVector(const A &vct)
{
    m_count     = vct.m_count;
    m_capacity  = vct.m_capacity;
    m_container = new A[m_capacity];
    for(unsigned i = 0; i < m_count; i++)
    {
        m_container[i] = vct.m_container[i];
    }
}

template <typename A>
CVector<A>::~CVector()
{
    m_count    = 0;
    m_capacity = 1;
    delete [] m_container;
}

template <typename A>
unsigned  CVector<A>::size()
{
    return m_count;
}

template <typename A>
unsigned CVector<A>::resize(int n)
{
    try
    {
        if(n < 0)
        {
            throw 1;
        }
        else if(n > int(m_count))
        {
            throw 2;
        }
    }
    catch (double a)
    {
        return 0;
    }
    catch(int a)
    {
        return 0;
    }
    if(n >= 0)
    {
        if(n < int(m_count))
        {
            m_count = unsigned(n);
            A *temp = new A[m_count];
            for(unsigned i = 0; i < m_count; i++)
            {
                temp[i] = m_container[i];
            }
            m_capacity = m_count * 2;

            delete [] m_container;
            m_container = new A[m_capacity];
            for(unsigned i = 0; i < m_count; i++)
            {
                m_container[i] = temp[i];
            }

            delete [] temp;
        }
    }
    return m_count;
}

template <typename A>
unsigned CVector<A>::resize(int n, A str)
{
    if(n > int(m_count))
    {
        unsigned temp_capacity = m_count;
        A *temp = new A[temp_capacity];
        for(unsigned i = 0; i < temp_capacity; i++)
        {
            temp[i] = m_container[i];
        }
        delete [] m_container;

        m_capacity = unsigned(n);
        m_container = new A[m_capacity];
        unsigned i = 0;
        for(; i < m_count; i++)
        {
            m_container[i] = temp[i];
        }
        for(; i < m_capacity; i++)
        {
            m_container[i] = str;
        }
        delete [] temp;
    }
    return m_count;
}

template <typename A>
void CVector<A>::push_front(const A &value)
{
    if(m_count == m_capacity)
    {
        m_capacity *= 2;
        A *temp = new A[m_capacity];

        temp[0] = value;
        for(unsigned i = 1, j = 0; j < m_count; i++, j++)
        {
            temp[i] = m_container[j];
        }

        delete [] m_container;
        m_container = temp;
        m_count++;
    }
    else if(m_count < m_capacity)
    {
        A *temp = new A[m_capacity];
        temp[0] = value;
        for(unsigned i = 1, j = 0; j < m_count; i++, j++)
        {
            temp[i] = m_container[j];
        }

        delete [] m_container;
        m_container = temp;
        m_count++;
    }
}

template <typename A>
void CVector<A>::push_back(const A &value)
{
    if(m_count == m_capacity)
    {
        m_capacity *= 2;
        A *temp = new A[m_capacity];
        for(unsigned i = 0; i < m_count; i++)
        {
            temp[i] = m_container[i];
        }
        delete [] m_container;
        m_container = temp;
    }
    if(m_count != 0)
    {
        m_container[m_count] = value;
        m_count++;
    }
    else if(m_count == 0)
    {
        m_count++;
        m_capacity *= 2;
        delete [] m_container;
        m_container = new A[m_capacity];
        m_container[0] = value;
    }
}

template <typename A>
bool CVector<A>::is_empty()
{
    bool empty = true;
    if(m_capacity == 1 && m_count == 0)
    {
        empty = true;
    }
    else
    {
        empty = false;
    }
    return empty;
}

template <typename A>
A & CVector<A>::at(int n)
{
    try
    {
        if(n < 0)
        {
            throw 1;
        }
        else if(n > int(m_count) - 1)
        {
            throw 1.0;
        }
    }
    catch(int a)
    {
        return m_container[m_count];
    }
    catch(double a)
    {
        return m_container[m_count];
    }
    return m_container[n];
}

template <typename A>
const A *CVector<A>::data()
{
    return m_container;
}

template <typename A>
A & CVector<A>::front()
{
    try
    {
        if(m_capacity == 1 && m_count == 0)
        {
            throw 1;
        }
    }
    catch (int a)
    {
        return m_container[m_count];
    }

    return m_container[0];
}

template <typename A>
A & CVector<A>::back()
{
    try
    {
        if(m_capacity == 1 && m_count == 0)
        {
            throw 1;
        }
    }
    catch (int a)
    {
        return m_container[m_count];
    }
    return m_container[m_count - 1];
}

template <typename A>
void CVector<A>::pop_front()
{
    try
    {
        if(m_capacity == 1 && m_count == 0)
        {
            throw "0";
        }
    }
    catch (const char *a)
    {
        cout << a << endl;
    }
    A *temp = new A[m_capacity];
    for(unsigned i = 0, j = 1; j < m_count; i++, j++)
    {
        temp[i] = m_container[j];
    }

    m_count--;
    delete [] m_container;
    m_container = temp;
}

template <typename A>
void CVector<A>::pop_back()
{
    try
    {
        if(m_capacity == 1 && m_count == 0)
        {
            throw "0";
        }
    }
    catch (const char *a)
    {
        cout << a << endl;
    }
    A *temp = new A[m_capacity];
    for(unsigned i = 0; i < m_count - 1; i++)
    {
        temp[i] = m_container[i];
    }

    m_count--;
    delete [] m_container;
    m_container = temp;
}

template <typename A>
void CVector<A>::clear()
{
    delete [] m_container;
    m_capacity = 1;
    m_count = 0;
    m_container = new A[m_capacity];
}

template <typename A>
CVector <A> & CVector<A>::erase1(unsigned n)
{
    try
    {
        if(n < 0)
        {
            throw 1;
        }
        if(int(n) > int(m_count) - 1)
        {
            throw 1.0;
        }
    }
    catch (int a)
    {
        return *this;
    }
    catch (double a)
    {
        return *this;
    }
    unsigned num = unsigned(n);
    unsigned new_m_size = m_count - 1;
    A *temp = new A[new_m_size];
    int i = 0;
    for(unsigned j = 0; j < num; i++, j++)
    {
        temp[i] = m_container[j];
    }
    for(unsigned j = num + 1; j < m_count; i++, j++)
    {
        temp[i] = m_container[j];
    }
    delete [] m_container;
    m_count     = new_m_size;
    m_capacity  = m_count;
    m_container = temp;
    return *this;
}

template <typename A>
CVector<A> & CVector<A>::erase(int fr, int lt, char f,  char l)
{
    try
    {
        if(fr < 0 || fr > int(m_count) - 2)
        {
            throw 1;
        }
        if(lt < 1 || lt > int(m_count) - 1)
        {
            throw 1.0;
        }
    }
    catch (int a)
    {
        return *this;
    }
    catch (double a)
    {
        return *this;
    }
    unsigned first = unsigned(fr);
    unsigned last  = unsigned(lt);
    if(f == '[' && l == ']')
    {

        if(first == 0 && last == m_count - 1)
        {
            delete [] m_container;
            m_count     = 0;
            m_capacity  = 1;
            m_container = new A[m_capacity];
        }
        else if(first == 0 && last != m_count - 1)
        {
            unsigned new_m_count = m_count - last - 1;
            A *temp = new A[new_m_count];
            for(unsigned i = 0, j = last + 1; j < m_count; i++, j++)
            {
                temp[i] = m_container[j];
            }
            delete [] m_container;
            m_count     = new_m_count;
            m_capacity  = m_count;
            m_container = temp;
        }
        else if(first != 0 && last == m_count - 1)
        {
            unsigned new_m_size = first;
            A *temp = new A[new_m_size];
            for(unsigned i = 0, j = 0; j < first; i++, j++)
            {
                temp[i] = m_container[j];
            }
            delete [] m_container;
            m_count     = new_m_size;
            m_capacity  = m_count;
            m_container = temp;
        }
        else if(first != 0 && last != m_count - 1)
        {
            unsigned new_m_size = m_count - (last - first + 1);
            A *temp = new A[new_m_size];
            int i = 0;
            for(unsigned j = 0; j < first; i++, j++)
            {
                temp[i] = m_container[j];
            }
            for(unsigned j = last + 1; j < m_count; i++, j++)
            {
                temp[i] = m_container[j];
            }
            delete [] m_container;
            m_count     = new_m_size;
            m_capacity  = m_count;
            m_container = temp;
        }
    }
    else if(f == '(' && l == ')')
    {
        if(first == 0 && last == m_count - 1)
        {
            unsigned new_m_size = 2;
            A *temp = new A[new_m_size];
            temp[0] = m_container[first];
            temp[1] = m_container[last];
            delete [] m_container;
            m_count     = new_m_size;
            m_capacity  = m_count;
            m_container = temp;
        }
        else if(first == 0 && last != m_count - 1)
        {
            unsigned new_m_size = m_count - last + 1;
            A *temp = new A[new_m_size];
            temp[0] = m_container[0];
            for(unsigned i = 1, j = last; j < m_count; i++, j++)
            {
                temp[i] = m_container[j];
            }
            delete [] m_container;
            m_count     = new_m_size;
            m_capacity  = m_count;
            m_container = temp;
        }
        else if(first != 0 && last == m_count - 1)
        {
            unsigned new_m_size = m_count - (last - first - 1);
            A *temp = new A[new_m_size];
            for(unsigned i = 0, j = 0; j < first + 1; i++, j++)
            {
                temp[i] = m_container[j];
            }
            temp[new_m_size - 1] = m_container[m_count - 1];
            delete [] m_container;
            m_count     = new_m_size;
            m_capacity  = m_count;
            m_container = temp;
        }
        else if(first != 0 && last != m_count - 1)
        {
            unsigned new_m_size = m_count - (last - first - 1);
            A *temp = new A[new_m_size];
            int i = 0;
            for(unsigned j = 0; j < first + 1; i++, j++)
            {
                temp[i] = m_container[j];
            }
            for(unsigned j = last; j < m_count;i++, j++)
            {
                temp[i] = m_container[j];
            }
            delete [] m_container;
            m_count     = new_m_size;
            m_capacity  = m_count;
            m_container = temp;
        }
    }
    else if(f == '[' && l == ')')
    {
        if(first == 0 && last == m_count - 1)
        {
            unsigned new_m_size = 1;
            A *temp = new A[new_m_size];
            temp[0] = m_container[last];
            delete [] m_container;
            m_count     = new_m_size;
            m_capacity  = m_count;
            m_container = temp;
        }
        else if(first == 0 && last != m_count - 1)
        {
            unsigned new_m_size = m_count - last;
            A *temp = new A[new_m_size];
            for(unsigned i = 0, j = last; j < m_count; i++, j++)
            {
                temp[i] = m_container[j];
            }
            delete [] m_container;
            m_count     = new_m_size;
            m_capacity  = m_count;
            m_container = temp;
        }
        else if(first != 0 && last == m_count - 1)
        {
            unsigned new_m_size = m_count - (last - first);
            A *temp = new A[new_m_size];
            int i = 0;
            for(unsigned j = 0; j < first; i++, j++)
            {
                temp[i] = m_container[j];
            }
            for(unsigned j = last; j < m_count; i++, j++)
            {
                temp[i] = m_container[j];
            }
            delete [] m_container;
            m_count     = new_m_size;
            m_capacity  = m_count;
            m_container = temp;
        }
        else if(first != 0 && last != m_count - 1)
        {
            unsigned new_m_size = m_count - (last - first);
            A *temp = new A[new_m_size];
            unsigned i = 0;
            for(unsigned j = 0; j < first; i++, j++)
            {
                temp[i] = m_container[j];
            }
            for(unsigned j = last; j < m_count; i++, j++)
            {
                temp[i] = m_container[j];
            }
            delete [] m_container;
            m_count     = new_m_size;
            m_capacity  = m_count;
            m_container = temp;
        }
    }
    else if(f == '(' && l == ']')
    {
        if(first == 0 && last == m_count - 1)
        {
            unsigned new_m_size = 1;
            A *temp = new A[new_m_size];
            temp[0] = m_container[first];
            delete [] m_container;
            m_count     = new_m_size;
            m_capacity  = m_count;
            m_container = temp;
        }
        else if(first == 0 && last != m_count - 1)
        {
            unsigned new_m_size = m_count - last;
            A *temp = new A[new_m_size];
            temp[0] = m_container[0];
            for(unsigned i = 1, j = last + 1; j < m_count; i++, j++)
            {
                temp[i] = m_container[j];
            }
            delete [] m_container;
            m_count     = new_m_size;
            m_capacity  = m_count;
            m_container = temp;
        }
        else if(first != 0 && last == m_count - 1)
        {
            unsigned new_m_size = m_count - (last - first);
            A *temp = new A[new_m_size];
            for(unsigned i = 0, j = 0; j < first + 1; i++, j++)
            {
                temp[i] = m_container[j];
            }
            delete [] m_container;
            m_count     = new_m_size;
            m_capacity  = m_count;
            m_container = temp;
        }
        else if(first != 0 && last != m_count - 1)
        {
            unsigned new_m_size = m_count - (last - first);
            A *temp = new A[new_m_size];
            unsigned i = 0;
            for(unsigned j = 0; j < first + 1; i++, j++)
            {
                temp[i] = m_container[j];
            }
            for(unsigned j = last + 1; j < m_count; i++, j++)
            {
                temp[i] = m_container[j];
            }
            delete [] m_container;
            m_count     = new_m_size;
            m_capacity  = m_count;
            m_container = temp;
        }
    }

    return *this;

}

template <typename A>
unsigned CVector<A>::find(A &value)
{
    //номер с которого начинается первое совпадение
    unsigned number = 0;
    //количество совпадений
    unsigned num_value = 0;
    //если было совпадение
    bool find = false;

    for(unsigned i = 0; i < m_count; i++)
    {
        if(value == m_container[i])
        {
            number = i;
            find = true;
            break;
        }
    }
    if(find == true)
    {
        for(unsigned i = 0; i < m_count; i++)
        {
            if(value == m_container[i])
            {
                num_value++;
            }
        }
    }

    //если ни разу не совпало вывести предупреждение
    try
    {
        if(find == false)
        {
            throw 1;
        }
    }
    catch (int a)
    {
        return 0;
    }
    return number;
}

template <typename A>
unsigned CVector<A>::rfind(A &value)
{
    //номер с которого начинается первое совпадение
    unsigned number = 0;
    //количество совпадений
    unsigned num_value = 0;
    //если было совпадение
    bool find = false;

    for(int i = int(m_count); i > -1; i--)
    {
        if(value == m_container[i])
        {
            number = i;
            find = true;
            break;
        }
    }
    if(find == true)
    {
        for(int i = m_count; i > -1; i--)
        {
            if(value == m_container[i])
            {
                num_value++;
            }
        }
    }

    //если ни разу не совпало вывести предупреждение
    try
    {
        if(find == false)
        {
            throw 0;
        }
    }
    catch (unsigned a)
    {
        return 0;
    }
    return number;
}

template <typename A>
CVector<A>& CVector<A>::sorting(int choice)
{
    /*type_sorting type_sort = buble;
    choice = type_sort;*/
    /*cout << "Enter the choice: " << endl;
    cout <<"1) buble \n"
           "2) hairbrush \n"
           "3) exit" << endl;
    cin >> choice;*/
    if(choice != 3)
    {
        switch (choice)
        {
            case buble:
            {
                unsigned  j = 0;
                unsigned  t = 0;
                for(unsigned i = 0; i < m_count; i++)
                {
                    j = i;
                    for(t = i; t < m_count; t++)
                    {
                        if(m_container[j] > m_container[t])
                        {
                            j = t;
                        }
                    }
                    A temp;
                    temp = m_container[i];
                    m_container[i] = m_container[j];
                    m_container[j] = temp;
                }
                break;
            }
            case hairbrush:
            {
                double factor = 1.247;
                unsigned step = m_count - 1;
                while (step >= 1)
                {
                    for(unsigned i = 0; i + step < m_count; i++)
                    {
                        if(m_container[i] > m_container[i + step])
                        {
                            A temp;
                            temp = m_container[i];
                            m_container[i] = m_container[i + step];
                            m_container[i + step] = temp;
                        }
                    }
                step /= factor;
                }
            }
        }
    }

    return *this;
}

template <typename A>
CVector<A>& CVector<A>::operator=(const CVector &vct)
{
    if(this == &vct)
    {
        return *this;
    }

    if(m_capacity != 1 && m_count != 0)
    {
        delete [] m_container;
    }

    m_count = vct.m_count;
    m_capacity = vct.m_capacity;
    m_container = new A[m_capacity];
    for(unsigned i = 0; i < m_count; i++)
    {
        m_container[i] = vct.m_container[i];
    }

    return *this;
}

template <typename A>
CVector<A>& CVector<A>::operator=(const CVector *vct)
{
    if(this == vct)
    {
        return *this;
    }

    if(m_capacity != 1 && m_count != 0)
    {
        delete [] m_container;
    }

    m_count     = vct->m_count;
    m_capacity  = vct->m_capacity;
    m_container = new A[m_capacity];
    for(unsigned i = 0; i < m_count; i++)
    {
        m_container[i] = vct->m_container[i];
    }

    return  *this;
}

template <typename A>
CVector<A> & CVector<A>::operator+=(const CVector &vct)
{
    unsigned old_m_count = m_count;
    unsigned new_m_capacity = m_capacity + vct.m_capacity;
    A *temp = new A[new_m_capacity];

    unsigned k = 0;
    for(unsigned i = 0; i < old_m_count; i++, k++)
    {
        temp[k] = m_container[i];
    }
    for(unsigned i = 0; i < vct.m_count; i++, k++)
    {
        temp[k] = vct.m_container[i];
    }

    if(m_capacity != 1 && m_count != 0)
    {
        delete [] m_container;
    }
    m_capacity += vct.m_capacity;
    m_count    += vct.m_count;
    m_container = temp;

    return *this;
}

template <typename A>
CVector<A>& CVector<A>::operator+=(const A &str)
{
    if(m_count == m_capacity)
    {
        m_capacity *= 2;
        A *temp = new A[m_capacity];
        for(unsigned i = 0; i < m_count; i++)
        {
            temp[i] = m_container[i];
        }
        delete [] m_container;
        m_container = temp;
    }
    m_container[m_count] = str;
    m_count++;

    return *this;
}

template <typename A>
CVector<A> & CVector<A>::operator+(const CVector &vct)
{
    unsigned new_m_count = m_count + vct.m_count;
    A *temp = new A[new_m_count];
    for(unsigned i = 0; i < m_count; i++)
    {
        temp[i] = m_container[i];
    }

    for(unsigned i = m_count, j = 0; j < vct.m_count; i++, j++)
    {
        temp[i] = vct.m_container[j];
    }
    delete [] m_container;
    m_count     = new_m_count;
    m_capacity  = new_m_count;
    m_container = temp;
    return *this;
}

template <typename A>
CVector<A> & CVector<A>::operator+(const A &str)
{
    if(m_count == m_capacity)
    {
        m_capacity *= 2;
        A *temp = new A[m_capacity];
        for(unsigned i = 0; i < m_count; i++)
        {
            temp[i] = m_container[i];
        }
        m_container = temp;

    }
    m_container[m_count] = str;
    m_count++;
    return *this;
}

template <typename A>
A & CVector<A>::operator[](int n)
{
    return m_container[n];
}

template <typename A>
bool CVector<A>::operator==(const CVector &vct)
{
    bool coincidence = false;
    unsigned  find_coincidence = 0;

    if(m_count == vct.m_count)
    {
        for(unsigned i = 0; i < m_count; i++)
        {
            if(m_container[i] == vct.m_container[i])
            {
                find_coincidence++;
            }
            else
            {
                find_coincidence = 0;
                break;
            }
        }
        if(find_coincidence == m_count)
        {
            coincidence = true;
        }

    }
    return coincidence;
}

template <typename A>
bool CVector<A>::operator!=(const CVector &vct)
{
    bool dismatch = true;
    unsigned find_coincidence = 0;
    if(m_count == vct.m_count)
    {
        for(unsigned i = 0; i < m_count; i++)
        {
            if(m_container[i] == vct.m_container[i])
            {
                find_coincidence++;
            }
            else
            {
                find_coincidence = 0;
                break;
            }
        }
        if(find_coincidence == m_count)
        {
            dismatch = false;
        }

    }
    return dismatch;
}

template <typename A>
bool CVector<A>::operator<=(const CVector &vct)
{
    bool less = false;
    unsigned  search_m_count = 0;
    if(m_count <= vct.m_count)
    {
        for(unsigned i = 0; i < m_count; i++)
        {
            if(m_container[i] <= vct.m_container[i])
            {
                search_m_count++;
            }
            else
            {
                break;
            }
        }

        if(search_m_count <= m_count)
        {
            less = true;
        }
    }
    return less;
}

template <typename A>
bool CVector<A>::operator>=(const CVector &vct)
{
    bool more = false;
    unsigned  search_m_count = 0;
    if(m_count >= vct.m_count)
    {
        for(unsigned i = 0; i < m_count; i++)
        {
            if(m_container[i] >= vct.m_container[i])
            {
                search_m_count++;
            }
            else
            {
                break;
            }
        }

        if(search_m_count >= m_count)
        {
            more = true;
        }
    }
    return more;
}

template <typename A>
bool CVector<A>::operator>(const CVector &vct)
{
    bool more = false;
    if(m_count > vct.m_count)
    {
        more = true;
    }
    else if(m_count == vct.m_count)
    {
        A sum0 = 0;
        A sum1 = 0;
        for(unsigned i = 0; i < m_count; i++)
        {
            sum0 += m_container[i];
        }
        for(unsigned i = 0; i < m_count; i++)
        {
            sum1 += vct.m_container[i];
        }
        if(sum0 > sum1)
        {
            more = true;
        }
        else if(sum0 == sum1)
        {
            more = true;
        }
        else
        {
            more = false;
        }
    }
    return more;
}

template <typename A>
bool CVector<A>::operator<(const CVector &vct)
{
    bool less = false;
    if(m_count < vct.m_count)
    {
        less = true;
    }
    else if(m_count == vct.m_count)
    {
        A sum0 = 0;
        A sum1 = 0;
        for(unsigned i = 0; i < m_count; i++)
        {
            sum0 += m_container[i];
        }
        for(unsigned i = 0; i < m_count; i++)
        {
            sum1 += vct.m_container[i];
        }
        if(sum0 < sum1)
        {
            less = true;
        }
        else if(sum0 == sum1)
        {
            less = true;
        }
        else
        {
            less = false;
        }
    }
    return less;
}
#endif // CVECTOR_H
