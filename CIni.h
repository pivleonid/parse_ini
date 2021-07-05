#ifndef CINI_H
#define CINI_H
#include <iostream>
#include "fstream"
#include "string"
#include "vector"
#include "map"
using namespace std;
class Content_of_section
{

private:
    friend class CIni;
    /*!
     * \brief name_section - название секции
     */
    string m_name_section;
    /*!
     * \brief m_comment_section - комментарий к секции
     */
    string m_comment_section;
    /*!
     * \brief m_key_value - содержимое секции
     */
    map<string, vector<string>> m_key_value;

    Content_of_section()
    {
        string empty_name    = "empty name";
        string empty_comment = "empty comment";
        string empty_key     = "empty key";
        string empty_value   = "empty value";
        vector<string> empty_vec;
        empty_vec.push_back(empty_value);
        map<string, vector<string>> empty_map;
        empty_map.insert(pair<string, vector<string>>(empty_key, empty_vec));
        m_name_section    = empty_name;
        m_comment_section = empty_comment;
        m_key_value       = empty_map;
    }
    void clear()
    {
        m_name_section.clear();
        m_comment_section.clear();
        m_key_value.clear();
    }
};

class CIni
{
private:
    /*!
     * \brief m_name_file - имя файла
     */
    string m_name_file;

    /*!
     * \brief m_temp_container  - объект типа vector для хранения необработанных данных
                                 ini-файла
     */
    vector<string> m_temp_container;

    /*!
     * \brief m_data           - объект типа vector для хранения обработанных данных
                               ini-файла
     */
    vector<Content_of_section> m_data;

    /*!
     * \brief analyze_file - анализ содержимого m_temp_container
     */
    void analyze_file();

    /*!
      * \brief write_file_inner - запись данных из m_data обратно в m_temp_container
                                  чтобы их записать в пустой ini-файл
      */
    void write_file_inner();

public:
    /*!
     * \brief read_file        - чтение данных из ini-файла
     * \param name_file        - имя ini-файла
     */
    void read_file(string &name_file);

    /*!
     * \brief create_file      - создание пустого ini-файла
     * \param name_file        - имя ini-файла
     */
    void create_file(string &name_file);

    /*!
     * \brief delete_file      - удаление файла
     * \param name_file        - имя ini-файла
     */
    void delete_file(string &name_file);

    /*!
     * \brief write_file       - запись данных в ini-файл
     * \param name_file        - имя ini-файла
     */
    void write_file(string &name_file);

    /*!
     * \brief search           - поиск секции по имени name_section в объекте CIni
     * \param name_section     - имя секции для поиска
     * \return                 - true если секция по имени name_section есть в объекте CIni,
                                 false если отсутствует
     */
    bool search_name_section(string &name_section);

    /*!
     * \brief add_name_section - добавление имени для новой секции
     * \param new_name         - имя секции
     * \return                 - true если секция по имени new_section уже есть в объекте CIni,
                                 false если отсутствует
     */
    bool add_name_section(string &new_name);

    /*!
     * \brief add_comment_section - добавляет комментарий для новой секции
     * \param name_section        - имя секции куда добавляем комментарий
     * \param comment_section     - комментарий
     * \return                    - true если секция по имени name_section есть в объекте CIni,
                                    false если отсутствует
     */
    bool add_comment_section(string &name_section, string &comment_section);


    /*!
     * \brief change_name_section - поменять название секции
     * \param old_name            - старое название
     * \param new_name            - новое название
     * \return                    - true если секция по имени old_name есть в объекте CIni,
                                    false если отсутствует
     */
    bool change_name_section(string &old_name, string &new_name);

    /*!
     * \brief add_key_value       - наполняет секцию содержимым
     * \param name_section        - секция для наполнения
     * \param key_value           - содержимое секции
     * \return                    - true если секция по имени name_section есть в объекте CIni,
                                    false если отсутствует

     */
    bool add_key_value(string &name_section, map<string, vector<string>> &key_value);

    /*!
     * \brief get_comment_section - получить комментарий к секции name_section
     * \param name_section        - имя секции
     * \return                    - пустая строка если секци по имени name_section отсутствует
     */
    const char *get_comment_section(string &name_section);

    /*!
     * \brief getValue            - получение значения типа vector<string> по ключу key
     * \param name_section        - имя секции
     * \param key                 - имя ключа для поиска по дереву
     * \return                    - объект типа vector<string> по ключу key
     */
    vector<string> &getValue(string &name_section, string &key);

    /*!
     * \brief delete_value        - удалить значение value в объекте типа vector<string>
     * \param name_section        - секция в которой происходит удаление
     * \param key                 - ключ по которому находится искомый объект
     * \param value               - значение для удаления
     * \return                    - true если секция по имени name_section есть в объекте CIni
                                    и если value есть в vector<string>, false если отсутствуют

     */
    bool delete_value(string &name_section, string &key, string &value);
    /*!
     * \brief delete_value        - удалить узел в дереве по ключу key
     * \param name_section        - секция в которой происходит удаление
     * \param key                 - ключ по которому находится искомый узел
     * \return                    - true если секция по имени name_section есть в объекте CIni,
                                    false если отсутствует
     */
    bool delete_value(string &name_section, string &key);

    /*!
     * \brief get_size_key_value  - получить размер дерева типа map
     * \param name_section        - имя секции
     * \return                    - размер дерева
     */
    unsigned &get_size_key_value(string &name_section);

    /*!
     * \brief change_value        - полностью меняет значение типа vector<string>, по указанному ключу key
     * \param name_section        - имя секции
     * \param key                 - ключ по которому находится искомый узел
     * \param value               - значение на которое происходит замена
     * \return                    - true если секция по имени name_section есть в объекте CIni,
                                    false если отсутствует
     */
    bool change_value(string &name_section, string &key, vector<string> &value);

    /*!
     * \brief change_value        - меняет значение old_value в объекте типа vector<string>, по указанному ключу key
     * \param name_section        - имя секции
     * \param key                 - ключ по которому находится искомый узел
     * \param old_value           - значение которое нужно изменить
     * \param new_value           - значение на которое происходит замена
     * \return                    - true если секция по имени name_section есть в объекте CIni
                                    и если value есть в vector<string>, false если отсутствуют
     */
    bool change_value(string &name_section, string &key, string & old_value, string & new_value);

    /*!
     * \brief add_value           - добавляет значение типа vector<string> в секцию по имени name_section
     * \param name_section        - имя секции
     * \param key                 - ключ для добавления
     * \param value               - значения по ключу
     * \return                    - true если секция по имени name_section есть в объекте CIni,
                                    false если отсутствуют, в случае false, создаётся секция по имени name_section
                                    и добавляется в объект CIni
     */
    bool add_value(string &name_section, string &key, vector<string> &value);

    /*!
     * \brief add_value            - добавляет значение типа string в секцию по имени name_section
     * \param m_name_section       - имя секции
     * \param key                  - ключ для добавления
     * \param value                - добавляемое значение
     * \return                     - true если секция по имени name_section есть в объекте CIni,
                                    false если отсутствуют, в случае false, создаётся секция по имени name_section
                                    и добавляется в объект CIni
     */
    bool  add_value(string &m_name_section, string &key, string &value);
};
#endif // CINI_H
