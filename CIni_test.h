#ifndef CINI_TEST_H
#define CINI_TEST_H
#include "CIni.h"
#include <gtest/include/gtest/gtest.h>
TEST(test001, test_CIni_read_file)
{
    CIni new_file;

       /*содержимое ini-файла "test" имеет следующий вид:
        [Numbers]
        ;This section contains the numbers
        eight=70, 45
        eleven=69
        five=24
        four=11
        nine=68
        one=35
        seven=42
        six=23
        ten=63
        thirteen=89, 78, 25
        three=17
        twelve=71, 56
        two=21
        zero=60
        [Strings]
        ;And this section containts the strings
        eight=ABCDEFGHIJ
        eighteen=ABCDEFGHIJKLMNOPQRSTUV
        eleven=ABCDEFGHIJK
        fifteen=ABCDEFGHIJKLMNOPQ
        five=A
        four=ABC
        fourteen=ABCDEFGHIJKLMN
        nine=ABCDEFGHI
        nineteen=ABCDEFGHIJKLMNOPQRSTU
        one=ABCDEFGH
        seven=ABCDEF
        seventeen=ABCDEFGHIJKLMNOPQR
        six=AB
        sixteen=ABCDEFGHIJKLMNOP
        ten=ABCDEFGHIJKL
        thirteen=ABCDEFGHIJKLMNO
        three=ABCD
        twelve=ABCDEFGHIJKLMNOPQRS
        twenty=ABCDEFGHIJKLMNOPQRST
        twenty-four=ABCDEFGHIJKLMNOPQRSTUVWXYZ
        twenty-one=ABCDEFGHIJKLMNOPQRSTUVWX
        twenty-three=ABCDEFGHIJKLMNOPQRSTUVWXY
        two=ABCDE
        zero=ABCDEFGHIJKLM

       */
       //создание контента для заполнения ini-файла
       //присваивание 1 секции имени
       string name_section = "Numbers";
       new_file.add_name_section(name_section);

       //добавление комментария к секции
       string comment_section = "This section contains the numbers";
       new_file.add_comment_section(name_section, comment_section);
       map<string, vector<string>> key_value;

       //заполнение 1 секции содержимым
       string zero = "zero"; vector<string> v60;
       v60.push_back("60");
       key_value.insert(pair<string, vector<string>>(zero, v60));


       string one = "one"; vector<string> v35;
       v35.push_back("35");
       key_value.insert(pair<string, vector<string>>(one, v35));

       string eight = "eight"; vector<string> v70_45;
       v70_45.push_back("70");
       v70_45.push_back("45");
       key_value.insert(pair<string, vector<string>>(eight, v70_45));

       string two = "two"; vector<string> v21;
       v21.push_back("21");
       key_value.insert(pair<string, vector<string>>(two, v21));

       string seven = "seven"; vector<string> v42;
       v42.push_back("42");
       key_value.insert(pair<string, vector<string>>(seven, v42));

       string three = "three"; vector<string> v17;
       v17.push_back("17");
       key_value.insert(pair<string, vector<string>>(three, v17));

       string four = "four"; vector<string> v11;
       v11.push_back("11");
       key_value.insert(pair<string, vector<string>>(four, v11));

       string five = "five"; vector<string> v24;
       v24.push_back("24");
       key_value.insert(pair<string, vector<string>>(five, v24));

       string six = "six"; vector<string> v23;
       v23.push_back("23");
       key_value.insert(pair<string, vector<string>>(six, v23));

       string twelve = "twelve"; vector<string> v71_56;
       v71_56.push_back("71");
       v71_56.push_back("56");
       key_value.insert(pair<string, vector<string>>(twelve, v71_56));


       string thirteen = "thirteen"; vector<string> v89_78_25;
       v89_78_25.push_back("89");
       v89_78_25.push_back("78");
       v89_78_25.push_back("25");
       key_value.insert(pair<string, vector<string>>(thirteen, v89_78_25));

       string nine = "nine"; vector<string> v68;
       v68.push_back("68");
       key_value.insert(pair<string, vector<string>>(nine, v68));


       string ten = "ten"; vector<string> v63;
       v63.push_back("63");
       key_value.insert(pair<string, vector<string>>(ten, v63));

       string eleven = "eleven"; vector<string> v69;
       v69.push_back("69");
       key_value.insert(pair<string, vector<string>>(eleven, v69));

       new_file.add_key_value(name_section, key_value);

       //присваивание 2 секции имени
       string name_section1 = "Strings";
       new_file.add_name_section(name_section1);

       //добавление комментария к секции
       string comment_section1 = "And this section containts the strings";
       new_file.add_comment_section(name_section1, comment_section1);

       //заполнение 2 секции содержимым
       map<string, vector<string>> key_value_1;

       string zero_ = "zero"; vector<string> vlM;
       vlM.push_back("ABCDEFGHIJKLM");
       key_value_1.insert(pair<string, vector<string>>(zero_, vlM));

       string one_ = "one"; vector<string> vlH;
       vlH.push_back("ABCDEFGH");
       key_value_1.insert(pair<string, vector<string>>(one_, vlH));

       string two_ = "two"; vector<string> vlE;
       vlE.push_back("ABCDE");
       key_value_1.insert(pair<string, vector<string>>(two_, vlH));

       string three_ = "three"; vector<string> vlD;
       vlD.push_back("ABCD");
       key_value_1.insert(pair<string, vector<string>>(three_, vlD));

       string four_ = "four"; vector<string> vlC;
       vlC.push_back("ABC");
       key_value_1.insert(pair<string, vector<string>>(four_, vlC));

       string five_ = "five"; vector<string> vlA;
       vlA.push_back("A");
       key_value_1.insert(pair<string, vector<string>>(five_, vlA));

       string six_ = "six"; vector<string> vlB;
       vlB.push_back("AB");
       key_value_1.insert(pair<string, vector<string>>(six_, vlB));


       string seven_ = "seven"; vector<string> vlF;
       vlF.push_back("ABCDEF");
       key_value_1.insert(pair<string, vector<string>>(seven_, vlF));


       string eight_ = "eight"; vector<string> vlJ;
       vlJ.push_back("ABCDEFGHIJ");
       key_value_1.insert(pair<string, vector<string>>(eight_, vlJ));

       string nine_ = "nine"; vector<string> vlI;
       vlI.push_back("ABCDEFGHI");
       key_value_1.insert(pair<string, vector<string>>(nine_, vlI));


       string ten_ = "ten"; vector<string> vlL;
       vlL.push_back("ABCDEFGHIJKL");
       key_value_1.insert(pair<string, vector<string>>(ten_, vlL));

       string eleven_ = "eleven"; vector<string> vlK;
       vlK.push_back("ABCDEFGHIJK");
       key_value_1.insert(pair<string, vector<string>>(eleven_, vlK));

       string twelve_ = "twelve"; vector<string> vlS;
       vlS.push_back("ABCDEFGHIJKLMNOPQRS");
       key_value_1.insert(pair<string, vector<string>>(twelve_, vlS));

       string thirteen_ = "thirteen"; vector<string> vlO;
       vlO.push_back("ABCDEFGHIJKLMNO");
       key_value_1.insert(pair<string, vector<string>>(thirteen_, vlO));

       string fourteen_ = "fourteen"; vector<string> vlN;
       vlN.push_back("ABCDEFGHIJKLMN");
       key_value_1.insert(pair<string, vector<string>>(fourteen_, vlN));

       string fifteen_ = "fifteen"; vector<string> vlQ;
       vlQ.push_back("ABCDEFGHIJKLMNOPQ");
       key_value_1.insert(pair<string, vector<string>>(fifteen_, vlQ));

       string sixteen_ = "sixteen"; vector<string> vlP;
       vlP.push_back("ABCDEFGHIJKLMNOP");
       key_value_1.insert(pair<string, vector<string>>(sixteen_, vlP));

       string seventeen_ = "seventeen"; vector<string> vlR;
       vlR.push_back("ABCDEFGHIJKLMNOPQR");
       key_value_1.insert(pair<string, vector<string>>(seventeen_, vlR));

       string eighteen_ = "eighteen"; vector<string> vlV;
       vlV.push_back("ABCDEFGHIJKLMNOPQRSTUV");
       key_value_1.insert(pair<string, vector<string>>(eighteen_, vlV));

       string nineteen_ = "nineteen"; vector<string> vlU;
       vlU.push_back("ABCDEFGHIJKLMNOPQRSTU");
       key_value_1.insert(pair<string, vector<string>>(nineteen_, vlU));

       string twenty_ = "twenty"; vector<string> vlT;
       vlT.push_back("ABCDEFGHIJKLMNOPQRST");
       key_value_1.insert(pair<string, vector<string>>(twenty_, vlT));

       string twenty_one_ = "twenty-one"; vector<string> vlX;
       vlX.push_back("ABCDEFGHIJKLMNOPQRSTUVWX");
       key_value_1.insert(pair<string, vector<string>>(twenty_one_, vlX));

       string twenty_two_ = "twenty-two"; vector<string> vlW;
       vlW.push_back("ABCDEFGHIJKLMNOPQRSTUVW");
       key_value_1.insert(pair<string, vector<string>>(twenty_two_, vlW));


       string twenty_three_ = "twenty-three"; vector<string> vlY;
       vlY.push_back("ABCDEFGHIJKLMNOPQRSTUVWXY");
       key_value_1.insert(pair<string, vector<string>>(twenty_three_, vlY));

       string twenty_four_ = "twenty-four"; vector<string> vlZ;
       vlZ.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
       key_value_1.insert(pair<string, vector<string>>(twenty_four_, vlZ));

       new_file.add_key_value(name_section1, key_value_1);

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

       ASSERT_TRUE(v60 == check_file.getValue(name_section, zero));

       ASSERT_TRUE(v35 == check_file.getValue(name_section, one));

       ASSERT_TRUE(v70_45 == check_file.getValue(name_section, eight));

       ASSERT_TRUE(v21 == check_file.getValue(name_section, two));

       ASSERT_TRUE(v42 == check_file.getValue(name_section, seven));

       ASSERT_TRUE(v17 == check_file.getValue(name_section, three));

       ASSERT_TRUE(v11 == check_file.getValue(name_section, four));

       ASSERT_TRUE(v24 == check_file.getValue(name_section, five));

       ASSERT_TRUE(v23 == check_file.getValue(name_section, six));

       ASSERT_TRUE(v71_56 == check_file.getValue(name_section, twelve));

       ASSERT_TRUE(v89_78_25 == check_file.getValue(name_section, thirteen));

       ASSERT_TRUE(v68 == check_file.getValue(name_section, nine));

       ASSERT_TRUE(v63 == check_file.getValue(name_section, ten));

       ASSERT_TRUE(v69 == check_file.getValue(name_section, eleven));


       //проверка наличия второй секции
       ASSERT_TRUE(check_file.search_name_section(name_section1));

       //получение комментария к секции
       const char *res1 = "And this section containts the strings";
       ASSERT_STREQ(res1, check_file.get_comment_section(name_section1));

       //проверка значений второй секции

       ASSERT_TRUE(vlM == check_file.getValue(name_section1, zero_));

       ASSERT_TRUE(vlH == check_file.getValue(name_section1, one_));

       ASSERT_TRUE(vlE == check_file.getValue(name_section1, two_));

       ASSERT_TRUE(vlD == check_file.getValue(name_section1, three_));

       ASSERT_TRUE(vlC == check_file.getValue(name_section1, four_));

       ASSERT_TRUE(vlA == check_file.getValue(name_section1, five_));

       ASSERT_TRUE(vlB == check_file.getValue(name_section1, six_));

       ASSERT_TRUE(vlF == check_file.getValue(name_section1, seven_));

       ASSERT_TRUE(vlJ == check_file.getValue(name_section1, eight_));

       ASSERT_TRUE(vlI == check_file.getValue(name_section1, nine_));

       ASSERT_TRUE(vlL == check_file.getValue(name_section1, ten_));

       ASSERT_TRUE(vlK == check_file.getValue(name_section1, eleven_));

       ASSERT_TRUE(vlS == check_file.getValue(name_section1, twelve_));

       ASSERT_TRUE(vlO == check_file.getValue(name_section1, thirteen_));

       ASSERT_TRUE(vlN == check_file.getValue(name_section1, fourteen_));

       ASSERT_TRUE(vlQ == check_file.getValue(name_section1, fifteen_));

       ASSERT_TRUE(vlP == check_file.getValue(name_section1, sixteen_));

       ASSERT_TRUE(vlR == check_file.getValue(name_section1, seventeen_));

       ASSERT_TRUE(vlV == check_file.getValue(name_section1, eighteen_));

       ASSERT_TRUE(vlU == check_file.getValue(name_section1, nineteen_));

       ASSERT_TRUE(vlT == check_file.getValue(name_section1, twenty_));

       ASSERT_TRUE(vlX == check_file.getValue(name_section1, twenty_one_));

       ASSERT_TRUE(vlW == check_file.getValue(name_section1, twenty_two_));

       ASSERT_TRUE(vlY == check_file.getValue(name_section1, twenty_three_));

       ASSERT_TRUE(vlZ == check_file.getValue(name_section1, twenty_four_));

       //удаление ini-файла
       new_file.delete_file(name_file);
}
TEST(test002, test_CIni_change_value_add_value)
{
    /*содержимое ini-файла "test" до внесённых изменений имеет следующий вид:
     [Numbers]
     ;This section contains the numbers
     eight=70, 45
     eleven=69
     five=24
     four=11
     nine=68
     one=35
     seven=42
     six=23
     ten=63
     thirteen=89, 78, 25
     three=17
     twelve=71, 56
     two=21
     zero=60
     [Strings]
     ;And this section containts the strings
     eight=ABCDEFGHIJ
     eighteen=ABCDEFGHIJKLMNOPQRSTUV
     eleven=ABCDEFGHIJK
     fifteen=ABCDEFGHIJKLMNOPQ
     five=A
     four=ABC
     fourteen=ABCDEFGHIJKLMN
     nine=ABCDEFGHI
     nineteen=ABCDEFGHIJKLMNOPQRSTU
     one=ABCDEFGH
     seven=ABCDEF
     seventeen=ABCDEFGHIJKLMNOPQR
     six=AB
     sixteen=ABCDEFGHIJKLMNOP
     ten=ABCDEFGHIJKL
     thirteen=ABCDEFGHIJKLMNO
     three=ABCD
     twelve=ABCDEFGHIJKLMNOPQRS
     twenty=ABCDEFGHIJKLMNOPQRST
     twenty-four=ABCDEFGHIJKLMNOPQRSTUVWXYZ
     twenty-one=ABCDEFGHIJKLMNOPQRSTUVWX
     twenty-three=ABCDEFGHIJKLMNOPQRSTUVWXY
     two=ABCDE
     zero=ABCDEFGHIJKLM

    */
    CIni new_file;
    string old_name_section0 = "Numbers";
    new_file.add_name_section(old_name_section0);

    //добавление комментария к секции
    string comment_section = "This section contains the numbers";
    new_file.add_comment_section(old_name_section0, comment_section);
    map<string, vector<string>> key_value;

    //заполнение 1 секции содержимым
    string zero = "zero"; vector<string> v60;
    v60.push_back("60");
    key_value.insert(pair<string, vector<string>>(zero, v60));


    string one = "one"; vector<string> v35;
    v35.push_back("35");
    key_value.insert(pair<string, vector<string>>(one, v35));

    string eight = "eight"; vector<string> v70_45;
    v70_45.push_back("70");
    v70_45.push_back("45");
    key_value.insert(pair<string, vector<string>>(eight, v70_45));

    string two = "two"; vector<string> v21;
    v21.push_back("21");
    key_value.insert(pair<string, vector<string>>(two, v21));

    string seven = "seven"; vector<string> v42;
    v42.push_back("42");
    key_value.insert(pair<string, vector<string>>(seven, v42));

    string three = "three"; vector<string> v17;
    v17.push_back("17");
    key_value.insert(pair<string, vector<string>>(three, v17));

    string four = "four"; vector<string> v11;
    v11.push_back("11");
    key_value.insert(pair<string, vector<string>>(four, v11));

    string five = "five"; vector<string> v24;
    v24.push_back("24");
    key_value.insert(pair<string, vector<string>>(five, v24));

    string six = "six"; vector<string> v23;
    v23.push_back("23");
    key_value.insert(pair<string, vector<string>>(six, v23));

    string twelve = "twelve"; vector<string> v71_56;
    v71_56.push_back("71");
    v71_56.push_back("56");
    key_value.insert(pair<string, vector<string>>(twelve, v71_56));


    string thirteen = "thirteen"; vector<string> v89_78_25;
    v89_78_25.push_back("89");
    v89_78_25.push_back("78");
    v89_78_25.push_back("25");
    key_value.insert(pair<string, vector<string>>(thirteen, v89_78_25));

    string nine = "nine"; vector<string> v68;
    v68.push_back("68");
    key_value.insert(pair<string, vector<string>>(nine, v68));


    string ten = "ten"; vector<string> v63;
    v63.push_back("63");
    key_value.insert(pair<string, vector<string>>(ten, v63));

    string eleven = "eleven"; vector<string> v69;
    v69.push_back("69");
    key_value.insert(pair<string, vector<string>>(eleven, v69));

    new_file.add_key_value(old_name_section0, key_value);

    //присваивание 2 секции имени
    string old_name_section1 = "Strings";
    new_file.add_name_section(old_name_section1);

    //добавление комментария к секции
    string comment_section1 = "And this section containts the strings";
    new_file.add_comment_section(old_name_section1, comment_section1);

    //заполнение 2 секции содержимым
    map<string, vector<string>> key_value_1;

    string zero_ = "zero"; vector<string> vlM;
    vlM.push_back("ABCDEFGHIJKLM");
    key_value_1.insert(pair<string, vector<string>>(zero_, vlM));

    string one_ = "one"; vector<string> vlH;
    vlH.push_back("ABCDEFGH");
    key_value_1.insert(pair<string, vector<string>>(one_, vlH));

    string two_ = "two"; vector<string> vlE;
    vlE.push_back("ABCDE");
    key_value_1.insert(pair<string, vector<string>>(two_, vlH));

    string three_ = "three"; vector<string> vlD;
    vlD.push_back("ABCD");
    key_value_1.insert(pair<string, vector<string>>(three_, vlD));

    string four_ = "four"; vector<string> vlC;
    vlC.push_back("ABC");
    key_value_1.insert(pair<string, vector<string>>(four_, vlC));

    string five_ = "five"; vector<string> vlA;
    vlA.push_back("A");
    key_value_1.insert(pair<string, vector<string>>(five_, vlA));

    string six_ = "six"; vector<string> vlB;
    vlB.push_back("AB");
    key_value_1.insert(pair<string, vector<string>>(six_, vlB));


    string seven_ = "seven"; vector<string> vlF;
    vlF.push_back("ABCDEF");
    key_value_1.insert(pair<string, vector<string>>(seven_, vlF));


    string eight_ = "eight"; vector<string> vlJ;
    vlJ.push_back("ABCDEFGHIJ");
    key_value_1.insert(pair<string, vector<string>>(eight_, vlJ));

    string nine_ = "nine"; vector<string> vlI;
    vlI.push_back("ABCDEFGHI");
    key_value_1.insert(pair<string, vector<string>>(nine_, vlI));


    string ten_ = "ten"; vector<string> vlL;
    vlL.push_back("ABCDEFGHIJKL");
    key_value_1.insert(pair<string, vector<string>>(ten_, vlL));

    string eleven_ = "eleven"; vector<string> vlK;
    vlK.push_back("ABCDEFGHIJK");
    key_value_1.insert(pair<string, vector<string>>(eleven_, vlK));

    string twelve_ = "twelve"; vector<string> vlS;
    vlS.push_back("ABCDEFGHIJKLMNOPQRS");
    key_value_1.insert(pair<string, vector<string>>(twelve_, vlS));

    string thirteen_ = "thirteen"; vector<string> vlO;
    vlO.push_back("ABCDEFGHIJKLMNO");
    key_value_1.insert(pair<string, vector<string>>(thirteen_, vlO));

    string fourteen_ = "fourteen"; vector<string> vlN;
    vlN.push_back("ABCDEFGHIJKLMN");
    key_value_1.insert(pair<string, vector<string>>(fourteen_, vlN));

    string fifteen_ = "fifteen"; vector<string> vlQ;
    vlQ.push_back("ABCDEFGHIJKLMNOPQ");
    key_value_1.insert(pair<string, vector<string>>(fifteen_, vlQ));

    string sixteen_ = "sixteen"; vector<string> vlP;
    vlP.push_back("ABCDEFGHIJKLMNOP");
    key_value_1.insert(pair<string, vector<string>>(sixteen_, vlP));

    string seventeen_ = "seventeen"; vector<string> vlR;
    vlR.push_back("ABCDEFGHIJKLMNOPQR");
    key_value_1.insert(pair<string, vector<string>>(seventeen_, vlR));

    string eighteen_ = "eighteen"; vector<string> vlV;
    vlV.push_back("ABCDEFGHIJKLMNOPQRSTUV");
    key_value_1.insert(pair<string, vector<string>>(eighteen_, vlV));

    string nineteen_ = "nineteen"; vector<string> vlU;
    vlU.push_back("ABCDEFGHIJKLMNOPQRSTU");
    key_value_1.insert(pair<string, vector<string>>(nineteen_, vlU));

    string twenty_ = "twenty"; vector<string> vlT;
    vlT.push_back("ABCDEFGHIJKLMNOPQRST");
    key_value_1.insert(pair<string, vector<string>>(twenty_, vlT));

    string twenty_one_ = "twenty-one"; vector<string> vlX;
    vlX.push_back("ABCDEFGHIJKLMNOPQRSTUVWX");
    key_value_1.insert(pair<string, vector<string>>(twenty_one_, vlX));

    string twenty_two_ = "twenty-two"; vector<string> vlW;
    vlW.push_back("ABCDEFGHIJKLMNOPQRSTUVW");
    key_value_1.insert(pair<string, vector<string>>(twenty_two_, vlW));


    string twenty_three_ = "twenty-three"; vector<string> vlY;
    vlY.push_back("ABCDEFGHIJKLMNOPQRSTUVWXY");
    key_value_1.insert(pair<string, vector<string>>(twenty_three_, vlY));

    string twenty_four_ = "twenty-four"; vector<string> vlZ;
    vlZ.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    key_value_1.insert(pair<string, vector<string>>(twenty_four_, vlZ));

    new_file.add_key_value(old_name_section1, key_value_1);


    //изменение имён секций
    string new_name_0  = "Integers";
    new_file.change_name_section(old_name_section0, new_name_0);
    string new_name_1 = "Alphabet";
    new_file.change_name_section(old_name_section1, new_name_1);

    //удаление значений
    string num = "45";
    new_file.delete_value(new_name_0, eight, num);
    num = "78";
    new_file.delete_value(new_name_0, thirteen, num);
    new_file.delete_value(new_name_0, twelve);
    new_file.delete_value(new_name_0, eleven);

    new_file.delete_value(new_name_1, five_);
    new_file.delete_value(new_name_1, twelve_);
    new_file.delete_value(new_name_1, sixteen_);
    new_file.delete_value(new_name_1, twenty_);
    new_file.delete_value(new_name_1, twenty_two_);
    new_file.delete_value(new_name_1, twenty_four_);

    string name_file = "test";

    //создание пустого ini-файла
    new_file.create_file(name_file);

    //его заполнение
    new_file.write_file(name_file);

    //проверка содержимого ini-файла
    CIni check_file;

    //чтение ini-файла
    check_file.read_file(name_file);

    /*содержимое ini-файла "test" после внесённых изменений имеет следующий вид:
    [Integers]
    ;This section contains the numbers
    five=24
    four=11
    nine=68
    one=35
    seven=42
    six=23
    ten=63
    three=17
    two=21
    zero=60
    [Alphabet]
    ;And this section containts the strings
    eight=ABCDEFGHIJ
    eighteen=ABCDEFGHIJKLMNOPQRSTUV
    eleven=ABCDEFGHIJK
    fifteen=ABCDEFGHIJKLMNOPQ
    four=ABC
    fourteen=ABCDEFGHIJKLMN
    nine=ABCDEFGHI
    nineteen=ABCDEFGHIJKLMNOPQRSTU
    one=ABCDEFGH
    seven=ABCDEF
    seventeen=ABCDEFGHIJKLMNOPQR
    six=AB
    ten=ABCDEFGHIJKL
    thirteen=ABCDEFGHIJKLMNO
    three=ABCD
    twenty-one=ABCDEFGHIJKLMNOPQRSTUVWX
    twenty-three=ABCDEFGHIJKLMNOPQRSTUVWXY
    two=ABCDEFGH
    zero=ABCDEFGHIJKLM*/

    unsigned size_map_s1 = 12;
    ASSERT_EQ(size_map_s1, new_file.get_size_key_value(new_name_0));
    unsigned size_map_s2 = 19;
    ASSERT_EQ(size_map_s2 , new_file.get_size_key_value(new_name_0));

    vector<string> res0;
    res0.push_back("70");
    ASSERT_TRUE(res0 == check_file.getValue(new_name_0, eight));

    vector<string> res1;
    res1.push_back("89");
    res1.push_back("25");
    ASSERT_TRUE(res1 == check_file.getValue(new_name_0, thirteen));

    new_file.delete_file(name_file);
    cout << "good";
}
TEST(test003, test_CIni_change_value_add_value)
{
    /*содержимое ini-файла "test" до внесённых изменений имеет следующий вид:
     [Numbers]
     ;This section contains the numbers
     eight=70, 45
     eleven=69
     five=24
     four=11
     nine=68
     one=35
     seven=42
     six=23
     ten=63
     thirteen=89, 78, 25
     three=17
     twelve=71, 56
     two=21
     zero=60
     [Strings]
     ;And this section containts the strings
     eight=ABCDEFGHIJ
     eighteen=ABCDEFGHIJKLMNOPQRSTUV
     eleven=ABCDEFGHIJK
     fifteen=ABCDEFGHIJKLMNOPQ
     five=A
     four=ABC
     fourteen=ABCDEFGHIJKLMN
     nine=ABCDEFGHI
     nineteen=ABCDEFGHIJKLMNOPQRSTU
     one=ABCDEFGH
     seven=ABCDEF
     seventeen=ABCDEFGHIJKLMNOPQR
     six=AB
     sixteen=ABCDEFGHIJKLMNOP
     ten=ABCDEFGHIJKL
     thirteen=ABCDEFGHIJKLMNO
     three=ABCD
     twelve=ABCDEFGHIJKLMNOPQRS
     twenty=ABCDEFGHIJKLMNOPQRST
     twenty-four=ABCDEFGHIJKLMNOPQRSTUVWXYZ
     twenty-one=ABCDEFGHIJKLMNOPQRSTUVWX
     twenty-three=ABCDEFGHIJKLMNOPQRSTUVWXY
     two=ABCDE
     zero=ABCDEFGHIJKLM

    */
    CIni new_file;
    string name_section_0 = "Numbers";
    new_file.add_name_section(name_section_0);

    //добавление комментария к секции
    string comment_section = "This section contains the numbers";
    new_file.add_comment_section(name_section_0, comment_section);
    map<string, vector<string>> key_value;

    //заполнение 1 секции содержимым
    string zero = "zero"; vector<string> v60;
    v60.push_back("60");
    key_value.insert(pair<string, vector<string>>(zero, v60));


    string one = "one"; vector<string> v35;
    v35.push_back("35");
    key_value.insert(pair<string, vector<string>>(one, v35));

    string eight = "eight"; vector<string> v70_45;
    v70_45.push_back("70");
    v70_45.push_back("45");
    key_value.insert(pair<string, vector<string>>(eight, v70_45));

    string two = "two"; vector<string> v21;
    v21.push_back("21");
    key_value.insert(pair<string, vector<string>>(two, v21));

    string seven = "seven"; vector<string> v42;
    v42.push_back("42");
    key_value.insert(pair<string, vector<string>>(seven, v42));

    string three = "three"; vector<string> v17;
    v17.push_back("17");
    key_value.insert(pair<string, vector<string>>(three, v17));

    string four = "four"; vector<string> v11;
    v11.push_back("11");
    key_value.insert(pair<string, vector<string>>(four, v11));

    string five = "five"; vector<string> v24;
    v24.push_back("24");
    key_value.insert(pair<string, vector<string>>(five, v24));

    string six = "six"; vector<string> v23;
    v23.push_back("23");
    key_value.insert(pair<string, vector<string>>(six, v23));

    string twelve = "twelve"; vector<string> v71_56;
    v71_56.push_back("71");
    v71_56.push_back("56");
    key_value.insert(pair<string, vector<string>>(twelve, v71_56));


    string thirteen = "thirteen"; vector<string> v89_78_25;
    v89_78_25.push_back("89");
    v89_78_25.push_back("78");
    v89_78_25.push_back("25");
    key_value.insert(pair<string, vector<string>>(thirteen, v89_78_25));

    string nine = "nine"; vector<string> v68;
    v68.push_back("68");
    key_value.insert(pair<string, vector<string>>(nine, v68));


    string ten = "ten"; vector<string> v63;
    v63.push_back("63");
    key_value.insert(pair<string, vector<string>>(ten, v63));

    string eleven = "eleven"; vector<string> v69;
    v69.push_back("69");
    key_value.insert(pair<string, vector<string>>(eleven, v69));

    new_file.add_key_value(name_section_0, key_value);

    //присваивание 2 секции имени
    string name_section_1 = "Strings";
    new_file.add_name_section(name_section_1);

    //добавление комментария к секции
    string comment_section1 = "And this section containts the strings";
    new_file.add_comment_section(name_section_1, comment_section1);

    //заполнение 2 секции содержимым
    map<string, vector<string>> key_value_1;

    string zero_ = "zero"; vector<string> vlM;
    vlM.push_back("ABCDEFGHIJKLM");
    key_value_1.insert(pair<string, vector<string>>(zero_, vlM));

    string one_ = "one"; vector<string> vlH;
    vlH.push_back("ABCDEFGH");
    key_value_1.insert(pair<string, vector<string>>(one_, vlH));

    string two_ = "two"; vector<string> vlE;
    vlE.push_back("ABCDE");
    key_value_1.insert(pair<string, vector<string>>(two_, vlH));

    string three_ = "three"; vector<string> vlD;
    vlD.push_back("ABCD");
    key_value_1.insert(pair<string, vector<string>>(three_, vlD));

    string four_ = "four"; vector<string> vlC;
    vlC.push_back("ABC");
    key_value_1.insert(pair<string, vector<string>>(four_, vlC));

    string five_ = "five"; vector<string> vlA;
    vlA.push_back("A");
    key_value_1.insert(pair<string, vector<string>>(five_, vlA));

    string six_ = "six"; vector<string> vlB;
    vlB.push_back("AB");
    key_value_1.insert(pair<string, vector<string>>(six_, vlB));


    string seven_ = "seven"; vector<string> vlF;
    vlF.push_back("ABCDEF");
    key_value_1.insert(pair<string, vector<string>>(seven_, vlF));


    string eight_ = "eight"; vector<string> vlJ;
    vlJ.push_back("ABCDEFGHIJ");
    key_value_1.insert(pair<string, vector<string>>(eight_, vlJ));

    string nine_ = "nine"; vector<string> vlI;
    vlI.push_back("ABCDEFGHI");
    key_value_1.insert(pair<string, vector<string>>(nine_, vlI));


    string ten_ = "ten"; vector<string> vlL;
    vlL.push_back("ABCDEFGHIJKL");
    key_value_1.insert(pair<string, vector<string>>(ten_, vlL));

    string eleven_ = "eleven"; vector<string> vlK;
    vlK.push_back("ABCDEFGHIJK");
    key_value_1.insert(pair<string, vector<string>>(eleven_, vlK));

    string twelve_ = "twelve"; vector<string> vlS;
    vlS.push_back("ABCDEFGHIJKLMNOPQRS");
    key_value_1.insert(pair<string, vector<string>>(twelve_, vlS));

    string thirteen_ = "thirteen"; vector<string> vlO;
    vlO.push_back("ABCDEFGHIJKLMNO");
    key_value_1.insert(pair<string, vector<string>>(thirteen_, vlO));

    string fourteen_ = "fourteen"; vector<string> vlN;
    vlN.push_back("ABCDEFGHIJKLMN");
    key_value_1.insert(pair<string, vector<string>>(fourteen_, vlN));

    string fifteen_ = "fifteen"; vector<string> vlQ;
    vlQ.push_back("ABCDEFGHIJKLMNOPQ");
    key_value_1.insert(pair<string, vector<string>>(fifteen_, vlQ));

    string sixteen_ = "sixteen"; vector<string> vlP;
    vlP.push_back("ABCDEFGHIJKLMNOP");
    key_value_1.insert(pair<string, vector<string>>(sixteen_, vlP));

    string seventeen_ = "seventeen"; vector<string> vlR;
    vlR.push_back("ABCDEFGHIJKLMNOPQR");
    key_value_1.insert(pair<string, vector<string>>(seventeen_, vlR));

    string eighteen_ = "eighteen"; vector<string> vlV;
    vlV.push_back("ABCDEFGHIJKLMNOPQRSTUV");
    key_value_1.insert(pair<string, vector<string>>(eighteen_, vlV));

    string nineteen_ = "nineteen"; vector<string> vlU;
    vlU.push_back("ABCDEFGHIJKLMNOPQRSTU");
    key_value_1.insert(pair<string, vector<string>>(nineteen_, vlU));

    string twenty_ = "twenty"; vector<string> vlT;
    vlT.push_back("ABCDEFGHIJKLMNOPQRST");
    key_value_1.insert(pair<string, vector<string>>(twenty_, vlT));

    string twenty_one_ = "twenty-one"; vector<string> vlX;
    vlX.push_back("ABCDEFGHIJKLMNOPQRSTUVWX");
    key_value_1.insert(pair<string, vector<string>>(twenty_one_, vlX));

    string twenty_two_ = "twenty-two"; vector<string> vlW;
    vlW.push_back("ABCDEFGHIJKLMNOPQRSTUVW");
    key_value_1.insert(pair<string, vector<string>>(twenty_two_, vlW));


    string twenty_three_ = "twenty-three"; vector<string> vlY;
    vlY.push_back("ABCDEFGHIJKLMNOPQRSTUVWXY");
    key_value_1.insert(pair<string, vector<string>>(twenty_three_, vlY));

    string twenty_four_ = "twenty-four"; vector<string> vlZ;
    vlZ.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    key_value_1.insert(pair<string, vector<string>>(twenty_four_, vlZ));

    new_file.add_key_value(name_section_1, key_value_1);

    //изменение значений
    vector<string> new_zero;
    new_zero.push_back("1000000");
    new_file.change_value(name_section_0, zero, new_zero);

    vector<string> new_eight;
    new_eight.push_back("4000");
    new_file.change_value(name_section_0, eight, new_eight);

    string new_value_0 = "678";
    new_file.add_value(name_section_0, three, new_value_0);

    string new_value_1 = "9000";
    string old_value_1 = "71";
    new_file.change_value(name_section_0, twelve, old_value_1, new_value_1);

    string new_value_2 = "80000";
    string old_value_2 = "78";
    new_file.change_value(name_section_0, thirteen, old_value_2, new_value_2);
    string new_value_3 = "606";
    new_file.add_value(name_section_0, thirteen, new_value_3);

    vector<string> new_vec_4;
    new_vec_4.push_back("500");
    new_file.change_value(name_section_0, eleven, new_vec_4);

    vector<string> new_vec_5;
    new_vec_5.push_back("89457");

    string new_key_0 = "fourteen";
    new_file.add_value(name_section_0, new_key_0, new_vec_5);

    vector<string> new_vec_6;
    new_vec_6.push_back("Yeah");
    new_file.change_value(name_section_1, zero, new_vec_6);

    vector<string> new_vec_7;
    new_vec_7.push_back("Sub-zero");
    new_vec_7.push_back("Hello");
    new_file.change_value(name_section_1, four_, new_vec_7);

    vector<string> new_vec_8;
    new_vec_8.push_back("HZ");
    new_file.change_value(name_section_1, twelve_, new_vec_8);

    string new_value_4 = "CHAMPION";
    new_file.add_value(name_section_1, fourteen_, new_value_4);

    vector<string> new_vec_9;
    new_vec_9.push_back("Scorpion");
    new_file.change_value(name_section_1, sixteen_, new_vec_9);

    string new_value_5 = "GOLIAF";
    string new_value_6 = "SAMSON";
    new_file.add_value(name_section_1, nineteen_, new_value_5);
    new_file.add_value(name_section_1, nineteen_, new_value_6);

    vector<string> new_vec_10;
    new_vec_10.push_back("GLADIATOR");
    new_file.change_value(name_section_1, twenty_, new_vec_10);

    vector<string> new_vec_11;
    new_vec_11.push_back("Walorant");
    new_vec_11.push_back("GOOD");
    new_vec_11.push_back("Cinema");
    new_file.change_value(name_section_1, twenty_three_, new_vec_11);

    vector<string> new_vec_12;
    new_vec_12.push_back("NEW_YEAR");
    new_vec_12.push_back("CHRISTMAS");
    string key40 = "twenty-five";
    new_file.add_value(name_section_1, key40, new_vec_12);

    vector<string> new_vec_13;
    new_vec_13.push_back("HEAVY_RAIN");
    string key41 = "twenty-six";
    new_file.add_value(name_section_1, key41, new_vec_13);
    string name_file = "test";
    new_file.create_file(name_file);
    new_file.write_file(name_file);
    /*
    [Numbers]
    ;This section contains the numbers
    eight=4000
    eleven=500
    five=24
    four=11
    fourteen=89457
    nine=68
    one=35
    seven=42
    six=23
    ten=63
    thirteen=89, 80000, 25, 606
    three=17, 678
    twelve=9000, 56
    two=21
    zero=1000000
    [Strings]
    ;And this section containts the strings
    eight=ABCDEFGHIJ
    eighteen=ABCDEFGHIJKLMNOPQRSTUV
    eleven=ABCDEFGHIJK
    fifteen=ABCDEFGHIJKLMNOPQ
    five=A
    four=Sub-zero, Hello
    fourteen=ABCDEFGHIJKLMN, CHAMPION
    nine=ABCDEFGHI
    nineteen=ABCDEFGHIJKLMNOPQRSTU, GOLIAF, SAMSON
    one=ABCDEFGH
    seven=ABCDEF
    seventeen=ABCDEFGHIJKLMNOPQR
    six=AB
    sixteen=Scorpion
    ten=ABCDEFGHIJKL
    thirteen=ABCDEFGHIJKLMNO
    three=ABCD
    twelve=HZ
    twenty=GLADIATOR
    twenty-five=NEW_YEAR, CHRISTMAS
    twenty-four=ABCDEFGHIJKLMNOPQRSTUVWXYZ
    twenty-one=ABCDEFGHIJKLMNOPQRSTUVWX
    twenty-six=HEAVY_RAIN
    twenty-three=Walorant, GOOD, Cinema
    twenty-two=ABCDEFGHIJKLMNOPQRSTUVW
    two=ABCDEFGH
    zero=Yeah*/
}






























#endif // CINI_TEST_H
