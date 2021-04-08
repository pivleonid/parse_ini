#include "CMap.h"

template <typename A, typename B>
Map<A, B>::Map()
{
    root = NULL;
}

template <typename A, typename B>
Map<A, B>::~Map()
{
    delete_all(root);
}

template <typename A, typename B>
void Map<A, B>::delete_all(Node *cur_node)
{
    if(cur_node != NULL)
    {
        delete_all(cur_node->left);
        delete_all(cur_node->right);
        delete cur_node;
    }
}

template <typename A, typename B>
void Map<A, B>::add_pair(A &key,const B &value)
{
    A temp_key = key;
    B temp_value = value;
    root = add_pair_inner(key, value, root);

}

template <typename A, typename B>
typename Map<A, B>::Node * Map<A, B>::add_pair_inner(A & key,const B &value, Node *cur_node)
{
    if(cur_node == NULL)
    {
          cur_node        = new Node;
          cur_node->left  = NULL;
          cur_node->right = NULL;
          cur_node->key   = key;
          cur_node->value = value;
    }
    //если данный ключ уже есть в дереве
    if(cur_node->key == key)
    {
        //если для этого ключа введено другое значение
        if(cur_node->value != value)
        {
            //то меняем значение для этого ключа
            cur_node->value = value;
        }
    }
    //в противном случае идём дальше по дереву
    else if(cur_node->value > value)
    {
        //если данный ключ уже есть в дереве
        if(cur_node->key == key)
        {
            //то меняем значение для этого ключа
            cur_node->value = value;
        }
        cur_node->left = add_pair_inner(key, value, cur_node->left);
    }
    //в противном случае идём дальше по дереву
    else if(cur_node->value < value)
    {
        //если данный ключ уже есть в дереве
        if(cur_node->key == key)
        {
            //то меняем значение для этого ключа
            cur_node->value = value;
        }
        cur_node->right = add_pair_inner(key, value,  cur_node->right );
    }
    return cur_node;
}


template <typename A, typename B>
bool Map<A, B>::search_inner(A &target, Node *cur_node)
{
    bool found = false;
    if(cur_node->key == target)
    {
        found = true;
    }
    else
    {
        if(cur_node->left != 0 && found == false)
        {
            found = search_inner(target, cur_node->left);
        }
        if(cur_node->right != 0 && found == false)
        {
            found = search_inner(target, cur_node->right);
        }
    }
    return found;
}

template <typename A, typename B>
bool Map<A, B>::search(A &target)
{
      bool found = false;
      A temp_target = target;
      found = search_inner(target, root);
      return found;
}

template <typename A, typename B>
typename Map<A, B>::Node * Map<A, B>::getAdress(A &target, Node *cur_node)
{
    Node *temp = NULL;
    if(cur_node->key == target)
    {
        temp = cur_node;
    }
    if(cur_node->key != target)
    {
        if(cur_node->left != 0 && temp == NULL)
        {
            temp = getAdress(target, cur_node->left);
        }
        if(cur_node->right != 0 && temp == NULL)
        {
            temp = getAdress(target, cur_node->right);
        }
    }
    return temp;
}

template <typename A, typename B>
typename Map<A, B>::Node * Map<A, B>::getAdressParent(Node *child, Node *cur_node)
{
    Node *temp = NULL;
    if(cur_node->left == child || cur_node->right == child)
    {
        temp = cur_node;
    }
    else if(cur_node->left != child || cur_node->right != child)
    {
        if(cur_node->left != 0 && temp == NULL)
        {
            temp = getAdressParent(child, cur_node->left);
        }
        if(cur_node->right != 0 && temp == NULL)
        {
            temp = getAdressParent(child, cur_node->right);
        }
    }
    return temp;
}

template <typename A, typename B>
typename Map<A, B>::Node * Map<A, B>::search_replacing(Node *cur_node)
{
    Node *temp = NULL;
    if(cur_node->right != 0 && temp == NULL)
    {
        temp = search_replacing(cur_node->right);
    }
    if(cur_node->right == 0)
    {
        temp = cur_node;
    }
    return temp;
}

template <typename A, typename B>
void Map<A, B>::delete_key(A &target)
{
    //удаляемый элемент
    A temp_target = target;
    Node *deletable = getAdress(target, root);
    //его родитель
    Node *parent = getAdressParent(deletable, root);
    //если удаляемый элемент не имеет родителя(является корнем дерева)
    if(parent == NULL)
    {
        //если удаляемый элемент не имеет дочерних узлов
        if(deletable->left == NULL && deletable->right == NULL)
        {
            delete deletable;
            root = NULL;
        }
        //если удаляемый элемент имеет только левый дочерний узел
        else if(deletable->left != NULL && deletable->right == NULL)
        {
            root = deletable->left;
            delete deletable;
        }
        //если удаляемый элемент имеет только правый дочерний узел
        else if(deletable->left == NULL && deletable->right != NULL)
        {
            root = deletable->right;
            delete deletable;
        }
        //если удаляемый элемент имеет оба дочерних узла
        else if(deletable->left != NULL && deletable->right != NULL)
        {
            //ищем элемент для замены
            Node *replacing  = search_replacing(deletable->left);
            //если у найденного элемента есть дочерний узел слева
            //записываем его
            Node *replacing_child = replacing->left;
            //записываем адрес родителя этого элемента
            Node *replacing_parent = getAdressParent(replacing, root);
            //производим замену
            //если элемент найденный для замены элемент не является левым дочерним узлом
            //удаляемого элемента
            if(deletable->left != replacing)
            {
                replacing->left = deletable->left;
            }
            //если элемент найденный для замены элемент не является правым дочерним узлом
            //удаляемого элемента
            if(deletable->right != replacing)
            {
                replacing->right = deletable->right;
            }

            //если у элемента выбранного в качестве замены есть потомок слева
            //то он становится дочерним узлом родителя элемента-замены
            if(replacing_parent != deletable)
            {
                replacing_parent->right = replacing_child;
            }
            root = replacing;
            delete deletable;
        }

    }
    //если у удаляемого элемента есть родитель(не является корнем дерева)
    else if(parent != NULL)
    {
        //если удаляемый элемент не имеет дочерних узлов
        if(deletable->left == NULL && deletable->right == NULL)
        {
            delete deletable;
            if(parent->left == deletable)
            {
                parent->left = NULL;
            }
            else if(parent->right == deletable)
            {
                parent->right = NULL;
            }
        }
        //если удаляемый элемент имеет только левый дочерний узел
        else if(deletable->left != NULL && deletable->right == NULL)
        {
            if(parent->left == deletable)
            {
                parent->left = deletable->left;
            }
            else if(parent->right == deletable)
            {
                parent->right = deletable->right;
            }
            delete deletable;
        }
        //если удаляемый элемент имеет только правый дочерний узел
        else if(deletable->left == NULL && deletable->right != NULL)
        {
            if(parent->left == deletable)
            {
                parent->left = deletable->left;
            }
            else if(parent->right == deletable)
            {
                parent->right = deletable->right;
            }
            delete deletable;
        }
        //если удаляемый элемент имеет оба дочерних узла
        else if(deletable->left != NULL && deletable->right != NULL)
        {
            //ищем элемент для замены
            Node *replacing  = search_replacing(deletable->left);
            //если у найденного элемента есть дочерний узел слева
            //записываем его
            Node *replacing_child = replacing->left;
            //записываем адрес родителя этого элемента
            Node *replacing_parent = getAdressParent(replacing, root);
            //производим замену
            //если удаляемый элемент является левым дочерним узлом
            if(deletable == parent->left)
            {
                parent->left = replacing;
            }
            //если удаляемый элемент является правым дочерним узлом
            if(deletable == parent->right)
            {
                parent->right = replacing;
            }
            //если элемент найденный для замены элемент не является левым дочерним узлом
            //удаляемого элемента
            if(deletable->left != replacing)
            {
                replacing->left = deletable->left;
            }
            //если элемент найденный для замены элемент не является правым дочерним узлом
            //удаляемого элемента
            if(deletable->right != replacing)
            {
                replacing->right = deletable->right;
            }
            //если у элемента выбранного в качестве замены есть потомок слева
            //то он становится дочерним узлом родителя элемента-замены
            if(replacing_parent != deletable)
            {
                replacing_parent->right = replacing_child;
            }
            delete deletable;
        }
    }

}

template <typename A, typename B>
B & Map<A, B>::getValue(A &target)
{
    Node *temp = getAdress(target, root);
    return temp->value;
}

