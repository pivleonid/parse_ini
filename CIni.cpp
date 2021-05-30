#include "CIni.h"

void CIni::read_file(const char *file_path)
{
    char ch;
    ifstream fin(file_path);
    CString temp;
    while(!fin.eof())
    {
        ch = fin.get();
        temp.push_back(ch);
        if(ch == '\n')
        {
            temp_container.push_back(temp);
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
    for(unsigned i = 0; i < temp_container.size(); i++)
    {

        if(temp_container.at(i).front() == '[')
        {
            if(count > 0)
            {
                data.push_back(temp_content_of_section);
                temp_content_of_section.clear();
            }
            temp_container.at(i).pop_front();
            temp_container.at(i).pop_back();
            temp_container.at(i).pop_back();
            temp_content_of_section.m_name_section = temp_container.at(i);
            count++;
        }
        else if(temp_container.at(i).front() == ';')
        {
            temp_container.at(i).pop_front();
            CString temp_comment = temp_container.at(i);
            while(temp_container.at(i).find(' '))
            {
                unsigned start = temp_container.at(i).find(' ');
                unsigned end = temp_container.at(i).find('\n');
                temp_comment.erase(start, end);
                temp_content_of_section.m_name_comment.push_back(temp_comment);
                temp_comment.clear();

                end = temp_container.at(i).find(' ');
                temp_container.at(i).erase(0, end);
                temp_comment = temp_container.at(i);
            }
            temp_comment.clear();
            if(!temp_container.at(i).find(' '))
            {
                temp_container.at(i).pop_back();
                temp_content_of_section.m_name_comment.push_back(temp_container.at(i));
            }
        }
        else if(temp_container.at(i).empty())
        {
            continue;
        }
        else if(temp_container.at(i).front() == '\t')
        {
            continue;
        }
        else if(temp_container.at(i).front() == '\n')
        {
            continue;
        }
        else if(temp_container.at(i).front() != '[' || temp_container.at(i).front() != ' ')
        {
             temp_container.at(i).erase(' ');
             unsigned start = temp_container.at(i).find('=');
             unsigned end = temp_container.at(i).find('\n');
             CString temp_key = temp_container.at(i);
             temp_key.erase(start, end);
             end = temp_container.at(i).find('=');
             temp_container.at(i).erase(0, end);

             CVector<CString> temp_vector_value;
             CString temp_value;
             while(temp_container.at(i).find(','))
             {
                unsigned start = temp_container.at(i).find(',');
                unsigned end = temp_container.at(i).find('\n');
                temp_value = temp_container.at(i);

                temp_vector_value.push_back(temp_value.erase(start, end));
                temp_value.clear();

                end = temp_container.at(i).find(',');
                temp_container.at(i).erase(0, end);
             }
             if(!temp_container.at(i).find(','))
             {
                 temp_container.at(i).pop_back();
                 temp_vector_value.push_back(temp_container.at(i));
             }
             temp_content_of_section.m_key_value.add_pair(temp_key, temp_vector_value);
             temp_key.clear();
             temp_vector_value.clear();
        }
    }
    if(count == 1)
    {
        data.push_back(temp_content_of_section);
        temp_content_of_section.clear();
        temp_container.clear();
    }
    else if(count > 1)
    {
        data.push_back(temp_content_of_section);
        temp_content_of_section.clear();
        temp_container.clear();
    }
}

void CIni::write_file(const char *file_path)
{
    //const char *temp = "Some words";
    write_file_inner();
    ofstream fout(file_path, ios_base::out | ios_base::app);
    //fout << temp;
    char ch;
    for(unsigned i = 0; i < temp_container.size(); i++)
    {
        for(unsigned j = 0; j < temp_container.at(i).size(); j++)
        {
            if(temp_container.at(i).at(j) == '\0')
            {
                continue;
            }
            else
            {
                ch = temp_container.at(i).at(j);
                fout << ch;
            }
        }
    }
}

void CIni::write_file_inner()
{
    int k = 0;
    for(unsigned i = 0; i < data.size(); i++)
    {
        CString temp;
        temp = data.at(i).m_name_section;
        temp.push_front('[');
        temp.push_back(']');
        temp.push_back('\n');
        temp_container.push_back(temp);
        k++;
        if(!data.at(i).m_name_comment.is_empty())
        {
            temp.clear();
            temp_container.push_back(temp);
            temp_container.at(k).push_back(';');
            for(unsigned n = 0; n < data.at(i).m_name_comment.size(); n++)
            {
                temp_container.at(k).push_back(data.at(i).m_name_comment.at(n));
                temp_container.at(k).push_back(' ');
            }
            temp_container.at(k).pop_back();
            temp_container.at(k).push_back('\n');
            k++;
        }
        temp.clear();
        //unsigned size = data.at(i).m_key_value.size();
        unsigned j = 1;
        CString node;
        unsigned count = 0;
        node = j;
        while(count != data.at(i).m_key_value.size())
        {
            if(data.at(i).m_key_value.search(node))
            {
                temp_container.push_back(temp);
                temp_container.at(k).push_back(node);
                temp_container.at(k).push_back(" = ");
                for(unsigned l = 0; l < data.at(i).m_key_value.getValue(node).size(); l++)
                {
                    temp_container.at(k).push_back(data.at(i).m_key_value.getValue(node).at(l).data());
                    temp_container.at(k).push_back(", ");
                }
                temp_container.at(k).pop_back();
                temp_container.at(k).pop_back();
                temp_container.at(k).push_back('\n');
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
    for(unsigned i = 0; i < data.size(); i++)
    {
        if(old_name == data.at(i).m_name_section)
        {
            data.at(i).m_name_section = new_name;
        }
    }
}

void CIni::show_all()
{
    for(unsigned i = 0; i < data.size(); i++)
    {
        CString node;
        cout << data.at(i).m_name_section.data() << endl;
        if(!data.at(i).m_name_comment.is_empty())
        {
            for(unsigned j = 0; j < data.at(i).m_name_comment.size(); j++)
            {
                cout << data.at(i).m_name_comment.at(j).data() << ' ';
            }
            cout << endl;
        }
        unsigned k = 1;
        unsigned count = 0;
        node = k;
        while (count != data.at(i).m_key_value.size())
        {
            if(data.at(i).m_key_value.search(node))
            {
                cout << k << " = ";
                for(unsigned l = 0; l < data.at(i).m_key_value.getValue(node).size(); l++)
                {
                    cout << data.at(i).m_key_value.getValue(node).at(l).data() << ' ';
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
    for(unsigned i = 0; i < data.size(); i++)
    {
        if(m_name_section == data.at(i).m_name_section)
        {
            if(data.at(i).m_key_value.search(key))
            {
                data.at(i).m_key_value.delete_key(key);
            }
        }
    }
}

void CIni::delete_value(CString &m_name_section, CString &key, CString &value)
{
    for(unsigned i = 0; i < data.size(); i++)
    {
        if(m_name_section == data.at(i).m_name_section)
        {
            if(data.at(i).m_key_value.search(key))
            {
                CVector<CString> temp;
                temp = data.at(i).m_key_value.getValue(key);
                data.at(i).m_key_value.delete_key(key);

                for(unsigned j = 0; j < temp.size(); j++)
                {
                    if(value == temp.at(j))
                    {
                        temp.erase(j);
                    }
                };
                data.at(i).m_key_value.add_pair(key, temp);
            }
        }
    }
}

void CIni::change_value(CString &m_name_section, CString &key, CVector<CString> &value)
{
    for(unsigned i = 0; i < data.size(); i++)
    {
        if(m_name_section == data.at(i).m_name_section)
        {
            if(data.at(i).m_key_value.search(key))
            {
                data.at(i).m_key_value.delete_key(key);
                data.at(i).m_key_value.add_pair(key, value);
            }
        }
    }
}

void CIni::change_value(CString &m_name_section, CString &key, CString &old_value, CString &new_value)
{
    for(unsigned i = 0; i < data.size(); i++)
    {
        if(m_name_section == data.at(i).m_name_section)
        {
            CVector<CString> temp;
            temp = data.at(i).m_key_value.getValue(key);
            data.at(i).m_key_value.delete_key(key);

            for(unsigned j = 0; j < temp.size(); j++)
            {
                if(old_value == temp.at(j))
                {
                    temp.at(j) = new_value;
                }
            }
            data.at(i).m_key_value.add_pair(key, temp);
        }
    }
}

void CIni::add_value(CString &m_name_section, CString &key, CVector<CString> &value)
{
    for(unsigned i = 0; i < data.size(); i++)
    {
        if(m_name_section == data.at(i).m_name_section)
        {
            data.at(i).m_key_value.add_pair(key, value);
        }
    }
}

void CIni::add_value(CString &m_name_section, CString &key, CString &value)
{
    for(unsigned i = 0; i < data.size(); i++)
    {
        if(m_name_section == data.at(i).m_name_section)
        {
            CVector<CString> temp;
            temp = data.at(i).m_key_value.getValue(key);
            data.at(i).m_key_value.delete_key(key);

            temp.push_back(value);
            data.at(i).m_key_value.add_pair(key, temp);
        }
    }
}



































