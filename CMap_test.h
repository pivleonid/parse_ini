#ifndef MAP_TEST_H
#define MAP_TEST_H
#include "CMap.h"
#include "CMap.cpp"
#include <gtest/include/gtest/gtest.h>
using namespace std;

TEST(test037, test_CMap_CString_CString)
{
      Map<CString, CString> a;
      CString k1(1); CString b("Zero");
      a.add_pair(k1, b);

      CString k2(2); CString c("WALKYRIE");
      a.add_pair(k2, c);

      CString k3(3); CString d("New");
      a.add_pair(k3, d);

      CString k4(4); CString e("X-men");
      a.add_pair(k4, e);

      CString k5(5); CString g("developer");
      a.add_pair(k5, g);

      CString k6(6); CString h("match");
      a.add_pair(k6, h);

      CString k7(7); CString i("view");
      a.add_pair(k7, i);

      CString k8(8); CString j("hero");
      a.add_pair(k8, j);

      CString k9(9); CString m("big_boss");
      a.add_pair(k9, m);

      CString k10(10); CString n("Titan");
      a.add_pair(k10, n);

      CString k11(11); CString p("Sub-zero");
      a.add_pair(k11, p);

      CString l("hello");
      a.add_pair(k8, l);

      CString f("Warkraft");
      a.add_pair(k2, f);

      a.delete_key(k5);
      a.delete_key(k2);
      bool res = a.search(k4);
      CString k;
      k = a.getValue(k3);
      ASSERT_TRUE(res);
}

TEST(test038, test_CMap_int_int)
{
    Map<int, int> a;
    int k1 = 1; int b = 60;
    a.add_pair(k1, b);

    int k2 = 2; int c = 35;
    a.add_pair(k2, c);

    int k3 = 3; int d = 70;
    a.add_pair(k3, d);

}

TEST(test039, test_CMap_int_CString)
{
    Map<int, CString> a;
    int k1(1); CString b("Zero");
    a.add_pair(k1, b);

    int k2(2); CString c("WALKYRIE");
    a.add_pair(k2, c);

    int k3(3); CString d("New");
    a.add_pair(k3, d);
}

TEST(test040, test_CMap_int_CVector)
{
    Map<int, CVector<CString>> a;

    CVector<CString> v;
    CString b("Zero"); CString c("WALKYRIE"); CString d("New");
    v.push_back(b); v.push_back(c); v.push_back(d);

    int k1(1);

    a.add_pair(k1, v);

    CVector<CString> v1;
    CString e("X-men"); CString g("developer");
    v1.push_back(e); v1.push_back(g);

    int k2(2);

    a.add_pair(k2, v1);

    CVector<CString> v2;
    CString h("match"); CString i("view"); CString j("hero"); CString m("big_boss");
    v2.push_back(h); v2.push_back(i); v2.push_back(j); v2.push_back(m);

    int k3(3);

    a.add_pair(k3, v2);
}

#endif // MAP_TEST_H
