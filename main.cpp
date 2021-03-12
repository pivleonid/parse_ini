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
int mass[11] = {6,15,4,3,1,5,8,7,42,12,21};
    for(int i = 0 ; i < 11; i++)
    {
        tree.insert(mass[i]);
    }
    cout << endl;
    tree.output();
    cout << endl;
    tree.print();

    for(int i = 0; i < 50; i++)
    {
        cout<<"vvedite d"<<endl;
        int d;
        cin >> d;
        if(d == -1)
            break;
        bool ret = tree.find(d);
        if(ret == true )
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }

    tree.print();
    tree.Clear();

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    return 0;
}
