#ifndef CINI_H
#define CINI_H
#include <iostream>
#include "fstream"
#include "CVector.h"
#include "CVector.cpp"
#include "CMap.h"
#include "CMap.cpp"
using namespace std;

class Content_of_section
{
public:
    CString name_section;                                //название секции
    CVector<CString> name_comment;               //комментарий к секции
    CMap<CString, CVector<CString>, CVector<CString>> key_value;   //содержимое секции
};

class CIni
{
private:
    const char *file_path;                //путь к файлу
    CVector<CString> temp_container;
    CVector<Content_of_section> data;
    void analyze_file();
    void write_file_inner();
public:
    void read_file(const char *file_path);
    void write_file(const char *file_path);
};
#endif // CINI_H
