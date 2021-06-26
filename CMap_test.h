 #ifndef CMAP_TEST_H
#define CMAP_TEST_H
#include "CMap.h"
#include <gtest/include/gtest/gtest.h>
using namespace std;

TEST(test049, test_CMap_add_pair_size_search_getValue)
{
    /*map содержит следующие ключ значения:
        1 =  "ABCDEFGHIJKLM",
        2 =  "ABCDEFGH",
        3 =  "ABCDE",
        4 =  "ABCD",
        5 =  "ABC",
        6 =  "A",
        7 =  "AB",
        8 =  "ABCDEF",
        9 =  "ABCDEFGHIJ",
        10 = "ABCDEFGHI",
        11 = "ABCDEFGHIJKL",
        12 = "ABCDEFGHIJK",
        13 = "ABCDEFGHIJKLMNOPQRS",
        14 = "ABCDEFGHIJKLMNO",
        15 = "ABCDEFGHIJKLMN",
        16 = "ABCDEFGHIJKLMNOPQ",
        17 = "ABCDEFGHIJKLMNOP",
        18 = "ABCDEFGHIJKLMNOPQR",
        19 = "ABCDEFGHIJKLMNOPQRSTUV",
        20 = "ABCDEFGHIJKLMNOPQRSTU",
        21 = "ABCDEFGHIJKLMNOPQRST",
        22 = "ABCDEFGHIJKLMNOPQRSTUVWX",
        23 = "ABCDEFGHIJKLMNOPQRSTUVW",
        24 = "ABCDEFGHIJKLMNOPQRSTUVWXY",
        25 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    */

    //создание map
    CMap<CString, CString> map;
    CString k1(1); CString A("ABCDEFGHIJKLM");
    map.add_pair(1, A);

    CString k2(2); CString B("ABCDEFGH");
    map.add_pair(2, B);

    CString k3(3); CString C("ABCDE");
    map.add_pair(3, C);

    CString k4(4); CString D("ABCD");
    map.add_pair(4, D);

    CString k5(5); CString E("ABC");
    map.add_pair(5, E);

    CString k6(6); CString F("A");
    map.add_pair(6, F);

    CString k7(7); CString G("AB");
    map.add_pair(7, G);

    CString k8(8); CString H("ABCDEF");
    map.add_pair(8, H);

    CString k9(9); CString I("ABCDEFGHIJ");
    map.add_pair(9, I);

    CString k10(10); CString J("ABCDEFGHI");
    map.add_pair(10, J);

    CString k11(11); CString K("ABCDEFGHIJKL");
    map.add_pair(11, K);

    CString k12(12); CString L("ABCDEFGHIJK");
    map.add_pair(12, L);

    CString k13(13); CString M("ABCDEFGHIJKLMNOPQRS");
    map.add_pair(13, M);

    CString k14(14); CString N("ABCDEFGHIJKLMNO");
    map.add_pair(14, N);

    CString k15(15); CString P("ABCDEFGHIJKLMN");
    map.add_pair(15, P);

    CString k16(16); CString Q("ABCDEFGHIJKLMNOPQ");
    map.add_pair(16, Q);

    CString k17(17); CString R("ABCDEFGHIJKLMNOP");
    map.add_pair(17, R);

    CString k18(18); CString S("ABCDEFGHIJKLMNOPQR");
    map.add_pair(18, S);

    CString k19(19); CString T("ABCDEFGHIJKLMNOPQRSTUV");
    map.add_pair(19, T);

    CString k20(20); CString U("ABCDEFGHIJKLMNOPQRSTU");
    map.add_pair(20, U);

    CString k21(21); CString V("ABCDEFGHIJKLMNOPQRST");
    map.add_pair(21, V);

    CString k22(22); CString W("ABCDEFGHIJKLMNOPQRSTUVWX");
    map.add_pair(22, W);

    CString k23(23); CString X("ABCDEFGHIJKLMNOPQRSTUVW");
    map.add_pair(23, X);

    CString k24(24); CString Y("ABCDEFGHIJKLMNOPQRSTUVWXY");
    map.add_pair(24, Y);

    CString k25(25); CString Z("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    map.add_pair(25, Z);

    //проверка содержимого map
    ASSERT_TRUE(map.search(k1));
    const char *res1 = "ABCDEFGHIJKLM";
    ASSERT_STREQ(res1, map.getValue(k1).data());

    ASSERT_TRUE(map.search(k2));
    const char *res2 = "ABCDEFGH";
    ASSERT_STREQ(res2, map.getValue(k2).data());

    ASSERT_TRUE(map.search(k3));
    const char *res3 = "ABCDE";
    ASSERT_STREQ(res3, map.getValue(k3).data());

    ASSERT_TRUE(map.search(k4));
    const char *res4 = "ABCD";
    ASSERT_STREQ(res4, map.getValue(k4).data());

    ASSERT_TRUE(map.search(k5));
    const char *res5 = "ABC";
    ASSERT_STREQ(res5, map.getValue(k5).data());

    ASSERT_TRUE(map.search(k6));
    const char *res6 = "A";
    ASSERT_STREQ(res6, map.getValue(k6).data());

    ASSERT_TRUE(map.search(k7));
    const char *res7 = "AB";
    ASSERT_STREQ(res7, map.getValue(k7).data());

    ASSERT_TRUE(map.search(k8));
    const char *res8 = "ABCDEF";
    ASSERT_STREQ(res8, map.getValue(k8).data());

    ASSERT_TRUE(map.search(k9));
    const char *res9 = "ABCDEFGHIJ";
    ASSERT_STREQ(res9, map.getValue(k9).data());

    ASSERT_TRUE(map.search(k10));
    const char *res10 = "ABCDEFGHI";
    ASSERT_STREQ(res10, map.getValue(k10).data());

    ASSERT_TRUE(map.search(k11));
    const char *res11 = "ABCDEFGHIJKL";
    ASSERT_STREQ(res11, map.getValue(k11).data());

    ASSERT_TRUE(map.search(k12));
    const char *res12 = "ABCDEFGHIJK";
    ASSERT_STREQ(res12, map.getValue(k12).data());

    ASSERT_TRUE(map.search(k13));
    const char *res13 = "ABCDEFGHIJKLMNOPQRS";
    ASSERT_STREQ(res13, map.getValue(k13).data());

    ASSERT_TRUE(map.search(k14));
    const char *res14 = "ABCDEFGHIJKLMNO";
    ASSERT_STREQ(res14, map.getValue(k14).data());

    ASSERT_TRUE(map.search(k15));
    const char *res15 = "ABCDEFGHIJKLMN";
    ASSERT_STREQ(res15, map.getValue(k15).data());

    ASSERT_TRUE(map.search(k16));
    const char *res16 = "ABCDEFGHIJKLMNOPQ";
    ASSERT_STREQ(res16, map.getValue(k16).data());

    ASSERT_TRUE(map.search(k17));
    const char *res17 = "ABCDEFGHIJKLMNOP";
    ASSERT_STREQ(res17, map.getValue(k17).data());

    ASSERT_TRUE(map.search(k18));
    const char *res18 = "ABCDEFGHIJKLMNOPQR";
    ASSERT_STREQ(res18, map.getValue(k18).data());

    ASSERT_TRUE(map.search(k19));
    const char *res19 = "ABCDEFGHIJKLMNOPQRSTUV";
    ASSERT_STREQ(res19, map.getValue(k19).data());

    ASSERT_TRUE(map.search(k20));
    const char *res20 = "ABCDEFGHIJKLMNOPQRSTU";
    ASSERT_STREQ(res20, map.getValue(k20).data());

    ASSERT_TRUE(map.search(k21));
    const char *res21 = "ABCDEFGHIJKLMNOPQRST";
    ASSERT_STREQ(res21, map.getValue(k21).data());

    ASSERT_TRUE(map.search(k22));
    const char *res22 = "ABCDEFGHIJKLMNOPQRSTUVWX";
    ASSERT_STREQ(res22, map.getValue(k22).data());

    ASSERT_TRUE(map.search(k23));
    const char *res23 = "ABCDEFGHIJKLMNOPQRSTUVW";
    ASSERT_STREQ(res23, map.getValue(k23).data());

    ASSERT_TRUE(map.search(k24));
    const char *res24 = "ABCDEFGHIJKLMNOPQRSTUVWXY";
    ASSERT_STREQ(res24, map.getValue(k24).data());

    ASSERT_TRUE(map.search(k25));
    const char *res25 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    ASSERT_STREQ(res25, map.getValue(k25).data());

    unsigned size  = 25;
    unsigned res = map.size();
    ASSERT_EQ(size, res);

}

TEST(test050, test_CMap_operator_eq_delete_key)
{
    //создание map
    CMap<CString, CString> map;
    CString k1(1); CString A("ABCDEFGHIJKLM");
    map.add_pair(1, A);

    CString k2(2); CString B("ABCDEFGH");
    map.add_pair(2, B);

    CString k3(3); CString C("ABCDE");
    map.add_pair(3, C);

    CString k4(4); CString D("ABCD");
    map.add_pair(4, D);

    CString k5(5); CString E("ABC");
    map.add_pair(5, E);

    CString k6(6); CString F("A");
    map.add_pair(6, F);

    CString k7(7); CString G("AB");
    map.add_pair(7, G);

    CString k8(8); CString H("ABCDEF");
    map.add_pair(8, H);

    CString k9(9); CString I("ABCDEFGHIJ");
    map.add_pair(9, I);

    CString k10(10); CString J("ABCDEFGHI");
    map.add_pair(10, J);

    CString k11(11); CString K("ABCDEFGHIJKL");
    map.add_pair(11, K);

    CString k12(12); CString L("ABCDEFGHIJK");
    map.add_pair(12, L);

    CString k13(13); CString M("ABCDEFGHIJKLMNOPQRS");
    map.add_pair(13, M);

    CString k14(14); CString N("ABCDEFGHIJKLMNO");
    map.add_pair(14, N);

    CString k15(15); CString P("ABCDEFGHIJKLMN");
    map.add_pair(15, P);

    CString k16(16); CString Q("ABCDEFGHIJKLMNOPQ");
    map.add_pair(16, Q);

    CString k17(17); CString R("ABCDEFGHIJKLMNOP");
    map.add_pair(17, R);

    CString k18(18); CString S("ABCDEFGHIJKLMNOPQR");
    map.add_pair(18, S);

    CString k19(19); CString T("ABCDEFGHIJKLMNOPQRSTUV");
    map.add_pair(19, T);

    CString k20(20); CString U("ABCDEFGHIJKLMNOPQRSTU");
    map.add_pair(20, U);

    CString k21(21); CString V("ABCDEFGHIJKLMNOPQRST");
    map.add_pair(21, V);

    CString k22(22); CString W("ABCDEFGHIJKLMNOPQRSTUVWX");
    map.add_pair(22, W);

    CString k23(23); CString X("ABCDEFGHIJKLMNOPQRSTUVW");
    map.add_pair(23, X);

    CString k24(24); CString Y("ABCDEFGHIJKLMNOPQRSTUVWXY");
    map.add_pair(24, Y);

    CString k25(25); CString Z("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    map.add_pair(25, Z);

    //удаление узлов из дерева по выбранному ключу
    map.delete_key(k17);
    map.delete_key(k22);
    map.delete_key(k6);
    map.delete_key(k13);
    map.delete_key(k9);
    /*map до удаления узлов
        1 =  "ABCDEFGHIJKLM",
        2 =  "ABCDEFGH",
        3 =  "ABCDE",
        4 =  "ABCD",
        5 =  "ABC",
        6 =  "A",
        7 =  "AB",
        8 =  "ABCDEF",
        9 =  "ABCDEFGHIJ",
        10 = "ABCDEFGHI",
        11 = "ABCDEFGHIJKL",
        12 = "ABCDEFGHIJK",
        13 = "ABCDEFGHIJKLMNOPQRS",
        14 = "ABCDEFGHIJKLMNO",
        15 = "ABCDEFGHIJKLMN",
        16 = "ABCDEFGHIJKLMNOPQ",
        17 = "ABCDEFGHIJKLMNOP",
        18 = "ABCDEFGHIJKLMNOPQR",
        19 = "ABCDEFGHIJKLMNOPQRSTUV",
        20 = "ABCDEFGHIJKLMNOPQRSTU",
        21 = "ABCDEFGHIJKLMNOPQRST",
        22 = "ABCDEFGHIJKLMNOPQRSTUVWX",
        23 = "ABCDEFGHIJKLMNOPQRSTUVW",
        24 = "ABCDEFGHIJKLMNOPQRSTUVWXY",
        25 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    */
    /*map после удаления узлов
        1 =  "ABCDEFGHIJKLM",
        2 =  "ABCDEFGH",
        3 =  "ABCDE",
        4 =  "ABCD",
        5 =  "ABC",
        7 =  "AB",
        8 =  "ABCDEF",
        10 = "ABCDEFGHI",
        11 = "ABCDEFGHIJKL",
        12 = "ABCDEFGHIJK",
        14 = "ABCDEFGHIJKLMNO",
        15 = "ABCDEFGHIJKLMN",
        16 = "ABCDEFGHIJKLMNOPQ",
        18 = "ABCDEFGHIJKLMNOPQR",
        19 = "ABCDEFGHIJKLMNOPQRSTUV",
        20 = "ABCDEFGHIJKLMNOPQRSTU",
        21 = "ABCDEFGHIJKLMNOPQRST",
        23 = "ABCDEFGHIJKLMNOPQRSTUVW",
        24 = "ABCDEFGHIJKLMNOPQRSTUVWXY",
        25 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    */

    //проверка содержимого map
    ASSERT_TRUE(map.search(k1));
    const char *res1 = "ABCDEFGHIJKLM";
    ASSERT_STREQ(res1, map.getValue(k1).data());

    ASSERT_TRUE(map.search(k2));
    const char *res2 = "ABCDEFGH";
    ASSERT_STREQ(res2, map.getValue(k2).data());

    ASSERT_TRUE(map.search(k3));
    const char *res3 = "ABCDE";
    ASSERT_STREQ(res3, map.getValue(k3).data());

    ASSERT_TRUE(map.search(k4));
    const char *res4 = "ABCD";
    ASSERT_STREQ(res4, map.getValue(k4).data());

    ASSERT_TRUE(map.search(k5));
    const char *res5 = "ABC";
    ASSERT_STREQ(res5, map.getValue(k5).data());

    ASSERT_FALSE(map.search(k6));

    ASSERT_TRUE(map.search(k7));
    const char *res7 = "AB";
    ASSERT_STREQ(res7, map.getValue(k7).data());

    ASSERT_TRUE(map.search(k8));
    const char *res8 = "ABCDEF";
    ASSERT_STREQ(res8, map.getValue(k8).data());

    ASSERT_FALSE(map.search(k9));

    ASSERT_TRUE(map.search(k10));
    const char *res10 = "ABCDEFGHI";
    ASSERT_STREQ(res10, map.getValue(k10).data());

    ASSERT_TRUE(map.search(k11));
    const char *res11 = "ABCDEFGHIJKL";
    ASSERT_STREQ(res11, map.getValue(k11).data());

    ASSERT_TRUE(map.search(k12));
    const char *res12 = "ABCDEFGHIJK";
    ASSERT_STREQ(res12, map.getValue(k12).data());

    ASSERT_FALSE(map.search(k13));

    ASSERT_TRUE(map.search(k14));
    const char *res14 = "ABCDEFGHIJKLMNO";
    ASSERT_STREQ(res14, map.getValue(k14).data());

    ASSERT_TRUE(map.search(k15));
    const char *res15 = "ABCDEFGHIJKLMN";
    ASSERT_STREQ(res15, map.getValue(k15).data());

    ASSERT_TRUE(map.search(k16));
    const char *res16 = "ABCDEFGHIJKLMNOPQ";
    ASSERT_STREQ(res16, map.getValue(k16).data());

    ASSERT_FALSE(map.search(k17));

    ASSERT_TRUE(map.search(k18));
    const char *res18 = "ABCDEFGHIJKLMNOPQR";
    ASSERT_STREQ(res18, map.getValue(k18).data());

    ASSERT_TRUE(map.search(k19));
    const char *res19 = "ABCDEFGHIJKLMNOPQRSTUV";
    ASSERT_STREQ(res19, map.getValue(k19).data());

    ASSERT_TRUE(map.search(k20));
    const char *res20 = "ABCDEFGHIJKLMNOPQRSTU";
    ASSERT_STREQ(res20, map.getValue(k20).data());

    ASSERT_TRUE(map.search(k21));
    const char *res21 = "ABCDEFGHIJKLMNOPQRST";
    ASSERT_STREQ(res21, map.getValue(k21).data());

    ASSERT_FALSE(map.search(k22));

    ASSERT_TRUE(map.search(k23));
    const char *res23 = "ABCDEFGHIJKLMNOPQRSTUVW";
    ASSERT_STREQ(res23, map.getValue(k23).data());

    ASSERT_TRUE(map.search(k24));
    const char *res24 = "ABCDEFGHIJKLMNOPQRSTUVWXY";
    ASSERT_STREQ(res24, map.getValue(k24).data());

    ASSERT_TRUE(map.search(k25));
    const char *res25 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    ASSERT_STREQ(res25, map.getValue(k25).data());

    unsigned size  = 20;
    unsigned res = map.size();
    ASSERT_EQ(size, res);

}

TEST(test051, test_CMap_CVector)
{
    //создание map
    CMap<int , CVector<int>> map;
    int k1 = 1; CVector<int> vec1;
    vec1.push_back(60);
    map.add_pair(k1, vec1);

    int k2 = 2; CVector<int> vec2;
    vec2.push_back(35);
    map.add_pair(k2, vec2);

    int k3 = 3; CVector<int> vec3;
    vec3.push_back(70);
    vec3.push_back(45);
    map.add_pair(k3, vec3);

    int k4 = 4; CVector<int> vec4;
    vec4.push_back(21);
    map.add_pair(k4, vec4);

    int k5 = 5; CVector<int> vec5;
    vec5.push_back(42);
    map.add_pair(k5, vec5);

    int k6 = 6; CVector<int> vec6;
    vec6.push_back(17);
    map.add_pair(k6, vec6);

    int k7 = 7; CVector<int> vec7;
    vec7.push_back(11);
    map.add_pair(k7, vec7);

    int k8 = 8; CVector<int> vec8;
    vec8.push_back(24);
    map.add_pair(k8, vec8);

    int k9 = 9; CVector<int> vec9;
    vec9.push_back(23);
    map.add_pair(k9, vec9);

    int k10 = 10; CVector<int> vec10;
    vec10.push_back(71);
    vec10.push_back(56);
    map.add_pair(k10, vec10);

    int k11 = 11; CVector<int> vec11;
    vec11.push_back(89);
    vec11.push_back(78);
    vec11.push_back(25);
    map.add_pair(k11, vec11);

    int k12 = 12; CVector<int> vec12;
    vec12.push_back(68);
    map.add_pair(k12, vec12);

    int k13 = 13; CVector<int> vec13;
    vec13.push_back(63);
    map.add_pair(k13, vec13);

    int k14 = 14; CVector<int> vec14;
    vec14.push_back(69);
    map.add_pair(k14, vec14);

    /*map содержит следующие ключ значения
        1 =  60,
        2 =  35,
        3 =  70, 45,
        4 =  21,
        5 =  42,
        6 =  17,
        7 =  11,
        8 =  24,
        9 =  23,
        10 = 71, 56,
        11 = 89, 78, 25,
        12 = 68,
        13 = 63,
        14 = 69
    */

    //проверка содержимого map
    ASSERT_TRUE(map.search(k1));
    CVector<int> res;
    res.push_back(60);
    ASSERT_TRUE(res == map.getValue(k1));
    res.clear();

    ASSERT_TRUE(map.search(k2));
    res.push_back(35);
    ASSERT_TRUE(res == map.getValue(k2));
    res.clear();

    ASSERT_TRUE(map.search(k3));
    res.push_back(70);
    res.push_back(45);
    ASSERT_TRUE(res == map.getValue(k3));
    res.clear();

    ASSERT_TRUE(map.search(k4));
    res.push_back(21);
    ASSERT_TRUE(res == map.getValue(k4));
    res.clear();


    ASSERT_TRUE(map.search(k5));
    res.push_back(42);
    ASSERT_TRUE(res == map.getValue(k5));
    res.clear();

    ASSERT_TRUE(map.search(k6));
    res.push_back(17);
    ASSERT_TRUE(res == map.getValue(k6));
    res.clear();

    ASSERT_TRUE(map.search(k7));
    res.push_back(11);
    ASSERT_TRUE(res == map.getValue(k7));
    res.clear();

    ASSERT_TRUE(map.search(k8));
    res.push_back(24);
    ASSERT_TRUE(res == map.getValue(k8));
    res.clear();

    ASSERT_TRUE(map.search(k9));
    res.push_back(23);
    ASSERT_TRUE(res == map.getValue(k9));
    res.clear();

    ASSERT_TRUE(map.search(k10));
    res.push_back(71);
    res.push_back(56);
    ASSERT_TRUE(res == map.getValue(k10));
    res.clear();

    ASSERT_TRUE(map.search(k11));
    res.push_back(89);
    res.push_back(78);
    res.push_back(25);
    ASSERT_TRUE(res == map.getValue(k11));
    res.clear();

    ASSERT_TRUE(map.search(k12));
    res.push_back(68);
    ASSERT_TRUE(res == map.getValue(k12));
    res.clear();

    ASSERT_TRUE(map.search(k13));
    res.push_back(63);
    ASSERT_TRUE(res == map.getValue(k13));
    res.clear();

    ASSERT_TRUE(map.search(k14));
    res.push_back(69);
    ASSERT_TRUE(res == map.getValue(k14));
    res.clear();

}

TEST(test052, test_CMap_getKey)
{
    //создание map
    CMap<CString , CVector<int>> map;
    CString key = "zero"; CVector<int> value;
    value.push_back(60);
    map.add_pair(key, value);
    value.clear();

    key = "one";
    value.push_back(35);
    map.add_pair(key, value);
    value.clear();

    value.push_back(70);
    value.push_back(45);
    key = "two";
    map.add_pair(key, value);
    value.clear();

    key = "three";
    value.push_back(21);
    map.add_pair(key, value);
    value.clear();

    key = "four";
    value.push_back(42);
    map.add_pair(key, value);
    value.clear();

    key = "five";
    value.push_back(17);
    map.add_pair(key, value);
    value.clear();

    key = "six";
    value.push_back(24);
    map.add_pair(key, value);
    value.clear();

    key = "seven";
    value.push_back(11);
    map.add_pair(key, value);
    value.clear();

    key = "eight";
    value.push_back(23);
    map.add_pair(key, value);
    value.clear();

    key = "nine";
    value.push_back(71);
    value.push_back(56);
    map.add_pair(key, value);
    value.clear();

    key = "ten";
    value.push_back(89);
    value.push_back(78);
    value.push_back(25);
    map.add_pair(key, value);
    value.clear();

    key = "eleven";
    value.push_back(68);
    map.add_pair(key, value);
    value.clear();

    key = "twelve";
    value.push_back(63);
    map.add_pair(key, value);
    value.clear();

    key = "thirteen";
    value.push_back(69);
    map.add_pair(key, value);
    value.clear();

    //проверка работы функции getKey()
    unsigned node = 0;
    const char *res_k0 = "zero";
    ASSERT_STREQ(res_k0, map.getKey(node).data());

    node = 1;
    const char *res_k1 = "one";
    ASSERT_STREQ(res_k1, map.getKey(node).data());

    node = 2;
    const char *res_k2 = "three";
    ASSERT_STREQ(res_k2, map.getKey(node).data());

    node = 3;
    const char *res_k3 = "five";
    ASSERT_STREQ(res_k3, map.getKey(node).data());

    node = 4;
    const char *res_k4 = "seven";
    ASSERT_STREQ(res_k4, map.getKey(node).data());

    node = 5;
    const char *res_k5 = "six";
    ASSERT_STREQ(res_k5, map.getKey(node).data());

    node = 6;
    const char *res_k6 = "eight";
    ASSERT_STREQ(res_k6, map.getKey(node).data());

    node = 7;
    const char *res_k7 = "four";
    ASSERT_STREQ(res_k7, map.getKey(node).data());

    node = 8;
    const char *res_k8 = "two";
    ASSERT_STREQ(res_k8, map.getKey(node).data());

    node = 9;
    const char *res_k9 = "eleven";
    ASSERT_STREQ(res_k9, map.getKey(node).data());

    node = 10;
    const char *res_k10 = "twelve";
    ASSERT_STREQ(res_k10, map.getKey(node).data());

    node = 11;
    const char *res_k11 = "thirteen";
    ASSERT_STREQ(res_k11, map.getKey(node).data());

    node = 12;
    const char *res_k12 = "nine";
    ASSERT_STREQ(res_k12, map.getKey(node).data());

    node = 13;
    const char *res_k13 = "ten";
    ASSERT_STREQ(res_k13, map.getKey(node).data());
}

#endif // CMAP_TEST_H
