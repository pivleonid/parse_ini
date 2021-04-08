#ifndef MAP_H
#define MAP_H
#include "CString.h"
#include "CVector.h"
#include "string"
#include "cstring"
#include <iostream>
using namespace std;
template <typename A, typename B>
class Map
{
public:
    class Node
    {
    public:
        Node *left;
        Node *right;
        A    key;
        B    value;
    };
private:
    /*!
     * \brief root - корень дерева
     */
    Node *root;

    /*!
     * \brief getAdress - получение адреса элемента по ключу
     * \param target    - искомый ключ
     * \param tree      - дерево в котором этот элемент ищем
     * \return          - возвращает полученный адрес
     */

    Node *getAdress(A &target, Node *tree);
    /*!
     * \brief getAdressParent - получение адреса родителя искомого элемента
     * \param child           - искомый элемент
     * \param tree            - дерево в котором ищем адрес родителя
     * \return                - возвращает полученный адрес
     */
    Node *getAdressParent(Node *child, Node *tree);
<<<<<<< HEAD
    /*!
     * \brief search_replacing - поиск замены для удаляемого элемента
     * \param tree             - дерево в котором ищем замену
     * \return                 - возвращет адрес узла для замены
     */
    Node *search_replacing(Node *tree);

    bool search_inner(A &target, Node *tree);
    Node *add_pair_inner(A &key,const B &value, Node *tree);
=======

    Node *search_replacing(Node *tree);


    bool search_inner(A &target, Node *tree);
    //B &getValue(A &key, Node *tree);
    Node * add_pair_inner(A &key, B &value, Node *tree);
>>>>>>> dc63914f833218594477c9811b624317339d19a4
    void delete_all(Node *tree);
public:
    Map();
    ~Map();
<<<<<<< HEAD
=======
    void add_pair(A &key, B &value);
    bool search(A &target);
    //Есть ли такой ключ
    B &getValue(A &target);
    void delete_key(A &target);
>>>>>>> dc63914f833218594477c9811b624317339d19a4

    /*!
     * \brief add_pair - добавление нового узла в дерево
     * \param key      - ключ
     * \param value    - значение
     */
    void add_pair(A &key,const B &value);

    /*!
     * \brief search - поиск узла в дереве по ключу
     * \param target - искомый ключ
     * \return       - true если ключ найден
     */
    bool search(A &target);

    /*!
     * \brief getValue - получение значения по ключу
     * \param target   - искомый ключ
     * \return         - значение
     */
    B &getValue(A &target);

    /*!
     * \brief delete_key - удаление узла по ключу
     * \param target     - искомый ключ
     */
    void delete_key(A &target);

    B &operator=(B &value);
};
#endif // MAP_H








