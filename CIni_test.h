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
       key_value_1.insert(pair<string, vector<string>>(two_, vlE));

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
    ASSERT_EQ(size_map_s2 , new_file.get_size_key_value(new_name_1));

    vector<string> res0;
    res0.push_back("70");
    ASSERT_TRUE(res0 == check_file.getValue(new_name_0, eight));

    vector<string> res1;
    res1.push_back("89");
    res1.push_back("25");
    ASSERT_TRUE(res1 == check_file.getValue(new_name_0, thirteen));

    new_file.delete_file(name_file);
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
    key_value_1.insert(pair<string, vector<string>>(two_, vlE));

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
    //изменение значений 1 секции
    vector<string> v1000000;
    v1000000.push_back("1000000");
    new_file.change_value(name_section_0, zero, v1000000);

    vector<string> v4000;
    v4000.push_back("4000");
    new_file.change_value(name_section_0, eight, v4000);

    string vl678 = "678";
    new_file.add_value(name_section_0, three, vl678);

    string vl9000 = "9000";
    string vl71 = "71";
    new_file.change_value(name_section_0, twelve, vl71, vl9000);

    string vl80000 = "80000";
    string vl78 = "78";
    new_file.change_value(name_section_0, thirteen, vl78, vl80000);
    string vl606 = "606";
    new_file.add_value(name_section_0, thirteen, vl606);

    vector<string> v500;
    v500.push_back("500");
    new_file.change_value(name_section_0, eleven, v500);

    vector<string> v89457;
    v89457.push_back("89457");
    string fourteen = "fourteen";
    new_file.add_value(name_section_0, fourteen, v89457);

    //изменение значений 2 секции
    vector<string> vYeah;
    vYeah.push_back("Yeah");
    new_file.change_value(name_section_1, zero_, vYeah);

    vector<string> vSub_zero_Hello;
    vSub_zero_Hello.push_back("Sub-zero");
    vSub_zero_Hello.push_back("Hello");
    new_file.change_value(name_section_1, four_, vSub_zero_Hello);

    vector<string> vHZ;
    vHZ.push_back("HZ");
    new_file.change_value(name_section_1, twelve_, vHZ);

    string vlCHAMPION = "CHAMPION";
    new_file.add_value(name_section_1, fourteen_, vlCHAMPION);

    vector<string> vScorpion;
    vScorpion.push_back("Scorpion");
    new_file.change_value(name_section_1, sixteen_, vScorpion);

    string vlGOLIAF = "GOLIAF";
    string vlSAMSON = "SAMSON";
    new_file.add_value(name_section_1, nineteen_, vlGOLIAF);
    new_file.add_value(name_section_1, nineteen_, vlSAMSON);

    vector<string> vGLADIATOR;
    vGLADIATOR.push_back("GLADIATOR");
    new_file.change_value(name_section_1, twenty_, vGLADIATOR);

    vector<string> vWalorant;
    vWalorant.push_back("Walorant");
    vWalorant.push_back("GOOD");
    vWalorant.push_back("Cinema");
    new_file.change_value(name_section_1, twenty_three_, vWalorant);

    vector<string> vNEW_YEAR;
    vNEW_YEAR.push_back("NEW_YEAR");
    vNEW_YEAR.push_back("CHRISTMAS");
    string twenty_five_ = "twenty-five";
    new_file.add_value(name_section_1, twenty_five_, vNEW_YEAR);

    vector<string> vHEAVY_RAIN;
    vHEAVY_RAIN.push_back("HEAVY_RAIN");
    string twenty_six_ = "twenty-six";
    new_file.add_value(name_section_1, twenty_six_, vHEAVY_RAIN);

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


     new_file.delete_file(name_file);

     ASSERT_TRUE(v1000000 == check_file.getValue(name_section_0, zero));

     ASSERT_TRUE(v35 == check_file.getValue(name_section_0, one));

     ASSERT_TRUE(v4000 == check_file.getValue(name_section_0, eight));

     ASSERT_TRUE(v21 == check_file.getValue(name_section_0, two));

     ASSERT_TRUE(v42 == check_file.getValue(name_section_0, seven));

     vector<string> res_0;
     res_0.push_back("17");
     res_0.push_back("678");
     ASSERT_TRUE(res_0 == check_file.getValue(name_section_0, three));

     ASSERT_TRUE(v11 == check_file.getValue(name_section_0, four));

     ASSERT_TRUE(v24 == check_file.getValue(name_section_0, five));

     ASSERT_TRUE(v23 == check_file.getValue(name_section_0, six));

     vector<string> res_1;
     res_1.push_back("9000");
     res_1.push_back("56");
     ASSERT_TRUE(res_1 == check_file.getValue(name_section_0, twelve));

     vector<string> res_2;
     res_2.push_back("89");
     res_2.push_back("80000");
     res_2.push_back("25");
     res_2.push_back("606");
     ASSERT_TRUE(res_2 == check_file.getValue(name_section_0, thirteen));

     ASSERT_TRUE(v68 == check_file.getValue(name_section_0, nine));

     ASSERT_TRUE(v63 == check_file.getValue(name_section_0, ten));

     vector<string> res_3;
     res_3.push_back("500");
     ASSERT_TRUE(res_3 == check_file.getValue(name_section_0, eleven));

     ASSERT_TRUE(vYeah == check_file.getValue(name_section_1, zero_));

     ASSERT_TRUE(vlH == check_file.getValue(name_section_1, one_));

     ASSERT_TRUE(vlE == check_file.getValue(name_section_1, two_));

     ASSERT_TRUE(vlD == check_file.getValue(name_section_1, three_));

     ASSERT_TRUE(vSub_zero_Hello == check_file.getValue(name_section_1, four_));

     ASSERT_TRUE(vlA == check_file.getValue(name_section_1, five_));

     ASSERT_TRUE(vlB == check_file.getValue(name_section_1, six_));

     ASSERT_TRUE(vlF == check_file.getValue(name_section_1, seven_));

     ASSERT_TRUE(vlJ == check_file.getValue(name_section_1, eight_));

     ASSERT_TRUE(vlI == check_file.getValue(name_section_1, nine_));

     ASSERT_TRUE(vlL == check_file.getValue(name_section_1, ten_));

     ASSERT_TRUE(vlK == check_file.getValue(name_section_1, eleven_));

     ASSERT_TRUE(vHZ == check_file.getValue(name_section_1, twelve_));

     ASSERT_TRUE(vlO == check_file.getValue(name_section_1, thirteen_));

     vector<string> res_4;
     res_4.push_back("ABCDEFGHIJKLMN");
     res_4.push_back("CHAMPION");
     ASSERT_TRUE(res_4 == check_file.getValue(name_section_1, fourteen_));

     ASSERT_TRUE(vlQ == check_file.getValue(name_section_1, fifteen_));

     ASSERT_TRUE(vScorpion == check_file.getValue(name_section_1, sixteen_));

     ASSERT_TRUE(vlR == check_file.getValue(name_section_1, seventeen_));

     ASSERT_TRUE(vlV == check_file.getValue(name_section_1, eighteen_));

     vector<string> res_5;
     res_5.push_back("ABCDEFGHIJKLMNOPQRSTU");
     res_5.push_back("GOLIAF");
     res_5.push_back("SAMSON");
     ASSERT_TRUE(res_5 == check_file.getValue(name_section_1, nineteen_));

     ASSERT_TRUE(vGLADIATOR == check_file.getValue(name_section_1, twenty_));

     ASSERT_TRUE(vlX == check_file.getValue(name_section_1, twenty_one_));

     ASSERT_TRUE(vlW == check_file.getValue(name_section_1, twenty_two_));

     ASSERT_TRUE(vWalorant == check_file.getValue(name_section_1, twenty_three_));

     ASSERT_TRUE(vlZ == check_file.getValue(name_section_1, twenty_four_));

     ASSERT_TRUE(vNEW_YEAR == check_file.getValue(name_section_1, twenty_five_));

     ASSERT_TRUE(vHEAVY_RAIN == check_file.getValue(name_section_1, twenty_six_));
     check_file.delete_file(name_file);
}

#endif // CINI_TEST_H
