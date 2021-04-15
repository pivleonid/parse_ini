#ifndef MAP_H
#define MAP_H
#include "CString.h"
#include "CVector.h"
#include "string"
#include "cstring"
#include <iostream>
using namespace std;
template <typename A, typename B>
<<<<<<< HEAD
class CMap
=======
class Map
>>>>>>> 4ac85f01b16f65741dd1c39777f40c3d1ce81c29
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

<<<<<<< HEAD
    Node *getAdress(const A &key, Node *tree);
=======
    Node *getAdress(A &target, Node *tree);
>>>>>>> 4ac85f01b16f65741dd1c39777f40c3d1ce81c29
    /*!
     * \brief getAdressParent - получение адреса родителя искомого элемента
     * \param child           - искомый элемент
     * \param tree            - дерево в котором ищем адрес родителя
     * \return                - возвращает полученный адрес
     */
    Node *getAdressParent(Node *child, Node *tree);
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 4ac85f01b16f65741dd1c39777f40c3d1ce81c29
    /*!
     * \brief search_replacing - поиск замены для удаляемого элемента
     * \param tree             - дерево в котором ищем замену
     * \return                 - возвращет адрес узла для замены
     */
    Node *search_replacing(Node *tree);
<<<<<<< HEAD

    bool search_inner(const A &key, Node *tree);
    Node *add_pair_inner(const A &key,const B &value, Node *tree);
    void delete_all(Node *tree);
public:
    CMap();
    ~CMap();

    /*!
     * \brief add_pair - добавление нового узла в дерево
     * \param key      - ключ
     * \param value    - значение
     */
    void add_pair(const A &key,const B &value);

=======

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

>>>>>>> 4ac85f01b16f65741dd1c39777f40c3d1ce81c29
    /*!
     * \brief search - поиск узла в дереве по ключу
     * \param target - искомый ключ
     * \return       - true если ключ найден
     */
<<<<<<< HEAD
    bool search(const A &key);
=======
    bool search(A &target);
>>>>>>> 4ac85f01b16f65741dd1c39777f40c3d1ce81c29

    /*!
     * \brief getValue - получение значения по ключу
     * \param target   - искомый ключ
     * \return         - значение
     */
<<<<<<< HEAD
    B &getValue(const A &key);
=======
    B &getValue(A &target);
>>>>>>> 4ac85f01b16f65741dd1c39777f40c3d1ce81c29

    /*!
     * \brief delete_key - удаление узла по ключу
     * \param target     - искомый ключ
     */
<<<<<<< HEAD
    void delete_key(const A &key);
=======
    void delete_key(A &target);

    B &operator=(B &value);
>>>>>>> 4ac85f01b16f65741dd1c39777f40c3d1ce81c29
};
#endif // MAP_H








