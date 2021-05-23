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

        for(unsigned  i = 0; i < vec.size(); i++)
        {
            cout << vec.at(i).data() <<endl;
        }
        cout << "//-------------------------//" <<endl;
        CVector<bool> vec_bool;
        vec_bool.push_back(true);
        vec_bool.push_back(true);
        vec_bool.push_back(true);
        vec_bool.push_back(false);
        vec_bool.push_back(true);
        vec_bool.push_back(false);

        for(unsigned  i = 0; i < vec_bool.size(); i++)
        {
            cout << vec_bool.at(i) <<endl;
        }
        cout << "//-------------------------//" <<endl;
        CVector<int> vec_int;
        vec_int.push_back(1);
        vec_int.push_back(2);
        vec_int.push_back(3);
        vec_int.push_back(4);
        vec_int.push_back(5);
        vec_int.push_back(6);

        for(unsigned  i = 0; i < vec_int.size(); i++)
        {
            cout << vec_int.at(i) <<endl;
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
    vec.resize(3);
    vec.resize(3);
    vec.resize(-1);
    vec.resize(5);
    CString g("empty");
    vec.resize(5, g);
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
}

TEST(test034, test_CVector_empty)
{
    CVector<CString> vec;
    bool res;
    res = vec.is_empty();
    ASSERT_EQ(1, res);

    CString b = "dhdhdh";
    vec.push_back(b);
    res = vec.is_empty();
    ASSERT_EQ(0, res);
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
    vec.at(-10);
    vec.at(100);

    vec.at(2) = g;
    ASSERT_TRUE(vec.at(2) == g);
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i).data() <<endl;
    }
    cout << "//-------------------------//" <<endl;
}

TEST(test035, test_CVector_front_and_back)
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
    vec1.front();
    vec1.back();
    cout << "//-------------------------//" <<endl;
}

TEST(test036, test_CVector_pop_front_and_back)
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
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i).data() <<endl;
    }
    cout << "//-------------------------//" <<endl;
    vec.pop_front();
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i).data() <<endl;
    }
    cout << "//-------------------------//" <<endl;
    vec.pop_back();
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i).data() <<endl;
    }
    cout << "//-------------------------//" <<endl;
}

TEST(test037, test_CVector_erase)
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
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i).data() <<endl;
    }
    cout << "//-------------------------//" <<endl;

    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);
    vec.push_back(f);
    vec.push_back(g);
    vec.push_back(k);
    vec.erase(0, 4);
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i).data() <<endl;
    }
    cout << "//-------------------------//" <<endl;
    vec.clear();

    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);
    vec.push_back(f);
    vec.push_back(g);
    vec.push_back(k);
    vec.erase(1, 5);
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i).data() <<endl;
    }
    cout << "//-------------------------//" <<endl;
    vec.clear();

    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);
    vec.push_back(f);
    vec.push_back(g);
    vec.push_back(k);
    vec.erase(2, 4);
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i).data() <<endl;
    }
    cout << "//-------------------------//" <<endl;
    vec.clear();

    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);
    vec.push_back(f);
    vec.push_back(g);
    vec.push_back(k);
    vec.erase(0, 5, '(', ')');
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i).data() <<endl;
    }
    cout << "//-------------------------//" <<endl;
    vec.clear();

    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);
    vec.push_back(f);
    vec.push_back(g);
    vec.push_back(k);
    vec.erase(0, 3, '(', ')');
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i).data() <<endl;
    }
    cout << "//-------------------------//" <<endl;
    vec.clear();

    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);
    vec.push_back(f);
    vec.push_back(g);
    vec.push_back(k);
    vec.erase(2, 5, '(', ')');
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i).data() <<endl;
    }
    cout << "//-------------------------//" <<endl;
    vec.clear();

    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);
    vec.push_back(f);
    vec.push_back(g);
    vec.push_back(k);
    vec.erase(2, 4, '(', ')');
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i).data() <<endl;
    }
    cout << "//-------------------------//" <<endl;
    vec.clear();

    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);
    vec.push_back(f);
    vec.push_back(g);
    vec.push_back(k);
    vec.erase(0, 5, '[', ')');
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i).data() <<endl;
    }
    cout << "//-------------------------//" <<endl;
    vec.clear();

    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);
    vec.push_back(f);
    vec.push_back(g);
    vec.push_back(k);
    vec.erase(0, 3, '[', ')');
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i).data() <<endl;
    }
    cout << "//-------------------------//" <<endl;
    vec.clear();

    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);
    vec.push_back(f);
    vec.push_back(g);
    vec.push_back(k);
    vec.erase(2, 5, '[', ')');
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i).data() <<endl;
    }
    cout << "//-------------------------//" <<endl;
    vec.clear();

    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);
    vec.push_back(f);
    vec.push_back(g);
    vec.push_back(k);
    vec.erase(2, 4, '[', ')');
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i).data() <<endl;
    }
    cout << "//-------------------------//" <<endl;
    vec.clear();

    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);
    vec.push_back(f);
    vec.push_back(g);
    vec.push_back(k);
    vec.erase(0, 5, '(', ']');
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i).data() <<endl;
    }
    cout << "//-------------------------//" <<endl;
    vec.clear();

    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);
    vec.push_back(f);
    vec.push_back(g);
    vec.push_back(k);
    vec.erase(0, 2, '(', ']');
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i).data() <<endl;
    }
    cout << "//-------------------------//" <<endl;
    vec.clear();

    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);
    vec.push_back(f);
    vec.push_back(g);
    vec.push_back(k);
    vec.erase(2, 5, '(', ']');
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i).data() <<endl;
    }
    cout << "//-------------------------//" <<endl;
    vec.clear();

    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);
    vec.push_back(f);
    vec.push_back(g);
    vec.push_back(k);
    vec.erase(2, 4, '(', ']');
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i).data() <<endl;
    }
    cout << "//-------------------------//" <<endl;
    vec.clear();
}

TEST(test038, test_CVector_find_rfind)
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
    ASSERT_EQ(res, res1);
    res = vec.rfind(h);
    ASSERT_EQ(res1, res);

    CString l("Net");
    vec.find(l);
}

TEST(test039, test_CVector_sorting)
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
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i).data() <<endl;
    }
    cout << "//-------------------------//" <<endl;
    vec.clear();

    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);
    vec.push_back(f);
    vec.push_back(g);
    vec.sorting(2);
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i).data() <<endl;
    }
    cout << "//-------------------------//" <<endl;

}

TEST(test040, test_CVector_operator_equal)
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
    for(unsigned  i = 0; i < vec1.size(); i++)
    {
        cout << vec1.at(i).data() <<endl;
    }
    cout << "//-------------------------//" <<endl;
    vec1.clear();

}

TEST(test041, test_CVector_operator_plus_and_eq)
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
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i).data() <<endl;
    }
    cout << "//-------------------------//" <<endl;

    CString g("Funny");
    vec += g;
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i).data() <<endl;
    }
    cout << "//-------------------------//" <<endl;
}

TEST(test042, test_CVector_operator_plus)
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
    for(unsigned  i = 0; i < vec2.size(); i++)
    {
        cout << vec2.at(i).data() <<endl;
    }
    cout << "//-------------------------//" <<endl;

    CString k("Crazy");
    vec2 + k;
    for(unsigned  i = 0; i < vec2.size(); i++)
    {
        cout << vec2.at(i).data() <<endl;
    }
    cout << "//-------------------------//" <<endl;
}

TEST(test043, test_CVector_operator_square_bracket)
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
    vec[-10];
    vec[100];

    vec[2] = g;
    ASSERT_TRUE(vec[2] == g);
    for(unsigned  i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i).data() <<endl;
    }
    cout << "//-------------------------//" <<endl;
}

TEST(test044, test_CVector_operator_equal_unequal)
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
    ASSERT_EQ(1, res);

    CString h("Big");
    CString l("Bang");
    CString m("Thiory");
    CVector<CString> vec2;
    vec2.push_back(h);
    vec2.push_back(l);
    vec2.push_back(m);
    res = (vec == vec2);
    ASSERT_EQ(0, res);
    res = (vec != vec2);
    ASSERT_EQ(1, res);

    CString j("Big");
    CString p("Bang");
    CString i("Thiory");
    CVector<CString> vec3;
    vec3.push_back(j);
    vec3.push_back(p);
    vec3.push_back(i);
    res = (vec3 != vec2);
    ASSERT_EQ(0, res);
}

TEST(test045, test_CVector_operator_less_or_eq)
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
    ASSERT_EQ(1, res);

    CVector<CString> vec2;
    vec2.push_back(a);
    vec2.push_back(b);
    vec2.push_back(d);
    res = (vec2 <= vec);
    ASSERT_EQ(1, res);

    CString f("New");
    CVector<CString> vec3;
    vec3.push_back(a);
    vec3.push_back(b);
    vec3.push_back(d);
    vec3.push_back(f);
    res = (vec3 <= vec);
    ASSERT_EQ(0, res);
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
    ASSERT_EQ(1, res);

    CVector<CString> vec2;
    vec2.push_back(a);
    vec2.push_back(b);
    vec2.push_back(d);
    res = (vec >= vec1);
    ASSERT_EQ(1, res);

    CString f("New");
    CVector<CString> vec3;
    vec3.push_back(a);
    vec3.push_back(b);
    vec3.push_back(d);
    vec3.push_back(f);
    res = (vec >= vec3);
    ASSERT_EQ(0, res);
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
    ASSERT_EQ(1, res);
    res = (vec1 < vec);
    ASSERT_EQ(0, res);

    CString h("Theorz");
    CVector<CString> vec2;
    vec2.push_back(a);
    vec2.push_back(b);
    vec2.push_back(h);
    res = (vec1 < vec2);
    ASSERT_EQ(1, res);
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
    ASSERT_EQ(1, res);
    res = (vec > vec1);
    ASSERT_EQ(0, res);

    CString h("Theorz");
    CVector<CString> vec2;
    vec2.push_back(a);
    vec2.push_back(b);
    vec2.push_back(h);
    res = (vec2 > vec1);
    ASSERT_EQ(1, res);
}

#endif // CVECTOR_TEST_H
