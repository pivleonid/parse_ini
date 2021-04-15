#ifndef CFILE_H
#define CFILE_H
#include "CMap.h"
/*!
 * \brief The CFile class - для обработки ini файлов
 */
template <typename A, typename B>
class CFile
{
private:
    const char *file_path;                //путь к файлу
    int m_count_ch;                       //количество символов в файле
    char *array_chars;                    //массив для хранения всех символов в файле
    int m_size_container;                 //размер контейнера для хранения Node
    int m_count_container;                //счётчик элементов контейнера
    class Node
    {
      public:
        CString section;                  //название секции
        //CVector<CString> comment;         //комментарий к секции
        CMap<A, B> key_value;             //содердимое секции
    };
    Node *container;
    void analyze_file();
    void get_value(char *temp_array_chars, bool new_section);
public:

    CFile();
    ~CFile();
    /*!
     * \brief read_file - чтение файла
     * \param file_path - путь к файлу
     */
    void read_file(const char *file_path);
    void write_file(const char *file_path);
};
#endif // CFILE_H
