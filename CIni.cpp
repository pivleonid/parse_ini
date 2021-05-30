#include "CIni.h"

void CIni::read_file(const char *m_file_path)
{
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
    int count = 0;
    for(unsigned i = 0; i < m_temp_container.size(); i++)
    {

        if(m_temp_container.at(i).front() == '[')
        {
            if(count > 0)
            {
                m_data.push_back(temp_content_of_section);
                temp_content_of_section.clear();
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
        m_data.push_back(temp_content_of_section);
        temp_content_of_section.clear();
        m_temp_container.clear();
    }
    else if(count > 1)
    {
        m_data.push_back(temp_content_of_section);
        temp_content_of_section.clear();
        m_temp_container.clear();
    }
}

void CIni::write_file(const char *m_file_path)
{
    //const char *temp = "Some words";
    write_file_inner();
    ofstream fout(m_file_path, ios_base::out | ios_base::app);
    //fout << temp;
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

void CIni::change_m_name_section(CString &old_name, CString &new_name)
{
    for(unsigned i = 0; i < m_data.size(); i++)
    {
        if(old_name == m_data.at(i).m_name_section)
        {
            m_data.at(i).m_name_section = new_name;
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

void CIni::change_value(CString &m_name_section, CString &key, CString &old_value, CString &new_value)
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



































