#include "CIni.h"
Content_of_section::Content_of_section()
{
    CString empty_name;
    CString empty_comment;
    CMap<CString, CVector<CString>> empty_key_value;

    CString key = 1; CString value = "B";
    CVector<CString> temp;
    temp.push_back(value);
    empty_key_value.add_pair(key, temp);
    temp.clear();

    key = 2; value = "A";
    temp.push_back(value);
    empty_key_value.add_pair(key, temp);
    temp.clear();

    key = 3; value = "C";
    temp.push_back(value);
    empty_key_value.add_pair(key, temp);
    temp.clear();
    m_name_section = empty_name;
    m_comment_section = empty_comment;
    m_key_value    = empty_key_value;

}

void Content_of_section::clear()
{
     m_name_section.clear();
     m_comment_section.clear();
     m_key_value.clear();
}

CIni::CIni()
{
    CString empty_name;
    CString empty_comment;
    CMap<CString, CVector<CString>> empty_key_value;

    CString key = 1; CString value = "B";
    CVector<CString> temp;
    temp.push_back(value);
    empty_key_value.add_pair(key, temp);
    temp.clear();

    key = 2; value = "A";
    temp.push_back(value);
    empty_key_value.add_pair(key, temp);
    temp.clear();

    key = 3; value = "C";
    temp.push_back(value);
    empty_key_value.add_pair(key, temp);
    temp.clear();

    Content_of_section temp_content;
    temp_content.m_name_section = empty_name;
    temp_content.m_comment_section = empty_comment;
    temp_content.m_key_value    = empty_key_value;
    m_data.push_back(temp_content);
}

void CIni::create_file(string &name_file)
{
    string format = ".ini";
    m_name_file = name_file + format;
    ofstream new_file(m_name_file.c_str());
}

void CIni::delete_file(string &name_file)
{
    string format = ".ini";
    m_name_file = name_file + format;
    remove(m_name_file.c_str());
}

void CIni::read_file(string &name_file)
{
    string format = ".ini";
    m_name_file = name_file + format;
    char ch;
    ifstream fin(m_name_file.c_str());
    CString temp;
    while(!fin.eof())
    {
        ch = fin.get();
        temp.push_back(ch);
        if(ch == '\n')
        {
            m_temp_container.push_back(temp);
            temp.clear();
        }
    }
    fin.close();

    analyze_file();
}

void CIni::analyze_file()
{
    Content_of_section temp_content_of_section;
    temp_content_of_section.m_key_value.clear();
    int count = 0;

    for(unsigned i = 0; i < m_temp_container.size(); i++)
    {

        if(m_temp_container.at(i).front() == '[')
        {
            if(count > 0)
            {
                if(m_data.at(0).m_name_section.empty())
                {
                    m_data.at(0) = temp_content_of_section;
                    temp_content_of_section.clear();
                }
                else
                {
                    m_data.push_back(temp_content_of_section);
                    temp_content_of_section.clear();
                }
            }
            m_temp_container.at(i).pop_front();
            m_temp_container.at(i).pop_back();
            m_temp_container.at(i).pop_back();
            temp_content_of_section.m_name_section = m_temp_container.at(i);
            count++;
        }
        else if(m_temp_container.at(i).front() == ';')
        {
            m_temp_container.at(i).pop_front();
            m_temp_container.at(i).pop_back();
            temp_content_of_section.m_comment_section = m_temp_container.at(i);
        }
        else if(m_temp_container.at(i).empty())
        {
            continue;
        }
        else if(m_temp_container.at(i).front() == '\t')
        {
            continue;
        }
        else if(m_temp_container.at(i).front() == '\n')
        {
            continue;
        }
        else if(m_temp_container.at(i).front() != '[' || m_temp_container.at(i).front() != ' ')
        {
             m_temp_container.at(i).erase(' ');
             unsigned start = m_temp_container.at(i).find('=');
             unsigned end = m_temp_container.at(i).find('\n');
             CString temp_key = m_temp_container.at(i);
             temp_key.erase(start, end);
             end = m_temp_container.at(i).find('=');
             m_temp_container.at(i).erase(0, end);

             CVector<CString> temp_vector_value;
             CString temp_value;
             while(m_temp_container.at(i).find(','))
             {
                unsigned start = m_temp_container.at(i).find(',');
                unsigned end = m_temp_container.at(i).find('\n');
                temp_value = m_temp_container.at(i);

                temp_vector_value.push_back(temp_value.erase(start, end));
                temp_value.clear();

                end = m_temp_container.at(i).find(',');
                m_temp_container.at(i).erase(0, end);
             }
             if(!m_temp_container.at(i).find(','))
             {
                 m_temp_container.at(i).pop_back();
                 temp_vector_value.push_back(m_temp_container.at(i));
             }
             temp_content_of_section.m_key_value.add_pair(temp_key, temp_vector_value);
             temp_key.clear();
             temp_vector_value.clear();
        }
    }
    if(count == 1)
    {
        if(m_data.at(0).m_name_section.empty())
        {
            m_data.at(0) = temp_content_of_section;
            temp_content_of_section.clear();
        }
        else
        {
            m_data.push_back(temp_content_of_section);
            temp_content_of_section.clear();
            m_temp_container.clear();
        }
    }
    else if(count > 1)
    {
        m_data.push_back(temp_content_of_section);
        temp_content_of_section.clear();
        m_temp_container.clear();
    }
}

void CIni::write_file(string &name_file)
{
    string format = ".ini";
    m_name_file = name_file + format;
    write_file_inner();
    ofstream fout(m_name_file.c_str(), ios_base::out | ios_base::app);
    char ch;
    for(unsigned i = 0; i < m_temp_container.size(); i++)
    {
        for(unsigned j = 0; j < m_temp_container.at(i).size(); j++)
        {
            if(m_temp_container.at(i).at(j) == '\0')
            {
                continue;
            }
            else
            {
                ch = m_temp_container.at(i).at(j);
                fout << ch;
            }
        }
    }

}

void CIni::clear()
{
    for(unsigned i = 0; i < m_data.size(); i++)
    {
        if(!m_data.at(i).m_name_section.empty())
        {
            m_data.at(i).m_name_section.clear();
            m_data.at(i).m_comment_section.clear();
            m_data.at(i).m_key_value.clear();
        }
    }
    m_data.clear();
    CMap<CString, CVector<CString>> empty_key_value;

    CString key = 1; CString value = "B";
    CVector<CString> temp;
    temp.push_back(value);
    empty_key_value.add_pair(key, temp);
    temp.clear();

    key = 2; value = "A";
    temp.push_back(value);
    empty_key_value.add_pair(key, temp);
    temp.clear();

    key = 3; value = "C";
    temp.push_back(value);
    empty_key_value.add_pair(key, temp);
    temp.clear();

    m_data.at(0).m_key_value = empty_key_value;
    m_temp_container.clear();

}

bool CIni::search_name_section(CString &name_section)
{
    bool find = false;
    for(unsigned i = 0; i < m_data.size(); i++)
    {
        if(m_data.at(i).m_name_section == name_section)
        {
            find = true;
            break;
        }
    }
    return find;
}

void CIni::write_file_inner()
{
    int k = 0;
    for(unsigned i = 0; i < m_data.size(); i++)
    {
        CString temp;
        temp = m_data.at(i).m_name_section;
        temp.push_front('[');
        temp.push_back(']');
        temp.push_back('\n');
        m_temp_container.push_back(temp);
        k++;
        if(!m_data.at(i).m_comment_section.empty())
        {
            temp.clear();
            m_temp_container.push_back(temp);
            m_temp_container.at(k) = m_data.at(i).m_comment_section;
            m_temp_container.at(k).push_front(';');
            m_temp_container.at(k).push_back('\n');
            k++;
        }
        temp.clear();
        CString key;
        for(unsigned node = 0; node < m_data.at(i).m_key_value.size(); node++, k++)
        {
            m_temp_container.push_back(temp);
            key = m_data.at(i).m_key_value.getKey(node);
            m_temp_container.at(k).push_back(key);
            m_temp_container.at(k).push_back(" = ");
            for(unsigned n = 0; n < m_data.at(i).m_key_value.getValue(key).size(); n++)
            {
                m_temp_container.at(k).push_back(m_data.at(i).m_key_value.getValue(key).at(n));
                m_temp_container.at(k).push_back(", ");
            }
            m_temp_container.at(k).pop_back();
            m_temp_container.at(k).pop_back();
            m_temp_container.at(k).push_back('\n');
        }
    }
}

bool CIni::add_name_section(CString &new_name)
{
    bool found = false;
    for(unsigned i = 0; i < m_data.size(); i++)
    {
        if(m_data.at(i).m_name_section != new_name)
        {
            continue;
        }
        else
        {
            found = true;
            break;
        }
    }
    if(!found)
    {
        if(m_data.at(0).m_name_section.empty())
        {
           m_data.at(0).m_name_section = new_name;
        }
        else
        {
            Content_of_section temp;
            temp.m_name_section = new_name;
            m_data.push_back(temp);
        }
    }
    return found;
}

bool CIni::change_name_section(CString &old_name, CString &new_name)
{
    bool found = false;
    for(unsigned i = 0; i < m_data.size(); i++)
    {
        if(m_data.at(i).m_name_section == old_name)
        {
            found = true;
            m_data.at(i).m_name_section = new_name;
            break;
        }
    }
    return found;
}

bool CIni::add_key_value(CString &name_section, CMap<CString, CVector<CString> > &key_value)
{
    bool found = false;
    unsigned num_section = 0;
    for(unsigned i = 0; i < m_data.size(); i++)
    {
        if(m_data.at(i).m_name_section == name_section)
        {
            found = true;
            num_section = i;
            break;
        }
    }
    if(found)
    {
        unsigned count = 0;
        CString key;
        CVector<CString> temp_vct;
        for(unsigned j = 1; j < m_data.at(num_section).m_key_value.size() + 1; j++)
        {
            key = j;
            if(m_data.at(num_section).m_key_value.getValue(key).size() == 1)
            {
                if(m_data.at(num_section).m_key_value.getValue(key).at(0) == 'B' && key == 1)
                {
                    count++;
                }
                else if(m_data.at(num_section).m_key_value.getValue(key).at(0) == 'A' && key == 2)
                {
                    count++;
                }
                else if(m_data.at(num_section).m_key_value.getValue(key).at(0) == 'C' && key == 3)
                {
                    count++;
                }
                else
                {
                    count = 0;
                    break;
                }
            }
            else
            {
                break;
            }
        }
        if(count == 3)
        {
            m_data.at(num_section).m_key_value.clear();
            m_data.at(num_section).m_key_value = key_value;
        }
        else
        {
            m_data.at(num_section).m_key_value = key_value;
        };

    }
    return found;
}

const char *CIni::get_comment_section(CString &name_section)
{
    bool found = false;
    unsigned num = 0;
    for(unsigned i = 0; i < m_data.size(); i++)
    {
        if(m_data.at(i).m_name_section == name_section)
        {
            found = true;
            num = i;
            break;
        }
    }
    try
    {
        if(found == false)
        {
            throw 1;
        }
    }
    catch (int a)
    {
        const char *empty = "\0";
        return empty;
    }
    return m_data.at(num).m_comment_section.data();
}

bool CIni::search_key(CString &name_section, CString &key)
{
    bool found_n_s = false;
    bool found_key = false;
    unsigned num = 0;
    for(unsigned i = 0; i < m_data.size(); i++)
    {
        if(m_data.at(i).m_name_section == name_section)
        {
            found_n_s = true;
            num = i;
            break;
        }
    }
    try
    {
        if(found_n_s == false)
        {
            throw 1;
        }
    }
    catch (int a)
    {
        return found_n_s;
    }
    if(found_n_s == true)
    {
        if(m_data.at(num).m_key_value.search(key))
        {
            found_key = true;
        }
    }
    try
    {
        if(found_key == false)
        {
            throw 1;
        }
    }
    catch (int a)
    {
        return found_key;
    }
    return found_key;
}

CVector<CString> &CIni::getValue(CString &name_section, CString &key)
{
    unsigned num = 0;
    for(unsigned i = 0; i < m_data.size(); i++)
    {
        if(m_data.at(i).m_name_section == name_section)
        {
            num = i;
            break;
        }
    }
    return m_data.at(num).m_key_value.getValue(key);
}

bool CIni::add_comment_section(CString &name_section, CString &new_comment)
{
    bool found = false;
    unsigned num_section = 0;
    for(unsigned i = 0; i < m_data.size(); i++)
    {
        if(m_data.at(i).m_name_section == name_section)
        {
            found = true;
            num_section = i;
            break;
        }
    }
    if(found)
    {
        m_data.at(num_section).m_comment_section = new_comment;
    }
    return found;
}

bool CIni::change_comment_section(CString & name_section, CString & new_comment)
{
    bool found = false;
    unsigned num_section = 0;
    for(unsigned i = 0; i < m_data.size(); i++)
    {
        if(m_data.at(i).m_name_section == name_section)
        {
            found = true;
            num_section = i;
            break;
        }
    }
    if(found)
    {
        m_data.at(num_section).m_comment_section = new_comment;
    }
    return found;
}

void CIni::show_all()
{
    for(unsigned i = 0; i < m_data.size(); i++)
    {
        cout << m_data.at(i).m_name_section.data() << endl;
        if(!m_data.at(i).m_comment_section.empty())
        {
            cout << m_data.at(i).m_comment_section.data() << endl;
        }
        CString key;
        for(unsigned node = 0; node < m_data.at(i).m_key_value.size(); node++)
        {
            key = m_data.at(i).m_key_value.getKey(node);
            cout << key.data() << " = ";
            for(unsigned k = 0; k < m_data.at(i).m_key_value.getValue(key).size(); k++)
            {
                cout << m_data.at(i).m_key_value.getValue(key).at(k).data() << ' ';
            }
            cout << endl;
        }
    }
}

bool CIni::delete_value(CString &name_section, CString &key)
{
    bool found = false;
    unsigned num_section = 0;
    for(unsigned i = 0; i < m_data.size(); i++)
    {
        if(m_data.at(i).m_name_section == name_section)
        {
            found = true;
            num_section = i;
            break;
        }
    }
    if(found)
    {
        if(m_data.at(num_section).m_key_value.search(key))
        {
            m_data.at(num_section).m_key_value.delete_key(key);
        }
    }
    return found;
}

bool CIni::delete_value(CString &name_section, CString &key, CString &value)
{
    bool found = false;
    unsigned num_section = 0;
    for(unsigned i = 0; i < m_data.size(); i++)
    {
        if(m_data.at(i).m_name_section == name_section)
        {
            found = true;
            num_section = i;
            break;
        }
    }
    if(found)
    {
        if(m_data.at(num_section).m_key_value.search(key))
        {
            CVector<CString> temp;
            temp = m_data.at(num_section).m_key_value.getValue(key);
            m_data.at(num_section).m_key_value.delete_key(key);
            for(unsigned j = 0; j < temp.size(); j++)
            {
                if(value == temp.at(j))
                {
                    temp.erase(j);
                }
            };
            m_data.at(num_section).m_key_value.add_pair(key, temp);
        }
    }
    return found;
}

bool CIni::change_value(CString &name_section, CString &key, CVector<CString> &value)
{
    bool found = false;
    unsigned num_section = 0;
    for(unsigned i = 0; i < m_data.size(); i++)
    {
        if(m_data.at(i).m_name_section == name_section)
        {
            found = true;
            num_section = i;
            break;
        }
    }
    if(found)
    {
        if(m_data.at(num_section).m_key_value.search(key))
        {
            m_data.at(num_section).m_key_value.delete_key(key);
            m_data.at(num_section).m_key_value.add_pair(key, value);
        }
    }
    return found;
}

bool CIni::change_value(CString &name_section, CString &key, CString & old_value, CString & new_value)
{
    bool found = false;
    unsigned num_section = 0;
    for(unsigned i = 0; i < m_data.size(); i++)
    {
        if(m_data.at(i).m_name_section == name_section)
        {
            found = true;
            num_section = i;
            break;
        }
    }
    if(found)
    {
        CVector<CString> temp;
        temp = m_data.at(num_section).m_key_value.getValue(key);
        m_data.at(num_section).m_key_value.delete_key(key);

        for(unsigned j = 0; j < temp.size(); j++)
        {
            if(old_value == temp.at(j))
            {
                temp.at(j) = new_value;
            }
        }
        m_data.at(num_section).m_key_value.add_pair(key, temp);

    }
    return found;
}

bool CIni::add_value(CString &name_section, CString &key, CVector<CString> &value)
{
    bool found = false;
    unsigned num_section = 0;
    for(unsigned i = 0; i < m_data.size(); i++)
    {
        if(m_data.at(i).m_name_section == name_section)
        {
            found = true;
            num_section = i;
            break;
        }
    }
    if(found)
    {
        m_data.at(num_section).m_key_value.add_pair(key, value);
    }
    return found;
}

bool CIni::add_value(CString &name_section, CString &key, CString &value)
{
    bool found = false;
    unsigned num_section = 0;
    for(unsigned i = 0; i < m_data.size(); i++)
    {
        if(m_data.at(i).m_name_section == name_section)
        {
            found = true;
            num_section = i;
            break;
        }
    }
    if(found)
    {
        CVector<CString> temp;
        temp = m_data.at(num_section).m_key_value.getValue(key);
        m_data.at(num_section).m_key_value.delete_key(key);

        temp.push_back(value);
        m_data.at(num_section).m_key_value.add_pair(key, temp);
    }
    return found;
}
