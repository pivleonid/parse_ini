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

TEST(test052, test_CIni_create_ini_file)
{
    CIni new_file;

    CString name = "Numbers";
    new_file.add_name_section(name);

    CString comment = "This section contains the numbers";
    new_file.add_name_comment(name, comment);

    CMap<CString, CVector<CString>> key_value;

    CString k1 = 1; CVector<CString> vec1;
    vec1.push_back(60);
    key_value.add_pair(k1, vec1);

    CString k2 = 2; CVector<CString> vec2;
    vec2.push_back(35);
    key_value.add_pair(k2, vec2);

    CString k3 = 3; CVector<CString> vec3;
    vec3.push_back(70);
    vec3.push_back(45);
    key_value.add_pair(k3, vec3);

    CString k4 = 4; CVector<CString> vec4;
    vec4.push_back(21);
    key_value.add_pair(k4, vec4);

    CString k5 = 5; CVector<CString> vec5;
    vec5.push_back(42);
    key_value.add_pair(k5, vec5);

    CString k6 = 6; CVector<CString> vec6;
    vec6.push_back(17);
    key_value.add_pair(k6, vec6);

    CString k7 = 7; CVector<CString> vec7;
    vec7.push_back(11);
    key_value.add_pair(k7, vec7);

    CString k8 = 8; CVector<CString> vec8;
    vec8.push_back(24);
    key_value.add_pair(k8, vec8);

    CString k9 = 9; CVector<CString> vec9;
    vec9.push_back(23);
    key_value.add_pair(k9, vec9);

    CString k10 = 10; CVector<CString> vec10;
    vec10.push_back(71);
    vec10.push_back(56);
    key_value.add_pair(k10, vec10);

    CString k11 = 11; CVector<CString> vec11;
    vec11.push_back(89);
    vec11.push_back(78);
    vec11.push_back(25);
    key_value.add_pair(k11, vec11);

    CString k12 = 12; CVector<CString> vec12;
    vec12.push_back(68);
    key_value.add_pair(k12, vec12);

    CString k13 = 13; CVector<CString> vec13;
    vec13.push_back(63);
    key_value.add_pair(k13, vec13);

    CString k14 = 14; CVector<CString> vec14;
    vec14.push_back(69);
    key_value.add_pair(k14, vec14);

    new_file.add_key_value(name, key_value);

    new_file.create_file("C:\\FilesC++\\test\\parse_ini\\test.ini");
    new_file.write_file("C:\\FilesC++\\test\\parse_ini\\test.ini");

    CIni check_file;
    check_file.read_file("C:\\FilesC++\\test\\parse_ini\\test.ini");

    const char *res = "Numbers";

    const char *res1[5]  =
    {
        "This", "section", "contains", "the", "numbers"
    };

    const char *res2[18] =
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

    ASSERT_STREQ(res, check_file.m_data.at(0).m_name_section.data());

    unsigned k = 0;
    for(unsigned j = 0; j < check_file.m_data.at(0).m_name_comment.size(); j++, k++)
    {
        ASSERT_STREQ(res1[k], check_file.m_data.at(0).m_name_comment.at(j).data());
    }

    unsigned t = 0;
    CString node;
    for(unsigned n = 1; n < check_file.m_data.at(0).m_key_value.size() + 1; n++)
    {
        node = n;
        for(unsigned h = 0; h < check_file.m_data.at(0).m_key_value.getValue(node).size(); h++, t++)
        {
            ASSERT_STREQ(res2[t], check_file.m_data.at(0).m_key_value.getValue(node).at(h).data());
        }
    }

    new_file.delete_file("C:\\FilesC++\\test\\parse_ini\\test.ini");
}


#endif // CINI_TEST_H
