#ifndef MAP_H
#define MAP_H
#include "CString.h"
#include "string"
#include "cstring"
#include <iostream>
using namespace std;
struct Node
{
    const char  *str;
    Node        *left;
    Node        *right;
};
class Map
{
private:
    Node *root;
    bool find;
    Node *key;
public:
    Map();
    ~Map();
    void add(CString &str);
    Node *add(const char *new_str, Node *tree);
    void walk(const char *target, Node *tree);
    bool search(const char *target);
    void delete_elem(Node *tree);
};
#endif // MAP_H
