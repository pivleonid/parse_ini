#ifndef CINI_TEST_H
#define CINI_TEST_H
#include "CIni.h"
#include <gtest/include/gtest/gtest.h>
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
    cout << "good";
    write_file_inner();
}

/*void CIni::write_file(const char *file_path)
{

    ofstream fout;
    fout.open(file_path);
    std::ofstream out(file_path, std::ios::app);
    if (out.is_open())
    {
        out << "Welcome to CPP" << std::endl;
    }
    for(int i = 0; i < temp_container.size() + 1; i++)
    {
        for(int j = 0; j <  temp_container[i].size(); j++)
        {
            fout << temp_container[i][j];
            cout << temp_container[i][j];
        }
    }
}
*/

TEST(test038, test_CIni)
{
    CIni a;
    a.read_file("C:\\FilesC++\\file1.ini");
    //a.write_file("C:\\FilesC++\\file3.ini");
}
#endif // CINI_TEST_H
