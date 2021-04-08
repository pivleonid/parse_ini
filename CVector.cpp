#include "CVector.h"
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;

template <typename A>
CVector<A>::CVector()
{
    m_count    = 0;
    m_capacity = 1;
    container  = new A[m_capacity];
}

template <typename A>
CVector<A>::CVector(int n)
{
    m_count    = 0;
    m_capacity = n;
    container  = new A[m_capacity];
}

template <typename A>
CVector<A>::~CVector()
{
    m_count    = 0;
    m_capacity = 1;
    delete [] container;
}

template <typename A>
CVector<A>::CVector(const A &vct)
{
    m_count = vct.m_count;
    m_capacity = vct.m_capacity;
    container = new A[m_capacity];
    for(unsigned i = 0; i < m_count; i++)
    {
        container[i] = vct.container[i];
    }
}

template <typename A>
void CVector<A>::push_back(const A &value)
{
    if(m_count == m_capacity)
    {
        m_capacity *= 2;
        A *temp = new A[m_capacity];
        for(unsigned int i = 0; i < m_count; i++)
        {
            temp[i] = container[i];
        }

        delete [] container;
        container = temp;
    }

    container[m_count] = value;
    m_count++;
}

template <typename A>
void CVector<A>::push_front(const A &value)
{
    if(m_count == m_capacity)
    {
        m_capacity *= 2;
        A *temp = new A[m_capacity];
        temp[0] = value;
        for(unsigned int i = 1, j = 0; i < m_count; i++, j++)
        {
            temp[i] = container[j];
        }

        delete [] container;
        container = temp;
        m_count++;
    }
    else if(m_count < m_capacity)
    {
        A *temp = new A[m_capacity];
        temp[0] = value;
        for(unsigned int i = 1, j = 0; i < m_count; i++, j++)
        {
            temp[i] = container[j];
        }

        delete [] container;
        container = temp;
        m_count++;
    }
}

template <typename A>
unsigned CVector<A>::size()
{
    return m_count;
}

template <typename A>
bool CVector<A>::is_empty()
{
    bool empty = true;
    if(m_capacity == 1 && container[0].empty() == 1)
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
A& CVector<A>::at(int n)
{
    if(n < 0)
    {
        cout << "Enter the \'n\' from 0 to " << m_count << " ." << endl;
        return container[m_count];
    }
    unsigned int n1 = n;

    if(n1 > m_count)
    {
        cout << "Enter the \'n\' from 0 to " << m_count << " ." << endl;

        return container[m_count];
    }
    else
    {
        return container[n];
    }
}

template <typename A>
A& CVector<A>::front()
{
    if(m_capacity == 1 && container[0].empty() == 1)
    {
        cout << "Add the object A in CVector." << endl;

        return container[m_count];
    }
    else
    {

        return container[0];
    }


}

template <typename A>
A& CVector<A>::back()
{
    if(m_capacity == 1 && container[0].empty() == 1)
    {
        cout << "Add the object A in CVector." << endl;
        return container[m_count];
    }
    else
    {
        return container[m_count - 1];
    }
}

template <typename A>
A CVector<A>::pop_front()
{
    A first;
    if(m_capacity == 1 && container[0].empty() == 1)
    {
        cout << "Add the object A in CVector." << endl;
    }

    else
    {
        first = container[0];
        A *temp = new A[m_capacity];
        for(unsigned int i = 0, j = 1; j < m_count; i++, j++)
        {
            temp[i] = container[j];
        }

        m_count--;
        delete [] container;
        container = temp;
    }

    return first;
}

template <typename A>
A CVector<A>::pop_back()
{
    A last;
    if(m_capacity == 1 && container[0].empty() == 1)
    {
        cout << "Add the object A in CVector." << endl;
    }

    else
    {
        last = container[m_count - 1];
        A *temp = new A[m_capacity];
        for(unsigned i = 0; i < m_count - 1; i++)
        {
            temp[i] = container[i];
        }

        m_count--;
        delete [] container;
        container = temp;
    }

    return last;
}

template <typename A>
CVector<A>& CVector<A>::erase(unsigned int first, unsigned int last)
{
    int false0 = 0;
    //если first вне диапазона массива выводим предупреждение
    if(first < 0 || first > m_count - 1)
    {
        false0 = 1;
    }

    if(false0 == 1)
    {
        cout << "The \'first\' number should be from 0 " << "to " <<m_count - 1 << " ." << endl;
    }

    //если last вне диапазона массива выводим предупреждение
    if(last < 1 || last > m_count - 1)
    {
        false0 = 2;
    }

    if(false0 == 2)
    {
        cout << "The last number should be from 1 " << "to " << m_count - 1 << " ." << endl;
    }

    else if(false0 == 0)
    {
        char choice1;
        char choice2;
        cout << "Do you wish delete element \'first\':" << endl;
        cout << "Enter Y or N:" << endl;
        cin >> choice1;
        cout << "Do you wish delete element \'last \':" << endl;
        cout << "Enter Y or N:" << endl;
        cin >> choice2;
        char choice3 = toupper(choice1);
        char choice4 = toupper(choice2);
        if(choice3 == 'N' && choice4 == 'N')
        {
            A *temp = new A[m_capacity];

            if(first == 0 && last == m_count - 1)
            {
                temp[0] = container[first];
                temp[1] = container[last];

                delete [] container;
                container = temp;
            }

            else if(first == 0 && last != m_count - 1)
            {
                temp[0] = container[first];

                for(unsigned int i = 1, j = last; j < m_count - 1; i++, j++)
                {
                    temp[i] = container[j];
                }

                delete [] container;
                container = temp;
            }

            else if(first != 0 && last == m_count - 1)
            {
                unsigned int i = 0;

                for(unsigned int j = 0; j < first + 1; i++, j++)
                {
                    temp[i] = container[j];
                }

                temp[i] = container[m_count - 1];
                delete [] container;
                container = temp;
            }

            else if(first != 0 && last != m_count - 1)
            {
                unsigned int i = 0;

                for(unsigned int j = 0; j < first + 1; i++, j++)
                {
                    temp[i] = container[j];
                }
                for(unsigned int  j = last; j < m_count; i++, j++)
                {
                    temp[i] = container[j];
                }


                delete [] container;
                container = temp;
            }

        }

        else if(choice3 == 'Y' && choice4 == 'N')
        {
            A *temp = new A[m_capacity];

            if(first == 0 && last == m_count - 1)
            {
                temp[0] = container[last];
                delete [] container;
                container = temp;
            }

            else if(first == 0 && last != m_count - 1)
            {

                for(unsigned int i = 0, j = last; j < m_count; i++, j++)
                {
                    temp[i] = container[j];
                }

                delete [] container;
                container = temp;
            }

            else if(first != 0 && last == m_count - 1)
            {
                unsigned int i = 0;

                for(unsigned int j = 0; j < first; i++, j++)
                {
                    temp[i] = container[j];
                }

                temp[i] = container[m_count - 1];
                delete [] container;
                container = temp;
            }

            else if(first != 0 && last != m_count - 1)
            {
                unsigned int i = 0;

                for(unsigned int j = 0; j < first; i++, j++)
                {
                    temp[i] = container[j];
                }

                for(unsigned int  j = last; j < m_count; i++, j++)
                {
                    temp[i] = container[j];
                }

                delete [] container;
                container = temp;
            }
        }

        else if(choice3 == 'N' && choice4 == 'Y')
        {
            A *temp = new A[m_capacity];

            if(first == 0 && last == m_count - 1)
            {
                temp[0] = container[first];

                delete [] container;
                container = temp;
            }

            else if(first == 0 && last != m_count - 1)
            {
                temp[0] = container[first];

                for(unsigned int i = 1, j = last + 1; j < m_count; i++, j++)
                {
                    temp[i] = container[j];
                }

                delete [] container;
                container = temp;
            }

            else if(first != 0 && last == m_count - 1)
            {
                unsigned int i = 0;

                for(unsigned int j = 0; j < first + 1; i++, j++)
                {
                    temp[i] = container[j];
                }

                delete [] container;
                container = temp;
            }

            else if(first != 0 && last != m_count - 1)
            {
                unsigned int i = 0;

                for(unsigned int j = 0; j < first + 1; i++, j++)
                {
                    temp[i] = container[j];
                }

                for(unsigned int  j = last + 1; j < m_count; i++, j++)
                {
                    temp[i] = container[j];
                }

                delete [] container;
                container = temp;
            }
        }

        else if(choice3 == 'Y' && choice4 == 'Y')
        {
            A *temp = new A[m_capacity];

            if(first == 0 && last == m_count - 1)
            {
                delete [] container;
                container = temp;
            }

            else if(first == 0 && last != m_count - 1)
            {
                for(unsigned int i = 0, j = last + 1; j < m_count; i++, j++)
                {
                    temp[i] = container[j];
                }

                delete [] container;
                container = temp;
            }

            else if(first != 0 && last == m_count - 1)
            {
                for(unsigned int i = 0, j = 0; j < first; i++, j++)
                {
                    temp[i] = container[j];
                }

                delete [] container;
                container = temp;
            }

            else if(first != 0 && last != m_count - 1)
            {
                unsigned int i = 0;

                for(unsigned int j = 0; j < first; i++, j++)
                {
                    temp[i] = container[j];
                }

                for(unsigned int  j = last + 1; j < m_count; i++, j++)
                {
                    temp[i] = container[j];
                }

                delete [] container;
                container = temp;
            }
        }
    }

    return *this;
}

template <typename A>
unsigned CVector<A>::resize(int n)
{

    if(n < 0)
    {
        cout << "Enter the correct number" << endl;
    }

    unsigned n1 = n;
    if(n1 < m_count)
    {
        m_count = n1;
        A *temp = new A[m_count];
        for(unsigned i = 0; i < m_count; i++)
        {
            temp[i] = container[i];
        }
        m_capacity = m_count * 2;

        delete [] container;
        container = new A[m_capacity];
        for(unsigned i = 0; i < m_count; i++)
        {
            container[i] = temp[i];
        }

        delete [] temp;
    }
    return m_count;
}

template <typename A>
void CVector<A>::clear()
{
    delete [] container;
    m_capacity = 1;
    m_count = 0;
    container = new A[m_capacity];
}

template <typename A>
int CVector<A>::find(A &value)
{
    //номер с которого начинается первое совпадение
    int number = 0;
    //количество совпадений
    int n_word = 0;
    //если было совпадение
    bool coincidence = false;

    for(unsigned i = 0; i < m_count; i++)
    {
        if(value == container[i])
        {
            number = i;
            coincidence = true;
            break;
        }
    }
    if(coincidence == true)
    {
        for(unsigned i = 0; i < m_count; i++)
        {
            if(value == container[i])
            {
                n_word++;
            }
        }
    }

    //если ни разу не совпало вывести предупреждение
    else if(coincidence == false)
    {
        cout << "Enter the correct value for search." << endl;
    }
    return number;
}

template <typename A>
int CVector<A>::rfind(A &value)
{
    //номер с которого начинается первое совпадение
    int number = 0;
    //количество совпадений
    int n_word = 0;
    //если было совпадение
    bool coincidence = false;

    for(int i = m_count; i > -1; i--)
    {
        if(value == container[i])
        {
            number = i;
            coincidence = true;
            break;
        }
    }
    if(coincidence == true)
    {
        for(int i = m_count; i > -1; i--)
        {
            if(value == container[i])
            {
                n_word++;
            }
        }
    }

    //если ни разу не совпало вывести предупреждение
    else if(coincidence == false)
    {
        cout << "Enter the correct value for search." << endl;
    }
    return number;
}
template <typename A>
CVector<A>& CVector<A>::sorting()
{
    type_sorting type_sort = buble;
    int choice = type_sort;
    cout << "Enter the choice: " << endl;
    cout <<"1) buble \n"
           "2) hairbrush \n"
           "3) exit" << endl;
    cin >> choice;
    if(choice != 3)
    {
        switch (choice)
        {
            case buble:
            {
                unsigned j = 0;
                unsigned t = 0;
                for(unsigned i = 0; i < m_count; i++)
                {
                    j = i;
                    for(t = i; t < m_count; t++)
                    {
                        if(container[j].m_size > container[t].m_size)
                        {
                            j = t;
                        }
                    }
                    A temp;
                    temp = container[i];
                    container[i] = container[j];
                    container[j] = temp;
                }
                break;
            }
            case hairbrush:
            {
                double factor = 1.247;
                int step = m_count - 1;
                while (step >= 1)
                {
                    for(unsigned i = 0; i + step < m_count; i++)
                    {
                        if(container[i].m_size > container[i + step].m_size)
                        {
                            A temp;
                            temp = container[i];
                            container[i] = container[i + step];
                            container[i + step] = temp;
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

    if(m_capacity != 1 && container[0].empty() == 0)
    {
        delete [] container;
    }

    m_count = vct.m_count;
    m_capacity = vct.m_capacity;
    container = new A[m_capacity];
    for(unsigned int i = 0; i < m_count; i++)
    {
        container[i] = vct.container[i];
    }

    return *this;
}

template <typename A>
CVector<A>& CVector<A>::operator=(const CVector *vct)
{
    if(this == vct)
        return *this;

    m_count = vct->m_count;

    m_capacity = vct->m_capacity;

    if(m_capacity != 1)
    {
        delete [] container;
    }

    container = new A[m_capacity];

    for(unsigned int i = 0; i < m_count; i++)
    {
        container[i] = vct->container[i];
    }

    return  *this;
}

template <typename A>
CVector<A>& CVector<A>::operator+=(const CVector &vct)
{
    unsigned int old_m_count = m_count;
    m_count += vct.m_count;
    m_capacity += vct.m_capacity;
    A *temp = new A[m_capacity];

    int k = 0;
    for(unsigned int i = 0; i < old_m_count; i++, k++)
    {
        temp[k] = container[i];

    }
    for(unsigned int i = 0; i < vct.m_count; i++, k++)
    {
        temp[k] = vct.container[i];
    }

    delete [] container;
    container = temp;

    return *this;
}

template <typename A>
CVector<A>& CVector<A>::operator+=(const A &str)
{

    if(m_count == m_capacity)
    {
        m_capacity *= 2;
        A *temp = new A[m_capacity];
        for(unsigned int i = 0; i < m_count; i++)
        {
            temp[i] = container[i];
        }
        delete [] container;
        container = temp;
    }
    container[m_count] = str;
    m_count++;

    return *this;
}

template <typename A>
bool CVector<A>::operator==(const CVector &vct)
{
    bool coincidence = false;
    unsigned find_coincidence = 0;

    if(m_count == vct.m_count)
    {
        for(unsigned i = 0; i < m_count; i++)
        {
            if(container[i] == vct.container[i])
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
            if(container[i] == vct.container[i])
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
    unsigned search_m_count = 0;

    bool less = false;

    if(m_count <= vct.m_count)
    {
        for(unsigned i = 0; i < m_count; i++)
        {
            if(container[i] <= vct.container[i])
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
    unsigned search_m_count = 0;
    bool more = false;
    if(m_count >= vct.m_count)
    {
        for(unsigned i = 0; i < m_count; i++)
        {
            if(container[i] >= vct.container[i])
            {
                search_m_count++;
            }
            else
                break;
        }

        if(search_m_count >= m_count)
        {
            more = true;
        }
    }

    return more;
}

template <typename A>
CVector<A> CVector<A>::operator+(const CVector &vct) const
{
    CVector vct1;

    vct1.m_count = m_count + vct.m_count;
    vct1.m_capacity = m_capacity + vct.m_capacity;
    delete [] vct1.container;
    vct1.container = new A[vct1.m_capacity];


    for(unsigned i = 0; i < m_count; i++)
    {
        vct1.container[i] = container[i];
    }

    for(unsigned i = m_count, j = 0; i < vct1.m_count; i++, j++)
    {
        vct1.container[i] = vct.container[j];
    }

    return vct1;
}

template <typename A>
CVector<A> CVector<A>::operator+(const A &str) const
{
    CVector vct;
    vct.m_count = m_count;
    vct.m_capacity = m_capacity;
    if(m_count == m_capacity)
    {
        vct.m_capacity *= 2;
        A *temp = new A[vct.m_capacity];
        for(unsigned int i = 0; i < m_count; i++)
        {
            temp[i] = container[i];
        }

        vct.container = temp;

    }
    vct.container[m_count] = str;
    vct.m_count++;
    return vct;
}

template <typename A>
A& CVector<A>::operator[] (int n)
{
    if(n < 0)
    {
        cout << "Enter the number \'n\' from 0 " << " to " << m_count - 1 << " ." << endl;
    }

    unsigned n1 = n;

    if(n1 > m_count - 1)
    {
        cout << "Enter the number \'n\' from 0 " << " to " << m_count - 1 << " ." << endl;
    }

    return container[n];
}

template <typename A>
bool CVector<A>::operator>(const CVector &vct)
{
    bool more = false;
    if(m_count > vct.m_count)
    {
        more = true;
    }
    return more;
}

template <typename A>
bool CVector<A>::operator<(const CVector &vct)
{
    int less = false;
    if(m_count < vct.m_count)
    {
        less = true;
    }
    return less;
}




























