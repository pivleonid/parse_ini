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
    //write_file_inner();
}
TEST(test038, test_CIni)
{
    CIni a;
    a.read_file("C:\\FilesC++\\parse_ini-nikita_test\\file1.ini");
}

#endif // CINI_TEST_H
