#ifndef CVECTOR_TEST_H
#define CVECTOR_TEST_H
#include "CString.h"
#include "CVector.h"
#include <gtest/include/gtest/gtest.h>
TEST(test031, test_CVector_push_back_and_size)
{
        CString a("Big");
        CString b("Bang");
        CString d("Theory");
        CString f("some");
        CVector<CString> vec;
        vec.push_back(a);
        vec.push_back(b);
        vec.push_back(d);
        vec.push_back(f);
        unsigned res = vec.size();
        unsigned value = 4;
        ASSERT_EQ(value, res);

        const char *res1[4] = {"Big", "Bang", "Theory", "some"};
        for(unsigned  i = 0; i < vec.size(); i++)
        {
            ASSERT_EQ(*res1[i], *vec.at(i).data());
            //cout << vec.at(i).data() <<endl;
        }
        //cout << "//-------------------------//" <<endl;
        CVector<bool> vec_bool;
        vec_bool.push_back(true);
        vec_bool.push_back(true);
        vec_bool.push_back(true);
        vec_bool.push_back(false);
        vec_bool.push_back(true);
        vec_bool.push_back(false);

        bool res2[6] = {true, true, true, false, true, false};
        for(unsigned  i = 0; i < vec_bool.size(); i++)
        {
            ASSERT_EQ(res2[i], vec_bool.at(i));
            //cout << vec_bool.at(i) <<endl;
        }
        //cout << "//-------------------------//" <<endl;
        CVector<int> vec_int;
        vec_int.push_back(1);
        vec_int.push_back(2);
        vec_int.push_back(3);
        vec_int.push_back(4);
        vec_int.push_back(5);
        vec_int.push_back(6);

        int res3[6] = {1, 2, 3, 4, 5, 6};
        for(unsigned  i = 0; i < vec_int.size(); i++)
        {
            ASSERT_EQ(res3[i], vec_int.at(i));
            //cout << vec_int.at(i) <<endl;
        }
}

TEST(test032, test_CVector_resize)
{
    CString a("Big");
    CString b("Bang");
    CString d("Theory");
    CString f("some");
    CVector<CString> vec;
    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);
    vec.push_back(f);
    unsigned res = vec.resize(3);
    ASSERT_EQ(res, vec.size());

    res = vec.resize(-1);
    unsigned num = 0;
    ASSERT_EQ(num, res);

    res = vec.resize(5);
    ASSERT_EQ(num, res);

    CString g("empty");
    res = vec.resize(5, g);
    ASSERT_EQ(res, vec.size());
}

TEST(test033, test_CVector_push_front)
{
    CString a("Big");
    CString b("Bang");
    CString d("Theory");
    CString f("some");
    CVector<CString> vec;
    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);
    vec.push_back(f);
    CString g("New");
    vec.push_front(g);

    const char *res[5] = {"New", "Big", "Bang", "Theory", "some"};
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        ASSERT_EQ(*res[i], *vec.at(i).data());
        //cout << vec.at(i).data() <<endl;
    }
    //cout << "//-------------------------//" <<endl;
}

TEST(test034, test_CVector_empty)
{
    CVector<CString> vec;
    bool res;
    res = vec.is_empty();
    ASSERT_TRUE(res);

    CString b = "dhdhdh";
    vec.push_back(b);
    res = vec.is_empty();
    ASSERT_FALSE(res);
}

TEST(test035, test_CVector_at)
{
    CString a("Big");
    CString b("Bang");
    CString d("Theory");
    CString f("New");
    CString g("Funny");
    CVector<CString> vec;
    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);
    vec.push_back(f);
    vec.push_back(g);

    CString h = vec.at(1);
    ASSERT_TRUE(b == h);

    CString j;
    CString k = vec.at(-10);
    ASSERT_TRUE(k == j);

    CString l = vec.at(100);
    ASSERT_TRUE(l == j);

    vec.at(2) = g;
    ASSERT_TRUE(vec.at(2) == g);
     const char *res[5] = {"Big", "Bang", "Funny", "New", "Funny"};
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        ASSERT_EQ(*res[i], *vec.at(i).data());
        //cout << vec.at(i).data() <<endl;
    }
    //cout << "//-------------------------//" <<endl;
}

TEST(test036, test_CVector_front_and_back)
{
    CString a("Big");
    CString b("Bang");
    CString d("Theory");
    CString f("New");
    CString g("Funny");
    CVector<CString> vec;
    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);
    vec.push_back(f);
    vec.push_back(g);

    CString e = vec.front();
    ASSERT_TRUE(e == a);
    CString h = vec.back();
    ASSERT_TRUE(h == g);

    CVector<CString> vec1;
    CString j;
    CString k = vec1.front();
    ASSERT_TRUE(k == j);

    CString p = vec1.back();
    ASSERT_TRUE(p == j);
}

TEST(test037, test_CVector_pop_front_and_back)
{
    CString a("Big");
    CString b("Bang");
    CString d("Theory");
    CString f("New");
    CString g("Funny");
    CVector<CString> vec;
    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);
    vec.push_back(f);
    vec.push_back(g);

    const char *res[5] = {"Big", "Bang", "Theory", "New", "Funny"};
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        ASSERT_EQ(*res[i], *vec.at(i).data());
        //cout << vec.at(i).data() <<endl;
    }
    //cout << "//-------------------------//" <<endl;

    vec.pop_front();
    const char *res1[4] = {"Bang", "Theory", "New", "Funny"};
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        ASSERT_EQ(*res1[i], *vec.at(i).data());
        //cout << vec.at(i).data() <<endl;
    }
    //cout << "//-------------------------//" <<endl;

    vec.pop_back();
    const char *res2[3] = {"Bang", "Theory", "New"};
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        ASSERT_EQ(*res2[i], *vec.at(i).data());
        //cout << vec.at(i).data() <<endl;
    }
    //cout << "//-------------------------//" <<endl;
}

TEST(test038, test_CVector_erase)
{
        CString a("Big");
        CString b("Bang");
        CString d("Theory");
        CString f("New");
        CString g("Funny");
        CString k("Happy");
        CVector<CString> vec;
        vec.push_back(a);
        vec.push_back(b);
        vec.push_back(d);
        vec.push_back(f);
        vec.push_back(g);
        vec.push_back(k);
        vec.erase1(2);

        const char *res[5] = {"Big", "Bang", "New", "Funny", "Happy"};
        for(unsigned  i = 0; i < vec.size(); i++)
        {
            ASSERT_EQ(*res[i], *vec.at(i).data());
            //cout << vec.at(i).data() <<endl;
        }
        //cout << "//-------------------------//" <<endl;
}
TEST(test039, test_CVector_erase)
{
    CString a("Big");
    CString b("Bang");
    CString d("Theory");
    CString f("New");
    CString g("Funny");
    CString k("Happy");
    CVector<CString> vec;
    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);
    vec.push_back(f);
    vec.push_back(g);
    vec.push_back(k);
    vec.erase(0, 5);

    const char *res = "\0";
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        ASSERT_EQ(*res, *vec.at(i).data());
        //cout << vec.at(i).data() <<endl;
    }
    //cout << "//-------------------------//" <<endl;

    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);
    vec.push_back(f);
    vec.push_back(g);
    vec.push_back(k);
    vec.erase(0, 4);

    res = "Happy";
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        ASSERT_EQ(*res, *vec.at(i).data());
        //cout << vec.at(i).data() <<endl;
    }
    //cout << "//-------------------------//" <<endl;
    vec.clear();

    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);
    vec.push_back(f);
    vec.push_back(g);
    vec.push_back(k);
    vec.erase(1, 5);

    res = "Big";
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        ASSERT_EQ(*res, *vec.at(i).data());
        //cout << vec.at(i).data() <<endl;
    }
    //cout << "//-------------------------//" <<endl;
    vec.clear();

    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);
    vec.push_back(f);
    vec.push_back(g);
    vec.push_back(k);
    vec.erase(2, 4);

    const char *res1[3] = {"Big", "Bang", "Happy"};
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        ASSERT_EQ(*res1[i], *vec.at(i).data());
        //cout << vec.at(i).data() <<endl;
    }
    //cout << "//-------------------------//" <<endl;
    vec.clear();

    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);
    vec.push_back(f);
    vec.push_back(g);
    vec.push_back(k);
    vec.erase(0, 5, '(', ')');

    const char *res2[2] = {"Big", "Happy"};
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        ASSERT_EQ(*res2[i], *vec.at(i).data());
        //cout << vec.at(i).data() <<endl;
    }
    //cout << "//-------------------------//" <<endl;
    vec.clear();

    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);
    vec.push_back(f);
    vec.push_back(g);
    vec.push_back(k);
    vec.erase(0, 3, '(', ')');

    const char *res3[4] = {"Big", "New", "Funny", "Happy"};
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        ASSERT_EQ(*res3[i], *vec.at(i).data());
        //cout << vec.at(i).data() <<endl;
    }
    //cout << "//-------------------------//" <<endl;
    vec.clear();

    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);
    vec.push_back(f);
    vec.push_back(g);
    vec.push_back(k);
    vec.erase(2, 5, '(', ')');

    const char *res4[4] = {"Big", "Bang", "Theory", "Happy"};
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        ASSERT_EQ(*res4[i], *vec.at(i).data());
        //cout << vec.at(i).data() <<endl;
    }
    //cout << "//-------------------------//" <<endl;
    vec.clear();

    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);
    vec.push_back(f);
    vec.push_back(g);
    vec.push_back(k);
    vec.erase(2, 4, '(', ')');

    const char *res5[5] = {"Big", "Bang", "Theory", "Funny", "Happy"};
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        ASSERT_EQ(*res5[i], *vec.at(i).data());
        //cout << vec.at(i).data() <<endl;
    }
    //cout << "//-------------------------//" <<endl;
    vec.clear();

    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);
    vec.push_back(f);
    vec.push_back(g);
    vec.push_back(k);
    vec.erase(0, 5, '[', ')');

    res = "Happy";
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        ASSERT_EQ(*res, *vec.at(i).data());
        //cout << vec.at(i).data() <<endl;
    }
    //cout << "//-------------------------//" <<endl;
    vec.clear();

    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);
    vec.push_back(f);
    vec.push_back(g);
    vec.push_back(k);
    vec.erase(0, 3, '[', ')');

    const char *res6[3] = {"New", "Funny", "Happy"};
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        ASSERT_EQ(*res6[i], *vec.at(i).data());
        //cout << vec.at(i).data() <<endl;
    }
    //cout << "//-------------------------//" <<endl;
    vec.clear();

    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);
    vec.push_back(f);
    vec.push_back(g);
    vec.push_back(k);
    vec.erase(2, 5, '[', ')');

    const char *res7[3] = {"Big", "Bang", "Happy"};
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        ASSERT_EQ(*res7[i], *vec.at(i).data());
        //cout << vec.at(i).data() <<endl;
    }
    //cout << "//-------------------------//" <<endl;
    vec.clear();

    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);
    vec.push_back(f);
    vec.push_back(g);
    vec.push_back(k);
    vec.erase(2, 4, '[', ')');

    const char *res8[4] = {"Big", "Bang", "Funny", "Happy"};
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        ASSERT_EQ(*res8[i], *vec.at(i).data());
        //cout << vec.at(i).data() <<endl;
    }
    //cout << "//-------------------------//" <<endl;
    vec.clear();

    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);
    vec.push_back(f);
    vec.push_back(g);
    vec.push_back(k);
    vec.erase(0, 5, '(', ']');

    res = {"Big"};
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        ASSERT_EQ(*res, *vec.at(i).data());
        //cout << vec.at(i).data() <<endl;
    }
    //cout << "//-------------------------//" <<endl;
    vec.clear();

    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);
    vec.push_back(f);
    vec.push_back(g);
    vec.push_back(k);
    vec.erase(0, 2, '(', ']');

    const char *res9[4] = {"Big", "New", "Funny", "Happy"};
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        ASSERT_EQ(*res9[i], *vec.at(i).data());
        //cout << vec.at(i).data() <<endl;
    }
    //cout << "//-------------------------//" <<endl;
    vec.clear();

    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);
    vec.push_back(f);
    vec.push_back(g);
    vec.push_back(k);
    vec.erase(2, 5, '(', ']');

    const char *res10[4] = {"Big", "Bang", "Theory"};
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        ASSERT_EQ(*res10[i], *vec.at(i).data());
        //cout << vec.at(i).data() <<endl;
    }
    //cout << "//-------------------------//" <<endl;
    vec.clear();

    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);
    vec.push_back(f);
    vec.push_back(g);
    vec.push_back(k);
    vec.erase(2, 4, '(', ']');

    const char *res11[4] = {"Big", "Bang", "Theory", "Happy"};
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        ASSERT_EQ(*res11[i], *vec.at(i).data());
        //cout << vec.at(i).data() <<endl;
    }
    //cout << "//-------------------------//" <<endl;
    vec.clear();
}

TEST(test040, test_CVector_find_rfind)
{
    CString a("Big");
    CString b("Bang");
    CString d("Theory");
    CString f("New");
    CString g("Funny");
    CVector<CString> vec;
    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);
    vec.push_back(f);
    vec.push_back(g);
    CString h("Theory");
    unsigned res  = vec.find(h);
    unsigned res1 = 2;
    ASSERT_EQ(res1, res);

    res = vec.rfind(h);
    ASSERT_EQ(res1, res);

    CString l("Net");
    res = vec.find(l);
    res1 = 0;
    ASSERT_EQ(res1, res);
}

TEST(test041, test_CVector_sorting)
{
    CString a("Big");
    CString b("Bang");
    CString d("Theory");
    CString f("New");
    CString g("Funny");
    CVector<CString> vec;
    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);
    vec.push_back(f);
    vec.push_back(g);
    vec.sorting(1);

    const char *res[5] = {"Bang", "Big", "Funny", "New", "Theory"};
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        ASSERT_EQ(*res[i], *vec.at(i).data());
        //cout << vec.at(i).data() <<endl;
    }
    //cout << "//-------------------------//" <<endl;
    vec.clear();

    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);
    vec.push_back(f);
    vec.push_back(g);
    vec.sorting(2);
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        ASSERT_EQ(*res[i], *vec.at(i).data());
        //cout << vec.at(i).data() <<endl;
    }
    //cout << "//-------------------------//" <<endl;

}

TEST(test042, test_CVector_operator_equal)
{
    CString a("Big");
    CString b("Bang");
    CString d("Theory");
    CString f("New");
    CString g("Funny");
    CVector<CString> vec;
    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);
    vec.push_back(f);
    vec.push_back(g);
    CVector<CString> vec1;
    vec1 = vec;

    const char *res[5] = {"Big", "Bang", "Theory", "New", "Funny"};
    for(unsigned  i = 0; i < vec1.size(); i++)
    {
        ASSERT_EQ(*res[i], *vec1.at(i).data());
        //cout << vec1.at(i).data() <<endl;
    }
    //cout << "//-------------------------//" <<endl;
    vec1.clear();

}

TEST(test043, test_CVector_operator_plus_and_eq)
{
    CString a("Big");
    CString b("Bang");
    CVector<CString> vec;
    vec.push_back(a);
    vec.push_back(b);

    CString d("Theory");
    CString f("New");
    CVector<CString> vec1;
    vec1.push_back(d);
    vec1.push_back(f);
    vec += vec1;

    const char *res[4] = {"Big", "Bang", "Theory", "New"};
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        ASSERT_EQ(*res[i], *vec.at(i).data());
        //cout << vec.at(i).data() <<endl;
    }
    //cout << "//-------------------------//" <<endl;

    CString g("Funny");
    vec += g;

    const char *res1[5] = {"Big", "Bang", "Theory", "New", "Funny"};
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        ASSERT_EQ(*res1[i], *vec.at(i).data());
        //cout << vec.at(i).data() <<endl;
    }
    //cout << "//-------------------------//" <<endl;
}

TEST(test044, test_CVector_operator_plus)
{
    CString a("Big");
    CString b("Bang");
    CString d("Theory");
    CVector<CString> vec;
    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);

    CString f("New");
    CString g("Funny");
    CVector<CString> vec2;
    vec2.push_back(f);
    vec2.push_back(g);

    vec2 + vec;
    const char *res[5] = { "New", "Funny", "Big", "Bang", "Theory"};
    for(unsigned  i = 0; i < vec2.size(); i++)
    {
        ASSERT_EQ(*res[i], *vec2.at(i).data());
        //cout << vec2.at(i).data() <<endl;
    }
    //cout << "//-------------------------//" <<endl;

    CString k("Crazy");
    vec2 + k;
    const char *res1[6] = {"New", "Funny", "Big", "Bang", "Theory", "Crazy"};
    for(unsigned  i = 0; i < vec2.size(); i++)
    {
        ASSERT_EQ(*res1[i], *vec2.at(i).data());
        //cout << vec2.at(i).data() <<endl;
    }
    //cout << "//-------------------------//" <<endl;
}

TEST(test045, test_CVector_operator_square_bracket)
{
    CString a("Big");
    CString b("Bang");
    CString d("Theory");
    CString f("New");
    CString g("Funny");
    CVector<CString> vec;
    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);
    vec.push_back(f);
    vec.push_back(g);

    CString h = vec[1];
    ASSERT_TRUE(b == h);

    vec[2] = g;
    ASSERT_TRUE(vec[2] == g);

    const char *res[5] = {"Big", "Bang", "Funny", "New", "Funny"};
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        ASSERT_EQ(*res[i], *vec.at(i).data());
        //cout << vec.at(i).data() <<endl;
    }
    //cout << "//-------------------------//" <<endl;
}

TEST(test046, test_CVector_operator_equal_unequal)
{
    CString a("Big");
    CString b("Bang");
    CString d("Theory");
    CVector<CString> vec;
    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);
    CVector<CString> vec1;
    vec1.push_back(a);
    vec1.push_back(b);
    vec1.push_back(d);
    bool res = (vec == vec1);
    ASSERT_TRUE(res);

    CString h("Big");
    CString l("Bang");
    CString m("Thiory");
    CVector<CString> vec2;
    vec2.push_back(h);
    vec2.push_back(l);
    vec2.push_back(m);
    res = (vec == vec2);
    ASSERT_FALSE(res);
    res = (vec != vec2);
    ASSERT_TRUE(res);

    CString j("Big");
    CString p("Bang");
    CString i("Thiory");
    CVector<CString> vec3;
    vec3.push_back(j);
    vec3.push_back(p);
    vec3.push_back(i);
    res = (vec3 != vec2);
    ASSERT_FALSE(res);
}

TEST(test047, test_CVector_operator_less_or_eq)
{
    CString a("Big");
    CString b("Bang");
    CString d("Theory");
    CVector<CString> vec;
    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);

    CVector<CString> vec1;
    vec1.push_back(a);
    vec1.push_back(b);
    bool res = (vec1 <= vec);
    ASSERT_TRUE(res);

    CVector<CString> vec2;
    vec2.push_back(a);
    vec2.push_back(b);
    vec2.push_back(d);
    res = (vec2 <= vec);
    ASSERT_TRUE(res);

    CString f("New");
    CVector<CString> vec3;
    vec3.push_back(a);
    vec3.push_back(b);
    vec3.push_back(d);
    vec3.push_back(f);
    res = (vec3 <= vec);
    ASSERT_FALSE(res);
}

TEST(test046, test_CVector_operator_more_or_eq)
{
    CString a("Big");
    CString b("Bang");
    CString d("Theory");
    CVector<CString> vec;
    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);

    CVector<CString> vec1;
    vec1.push_back(a);
    vec1.push_back(b);
    bool res = (vec >= vec1);
    ASSERT_TRUE(res);

    CVector<CString> vec2;
    vec2.push_back(a);
    vec2.push_back(b);
    vec2.push_back(d);
    res = (vec >= vec2);
    ASSERT_TRUE(res);

    CString f("New");
    CVector<CString> vec3;
    vec3.push_back(a);
    vec3.push_back(b);
    vec3.push_back(d);
    vec3.push_back(f);
    res = (vec >= vec3);
    ASSERT_FALSE(res);
}

TEST(test047, test_CVector_operator_less)
{
    CString a("Big");
    CString b("Bang");
    CVector<CString> vec;
    vec.push_back(a);
    vec.push_back(b);


    CString d("Theory");
    CVector<CString> vec1;
    vec1.push_back(a);
    vec1.push_back(b);
    vec1.push_back(d);
    bool res = (vec < vec1);
    ASSERT_TRUE(res);
    res = (vec1 < vec);
    ASSERT_FALSE(res);

    CString h("Theorz");
    CVector<CString> vec2;
    vec2.push_back(a);
    vec2.push_back(b);
    vec2.push_back(h);
    res = (vec1 < vec2);
    ASSERT_TRUE(res);
}

TEST(test048, test_CVector_operator_more)
{
    CString a("Big");
    CString b("Bang");
    CVector<CString> vec;
    vec.push_back(a);
    vec.push_back(b);


    CString d("Theory");
    CVector<CString> vec1;
    vec1.push_back(a);
    vec1.push_back(b);
    vec1.push_back(d);

    bool res = (vec1 > vec);
    ASSERT_TRUE(res);
    res = (vec > vec1);
    ASSERT_FALSE(res);

    CString h("Theorz");
    CVector<CString> vec2;
    vec2.push_back(a);
    vec2.push_back(b);
    vec2.push_back(h);
    res = (vec2 > vec1);
    ASSERT_TRUE(res);
}

#endif // CVECTOR_TEST_H
