#ifndef CINI_H
#define CINI_H
#include <iostream>
#include "fstream"
#include "CVector.h"
#include "CVector.cpp"
#include "CMap.h"
#include "CMap.cpp"
using namespace std;

class Section_data
{
public:
    CString section;                        //название секции
    //CVector<CString> comment;             //комментарий к секции
    CMap<CString, CString> key_value;       //содержимое секции
};

class CIni
{
private:
    const char *file_path;                //путь к файлу
    CVector<CString> temp_container;
    CVector<Section_data> data;
    void analyze_file();
public:
    void read_file(const char *file_path);

};
#endif // CINI_H
