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

TEST(test053, test_CIni_change_m_name_section_delete_value)
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
    //создание контента для заполнения ini-файла
    //первая секция
    CIni new_file;
    CString old_name_0 = "Numbers";
    new_file.add_name_section(old_name_0);

    CString comment_section_0 = "This section contains the numbers";
    new_file.add_comment_section(old_name_0, comment_section_0);

    CMap<CString, CVector<CString>> key_value_0;

    CString k1 = "zero"; CVector<CString> vec1;
    vec1.push_back(60);
    key_value_0.add_pair(k1, vec1);

    CString k2 = "one"; CVector<CString> vec2;
    vec2.push_back(35);
    key_value_0.add_pair(k2, vec2);

    CString k3 = "eight"; CVector<CString> vec3;
    vec3.push_back(70);
    vec3.push_back(45);
    key_value_0.add_pair(k3, vec3);

    CString k4 = "two"; CVector<CString> vec4;
    vec4.push_back(21);
    key_value_0.add_pair(k4, vec4);

    CString k5 = "seven"; CVector<CString> vec5;
    vec5.push_back(42);
    key_value_0.add_pair(k5, vec5);

    CString k6 = "three"; CVector<CString> vec6;
    vec6.push_back(17);
    key_value_0.add_pair(k6, vec6);

    CString k7 = "four"; CVector<CString> vec7;
    vec7.push_back(11);
    key_value_0.add_pair(k7, vec7);

    CString k8 = "five"; CVector<CString> vec8;
    vec8.push_back(24);
    key_value_0.add_pair(k8, vec8);

    CString k9 = "six"; CVector<CString> vec9;
    vec9.push_back(23);
    key_value_0.add_pair(k9, vec9);

    CString k10 = "twelve"; CVector<CString> vec10;
    vec10.push_back(71);
    vec10.push_back(56);
    key_value_0.add_pair(k10, vec10);

    CString k11 = "thirteen"; CVector<CString> vec11;
    vec11.push_back(89);
    vec11.push_back(78);
    vec11.push_back(25);
    key_value_0.add_pair(k11, vec11);

    CString k12 = "nine"; CVector<CString> vec12;
    vec12.push_back(68);
    key_value_0.add_pair(k12, vec12);

    CString k13 = "ten"; CVector<CString> vec13;
    vec13.push_back(63);
    key_value_0.add_pair(k13, vec13);

    CString k14 = "eleven"; CVector<CString> vec14;
    vec14.push_back(69);
    key_value_0.add_pair(k14, vec14);

    new_file.add_key_value(old_name_0, key_value_0);

    //вторая секция
    CString old_name_1 = "Strings";
    new_file.add_name_section(old_name_1);

    CString comment_section_1 = "And this section containts the strings";
    new_file.add_comment_section(old_name_1, comment_section_1);

    CMap<CString, CVector<CString>> key_value_1;

    CString key15 = "zero"; CVector<CString> value15;
    value15.push_back("ABCDEFGHIJKLM");
    key_value_1.add_pair(key15, value15);

    CString key16 = "one"; CVector<CString> value16;
    value16.push_back("ABCDEFGH");
    key_value_1.add_pair(key16, value16);

    CString key17 = "two"; CVector<CString> value17;
    value17.push_back("ABCDE");
    key_value_1.add_pair(key17, value17);

    CString key18 = "three"; CVector<CString> value18;
    value18.push_back("ABCD");
    key_value_1.add_pair(key18, value18);

    CString key19 = "four"; CVector<CString> value19;
    value19.push_back("ABC");
    key_value_1.add_pair(key19, value19);

    CString key20 = "five"; CVector<CString> value20;
    value20.push_back("A");
    key_value_1.add_pair(key20, value20);

    CString key21 = "six"; CVector<CString> value21;
    value21.push_back("AB");
    key_value_1.add_pair(key21, value21);

    CString key22 = "seven"; CVector<CString> value22;
    value22.push_back("ABCDEF");
    key_value_1.add_pair(key22, value22);

    CString key23 = "eight"; CVector<CString> value23;
    value23.push_back("ABCDEFGHIJ");
    key_value_1.add_pair(key23, value23);

    CString key24 = "nine"; CVector<CString> value24;
    value24.push_back("ABCDEFGHI");
    key_value_1.add_pair(key24, value24);

    CString key25 = "ten"; CVector<CString> value25;
    value25.push_back("ABCDEFGHIJKL");
    key_value_1.add_pair(key25, value25);

    CString key26 = "eleven"; CVector<CString> value26;
    value26.push_back("ABCDEFGHIJK");
    key_value_1.add_pair(key26, value26);

    CString key27 = "twelve"; CVector<CString> value27;
    value27.push_back("ABCDEFGHIJKLMNOPQRS");
    key_value_1.add_pair(key27, value27);

    CString key28 = "thirteen"; CVector<CString> value28;
    value28.push_back("ABCDEFGHIJKLMNO");
    key_value_1.add_pair(key28, value28);

    CString key29 = "fourteen"; CVector<CString> value29;
    value29.push_back("ABCDEFGHIJKLMN");
    key_value_1.add_pair(key29, value29);

    CString key30 = "fifteen"; CVector<CString> value30;
    value30.push_back("ABCDEFGHIJKLMNOPQ");
    key_value_1.add_pair(key29, value29);

    CString key31 = "sixteen"; CVector<CString> value31;
    value31.push_back("ABCDEFGHIJKLMNOP");
    key_value_1.add_pair(key31, value31);

    CString key32 = "seventeen"; CVector<CString> value32;
    value32.push_back("ABCDEFGHIJKLMNOPQR");
    key_value_1.add_pair(key32, value32);

    CString key33 = "eighteen"; CVector<CString> value33;
    value33.push_back("ABCDEFGHIJKLMNOPQRSTUV");
    key_value_1.add_pair(key33, value33);

    CString key34 = "nineteen"; CVector<CString> value34;
    value34.push_back("ABCDEFGHIJKLMNOPQRSTU");
    key_value_1.add_pair(key34, value34);

    CString key35 = "twenty"; CVector<CString> value35;
    value35.push_back("ABCDEFGHIJKLMNOPQRST");
    key_value_1.add_pair(key35, value35);

    CString key36 = "twenty-one"; CVector<CString> value36;
    value36.push_back("ABCDEFGHIJKLMNOPQRSTUVWX");
    key_value_1.add_pair(key36, value36);

    CString key37 = "twenty-two"; CVector<CString> value37;
    value37.push_back("ABCDEFGHIJKLMNOPQRSTUVW");
    key_value_1.add_pair(key37, value37);

    CString key38 = "twenty-three"; CVector<CString> value38;
    value38.push_back("ABCDEFGHIJKLMNOPQRSTUVWXY");
    key_value_1.add_pair(key38, value38);

    CString key39 = "twenty-four"; CVector<CString> value39;
    value39.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    key_value_1.add_pair(key39, value39);

    new_file.add_key_value(old_name_1, key_value_1);

    //изменение имён секции
    CString new_name_0 = "Integers";
    new_file.change_name_section(old_name_0, new_name_0);
    CString new_name_1 = "Alphabet";
    new_file.change_name_section(old_name_1, new_name_1);
    //удаление значений
    new_file.delete_value(new_name_0, k1);
    new_file.delete_value(new_name_0, k3);
    new_file.delete_value(new_name_0, k10);
    new_file.delete_value(new_name_0, k11);
    new_file.delete_value(new_name_0, k14);

    new_file.delete_value(new_name_1, key20);
    new_file.delete_value(new_name_1, key27);
    new_file.delete_value(new_name_1, key31);
    new_file.delete_value(new_name_1, key35);
    new_file.delete_value(new_name_1, key37);
    new_file.delete_value(new_name_1, key39);
    /*содержимое ini-файла "test" после внесённых изменений имеет следующий вид:
        [Integers]
        ;This section contains the numbers
        one =  35,
        two =  21,
        seven =  42,
        three =  17,
        four =  11,
        five =  24,
        six =  23,
        nine = 68,
        ten = 63,

        [Alphabet]
        ;And this section containts the strings
        zero =  "ABCDEFGHIJKLM",
        one =  "ABCDEFGH",
        two =  "ABCDE",
        three =  "ABCD",
        four =  "ABC",
        six =  "AB",
        seven =  "ABCDEF",
        eight =  "ABCDEFGHIJ",
        nine = "ABCDEFGHI",
        ten = "ABCDEFGHIJKL",
        eleven = "ABCDEFGHIJK",
        thirteen = "ABCDEFGHIJKLMNO",
        fourteen = "ABCDEFGHIJKLMN",
        fifteen = "ABCDEFGHIJKLMNOPQ",
        seventeen = "ABCDEFGHIJKLMNOPQR",
        eighteen = "ABCDEFGHIJKLMNOPQRSTUV",
        nineteen = "ABCDEFGHIJKLMNOPQRSTU",
        twenty-one = "ABCDEFGHIJKLMNOPQRSTUVWX",
        twenty-three = "ABCDEFGHIJKLMNOPQRSTUVWXY"
    */
    string name_file = "test";
    new_file.create_file(name_file);
    new_file.write_file(name_file);

    CIni check_file;
    check_file.read_file(name_file);
    //проверка наличия первой секции
    ASSERT_TRUE(check_file.search_name_section(new_name_0));

    //получение комментария к секции
    const char *res = "This section contains the numbers";
    ASSERT_STREQ(res, check_file.get_comment_section(new_name_0));

    //проверка значений первой секции
    ASSERT_FALSE(check_file.search_key(new_name_0, k1));

    ASSERT_TRUE(check_file.search_key(new_name_0, k2));
    ASSERT_TRUE(vec2 == check_file.getValue(new_name_0, k2));

    ASSERT_TRUE(check_file.search_key(new_name_0, k3));
    ASSERT_TRUE(vec3 == check_file.getValue(new_name_0, k3));

    ASSERT_TRUE(check_file.search_key(new_name_0, k4));
    ASSERT_TRUE(vec4 == check_file.getValue(new_name_0, k4));

    ASSERT_TRUE(check_file.search_key(new_name_0, k5));
    ASSERT_TRUE(vec5 == check_file.getValue(new_name_0, k5));

    ASSERT_TRUE(check_file.search_key(new_name_0, k6));
    ASSERT_TRUE(vec6 == check_file.getValue(new_name_0, k6));

    ASSERT_TRUE(check_file.search_key(new_name_0, k7));
    ASSERT_TRUE(vec7 == check_file.getValue(new_name_0, k7));

    ASSERT_TRUE(check_file.search_key(new_name_0, k8));
    ASSERT_TRUE(vec8 == check_file.getValue(new_name_0, k8));

    ASSERT_TRUE(check_file.search_key(new_name_0, k9));
    ASSERT_TRUE(vec9 == check_file.getValue(new_name_0, k9));

    ASSERT_FALSE(check_file.search_key(new_name_0, k10));

    ASSERT_FALSE(check_file.search_key(new_name_0, k11));

    ASSERT_TRUE(check_file.search_key(new_name_0, k12));
    ASSERT_TRUE(vec12 == check_file.getValue(new_name_0, k12));

    ASSERT_TRUE(check_file.search_key(new_name_0, k13));
    ASSERT_TRUE(vec13 == check_file.getValue(new_name_0, k13));

    ASSERT_FALSE(check_file.search_key(new_name_0, k14));

    //проверка наличия второй секции
    ASSERT_TRUE(check_file.search_name_section(new_name_1));

    //получение комментария к секции
    const char *res1 = "And this section containts the strings";
    ASSERT_STREQ(res1, check_file.get_comment_section(new_name_1));

    //проверка значений второй секции
    ASSERT_FALSE(check_file.search_key(new_name_1, k1));

    ASSERT_TRUE(check_file.search_key(new_name_1, key15));
    ASSERT_TRUE(value15 == check_file.getValue(new_name_1, key15));

    ASSERT_TRUE(check_file.search_key(new_name_1, key16));
    ASSERT_TRUE(value16 == check_file.getValue(new_name_1, key16));

    ASSERT_TRUE(check_file.search_key(new_name_1, key17));
    ASSERT_TRUE(value17 == check_file.getValue(new_name_1, key17));

    ASSERT_TRUE(check_file.search_key(new_name_1, key18));
    ASSERT_TRUE(value18 == check_file.getValue(new_name_1, key18));

    ASSERT_TRUE(check_file.search_key(new_name_1, key19));
    ASSERT_TRUE(value19 == check_file.getValue(new_name_1, key19));

    ASSERT_FALSE(check_file.search_key(new_name_1, key20));

    ASSERT_TRUE(check_file.search_key(new_name_1, key21));
    ASSERT_TRUE(value21 == check_file.getValue(new_name_1, key21));

    ASSERT_TRUE(check_file.search_key(new_name_1, key22));
    ASSERT_TRUE(value22 == check_file.getValue(new_name_1, key22));

    ASSERT_TRUE(check_file.search_key(new_name_1, key23));
    ASSERT_TRUE(value23 == check_file.getValue(new_name_1, key23));

    ASSERT_TRUE(check_file.search_key(new_name_1, key24));
    ASSERT_TRUE(value24 == check_file.getValue(new_name_1, key24));

    ASSERT_TRUE(check_file.search_key(new_name_1, key25));
    ASSERT_TRUE(value25 == check_file.getValue(new_name_1, key25));

    ASSERT_TRUE(check_file.search_key(new_name_1, key26));
    ASSERT_TRUE(value26 == check_file.getValue(new_name_1, key26));

    ASSERT_FALSE(check_file.search_key(new_name_1, key27));

    ASSERT_TRUE(check_file.search_key(new_name_1, key28));
    ASSERT_TRUE(value28 == check_file.getValue(new_name_1, key28));

    ASSERT_TRUE(check_file.search_key(new_name_1, key29));
    ASSERT_TRUE(value29 == check_file.getValue(new_name_1, key29));

    ASSERT_TRUE(check_file.search_key(new_name_1, key30));
    ASSERT_TRUE(value30 == check_file.getValue(new_name_1, key30));

    ASSERT_FALSE(check_file.search_key(new_name_1, key31));

    ASSERT_TRUE(check_file.search_key(new_name_1, key32));
    ASSERT_TRUE(value32 == check_file.getValue(new_name_1, key32));

    ASSERT_TRUE(check_file.search_key(new_name_1, key33));
    ASSERT_TRUE(value33 == check_file.getValue(new_name_1, key33));

    ASSERT_TRUE(check_file.search_key(new_name_1, key34));
    ASSERT_TRUE(value34 == check_file.getValue(new_name_1, key34));

    ASSERT_FALSE(check_file.search_key(new_name_1, key35));

    ASSERT_TRUE(check_file.search_key(new_name_1, key36));
    ASSERT_TRUE(value36 == check_file.getValue(new_name_1, key36));

    ASSERT_FALSE(check_file.search_key(new_name_1, key37));

    ASSERT_TRUE(check_file.search_key(new_name_1, key38));
    ASSERT_TRUE(value38 == check_file.getValue(new_name_1, key38));

    ASSERT_FALSE(check_file.search_key(new_name_1, key39));

    check_file.delete_file(name_file);
}

#endif // CINI_TEST_H
