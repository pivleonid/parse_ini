#include "CMap.h"

template <typename A, typename B>
<<<<<<< HEAD
CMap<A, B>::CMap()
=======
Map<A, B>::Map()
>>>>>>> 4ac85f01b16f65741dd1c39777f40c3d1ce81c29
{
    root = NULL;
}

template <typename A, typename B>
<<<<<<< HEAD
CMap<A, B>::~CMap()
=======
Map<A, B>::~Map()
>>>>>>> 4ac85f01b16f65741dd1c39777f40c3d1ce81c29
{
    delete_all(root);
}
<<<<<<< HEAD

<<<<<<< HEAD
template <typename A, typename B>
void CMap<A, B>::delete_all(Node *cur_node)
=======
=======
>>>>>>> dc63914f833218594477c9811b624317339d19a4
template <typename A, typename B>
void Map<A, B>::delete_all(Node *cur_node)
>>>>>>> 4ac85f01b16f65741dd1c39777f40c3d1ce81c29
{
    if(cur_node != NULL)
    {
        delete_all(cur_node->left);
        delete_all(cur_node->right);
        delete cur_node;
    }
}

template <typename A, typename B>
<<<<<<< HEAD
void CMap<A, B>::add_pair(const A &key,const B &value)
{
    //A temp_key = key;
    //B temp_value = value;
=======
<<<<<<< HEAD
void Map<A, B>::add_pair(A &key,const B &value)
=======
void Map<A, B>::add_pair(A &key, B &value)
>>>>>>> dc63914f833218594477c9811b624317339d19a4
{
    A temp_key = key;
    B temp_value = value;
>>>>>>> 4ac85f01b16f65741dd1c39777f40c3d1ce81c29
    root = add_pair_inner(key, value, root);

}

template <typename A, typename B>
<<<<<<< HEAD
typename CMap<A, B>::Node * CMap<A, B>::add_pair_inner(const A &key,const B &value, Node *cur_node)
=======
<<<<<<< HEAD
typename Map<A, B>::Node * Map<A, B>::add_pair_inner(A & key,const B &value, Node *cur_node)
=======
typename Map<A, B>::Node * Map<A, B>::add_pair_inner(A & key, B &value, Node * cur_node)
>>>>>>> dc63914f833218594477c9811b624317339d19a4
>>>>>>> 4ac85f01b16f65741dd1c39777f40c3d1ce81c29
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
<<<<<<< HEAD
bool CMap<A, B>::search_inner(const A &key, Node *cur_node)
{
    bool found = false;
    if(cur_node->key == key)
=======
<<<<<<< HEAD
bool Map<A, B>::search_inner(A &target, Node *cur_node)
=======
bool Map<A, B>::search_inner(A & target, Node * cur_node)
>>>>>>> dc63914f833218594477c9811b624317339d19a4
{
    bool found = false;
    if(cur_node->key == target)
>>>>>>> 4ac85f01b16f65741dd1c39777f40c3d1ce81c29
    {
        found = true;
    }
    else
    {
        if(cur_node->left != 0 && found == false)
        {
<<<<<<< HEAD
            found = search_inner(key, cur_node->left);
        }
        if(cur_node->right != 0 && found == false)
        {
            found = search_inner(key, cur_node->right);
=======
            found = search_inner(target, cur_node->left);
        }
        if(cur_node->right != 0 && found == false)
        {
            found = search_inner(target, cur_node->right);
>>>>>>> 4ac85f01b16f65741dd1c39777f40c3d1ce81c29
        }
    }
    return found;
}

template <typename A, typename B>
<<<<<<< HEAD
bool CMap<A, B>::search(const A &key)
{
      bool found = false;
      A temp_key = key;
      found = search_inner(key, root);
=======
<<<<<<< HEAD
bool Map<A, B>::search(A &target)
=======
bool Map<A, B>::search(A & target)
>>>>>>> dc63914f833218594477c9811b624317339d19a4
{
      bool found = false;
      A temp_target = target;
      found = search_inner(target, root);
>>>>>>> 4ac85f01b16f65741dd1c39777f40c3d1ce81c29
      return found;
}

template <typename A, typename B>
<<<<<<< HEAD
typename CMap<A, B>::Node * CMap<A, B>::getAdress(const A &key, Node *cur_node)
{
    Node *temp = NULL;
    if(cur_node->key == key)
    {
        temp = cur_node;
    }
    if(cur_node->key != key)
    {
        if(cur_node->left != 0 && temp == NULL)
        {
            temp = getAdress(key, cur_node->left);
        }
        if(cur_node->right != 0 && temp == NULL)
        {
            temp = getAdress(key, cur_node->right);
=======
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
>>>>>>> 4ac85f01b16f65741dd1c39777f40c3d1ce81c29
        }
    }
    return temp;
}

template <typename A, typename B>
<<<<<<< HEAD
typename CMap<A, B>::Node * CMap<A, B>::getAdressParent(Node *child, Node *cur_node)
=======
typename Map<A, B>::Node * Map<A, B>::getAdressParent(Node *child, Node *cur_node)
>>>>>>> 4ac85f01b16f65741dd1c39777f40c3d1ce81c29
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
<<<<<<< HEAD
typename CMap<A, B>::Node * CMap<A, B>::search_replacing(Node *cur_node)
=======
typename Map<A, B>::Node * Map<A, B>::search_replacing(Node *cur_node)
>>>>>>> 4ac85f01b16f65741dd1c39777f40c3d1ce81c29
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
<<<<<<< HEAD
void CMap<A, B>::delete_key(const A &key)
{
    //удаляемый элемент
    A temp_key = key;
    Node *deletable = getAdress(key, root);
=======
void Map<A, B>::delete_key(A &target)
{
    //удаляемый элемент
    A temp_target = target;
    Node *deletable = getAdress(target, root);
>>>>>>> 4ac85f01b16f65741dd1c39777f40c3d1ce81c29
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
<<<<<<< HEAD
        {
            root = deletable->right;
            delete deletable;
        }
        //если удаляемый элемент имеет оба дочерних узла
        else if(deletable->left != NULL && deletable->right != NULL)
        {
=======
<<<<<<< HEAD
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
>>>>>>> 4ac85f01b16f65741dd1c39777f40c3d1ce81c29
            //ищем элемент для замены
            Node *replacing  = search_replacing(deletable->left);
            //если у найденного элемента есть дочерний узел слева
            //записываем его
            Node *replacing_child = replacing->left;
            //записываем адрес родителя этого элемента
            Node *replacing_parent = getAdressParent(replacing, root);
            //производим замену
<<<<<<< HEAD
=======
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
>>>>>>> 4ac85f01b16f65741dd1c39777f40c3d1ce81c29
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
<<<<<<< HEAD

=======
>>>>>>> 4ac85f01b16f65741dd1c39777f40c3d1ce81c29
            //если у элемента выбранного в качестве замены есть потомок слева
            //то он становится дочерним узлом родителя элемента-замены
            if(replacing_parent != deletable)
            {
                replacing_parent->right = replacing_child;
            }
<<<<<<< HEAD
            root = replacing;
            delete deletable;
        }

=======
            delete deletable;
        }
    }
=======
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

>>>>>>> 4ac85f01b16f65741dd1c39777f40c3d1ce81c29
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
<<<<<<< HEAD
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
=======
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

/*CString Map::getValue(CString &target, Node *tree)
{
    const char *key_tree = target.data();
    const char *key_search = tree->key.data();

    CString temp_str;
    if(strcmp(key_tree, key_search) == 0)
    {
        temp_str = tree->value;
    }
    else
    {
        if(tree->left != 0 && temp_str.empty())
        {
            temp_str = getValue(target, tree->left);
        }
        if(tree->right != 0 && temp_str.empty())
        {
            temp_str = getValue(target, tree->right);
        }
    }
    return temp_str;
}*/

/*template <typename A, typename B>
typename Map<A, B>::Node B & Node<A, B>::getValue(A &target)
{
    int temp;
    //temp = getValue(target, root);
    return temp;
}*/
>>>>>>> dc63914f833218594477c9811b624317339d19a4

}

template <typename A, typename B>
B & Map<A, B>::getValue(A &target)
{
    Node *temp = getAdress(target, root);
    return temp->value;
}
>>>>>>> 4ac85f01b16f65741dd1c39777f40c3d1ce81c29

template <typename A, typename B>
B &CMap<A, B>::getValue(const A &key)
{
    Node *temp = getAdress(key, root);
    return temp->value;
}
