#ifndef CINI_TEST_H
#define CINI_TEST_H
#include "CIni.h"
#include <gtest/include/gtest/gtest.h>
/*TEST(test052, test_CIni_read_file)
{
    CIni ini;
    ini.read_file("C:\\FilesC++\\parse\\file3.ini");
    for(unsigned  i = 0; i < ini.temp_container.size(); i++)
    {
        cout << ini.temp_container.at(i).data() << endl;
    }
    cout << "//-------------------------//" <<endl;
    for(unsigned i = 0; i < ini.data.size(); i++)
    {
        cout << ini.data.at(i).name_section.data() << endl;
        for(unsigned j = 0; j < ini.data.at(i).name_comment.size(); j++)
        {
            cout << ini.data.at(i).name_comment.at(j).data() << " ";
        }
        cout << endl;
        for(unsigned k = 1; k < ini.data.at(i).key_value.size() + 1; k++)
        {
            CString node;
            node = k;
            cout << k << " = ";
            for(unsigned h = 0; h < ini.data.at(i).key_value.getValue(node).size(); h++)
            {
                cout << ini.data.at(i).key_value.getValue(node).at(h).data() << " ";
            }
            cout << endl;
        }
    }
<<<<<<< HEAD
}*/

TEST(test053, test_CIni_write_file)
{
    CIni ini;
    ini.read_file("C:\\FilesC++\\test\\parse_ini\\file3.ini");
    ini.write_file("C:\\FilesC++\\test\\parse_ini\\file4.ini");
    cout << "//-------------------------//" <<endl;
}
#endif // CINI_TEST_H
