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
     * \brief m_name_section - название секции
     */
    CString m_name_section;
    /*!
     * \brief m_name_comment - комментарий к секции
     */
    CVector<CString> m_name_comment;
    /*!
     * \brief m_key_value    - содержимое секции
     */
    CMap<CString, CVector<CString>> m_key_value;

    Content_of_section();
    void clear()
    {
        m_name_section.clear();
        m_name_comment.clear();
        m_key_value.clear();
    }
};

class CIni
{
private:
    /*!
     * \brief m_file_path      - путь к ini-файлу
     */
    const char *m_file_path;


    /*!
     * \briefm_temp_container  - объект CVector для хранения необработанных данных
                                 ini-файла
     */
    CVector<CString>m_temp_container;

    /*!
     * \brief analyze_file     - анализ содержимого m_temp_container
     */
    void analyze_file();

    /*!
     * \brief write_file_inner - запись данных из m_data обратно вm_temp_container
                                 чтобы их записать в пустой ini-файл
     */
    void write_file_inner();

public:

    CIni();
    /*!
     * \brief m_data           - объект CVector для хранения обработанных данных
                               ini-файла
     */
    CVector<Content_of_section> m_data;

    /*!
     * \brief create_file      - создание пустого ini-файла
     * \param file_path        - путь к ini-файлу
     */
    void create_file(const char *file_path);

    /*!
     * \brief delete_file      - удаление файла
     * \param file_path        - путь к ini-файлу
     */
    void delete_file(const char *file_path);

    /*!
     * \brief read_file        - чтение данных из ini-файла
     * \param file_path        - путь к ini-файлу
     */
    void read_file(const char *file_path);

    /*!
     * \brief write_file       - запись данных в ini-файл
     * \param file_path        - путь к ini-файлу
     */
    void write_file(const char *file_path);

    /*!
     * \brief clear            - очистка содержимого объекта CIni
     */
    void clear();

    /*!
     * \brief add_name_section - добавление имени для новой секции
     * \param new_name         - имя секции
     */
    void add_name_section(CString & new_name);

    /*!
     * \brief change_m_name_section - поменять название секции
     * \param old_name            - старое название
     * \param new_name            - новое название
     */
    void change_name_section(CString &old_name, CString &new_name);

    /*!
     * \brief add_name_comment - добавляет комментарий для новой секции
     * \param name_section     - имя секции куда добавляем комментарий
     * \param new_comment      - комментарий
     */
    void add_name_comment(CString & name_section, CString & new_comment);

    /*!
     * \brief add_key_value - наполняет секцию содержимым
     * \param name_section  - секция для наполнения
     * \param key_value     - содержимое секции
     */
    void add_key_value(CString & name_section, CMap<CString, CVector<CString>> & key_value);

    /*!
     * \brief change_name_comment - меняет значение old_comment, на new_comment
     * \param name_section        - секция в которой меняем значение
     * \param new_comment         - значение для замены
     */
    void change_name_comment(CString & name_section, CString & new_comment);

    /*!
     * \brief change_name_comment - меняет значение old_comment в CVector, на new_comment
     * \param name_section        - секция в которой меняем значение
     * \param old_comment         - изменяемое значение
     * \param new_comment         - значение для замены
     */
    void change_name_comment(CString & name_section, CString & old_comment, CString & new_comment);

    /*!
     * \brief delete_value        - удалить полностью значение по ключу
     * \param m_name_section        - секция в которой удаляем
     * \param key                 - ключ по которому удаляем
     */
    void delete_value(CString &m_name_section, CString &key);
    /*!
     * \brief delete_value        - удалить значение под номером n в CVector
     * \param m_name_section      - секция в которой удаляем
     * \param key                 - ключ по которому удаляем
     * \param value               - значение в CVector для удаления
     */
    void delete_value(CString &m_name_section, CString &key, CString &value);

    /*!
     * \brief show_all            - демонстрация содержимого всего ini-файла
     */
    void show_all();

    /*!
     * \brief change_value          - полностью меняет значение CVector, по указанному ключу
     * \param m_name_section        - секция в которой меняем значение
     * \param key                   - ключ для поиска значения
     * \param value                 - значение для замены
     */
    void change_value(CString &m_name_section, CString &key, CVector<CString> &value);
    /*!
     * \brief change_value               - меняет значение под old_value в CVector, по указанному ключу
     * \param m_name_section             - секция в которой меняем значение
     * \param key                        - ключ для поиска значения
     * \param new_value                  - значение для замены
     * \param old_value                  - номер значения в CVector для замены
     */
    void change_value(CString &m_name_section, CString &key, CString & old_value, CString & new_value);

    /*!
     * \brief add_value             - добавляет значение которого нет в секции
     * \param m_name_section        - секция в которую добавляем
     * \param key                 - ключ для добавления
     * \param value               - значение для добавления
     */
    void add_value(CString &m_name_section, CString &key, CVector<CString> &value);
    /*!
     * \brief add_value          - добавляет значение CString в CVector, по указанному ключу
     * \param m_name_section       - секция в которую добавляем
     * \param key                - ключ для добавления
     * \param value              - значение для добавления
     */
    void add_value(CString &m_name_section, CString &key, CString &value);
};

#endif // CINI_H











