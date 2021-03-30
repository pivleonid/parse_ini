#include "CMap.h"

Map::Map()
{
    root  = NULL;
}

Map::~Map()
{
    delete_all(root);
}

void Map::delete_all(Node *tree)
{
    if(tree != NULL)
    {
        delete_all(tree->left);
        delete_all(tree->right);
        delete tree;
    }
}

void Map::add_pair(CString &key, CString &str)
{
    root = add_pair(key, str, root);
}

Node* Map::add_pair(CString & key, CString &str, Node *tree)
{
    if(tree == NULL)
    {
          tree        = new Node;
          tree->left  = NULL;
          tree->right = NULL;
          tree->key   = key;
          tree->value = str;
    }
    const char *value_tree = tree->value.data();
    const char *value_new = str.data();
    const char *key_tree = tree->key.data();
    const char *key_new = key.data();
    if(strcmp(key_tree, key_new) == 0)
    {
        if(strcmp(value_tree, value_new) != 0)
        {
            tree->value = str;
        }
    }
    else if(strcmp(value_tree, value_new) > 0)
    {
        if(strcmp(key_tree, key_new) == 0)
        {
            tree->value = str;
        }
        tree->left = add_pair(key, str, tree->left);
    }
    else if(strcmp(value_tree, value_new) < 0)
    {
        if(strcmp(key_tree, key_new) == 0)
        {
            tree->value = str;
        }
        tree->right = add_pair(key, str,  tree->right );
    }


    return tree;
}


bool Map::find(CString& target, Node *tree)
{
    const char *temp0 = target.data();
    const char *temp1 = tree->key.data();
    bool found = false;

    if(strcmp(temp0, temp1) == 0)
    {
        found = true;
    }
    else
    {
        if(tree->left != 0 && found == false)
        {
            found = find(target, tree->left);
        }
        if(tree->right != 0 && found == false)
        {
            found = find(target, tree->right);
        }
    }

    return found;
}

bool Map::search(CString &target)
{
      bool found = false;
      found = find(target, root);
      return found;
}

Node* Map::getAdress(CString &target, Node *tree)
{

    const char *temp0 = target.data();
    const char *temp1 = tree->key.data();
    Node *temp = NULL;
    if(strcmp(temp0, temp1) == 0)
    {
        temp = tree;
    }
    if(strcmp(temp0, temp1) != 0)
    {
        if(tree->left != 0 && temp == NULL)
        {
            temp = getAdress(target, tree->left);
        }
        if(tree->right != 0 && temp == NULL)
        {
            temp = getAdress(target, tree->right);
        }
    }
    return temp;
}

Node* Map::getAdressParent(Node *child, Node *tree)
{
    Node *temp = NULL;
    if(tree->left == child || tree->right == child)
    {
        temp = tree;
    }
    else if(tree->left != child || tree->right != child)
    {
        if(tree->left != 0 && temp == NULL)
        {
            temp = getAdressParent(child, tree->left);
        }
        if(tree->right != 0 && temp == NULL)
        {
            temp = getAdressParent(child, tree->right);
        }
    }
    return temp;
}

Node *Map::search_replacing(Node *tree)
{
    Node *temp = NULL;
    if(tree->right != 0 && temp == NULL)
    {
        temp = search_replacing(tree->right);
    }
    if(tree->right == 0)
    {
        temp = tree;
    }
    return temp;
}

Node* Map::delete_key(CString &target)
{
    Node *adress = getAdress(target, root);
    Node *parent = getAdressParent(adress, root);
    //если удаляемый элемент не имеет дочерних узлов
    if(adress->left == NULL && adress->right == NULL)
    {
        delete adress;
        if(parent->left == adress)
        {
            parent->left = NULL;
        }
        else if(parent->right == adress)
        {
            parent->right = NULL;
        }
    }
    //если удаляемый элемент имеет только левый дочерний узел
    else if(adress->left != NULL && adress->right == NULL)
    {
        if(parent->left == adress)
        {
            parent->left = adress->left;
        }
        else if(parent->right == adress)
        {
            parent->right = adress->right;
        }
        delete adress;
    }
    //если удаляемый элемент имеет только правый дочерний узел
    else if(adress->left == NULL && adress->right != NULL)
    {
        if(parent->left == adress)
        {
            parent->left = adress->left;
        }
        else if(parent->right == adress)
        {
            parent->right = adress->right;
        }
        delete adress;
    }

    //если удаляемый элемент имеет оба дочерних узла
    else if(adress->left != NULL && adress->right != NULL)
    {
        //ищем элемент для замены
        Node *temp  = search_replacing(adress->left);
        //если у найденного элемента есть дочерний узел слева
        //записываем его
        Node *temp1 = temp->left;
        //записываем адрес родителя этого элемента
        Node *temp2 = getAdressParent(temp, root);
        //производим замену
        if(adress == parent->left)
        {
            parent->left = temp;
        }
        if(adress == parent->right)
        {
            parent->right = temp;
        }
        if(adress->left != temp)
        {
            temp->left = adress->left;
        }
        if(adress->right != temp)
        {
            temp->right = adress->right;
        }

        if(temp2 != adress)
        {
            temp2->right = temp1;
        }

        delete adress;
    }
    return adress;
}



