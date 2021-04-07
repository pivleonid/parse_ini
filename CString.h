#ifndef CSTRING_H
#define CSTRING_H
class CString
{
private:
    // добавляемое слово
    char *m_word;
    //размер этого слова + нулевой символ
    int   m_size;
public:
    CString();
    CString(char s);
    CString(const char *str);
    CString(const CString &new_word);
    CString(int n);
    ~CString();



    /*!
     * \brief size - возвращает размер m_word
     * \return     - m_size
     */
    int size();

    /*!
     * \brief at - доступ к символу массива m_word
     * \param n  - порядковый номер символа
     * \return   - возвращает ссылку на выбранный символ
     */
    char& at(int n);

    /*!
     * \brief front - возвращает 1 элемент m_word
     * \return      - ссылка на 1 элемент m_word
     */
    char& front();

    /*!
     * \brief back - возвращает предпоследний элемент m_word
     * \return     - ссылка на предпоследний элемент m_word
     */
    char& back();

    /*!
     * \brief data - возвращает указатель на m_word
     * \return     - указатель на m_word
     */
    const char* data();

    /*!
     * \brief empty - проверяет пустой ли объект
     * \return      - true - пустой, false - полный
     */
    bool empty();

    /*!
     * \brief erase - удаляет символы m_word в диапазоне first - last
     * \param first - символ с которого начинается удаление
     * \param last  - символ на котором заканчивается
     * \return      - изменённый m_word
     */
    CString& erase(int first, int last);

    /*!
     * \brief erase - удаляет все символы s в m_word
     * \param s     - выбранный для удаления символ
     * \return      - изменённый m_word
     */
    CString& erase(char s);

    /*!
     * \brief push_back - добавляет символ s в конец m_word
     * \param s         - добавляемый символ
     */
    void push_back(char s);

    /*!
     * \brief push_back - добавляет str в конец m_word
     * \param str       - добавляемый объект
     */
    void push_back(const CString &str);

    /*!
     * \brief pop_back - удаляет предпоследний элемент в m_word
     */
    void pop_back();

    /*!
     * \brief compare - сравнивает два объекта
     * \param str     - объект с которым сравниваем
     * \return        - true если совпали все символы
     */
    bool compare(const CString &str);

    /*!
     * \brief find - ищет s в m_word
     * \param s    - искомый символ
     * \return     - порядковый номер символа, если совпадений несколько
                     то возвращает сколько раз
     */
    int find(char s);

    /*!
     * \brief find - ищет str в m_word
     * \param str  - искомая строка
     * \return     - номер в m_word, с которого начинается str
     */
    int find(const CString &str);

    /*!
     * \brief rfind - ищет s в m_word с конца
     * \param s     - искомый символ
     * \return      - порядковый номер s в первом вхождении
     */
    int rfind(char s);

    /*!
     * \brief rfind - ищет str в m_word с конца
     * \param str   - искомая строка
     * \return      - порядковый номер str в первом вхождении
     */
    int rfind(const CString &str);

    /*!
     * \brief stoi - переводит массив char в число типа int
     * \return     - полученное число
     */
    int  stoi();

    /*!
     * \brief stof - переводит массив char в число типа double
     * \return     - полученное число
     */
    double stof();

    /*!
     * \brief stoi - переводит m_word объекта str в число типа int
     * \param str
     * \return     - полученное число
     */
    int stoi(const CString &str);

    /*!
     * \brief stof - переводит m_word объекта str в число типа double
     * \param str
     * \return     - полученное число
     */
    double stof(const CString &str);

    /*!
     * \brief to_string  - переводит n типа int в m_word объекта класса
                           CString
     * \param n
     * \return           - полученный объект
     */
    CString& to_string(int n);

    /*!
     * \brief to_string - переводит n типа double в m_word объекта класса
                          CString
     * \param n
     * \return          - полученный объект
     */
    CString& to_string(double n);

    /*!
     * \brief clear - очищает объект CString
     */
    void clear();
    CString& operator=(const CString &str);
    CString& operator=(const char *str);
    CString& operator=(char s);
    CString& operator=(int n);
    //char * operator[](int n);
    CString& operator+=(const CString &str);
    CString& operator+=(char s);
    CString& operator+=(const char *str);
    CString& operator+(char s);
    CString& operator+(const char *str);
    friend const char* operator+(const CString &str1, const CString &str2);
    bool operator!=(const CString &str);
    bool operator==(const CString &str);
    bool operator<=(const CString &str);
    bool operator>=(const CString &str);
    bool operator<(const CString &str);
    bool operator>(const CString &str);
};
#endif // CSTRING_H
