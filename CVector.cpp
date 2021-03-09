#include "CVector.h"
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

CVector::CVector()
{
    m_count    = 1;
    m_capacity = 1;
    container  = new CString[m_capacity];
}

CVector::CVector(int n)
{
    m_count    = 1;
    m_capacity = n;
    container  = new CString[m_capacity];
}

CVector::~CVector()
{
    m_count    = 0;
    m_capacity = 0;
    delete [] container;
}

void CVector::push_back(const CString &str)
{
    if(m_count == m_capacity)
    {
        m_capacity *= 2;

        CString *temp = new CString[m_capacity];

        for(unsigned int i = 0; i < m_capacity / 2; i++)
        {
            temp[i] = container[i];
        }

        delete [] container;

        container = temp;
    }

    container[m_count] = str;
    m_count++;
}

void CVector::push_front(const CString &str)
{
    if(m_count == m_capacity)
    {
        m_capacity *= 2;

        CString *temp = new CString[m_capacity];

        temp[0] = str;

        for(unsigned int i = 1, j = 0; i < m_capacity / 2; i++, j++)
        {
            temp[i] = container[j];
        }

        delete [] container;

        container = temp;
    }
    else if(m_count < m_capacity)
    {
        CString *temp = new CString[m_capacity];

        temp[0] = str;

        for(unsigned int i = 1, j = 0; i < m_capacity; i++, j++)
        {
            temp[i] = container[j];
        }

        delete [] container;

        container = temp;
    }
}

int CVector::size()
{
    if(m_capacity > 1)
    {
        return m_capacity;
    }

    else
        return 0;
}

bool CVector::is_empty()
{
    bool empty = true;

    if(m_capacity > 1)
    {
        empty = false;

        return empty;
    }

    else
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

    else if(n1 >= 0 && n1 <= m_count)
    {
        cout << container[n].m_size << endl;

        for(int i = 0; i < container[n].m_size; i++)
        {
            cout << container[n].m_word[i];
        }

        cout << endl;

        return container[n];
    }
}

CString& CVector::front()
{
    if(m_capacity == 1)
    {
        cout << "Add the object CString in CVector." << endl;
    }

    else
    {
        cout << container[0].m_size << endl;

        for(int i = 0; i < container[0].m_size; i++)
        {
            cout << container[0].m_word[i];
        }

        cout << endl;
    }

    return container[0];
}

CString& CVector::back()
{
    if(m_capacity == 1)
    {
        cout << "Add the object CString in CVector." << endl;
    }

    else
    {
        cout << container[m_count - 1].m_size << endl;

        for(int i = 0; i < container[m_count - 1].m_size; i++)
        {
            cout << container[m_count - 1].m_word[i];
        }

        cout << endl;
    }

    return container[m_count - 1];
}

CVector& CVector::pop_front()
{
    CVector first;
    CVector *temp1 = &first;
    if(m_capacity == 1)
    {
        cout << "Add the object CString in CVector." << endl;
    }

    else
    {
        cout << container[0].m_size << endl;

        for(int i = 0; i < container[0].m_size; i++)
        {
            cout << container[0].m_word[i];
        }

        cout << endl;


        first.push_back(container[0]);

        CString *temp = new CString[m_capacity];
        for(unsigned int i = 0, j = 1; i < m_count; i++, j++)
        {
            temp[i] = container[j];
        }

        m_count--;

        delete [] container;

        container = temp;
    }

    return *temp1;
}
























