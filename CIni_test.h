#ifndef CINI_TEST_H
#define CINI_TEST_H
#include "CIni.h"
#include <gtest/include/gtest/gtest.h>
/*TEST(test052, test_CIni_read_file)
{
    CIni ini;
    ini.read_file("C:\\FilesC++\\parse\\file3.ini");
    for(unsigned  i = 0; i < ini.temp_container.size(); i++)
    {
        cout << ini.temp_container.at(i).data() << endl;
    }
    cout << "//-------------------------//" <<endl;
    for(unsigned i = 0; i < ini.data.size(); i++)
    {
        cout << ini.data.at(i).name_section.data() << endl;
        for(unsigned j = 0; j < ini.data.at(i).name_comment.size(); j++)
        {
            cout << ini.data.at(i).name_comment.at(j).data() << " ";
        }
        cout << endl;
        for(unsigned k = 1; k < ini.data.at(i).key_value.size() + 1; k++)
        {
            CString node;
            node = k;
            cout << k << " = ";
            for(unsigned h = 0; h < ini.data.at(i).key_value.getValue(node).size(); h++)
            {
                cout << ini.data.at(i).key_value.getValue(node).at(h).data() << " ";
            }
            cout << endl;
        }
    }
<<<<<<< HEAD
}*/

TEST(test053, test_CIni_write_file)
{
    CIni ini;
    ini.read_file("C:\\FilesC++\\parse_ini\\file3.ini");
    ini.write_file("C:\\FilesC++\\parse_ini\\file4.ini");
    cout << "//-------------------------//" <<endl;
=======
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
>>>>>>> 2cfe95f891e7f8f9a32ba1a515491c986c0d2386
}
#endif // CINI_TEST_H
