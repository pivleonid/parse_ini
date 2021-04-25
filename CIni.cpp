#include "CIni.h"
void CIni::analyze_file()
{
    int k = 0;
    int m = 0;
    int j = 0;
    CString temp_name_section;
    CString temp_str_name_comment;
    CVector<CString> temp_name_comment;
    CString temp_key;
    CString temp_value;
    CVector<CString> temp_vector_value;
    CString temp_str_key_value_comment;
    CVector<CString> temp_vector_key_value_comment;
    for(int i = 0; i < temp_container.size(); i++)
    {
        j = 0;
        while(j < temp_container.at(i).size())
        {
            if(temp_container.at(i).front() == '[')
            {
                j++;
                while(j < temp_container.at(i).find(']'))
                {
                    temp_name_section.push_back(temp_container.at(i).at(j));
                    j++;
                }
            }
            j++;
        }
    }

}

