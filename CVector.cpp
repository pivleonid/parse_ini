#include "CVector.h"
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

CVector::CVector()
{
    m_count    = 0;

    m_capacity = 1;

    container  = new CString[m_capacity];
}

CVector::CVector(int n)
{
    m_count    = 0;

    m_capacity = n;

    container  = new CString[m_capacity];
}

CVector::~CVector()
{
    m_count    = 0;
    m_capacity = 0;
    delete [] container;
}

CVector& CVector::operator=(const CVector &vct)
{
    if(this == &vct)
        return *this;

    m_count = vct.m_count;

    m_capacity = vct.m_capacity;

    if(m_capacity != 1)
    {
        delete [] container;
    }

    container = new CString[m_capacity];

    for(unsigned int i = 0; i < m_count; i++)
    {
        container[i] = vct.container[i];
    }

    return *this;
}

CVector& CVector::operator=(const CVector *vct)
{
    if(this == vct)
        return *this;

    m_count = vct->m_count;

    m_capacity = vct->m_capacity;

    if(m_capacity != 1)
    {
        delete [] container;
    }

    container = new CString[m_capacity];

    for(unsigned int i = 0; i < m_count; i++)
    {
        container[i] = vct->container[i];
    }

    return  *this;
}

CVector& CVector::operator+=(const CVector &vct)
{
    unsigned int old_m_count = m_count;
    m_count += vct.m_count;

    if(m_capacity <= m_count)
    {
        m_capacity = vct.m_capacity;
    }

    CString *temp = new CString[m_capacity];

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

CVector& CVector::operator+=(const CString &str)
{

    if(m_count == m_capacity)
    {
        m_capacity *= 2;
    }

    CString *temp = new CString[m_capacity];

    for(unsigned int i = 0; i < m_count; i++)
    {
        temp[i] = container[i];
    }

    temp[m_count] = str;

    delete [] container;

    container = temp;

    m_count++;

    return *this;
}

bool CVector::operator==(const CVector &vct)
{
    unsigned search_m_count = 0;

    bool find_symbol = false;

    if(m_count == vct.m_count)
    {
        for(unsigned i = 0; i < m_count; i++)
        {
            for(unsigned j = 0; j < vct.m_count; j++)
            {
                if(container[i].m_size == vct.container[j].m_size)
                {
                    search_m_count++;
                    break;
                }
            }

        }

        if(search_m_count == m_count - 1)
        {
            for(unsigned i = 0; i < m_count; i++)
            {
                for(unsigned j = 0; j < vct.m_count; j++)
                {
                    if(container[i].m_size == vct.container[j].m_size)
                    {
                        for(int k = 0; k < vct.container[j].m_size; k++)
                        {
                            if(container[i].m_word[k] == vct.container[j].m_word[k])
                            {
                                find_symbol = true;
                            }
                        }

                    }
                }

            }
        }
    }

    return find_symbol;
}

bool CVector::operator!=(const CVector &vct)
{
    unsigned search_m_count = 0;

    bool dismatch = true;

    if(m_count == vct.m_count)
    {
        for(unsigned i = 0; i < m_count; i++)
        {
            for(unsigned j = 0; j < vct.m_count; j++)
            {
                if(container[i].m_size == vct.container[j].m_size)
                {
                    search_m_count++;
                    break;
                }
            }

        }

        if(search_m_count == m_count - 1)
        {
            for(unsigned i = 0; i < m_count; i++)
            {
                for(unsigned j = 0; j < vct.m_count; j++)
                {
                    if(container[i].m_size == vct.container[j].m_size)
                    {
                        for(int k = 0; k < vct.container[j].m_size; k++)
                        {
                            if(container[i].m_word[k] == vct.container[j].m_word[k])
                            {
                                dismatch = false;
                            }
                        }

                    }
                }

            }
        }
    }

    return dismatch;
}

bool CVector::operator<=(const CVector &vct)
{
    unsigned search_m_count = 0;

    bool less = false;

    if(m_count <= vct.m_count)
    {
        for(unsigned i = 0; i < m_count; i++)
        {
            for(unsigned j = 0; j < vct.m_count; j++)
            {
                if(container[i].m_size == vct.container[j].m_size)
                {
                    search_m_count++;
                    break;
                }
            }

        }

        if(search_m_count == m_count - 1)
        {
            for(unsigned i = 0; i < m_count; i++)
            {
                for(unsigned j = 0; j < vct.m_count; j++)
                {
                    if(container[i].m_size == vct.container[j].m_size)
                    {
                        for(int k = 0; k < vct.container[j].m_size; k++)
                        {
                            if(container[i].m_word[k] == vct.container[j].m_word[k])
                            {
                                less = true;
                            }
                        }

                    }
                }

            }
        }
    }

    return less;
}

bool CVector::operator>=(const CVector &vct)
{
    unsigned search_m_count = 0;

    bool more = false;

    if(m_count >= vct.m_count)
    {
        for(unsigned i = 0; i < m_count; i++)
        {
            for(unsigned j = 0; j < vct.m_count; j++)
            {
                if(container[i].m_size == vct.container[j].m_size)
                {
                    search_m_count++;
                    break;
                }
            }

        }

        if(search_m_count == m_count - 1)
        {
            for(unsigned i = 0; i < m_count; i++)
            {
                for(unsigned j = 0; j < vct.m_count; j++)
                {
                    if(container[i].m_size == vct.container[j].m_size)
                    {
                        for(int k = 0; k < vct.container[j].m_size; k++)
                        {
                            if(container[i].m_word[k] == vct.container[j].m_word[k])
                            {
                                more = true;
                            }
                        }

                    }
                }

            }
        }
    }

    return more;
}

const CVector& CVector::operator+(const CVector &vct) const
{
    CVector vct1;

    vct1.m_count = m_count + vct.m_count - 1;

    vct1.m_capacity = m_capacity + vct.m_capacity;

    delete [] vct1.container;

    vct1.container = new CString[vct1.m_capacity];


    for(unsigned i = 0; i < m_count; i++)
    {
        vct1.container[i] = container[i];
    }

    for(unsigned i = m_count, j = 0; i < vct.m_count; i++, j++)
    {
        vct1.container[i] = vct.container[i];
    }

    const CVector *temp = &vct1;

    return *temp;
}

const CVector& CVector::operator+(const CString &str) const
{
    CVector vct;
    vct.m_count = m_count;

    if(m_count == m_capacity)
    {
        vct.m_capacity *= 2;
    }

    delete [] vct.container;

    vct.container = new CString[vct.m_capacity];

    for(unsigned i = 0; i < m_count; i++)
    {
        vct.container[i] = container[i];
    }

    vct.container[m_count] = str;

    vct.m_count++;

    const CVector *temp = &vct;

    return *temp;
}

CString& CVector::operator[] (int n)
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

void CVector::push_back(const CString &str)
{
    if(m_count == m_capacity)
    {
        m_capacity *= 2;

        CString *temp = new CString[m_capacity];

        for(unsigned int i = 0; i < m_count; i++)
        {
            temp[i] = container[i];
        }

        delete [] container;

        container = temp;
    }

    container[m_count] = str;

    m_count++;
}

void CVector::show()
{
    for(unsigned i = 0; i < m_count; i++)
    {
        for(int j = 0; j < container[i].m_size; j++)
        {
            cout << container[i].m_word[j];
        }
        cout << endl;
    }
    cout << endl;
}

void CVector::push_front(const CString &str)
{
    if(m_count == m_capacity)
    {
        m_capacity *= 2;

        CString *temp = new CString[m_capacity];

        temp[0] = str;

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
        CString *temp = new CString[m_capacity];

        temp[0] = str;

        for(unsigned int i = 1, j = 0; i < m_count; i++, j++)
        {
            temp[i] = container[j];
        }

        delete [] container;

        container = temp;

        m_count++;
    }
}

int CVector::size()
{
    if(m_capacity == 1 && container[0].m_word[0] == '\0')
    {
        return 0;
    }

    else
        return m_capacity;
}

bool CVector::is_empty()
{
    bool empty = true;

    if(m_capacity == 1 && container[0].m_word[0] == '\0')
    {
        empty = true;
    }

    else
    {
        empty = false;
    }

    return empty;
}

CString& CVector::at(int n)
{
    if(n < 0)
    {
        cout << "Enter the \'n\' from 0 to " << m_count << " ." << endl;

        return container[0];
    }

    unsigned int n1 = n;

    if(n1 > m_count)
    {
        cout << "Enter the \'n\' from 0 to " << m_count << " ." << endl;

        return container[0];
    }

    if(n >= 0 && n1 <= m_count)
    {
        /*cout << container[n].m_size << endl;

        for(int i = 0; i < container[n].m_size; i++)
        {
            cout << container[n].m_word[i];
        }

        cout << endl;*/

        return container[n];
    }
}

CString& CVector::front()
{
    if(m_capacity == 1 && container[0].m_word[0] == '\0')
    {
        cout << "Add the object CString in CVector." << endl;

        return container[0];
    }

    else
    {
        /*cout << container[0].m_size << endl;

        for(int i = 0; i < container[0].m_size; i++)
        {
            cout << container[0].m_word[i];
        }

        cout << endl;*/

        return container[0];
    }


}

CString& CVector::back()
{
    if(m_capacity == 1 && container[0].m_word[0] == '\0')
    {
        cout << "Add the object CString in CVector." << endl;
        return container[0];
    }

    else
    {
        /*cout << container[m_count - 1].m_size << endl;

        for(int i = 0; i < container[m_count - 1].m_size; i++)
        {
            cout << container[m_count - 1].m_word[i];
        }

        cout << endl;*/
        return container[m_count - 1];
    }


}

CString CVector::pop_front()
{
    CString first;
    if(m_capacity == 1 && container[0].m_word[0] == '\0')
    {
        cout << "Add the object CString in CVector." << endl;
    }

    else
    {
        /*cout << container[0].m_size << endl;

        for(int i = 0; i < container[0].m_size; i++)
        {
            cout << container[0].m_word[i];
        }

        cout << endl;*/

        first.push_back(container[0]);

        CString *temp = new CString[m_capacity];
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

CString CVector::pop_back()
{
    CString last;
    if(m_capacity == 1 && container[0].m_word[0] == '\0')
    {
        cout << "Add the object CString in CVector." << endl;
    }

    else
    {
        /*cout << container[m_count - 1].m_size << endl;

        for(int i = 0; i < container[m_count - 1].m_size; i++)
        {
            cout << container[m_count - 1].m_word[i];
        }

        cout << endl;*/

        last.push_back(container[m_count - 1]);

        CString *temp = new CString[m_capacity];
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

CVector& CVector::erase(unsigned int first, unsigned int last)
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
            CString *temp = new CString[m_capacity];

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
            CString *temp = new CString[m_capacity];

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
            CString *temp = new CString[m_capacity];

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
            CString *temp = new CString[m_capacity];

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

void CVector::resize(int n)
{
    m_capacity = n;
}

void CVector::clear()
{
    delete [] container;

    m_capacity = 1;

    m_count = 1;
}

int CVector::find(const CString &str)
{
    //размер str
    int count = 0;
    //номер с которого начинается первое совпадение
    int number = 0;
    //количество совпадений
    int n_word = 0;
    //если было совпадение
    bool coincidence = false;

    for(unsigned i = 0; i < m_count; i++)
    {
        if(str.m_size == container[i].m_size)
        {
            for(int j = 0; j < container[i].m_size; j++)
            {
                if(str.m_word[j] == container[i].m_word[j])
                {
                    count++;
                }
                if(count == str.m_size)
                {
                    number = i;

                    coincidence = true;

                    break;
                }
            }
        }
    }
    if(coincidence == true)
    {
        for(unsigned i = 0; i < m_count; i++)
        {
            if(str.m_size == container[i].m_size)
            {
                for(int j = 0; j < container[i].m_size; j++)
                {
                    if(str.m_word[j] == container[i].m_word[j])
                    {
                        count++;
                    }

                    else
                    {
                        count = 0;

                        break;
                    }

                    if(count == str.m_size)
                    {
                        n_word++;
                    }
                }
             }
        }
    }


    //если ни разу не совпало вывести предупреждение
    else if(coincidence == false)
    {
        cout << "Enter the correct string for search." << endl;
    }

    //если совпадений несколько вывести, то сколько раз
    if(n_word > 1)
    {
        cout << "From the symbol number " << number << " the string contains word \'";
        for(int i = 0; i < str.m_size - 1; i++)
        {
            cout << str.m_word[i];
        }
        cout << "\' " << n_word << " times." << endl;
    }

    return number;
}

int CVector::rfind(const CString &str)
{
    //размер str
    int count = 0;
    //номер с которого начинается первое совпадение
    int number = 0;
    //количество совпадений
    int n_word = 0;
    //если было совпадение
    bool coincidence = false;
    for(int i = m_count; i > -1; i--)
    {
        if(str.m_size == container[i].m_size)
        {
            for(int j = 0; j < container[i].m_size; j++)
            {
                if(str.m_word[j] == container[i].m_word[j])
                {
                    count++;
                }
                if(count == str.m_size)
                {
                    number = i;

                    coincidence = true;

                    break;
                }
            }
        }
    }
    if(coincidence == true)
    {
        for(unsigned i = m_count; i > 0; i--)
        {
            if(str.m_size == container[i].m_size)
            {
                for(int j = 0; j < container[i].m_size; j++)
                {
                    if(str.m_word[j] == container[i].m_word[j])
                    {
                        count++;
                    }

                    else
                    {
                        count = 0;

                        break;
                    }

                    if(count == str.m_size)
                    {
                        n_word++;
                    }

                }
            }
        }
    }

    //если ни разу не совпало вывести предупреждение
    else if(coincidence == false)
    {
        cout << "Enter the correct string for search." << endl;
    }

    //если совпадений несколько вывести, то сколько раз
    if(n_word > 1)
    {
        cout << "From the symbol number " << number << " the string contains word \'";
        for(int i = 0; i < str.m_size - 1; i++)
        {
            cout << str.m_word[i];
        }
        cout << "\' " << n_word << " times." << endl;
    }

    return number;
}











