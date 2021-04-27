#include "CIni.h"

void CIni::analyze_file()
{
    int k = 0;
    int m = 0;
    for(int i = 0; i < temp_container.size(); i++)
    {
        if(temp_container.at(i).front() == '[')
        {
            if(k > 0)
            {
                data.resize(k);
            }
            temp_container.at(i).pop_front();
            int start = temp_container.at(i).find(']');
            int end = temp_container.at(i).size() - 2;
            temp_container.at(i).erase(start, end);
            data[k].name_section = temp_container.at(i);
            m = k;
            k++;
        }
        else if(temp_container.at(i).front() == ';')
        {
            temp_container.at(i).pop_front();
            CString temp;
            while(temp_container.at(i).find(' '))
            {
                int start = 0;
                int end = temp_container.at(i).find(' ');
                temp = temp_container.at(i).erase(start, end);
                temp.pop_back();
                data[m].name_comment.push_back(temp);
                temp.clear();
            }
            if(!temp_container.at(i).find(' '))
            {
                temp_container.at(i).pop_back();
                data[m].name_comment.push_back(temp_container.at(i));
            }
        }
        else if(temp_container.at(i).front() != '[' || temp_container.at(i).front() != ' ')
        {
            CString temp_comment;
            CVector<CString> vector_temp_comment;
            if(temp_container.at(i).find(';'))
            {
                int start = temp_container.at(i).find(';');
                int end = temp_container.at(i).find('\n') - 1;
                temp_comment = temp_container.at(i).erase(start, end);
                temp_comment.pop_front();
                CString temp;
                while(temp_comment.find(' '))
                {
                    int end = temp_comment.find(' ');
                    temp = temp_comment.erase(0, end);
                    temp.pop_back();
                    vector_temp_comment.push_back(temp);
                    temp.clear();
                }
                if(!temp_comment.find(' '))
                {
                    vector_temp_comment.push_back(temp_comment);
                    temp_comment.clear();
                }
            }
            temp_container.at(i).erase(' ');
            int end = temp_container.at(i).find('=');
            CString temp_key;
            temp_key = temp_container.at(i).erase(0, end);
            temp_key.pop_back();
            CString temp_value;
            CVector<CString> vector_temp_value;
            while(temp_container.at(i).find(','))
            {
                int end = temp_container.at(i).find(',');
                temp_value = temp_container.at(i).erase(0, end);
                temp_value.pop_back();
                vector_temp_value.push_back(temp_value);
                temp_value.clear();
            }
            if(!temp_container.at(i).find(','))
            {
                temp_container.at(i).pop_back();
                vector_temp_value.push_back(temp_container.at(i));
            }
            data[m].key_value.add_pair(temp_key, vector_temp_value, vector_temp_comment);
            temp_key.clear();
            vector_temp_value.clear();
            vector_temp_comment.clear();
        }
    }
    temp_container.clear();
}

void CIni::write_file_inner()
{
    int count = 0;
    for(int i = 0; i < data.size(); i++)
    {
        if(!data[i].name_section.empty())
        {
            count++;
        }
        else if(!data[i].name_comment.is_empty())
        {
            count++;
        }
        count += data[i].key_value.size();
    }
    temp_container.resize(count);

    int k = 0;
    for(int i = 0; i < data.size(); i++, k++)
    {
        temp_container.at(k) = data.at(i).name_section;
        temp_container.at(k).push_front('[');
        temp_container.at(k).push_back("]\n");
        if(!data.at(i).name_comment.is_empty())
        {
            k++;
            CVector<CString> temp;
            temp = data.at(i).name_comment;
            temp_container.at(k).push_back(';');
            for(int j = 0; j < temp.size(); j++)
            {
                temp_container.at(k).push_back(temp.at(j));
                temp_container.at(k).push_back(' ');
            }
            temp_container.at(k).pop_back();
            temp_container.at(k).push_back('\n');
        }
        for(int j = 1; j < data.at(i).key_value.size() + 1; j++)
        {
            k++;
            CString temp;
            CVector<CString> vector_temp_value;
            temp = j;
            temp_container.at(k).push_back(temp);
            temp_container.at(k).push_back(" = ");
            vector_temp_value = data.at(i).key_value.getValue(temp);
            if(vector_temp_value.size() > 1)
            {
                for(int p = 0; p < vector_temp_value.size(); p++)
                {
                    temp_container.at(k).push_back(vector_temp_value[p]);
                    temp_container.at(k).push_back(", ");
                }
                temp_container.at(k).pop_back();
                temp_container.at(k).pop_back();
                vector_temp_value.clear();
            }
            else
            {
                temp_container.at(k).push_back(vector_temp_value[0]);
                vector_temp_value.clear();
            }
            if(!data.at(i).key_value.getComment(temp).is_empty())
            {
                CVector<CString> vector_temp_comment = data.at(i).key_value.getComment(temp);
                temp_container.at(k).push_back(" ;");
                if(vector_temp_comment.size() > 1)
                {
                    for(int p = 0; p < vector_temp_comment.size(); p++)
                    {
                        temp_container.at(k).push_back(vector_temp_comment[p]);
                        temp_container.at(k).push_back(" ");
                    }
                    temp_container.at(k).pop_back();
                    vector_temp_comment.clear();
                }
                else
                {
                    temp_container.at(k).push_back(vector_temp_comment[0]);
                    vector_temp_comment.clear();
                }
            }
            temp_container.at(k).push_back('\n');
        }
        temp_container.at(k).push_back('\n');

    }
}

