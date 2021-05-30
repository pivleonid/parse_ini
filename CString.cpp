#include "CString.h"
#include <cstring>
#include <cmath>
#include <iostream>
#define empty_str '\0'

using namespace std;

CString::CString()
{
    m_size    = 1;
    m_word    = new char[m_size];
    m_word[0] = empty_str;
}

CString::CString(char s)
{
    m_size    = 2;
    m_word    = new char[m_size];
    m_word[0] = s;
    m_word[1] = empty_str;
}

CString::CString(const char *str)
{
    const char *temp = str;
    m_size = 1;
    while(*str++)
    {
        m_size++;
    }
    m_word = new char[m_size];
    for(unsigned i = 0; i < m_size - 1; i++)
    {
        m_word[i] = temp[i];
    }
    m_word[m_size - 1] = empty_str;
}

CString::CString(const CString &new_word)
{
    m_size = new_word.m_size;
    m_word = new char[m_size];
    for(unsigned i = 0; i < m_size; i++)
    {
        m_word[i] = new_word.m_word[i];
    }
}



CString::CString(int n)
{
    if(n == 0)
    {
        m_size    = 2;
        m_word    = new char[m_size];
        m_word[0] = n + '0';
        m_word[1] = empty_str;
    }
    else
    {
        int temp_n = n;
        //количество цифр в числе
        int number = 0;
        //определение количества цифр в числе
        while (temp_n)
        {
            temp_n = temp_n / 10;
            number++;
        }

        //массив для хранения цифр из которых состоит число
        int *cont = new int[number];
        int k = 0;
        //значение числа
        int value_n = n;
        //оставшиеся цифры для записи
        int rest = 0;
        //степень числа
        int rate = 0;
        for(int i = 1; i < number + 1; i++)
        {
            value_n = value_n / int(pow(10, number - i));
            //запись числа по одной цифре в массив
            cont[k] = value_n;
            //перезапись степени для нахождения оставшихся цифр
            rate = int(pow(10, number - i));
            //нахождение оставшихся цифр для записи
            rest = n % rate;
            value_n = rest;
            k++;
        }
        m_size = number + 1;
        m_word = new char[m_size];
        for(int i = 0; i < number; i++)
        {
            m_word[i] = cont[i] + '0';
        }
        m_word[m_size - 1] = empty_str;
        delete [] cont;
    }
}

CString::~CString()
{
    m_size = 0;
    delete [] m_word;
}

unsigned CString::size()
{
    return m_size;
}

char &CString::at(int n)
{
    try
    {
        if(n < 0)
        {
            throw 1;
        }
        else if(n > int(m_size) - 2)
        {
            throw 1.0;
        }
    }
    catch(int a)
    {
        return m_word[m_size - 1];
    }
    catch(double)
    {
        return m_word[m_size - 1];
    }
    return m_word[n];
}

char &CString::front()
{
    return m_word[0];
}

char &CString::back()
{
    try
    {
        if(m_size == 1 && m_word[0] == empty_str)
        {
            throw 1;
        }
    }
    catch (int a)
    {
        return m_word[m_size - 1];
    }
    return m_word[m_size - 2];
}

const char *CString::data()
{
    return this->m_word;
}

bool CString::empty()
{
    bool empty = false;
    if(m_size == 1 && m_word[0] == empty_str)
    {
        empty = true;
    }
    return empty;
}

CString & CString::erase(char s)
{
    int count = 0; //для подсчёта сколько раз символ встречается в строке
    for(unsigned i = 0; i < m_size - 1; i++)
    {
        if(m_word[i] == s)
        {
            count++;
        }
    }
    char MIN = m_word[0];
    char MAX = m_word[0];
    for(unsigned i = 0; i < m_size - 1; i++)
    {
        MAX < m_word[i] ? MAX = m_word[i] : MIN = m_word[i];
    }
    //если указанный символ не встречается в m_word, то выводим предупреждение
    try
    {
        if(count == 0)
        {
            throw "This string doesn't contain this symbol.";
        }
    }
    catch (const char *a)
    {
        cout << a << endl;
        cout << "Enter the from \'" << MIN << "\' to \'" << MAX <<"\'." << endl;
    }
    unsigned new_m_size = m_size - count;
    char *temp = new char[new_m_size];
    int k = 0;
    //если символ найден в m_word
    if(count > 0)
    {
        for(unsigned i = 0; i < m_size - 1; i++)
        {
            if(m_word[i] == s)
            {
                continue;
            }
            else
            {
                temp[k] = m_word[i];
                k++;
            }
        }
        delete [] m_word;
        m_size = new_m_size;
        m_word = new char[m_size];
        for(unsigned i = 0; i < m_size - 1; i++)
        {
            m_word[i] = temp[i];
        }
        m_word[m_size - 1] = empty_str;

    }
    delete [] temp;
    return *this;
}


CString & CString::erase(int fr, int lt, char f,  char l)
{
    try
    {
        if(fr < 0 || fr > int(m_size) - 3)
        {
            throw 1;
        }
        if(lt < 1 || lt > int(m_size) - 2)
        {
            throw 1.0;
        }
    }
    catch (int a)
    {
        cout << "The first number should be from 0 " << "to " << m_size - 3 << " ." << endl;
    }
    catch (double a)
    {
        cout << "The last number should be from 1 " << "to " << m_size - 2 << " ." << endl;
    }
    unsigned first = unsigned(fr);
    unsigned last  = unsigned(lt);
    if(f == '[' && l == ']')
    {
        if(first == 0 && last == m_size - 2)
        {
            delete [] m_word;
            m_size = 1;
            m_word = new char[m_size];
            m_word[0] = empty_str;
        }
        else if(first == 0 && last != m_size - 2)
        {
            unsigned new_m_size = m_size - last - 1;
            char *temp = new char[new_m_size];
            for(unsigned i = 0, j = last + 1; j < m_size; i++, j++)
            {
                temp[i] = m_word[j];
            }
            delete [] m_word;
            m_size = new_m_size;
            m_word = temp;
        }
        else if(first != 0 && last == m_size - 2)
        {
            unsigned new_m_size = first + 1;
            char *temp = new char[new_m_size];
            for(unsigned i = 0, j = 0; j < first; i++, j++)
            {
                temp[i] = m_word[j];
            }
            temp[new_m_size - 1] = empty_str;
            delete [] m_word;
            m_size = new_m_size;
            m_word = temp;
        }
        else if(first != 0 && last != m_size - 2)
        {
            unsigned new_m_size = m_size - last + 1;
            char *temp = new char[new_m_size];
            unsigned i = 0;
            for(unsigned j = 0; j < first; i++, j++)
            {
                temp[i] = m_word[j];
            }
            for(unsigned j = last + 1; j < m_size; i++, j++)
            {
                temp[i] = m_word[j];
            }
            delete [] m_word;
            m_size = new_m_size;
            m_word = temp;
        }
    }
    else if(f == '(' && l == ')')
    {
        if(first == 0 && last == m_size - 2)
        {
            unsigned new_m_size = 3;
            char *temp = new char[new_m_size];
            temp[0] = m_word[first];
            temp[1] = m_word[last];
            temp[2] = empty_str;
            delete [] m_word;
            m_size = new_m_size;
            m_word = temp;
        }
        else if(first == 0 && last != m_size - 2)
        {
            unsigned new_m_size = m_size - last + 1;
            char *temp = new char[new_m_size];
            temp[0] = m_word[first];
            for(unsigned i = 1, j = last; j < m_size; i++, j++)
            {
                temp[i] = m_word[j];
            }
            delete [] m_word;
            m_size = new_m_size;
            m_word = temp;
        }
        else if(first != 0 && last == m_size - 2)
        {
            unsigned new_m_size = m_size - last + first + 1;
            char *temp = new char[new_m_size];
            for(unsigned i = 0, j = 0; j < first + 1; i++, j++)
            {
                temp[i] = m_word[j];
            }
            temp[new_m_size - 2] = m_word[m_size - 2];
            temp[new_m_size - 1] = empty_str;
            delete [] m_word;
            m_size = new_m_size;
            m_word = temp;
        }
        else if(first != 0 && last != m_size - 2)
        {
            unsigned new_m_size = m_size - (last - first - 1);
            char *temp = new char[new_m_size];
            unsigned i = 0;
            for(unsigned j = 0; j < first + 1; i++, j++)
            {
                temp[i] = m_word[j];
            }
            for(unsigned j = last; j < m_size; i++, j++)
            {
                temp[i] = m_word[j];
            }
            delete [] m_word;
            m_size = new_m_size;
            m_word = temp;
        }
    }
    else if(f == '[' && l == ')')
    {
        if(first == 0 && last == m_size - 2)
        {
            unsigned new_m_size = 2;
            char *temp = new char[new_m_size];
            temp[0] = m_word[last];
            temp[1] = empty_str;
            delete [] m_word;
            m_size = new_m_size;
            m_word = temp;
        }
        else if(first == 0 && last != m_size - 2)
        {
            unsigned new_m_size = m_size - last;
            char *temp = new char[new_m_size];
            for(unsigned i = 0, j = last; j < m_size; i++, j++)
            {
                temp[i] = m_word[j];
            }
            delete [] m_word;
            m_size = new_m_size;
            m_word = temp;
        }
        else if(first != 0 && last == m_size - 2)
        {
            unsigned new_m_size = m_size - (last - first);
            char *temp = new char[new_m_size];
            unsigned i = 0;
            for(unsigned j = 0; j < first; i++, j++)
            {
                temp[i] = m_word[j];
            }
            for(unsigned j = last; j < m_size; i++, j++)
            {
                temp[i] = m_word[j];
            }
            delete [] m_word;
            m_size = new_m_size;
            m_word = temp;
        }
        else if(first != 0 && last != m_size - 2)
        {
            unsigned new_m_size = last - first + 1;
            char *temp = new char[new_m_size];
            unsigned i = 0;
            for(unsigned j = 0; j < first; i++, j++)
            {
                temp[i] = m_word[j];
            }
            for(unsigned j = last; j < m_size; i++, j++)
            {
                temp[i] = m_word[j];
            }
            delete [] m_word;
            m_size = new_m_size;
            m_word = temp;
        }
    }
    else if(f == '(' && l == ']')
    {
        if(first == 0 && last == m_size - 2)
        {
            unsigned new_m_size = 2;
            char *temp = new char[new_m_size];
            temp[0] = m_word[first];
            temp[1] = empty_str;
            delete [] m_word;
            m_size = new_m_size;
            m_word = temp;
        }
        else if(first == 0 && last != m_size - 2)
        {
            unsigned new_m_size = m_size - last;
            char *temp = new char[new_m_size];
            temp[0] = m_word[0];
            for(unsigned i = 1, j = last + 1; j < m_size; i++, j++)
            {
                temp[i] = m_word[j];
            }
            delete [] m_word;
            m_size = new_m_size;
            m_word = temp;
        }
        else if(first != 0 && last == m_size - 2)
        {
            unsigned new_m_size = m_size - (last - first);
            char *temp = new char[new_m_size];

            for(unsigned i = 0, j = 0; j < first + 1; i++, j++)
            {
                temp[i] = m_word[j];
            }
            temp[new_m_size - 1] = empty_str;
            delete [] m_word;
            m_size = new_m_size;
            m_word = temp;
        }
        else if(first != 0 && last != m_size - 2)
        {
            unsigned new_m_size = last - first + 1;
            char *temp = new char[new_m_size];
            unsigned i = 0;
            for(unsigned j = 0; j < first + 1; i++, j++)
            {
                temp[i] = m_word[j];
            }
            for(unsigned j = last + 1; j < m_size; i++, j++)
            {
                temp[i] = m_word[j];
            }
            delete [] m_word;
            m_size = new_m_size;
            m_word = temp;
        }
    }
    return *this;
}


void CString::clear()
{
    delete [] m_word;
    m_size = 1;
    m_word = new char[m_size];
    m_word[0] = empty_str;
}

void CString::push_front(char s)
{
    unsigned new_m_size = m_size + 1;
    char *temp = new char[new_m_size];
    for(unsigned i = 0, j = 1; j < new_m_size - 1; i++, j++)
    {
        temp[j] = m_word[i];
    }
    temp[0] = s;
    temp[new_m_size - 1] = empty_str;
    delete [] m_word;
    m_size = new_m_size;
    m_word = new char[m_size];
    for(unsigned i = 0; i < m_size; i++)
    {
        m_word[i] = temp[i];
    }
    delete [] temp;
}

void CString::push_front(const char *str)
{
    const char *temp = str;
    unsigned new_m_size = 0;
    while(*str++)
    {
        new_m_size++;
    }
    new_m_size = new_m_size + m_size;
    char *temp1 = new char[new_m_size];
    for(unsigned i = 0; i < new_m_size - m_size; i++)
    {
        temp1[i] = temp[i];
    }
    for(unsigned i = new_m_size - m_size, j = 0; i < new_m_size; i++, j++)
    {
        temp1[i] = m_word[j];
    }
    delete [] m_word;
    m_size = new_m_size;
    m_word = temp1;
}

void CString::push_front(const CString &str)
{
    unsigned new_m_size = m_size + str.m_size - 1;
    //temp для хранения 2 массивов
    char *temp = new char[new_m_size];
    for(unsigned k = 0, i = 0; i < str.m_size - 1; i++, k++)
    {
        temp[k] = str.m_word[i];
    }
    for(unsigned k = str.m_size - 1, i = 0; i < m_size; i++, k++)
    {
        temp[k] = m_word[i];
    }
    delete [] m_word;
    m_size = new_m_size;
    m_word = temp;
}

void CString::push_back(char s)
{
    unsigned new_m_size = m_size + 1;
    char *temp = new char[new_m_size];
    if(!this->empty())
    {
        for(unsigned i = 0; i < m_size - 1; i++)
        {
            temp[i] = m_word[i];
        }
    }
    temp[new_m_size - 2] = s;
    temp[new_m_size - 1] = empty_str;
    delete [] m_word;
    m_size = new_m_size;
    m_word = temp;
}

void CString::push_back(const char *str)
{
    const char *temp = str;
    unsigned new_m_size = 1;
    while(*str++)
    {
        new_m_size++;
    }
    new_m_size = new_m_size + m_size - 1;
    char *temp1 = new char[new_m_size];
    if(!this->empty())
    {
        for(unsigned i = 0; i < m_size - 1; i++)
        {
            temp1[i] = m_word[i];
        }
        for(unsigned i = m_size - 1, j = 0; i < new_m_size - 1; i++, j++)
        {
            temp1[i] = temp[j];
        }
        temp1[new_m_size - 1] = empty_str;
    }
    else
    {
        for(unsigned i = 0, j = 0; i < new_m_size - 1; i++, j++)
        {
            temp1[i] = temp[j];
        }
        temp1[new_m_size - 1] = empty_str;
    }
    delete [] m_word;
    m_size = new_m_size;
    m_word = temp1;
}

void CString::push_back(const CString &str)
{
    unsigned new_m_size = m_size + str.m_size - 1;
    //temp для хранения 2 массивов
    char *temp = new char[new_m_size];
    for(unsigned k = 0, i = 0; i < m_size - 1; i++, k++)
    {
        temp[k] = m_word[i];
    }
    for(unsigned k = m_size - 1, i = 0; i < str.m_size; i++, k++)
    {
        temp[k] = str.m_word[i];
    }
    delete [] m_word;
    m_size = new_m_size;
    m_word = temp;
}

void CString::pop_front()
{
    unsigned new_m_size = m_size - 1;
    char *temp = new char[new_m_size];
    for(unsigned i = 0, j = 1; j < m_size; i++, j++)
    {
        temp[i] = m_word[j];
    }
    delete [] m_word;
    m_size = new_m_size;
    m_word = temp;
}

void CString::pop_back()
{
    unsigned new_m_size = m_size - 1;
    char *temp = new char[new_m_size];
    for(unsigned i = 0; i < new_m_size; i++)
    {
        temp[i] = m_word[i];
    }
    temp[new_m_size - 1] = empty_str;
    delete [] m_word;
    m_size = new_m_size;
    m_word = temp;
}

bool CString::compare(const CString &str)
{
    unsigned count = 0;
    bool compare = false;
    if(str.m_size == m_size)
    {
        for(unsigned i = 0; i < m_size; i++)
        {
            if(str.m_word[i] == m_word[i])
            {
                count++;
            }
            else
            {
                break;
            }
        }
    }
    if(count == m_size)
    {
        compare = true;
    }
    return compare;
}

unsigned CString::find(char s)
{
    bool find = false;
    //номер с которого начинается первое совпадение
    unsigned number = 0;
    //количество совпадений
    unsigned count = 0;
    char MIN = m_word[0];
    char MAX = m_word[0];
    for(unsigned i = 0; i < m_size - 1; i++)
    {
        MAX < m_word[i] ? MAX = m_word[i] : MIN = m_word[i];
    }

    for(unsigned i = 0; i < m_size - 1; i++)
    {
        if(m_word[i] == s)
        {
            number = i;
            find = true;
            break;
        }
    }
    for(unsigned i = number + 1; i < m_size - 1; i++)
    {
        if(m_word[i] == s)
        {
            count++;
        }
    }
    //Если символ отсутствует в строке
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
    //если совпадений несколько, то вывести сколько раз
    /*if(count > 1)
    {
        cout << "From the position number " << number << " the string contains \'" << s << "\' " << count << " of times." << endl;
    }*/

    return number;
}

unsigned CString::find(const CString &str)
{
    int k = 0;
    //размер str
    unsigned count = 0;
    //номер с которого начинается первое совпадение
    unsigned number = 0;
    //количество совпадений
    unsigned n_word = 0;
    //если полностью совпало
    bool find = false;
    for(unsigned i = 0; i < m_size - 1; i++)
    {
        if(str.m_word[k] != m_word[i])
        {
             k = 0;
             count = 0;
             number = 0;
        }
        else if(str.m_word[k] == m_word[i])
        {
            if(k == 0)
            {
                number = i;
            }
            k++;
            count++;
        }
        if(count == str.m_size - 1)
        {
            find = true;
            break;
        }
    }
    if(find == true)
    {
        k = 0;
        count = 0;
        for(unsigned i = number; i < m_size - 1; i++)
        {
            if(str.m_word[k] != m_word[i])
            {
                 k = 0;
                 count = 0;
            }
            else if(str.m_word[k] == m_word[i])
            {
                k++;
                count++;
            }
            if(count == str.m_size - 1)
            {
                n_word++;
                count = 0;
                k = 0;
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
    catch (int a)
    {
        return 0;
    }
    //если совпадений несколько вывести, то сколько раз
    /*if(n_word > 1)
    {
        cout << "From the symbol number " << number << " the string contains word \'";
        for(unsigned i = 0; i < str.m_size - 1; i++)
        {
            cout << str.m_word[i];
        }
        cout << "\' " << n_word << " times." << endl;
    }*/
    return number;
}

unsigned CString::rfind(char s)
{
    bool rfind = false;
    //номер с которого начинается первое совпадение
    unsigned number = 0;
    //количество совпадений
    unsigned count = 0;
    char MIN = m_word[0];
    char MAX = m_word[0];
    for(unsigned i = 0; i < m_size - 1; i++)
    {
        MAX < m_word[i] ? MAX = m_word[i] : MIN = m_word[i];
    }

    for(int i = int(m_size) - 2; i >= 0; i--)
    {
        if(m_word[i] == s)
        {
            number = i;
            rfind = true;
            break;
        }
    }
    for(int i = int(m_size) - 2; i >= 0; i--)
    {
        if(m_word[i] == s)
        {
            count++;
        }
    }

    //Если символ отсутствует в строке
    try
    {
        if(rfind == false)
        {
            throw 0;
        }
    }
    catch (int a)
    {
        return 0;
    }

    //если совпадений несколько, то вывести сколько раз
    /*if(count > 1)
    {
        cout << "From the position number " << number << " the string contains \'" << s << "\' " << count << " of times." << endl;
    }*/

    return number;
}

unsigned CString::rfind(const CString &str)
{
    unsigned k = str.m_size - 2;
    //размер str
    unsigned count = 0;
    //номер с которого начинается первое совпадение
    unsigned number = 0;
    //количество совпадений
    unsigned n_word = 0;
    //если полностью совпало
    int rfind = false;

    for(int i = int(m_size) - 2; i >= 0; i--)
    {
        if(str.m_word[k] != m_word[i])
        {
             k = str.m_size - 2;
             count = 0;
             number = 0;
        }
        else if(str.m_word[k] == m_word[i])
        {
            if(k == str.m_size - 2)
            {
                number = i;
            }
            k--;
            count++;
        }
        if(count == str.m_size - 1)
        {
            rfind = true;
            break;
        }
    }

    if(rfind == true)
    {
        k = str.m_size - 2;
        count = 0;
        for(int i = number; i >= 0; i--)
        {
            if(str.m_word[k] != m_word[i])
            {
                 k = str.m_size - 2;
                 count = 0;
            }
            else if(str.m_word[k] == m_word[i])
            {
                k--;
                count++;
            }
            if(count == str.m_size - 1)
            {
                 n_word++;
                 count = 0;
                 k = str.m_size - 2;
            }
        }

    }
    //если ни разу не совпало вывести предупреждение
    try
    {
        if(rfind == false)
        {
            throw 0;
        }
    }
    catch (int a)
    {
        return 0;
    }
    //если совпадений несколько, то вывести сколько раз
    /*if(n_word > 1)
    {
        cout << "From the symbol number " << number << " the string contains word \'";
        for(unsigned i = 0; i < str.m_size - 1; i++)
        {
            cout << str.m_word[i];
        }
        cout << "\' " << n_word << " times." << endl;
    }*/

    return number;
}

int CString::stoi()
{
    //количество цифр
    int count = 0;
    //степень числа
    int rate = 0;
    //итоговое число
    int number = 0;
    //на тот случай если первая цифра 0
    bool f_zero = false;

    //временный массив для перевода из char в int
    unsigned new_m_size = m_size - 1;
    int *temp = new int[new_m_size];
    if(m_word[0] == '0')
    {
        f_zero = true;
    }

    if(f_zero == false)
    {
        for(unsigned i = 0; i < m_size - 1; i++)
        {
            if(m_word[i] >= '0' && m_word[i] <= '9')
            {
                count++;
            }
            //предпреждение если в строке не число типа int
            else
            {
                count = 0;
                break;
            }

        }
    }
    if(count > 0)
    {
        //вычисление степени числа и заполнение массива типа int
        for(int i = 0;  i < count; i++)
            {
                temp[i] = m_word[i] - '0';
                rate++;
            }

        //создание числа
        for(int k = 1, i = 0; i < count; i++, k++)
        {
            number += temp[i] * int(pow(10, rate - k));
        }
    }
    try
    {
        if(count == 0)
        {
            throw 0;
        }
    }
    catch (int a)
    {
        return a;
    }
    delete [] temp;
    return number;
}

double CString::stof()
{
    //целое значение конечного результата
    int number = 0;
    //конечный результат
    double number1 = 0;
    //количество цифр после точки
    int after_dot = 0;
    //для проверки если точек несколько
    int f_dot = 0;
    //для сигнала что точка найдена
    int dot = 0;
    //для проверки что строка корректна
    bool good = false;
    //общее количество цифр
    int count = 0;

    //Анализ массива на предмет корректности
    for(unsigned i = 0; i < m_size - 1; i++)
    {
        if(m_word[i] >= '0' && m_word[i] <= '9')
        {
            good = true;
            count++;
            continue;
        }
        else if(m_word[i] == ',' || m_word[i] == '.')
        {
            f_dot++;
            if(f_dot > 1)
            {
                good = false;
                break;
            }
            continue;
        }
        else if (m_word[i] < '0' || m_word[i] > '9')
        {
            good = false;
            break;
        }
    }

    //Также если точка отсуствует строка не корректна
    if(f_dot == 0)
    {
        good = false;
    }

    int *temp =new int[count];
    //Если строка корректна, то
    if (good == true)
    {
        int l = 0;
        for(int i = 0;  i < count + 1; i++)
        {
            //записываем значения во временный массив для создания числа
            if(m_word[i] >= '0' && m_word[i] <= '9')
            {
                temp[l] = m_word[i] - '0';
                l++;
            }
            //находим точку
            else if(m_word[i] == ',' || m_word[i] == '.')
            {
                dot = 1;
                continue;
            }
            //подсчитываем количество цифр после точки
            if(dot == 1)
            {
                after_dot++;
            }
        }
        //Создаём число:
        for(int k = 1, i = 0; i < count; i++, k++)
        {
            number += temp[i] * (pow(10,count - k));
        }
        number1 = number / (pow(10, after_dot));
    }
    //если строка не корректна, выводим предупреждение
    try
    {
        if(good == false)
        {
            throw 0;
        }
    }
    catch (int a)
    {
        return a;
    }
    delete [] temp;
    return number1;
}

int CString::stoi(const CString &str)
{
    //общее количество цифр
    int count = 0;
    //степень числа
    int rate = 0;
    //конечный результат
    int number = 0;
    //на тот случай если первый символ окажется 0
    bool f_zero = false;

    delete [] m_word;
    m_size = str.m_size;
    m_word = new char[m_size];
    for(unsigned i = 0; i < m_size; i++)
    {
        m_word[i] = str.m_word[i];
    }

    int new_m_size = str.m_size - 1;
    int *temp = new int [new_m_size];

    //проверка на первый нулевой символ
    if(m_word[0] == '0')
    {
        f_zero = true;
    }

    //если пройдена продолжаем
    if(f_zero == false)
    {
        for(unsigned i = 0; i < m_size - 1; i++)
        {
            //проверка остальных значений массива
            if(m_word[i] >= '0' && m_word[i] <= '9')
            {
                count++;
            }
            //если массив не корректен выводим предупреждение
            else
            {
                count = 0;
                break;
            }

        }
    }
    //продолжаем если с массивом всё в порядке
    if(count > 0)
    {
        for(int i = 0;  i < count; i++)
        {
            temp[i] = m_word[i] - '0';
            rate++;
        }

        int k = 1;
        for(int i = 0; i < count; i++)
        {
            number += temp[i] * int(pow(10, rate - k));
            k++;
        }
    }
    try
    {
        if(count == 0)
        {
            throw 0;
        }
    }
    catch (int a)
    {
        return a;
    }
    delete [] temp;
    return number;
}

double CString::stof(const CString &str)
{
    //целое значение конечного результата
    int number = 0;
    //конечный результат
    double number1 = 0;
    //количество цифр после точки
    int after_dot = 0;
    //для проверки если точек несколько
    int f_dot = 0;
    //для сигнала что точка найдена
    bool dot = false;
    //для проверки что строка корректна
    bool good = false;
    //общее количество цифр
    int count = 0;


    delete [] m_word;
    m_size = str.m_size;
    m_word = new char[m_size];
    for(unsigned i = 0; i < m_size; i++)
    {
        m_word[i] = str.m_word[i];
    }

    //Анализ массива на предмет корректности
    for(unsigned i = 0; i < m_size - 1; i++)
    {
        if(m_word[i] >= '0' && m_word[i] <= '9')
        {
            good = true;
            count++;
            continue;
        }
        else if(m_word[i] == ',' || m_word[i] == '.')
        {
            f_dot++;
            if(f_dot > 1)
            {
                good = false;
                break;
            }
            continue;
        }
        else if (m_word[i] < '0' || m_word[i] > '9')
        {
            good = false;
            break;
        }
    }

    int *temp = new int[count];
    //Если строка корректна, то
    if (good == true)
    {
        int l = 0;
        for(int i = 0;  i < count + 1; i++)
        {
            //записываем значения во временный массив для создания числа
            if(m_word[i] >= '0' && m_word[i] <= '9')
            {
                temp[l] = m_word[i] - '0';
                l++;
            }

            //находим точку
            else if(m_word[i] == ',' || m_word[i] == '.')
            {
                dot = true;
                continue;
            }
            //подсчитываем количество цифр после точки
            if(dot == true)
            {
                after_dot++;
            }
        }
        //Создаём число:
        for(int k = 1, i = 0; i < count; i++, k++)
        {
            number += temp[i] * (pow(10, count - k));
        }
        number1 = number / (pow(10, after_dot));
    }

    //если строка не корректна, выводим предупреждение
    try
    {
        if(good == false)
        {
            throw 0;
        }
    }
    catch (int a)
    {
        return a;
    }
    delete [] temp;
    return number1;
 }

CString& CString::to_string(int n)
{

    int temp_n = n;
    //количество цифр в числе
    int number = 0;
    //определение количества цифр в числе
    while (temp_n)
    {
        temp_n = temp_n / 10;
        number++;
    }
    //массив для хранения цифр из которых состоит число
    int *cont = new int[number];
    //значение числа
    int value_n = n;
    //оставшиеся цифры для записи
    int rest = 0;
    //степень числа
    int rate = 0;
    for(int k = 0, i = 1; i < number + 1; i++, k++)
    {
        value_n = value_n / int(pow(10, number - i));
        //запись числа по одной цифре в массив
        cont[k] = value_n;
        //перезапись степени для нахождения оставшихся цифр
        rate = int(pow(10, number - i));
        //нахождение оставшихся цифр для записи
        rest = n % rate;
        value_n = rest;
    }

    delete [] m_word;
    m_size = number + 1;
    m_word = new char[m_size];
    for(int i = 0; i < number; i++)
    {
        m_word[i] = cont[i] + '0';
    }
    m_word[m_size - 1] = empty_str;
    delete [] cont;
    return *this;
}

CString& CString::operator=(const CString &str)
{
    if(this == &str)
    {
        return *this;
    }
    delete [] m_word;
    m_size = str.m_size;
    m_word = new char[m_size];
    for (unsigned i = 0; i < m_size; i++)
    {
        m_word[i] = str.m_word[i];
    }
    return *this;
}

CString& CString::operator=(const char *str)
{
    const char *temp = str;
    unsigned temp_m_size = 1;
    while(*str++)
    {
        temp_m_size++;
    }
    delete [] m_word;
    m_size = temp_m_size;
    m_word = new char[m_size];
    for(unsigned i = 0; i < m_size - 1; i++)
    {
        m_word[i] = temp[i];
    }
    m_word[m_size - 1] = empty_str;
    return *this;
}

CString & CString::operator=(char s)
{
    if(m_word[0] != empty_str)
    {
        delete [] m_word;
    }
    m_size = 2;
    m_word = new char[m_size];
    m_word[0] = s;
    m_word[1] = empty_str;
    return *this;
}

CString & CString::operator=(int n)
{
    int temp_n = n;
    //количество цифр в числе
    int number = 0;
    //определение количества цифр в числе
    while (temp_n)
    {
        temp_n = temp_n / 10;
        number++;
    }

    //массив для хранения цифр из которых состоит число
    int *cont = new int[number];
    int k = 0;
    //значение числа
    int value_n = n;
    //оставшиеся цифры для записи
    int rest = 0;
    //степень числа
    int rate = 0;
    for(int i = 1; i < number + 1; i++)
    {
        value_n = value_n / int(pow(10, number - i));
        //запись числа по одной цифре в массив
        cont[k] = value_n;
        //перезапись степени для нахождения оставшихся цифр
        rate = int(pow(10, number - i));
        //нахождение оставшихся цифр для записи
        rest = n % rate;
        value_n = rest;
        k++;
    }

    delete [] m_word;
    m_size = number + 1;
    m_word = new char[m_size];
    for(int i = 0; i < number; i++)
    {
        m_word[i] = cont[i] + '0';
    }
    m_word[m_size - 1] = empty_str;
    delete [] cont;
    return *this;
}

CString & CString::operator=(unsigned n)
{
    unsigned temp_n = n;
    //количество цифр в числе
    unsigned number = 0;
    //определение количества цифр в числе
    while (temp_n)
    {
        temp_n = temp_n / 10;
        number++;
    }

    //массив для хранения цифр из которых состоит число
    unsigned *cont = new unsigned[number];
    int k = 0;
    //значение числа
    int value_n = n;
    //оставшиеся цифры для записи
    int rest = 0;
    //степень числа
    int rate = 0;
    for(unsigned i = 1; i < number + 1; i++)
    {
        value_n = value_n / int(pow(10, number - i));
        //запись числа по одной цифре в массив
        cont[k] = value_n;
        //перезапись степени для нахождения оставшихся цифр
        rate = int(pow(10, number - i));
        //нахождение оставшихся цифр для записи
        rest = n % rate;
        value_n = rest;
        k++;
    }

    delete [] m_word;
    m_size = number + 1;
    m_word = new char[m_size];
    for(unsigned i = 0; i < number; i++)
    {
        m_word[i] = cont[i] + '0';
    }
    m_word[m_size - 1] = empty_str;
    delete [] cont;
    return *this;
}

bool CString::operator==(const CString &str)
{
    unsigned count = 0;
    if(m_size == str.m_size)
    {
        for(unsigned i = 0; i < m_size; i++)
        {
            if(m_word[i] == str.m_word[i])
            {
                count++;
            }
            else
                break;
        }
    }
    if(count == 0)
    {
        return false;
    }
    else if(count == m_size)
    {
        return true;
    }
    else
    {
        return false;
    }

}

char &CString::operator[](int n)
{
    return m_word[n];
}

CString& CString::operator+=(char s)
{
    unsigned new_m_size = m_size + 1;
    char *temp = new char[new_m_size];
    for(unsigned i = 0; i < m_size - 1; i++)
    {
        temp[i] = m_word[i];
    }
    temp[new_m_size - 2] = s;
    temp[new_m_size - 1] = empty_str;
    delete [] m_word;
    m_size = new_m_size;
    m_word = temp;
    return *this;
}

CString& CString::operator+=(const char *str)
{
    const char *temp0 = str;
    unsigned new_m_size = 0;
    while(*temp0++)
    {
        new_m_size++;
    }
    char *temp1 = new char[m_size];
    for(unsigned i = 0; i < m_size; i++)
    {
        temp1[i] = m_word[i];
    }
    unsigned temp_m_size = m_size;
    new_m_size += m_size;
    delete [] m_word;
    m_size = new_m_size;
    m_word = new char[m_size];
    for(unsigned i = 0; i < temp_m_size - 1; i++)
    {
        m_word[i] = temp1[i];
    }
    for(unsigned i = temp_m_size - 1, j = 0; i < m_size - 1; i++, j++)
    {
        m_word[i] = str[j];
    }
    m_word[m_size - 1] = empty_str;
    delete [] temp1;
    return *this;
}

CString& CString::operator+=(const CString &str)
{
    unsigned new_m_size = m_size + str.m_size - 1;
    char *temp = new char[new_m_size];
    for(unsigned k = 0, i = 0; i < m_size - 1; i++, k++)
    {
        temp[k] = m_word[i];
    }
    for(unsigned k = m_size - 1, i = 0; i < str.m_size; i++, k++)
    {
        temp[k] = str.m_word[i];
    }
    delete [] m_word;
    m_size = new_m_size;
    m_word = temp;
    return *this;
}

CString& CString::operator+(char s)
{
    unsigned new_m_size = m_size + 1;
    char *temp = new char[new_m_size];
    for(unsigned i = 0; i < m_size - 1; i++)
    {
        temp[i] = m_word[i];
    }
    temp[new_m_size - 2] = s;
    temp[new_m_size - 1] = empty_str;
    delete [] m_word;
    m_size = new_m_size;
    m_word = temp;
    return *this;
}

CString& CString::operator+(const char *str)
{
    const char *temp0 = str;
    unsigned new_m_size = 0;
    while(*temp0++)
    {
        new_m_size++;
    }
    char *temp1 = new char[m_size - 1];
    for(unsigned i = 0; i < m_size - 1; i++)
    {
        temp1[i] = m_word[i];
    }
    unsigned temp_m_size = m_size;
    new_m_size += m_size;
    delete [] m_word;
    m_size = new_m_size;
    m_word = new char[m_size];
    for(unsigned i = 0; i < temp_m_size - 1; i++)
    {
        m_word[i] = temp1[i];
    }
    for(unsigned i = temp_m_size - 1, j = 0; i < m_size - 1; i++, j++)
    {
            m_word[i] = str[j];
    }
    m_word[m_size - 1] = empty_str;
    delete [] temp1;
    return *this;
}

const char* operator+(const CString &str1, const CString &str2)
{
    unsigned new_m_size = str1.m_size + str2.m_size - 1;
    char *temp = new char[new_m_size];
    for(unsigned i = 0; i < str1.m_size - 1; i++)
    {
        temp[i] = str1.m_word[i];
    }
    for(unsigned i = str1.m_size - 1, j = 0; j < str2.m_size; i++, j++)
    {
        temp[i] = str2.m_word[j];
    }
    return temp;
}

bool CString::operator!=(const CString &str)
{
    unsigned count = 0;
    if(m_size == str.m_size)
    {
        for(unsigned i = 0; i < m_size; i++)
        {
            if(m_word[i] == str.m_word[i])
            {
                count++;
            }
            else
            {
                break;
            }
        }
    }
    if(count != m_size)
    {
        return true;
    }
    else
    {
        return false;
    }

}

bool CString::operator<=(const CString &str)
{
    unsigned count = 0;
    if(m_size <= str.m_size)
    {
        for(unsigned i = 0; i < m_size; i++)
        {
            if(m_word[i] == str.m_word[i])
            {
                count++;
            }
            else
            {
                break;
            }
        }
    }
    if(count <= str.m_size)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CString::operator>=(const CString &str)
{

    unsigned count = 0;
    if(m_size >= str.m_size)
    {
        for(unsigned i = 0; i < str.m_size; i++)
        {
            if(m_word[i] == str.m_word[i])
            {
                count++;
            }
            else
            {
                break;
            }
        }
    }
    if(count <= m_size)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CString::operator>(const CString &str)
{
    CString temp = str;
    const char *this_object  = this->data();
    const char *other_object = temp.data();
    bool more = false;
    if(strcmp(this_object, other_object) > 0)
    {
        more = true;
    }
    return more;
}

bool CString::operator<(const CString &str)
{
    CString temp = str;
    const char *this_object  = this->data();
    const char *other_object = temp.data();
    bool less = false;
    if(strcmp(this_object, other_object) < 0)
    {
        less = true;
    }
    return less;
}

/*CString CString::operator+(const CString &str)
{
    CString temp;
    unsigned new_m_size = m_size + str.m_size - 1;
    temp.m_size = new_m_size;
    for(unsigned i = 0; i < m_size - 1; i++)
    {
        temp.m_word[i] = m_word[i];
    }
    for(unsigned i = m_size - 1, j = 0; j < str.m_size; i++, j++)
    {
        temp.m_word[i] = str.m_word[j];
    }
    return temp;

}*/

/*CString& CString::to_string(double n)
{

    int temp = n;
    int after_dot = 0;
    int before_dot = 0;
    double rest = n - temp;
    int rest_int = 0;
    double rest_double = 0;
    //подсчёт количества знаков после запятой
    int count_nine = 0;
    int nine = 9;
    while(count_nine != 9)
    {
        rest_int = rest * 10;
        if(rest_int == nine)
        {
            count_nine++;
        }
        else
        {
            count_nine = 0;
        }
        rest_double = rest * 10 - rest_int;
        rest = rest_double;
    }
    //запись значения после запятой

    int rest_int = rest * int(pow(10, after_dot));

    while
    //вычисление количества знаков перед запятой
    while (temp)
    {
        temp = temp/10;
        before_dot++;
    }
    int new_m_size = after_dot + before_dot;
    //запись значения перед запятой
    int real = n - rest;
    int *cont = new int[new_m_size];
    int k = 0;
    int temp_real = real;
    int rate_real = 0;
    int rest_real = 0;
    for(int i = 1; i < before_dot + 1; i++)
    {
         temp_real = temp_real / int(pow(10, before_dot - i));
         cont[k] = temp_real;
         rate_real = int(pow(10, before_dot - i));
         rest_real = real % rate_real;
         temp_real = rest_real;
         k++;
    }
    int temp_rest = rest_int;
    int rate_rest = 0;
    int rest_rest = 0;
    for(int i = 1; i < after_dot + 1; i++)
    {
        temp_rest = temp_rest / int(pow(10, after_dot - i));
        cont[k] = temp_rest;
        rate_rest = int(pow(10, after_dot - i));
        rest_rest = rest_int % rate_rest;
        temp_rest = rest_rest;
        k++;
    }

    delete [] m_word;
    m_size = new_m_size + 1;
    m_word = new char[m_size];
    k = 0;
    for(int i = 0; i < m_size - 1; i++)
    {
        if(i == before_dot)
        {
            m_word[i] = '.';
            continue;
        }
        m_word[i] = cont[k] + '0';
        k++;
    }
    m_word[m_size - 1] = empty_str;
    delete [] cont;
    return *this;
}*/



























