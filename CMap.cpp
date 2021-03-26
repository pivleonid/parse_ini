#include "CMap.h"

Map::Map()
{
    root  = NULL;
    find  = false;
    key   = NULL;
}

Map::~Map()
{
    delete_elem(root);
}

void Map::delete_elem(Node *tree)
{
    if(tree != NULL)
    {
        delete_elem(tree->left);
        delete_elem(tree->right);
        delete tree;
    }
}

void Map::add(CString &str)
{
    const char *new_str = str.data();
    root = add(new_str, root);
}

Node *Map::add(const char *new_str, Node *tree)
{
    if(tree == NULL)
    {
        tree        = new Node;
        tree->str = new_str;
        tree->left  = NULL;
        tree->right = NULL;
    }
    else if(strcmp(tree->str, new_str) == 0)
    {
        cout << "The strings can't coincide !" << endl;
    }
    else if(strcmp(tree->str, new_str) > 0)
    {
        tree->left = add(new_str, tree->left);
    }
    else if(strcmp(tree->str, new_str) < 0)
    {
        tree->right = add(new_str, tree->right);
    }
    return tree;
}

void Map::walk(const char *target, Node *tree)
{
    if(strcmp(tree->str, target) != 0)
    {
        if(tree->left != NULL)
        {
            walk(target, tree->left);
        }
        if(tree->right != NULL)
        {
            walk(target, tree->right);
        }
    }
    else
    {
        find = true;
    }
}

bool Map::search(const char *target)
{
    find = false;
    walk(target, root);
    return find;
}








