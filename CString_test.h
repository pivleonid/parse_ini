#ifndef CSTRING_TEST_H
#define CSTRING_TEST_H
#include "CString.h"
#include <gtest/include/gtest/gtest.h>
TEST(test001, test_CString_Constructor)
{
    CString a;
    CString b('b');
    CString c("some");
    CString d(c);
    CString e(128);
    CString f(0);
}

TEST(test002, test_CString_size)
{
    CString a;
    unsigned res = 1;
    ASSERT_EQ(res, a.size());
    CString b("some");
    res = 5;
    ASSERT_EQ(res, b.size());
}

TEST(test003, test_CString_at)
{
    CString a("some");
    char b = a.at(0);
    ASSERT_EQ('s', b);
    char c = a.at(2);
    ASSERT_EQ('m', c);
    a.at(-1);
    a.at(4);
    a.at(5);
    a.at(2) = 'k';
    CString d("soke");
    ASSERT_TRUE(a == d);
}

TEST(test004, test_CString_front)
{
    CString a = "Nicki";
    char b = a.front();
    ASSERT_EQ('N', b);
}

TEST(test005, test_CString_back)
{
    CString a = "Big_Bossik";
    char b = a.back();
    ASSERT_EQ('k', b);
    CString c;
    c.back();
}

TEST(test006, test_CString_empty)
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

TEST(test007, test_CString_operator_eq)
{
    CString a;
    a = "Worlds";
    a = 'H';
    a = 2558955;
    CString b;
    b = a;
}

TEST(test008, test_CString_empty)
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

TEST(test008, test_CString_erase)
{
    CString a("WORLDS");
    a.erase(0, 5);
    CString res;
    res = "\0";
    ASSERT_TRUE(a == res);

    a = "WORLDS";
    a.erase(0, 3);
    res = "DS";
    ASSERT_TRUE(a == res);

    a = "WORLDS";
    a.erase(2, 5);
    res = "WO";
    ASSERT_TRUE(a == res);

    a = "WORLDS";
    a.erase(2, 4);
    res = "WOS";
    ASSERT_TRUE(a == res);
}

TEST(test008, test_CString_erase1)
{
    CString a("WORLDS");
    a.erase(0, 5, '(', ')');
    CString res;
    res = "WS";
    ASSERT_TRUE(a == res);

    a = "WORLDS";
    a.erase(0, 4,'(', ')');
    res = "WDS";
    ASSERT_TRUE(a == res);

    a = "WORLDS";
    a.erase(1, 5,'(',')');
    res = "WOS";
    ASSERT_TRUE(a == res);

    a = "WORLDS";
    a.erase(1, 4, '(', ')');
    res = "WODS";
    ASSERT_TRUE(a == res);
}

TEST(test009, test_CString_erase2)
{
    CString a;
    a = "WORLDS";
    a.erase(0, 5, '[', ')');
    CString res;
    res = "S";
    ASSERT_TRUE(a == res);

    a = "WORLDS";
    a.erase(0, 4, '[', ')');
    res = "DS";
    ASSERT_TRUE(a == res);

    a = "WORLDS";
    a.erase(1, 5, '[', ')');
    res = "WS";
    ASSERT_TRUE(a == res);

    a = "WORLDS";
    a.erase(1, 4, '[', ')');
    res = "WDS";
    ASSERT_TRUE(a == res);
}

TEST(test010, test_CString_erase3)
{
    CString a;
    a = "WORLDS";
    a.erase(0, 5, '(', ']');
    CString res;
    res = "W";
    ASSERT_TRUE(a == res);

    a = "WORLDS";
    a.erase(0, 4, '(', ']');
    res = "WS";
    ASSERT_TRUE(a == res);

    a = "WORLDS";
    a.erase(1, 5, '(', ']');
    res = "WO";
    ASSERT_TRUE(a == res);

    a = "WORLDS";
    a.erase(1, 4, '(', ']');
    res = "WOS";
    ASSERT_TRUE(a == res);
}

TEST(test011, test_CString_erase_symbol)
{
    CString a("Something new");
    a.erase('g');
    CString b("Somethin new");
    ASSERT_TRUE(b == a);
    CString c("Something new");
    ASSERT_FALSE(c == a);
    c.erase('n');
    CString e("Somethig ew");
    ASSERT_TRUE(e == c);
}

TEST(test012, test_CString_push_front)
{
    CString a("omething new!");
    a.push_front('S');
    CString b("Something new!");
    ASSERT_TRUE(b == a);

    CString c("Year!");
    c.push_front("New ");
    CString d("New Year!");
    ASSERT_TRUE(c == d);

    CString e("Good ");
    CString f("Night!");
    CString g("Good Night!");
    f.push_front(e);
    ASSERT_TRUE(f == g);
}

TEST(test013, test_CString_push_back)
{
    CString a("Something new");
    a.push_back('!');
    CString b("Something new!");
    ASSERT_TRUE(b == a);

    CString c("Brave new ");
    c.push_back("World!");
    CString d("Brave new World!");
    ASSERT_TRUE(c == d);

    CString e("Good ");
    CString f("Night!");
    e.push_back(f);
    CString g("Good Night!");
    ASSERT_TRUE(e == g);
}

TEST(test014, test_CString_pop_front)
{
    CString a("Weather");
    a.pop_front();
    CString b("eather");
    ASSERT_TRUE(a == b);
}

TEST(test015, test_CString_pop_back)
{
    CString a("Good luck!");
    a.pop_back();
    CString b("Good luck");
    ASSERT_TRUE(b == a);
}

TEST(test016, test_CString_compare)
{
    CString a("Crazy");
    CString b("Crazy");
    bool res = a.compare(b);
    ASSERT_TRUE(res);
    CString c("Crazi");
    res = a.compare(c);
    ASSERT_FALSE(res);
}

TEST(test017, test_CString_find)
{
    CString a("Lucky Strike!");
    int num = a.find('S');
    ASSERT_EQ(6, num);
    num = a.find('G');
    ASSERT_EQ(0, num);
    num = a.find('k');
    ASSERT_EQ(3, num);

    CString b("Hell Yeah!");
    CString c("Yeah!");
    num = b.find(c);
    ASSERT_EQ(5, num);

    CString d("G");
    num = b.find(d);
    ASSERT_EQ(0, num);

    CString e("Hell Yeah! Yezh! Yeah! Yeah!");
    CString f("Yeah!");
    num = e.find(f);
    ASSERT_EQ(5, num);

    CString g("Yezh!");
    num = e.find(g);
    ASSERT_EQ(11, num);
}

TEST(test018, test_CString_rfind)
{
    CString a("Big Bang Theory!");
    int num = a.rfind('i');
    ASSERT_EQ(1, num);
    num = a.rfind('u');
    ASSERT_EQ(0, num);
    num = a.rfind('B');
    ASSERT_EQ(4, num);

    CString b("Il buono, il brutto, il cattivo");
    num = b.rfind("brutto");
    ASSERT_EQ(18, num);
    num = b.rfind("hz");
    ASSERT_EQ(0, num);
    num = b.rfind("il");
    ASSERT_EQ(22, num);

}

TEST(test019, test_CString_rfind)
{
 }

TEST(test020, test_CString_stoi)
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

    CString b;
    CString c = "12345";
    res = b.stoi(c);
    ASSERT_TRUE(12345 == res);

    c = "123,6";
    res = b.stoi(c);
    ASSERT_EQ(0, res);

    c = "123ddg6";
    res = b.stoi(c);
    ASSERT_EQ(0, res);

    c = "01236";
    res = b.stoi(c);
    ASSERT_EQ(0, res);

}

TEST(test021, test_CString_stof)
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

    CString b;
    CString c = "123,45";
    res = b.stof(c);
    ASSERT_TRUE(123.45 == res);

    c = "12.3,4";
    res = b.stof(c);
    ASSERT_TRUE(0 == res);

    c = "a123,4";
    res = b.stof(c);
    ASSERT_TRUE(0 == res);
}

TEST(test022, test_CString_to_string)
{
    CString a;
    a.to_string(12345);
    CString b("12345");
    ASSERT_TRUE(a == b);
}

TEST(test023, test_CString_operator_square_bracket)
{
    CString a("some");
    char b = a[0];
    ASSERT_EQ('s', b);
    char c = a[2];
    ASSERT_EQ('m', c);
    a[-1];
    a[4];
    a[5];
    a[2] = 'k';
    CString d("soke");
    ASSERT_TRUE(a == d);
}

TEST(test024, test_CString_operator_plus_eq)
{
    CString a("Happy ");
    CString b("Birthday! ");
    a += b;
    CString c("Happy Birthday! ");
    ASSERT_TRUE(a == c);

    a += 'M';
    c = "Happy Birthday! M";
    ASSERT_TRUE(a == c);

    a += "ike";
    c = "Happy Birthday! Mike";
    ASSERT_TRUE(a == c);
}

TEST(test025, test_CString_operator_plus)
{
    CString a("Craz");
    a = a + 'y';
    CString b("Crazy");
    ASSERT_TRUE(a == b);

    a = a + " Dayzi";
    b = "Crazy Dayzi";
    ASSERT_TRUE(a == b);

    CString c(" Everyday!");
    CString d("Crazy Dayzi Everyday!");
    a = b + c;
    ASSERT_TRUE(a == d);
}

TEST(test026, test_CString_operator_equal)
{
    CString a("MoDern");
    CString b("MoBern");
    int res = (a != b);
    ASSERT_EQ(1, res);
    CString c("MoDern");
    res = (a == c);
    ASSERT_EQ(1, res);
}

TEST(test027, test_CString_operator_unequal)
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

TEST(test028, test_CString_operator_more)
{
    CString a("A");
    CString b("B");
    ASSERT_TRUE(b > a);

    a = "AB";
    b = "AD";
    ASSERT_TRUE(b > a);

    a = "ABC";
    b = "AB";
    ASSERT_TRUE(a > b);
}

TEST(test029, test_CString_operator_less)
{
    CString a("A");
    CString b("B");
    ASSERT_TRUE(a < b);

    a = "AB";
    b = "AD";
    ASSERT_TRUE(a < b);

    a = "ABC";
    b = "AB";
    ASSERT_TRUE(b < a);
}

#endif // CSTRING_TEST_H
