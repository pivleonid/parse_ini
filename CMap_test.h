#ifndef MAP_TEST_H
#define MAP_TEST_H
#include "CMap.h"

#include <gtest/include/gtest/gtest.h>
using namespace std;

TEST(test037, test_CMap)
{
    Map a;
    CString b("Zero");
    CString c("WALKYRIE");
    CString d("New");
    CString e("X-men");
    CString f("developer");
    CString g("match");
    CString h("view");
    CString i("hero");
    CString j("Zero");
    CString k("hero");
    CString l("big_boss");
    a.add(b);
    a.add(c);
    a.add(d);
    a.add(e);
    a.add(f);
    a.add(g);
    a.add(h);
    a.add(i);
    a.add(j);
    a.add(k);
    a.add(l);
    bool res = a.search("Zero");
    ASSERT_EQ(1, res);
}
#endif // MAP_TEST_H
