#include "CIni.h"
void CIni::analyze_file()
{
    int k = 0;
    int m = 0;
    int j = 0;
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

