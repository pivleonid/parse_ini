#ifndef CVECTOR_TEST_H
#define CVECTOR_TEST_H
#include "CString.h"
#include "CVector.h"
#include "CVector.cpp"
#include <gtest/include/gtest/gtest.h>
using namespace std;

TEST(test022, test_operator_to_string)
{
    CString a("Nikita");
    CString b("Sinodov");
    CString d("Andreich");
    CString f("some");
    CVector<CString> vec;
    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(d);
    vec.push_back(f);
    for(int  i = 0; i < vec.size(); i++)
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

    for(int  i = 0; i < vec_bool.size(); i++)
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

    for(int  i = 0; i < vec_int.size(); i++)
    {
        cout << vec_int.at(i) <<endl;
    }

}

TEST(test023, test_CVector_size_resize)
{
    CString a("Nikita");
    CString b("Sinodov");
    CString k("New");
    CString d("Andreich");
    CString f("New");
    CString g("Funny");
    CVector<CString> c;
    CVector<CString> h;
    c.push_back(a);
    c.push_back(b);
    c.push_back(k);
    c.push_back(d);
    c.push_back(f);
    c.push_back(g);
    int  res = c.size();
    ASSERT_EQ(6, res);
    res = h.size();
    ASSERT_EQ(0, res);
    res = c.resize(3);
    ASSERT_EQ(3, res);
    c.resize(-1);
}

TEST(test024, test_CVector_push)
{
    CString a("Nikita");
    CString b("Sinodov");
    CString d("Andreich");
    CString f("New");
    CString g("Funny");
    CVector<CString> c;
    c.push_back(a);
    c.push_back(b);
    c.push_back(d);
    c.push_back(f);
    c.push_front(g);
}

TEST(test025, test_CVector_empty)
{
    CVector<CString> a;
    bool res;
    res = a.is_empty();
    ASSERT_EQ(1, res);
    CString b = "dhdhdh";
    a.push_back(b);
    res = a.is_empty();
    ASSERT_EQ(0, res);
}

TEST(test026, test_CVector_at)
{
    CString a("Nikita");
    CString b("Sinodov");
    CString d("Andreich");
    CString f("New");
    CString g("Funny");
    CString k;
    CVector<CString> c;
    c.push_back(a);
    c.push_back(b);
    c.push_back(d);
    c.push_back(f);
    c.push_back(g);
    CString h = c.at(1);
    ASSERT_TRUE(b == h);
    h = c.at(-10);
    ASSERT_TRUE(k == h);
    h = c.at(100);
    ASSERT_TRUE(k == h);
}

TEST(test027, test_CVector_front_and_back)
{
    CString a("Nikita");
    CString b("Sinodov");
    CString d("Andreich");
    CString j;
    CVector<CString> c;
    CString e = c.front();
    ASSERT_TRUE(e == j);
    e = c.back();
    ASSERT_TRUE(e == j);
    c.push_back(a);
    c.push_back(b);
    c.push_back(d);
    e = c.front();
    ASSERT_TRUE(e == a);
    e = c.back();
    ASSERT_TRUE(e == d);
}

TEST(test028, test_CVector_pop_front_and_pop_back)
{
    CString a("Nikita");
    CString b("Sinodov");
    CString d("Andreich");
    CString f("New");
    CString g("Funny");
    CVector<CString> c;
    c.push_back(a);
    c.push_back(b);
    c.push_back(d);
    c.push_back(f);
    c.push_back(g);
    CString e = c.pop_front();
    ASSERT_TRUE(e == a);
    e = c.pop_back();
    ASSERT_TRUE(e == g);
}

/*TEST(test029, test_CVector_erase)
{
    CString a("Nikita");
    CString b("Sinodov");
    CString d("Andreich");
    CString f("New");
    CString g("Funny");
    CVector<CString> c;
    c.push_back(a);
    c.push_back(b);
    c.push_back(d);
    c.push_back(f);
    c.push_back(g);
    c.erase(-1, 20);
    c.erase(2, -1);
    c.erase(10, 3);
    c.erase(1, 3);
}*/

TEST(test030, test_CVector_find_rfind)
{
    CString a("Nikita");
    CString b("Sinodov");
    CString k("New");
    CString d("Andreich");
    CString f("New");
    CString g("Funny");
    CVector<CString> c;
    c.push_back(a);
    c.push_back(b);
    c.push_back(k);
    c.push_back(d);
    c.push_back(f);
    c.push_back(g);
    CString j = "New";
    int res = c.find(j);
    ASSERT_EQ(2, res);
    res = c.rfind(j);
    ASSERT_EQ(4, res);
}

TEST(test031, test_CVector_operator_equal)
{
    CString a("Nikita");
    CString b("Sinodov");
    CString k("New");
    CString d("Andreich");
    CString f("New");
    CString g("Funny");
    CVector<CString> c;
    c.push_back(a);
    c.push_back(b);
    c.push_back(k);
    c.push_back(d);
    c.push_back(f);
    c.push_back(g);
    CVector<CString> h;
    h = c;
    h.clear();
    h = c;
}

TEST(test032, test_CVector_operator_equal_unequal)
{
    CString a("Nikita");
    CString b("Sinodov");
    CString k("New");
    CVector<CString> c;
    c.push_back(a);
    c.push_back(b);
    c.push_back(k);
    CVector<CString> g;
    g.push_back(a);
    g.push_back(b);
    g.push_back(k);
    bool res = (c == g);
    ASSERT_EQ(1, res);
    CString h("Niketa");
    CString l("Sinodov");
    CString m("New");
    CVector<CString> o;
    o.push_back(h);
    o.push_back(l);
    o.push_back(m);
    res = (c == o);
    ASSERT_EQ(0, res);
    res = (c != o);
    ASSERT_EQ(1, res);
    res = (c != g);
    ASSERT_EQ(0, res);
}

TEST(test033, test_CVector_operator_less_or_eq)
{
    CString a("Nikita");
    CString b("Sinodov");
    CString k("New");
    CVector<CString> c;
    c.push_back(a);
    c.push_back(b);
    c.push_back(k);
    CString h("Nikita");
    CString l("Sinodov");
    CVector<CString> o;
    o.push_back(h);
    o.push_back(l);
    bool res = (o <= c);
    ASSERT_EQ(1, res);
    CString f("Niketa");
    o.clear();
    o.push_back(f);
    o.push_back(l);
    res = (o != c);
    ASSERT_EQ(1, res);
}

TEST(test034, test_CVector_operator_plus)
{
    CString a("Nikita");
    CString b("Sinodov");
    CString k("New");
    CVector<CString> c;
    c.push_back(a);
    c.push_back(b);
    c.push_back(k);
    CVector<CString> f;
    CString d("Andreich");
    CString g("Funny");
    f.push_back(d);
    f.push_back(g);
    CVector<CString> h;
    h = c + f;
    h.clear();
    CString j("Crazy");
    h = f + j;
}

TEST(test035, test_CVector_operator_plus_and_eq)
{
    CString a("Nikita");
    CString b("Sinodov");
    CVector<CString> c;
    c.push_back(a);
    c += b;
    CString d("Andreich");
    CString g("Funny");
    CVector<CString> f;
    f.push_back(d);
    f.push_back(g);
    c += f;
}

/*TEST(test036, test_CVector_sorting)
{
    CString a("Nikita");
    CString b("Sinodov");
    CString k("New");
    CString d("Andreich");
    CString g("Funny");
    CVector<CString> c;
    c.push_back(a);
    c.push_back(b);
    c.push_back(d);
    c.push_back(k);
    c.push_back(g);
    c.sorting();
}*/

#endif // CVECTOR_TEST_H
