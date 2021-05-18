#ifndef CINI_H
#define CINI_H
#include <iostream>
#include "fstream"
#include "CVector.h"
//#include "CVector.cpp"
#include "CMap.h"
//#include "CMap.cpp"
using namespace std;

class Content_of_section
{
public:
<<<<<<< HEAD
    /*!
     * \brief name_section - название секции
     */
    CString name_section;
    /*!
     * \brief name_comment - комментарий к секции
     */
    CVector<CString> name_comment;
    /*!
     * \brief key_value    - содержимое секции
     */
    CMap<CString, CVector<CString>> key_value;
    void clear()
    {
        name_section.clear();
        name_comment.clear();
        key_value.clear();
    }
=======
    CString name_section;                                //название секции
    CVector<CString> name_comment;               //комментарий к секции
    CMap<CString, CVector<CString>, CVector<CString>> key_value;   //содержимое секции
>>>>>>> 2cfe95f891e7f8f9a32ba1a515491c986c0d2386
};

class CIni
{
private:
<<<<<<< HEAD
    /*!
     * \brief file_path - путь к ini-файлу
     */
    const char *file_path;

    /*!
     * \brief analyze_file   - функция для анализа содержимого temp_container
     */
    void analyze_file();

    /*!
     * \brief write_file_inner - запись данных из data обратно в temp_container
                                 чтобы их записать в пустой ini-файл
     */
=======
    const char *file_path;                //путь к файлу
    CVector<CString> temp_container;
    CVector<Content_of_section> data;
    void analyze_file();
>>>>>>> 2cfe95f891e7f8f9a32ba1a515491c986c0d2386
    void write_file_inner();
public:
    /*!
     * \brief data           - объект CVector для хранения обработанных данных
                               ini-файла
     */
    CVector<Content_of_section> data;
    /*!
     * \brief temp_container - объект CVector для хранения необработанных данных
                               ini-файла
     */
    CVector<CString> temp_container;
    /*!
     * \brief read_file - чтение данных из ini-файл
     * \param file_path - путь к ini-файлу
     */
    void read_file(const char *file_path);
<<<<<<< HEAD

    /*!
     * \brief write_file - запись данных в пустой ini-файл
     * \param file_path  - путь к пустому ini-файлу
     */
=======
>>>>>>> 2cfe95f891e7f8f9a32ba1a515491c986c0d2386
    void write_file(const char *file_path);
};
#endif // CINI_H











