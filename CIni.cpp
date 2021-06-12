#include "CIni.h"
Content_of_section::Content_of_section()
{
    CString empty_name;
    CVector<CString> empty_comment;
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
    m_name_comment = empty_comment;
    m_key_value    = empty_key_value;

}
CIni::CIni()
{
    CString empty_name;
    CVector<CString> empty_comment;
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
    temp_content.m_name_comment = empty_comment;
    temp_content.m_key_value    = empty_key_value;
    m_data.push_back(temp_content);
}

void CIni::create_file(const char *file_path)
{
    m_file_path = file_path;
    ofstream new_file(m_file_path);
}

void CIni::delete_file(const char *file_path)
{
    m_file_path = file_path;
    remove(m_file_path);
}

void CIni::read_file(const char *file_path)
{
    m_file_path = file_path;
    char ch;
    ifstream fin(m_file_path);
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
            CString temp_comment = m_temp_container.at(i);
            while(m_temp_container.at(i).find(' '))
            {
                unsigned start = m_temp_container.at(i).find(' ');
                unsigned end = m_temp_container.at(i).find('\n');
                temp_comment.erase(start, end);
                temp_content_of_section.m_name_comment.push_back(temp_comment);
                temp_comment.clear();

                end = m_temp_container.at(i).find(' ');
                m_temp_container.at(i).erase(0, end);
                temp_comment = m_temp_container.at(i);
            }
            temp_comment.clear();
            if(!m_temp_container.at(i).find(' '))
            {
                m_temp_container.at(i).pop_back();
                temp_content_of_section.m_name_comment.push_back(m_temp_container.at(i));
            }
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


void CIni::write_file(const char *file_path)
{
    m_file_path = file_path;
    write_file_inner();
    ofstream fout(m_file_path, ios_base::out | ios_base::app);
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
            m_data.at(i).m_name_comment.clear();
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
        if(!m_data.at(i).m_name_comment.is_empty())
        {
            temp.clear();
            m_temp_container.push_back(temp);
            m_temp_container.at(k).push_back(';');
            for(unsigned n = 0; n < m_data.at(i).m_name_comment.size(); n++)
            {
                m_temp_container.at(k).push_back(m_data.at(i).m_name_comment.at(n));
                m_temp_container.at(k).push_back(' ');
            }
            m_temp_container.at(k).pop_back();
            m_temp_container.at(k).push_back('\n');
            k++;
        }
        temp.clear();
        //unsigned size = m_data.at(i).m_key_value.size();
        unsigned j = 1;
        CString node;
        unsigned count = 0;
        node = j;
        while(count != m_data.at(i).m_key_value.size())
        {
            if(m_data.at(i).m_key_value.search(node))
            {
                m_temp_container.push_back(temp);
                m_temp_container.at(k).push_back(node);
                m_temp_container.at(k).push_back(" = ");
                for(unsigned l = 0; l < m_data.at(i).m_key_value.getValue(node).size(); l++)
                {
                    m_temp_container.at(k).push_back(m_data.at(i).m_key_value.getValue(node).at(l).data());
                    m_temp_container.at(k).push_back(", ");
                }
                m_temp_container.at(k).pop_back();
                m_temp_container.at(k).pop_back();
                m_temp_container.at(k).push_back('\n');
                count++;
                k++;
            }
            j++;
            node = j;
            temp.clear();
        }
    }
}

void CIni::add_name_section(CString &new_name)
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

void CIni::change_name_section(CString &old_name, CString &new_name)
{
    for(unsigned i = 0; i < m_data.size(); i++)
    {
        if(old_name == m_data.at(i).m_name_section)
        {
            m_data.at(i).m_name_section = new_name;
        }
    }
}

void CIni::add_name_comment(CString & name_section, CString & new_comment)
{

    CVector<CString> temp_vct;
    CString temp_comment = new_comment;
    for(unsigned i = 0; i < m_data.size(); i++)
    {
        if(name_section == m_data.at(i).m_name_section)
        {
            while (new_comment.find(' '))
            {
                unsigned start = new_comment.find(' ');
                unsigned end = new_comment.size() - 1;
                temp_comment.erase(start, end);
                temp_vct.push_back(temp_comment);
                temp_comment.clear();

                end = new_comment.find(' ');
                new_comment.erase(0, end);
                temp_comment = new_comment;
            }
            temp_comment.clear();
            if(!new_comment.find(' '))
            {
                temp_vct.push_back(new_comment);
            }
            m_data.at(i).m_name_comment = temp_vct;
            break;
        }
    }
}

void CIni::add_key_value(CString &name_section, CMap<CString, CVector<CString> > &key_value)
{
    for(unsigned i = 0; i < m_data.size(); i++)
    {
        if(name_section == m_data.at(i).m_name_section)
        {
            unsigned count = 0;
            CString key;
            CVector<CString> temp_vct;
            for(unsigned j = 1; j < m_data.at(i).m_key_value.size() + 1; j++)
            {
                key = j;
                if(m_data.at(i).m_key_value.getValue(key).size() == 1)
                {
                    if(m_data.at(i).m_key_value.getValue(key).at(0) == 'B' && key == 1)
                    {
                        count++;
                    }
                    else if(m_data.at(i).m_key_value.getValue(key).at(0) == 'A' && key == 2)
                    {
                        count++;
                    }
                    else if(m_data.at(i).m_key_value.getValue(key).at(0) == 'C' && key == 3)
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
                m_data.at(i).m_key_value.clear();
                m_data.at(i).m_key_value = key_value;
            }
            else
            {
                m_data.at(i).m_key_value = key_value;
            };

        }
    }
}

void CIni::change_name_comment(CString & name_section, CString & old_comment, CString & new_comment)
{
    for(unsigned i = 0; i < m_data.size(); i++)
    {
        if(name_section == m_data.at(i).m_name_section)
        {
            for(unsigned j = 0; j < m_data.at(i).m_name_comment.size(); j++)
            {
                if(old_comment == m_data.at(i).m_name_comment.at(j))
                {
                    m_data.at(i).m_name_comment.at(j) = new_comment;
                }
            }
        }
    }
}

void CIni::change_name_comment(CString & name_section, CString & new_comment)
{
    for(unsigned i = 0; i < m_data.size(); i++)
    {
        if(name_section == m_data.at(i).m_name_section)
        {
            CVector<CString> temp_vct;
            CString temp_comment = new_comment;
            while (new_comment.find(' '))
            {
                unsigned start = new_comment.find(' ');
                unsigned end = new_comment.size();
                temp_comment.erase(start, end);
                temp_vct.push_back(temp_comment);
                temp_comment.clear();

                end = new_comment.find(' ');
                new_comment.erase(0, end);
                temp_comment = new_comment;
            }
            temp_comment.clear();
            if(new_comment.find(' '))
            {
                temp_vct.push_back(new_comment);
            }
            m_data.at(i).m_name_comment = temp_vct;
        }
    }
}

void CIni::show_all()
{
    for(unsigned i = 0; i < m_data.size(); i++)
    {
        CString node;
        cout << m_data.at(i).m_name_section.data() << endl;
        if(!m_data.at(i).m_name_comment.is_empty())
        {
            for(unsigned j = 0; j < m_data.at(i).m_name_comment.size(); j++)
            {
                cout << m_data.at(i).m_name_comment.at(j).data() << ' ';
            }
            cout << endl;
        }
        unsigned k = 1;
        unsigned count = 0;
        node = k;
        while (count != m_data.at(i).m_key_value.size())
        {
            if(m_data.at(i).m_key_value.search(node))
            {
                cout << k << " = ";
                for(unsigned l = 0; l < m_data.at(i).m_key_value.getValue(node).size(); l++)
                {
                    cout << m_data.at(i).m_key_value.getValue(node).at(l).data() << ' ';
                }
                cout << endl;
                count++;
            }
            node.clear();
            k++;
            node = k;
        }
    }
}

void CIni::delete_value(CString &m_name_section, CString &key)
{
    for(unsigned i = 0; i < m_data.size(); i++)
    {
        if(m_name_section == m_data.at(i).m_name_section)
        {
            if(m_data.at(i).m_key_value.search(key))
            {
                m_data.at(i).m_key_value.delete_key(key);
            }
        }
    }
}

void CIni::delete_value(CString &m_name_section, CString &key, CString &value)
{
    for(unsigned i = 0; i < m_data.size(); i++)
    {
        if(m_name_section == m_data.at(i).m_name_section)
        {
            if(m_data.at(i).m_key_value.search(key))
            {
                CVector<CString> temp;
                temp = m_data.at(i).m_key_value.getValue(key);
                m_data.at(i).m_key_value.delete_key(key);

                for(unsigned j = 0; j < temp.size(); j++)
                {
                    if(value == temp.at(j))
                    {
                        temp.erase(j);
                    }
                };
                m_data.at(i).m_key_value.add_pair(key, temp);
            }
        }
    }
}

void CIni::change_value(CString &m_name_section, CString &key, CVector<CString> &value)
{
    for(unsigned i = 0; i < m_data.size(); i++)
    {
        if(m_name_section == m_data.at(i).m_name_section)
        {
            if(m_data.at(i).m_key_value.search(key))
            {
                m_data.at(i).m_key_value.delete_key(key);
                m_data.at(i).m_key_value.add_pair(key, value);
            }
        }
    }
}

void CIni::change_value(CString &m_name_section, CString &key, CString & old_value, CString & new_value)
{
    for(unsigned i = 0; i < m_data.size(); i++)
    {
        if(m_name_section == m_data.at(i).m_name_section)
        {
            CVector<CString> temp;
            temp = m_data.at(i).m_key_value.getValue(key);
            m_data.at(i).m_key_value.delete_key(key);

            for(unsigned j = 0; j < temp.size(); j++)
            {
                if(old_value == temp.at(j))
                {
                    temp.at(j) = new_value;
                }
            }
            m_data.at(i).m_key_value.add_pair(key, temp);
        }
    }
}

void CIni::add_value(CString &m_name_section, CString &key, CVector<CString> &value)
{
    for(unsigned i = 0; i < m_data.size(); i++)
    {
        if(m_name_section == m_data.at(i).m_name_section)
        {
            m_data.at(i).m_key_value.add_pair(key, value);
        }
    }
}

void CIni::add_value(CString &m_name_section, CString &key, CString &value)
{
    for(unsigned i = 0; i < m_data.size(); i++)
    {
        if(m_name_section == m_data.at(i).m_name_section)
        {
            CVector<CString> temp;
            temp = m_data.at(i).m_key_value.getValue(key);
            m_data.at(i).m_key_value.delete_key(key);

            temp.push_back(value);
            m_data.at(i).m_key_value.add_pair(key, temp);
        }
    }
}



































