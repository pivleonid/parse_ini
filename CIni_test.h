#ifndef CINI_TEST_H
#define CINI_TEST_H
#include "CIni.h"
#include <gtest/include/gtest/gtest.h>

TEST(test053, test_CIni_create_ini_file)
{
    CIni new_file;

    /*содержимое ini-файла "test" имеет следующий вид:
        [Numbers]
        ;This section contains the numbers
        zero =  60
        one =  35
        eight = 70, 45
        two =  21
        seven =  42
        three =  17
        four =  11
        five =  24
        six =  23
        twelve = 71, 56
        thirteen = 89, 78, 25
        nine = 68
        ten = 63
        eleven = 69
    */
    //создание контента для заполнения ini-файла
    //присваивание 1 секции имени
    CString name_section = "Numbers";
    new_file.add_name_section(name_section);
    // комментарий к 1 секции
    CString comment_section = "This section contains the numbers";
    new_file.add_comment_section(name_section, comment_section);

    //контент 1 секции
    CMap<CString, CVector<CString>> key_value;

    CString zero = "zero"; CVector<CString> v60;
    v60.push_back(60);
    key_value.add_pair(zero, v60);

    CString one = "one"; CVector<CString> v35;
    v35.push_back(35);
    key_value.add_pair(one, v35);

    CString eight = "eight"; CVector<CString> v70_45;
    v70_45.push_back(70);
    v70_45.push_back(45);
    key_value.add_pair(eight, v70_45);

    CString two = "two"; CVector<CString> v21;
    v21.push_back(21);
    key_value.add_pair(two, v21);

    CString seven = "seven"; CVector<CString> v42;
    v42.push_back(42);
    key_value.add_pair(seven, v42);

    CString three = "three"; CVector<CString> v17;
    v17.push_back(17);
    key_value.add_pair(three, v17);

    CString four = "four"; CVector<CString> v11;
    v11.push_back(11);
    key_value.add_pair(four, v11);

    CString five = "five"; CVector<CString> v24;
    v24.push_back(24);
    key_value.add_pair(five, v24);

    CString six = "six"; CVector<CString> v23;
    v23.push_back(23);
    key_value.add_pair(six, v23);

    CString twelve = "twelve"; CVector<CString> v71_56;
    v71_56.push_back(71);
    v71_56.push_back(56);
    key_value.add_pair(twelve, v71_56);

    CString thirteen = "thirteen"; CVector<CString> v89_78_25;
    v89_78_25.push_back(89);
    v89_78_25.push_back(78);
    v89_78_25.push_back(25);
    key_value.add_pair(thirteen, v89_78_25);

    CString nine = "nine"; CVector<CString> v68;
    v68.push_back(68);
    key_value.add_pair(nine, v68);

    CString ten = "ten"; CVector<CString> v63;
    v63.push_back(63);
    key_value.add_pair(ten, v63);

    CString eleven = "eleven"; CVector<CString> v69;
    v69.push_back(69);
    key_value.add_pair(eleven, v69);

    new_file.add_key_value(name_section, key_value);

    //имя 2 секции
    CString name_section_1 = "Strings";
    new_file.add_name_section(name_section_1);

    //комментарий ко 2 секции
    CString comment_section_1 = "And this section containts the strings";
    new_file.add_comment_section(name_section_1, comment_section_1);

    //контент 2 секции
    CMap<CString, CVector<CString>> key_value_1;

    CString zero_ = "zero"; CVector<CString> vlM;
    vlM.push_back("ABCDEFGHIJKLM");
    key_value_1.add_pair(zero_, vlM);

    CString one_ = "one"; CVector<CString> vlH;
    vlH.push_back("ABCDEFGH");
    key_value_1.add_pair(one_, vlH);

    CString two_ = "two"; CVector<CString> vlE;
    vlE.push_back("ABCDE");
    key_value_1.add_pair(two_, vlE);

    CString three_ = "three"; CVector<CString> vlD;
    vlD.push_back("ABCD");
    key_value_1.add_pair(three_, vlD);

    CString four_ = "four"; CVector<CString> vlC;
    vlC.push_back("ABC");
    key_value_1.add_pair(four_, vlC);

    CString five_ = "five"; CVector<CString> vlA;
    vlA.push_back("A");
    key_value_1.add_pair(five_, vlA);

    CString six_ = "six"; CVector<CString> vlB;
    vlB.push_back("AB");
    key_value_1.add_pair(six_, vlB);

    CString seven_ = "seven"; CVector<CString> vlF;
    vlF.push_back("ABCDEF");
    key_value_1.add_pair(seven_, vlF);

    CString eight_ = "eight"; CVector<CString> vlJ;
    vlJ.push_back("ABCDEFGHIJ");
    key_value_1.add_pair(eight_, vlJ);

    CString nine_ = "nine"; CVector<CString> vlI;
    vlI.push_back("ABCDEFGHI");
    key_value_1.add_pair(nine_, vlI);

    CString ten_ = "ten"; CVector<CString> vlL;
    vlL.push_back("ABCDEFGHIJKL");
    key_value_1.add_pair(ten_, vlL);

    CString eleven_ = "eleven"; CVector<CString> vlK;
    vlK.push_back("ABCDEFGHIJK");
    key_value_1.add_pair(eleven_, vlK);

    CString twelve_ = "twelve"; CVector<CString> vlS;
    vlS.push_back("ABCDEFGHIJKLMNOPQRS");
    key_value_1.add_pair(twelve_, vlS);

    CString thirteen_ = "thirteen"; CVector<CString> vlO;
    vlO.push_back("ABCDEFGHIJKLMNO");
    key_value_1.add_pair(thirteen_, vlO);

    CString fourteen_ = "fourteen"; CVector<CString> vlN;
    vlN.push_back("ABCDEFGHIJKLMN");
    key_value_1.add_pair(fourteen_, vlN);

    CString fifteen_ = "fifteen"; CVector<CString> vlQ;
    vlQ.push_back("ABCDEFGHIJKLMNOPQ");
    key_value_1.add_pair(fifteen_, vlQ);

    CString sixteen_ = "sixteen"; CVector<CString> vlP;
    vlP.push_back("ABCDEFGHIJKLMNOP");
    key_value_1.add_pair(sixteen_, vlP);

    CString seventeen_ = "seventeen"; CVector<CString> vlR;
    vlR.push_back("ABCDEFGHIJKLMNOPQR");
    key_value_1.add_pair(seventeen_, vlR);

    CString eighteen_ = "eighteen"; CVector<CString> vlV;
    vlV.push_back("ABCDEFGHIJKLMNOPQRSTUV");
    key_value_1.add_pair(eighteen_, vlV);

    CString nineteen_ = "nineteen"; CVector<CString> vlU;
    vlU.push_back("ABCDEFGHIJKLMNOPQRSTU");
    key_value_1.add_pair(nineteen_, vlU);

    CString twenty_ = "twenty"; CVector<CString> vlT;
    vlT.push_back("ABCDEFGHIJKLMNOPQRST");
    key_value_1.add_pair(twenty_, vlT);

    CString twenty_one_ = "twenty-one"; CVector<CString> vlX;
    vlX.push_back("ABCDEFGHIJKLMNOPQRSTUVWX");
    key_value_1.add_pair(twenty_one_, vlX);

    CString twenty_two_ = "twenty-two"; CVector<CString> vlW;
    vlW.push_back("ABCDEFGHIJKLMNOPQRSTUVW");
    key_value_1.add_pair(twenty_two_, vlW);


    CString twenty_three_ = "twenty-three"; CVector<CString> vlY;
    vlY.push_back("ABCDEFGHIJKLMNOPQRSTUVWXY");
    key_value_1.add_pair(twenty_three_, vlY);

    CString twenty_four_ = "twenty-four"; CVector<CString> vlZ;
    vlZ.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    key_value_1.add_pair(twenty_four_, vlZ);


    new_file.add_key_value(name_section_1, key_value_1);

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

    //проверка значений 1 секции
    ASSERT_TRUE(check_file.search_key(name_section, zero));
    ASSERT_TRUE(v60 == check_file.getValue(name_section, zero));

    ASSERT_TRUE(check_file.search_key(name_section, one));
    ASSERT_TRUE(v35 == check_file.getValue(name_section, one));

    ASSERT_TRUE(check_file.search_key(name_section, eight));
    ASSERT_TRUE(v70_45 == check_file.getValue(name_section, eight));

    ASSERT_TRUE(check_file.search_key(name_section, two));
    ASSERT_TRUE(v21 == check_file.getValue(name_section, two));

    ASSERT_TRUE(check_file.search_key(name_section, seven));
    ASSERT_TRUE(v42 == check_file.getValue(name_section, seven));

    ASSERT_TRUE(check_file.search_key(name_section, three));
    ASSERT_TRUE(v17 == check_file.getValue(name_section, three));

    ASSERT_TRUE(check_file.search_key(name_section, four));
    ASSERT_TRUE(v11 == check_file.getValue(name_section, four));

    ASSERT_TRUE(check_file.search_key(name_section, five));
    ASSERT_TRUE(v24 == check_file.getValue(name_section, five));

    ASSERT_TRUE(check_file.search_key(name_section, six));
    ASSERT_TRUE(v23 == check_file.getValue(name_section, six));

    ASSERT_TRUE(check_file.search_key(name_section, twelve));
    ASSERT_TRUE(v71_56 == check_file.getValue(name_section, twelve));

    ASSERT_TRUE(check_file.search_key(name_section, thirteen));
    ASSERT_TRUE(v89_78_25 == check_file.getValue(name_section, thirteen));

    ASSERT_TRUE(check_file.search_key(name_section, nine));
    ASSERT_TRUE(v68 == check_file.getValue(name_section, nine));

    ASSERT_TRUE(check_file.search_key(name_section, ten));
    ASSERT_TRUE(v63 == check_file.getValue(name_section, ten));

    ASSERT_TRUE(check_file.search_key(name_section, eleven));
    ASSERT_TRUE(v69 == check_file.getValue(name_section, eleven));

    //проверка значений 2 секции
    ASSERT_TRUE(check_file.search_key(name_section_1, zero_));
    ASSERT_TRUE(vlM == check_file.getValue(name_section_1, zero_));

    ASSERT_TRUE(check_file.search_key(name_section_1, one_));
    ASSERT_TRUE(vlH == check_file.getValue(name_section_1, one_));

    ASSERT_TRUE(check_file.search_key(name_section_1, two_));
    ASSERT_TRUE(vlE == check_file.getValue(name_section_1, two_));

    ASSERT_TRUE(check_file.search_key(name_section_1, three_));
    ASSERT_TRUE(vlD == check_file.getValue(name_section_1, three_));

    ASSERT_TRUE(check_file.search_key(name_section_1, four_));
    ASSERT_TRUE(vlC == check_file.getValue(name_section_1, four_));

    ASSERT_TRUE(check_file.search_key(name_section_1, five_));
    ASSERT_TRUE(vlA == check_file.getValue(name_section_1, five_));

    ASSERT_TRUE(check_file.search_key(name_section_1, six_));
    ASSERT_TRUE(vlB == check_file.getValue(name_section_1, six_));

    ASSERT_TRUE(check_file.search_key(name_section_1, seven_));
    ASSERT_TRUE(vlF == check_file.getValue(name_section_1, seven_));

    ASSERT_TRUE(check_file.search_key(name_section_1, eight_));
    ASSERT_TRUE(vlJ == check_file.getValue(name_section_1, eight_));

    ASSERT_TRUE(check_file.search_key(name_section_1, nine_));
    ASSERT_TRUE(vlI == check_file.getValue(name_section_1, nine_));

    ASSERT_TRUE(check_file.search_key(name_section_1, ten_));
    ASSERT_TRUE(vlL == check_file.getValue(name_section_1, ten_));

    ASSERT_TRUE(check_file.search_key(name_section_1, eleven_));
    ASSERT_TRUE(vlK == check_file.getValue(name_section_1, eleven_));

    ASSERT_TRUE(check_file.search_key(name_section_1, twelve_));
    ASSERT_TRUE(vlS == check_file.getValue(name_section_1, twelve_));

    ASSERT_TRUE(check_file.search_key(name_section_1, thirteen_));
    ASSERT_TRUE(vlO == check_file.getValue(name_section_1, thirteen_));

    ASSERT_TRUE(check_file.search_key(name_section_1, fourteen_));
    ASSERT_TRUE(vlN == check_file.getValue(name_section_1, fourteen_));

    ASSERT_TRUE(check_file.search_key(name_section_1, fifteen_));
    ASSERT_TRUE(vlQ == check_file.getValue(name_section_1, fifteen_));

    ASSERT_TRUE(check_file.search_key(name_section_1, sixteen_));
    ASSERT_TRUE(vlP == check_file.getValue(name_section_1, sixteen_));

    ASSERT_TRUE(check_file.search_key(name_section_1, seventeen_));
    ASSERT_TRUE(vlR == check_file.getValue(name_section_1, seventeen_));

    ASSERT_TRUE(check_file.search_key(name_section_1, eighteen_));
    ASSERT_TRUE(vlV == check_file.getValue(name_section_1, eighteen_));

    ASSERT_TRUE(check_file.search_key(name_section_1, nineteen_));
    ASSERT_TRUE(vlU == check_file.getValue(name_section_1, nineteen_));

    ASSERT_TRUE(check_file.search_key(name_section_1, twenty_));
    ASSERT_TRUE(vlT == check_file.getValue(name_section_1, twenty_));

    ASSERT_TRUE(check_file.search_key(name_section_1, twenty_one_));
    ASSERT_TRUE(vlX == check_file.getValue(name_section_1, twenty_one_));

    ASSERT_TRUE(check_file.search_key(name_section_1, twenty_two_));
    ASSERT_TRUE(vlW == check_file.getValue(name_section_1, twenty_two_));

    ASSERT_TRUE(check_file.search_key(name_section_1, twenty_three_));
    ASSERT_TRUE(vlY == check_file.getValue(name_section_1, twenty_three_));

    ASSERT_TRUE(check_file.search_key(name_section_1, twenty_four_));
    ASSERT_TRUE(vlZ == check_file.getValue(name_section_1, twenty_four_));

    //удаление ini-файла
    new_file.delete_file(name_file);
}

TEST(test054, test_CIni_change_m_name_section_delete_value)
{
    /*содержимое ini-файла "test" до внесённых изменений имеет следующий вид:
        [Numbers]
        ;This section contains the numbers
        zero =  60
        one =  35
        eight =  70, 45
        two =  21
        seven =  42
        three =  17
        four =  11
        five =  24
        six =  23
        twelve = 71, 56
        thirteen = 89, 78, 25
        nine = 68
        ten = 63
        eleven = 69

        [CStrings]
        ;This section contains the CStrings
        zero =  "ABCDEFGHIJKLM"
        one =  "ABCDEFGH"
        two =  "ABCDE"
        three =  "ABCD"
        four =  "ABC"
        five =  "A"
        six =  "AB"
        seven =  "ABCDEF"
        eight =  "ABCDEFGHIJ"
        nine = "ABCDEFGHI"
        ten = "ABCDEFGHIJKL"
        eleven = "ABCDEFGHIJK"
        twelve = "ABCDEFGHIJKLMNOPQRS"
        thirteen = "ABCDEFGHIJKLMNO"
        fourteen = "ABCDEFGHIJKLMN"
        fifteen = "ABCDEFGHIJKLMNOPQ"
        sixteen = "ABCDEFGHIJKLMNOP"
        seventeen = "ABCDEFGHIJKLMNOPQR"
        eighteen = "ABCDEFGHIJKLMNOPQRSTUV"
        nineteen = "ABCDEFGHIJKLMNOPQRSTU"
        twenty = "ABCDEFGHIJKLMNOPQRST"
        twenty-one = "ABCDEFGHIJKLMNOPQRSTUVWX"
        twenty-two = "ABCDEFGHIJKLMNOPQRSTUVW"
        twenty-three = "ABCDEFGHIJKLMNOPQRSTUVWXY"
        twenty-four = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    */
    //создание контента для заполнения ini-файла
    //первая секция
    CIni new_file;
    CString old_name_0 = "Numbers";
    new_file.add_name_section(old_name_0);

    CString comment_section_0 = "This section contains the numbers";
    new_file.add_comment_section(old_name_0, comment_section_0);

    CMap<CString, CVector<CString>> key_value_0;

    CString zero = "zero"; CVector<CString> v60;
    v60.push_back(60);
    key_value_0.add_pair(zero, v60);

    CString one = "one"; CVector<CString> v35;
    v35.push_back(35);
    key_value_0.add_pair(one, v35);

    CString eight = "eight"; CVector<CString> v70_45;
    v70_45.push_back(70);
    v70_45.push_back(45);
    key_value_0.add_pair(eight, v70_45);

    CString two = "two"; CVector<CString> v21;
    v21.push_back(21);
    key_value_0.add_pair(two, v21);

    CString seven = "seven"; CVector<CString> v42;
    v42.push_back(42);
    key_value_0.add_pair(seven, v42);

    CString three = "three"; CVector<CString> v17;
    v17.push_back(17);
    key_value_0.add_pair(three, v17);

    CString four = "four"; CVector<CString> v11;
    v11.push_back(11);
    key_value_0.add_pair(four, v11);

    CString five = "five"; CVector<CString> v24;
    v24.push_back(24);
    key_value_0.add_pair(five, v24);

    CString six = "six"; CVector<CString> v23;
    v23.push_back(23);
    key_value_0.add_pair(six, v23);

    CString twelve = "twelve"; CVector<CString> v71_56;
    v71_56.push_back(71);
    v71_56.push_back(56);
    key_value_0.add_pair(twelve, v71_56);

    CString thirteen = "thirteen"; CVector<CString> v89_78_25;
    v89_78_25.push_back(89);
    v89_78_25.push_back(78);
    v89_78_25.push_back(25);
    key_value_0.add_pair(thirteen, v89_78_25);

    CString nine = "nine"; CVector<CString> v68;
    v68.push_back(68);
    key_value_0.add_pair(nine, v68);

    CString ten = "ten"; CVector<CString> v63;
    v63.push_back(63);
    key_value_0.add_pair(ten, v63);

    CString eleven = "eleven"; CVector<CString> v69;
    v69.push_back(69);
    key_value_0.add_pair(eleven, v69);

    new_file.add_key_value(old_name_0, key_value_0);

    //вторая секция
    CString old_name_1 = "Strings";
    new_file.add_name_section(old_name_1);

    CString comment_section_1 = "And this section containts the strings";
    new_file.add_comment_section(old_name_1, comment_section_1);

    CMap<CString, CVector<CString>> key_value_1;

    CString zero_ = "zero"; CVector<CString> vlM;
    vlM.push_back("ABCDEFGHIJKLM");
    key_value_1.add_pair(zero_, vlM);

    CString one_ = "one"; CVector<CString> vlH;
    vlH.push_back("ABCDEFGH");
    key_value_1.add_pair(one_, vlH);

    CString two_ = "two"; CVector<CString> vlE;
    vlE.push_back("ABCDE");
    key_value_1.add_pair(two_, vlE);

    CString three_ = "three"; CVector<CString> vlD;
    vlD.push_back("ABCD");
    key_value_1.add_pair(three_, vlD);

    CString four_ = "four"; CVector<CString> vlC;
    vlC.push_back("ABC");
    key_value_1.add_pair(four_, vlC);

    CString five_ = "five"; CVector<CString> vlA;
    vlA.push_back("A");
    key_value_1.add_pair(five_, vlA);

    CString six_ = "six"; CVector<CString> vlB;
    vlB.push_back("AB");
    key_value_1.add_pair(six_, vlB);

    CString seven_ = "seven"; CVector<CString> vlF;
    vlF.push_back("ABCDEF");
    key_value_1.add_pair(seven_, vlF);

    CString eight_ = "eight"; CVector<CString> vlJ;
    vlJ.push_back("ABCDEFGHIJ");
    key_value_1.add_pair(eight_, vlJ);

    CString nine_ = "nine"; CVector<CString> vlI;
    vlI.push_back("ABCDEFGHI");
    key_value_1.add_pair(nine_, vlI);

    CString ten_ = "ten"; CVector<CString> vlL;
    vlL.push_back("ABCDEFGHIJKL");
    key_value_1.add_pair(ten_, vlL);

    CString eleven_ = "eleven"; CVector<CString> vlK;
    vlK.push_back("ABCDEFGHIJK");
    key_value_1.add_pair(eleven_, vlK);

    CString twelve_ = "twelve"; CVector<CString> vlS;
    vlS.push_back("ABCDEFGHIJKLMNOPQRS");
    key_value_1.add_pair(twelve_, vlS);

    CString thirteen_ = "thirteen"; CVector<CString> vlO;
    vlO.push_back("ABCDEFGHIJKLMNO");
    key_value_1.add_pair(thirteen_, vlO);

    CString fourteen_ = "fourteen"; CVector<CString> vlN;
    vlN.push_back("ABCDEFGHIJKLMN");
    key_value_1.add_pair(fourteen_, vlN);

    CString fifteen_ = "fifteen"; CVector<CString> vlQ;
    vlQ.push_back("ABCDEFGHIJKLMNOPQ");
    key_value_1.add_pair(fifteen_, vlQ);

    CString sixteen_ = "sixteen"; CVector<CString> vlP;
    vlP.push_back("ABCDEFGHIJKLMNOP");
    key_value_1.add_pair(sixteen_, vlP);

    CString seventeen_ = "seventeen"; CVector<CString> vlR;
    vlR.push_back("ABCDEFGHIJKLMNOPQR");
    key_value_1.add_pair(seventeen_, vlR);

    CString eighteen_ = "eighteen"; CVector<CString> vlV;
    vlV.push_back("ABCDEFGHIJKLMNOPQRSTUV");
    key_value_1.add_pair(eighteen_, vlV);

    CString nineteen_ = "nineteen"; CVector<CString> vlU;
    vlU.push_back("ABCDEFGHIJKLMNOPQRSTU");
    key_value_1.add_pair(nineteen_, vlU);

    CString twenty_ = "twenty"; CVector<CString> vlT;
    vlT.push_back("ABCDEFGHIJKLMNOPQRST");
    key_value_1.add_pair(twenty_, vlT);

    CString twenty_one_ = "twenty-one"; CVector<CString> vlX;
    vlX.push_back("ABCDEFGHIJKLMNOPQRSTUVWX");
    key_value_1.add_pair(twenty_one_, vlX);

    CString twenty_two_ = "twenty-two"; CVector<CString> vlW;
    vlW.push_back("ABCDEFGHIJKLMNOPQRSTUVW");
    key_value_1.add_pair(twenty_two_, vlW);


    CString twenty_three_ = "twenty-three"; CVector<CString> vlY;
    vlY.push_back("ABCDEFGHIJKLMNOPQRSTUVWXY");
    key_value_1.add_pair(twenty_three_, vlY);

    CString twenty_four_ = "twenty-four"; CVector<CString> vlZ;
    vlZ.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    key_value_1.add_pair(twenty_four_, vlZ);

    new_file.add_key_value(old_name_1, key_value_1);

    //изменение имён секции
    CString new_name_0  = "Integers";
    new_file.change_name_section(old_name_0, new_name_0);
    CString new_name_1 = "Alphabet";
    new_file.change_name_section(old_name_1, new_name_1);
    //удаление значений
    new_file.delete_value(new_name_0, zero);
    new_file.delete_value(new_name_0, eight);
    new_file.delete_value(new_name_0, twelve);
    new_file.delete_value(new_name_0, thirteen);
    new_file.delete_value(new_name_0, eleven);

    new_file.delete_value(new_name_1, five_);
    new_file.delete_value(new_name_1, twelve_);
    new_file.delete_value(new_name_1, sixteen_);
    new_file.delete_value(new_name_1, twenty_);
    new_file.delete_value(new_name_1, twenty_two_);
    new_file.delete_value(new_name_1, twenty_four_);
    /*содержимое ini-файла "test" после внесённых изменений имеет следующий вид:
        [Integers]
        ;This section contains the numbers
        seven =  42
        one =  35
        two =  21
        three =  17
        four =  11
        five =  24
        six =  23
        nine = 68
        ten = 63

        [Alphabet]
        ;And this section containts the strings
        zero =  "ABCDEFGHIJKLM"
        one =  "ABCDEFGH"
        two =  "ABCDE"
        three =  "ABCD"
        four =  "ABC"
        six =  "AB"
        seven =  "ABCDEF"
        eight =  "ABCDEFGHIJ"
        nine = "ABCDEFGHI"
        ten = "ABCDEFGHIJKL"
        eleven = "ABCDEFGHIJK"
        thirteen = "ABCDEFGHIJKLMNO"
        fourteen = "ABCDEFGHIJKLMN"
        fifteen = "ABCDEFGHIJKLMNOPQ"
        seventeen = "ABCDEFGHIJKLMNOPQR"
        eighteen = "ABCDEFGHIJKLMNOPQRSTUV"
        nineteen = "ABCDEFGHIJKLMNOPQRSTU"
        twenty-one = "ABCDEFGHIJKLMNOPQRSTUVWX"
        twenty-three = "ABCDEFGHIJKLMNOPQRSTUVWXY"
    */
    string name_file = "test";
    new_file.create_file(name_file);
    new_file.write_file(name_file);

    CIni check_file;
    check_file.read_file(name_file);
    //проверка наличия первой секции
    ASSERT_TRUE(check_file.search_name_section(new_name_0));

    //проверка значений первой секции
    ASSERT_FALSE(check_file.search_key(new_name_0, zero));

    ASSERT_TRUE(check_file.search_key(new_name_0, one));
    ASSERT_TRUE(v35 == check_file.getValue(new_name_0, one));

    ASSERT_FALSE(check_file.search_key(new_name_0, eight));

    ASSERT_TRUE(check_file.search_key(new_name_0, two));
    ASSERT_TRUE(v21 == check_file.getValue(new_name_0, two));

    ASSERT_TRUE(check_file.search_key(new_name_0, seven));
    ASSERT_TRUE(v42 == check_file.getValue(new_name_0, seven));

    ASSERT_TRUE(check_file.search_key(new_name_0, three));
    ASSERT_TRUE(v17 == check_file.getValue(new_name_0, three));

    ASSERT_TRUE(check_file.search_key(new_name_0, four));
    ASSERT_TRUE(v11 == check_file.getValue(new_name_0, four));

    ASSERT_TRUE(check_file.search_key(new_name_0, five));
    ASSERT_TRUE(v24 == check_file.getValue(new_name_0, five));

    ASSERT_TRUE(check_file.search_key(new_name_0, six));
    ASSERT_TRUE(v23 == check_file.getValue(new_name_0, six));

    ASSERT_FALSE(check_file.search_key(new_name_0, twelve));

    ASSERT_FALSE(check_file.search_key(new_name_0, thirteen));

    ASSERT_TRUE(check_file.search_key(new_name_0, nine));
    ASSERT_TRUE(v68 == check_file.getValue(new_name_0, nine));

    ASSERT_TRUE(check_file.search_key(new_name_0, ten));
    ASSERT_TRUE(v63 == check_file.getValue(new_name_0, ten));

    ASSERT_FALSE(check_file.search_key(new_name_0, eleven));

    //проверка наличия второй секции
    ASSERT_TRUE(check_file.search_name_section(new_name_1));
    //проверка значений второй секции

    ASSERT_TRUE(check_file.search_key(new_name_1, zero_));
    ASSERT_TRUE(vlM == check_file.getValue(new_name_1, zero_));

    ASSERT_TRUE(check_file.search_key(new_name_1, one_));
    ASSERT_TRUE(vlH == check_file.getValue(new_name_1, one_));

    ASSERT_TRUE(check_file.search_key(new_name_1, two_));
    ASSERT_TRUE(vlE == check_file.getValue(new_name_1, two_));

    ASSERT_TRUE(check_file.search_key(new_name_1, three_));
    ASSERT_TRUE(vlD == check_file.getValue(new_name_1, three_));

    ASSERT_TRUE(check_file.search_key(new_name_1, four_));
    ASSERT_TRUE(vlC == check_file.getValue(new_name_1, four_));

    ASSERT_FALSE(check_file.search_key(new_name_1, five_));
    ASSERT_TRUE(check_file.search_key(new_name_1, six_));
    ASSERT_TRUE(vlB == check_file.getValue(new_name_1, six_));

    ASSERT_TRUE(check_file.search_key(new_name_1, seven_));
    ASSERT_TRUE(vlF == check_file.getValue(new_name_1, seven_));

    ASSERT_TRUE(check_file.search_key(new_name_1, eight_));
    ASSERT_TRUE(vlJ == check_file.getValue(new_name_1, eight_));

    ASSERT_TRUE(check_file.search_key(new_name_1, nine_));
    ASSERT_TRUE(vlI == check_file.getValue(new_name_1, nine_));

    ASSERT_TRUE(check_file.search_key(new_name_1, ten_));
    ASSERT_TRUE(vlL == check_file.getValue(new_name_1, ten_));

    ASSERT_TRUE(check_file.search_key(new_name_1, eleven_));
    ASSERT_TRUE(vlK == check_file.getValue(new_name_1, eleven_));

    ASSERT_FALSE(check_file.search_key(new_name_1, twelve_));

    ASSERT_TRUE(check_file.search_key(new_name_1, six_));
    ASSERT_TRUE(vlB == check_file.getValue(new_name_1, six_));

    ASSERT_TRUE(check_file.search_key(new_name_1, seven_));
    ASSERT_TRUE(vlF == check_file.getValue(new_name_1, seven_));

    ASSERT_TRUE(check_file.search_key(new_name_1, eight_));
    ASSERT_TRUE(vlJ == check_file.getValue(new_name_1, eight_));

    ASSERT_TRUE(check_file.search_key(new_name_1, nine_));
    ASSERT_TRUE(vlI == check_file.getValue(new_name_1, nine_));

    ASSERT_TRUE(check_file.search_key(new_name_1, ten_));
    ASSERT_TRUE(vlL == check_file.getValue(new_name_1, ten_));

    ASSERT_TRUE(check_file.search_key(new_name_1, eleven_));
    ASSERT_TRUE(vlK == check_file.getValue(new_name_1, eleven_));

    ASSERT_FALSE(check_file.search_key(new_name_1, twelve_));

    ASSERT_TRUE(check_file.search_key(new_name_1, nineteen_));
    ASSERT_TRUE(vlU == check_file.getValue(new_name_1, nineteen_));

    ASSERT_FALSE(check_file.search_key(new_name_1, twenty_));

    ASSERT_TRUE(check_file.search_key(new_name_1, twenty_one_));
    ASSERT_TRUE(vlX == check_file.getValue(new_name_1, twenty_one_));

    ASSERT_FALSE(check_file.search_key(new_name_1, twenty_two_));

    ASSERT_TRUE(check_file.search_key(new_name_1, twenty_three_));
    ASSERT_TRUE(vlY == check_file.getValue(new_name_1, twenty_three_));

    ASSERT_FALSE(check_file.search_key(new_name_1, twenty_four_));
    check_file.delete_file(name_file);

}

TEST(test055, test_CIni_change_value_add_value)
{
    /*содержимое ini-файла "test" до внесённых изменений имеет следующий вид:
        [Numbers]
        ;This section contains the numbers
        zero =  60
        one =  35
        eight =  70, 45
        two =  21
        seven =  42
        three =  17
        four =  11
        five =  24
        six =  23
        twelve = 71, 56
        thirteen = 89, 78, 25
        nine = 68
        ten = 63
        eleven = 69

        [Strings]
        ;This section contains the strings
        zero =  "ABCDEFGHIJKLM"
        one =  "ABCDEFGH"
        two =  "ABCDE"
        three =  "ABCD"
        four =  "ABC"
        five =  "A"
        six =  "AB"
        seven =  "ABCDEF"
        eight =  "ABCDEFGHIJ"
        nine = "ABCDEFGHI"
        ten = "ABCDEFGHIJKL"
        eleven = "ABCDEFGHIJK"
        twelve = "ABCDEFGHIJKLMNOPQRS"
        thirteen = "ABCDEFGHIJKLMNO"
        fourteen = "ABCDEFGHIJKLMN"
        fifteen = "ABCDEFGHIJKLMNOPQ"
        sixteen = "ABCDEFGHIJKLMNOP"
        seventeen = "ABCDEFGHIJKLMNOPQR"
        eighteen = "ABCDEFGHIJKLMNOPQRSTUV"
        nineteen = "ABCDEFGHIJKLMNOPQRSTU"
        twenty = "ABCDEFGHIJKLMNOPQRST"
        twenty-one = "ABCDEFGHIJKLMNOPQRSTUVWX"
        twenty-two = "ABCDEFGHIJKLMNOPQRSTUVW"
        twenty-three = "ABCDEFGHIJKLMNOPQRSTUVWXY"
        twenty-four = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    */
    //создание контента для заполнения ini-файла
    //первая секция
    CIni new_file;
    CString name_section_1 = "Numbers";
    new_file.add_name_section(name_section_1);

    CString comment_section_1 = "This section contains the numbers";
    new_file.add_comment_section(name_section_1, comment_section_1);

    CMap<CString, CVector<CString>> key_value_1;

    CString zero = "zero"; CVector<CString> v60;
    v60.push_back(60);
    key_value_1.add_pair(zero, v60);

    CString one = "one"; CVector<CString> v35;
    v35.push_back(35);
    key_value_1.add_pair(one, v35);

    CString eight = "eight"; CVector<CString> v70_45;
    v70_45.push_back(70);
    v70_45.push_back(45);
    key_value_1.add_pair(eight, v70_45);

    CString two = "two"; CVector<CString> v21;
    v21.push_back(21);
    key_value_1.add_pair(two, v21);

    CString seven = "seven"; CVector<CString> v42;
    v42.push_back(42);
    key_value_1.add_pair(seven, v42);

    CString three = "three"; CVector<CString> v17;
    v17.push_back(17);
    key_value_1.add_pair(three, v17);

    CString four = "four"; CVector<CString> v11;
    v11.push_back(11);
    key_value_1.add_pair(four, v11);

    CString five = "five"; CVector<CString> v24;
    v24.push_back(24);
    key_value_1.add_pair(five, v24);

    CString six = "six"; CVector<CString> v23;
    v23.push_back(23);
    key_value_1.add_pair(six, v23);

    CString twelve = "twelve"; CVector<CString> v71_56;
    v71_56.push_back(71);
    v71_56.push_back(56);
    key_value_1.add_pair(twelve, v71_56);

    CString thirteen = "thirteen"; CVector<CString> v89_78_25;
    v89_78_25.push_back(89);
    v89_78_25.push_back(78);
    v89_78_25.push_back(25);
    key_value_1.add_pair(thirteen, v89_78_25);

    CString nine = "nine"; CVector<CString> v68;
    v68.push_back(68);
    key_value_1.add_pair(nine, v68);

    CString ten = "ten"; CVector<CString> v63;
    v63.push_back(63);
    key_value_1.add_pair(ten, v63);

    CString eleven = "eleven"; CVector<CString> v69;
    v69.push_back(69);
    key_value_1.add_pair(eleven, v69);

    new_file.add_key_value(name_section_1, key_value_1);
    //вторая секция
    CString name_section_2 = "Strings";
    new_file.add_name_section(name_section_2);

    CString comment_section_2 = "And this section containts the strings";
    new_file.add_comment_section(name_section_2, comment_section_1);

    CMap<CString, CVector<CString>> key_value_2;
    CString zero_ = "zero"; CVector<CString> vlM;
    vlM.push_back("ABCDEFGHIJKLM");
    key_value_2.add_pair(zero_, vlM);

    CString one_ = "one"; CVector<CString> vlH;
    vlH.push_back("ABCDEFGH");
    key_value_2.add_pair(one_, vlH);

    CString two_ = "two"; CVector<CString> vlE;
    vlE.push_back("ABCDE");
    key_value_2.add_pair(two_, vlE);

    CString three_ = "three"; CVector<CString> vlD;
    vlD.push_back("ABCD");
    key_value_2.add_pair(three_, vlD);

    CString four_ = "four"; CVector<CString> vlC;
    vlC.push_back("ABC");
    key_value_2.add_pair(four_, vlC);

    CString five_ = "five"; CVector<CString> vlA;
    vlA.push_back("A");
    key_value_2.add_pair(five_, vlA);

    CString six_ = "six"; CVector<CString> vlB;
    vlB.push_back("AB");
    key_value_2.add_pair(six_, vlB);

    CString seven_ = "seven"; CVector<CString> vlF;
    vlF.push_back("ABCDEF");
    key_value_2.add_pair(seven_, vlF);

    CString eight_ = "eight"; CVector<CString> vlJ;
    vlJ.push_back("ABCDEFGHIJ");
    key_value_2.add_pair(eight_, vlJ);

    CString nine_ = "nine"; CVector<CString> vlI;
    vlI.push_back("ABCDEFGHI");
    key_value_2.add_pair(nine_, vlI);

    CString ten_ = "ten"; CVector<CString> vlL;
    vlL.push_back("ABCDEFGHIJKL");
    key_value_2.add_pair(ten_, vlL);

    CString eleven_ = "eleven"; CVector<CString> vlK;
    vlK.push_back("ABCDEFGHIJK");
    key_value_2.add_pair(eleven_, vlK);

    CString twelve_ = "twelve"; CVector<CString> vlS;
    vlS.push_back("ABCDEFGHIJKLMNOPQRS");
    key_value_2.add_pair(twelve_, vlS);

    CString thirteen_ = "thirteen"; CVector<CString> vlO;
    vlO.push_back("ABCDEFGHIJKLMNO");
    key_value_2.add_pair(thirteen_, vlO);

    CString fourteen_ = "fourteen"; CVector<CString> vlN;
    vlN.push_back("ABCDEFGHIJKLMN");
    key_value_2.add_pair(fourteen_, vlN);

    CString fifteen_ = "fifteen"; CVector<CString> vlQ;
    vlQ.push_back("ABCDEFGHIJKLMNOPQ");
    key_value_2.add_pair(fifteen_, vlQ);

    CString sixteen_ = "sixteen"; CVector<CString> vlP;
    vlP.push_back("ABCDEFGHIJKLMNOP");
    key_value_2.add_pair(sixteen_, vlP);

    CString seventeen_ = "seventeen"; CVector<CString> vlR;
    vlR.push_back("ABCDEFGHIJKLMNOPQR");
    key_value_2.add_pair(seventeen_, vlR);

    CString eighteen_ = "eighteen"; CVector<CString> vlV;
    vlV.push_back("ABCDEFGHIJKLMNOPQRSTUV");
    key_value_2.add_pair(eighteen_, vlV);

    CString nineteen_ = "nineteen"; CVector<CString> vlU;
    vlU.push_back("ABCDEFGHIJKLMNOPQRSTU");
    key_value_2.add_pair(nineteen_, vlU);

    CString twenty_ = "twenty"; CVector<CString> vlT;
    vlT.push_back("ABCDEFGHIJKLMNOPQRST");
    key_value_2.add_pair(twenty_, vlT);

    CString twenty_one_ = "twenty-one"; CVector<CString> vlX;
    vlX.push_back("ABCDEFGHIJKLMNOPQRSTUVWX");
    key_value_2.add_pair(twenty_one_, vlX);

    CString twenty_two_ = "twenty-two"; CVector<CString> vlW;
    vlW.push_back("ABCDEFGHIJKLMNOPQRSTUVW");
    key_value_2.add_pair(twenty_two_, vlW);


    CString twenty_three_ = "twenty-three"; CVector<CString> vlY;
    vlY.push_back("ABCDEFGHIJKLMNOPQRSTUVWXY");
    key_value_2.add_pair(twenty_three_, vlY);

    CString twenty_four_ = "twenty-four"; CVector<CString> vlZ;
    vlZ.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    key_value_2.add_pair(twenty_four_, vlZ);

    new_file.add_key_value(name_section_2, key_value_2);

    //изменение значений 1 секции
    CVector<CString> v1000000;
    v1000000.push_back(1000000);
    new_file.change_value(name_section_1, zero, v1000000);

    CVector<CString> v4000;
    v4000.push_back(4000);
    new_file.change_value(name_section_1, eight, v4000);

    CString vl678 = 678;
    new_file.add_value(name_section_1, three, vl678);

    CString vl9000 = 9000;
    CString vl71 = 71;
    new_file.change_value(name_section_1, twelve, vl71, vl9000);

    CString vl80000 = 80000;
    CString vl78 = 78;
    new_file.change_value(name_section_1, thirteen, vl78, vl80000);
    CString vl606 = 606;
    new_file.add_value(name_section_1, thirteen, vl606);

    CVector<CString> v500;
    v500.push_back(500);
    new_file.change_value(name_section_1, eleven, v500);

    CVector<CString> v89457;
    v89457.push_back(89457);
    CString fourteen = "fourteen";
    new_file.add_value(name_section_1, fourteen, v89457);

    //изменение значений 2 секции
    CVector<CString> vYeah;
    vYeah.push_back("Yeah");
    new_file.change_value(name_section_2, zero_, vYeah);

    CVector<CString> vSub_zero_Hello;
    vSub_zero_Hello.push_back("Sub-zero");
    vSub_zero_Hello.push_back("Hello");
    new_file.change_value(name_section_2, four_, vSub_zero_Hello);

    CVector<CString> vHZ;
    vHZ.push_back("HZ");
    new_file.change_value(name_section_2, twelve_, vHZ);

    CString vlCHAMPION = "CHAMPION";
    new_file.add_value(name_section_2, fourteen_, vlCHAMPION);

    CVector<CString> vScorpion;
    vScorpion.push_back("Scorpion");
    new_file.change_value(name_section_2, sixteen_, vScorpion);

    CString vlGOLIAF = "GOLIAF";
    CString vlSAMSON = "SAMSON";
    new_file.add_value(name_section_2, nineteen_, vlGOLIAF);
    new_file.add_value(name_section_2, nineteen_, vlSAMSON);

    CVector<CString> vGLADIATOR;
    vGLADIATOR.push_back("GLADIATOR");
    new_file.change_value(name_section_2, twenty_, vGLADIATOR);

    CVector<CString> vWalorant;
    vWalorant.push_back("Walorant");
    vWalorant.push_back("GOOD");
    vWalorant.push_back("Cinema");
    new_file.change_value(name_section_2, twenty_three_, vWalorant);

    CVector<CString> vNEW_YEAR;
    vNEW_YEAR.push_back("NEW_YEAR");
    vNEW_YEAR.push_back("CHRISTMAS");
    CString twenty_five_ = "twenty-five";
    new_file.add_value(name_section_2, twenty_five_, vNEW_YEAR);

    CVector<CString> vHEAVY_RAIN;
    vHEAVY_RAIN.push_back("HEAVY_RAIN");
    CString twenty_six_ = "twenty-six";
    new_file.add_value(name_section_2, twenty_six_, vHEAVY_RAIN);

    /*содержимое ini-файла "test" после внесённых изменений имеет следующий вид:
    [Numbers]
    ;This section contains the numbers
    seven = 42
    one = 35
    two = 21
    four = 11
    zero = 1000000
    five = 24
    six = 23
    eight = 4000
    nine = 68
    ten = 63
    eleven = 500
    three = 17, 678
    fourteen = 89457
    twelve = 9000, 56
    thirteen = 89, 80000, 25, 606

    [Strings]
    ;And this section containts the strings
    ten = ABCDEFGHIJKL
    one = ABCDEFGH
    two = ABCDE
    three = ABCD
    five = A
    six = AB
    seven = ABCDEF
    eight = ABCDEFGHIJ
    nine = ABCDEFGHI
    eleven = ABCDEFGHIJK
    seventeen = ABCDEFGHIJKLMNOPQR
    thirteen = ABCDEFGHIJKLMNO
    fifteen = ABCDEFGHIJKLMNOPQ
    eighteen = ABCDEFGHIJKLMNOPQRSTUV
    twenty-one = ABCDEFGHIJKLMNOPQRSTUVWX
    twenty-two = ABCDEFGHIJKLMNOPQRSTUVW
    twenty-four = ABCDEFGHIJKLMNOPQRSTUVWXYZ
    zero = Yeah
    twelve = HZ
    twenty = GLADIATOR
    twenty-six = HEAVY_RAIN
    sixteen = Scorpion
    four = Sub-zero, Hello
    fourteen = ABCDEFGHIJKLMN, CHAMPION
    twenty-five = NEW_YEAR, CHRISTMAS
    nineteen = ABCDEFGHIJKLMNOPQRSTU, GOLIAF, SAMSON
    twenty-three = Walorant, GOOD, Cinema
     */
     string name_file = "test";
     new_file.create_file(name_file);
     new_file.write_file(name_file);

     CIni check_file;
     check_file.read_file(name_file);

     ASSERT_TRUE(check_file.search_key(name_section_1, zero));
     ASSERT_TRUE(v1000000 == check_file.getValue(name_section_1, zero));

     ASSERT_TRUE(check_file.search_key(name_section_1, one));
     ASSERT_TRUE(v35 == check_file.getValue(name_section_1, one));

     ASSERT_TRUE(check_file.search_key(name_section_1, eight));
     ASSERT_TRUE(v4000 == check_file.getValue(name_section_1, eight));

     ASSERT_TRUE(check_file.search_key(name_section_1, two));
     ASSERT_TRUE(v21 == check_file.getValue(name_section_1, two));

     ASSERT_TRUE(check_file.search_key(name_section_1, seven));
     ASSERT_TRUE(v42 == check_file.getValue(name_section_1, seven));

     ASSERT_TRUE(check_file.search_key(name_section_1, three));
     CVector<CString> res_0;
     res_0.push_back(17);
     res_0.push_back(678);
     ASSERT_TRUE(res_0 == check_file.getValue(name_section_1, three));

     ASSERT_TRUE(check_file.search_key(name_section_1, four));
     ASSERT_TRUE(v11 == check_file.getValue(name_section_1, four));

     ASSERT_TRUE(check_file.search_key(name_section_1, five));
     ASSERT_TRUE(v24 == check_file.getValue(name_section_1, five));

     ASSERT_TRUE(check_file.search_key(name_section_1, six));
     ASSERT_TRUE(v23 == check_file.getValue(name_section_1, six));

     ASSERT_TRUE(check_file.search_key(name_section_1, twelve));
     CVector<CString> res_1;
     res_1.push_back(9000);
     res_1.push_back(56);
     ASSERT_TRUE(res_1 == check_file.getValue(name_section_1, twelve));

     ASSERT_TRUE(check_file.search_key(name_section_1, thirteen));
     CVector<CString> res_2;
     res_2.push_back(89);
     res_2.push_back(80000);
     res_2.push_back(25);
     res_2.push_back(606);
     ASSERT_TRUE(res_2 == check_file.getValue(name_section_1, thirteen));

     ASSERT_TRUE(check_file.search_key(name_section_1, nine));
     ASSERT_TRUE(v68 == check_file.getValue(name_section_1, nine));

     ASSERT_TRUE(check_file.search_key(name_section_1, ten));
     ASSERT_TRUE(v63 == check_file.getValue(name_section_1, ten));

     ASSERT_TRUE(check_file.search_key(name_section_1, eleven));
     CVector<CString> res_3;
     res_3.push_back(500);
     ASSERT_TRUE(res_3 == check_file.getValue(name_section_1, eleven));

     ASSERT_TRUE(check_file.search_key(name_section_2, zero_));
     ASSERT_TRUE(vYeah == check_file.getValue(name_section_2, zero_));

     ASSERT_TRUE(check_file.search_key(name_section_2, one_));
     ASSERT_TRUE(vlH == check_file.getValue(name_section_2, one_));

     ASSERT_TRUE(check_file.search_key(name_section_2, two_));
     ASSERT_TRUE(vlE == check_file.getValue(name_section_2, two_));

     ASSERT_TRUE(check_file.search_key(name_section_2, three_));
     ASSERT_TRUE(vlD == check_file.getValue(name_section_2, three_));

     ASSERT_TRUE(check_file.search_key(name_section_2, four_));
     ASSERT_TRUE(vSub_zero_Hello == check_file.getValue(name_section_2, four_));

     ASSERT_TRUE(check_file.search_key(name_section_2, five_));
     ASSERT_TRUE(vlA == check_file.getValue(name_section_2, five_));

     ASSERT_TRUE(check_file.search_key(name_section_2, six_));
     ASSERT_TRUE(vlB == check_file.getValue(name_section_2, six_));

     ASSERT_TRUE(check_file.search_key(name_section_2, seven_));
     ASSERT_TRUE(vlF == check_file.getValue(name_section_2, seven_));

     ASSERT_TRUE(check_file.search_key(name_section_2, eight_));
     ASSERT_TRUE(vlJ == check_file.getValue(name_section_2, eight_));

     ASSERT_TRUE(check_file.search_key(name_section_2, nine_));
     ASSERT_TRUE(vlI == check_file.getValue(name_section_2, nine_));

     ASSERT_TRUE(check_file.search_key(name_section_2, ten_));
     ASSERT_TRUE(vlL == check_file.getValue(name_section_2, ten_));

     ASSERT_TRUE(check_file.search_key(name_section_2, eleven_));
     ASSERT_TRUE(vlK == check_file.getValue(name_section_2, eleven_));

     ASSERT_TRUE(check_file.search_key(name_section_2, twelve_));
     ASSERT_TRUE(vHZ == check_file.getValue(name_section_2, twelve_));

     ASSERT_TRUE(check_file.search_key(name_section_2, thirteen_));
     ASSERT_TRUE(vlO == check_file.getValue(name_section_2, thirteen_));

     ASSERT_TRUE(check_file.search_key(name_section_2, fourteen_));
     CVector<CString> res_4;
     res_4.push_back("ABCDEFGHIJKLMN");
     res_4.push_back("CHAMPION");
     ASSERT_TRUE(res_4 == check_file.getValue(name_section_2, fourteen_));

     ASSERT_TRUE(check_file.search_key(name_section_2, fifteen_));
     ASSERT_TRUE(vlQ == check_file.getValue(name_section_2, fifteen_));

     ASSERT_TRUE(check_file.search_key(name_section_2, sixteen_));
     ASSERT_TRUE(vScorpion == check_file.getValue(name_section_2, sixteen_));

     ASSERT_TRUE(check_file.search_key(name_section_2, seventeen_));
     ASSERT_TRUE(vlR == check_file.getValue(name_section_2, seventeen_));

     ASSERT_TRUE(check_file.search_key(name_section_2, eighteen_));
     ASSERT_TRUE(vlV == check_file.getValue(name_section_2, eighteen_));

     ASSERT_TRUE(check_file.search_key(name_section_2, nineteen_));
     CVector<CString> res_5;
     res_5.push_back("ABCDEFGHIJKLMNOPQRSTU");
     res_5.push_back("GOLIAF");
     res_5.push_back("SAMSON");
     ASSERT_TRUE(res_5 == check_file.getValue(name_section_2, nineteen_));

     ASSERT_TRUE(check_file.search_key(name_section_2, twenty_));
     ASSERT_TRUE(vGLADIATOR == check_file.getValue(name_section_2, twenty_));

     ASSERT_TRUE(check_file.search_key(name_section_2, twenty_one_));
     ASSERT_TRUE(vlX == check_file.getValue(name_section_2, twenty_one_));

     ASSERT_TRUE(check_file.search_key(name_section_2, twenty_two_));
     ASSERT_TRUE(vlW == check_file.getValue(name_section_2, twenty_two_));

     ASSERT_TRUE(check_file.search_key(name_section_2, twenty_three_));
     ASSERT_TRUE(vWalorant == check_file.getValue(name_section_2, twenty_three_));

     ASSERT_TRUE (check_file.search_key(name_section_2, twenty_four_));
     ASSERT_TRUE(vlZ == check_file.getValue(name_section_2, twenty_four_));

     ASSERT_TRUE(check_file.search_key(name_section_2, twenty_five_));
     ASSERT_TRUE(vNEW_YEAR == check_file.getValue(name_section_2, twenty_five_));

     ASSERT_TRUE(check_file.search_key(name_section_2, twenty_six_));
     ASSERT_TRUE(vHEAVY_RAIN == check_file.getValue(name_section_2, twenty_six_));

     check_file.delete_file(name_file);
}
#endif // CINI_TEST_H
