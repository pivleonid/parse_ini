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
<<<<<<< HEAD
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
            temp_content_of_section.name_section = temp_container.at(i);
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
                temp_content_of_section.name_comment.push_back(temp_comment);
                temp_comment.clear();

                end = temp_container.at(i).find(' ');
                temp_container.at(i).erase(0, end);
                temp_comment = temp_container.at(i);
            }
            temp_comment.clear();
            if(!temp_container.at(i).find(' '))
            {
                temp_container.at(i).pop_back();
                temp_content_of_section.name_comment.push_back(temp_container.at(i));
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
             temp_content_of_section.key_value.add_pair(temp_key, temp_vector_value);
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
    ofstream fout(file_path);
    //fout << temp;
    char ch;
    for(unsigned i = 0; i < temp_container.size(); i++)
    {
        for(unsigned j = 0; j < temp_container.at(i).size(); j++)
        {
            ch = temp_container.at(i).at(j);
            fout << ch;
        }
    }
}

void CIni::write_file_inner()
{
    int k = 0;
    for(unsigned i = 0; i < data.size(); i++)
    {
        CString temp;
        temp = data.at(i).name_section;
        temp_container.push_back(temp);
        temp_container.at(k).push_front('[');
        temp_container.at(k).push_back(']');
        temp_container.at(k).push_back('\n');
        k++;
        if(!data.at(i).name_comment.is_empty())
        {
            temp.clear();
            temp_container.push_back(temp);
            temp_container.at(k).push_back(';');
            for(unsigned n = 0; n < data.at(i).name_comment.size(); n++)
            {
                temp_container.at(k).push_back(data.at(i).name_comment.at(n));
                temp_container.at(k).push_back(' ');
            }
            temp_container.at(k).pop_back();
            temp_container.at(k).push_back('\n');
            k++;
        }
        temp.clear();
        //unsigned size = data.at(i).key_value.size();
        for (unsigned j = 1; j < data.at(i).key_value.size() + 1; j++)
        {
            temp_container.push_back(temp);
            CString number;
            number = j;
            temp_container.at(k).push_back(number);
            temp_container.at(k).push_back(" = ");
            CString node;
            node = j;
            //unsigned size = data.at(i).key_value.getValue(node).size();
            for(unsigned l = 0; l < data.at(i).key_value.getValue(node).size(); l++)
            {
                temp_container.at(k).push_back(data.at(i).key_value.getValue(node).at(l).data());
                temp_container.at(k).push_back(", ");
            }
            temp_container.at(k).pop_back();
            temp_container.at(k).pop_back();
            temp_container.at(k).push_back('\n');
            k++;
            temp.clear();
        }
        temp_container.at(k).push_back('\n');
    }
}



=======
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

>>>>>>> 2cfe95f891e7f8f9a32ba1a515491c986c0d2386
