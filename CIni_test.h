#ifndef CINI_TEST_H
#define CINI_TEST_H
#include "CIni.h"
#include <gtest/include/gtest/gtest.h>
/*TEST(test054, test_CIni_read_file)
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

TEST(test055, test_CIni_write_file)
{
    CIni ini;
    ini.read_file("C:\\FilesC++\\test\\parse_ini\\file3.ini");
    ini.write_file("C:\\FilesC++\\test\\parse_ini\\file4.ini");
    cout << "//-------------------------//" <<endl;
}

TEST(test056, test_CIni_change_name_section)
{
    CIni ini;
    ini.read_file("C:\\FilesC++\\test\\parse_ini\\file3.ini");
    CString section1 = "Numbers";
    CString section2 = "Strings";
    CString new_name1 = "Integers";
    CString new_name2 = "Letters";

    ini.change_name_section(section1, new_name1);
    ini.change_name_section(section2, new_name2);
    ini.write_file("C:\\FilesC++\\test\\parse_ini\\file4.ini");
    //ini.show_all();
    cout << "//-------------------------//" <<endl;
}

TEST(test057, test_CIni_delete_value)
{
    CIni ini;
    ini.read_file("C:\\FilesC++\\test\\parse_ini\\file3.ini");
    CString section1 = "Numbers";
    CString section2 = "Strings";
    CString key1 = 3;
    CString key2 = 4;
    CString key3 = 23;
    ini.delete_value(section1, key1);
    ini.delete_value(section2, key2);
    ini.delete_value(section2, key3);
    ini.write_file("C:\\FilesC++\\test\\parse_ini\\file4.ini");
    //ini.show_all();
    cout << "//-------------------------//" <<endl;
}

TEST(test058, test_CIni_change_value)
{
    CIni ini;
    ini.read_file("C:\\FilesC++\\test\\parse_ini\\file3.ini");

    CString section1 = "Numbers";
    CString key1 = 14;
    CString num1 = 65;
    CVector<CString> vec1;
    vec1.push_back(num1);
    ini.change_value(section1, key1, vec1);

    CString section2 = "Strings";
    CString key2 = 20;
    CString str1 = "HZ";
    CVector<CString> vec2;
    vec2.push_back(str1);
    ini.change_value(section2, key2, vec2);
    ini.write_file("C:\\FilesC++\\test\\parse_ini\\file4.ini");
    //ini.show_all();
    cout << "//-------------------------//" <<endl;
}

TEST(test059, test_CIni_add_value)
{
    CIni ini;
    ini.read_file("C:\\FilesC++\\test\\parse_ini\\file3.ini");
    CString section = "Numbers";
    CString key = 15;
    CVector<CString> vec;
    CString num1 = 90;
    CString num2 = 79;
    CString num3 = 35;
    CString num4 = 40;
    vec.push_back(num1);
    vec.push_back(num2);
    vec.push_back(num3);
    vec.push_back(num4);
    ini.add_value(section, key, vec);
    ini.write_file("C:\\FilesC++\\test\\parse_ini\\file4.ini");
    //ini.show_all();
    cout << "//-------------------------//" <<endl;
}
#endif // CINI_TEST_H
