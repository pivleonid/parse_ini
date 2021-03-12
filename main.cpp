#include <iostream>
#include <CString.h>
#include <CVector.h>
#include <tree_abl.h>
#include <gtest/include/gtest/gtest.h>

using namespace std;
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




int main(int argc, char* argv[])
{

    tree_ABL tree;

    for(int i = 0 ; i < 10; i++)
    {
        int d;
        cin >> d;
        tree.insert(d);
    }
    tree.output();
    cout << endl;

    tree.print();
    tree.Clear();

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    return 0;
}
