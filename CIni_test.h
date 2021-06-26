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


TEST(test053, test_CIni_create_ini_file)
{
    CIni new_file;

    /*содержимое ini-файла "test" имеет следующий вид:
        [Numbers]
        ;This section contains the numbers
        zero =  60,
        one =  35,
        eight =  70, 45,
        two =  21,
        seven =  42,
        three =  17,
        four =  11,
        five =  24,
        six =  23,
        twelve = 71, 56,
        thirteen = 89, 78, 25,
        nine = 68,
        ten = 63,
        eleven = 69
    */
    //создание контента для заполнения ini-файла
    CString name_section = "Numbers";
    new_file.add_name_section(name_section);

    CString comment_section = "This section contains the numbers";
    new_file.add_comment_section(name_section, comment_section);

    CMap<CString, CVector<CString>> key_value;

    CString k1 = "zero"; CVector<CString> vec1;
    vec1.push_back(60);
    key_value.add_pair(k1, vec1);

    CString k2 = "one"; CVector<CString> vec2;
    vec2.push_back(35);
    key_value.add_pair(k2, vec2);

    CString k3 = "eight"; CVector<CString> vec3;
    vec3.push_back(70);
    vec3.push_back(45);
    key_value.add_pair(k3, vec3);

    CString k4 = "two"; CVector<CString> vec4;
    vec4.push_back(21);
    key_value.add_pair(k4, vec4);

    CString k5 = "seven"; CVector<CString> vec5;
    vec5.push_back(42);
    key_value.add_pair(k5, vec5);

    CString k6 = "three"; CVector<CString> vec6;
    vec6.push_back(17);
    key_value.add_pair(k6, vec6);

    CString k7 = "four"; CVector<CString> vec7;
    vec7.push_back(11);
    key_value.add_pair(k7, vec7);

    CString k8 = "five"; CVector<CString> vec8;
    vec8.push_back(24);
    key_value.add_pair(k8, vec8);

    CString k9 = "six"; CVector<CString> vec9;
    vec9.push_back(23);
    key_value.add_pair(k9, vec9);

    CString k10 = "twelve"; CVector<CString> vec10;
    vec10.push_back(71);
    vec10.push_back(56);
    key_value.add_pair(k10, vec10);

    CString k11 = "thirteen"; CVector<CString> vec11;
    vec11.push_back(89);
    vec11.push_back(78);
    vec11.push_back(25);
    key_value.add_pair(k11, vec11);

    CString k12 = "nine"; CVector<CString> vec12;
    vec12.push_back(68);
    key_value.add_pair(k12, vec12);

    CString k13 = "ten"; CVector<CString> vec13;
    vec13.push_back(63);
    key_value.add_pair(k13, vec13);

    CString k14 = "eleven"; CVector<CString> vec14;
    vec14.push_back(69);
    key_value.add_pair(k14, vec14);

    new_file.add_key_value(name_section, key_value);

    string name_file = "test";

    //создание пустого ini-файла
    new_file.create_file(name_file);

    //его заполнение
    new_file.write_file(name_file);

    //проверка содержимого ini-файла
    CIni check_file;
    //чтение ini-файла
    check_file.read_file(name_file);

    //поиск секции по name_section
    ASSERT_TRUE(check_file.search_name_section(name_section));

    //получение комментария к секции
    const char *res = "This section contains the numbers";
    ASSERT_STREQ(res, check_file.get_comment_section(name_section));

    ASSERT_TRUE(check_file.search_key(name_section, k1));
    ASSERT_TRUE(vec1 == check_file.getValue(name_section, k1));

    ASSERT_TRUE(check_file.search_key(name_section, k2));
    ASSERT_TRUE(vec2 == check_file.getValue(name_section, k2));

    ASSERT_TRUE(check_file.search_key(name_section, k3));
    ASSERT_TRUE(vec3 == check_file.getValue(name_section, k3));

    ASSERT_TRUE(check_file.search_key(name_section, k4));
    ASSERT_TRUE(vec4 == check_file.getValue(name_section, k4));

    ASSERT_TRUE(check_file.search_key(name_section, k5));
    ASSERT_TRUE(vec5 == check_file.getValue(name_section, k5));

    ASSERT_TRUE(check_file.search_key(name_section, k6));
    ASSERT_TRUE(vec6 == check_file.getValue(name_section, k6));

    ASSERT_TRUE(check_file.search_key(name_section, k7));
    ASSERT_TRUE(vec7 == check_file.getValue(name_section, k7));

    ASSERT_TRUE(check_file.search_key(name_section, k8));
    ASSERT_TRUE(vec8 == check_file.getValue(name_section, k8));

    ASSERT_TRUE(check_file.search_key(name_section, k9));
    ASSERT_TRUE(vec9 == check_file.getValue(name_section, k9));

    ASSERT_TRUE(check_file.search_key(name_section, k10));
    ASSERT_TRUE(vec10 == check_file.getValue(name_section, k10));

    ASSERT_TRUE(check_file.search_key(name_section, k11));
    ASSERT_TRUE(vec11 == check_file.getValue(name_section, k11));

    ASSERT_TRUE(check_file.search_key(name_section, k12));
    ASSERT_TRUE(vec12 == check_file.getValue(name_section, k12));

    ASSERT_TRUE(check_file.search_key(name_section, k13));
    ASSERT_TRUE(vec13 == check_file.getValue(name_section, k13));

    ASSERT_TRUE(check_file.search_key(name_section, k14));
    ASSERT_TRUE(vec14 == check_file.getValue(name_section, k14));



    //удаление ini-файла
    new_file.delete_file(name_file);
}

TEST(test053, test_CIni_change_m_name_section_delete_value_change_value)
{
    /*содержимое ini-файла "test" до внесённых изменений имеет следующий вид:
        [Numbers]
        ;This section contains the numbers
        zero =  60,
        one =  35,
        eight =  70, 45,
        two =  21,
        seven =  42,
        three =  17,
        four =  11,
        five =  24,
        six =  23,
        twelve = 71, 56,
        thirteen = 89, 78, 25,
        nine = 68,
        ten = 63,
        eleven = 69

        [Strings]
        ;This section contains the strings
        zero =  "ABCDEFGHIJKLM",
        one =  "ABCDEFGH",
        two =  "ABCDE",
        three =  "ABCD",
        four =  "ABC",
        five =  "A",
        six =  "AB",
        seven =  "ABCDEF",
        eight =  "ABCDEFGHIJ",
        nine = "ABCDEFGHI",
        ten = "ABCDEFGHIJKL",
        eleven = "ABCDEFGHIJK",
        twelve = "ABCDEFGHIJKLMNOPQRS",
        thirteen = "ABCDEFGHIJKLMNO",
        fourteen = "ABCDEFGHIJKLMN",
        fifteen = "ABCDEFGHIJKLMNOPQ",
        sixteen = "ABCDEFGHIJKLMNOP",
        seventeen = "ABCDEFGHIJKLMNOPQR",
        eighteen = "ABCDEFGHIJKLMNOPQRSTUV",
        nineteen = "ABCDEFGHIJKLMNOPQRSTU",
        twenty = "ABCDEFGHIJKLMNOPQRST",
        twenty-one = "ABCDEFGHIJKLMNOPQRSTUVWX",
        twenty-two = "ABCDEFGHIJKLMNOPQRSTUVW",
        twenty-three = "ABCDEFGHIJKLMNOPQRSTUVWXY",
        tewnty-four = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    */

}

#endif // CINI_TEST_H
