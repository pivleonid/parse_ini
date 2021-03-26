#include <iostream>
#include <CString_test.h>
#include <CVector_test.h>
#include <CMap_test.h>
#include <gtest/include/gtest/gtest.h>
using namespace std;
int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
    return 0;
}
