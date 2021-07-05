#include "CIni.h"

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
    string temp;
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
    unsigned count = 0;
    auto it_temp_cont = m_temp_container.begin();
    for(; it_temp_cont != m_temp_container.end(); it_temp_cont++)
    {
        if(it_temp_cont->front() == '[')
        {
            if(count > 0)
            {
                m_data.push_back(temp_content_of_section);
                temp_content_of_section.clear();
            }
            it_temp_cont->erase(it_temp_cont->begin());
            it_temp_cont->pop_back();
            it_temp_cont->pop_back();
            temp_content_of_section.m_name_section = it_temp_cont->data();
            it_temp_cont->clear();
            count++;
            continue;
        }
        if(it_temp_cont->front() == ';')
        {
            it_temp_cont->erase(it_temp_cont->begin());
            it_temp_cont->pop_back();
            temp_content_of_section.m_comment_section = it_temp_cont->data();
            continue;
        }
        else if (it_temp_cont->empty())
        {
            continue;
        }
        else if (it_temp_cont->front() == '\t')
        {
            continue;
        }
        else if (it_temp_cont->front() == '\n')
        {
            continue;
        }
        else
        {
            size_t start = it_temp_cont->find('=');
            size_t end = it_temp_cont->find('\n') + 1;
            string temp_key = it_temp_cont->data();
            temp_key.erase(start, end);

            end = it_temp_cont->find('=');
            it_temp_cont->erase(0, end);
            it_temp_cont->erase(it_temp_cont->begin());

            vector<string> temp_vct_value;
            string temp_value;
            while (!it_temp_cont->empty())
            {
                if(it_temp_cont->find(',') < 1000)
                {
                    size_t start = it_temp_cont->find(',');
                    size_t end = it_temp_cont->find('\n') + 1;
                    temp_value = it_temp_cont->data();

                    temp_vct_value.push_back(temp_value.erase(start, end));
                    temp_value.clear();

                    end = it_temp_cont->find(',') + 2;
                    it_temp_cont->erase(0, end);
                }
                else
                {
                    it_temp_cont->pop_back();
                    temp_vct_value.push_back(it_temp_cont->data());
                    it_temp_cont->clear();
                }
            }
            temp_content_of_section.m_key_value.insert(pair<string, vector<string>>(temp_key, temp_vct_value));
            string empty_key = "empty key";
            temp_content_of_section.m_key_value.erase(empty_key);
            temp_key.clear();
            temp_vct_value.clear();
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
    auto it_temp_cont = m_temp_container.begin();
    auto it_char = it_temp_cont->begin();
    for (unsigned i = 0; i < m_temp_container.size(); i++)
    {
        for (unsigned j = 0; j < m_temp_container.at(i).size(); j++)
        {
            if(m_temp_container.at(i).at(j) == '\0')
            {
                continue;
            }
            else
            {
                fout << m_temp_container.at(i).at(j);
            }
        }
    }
}

void CIni::write_file_inner()
{
    auto it_m_data = m_data.begin();
    string temp;
    for(; it_m_data != m_data.end(); it_m_data++)
    {

        temp = it_m_data->m_name_section;
        temp.insert(0, "[");
        temp.push_back(']');
        temp.push_back('\n');
        m_temp_container.push_back(temp);
        temp.clear();

        if(!it_m_data->m_comment_section.empty())
        {
            temp = it_m_data->m_comment_section;
            temp.insert(0, ";");
            temp.push_back('\n');
            m_temp_container.push_back(temp);
        }

        auto it_map_key = it_m_data->m_key_value.begin();
        for(; it_map_key != it_m_data->m_key_value.end(); it_map_key++)
        {
            temp = it_map_key->first;
            temp.push_back('=');
            auto it_temp_vct = it_map_key->second.begin();
            for(; it_temp_vct != it_map_key->second.end(); it_temp_vct++)
            {
                temp.append(it_temp_vct->data());
                temp.append(", ");
            }
            temp.pop_back();
            temp.pop_back();
            temp.push_back('\n');
            m_temp_container.push_back(temp);
        }
    }
}


bool CIni::search_name_section(string &name_section)
{
    bool found = false;
    auto it_m_data = m_data.begin();
    for(; it_m_data != m_data.end(); it_m_data++)
    {
        if(it_m_data->m_name_section == name_section)
        {
            found = true;
            break;
        }
    }
    return found;
}

bool CIni::add_name_section(string &new_name)
{
    bool found = false;
    auto it_m_data = m_data.begin();
    for(; it_m_data != m_data.end(); it_m_data++)
    {
        if(it_m_data->m_name_section != new_name)
        {
            continue;
        }
        else
        {
            found = true;
            break;
        }
    }
    if(found == false)
    {
        Content_of_section empty;
        if(m_data.empty())
        {
            m_data.push_back(empty);
            m_data.begin()->m_name_section = new_name;
        }
        else
        {
            m_data.push_back(empty);
            it_m_data = m_data.end() - 1;
            it_m_data->m_name_section = new_name;
        }
    }
    return found;
}

bool CIni::add_comment_section(string &name_section, string &comment_section)
{
    bool found = false;
    auto it_m_data = m_data.begin();
    for(unsigned i = 0; it_m_data != m_data.end(); it_m_data++, i++)
    {
        if(it_m_data->m_name_section == name_section)
        {
            found = true;
            break;
        }
    }
    if(found)
    {
        it_m_data->m_comment_section = comment_section;
    }
    return found;
}

bool CIni::change_name_section(string &old_name, string &new_name)
{
    bool found = false;
    auto it_m_data = m_data.begin();
    for(; it_m_data != m_data.end(); it_m_data++)
    {
        if(it_m_data->m_name_section == old_name)
        {
            found = true;
            it_m_data->m_name_section = new_name;
            break;
        }
    }
    return found;
}

bool CIni::add_key_value(string &name_section, map<string, vector<string>> &key_value)
{
    bool found = false;
    auto it_m_data = m_data.begin();
    for(; it_m_data != m_data.end(); it_m_data++)
    {
        if(it_m_data->m_name_section != name_section)
        {
            continue;
        }
        else
        {
            found = true;
            break;
        }
    }
    if(found)
    {
        it_m_data->m_key_value = key_value;
    }
    return found;
}

const char *CIni::get_comment_section(string &name_section)
{
    bool found = false;
    auto it_m_data = m_data.begin();
    for(; it_m_data != m_data.end(); it_m_data++)
    {
        if(it_m_data->m_name_section == name_section)
        {
            found = true;
            break;
        }
    }

    try
    {
        if(!found)
        {
            throw 1;
        }
    }
    catch (int a)
    {
        const char *empty = "\0";
        return empty;
    }
    return it_m_data->m_comment_section.data();
}

bool CIni::delete_value(string &name_section, string &key, string &value)
{
    bool found = false;
    auto it_m_data = m_data.begin();
    for(; it_m_data != m_data.end(); it_m_data++)
    {
        if(it_m_data->m_name_section == name_section)
        {
            found = true;
            break;
        }
    }
    if(found)
    {
        auto it_map = it_m_data->m_key_value.find(key);
        auto it_vector = it_map->second.begin();
        found = false;
        for(; it_vector != it_map->second.end(); it_vector++)
        {
            if(*it_vector == value)
            {
                found = true;
                it_map->second.erase(it_vector);
                break;
            }
        }
    }
    return found;
}

bool CIni::delete_value(string &name_section, string &key)
{
    bool found = false;
    auto it_m_data = m_data.begin();
    for(; it_m_data != m_data.end(); it_m_data++)
    {
        if(it_m_data->m_name_section == name_section)
        {
            found = true;
            break;
        }
    }
    if(found)
    {
        it_m_data->m_key_value.erase(key);
    }
    return found;
}

vector<string> &CIni::getValue(string &name_section, string &key)
{
    auto it_m_data = m_data.begin();
    for(; it_m_data != m_data.end(); it_m_data++)
    {
        if(it_m_data->m_name_section == name_section)
        {
            break;
        }
    }
    return it_m_data->m_key_value.find(key)->second;
}

unsigned &CIni::get_size_key_value(string &name_section)
{

    unsigned size = 0;
    bool found = false;
    auto it_m_data = m_data.begin();
    for(; it_m_data != m_data.end(); it_m_data++)
    {
        if(it_m_data->m_name_section == name_section)
        {
            found = true;
            break;
        }
    }
    if(found)
    {
        size = it_m_data->m_key_value.size();
    }
    return size;
}

bool CIni::change_value(string &name_section, string &key, vector<string> &value)
{
    bool found = false;
    auto it_m_data = m_data.begin();
    for(; it_m_data != m_data.end(); it_m_data++)
    {
        if(it_m_data->m_name_section == name_section)
        {
            found = true;
            break;
        }
    }
    if(found)
    {
        auto it_map = it_m_data->m_key_value.find(key);
        it_map->second = value;
    }
    return found;
}

bool CIni::change_value(string &name_section, string &key, string &old_value, string &new_value)
{
    bool found = false;
    auto it_m_data = m_data.begin();
    for(; it_m_data != m_data.end(); it_m_data++)
    {
        if(it_m_data->m_name_section == name_section)
        {
            found = true;
            break;
        }
    }
    if(found)
    {
        auto it_map = it_m_data->m_key_value.find(key);
        auto it_vector = it_map->second.begin();
        found = false;
        for(; it_vector != it_map->second.end(); it_vector++)
        {
            if(*it_vector == old_value)
            {
                found = true;
                *it_vector = new_value;
                break;
            }
        }
    }
    return found;
}

bool CIni::add_value(string &name_section, string &key, vector<string> &value)
{
    bool found = false;
    auto it_m_data = m_data.begin();
    for(; it_m_data != m_data.end(); it_m_data++)
    {
        if(it_m_data->m_name_section == name_section)
        {
            found = true;
            break;
        }
    }
    if(found)
    {
        it_m_data->m_key_value.insert(pair<string, vector<string>>(key, value));
    }
    if(!found)
    {
        Content_of_section temp;
        temp.m_name_section = name_section;
        temp.m_key_value.insert(pair<string, vector<string>>(key, value));
        m_data.push_back(temp);
    }
    return found;
}

bool CIni::add_value(string &name_section, string &key, string &value)
{
    bool found = false;
    auto it_m_data = m_data.begin();
    for(; it_m_data != m_data.end(); it_m_data++)
    {
        if(it_m_data->m_name_section == name_section)
        {
            found = true;
            break;
        }
    }
    if(found)
    {
        auto it_map = it_m_data->m_key_value.find(key);
        it_map->second.push_back(value);
    }
    if(!found)
    {
        Content_of_section temp;
        vector<string> temp_vct;
        temp_vct.push_back(value);
        temp.m_name_section = name_section;
        temp.m_key_value.insert(pair<string, vector<string>>(key, temp_vct));
        string empty_key = "empty key";
        temp.m_key_value.erase(empty_key);
        m_data.push_back(temp);
    }
    return found;
}
















