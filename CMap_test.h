#ifndef CMAP_TEST_H
#define CMAP_TEST_H
#include "CMap.h"
#include <gtest/include/gtest/gtest.h>
using namespace std;

TEST(test049, test_CMap_add_pair_size_search_getValue)
{
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


    const char *res1[25] =
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
    unsigned size  = 25;
    unsigned size1 = map.size();
    bool res;
    ASSERT_EQ(size, size1);
    CString temp = map.getValue(k25);
    CString temp1 = *res1[24];
    CString node;
    for(unsigned  i = 1, j = 0; i < map.size() + 1; i++, j++)
    {
        node = i;
        res = map.search(node);
        ASSERT_TRUE(res);
        ASSERT_EQ(*res1[j], *map.getValue(node).data());
        /*cout << map.getValue(node).data() << endl;
        cout << endl;*/
    }

    cout << "//-------------------------//" <<endl;
    CMap<CString, CString> map1;
    map1 = map;
    for(unsigned  i = 1, j = 0; i < map1.size() + 1; i++, j++)
    {
        node = i;
        res = map1.search(node);
        ASSERT_TRUE(res);
        ASSERT_EQ(*res1[j], *map1.getValue(node).data());
        //cout << map1.getValue(node).data() << endl;
        //cout << endl;
    }
}

TEST(test050, test_CMap_operator_eq_delete_key)
{
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

    map.delete_key(k17);
    map.delete_key(k22);
    map.delete_key(k6);
    map.delete_key(k13);
    map.delete_key(k9);

    const char *res1[20] =
    {
        /*1 =*/  "ABCDEFGHIJKLM",
        /*2 =*/  "ABCDEFGH",
        /*3 =*/  "ABCDE",
        /*4 =*/  "ABCD",
        /*5 =*/  "ABC",
        /*7 =*/  "AB",
        /*8 =*/  "ABCDEF",
        /*10 =*/ "ABCDEFGHI",
        /*11 =*/ "ABCDEFGHIJKL",
        /*12 =*/ "ABCDEFGHIJK",
        /*14 =*/ "ABCDEFGHIJKLMNO",
        /*15 =*/ "ABCDEFGHIJKLMN",
        /*16 =*/ "ABCDEFGHIJKLMNOPQ",
        /*18 =*/ "ABCDEFGHIJKLMNOPQR",
        /*19 =*/ "ABCDEFGHIJKLMNOPQRSTUV",
        /*20 =*/ "ABCDEFGHIJKLMNOPQRSTU",
        /*21 =*/ "ABCDEFGHIJKLMNOPQRST",
        /*23 =*/ "ABCDEFGHIJKLMNOPQRSTUVW",
        /*24 =*/ "ABCDEFGHIJKLMNOPQRSTUVWXY",
        /*25 =*/ "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    };

    CString node;
    for(unsigned  i = 1, j = 0; i < map.size() + 1; i++, j++)
    {
        node = i;
        if(map.search(node))
        {
            ASSERT_EQ(*res1[j], *map.getValue(node).data());
            //cout << map.getValue(node).data() << endl;
            //cout << endl;
        }
    }
}

TEST(test051, test_CMap_CVector)
{
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

    int res[18] =
    {
        60,
        35,
        70, 45,
        21,
        42,
        17,
        11,
        24,
        23,
        71, 56,
        89, 78, 25,
        68,
        63,
        69
    };
    unsigned j = 0;
    for(unsigned k = 1; k < map.size() + 1; k++)
    {
        //cout << k << " = ";
        for(unsigned h = 0; h < map.getValue(k).size(); h++, j++)
        {
            ASSERT_EQ(res[j], map.getValue(k).at(h));
            //cout << map.getValue(k).at(h) << " ";
        }
        //cout << endl;
    }
}

#endif // CMAP_TEST_H
