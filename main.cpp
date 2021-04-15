#include <iostream>
#include <CString_test.h>
#include <CVector_test.h>
#include <CMap_test.h>
#include "CFile.h"
#include "fstream"
#include "CFile.cpp"
#include <gtest/include/gtest/gtest.h>
using namespace std;

template <typename A, typename B>
void CFile<A, B>::read_file(const char *file_path)
{
    char ch;
    m_count_ch = 0;
    ifstream fin(file_path);
    while(!fin.eof())
    {
        ch = fin.get();
        m_count_ch++;
    }
    fin.close();
    //создание временного массива для хранения символов
    array_chars = new char[m_count_ch];
    int i = 0;
    ifstream fin1(file_path);
    while(!fin1.eof())
    {
        ch = fin1.get();
        array_chars[i] = ch;
        i++;
    }
    fin1.close();
    analyze_file();
    //write_data();
    cout << "Good";
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
    CFile<CString, CString> a;
    a.read_file("C:\\FilesC++\\parse\\file.ini");
    return 0;
}
