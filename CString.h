#ifndef CSTRING_H
#define CSTRING_H
class CString
{
private:
    /*!
     * \brief m_word - добавляемое слово
     */
    char *m_word;
    /*!
     * \brief m_size - размер этого слова + нулевой символ
     */
    unsigned   m_size;
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
    unsigned size();

    /*!
     * \brief at - доступ к символу массива m_word под номером n
     * \param n  - порядковый номер символа
     * \return   - возвращает ссылку на выбранный символ
     */
    char &at(int n);

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
     * \return      - удалённый диапазон
     */
    CString & erase(int first = 0, int last = 1, char f = '[',  char l = ']');

    /*!
     * \brief erase - удаляет все символы s в m_word
     * \param s     - выбранный для удаления символ
     * \return      - изменённый m_word
     */
    CString & erase(char s);

    /*!
     * \brief clear - очищает объект CString
     */
    void clear();

    /*!
     * \brief push_front - добавляет символ s в начало m_word
     * \param s          - добавляемый символ
     */
    void push_front(char s);

    /*!
     * \brief push_front - добавляет str в начало m_word
     * \param s          - добавляемая строка
     */
     void push_front(const char *str);

     /*!
      * \brief push_fornt - добавляет str в начало m_word
      * \param str        - добавляемый объект
      */
     void push_front(const CString &str);

     /*!
      * \brief push_back  - добавляет символ s в конец m_word
      * \param s          - добавляемый символ
      */
     void push_back(char s);

     /*!
      * \brief push_front - добавляет str в конец m_word
      * \param s          - добавляемая строка
      */
     void push_back(const char *str);

     /*!
      * \brief push_fornt - добавляет str в начало m_word
      * \param str        - добавляемый объект
      */
     void push_back(const CString &str);

     /*!
      * \brief pop_front - удаляет первый элемент
      */
     void pop_front();

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
     unsigned find(char s);

     /*!
      * \brief find - ищет str в m_word
      * \param str  - искомая строка
      * \return     - номер в m_word, с которого начинается str
      */
     unsigned find(const CString &str);

     /*!
      * \brief rfind - ищет s в m_word с конца
      * \param s     - искомый символ
      * \return      - порядковый номер s в первом вхождении
      */
     unsigned rfind(char s);

     /*!
      * \brief rfind - ищет str в m_word с конца
      * \param str   - искомая строка
      * \return      - порядковый номер str в первом вхождении
      */
     unsigned rfind(const CString &str);

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
      * \param str  - объект для обработки
      * \return     - полученное число
      */
     int stoi(const CString &str);

     /*!
      * \brief stof - переводит m_word объекта str в число типа double
      * \param str  - объект для обработки
      * \return     - полученное число
      */
     double stof(const CString &str);

     /*!
      * \brief to_string  - переводит число n типа int в m_word
                            объекта класса CString
      * \param n          - число для обработки
      * \return           - полученный объект
      */
     CString& to_string(int n);




    CString & operator=(const CString &str);
    CString & operator=(char *str);
    CString & operator=(const char *str);
    CString & operator=(char s);
    CString & operator=(int n);
    CString & operator=(unsigned n);

    char & operator[](int n);

    CString & operator+=(char s);
    CString & operator+=(const char *str);
    CString & operator+=(const CString &str);

    CString & operator+(char s);
    CString & operator+(const char *str);
    friend const char * operator+(const CString &str1, const CString &str2);
    //CString operator+(const CString &str);

    bool operator!=(const CString &str);
    bool operator==(const CString &str);

    bool operator<=(const CString &str);
    bool operator>=(const CString &str);

    bool operator<(const CString &str);
    bool operator>(const CString &str);
};
#endif // CSTRING_H
