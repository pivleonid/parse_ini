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
    friend class CVector;
    CString();
    CString(char s);
    CString(const char *str);
    CString(const CString &new_word);
    CString(int n);
    ~CString();

    CString& operator=(const CString &str);
    CString& operator=(const char *str);
    CString& operator=(char s);
    CString& operator=(int n);

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
    char* data();

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

    /*************************************************************
     * find - ищет s в m_word и возвращает его порядковый номер
     *************************************************************
    */
    /*!
     * \brief find - ищет s в m_word
     * \param s    - искомый символ
     * \return     - порядковый номер символа, если совпадений несколько
                     то возвращает сколько раз
     */
    int find(char s);

    /*************************************************************
     * find - ищет str в m_word и возвращает номер в m_word,
              с которого str начинается
     *************************************************************
    */
    /*!
     * \brief find
     * \param str
     * \return
     */
    int find(const CString &str);

    /*************************************************************
     * rfind - ищет s в m_word с конца и возвращает его
               порядковый номер
     *************************************************************
    */
    int rfind(char s);

    /*************************************************************
     * rfind - ищет str в m_word с конца и возвращает номер
               в m_word, с которого str начинается
     *************************************************************
    */
    int rfind(const CString &str);



    /*************************************************************
     * stoi - переводит массив char в число типа int
              и возвращает это число
     *************************************************************
    */
    int  stoi();

    /*************************************************************
     * stof - переводит массив char в число типа double
              и возвращает это число
     *************************************************************
    */
    double stof();

    /*************************************************************
     * stoi - переводит m_word объекта str в число типа int
              и возвращает это число
     *************************************************************
    */
    int stoi(const CString &str);

    /*************************************************************
     * stof - переводит m_word объекта str в число типа double
              и возвращает это число
     *************************************************************
    */
    double stof(const CString &str);

    /*************************************************************
     * to_string - переводит n типа int в m_word объекта класса
                   CString и возвращает этот объект
     *************************************************************
    */
    CString& to_string(int n);

    /*************************************************************
     * to_string - переводит n типа double в m_word объекта класса
                   CString и возвращает этот объект
     *************************************************************
    */
    CString& to_string(double n);

    /*************************************************************
     *clear      - очищает объект CString
     *************************************************************
    */
    void clear();
};
#endif // CSTRING_H
