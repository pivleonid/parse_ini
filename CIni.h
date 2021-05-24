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
};

class CIni
{
private:
    /*!
     * \brief file_path - путь к ini-файлу
     */
    const char *file_path;

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
     * \brief analyze_file   - функция для анализа содержимого temp_container
     */
    void analyze_file();

    /*!
     * \brief write_file_inner - запись данных из data обратно в temp_container
                                 чтобы их записать в пустой ini-файл
     */
    void write_file_inner();

public:

    /*!
     * \brief read_file - чтение данных из ini-файл
     * \param file_path - путь к ini-файлу
     */
    void read_file(const char *file_path);

    /*!
     * \brief write_file - запись данных в пустой ini-файл
     * \param file_path  - путь к пустому ini-файлу
     */
    void write_file(const char *file_path);

    /*!
     * \brief change_name_section - поменять название секции
     * \param old_name            - старое название
     * \param new_name            - новое название
     */
    void change_name_section(CString &old_name, CString &new_name);

    /*!
     * \brief delete_value        - удалить полностью значение по ключу
     * \param name_section        - секция в которой удаляем
     * \param key                 - ключ по котором удаляем
     */
    void delete_value(CString &name_section, CString &key);

    /*!
     * \brief show_all            - демонстрация содержимого всего ini-файла
     */
    void show_all();

    /*!
     * \brief change_value        - полностью меняет значение, указанное по ключу
     * \param name_section        - секция в которой меняем значение
     * \param key                 - ключ для поиска значения
     * \param value               - значение для замены
     */
    void change_value(CString &name_section, CString &key, CVector<CString> &value);

    /*!
     * \brief add_value           - добавляет значение которого нет в секции
     * \param name_section        - секция в которую добавляем
     * \param key                 - ключ для добавления
     * \param value               - значение для добваления
     */
    void add_value(CString &name_section, CString &key, CVector<CString> &value);
};

#endif // CINI_H











