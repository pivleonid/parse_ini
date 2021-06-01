#ifndef CINI_TEST_H
#define CINI_TEST_H
#include "CIni.h"
#include <gtest/include/gtest/gtest.h>
/*TEST(test057, test_CIni_read_file)
{
    CIni ini;
    ini.read_file("C:\\FilesC++\\parse\\file3.ini");
    for(unsigned  i = 0; i < ini.m_temp_container.size(); i++)
    {
        cout << ini.m_temp_container.at(i).data() << endl;
    }
    cout << "//-------------------------//" <<endl;
    for(unsigned i = 0; i < ini.m_data.size(); i++)
    {
        cout << ini.m_data.at(i).m_name_section.m_data() << endl;
        for(unsigned j = 0; j < ini.m_data.at(i).m_name_comment.size(); j++)
        {
            cout << ini.m_data.at(i).m_name_comment.at(j).data() << " ";
        }
        cout << endl;
        for(unsigned k = 1; k < ini.m_data.at(i).m_key_value.size() + 1; k++)
        {
            CString node;
            node = k;
            cout << k << " = ";
            for(unsigned h = 0; h < ini.m_data.at(i).m_key_value.getValue(node).size(); h++)
            {
                cout << ini.m_data.at(i).m_key_value.getValue(node).at(h).data() << " ";
            }
            cout << endl;
        }
    }
}*/

TEST(test052, test_CIni_write_file)
{
    CIni ini;
    const char *name1 = {"Numbers"};
    const char *comment1[5]  =
    {
        "This", "section", "contains", "the", "numbers"
    };
    const char *res1[18] =
    {
        /*1 =*/  "60",
        /*2 =*/  "35",
        /*3 =*/  "70", "45",
        /*4 =*/  "21",
        /*5 =*/  "42",
        /*6 =*/  "17",
        /*7 =*/  "11",
        /*8 =*/  "24",
        /*9 =*/  "23",
        /*10 =*/ "71", "56",
        /*11 =*/ "89", "78", "25",
        /*12 =*/ "68",
        /*13 =*/ "63",
        /*14 =*/ "69"
    };

    const char *name2 = {"Strings"};
    const char *comment2[5]  =
    {
        "This", "section", "contains", "the", "strings"
    };
    const char *res2[25] =
    {
        /*1 =*/  "ABCDEFGHIJKLM",
        /*2 =*/  "ABCDEFGH",
        /*3 =*/  "ABCDE",
        /*4 =*/  "ABCD",
        /*5 =*/  "ABC",
        /*6 =*/  "A",
        /*7 =*/  "AB",
        /*8 =*/  "ABCDEF",
        /*9 =*/  "ABCDEFGHIJ",
        /*10 =*/ "ABCDEFGHI",
        /*11 =*/ "ABCDEFGHIJKL",
        /*12 =*/ "ABCDEFGHIJK",
        /*13 =*/ "ABCDEFGHIJKLMNOPQRS",
        /*14 =*/ "ABCDEFGHIJKLMNO",
        /*15 =*/ "ABCDEFGHIJKLMN",
        /*16 =*/ "ABCDEFGHIJKLMNOPQ",
        /*17 =*/ "ABCDEFGHIJKLMNOP",
        /*18 =*/ "ABCDEFGHIJKLMNOPQR",
        /*19 =*/ "ABCDEFGHIJKLMNOPQRSTUV",
        /*20 =*/ "ABCDEFGHIJKLMNOPQRSTU",
        /*21 =*/ "ABCDEFGHIJKLMNOPQRST",
        /*22 =*/ "ABCDEFGHIJKLMNOPQRSTUVWX",
        /*23 =*/ "ABCDEFGHIJKLMNOPQRSTUVW",
        /*24 =*/ "ABCDEFGHIJKLMNOPQRSTUVWXY",
        /*25 =*/ "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    };
    for(unsigned i = 0; i < ini.m_data.size(); i++)
        {
            if(i == 0)
            {
                ASSERT_EQ(*name1, *ini.m_data.at(i).m_name_section.data());
                unsigned k = 0;
                for(unsigned j = 0; j < ini.m_data.at(i).m_name_comment.size(); j++, k++)
                {
                    ASSERT_EQ(*comment1[k], *ini.m_data.at(i).m_name_comment.at(j).data());
                }

                unsigned t = 0;
                CString node;
                for(unsigned n = 1; n < ini.m_data.at(i).m_key_value.size() + 1; n++)
                {
                    node = n;
                    for(unsigned h = 0; h < ini.m_data.at(i).m_key_value.getValue(node).size(); h++, t++)
                    {
                        ASSERT_EQ(*res1[t], *ini.m_data.at(i).m_key_value.getValue(node).at(h).data());
                        //cout << ini.m_data.at(i).m_key_value.getValue(node).at(h).data() << " ";
                    }
                }
            }
            if(i == 1)
            {
                ASSERT_EQ(*name2, *ini.m_data.at(i).m_name_section.data());
                unsigned k = 0;
                for(unsigned j = 0; j < ini.m_data.at(i).m_name_comment.size(); j++, k++)
                {
                    ASSERT_EQ(*comment2[k], *ini.m_data.at(i).m_name_comment.at(j).data());
                }

                unsigned t = 0;
                CString node;
                for(unsigned n = 1; n < ini.m_data.at(i).m_key_value.size() + 1; n++)
                {
                    node = n;
                    for(unsigned h = 0; h < ini.m_data.at(i).m_key_value.getValue(node).size(); h++, t++)
                    {
                        ASSERT_EQ(*res2[t], *ini.m_data.at(i).m_key_value.getValue(node).at(h).data());
                        //cout << ini.m_data.at(i).m_key_value.getValue(node).at(h).data() << " ";
                    }
                }
            }

        }

    //ini.read_file("C:\\FilesC++\\test\\parse_ini\\file3.ini");
    //ini.write_file("C:\\FilesC++\\test\\parse_ini\\file4.ini");
    //ini.show_all();
    //cout << "//-------------------------//" <<endl;
}

TEST(test053, test_CIni_change_m_name_section)
{
    CIni ini;
    ini.read_file("C:\\FilesC++\\test\\parse_ini\\file3.ini");
    CString section1 = "Numbers";
    CString section2 = "Strings";
    CString new_name1 = "Integers";
    CString new_name2 = "Letters";
    const char *res[2] =
    {
        "Integers",
        "Letters"
    };
    ini.change_m_name_section(section1, new_name1);
    ini.change_m_name_section(section2, new_name2);
    for(unsigned i = 0; i < ini.m_data.size(); i++)
    {
        ASSERT_EQ(*res[i], *ini.m_data.at(i).m_name_section.data());
    }
    //ini.write_file("C:\\FilesC++\\test\\parse_ini\\file4.ini");
    //ini.show_all();
    //cout << "//-------------------------//" <<endl;
}

TEST(test054, test_CIni_delete_value)
{
    CIni ini;
    ini.read_file("C:\\FilesC++\\test\\parse_ini\\file3.ini");
    CString section1 = "Numbers";
    CString key = 3;
    ini.delete_value(section1, key);
    key = 6;
    ini.delete_value(section1, key);
    key = 9;
    ini.delete_value(section1, key);
    key = 11;
    ini.delete_value(section1, key);
    key = 13;
    ini.delete_value(section1, key);

    CString section2 = "Strings";
    key = 4;
    ini.delete_value(section2, key);
    key = 25;
    ini.delete_value(section2, key);
    key = 13;
    ini.delete_value(section2, key);
    key = 19;
    ini.delete_value(section2, key);
    key = 9;
    ini.delete_value(section2, key);
    const char *res1[10] =
    {
        /*1 =*/  "60",
        /*2 =*/  "35",
        /*4 =*/  "21",
        /*5 =*/  "42",
        /*7 =*/  "11",
        /*8 =*/  "24",
        /*10 =*/ "71", "56",
        /*12 =*/ "68",
        /*14 =*/ "69"
    };
    const char *res2[20] =
    {
        /*1 =*/  "ABCDEFGHIJKLM",
        /*2 =*/  "ABCDEFGH",
        /*3 =*/  "ABCDE",
        /*5 =*/  "ABC",
        /*6 =*/  "A",
        /*7 =*/  "AB",
        /*8 =*/  "ABCDEF",
        /*10 =*/ "ABCDEFGHI",
        /*11 =*/ "ABCDEFGHIJKL",
        /*12 =*/ "ABCDEFGHIJK",
        /*14 =*/ "ABCDEFGHIJKLMNO",
        /*15 =*/ "ABCDEFGHIJKLMN",
        /*16 =*/ "ABCDEFGHIJKLMNOPQ",
        /*17 =*/ "ABCDEFGHIJKLMNOP",
        /*18 =*/ "ABCDEFGHIJKLMNOPQR",
        /*20 =*/ "ABCDEFGHIJKLMNOPQRSTU",
        /*21 =*/ "ABCDEFGHIJKLMNOPQRST",
        /*22 =*/ "ABCDEFGHIJKLMNOPQRSTUVWX",
        /*23 =*/ "ABCDEFGHIJKLMNOPQRSTUVW",
        /*24 =*/ "ABCDEFGHIJKLMNOPQRSTUVWXY"
    };
    for(unsigned i = 0; i < ini.m_data.size(); i++)
    {
        if(i == 0)
        {
            CString node;
            unsigned t = 0;
            for(unsigned n = 1; n < ini.m_data.at(i).m_key_value.size() + 1; n++)
            {
                node = n;
                if(ini.m_data.at(i).m_key_value.search(node))
                {
                    for(unsigned h = 0; h < ini.m_data.at(i).m_key_value.getValue(node).size(); h++, t++)
                    {
                        ASSERT_EQ(*res1[t], *ini.m_data.at(i).m_key_value.getValue(node).at(h).data());
                        //cout << ini.m_data.at(i).m_key_value.getValue(node).at(h).data() << " ";
                    }
                }
            }
        }
        if(i == 1)
        {
            CString node;
            unsigned t = 0;
            for(unsigned n = 1; n < ini.m_data.at(i).m_key_value.size() + 1; n++)
            {
                node = n;
                if(ini.m_data.at(i).m_key_value.search(node))
                {
                    for(unsigned h = 0; h < ini.m_data.at(i).m_key_value.getValue(node).size(); h++, t++)
                    {
                        ASSERT_EQ(*res2[t], *ini.m_data.at(i).m_key_value.getValue(node).at(h).data());
                        //cout << ini.m_data.at(i).m_key_value.getValue(node).at(h).data() << " ";
                    }
                }
            }
        }
    }

    //ini.write_file("C:\\FilesC++\\test\\parse_ini\\file4.ini");
    //ini.show_all();
    //cout << "//-------------------------//" <<endl;
}

TEST(test055, test_CIni_change_value1)
{
    CIni ini;
    ini.read_file("C:\\FilesC++\\test\\parse_ini\\file3.ini");

    CString section1 = "Numbers";
    CString key1 = 3;
    CVector<CString> vec1;
    CString number = 80;
    vec1.push_back(number);
    ini.change_value(section1, key1, vec1);
    vec1.clear();

    key1 = 5;
    number = 91;
    vec1.push_back(number);
    ini.change_value(section1, key1, vec1);
    vec1.clear();

    key1 = 8;
    number = 52;
    vec1.push_back(number);
    ini.change_value(section1, key1, vec1);
    vec1.clear();

    key1 = 10;
    number = 330;
    vec1.push_back(number);
    ini.change_value(section1, key1, vec1);
    vec1.clear();


    CString section2 = "Strings";
    CString key2 = 2;
    CString str = "HZ";
    CVector<CString> vec2;
    vec2.push_back(str);
    ini.change_value(section2, key2, vec2);
    vec2.clear();

    key2 = 9;
    str = "Sub-zero";
    vec2.push_back(str);
    ini.change_value(section2, key2, vec2);
    vec2.clear();

    key2 = 13;
    str = "Alpha";
    vec2.push_back(str);
    str = "Betta";
    vec2.push_back(str);
    str = "Gamma";
    vec2.push_back(str);
    ini.change_value(section2, key2, vec2);
    vec2.clear();

    key2 = 18;
    str = "WALKIRYE";
    vec2.push_back(str);
    ini.change_value(section2, key2, vec2);
    vec2.clear();

    key2 = 21;
    str = "X-men";
    vec2.push_back(str);
    ini.change_value(section2, key2, vec2);
    vec2.clear();

    key2 = 24;
    str = "New";
    vec2.push_back(str);
    ini.change_value(section2, key2, vec2);
    vec2.clear();

    const char *res1[16] =
    {
        /*1 =*/  "60",
        /*2 =*/  "35",
        /*3 =*/  "80",
        /*4 =*/  "21",
        /*5 =*/  "91",
        /*6 =*/  "17",
        /*7 =*/  "11",
        /*8 =*/  "52",
        /*9 =*/  "23",
        /*10 =*/ "330",
        /*11 =*/ "89", "78", "25",
        /*12 =*/ "68",
        /*13 =*/ "63",
        /*14 =*/ "69"
    };

    const char *res2[27] =
    {
        /*1 =*/  "ABCDEFGHIJKLM",
        /*2 =*/  "HZ",
        /*3 =*/  "ABCDE",
        /*4 =*/  "ABCD",
        /*5 =*/  "ABC",
        /*6 =*/  "A",
        /*7 =*/  "AB",
        /*8 =*/  "ABCDEF",
        /*9 =*/  "Sub-zero",
        /*10 =*/ "ABCDEFGHI",
        /*11 =*/ "ABCDEFGHIJKL",
        /*12 =*/ "ABCDEFGHIJK",
        /*13 =*/ "Alpha", "Betta", "Gamma",
        /*14 =*/ "ABCDEFGHIJKLMNO",
        /*15 =*/ "ABCDEFGHIJKLMN",
        /*16 =*/ "ABCDEFGHIJKLMNOPQ",
        /*17 =*/ "ABCDEFGHIJKLMNOP",
        /*18 =*/ "WALKIRYE",
        /*19 =*/ "ABCDEFGHIJKLMNOPQRSTUV",
        /*20 =*/ "ABCDEFGHIJKLMNOPQRSTU",
        /*21 =*/ "X-men",
        /*22 =*/ "ABCDEFGHIJKLMNOPQRSTUVWX",
        /*23 =*/ "ABCDEFGHIJKLMNOPQRSTUVW",
        /*24 =*/ "New",
        /*25 =*/ "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    };

    for(unsigned i = 0; i < ini.m_data.size(); i++)
    {
        if(i == 0)
        {
            unsigned t = 0;
            CString node;
            for(unsigned n = 1; n < ini.m_data.at(i).m_key_value.size() + 1; n++)
            {
                node = n;
                for(unsigned h = 0; h < ini.m_data.at(i).m_key_value.getValue(node).size(); h++, t++)
                {
                    ASSERT_EQ(*res1[t], *ini.m_data.at(i).m_key_value.getValue(node).at(h).data());
                    //cout << ini.m_data.at(i).m_key_value.getValue(node).at(h).data() << " ";
                }
            }
        }
        if(i == 1)
        {
            unsigned t = 0;
            CString node;
            for(unsigned n = 1; n < ini.m_data.at(i).m_key_value.size() + 1; n++)
            {
                node = n;
                for(unsigned h = 0; h < ini.m_data.at(i).m_key_value.getValue(node).size(); h++, t++)
                {
                    CString temp = ini.m_data.at(i).m_key_value.getValue(node).at(h);
                    ASSERT_EQ(*res2[t], *ini.m_data.at(i).m_key_value.getValue(node).at(h).data());
                    //cout << ini.m_data.at(i).m_key_value.getValue(node).at(h).data() << " ";
                }
            }
        }
    }
    //ini.write_file("C:\\FilesC++\\test\\parse_ini\\file4.ini");
    //ini.show_all();
    //cout << "//-------------------------//" <<endl;
}

TEST(test056, test_CIni_change_value2)
{
    CIni ini;
    ini.read_file("C:\\FilesC++\\test\\parse_ini\\file3.ini");

    CString section1 = "Numbers";
    CString key1 = 3;
    CString old_num = 70;
    CString new_num = 81;
    ini.change_value(section1, key1, old_num, new_num);

    key1 = 10;
    old_num = 56;
    new_num = 64;
    ini.change_value(section1, key1, old_num, new_num);

    key1 = 11;
    old_num = 89;
    new_num = 101;
    ini.change_value(section1, key1, old_num, new_num);

    old_num = 25;
    new_num = 305;
    ini.change_value(section1, key1, old_num, new_num);

    const char *res1[18] =
    {
        /*1 =*/  "60",
        /*2 =*/  "35",
        /*3 =*/  "81", "45",
        /*4 =*/  "21",
        /*5 =*/  "42",
        /*6 =*/  "17",
        /*7 =*/  "11",
        /*8 =*/  "24",
        /*9 =*/  "23",
        /*10 =*/ "71", "64",
        /*11 =*/ "101", "78", "305",
        /*12 =*/ "68",
        /*13 =*/ "63",
        /*14 =*/ "69"
    };

    unsigned t = 0;
    CString node;
    for(unsigned n = 1; n < ini.m_data.at(0).m_key_value.size() + 1; n++)
    {
        node = n;
        for(unsigned h = 0; h < ini.m_data.at(0).m_key_value.getValue(node).size(); h++, t++)
        {
            ASSERT_EQ(*res1[t], *ini.m_data.at(0).m_key_value.getValue(node).at(h).data());
            //cout << ini.m_data.at(i).m_key_value.getValue(node).at(h).data() << " ";
        }
    }
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

    CString key1 = 11;
    CString num5 = 34;

    vec.push_back(num1);
    vec.push_back(num2);
    vec.push_back(num3);
    vec.push_back(num4);
    ini.add_value(section, key, vec);
    ini.add_value(section, key1, num5);

    const char *res1[23] =
    {
        /*1 =*/  "60",
        /*2 =*/  "35",
        /*3 =*/  "70", "45",
        /*4 =*/  "21",
        /*5 =*/  "42",
        /*6 =*/  "17",
        /*7 =*/  "11",
        /*8 =*/  "24",
        /*9 =*/  "23",
        /*10 =*/ "71", "56",
        /*11 =*/ "89", "78", "25", "34",
        /*12 =*/ "68",
        /*13 =*/ "63",
        /*14 =*/ "69",
        /*15 =*/ "90", "79", "35", "40"
    };

    unsigned t = 0;
    CString node;
    for(unsigned n = 1; n < ini.m_data.at(0).m_key_value.size() + 1; n++)
    {
        node = n;
        for(unsigned h = 0; h < ini.m_data.at(0).m_key_value.getValue(node).size(); h++, t++)
        {
            ASSERT_EQ(*res1[t], *ini.m_data.at(0).m_key_value.getValue(node).at(h).data());
            //cout << ini.m_data.at(i).m_key_value.getValue(node).at(h).data() << " ";
        }
    }

    //ini.write_file("C:\\FilesC++\\test\\parse_ini\\file4.ini");
    //ini.show_all();
    cout << "//-------------------------//" <<endl;
}
#endif // CINI_TEST_H
