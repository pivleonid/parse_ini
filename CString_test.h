#ifndef CSTRING_TEST_H
#define CSTRING_TEST_H
#include "CString.h"
#include <gtest/include/gtest/gtest.h>
TEST(test001, test_at)
{
    CString a = "something";
    char b = a.at(4);
    ASSERT_EQ('t', b);
    char c = a.at(100);
    ASSERT_EQ('\0', c);
    char d = a.at(-10);
    ASSERT_EQ('\0', d);
    a.at(5) = 'z';
    char e = a.at(5);
    ASSERT_EQ('z', e);
    a.at(90) = 'x';
    char f = a.at(90);
    ASSERT_EQ('\0', f);
    a.at(-1) = 'r';
    char g = a.at(-1);
    ASSERT_EQ('\0', g);
}

TEST(test002, test_front)
{
    CString a = "Nicki";
    char b = a.front();
    ASSERT_EQ('N', b);
}

TEST(test003, test_back)
{
    CString a = "Big_Bossik";
    char b = a.back();
    ASSERT_EQ('k', b);
}

TEST(test004, test_empty)
{
    CString a;
    bool res;
    res = a.empty();
    ASSERT_EQ(1, res);
    CString b = "dhdhdh";
    res = b.empty();
    ASSERT_EQ(0, res);
    CString c = 'f';
    res = c.empty();
    ASSERT_EQ(0, res);
    CString d = "\0";
    res = d.empty();
    ASSERT_EQ(1, res);
}

TEST(test005, test_erase)
{
    CString a("Hello World Ha-Ha!");
    a.erase(6, 10);
    CString b("Hello  Ha-Ha!");
    ASSERT_TRUE(b == a);
    CString c("Hello World Ha-Ha!");
    ASSERT_FALSE(c == a);
    c.erase(-20, 3);
    c.erase(0, 50);
}

TEST(test006, test_erase)
{
    CString a("Something new");
    a.erase('g');
    CString b("Somethin new");
    ASSERT_TRUE(b == a);
    CString c("Something new");
    ASSERT_FALSE(c == a);
    a.erase('y');
    c.erase('n');
    CString e("Somethig ew");
    ASSERT_TRUE(e == c);
}

TEST(test007, test_push_back)
{
    CString a("Something new");
    a.push_back('!');
    CString b("Something new!");
    ASSERT_TRUE(b == a);
}

TEST(test008, test_push_back)
{
    CString a("Brave new ");
    a.push_back("World!");
    CString b("Brave new World!");
    ASSERT_TRUE(b == a);
}

TEST(test009, test_pop_back)
{
    CString a("Good luck!");
    a.pop_back();
    CString b("Good luck");
    ASSERT_TRUE(b == a);
}

TEST(test010, test_compare)
{
    CString a("Crazy");
    CString b("Crazy");
    bool res = a.compare(b);
    ASSERT_TRUE(res);
    CString c("Crazi");
    res = a.compare(c);
    ASSERT_FALSE(res);
}

TEST(test011, test_find)
{
    CString a("Lucky Strike!");
    int num = a.find('S');
    ASSERT_EQ(6, num);
    num = a.find('G');
    ASSERT_EQ(0, num);
    num = a.find('k');
    ASSERT_EQ(3, num);
}

TEST(test012, test_find)
{
    CString a("Hell Yeah!");
    CString b("Yeah!");
    int num = a.find(b);
    ASSERT_EQ(5, num);
    CString c("G");
    num = a.find(c);
    ASSERT_EQ(0, num);
    CString d("Hell Yeah! Yezh! Yeah! Yeah!");
    CString e("Yeah!");
    num = d.find(e);
    ASSERT_EQ(5, num);
    CString f("Yezh!");
    num = a.find(a);
    ASSERT_EQ(0, num);
}

TEST(test013, test_rfind)
{
    CString a("Big Bang Theory!");
    int num = a.rfind('i');
    ASSERT_EQ(1, num);
    num = a.rfind('u');
    ASSERT_EQ(0, num);
    num = a.rfind('B');
    ASSERT_EQ(4, num);
}

TEST(test014, test_rfind)
{
    CString a("Il buono, il brutto, il cattivo");
    int num = a.rfind("brutto");
    ASSERT_EQ(18, num);
    num = a.rfind("hz");
    ASSERT_EQ(0, num);
    num = a.rfind("il");
    ASSERT_EQ(22, num);
}

TEST(test015, test_operator_plus)
{
    CString a = "Funny";
    a += " day";
    CString b = "Funny day";
    ASSERT_TRUE(b == a);
    a += '!';
    b = "Funny day!";
    ASSERT_TRUE(b == a);
    const char *c = " again";
    a += c;
    b = "Funny day! again";
    ASSERT_TRUE(b == a);
    CString d = "H";
    CString e = "appy";
    CString f = d + e;
    CString g("Happy");
    ASSERT_TRUE(g == f);

}

TEST(test016, test_operator_equal)
{
    CString a("MoDern");
    CString b("MoBern");
    int res = (a != b);
    ASSERT_EQ(1, res);
    CString c("MoDern");
    res = (a == c);
    ASSERT_EQ(1, res);
}

TEST(test017, test_operator_unequal)
{
    CString a("Big");
    CString b("Bigger");
    int res = (b >= a);
    ASSERT_EQ(1, res);
    res = (a <= b);
    ASSERT_EQ(1, res);
    CString c("Bigger");
    res = (b >= c);
    ASSERT_EQ(1, res);
}

TEST(test018, test_operator_stoi)
{
    CString a = "1234";
    int res = a.stoi();
    ASSERT_TRUE(1234 == res);
    a = "123,6";
    res = a.stoi();
    ASSERT_EQ(0, res);
    a = "123ddg6";
    res = a.stoi();
    ASSERT_EQ(0, res);
    a = "01236";
    res = a.stoi();
    ASSERT_EQ(0, res);
}

TEST(test019, test_operator_stof)
{
    CString a = "123,4";
    double res = a.stof();
    ASSERT_TRUE(123.4 == res);
    a = "12.3,4";
    res = a.stof();
    ASSERT_TRUE(0 == res);
    a = "a123,4";
    res = a.stof();
    ASSERT_TRUE(0 == res);
    a = "1234";
    res = a.stof();
    ASSERT_TRUE(0 == res);
}

TEST(test020, test_operator_stoi_str)
{
    CString a;
    CString b = "12345";
    double res = a.stoi(b);
    ASSERT_TRUE(12345 == res);
    b = "123,6";
    res = a.stoi(b);
    ASSERT_EQ(0, res);
    b = "123ddg6";
    res = a.stoi(b);
    ASSERT_EQ(0, res);
    b = "01236";
    res = a.stoi(b);
    ASSERT_EQ(0, res);
}

TEST(test021, test_operator_stof_str)
{
    CString a;
    CString b = "123,45";
    double res = a.stof(b);
    ASSERT_TRUE(123.45 == res);
    b = "12.3,4";
    res = a.stof(b);
    ASSERT_TRUE(0 == res);
    b = "a123,4";
    res = a.stof(b);
    ASSERT_TRUE(0 == res);
    CString c(123456);
    b = "123456";
    ASSERT_TRUE(b == c);
    CString d;
    d = 63674;
    b = "63674";
    ASSERT_TRUE(b == d);
}


#endif // CSTRING_TEST_H
