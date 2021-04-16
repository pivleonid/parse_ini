#include "CIni.h"

void CIni::analyze_file()
{
    int k = 0;
    int m = 0;
    CString temp_section;
    CString temp_key;
    CString temp_value;
    for(int i = 0; i < temp_container.size(); i++)
    {
        int j = 0;
        while (j < temp_container[i].size())
        {
            if(temp_container[i][j] == '[')
            {
                j++;
                while (temp_container[i][j] != ']')
                {
                    temp_section.push_back(temp_container[i][j]);
                    j++;
                }
                data[k].section = temp_section;
                temp_section.clear();
                m = k;
                k++;

            }
            else if(temp_container[i][j] == '\n')
            {
                j++;
                continue;
            }
            else if(isdigit(temp_container[i][j]) || isalpha(temp_container[i][j]) || temp_container[i][j] == '-' || temp_container[i][j] == '_')
            {
                while (temp_container[i][j] != '=')
                {
                    if(isdigit(temp_container[i][j]) || isalpha(temp_container[i][j]) || temp_container[i][j] == '-' || temp_container[i][j] == '_')
                    {
                        temp_key.push_back(temp_container[i][j]);
                    }
                    j++;
                }
                while (temp_container[i][j] != '\n')
                {
                    if(isdigit(temp_container[i][j]) || isalpha(temp_container[i][j]) || temp_container[i][j] == '-' || temp_container[i][j] == '_')
                    {
                        temp_value.push_back(temp_container[i][j]);
                    }
                    j++;
                }

                data[m].key_value.add_pair(temp_key, temp_value);
                temp_value.clear();
                temp_key.clear();
            }
            j++;
        }
    }

    int p = 0;
    p++;

}
