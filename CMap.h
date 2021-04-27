#ifndef MAP_H
#define MAP_H
#include "CString.h"
#include "CVector.h"
#include "string"
#include "cstring"
#include <iostream>
using namespace std;
template <typename A, typename B, typename C>
class CMap
{
public:
    class Node
    {
    public:
        Node *left;
        Node *right;
        A    key;
        B    value;
        C    comment;
    };
private:
    /*!
     * \brief root - корень дерева
     * m_count     - счётчик элементов дерева
     */
    Node *root;
    int m_count;

    /*!
     * \brief getAdress - получение адреса элемента по ключу
     * \param target    - искомый ключ
     * \param tree      - дерево в котором этот элемент ищем
     * \return          - возвращает полученный адрес
     */

    Node *getAdress(const A &key, Node *tree);
    /*!
     * \brief getAdressParent - получение адреса родителя искомого элемента
     * \param child           - искомый элемент
     * \param tree            - дерево в котором ищем адрес родителя
     * \return                - возвращает полученный адрес
     */
    Node *getAdressParent(Node *child, Node *tree);
    /*!
     * \brief search_replacing - поиск замены для удаляемого элемента
     * \param tree             - дерево в котором ищем замену
     * \return                 - возвращет адрес узла для замены
     */
    Node *search_replacing(Node *tree);

    bool search_inner(const A &key, Node *tree);
    Node *add_pair_inner(const A &key, const B &value, const C &comment, Node *tree);
    Node *operator_eq_inner(Node *this_tree, Node *tree);
    void delete_all(Node *tree);
public:
    CMap();
    ~CMap();

    /*!
     * \brief add_pair - добавление нового узла в дерево
     * \param key      - ключ
     * \param value    - значение
     */
    void add_pair(const A &key, const B &value, const C &comment = "null");

    /*!
     * \brief search - поиск узла в дереве по ключу
     * \param target - искомый ключ
     * \return       - true если ключ найден
     */
    bool search(const A &key);

    /*!
     * \brief getValue - получение значения по ключу
     * \param target   - искомый ключ
     * \return         - значение
     */
    B &getValue(const A &key);

    C &getComment(const A &key);
    /*!
     * \brief delete_key - удаление узла по ключу
     * \param target     - искомый ключ
     */
    void delete_key(const A &key);
    int size();
    CMap<A, B, C>  &operator=(const CMap &map);
};
#endif // MAP_H








