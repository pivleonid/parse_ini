#include "CFile.h"
#include "CVector.cpp"
#include "CMap.h"
#include "CMap.cpp"

template <typename A, typename B>
CFile<A, B>::CFile()
{
    file_path   = NULL;
    array_chars = NULL;
    container = NULL;
    m_count_ch = 0;
    m_size_container = 0;
    m_count_container = 0;
}


template <typename A, typename B>
CFile<A, B>::~CFile()
{
    delete file_path;
    delete array_chars;
    m_count_ch = 0;
    m_size_container = 0;
    m_count_container = 0;
}


template <typename A, typename B>
void CFile<A, B>::analyze_file()
{
    //подсчёт количества секций
    int i = 0;
    bool new_section = false;
    for (; i < m_count_ch; i++)
    {
        if(array_chars[i] == '[')
        {
            m_size_container++;
        }
    }
    container = new Node[m_size_container];
    i = 0;
    int j = 0;
    char *temp_array_chars = new char[20];
    for(; i  < m_count_ch; i++)
    {
        temp_array_chars[j] = array_chars[i];
        j++;
        if(array_chars[i] == '[')
        {
            new_section = true;
        }
        if(array_chars[i] == '\n')
        {
            get_value(temp_array_chars, new_section);
            j = 0;
            delete [] temp_array_chars;
            new_section = false;
        }
    }

}

template <typename A, typename B>
void CFile<A, B>::get_value(char *temp_array_chars, bool new_section)
{

    CString section;
    CString key;
    CString value;
    int i = 0;
    if(temp_array_chars[i] == '[')
    {
        i++;
        while(temp_array_chars[i] != ']')
        {
            section.push_back(temp_array_chars[i]);
            i++;
        }
        container[m_count_container].section = section;
    }
    else
    {
        while (temp_array_chars[i] != '=')
        {
            if(isdigit(temp_array_chars[i]) || isalpha(temp_array_chars[i]))
            {
                key.push_back(temp_array_chars[i]);
            }
            i++;
        }
        while (temp_array_chars[i] != '\n')
        {
            if(isdigit(temp_array_chars[i]) || isalpha(temp_array_chars[i]))
            {
                value.push_back(temp_array_chars[i]);
            }
            i++;
        }
        container[m_count_container].key_value.add_pair(key, value);
    }
    if(new_section == true)
    {
        m_count_container++;
    }
}

/*template <typename A, typename B>
char *CFile<A, B>::get_data()
{

    int i = 0;
    while(i < m_size_container)
    {
        for(int j = 0; j < container[i]->comment.size(); j++)
        {

        }
    }
}*/




















