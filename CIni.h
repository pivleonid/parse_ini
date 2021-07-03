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
            string name_section = "empty section";
            string comment_section = "empty comment";
            string key1 = "zero";
            string value1 = "empty value";
            vector<string> vec1;
            vec1.push_back(value1);
            map<string, vector<string>> key_value;
            key_value.insert(pair<string, vector<string>>(key1, vec1));
            m_name_section = name_section;
            m_comment_section = comment_section;
            m_key_value = key_value;
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
     * \brief m_temp_container - объект типа vector для хранения необработанных данных ini-файла
     */
    vector<string> m_temp_container;

    /*!
     * \brief m_data - объект типа vector для хранения обработанных данных ini-файла
     */
    vector<Content_of_section> m_data;
    /*!
     * \brief analyze_file - анализ содержимого m_temp_container
     */
    void analyze_file();
    /*!
     * \brief write_file_inner - запись данных из m_data
     */
    void write_file_inner();

public:
    /*CIni()
    {
        string name_section = "empty section";
        string comment_section = "empty comment";
        string key1 = "zero";
        string value1 = "empty value";
        vector<string> vec1;
        vec1.push_back(value1);
        map<string, vector<string>> key_value;
        key_value.insert(pair<string, vector<string>>(key1, vec1));
        m_data.begin()->m_name_section = name_section;
        m_data.begin()->m_comment_section = comment_section;
        m_data.begin()->m_key_value = key_value;
    }*/
    void read_file(string &name_file);

    void create_file(string &name_file);

    void delete_file(string &name_file);

    void write_file(string &name_file);
    bool search_name_section(string &name_section);
    bool add_name_section(string &new_name);
    bool add_comment_section(string &name_section, string &comment_section);

    bool change_name_section(string &old_name, string &new_name);
    bool add_key_value(string &name_section, map<string, vector<string>> &key_value);

    const char *get_comment_section(string &name_section);

    vector<string> &getValue(string &name_section, string &key);
    void delete_value(string &name_section, string &key, string &value);
    void delete_value(string &name_section, string &key);
    unsigned &get_size_key_value(string &name_section);
    bool change_value(string &name_section, string &key, vector<string> &value);
    bool change_value(string &name_section, string &key, string & old_value, string & new_value);
    bool add_value(string &name_section, string &key, vector<string> &value);
    bool  add_value(string &m_name_section, string &key, string &value);
};
#endif // CINI_H
