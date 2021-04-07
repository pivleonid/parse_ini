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

    Node *search_replacing(Node *tree);


    bool search_inner(A &target, Node *tree);
    //B &getValue(A &key, Node *tree);
    Node * add_pair_inner(A &key, B &value, Node *tree);
    void delete_all(Node *tree);
public:
    Map();
    ~Map();
    void add_pair(A &key, B &value);
    bool search(A &target);
    //Есть ли такой ключ
    B &getValue(A &target);
    void delete_key(A &target);

};
#endif // MAP_H
