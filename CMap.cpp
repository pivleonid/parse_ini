#include "CMap.h"

template <typename A, typename B, typename C>
CMap<A, B, C>::CMap()
{
    root = NULL;
    m_count = 0;
}

template <typename A, typename B, typename C>
CMap<A, B, C>::~CMap()
{
    delete_all(root);
    root = NULL;
}

template <typename A, typename B, typename C>
void CMap<A, B, C>::delete_all(Node *cur_node)
{
    if(cur_node != NULL)
    {
        delete_all(cur_node->left);
        delete_all(cur_node->right);
        delete cur_node;
    }
}

template <typename A, typename B, typename C>
void CMap<A, B, C>::add_pair(const A &key, const B &value, const C &comment)
{
    //A temp_key = key;
    //B temp_value = value;
    root = add_pair_inner(key, value, comment, root);

}

template <typename A, typename B, typename C>
typename CMap<A, B, C>::Node * CMap<A, B, C>::add_pair_inner(const A &key,const B &value, const C &comment, Node *cur_node)
{
    if(cur_node == NULL)
    {
          cur_node          = new Node;
          cur_node->left    = NULL;
          cur_node->right   = NULL;
          cur_node->key     = key;
          cur_node->value   = value;
          cur_node->comment = comment;
          m_count++;
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
        cur_node->left = add_pair_inner(key, value, comment, cur_node->left);
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
        cur_node->right = add_pair_inner(key, value, comment, cur_node->right );
    }
    return cur_node;
}


template <typename A, typename B, typename C>
bool CMap<A, B, C>::search_inner(const A &key, Node *cur_node)
{
    bool found = false;
    if(cur_node->key == key)
    {
        found = true;
    }
    else
    {
        if(cur_node->left != 0 && found == false)
        {
            found = search_inner(key, cur_node->left);
        }
        if(cur_node->right != 0 && found == false)
        {
            found = search_inner(key, cur_node->right);
        }
    }
    return found;
}

template <typename A, typename B, typename C>
bool CMap<A, B, C>::search(const A &key)
{
      bool found = false;
      A temp_key = key;
      found = search_inner(key, root);
      return found;
}

template <typename A, typename B, typename C>
typename CMap<A, B, C>::Node * CMap<A, B, C>::getAdress(const A &key, Node *cur_node)
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
        }
    }
    return temp;
}

template <typename A, typename B, typename C>
typename CMap<A, B, C>::Node * CMap<A, B, C>::getAdressParent(Node *child, Node *cur_node)
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

template <typename A, typename B, typename C>
typename CMap<A, B, C>::Node * CMap<A, B, C>::search_replacing(Node *cur_node)
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

template <typename A, typename B, typename C>
void CMap<A, B, C>::delete_key(const A &key)
{
    //удаляемый элемент
    A temp_key = key;
    Node *deletable = getAdress(key, root);
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
    m_count--;

}

template <typename A, typename B, typename C>
B &CMap<A, B, C>::getValue(const A &key)
{
    Node *temp = getAdress(key, root);
    return temp->value;
}

template <typename A, typename B, typename C>
C &CMap<A, B, C>::getComment(const A &key)
{
    Node *temp = getAdress(key, root);
    return temp->comment;
}

template <typename A, typename B, typename C>
typename CMap<A, B, C>::Node * CMap<A, B, C>::operator_eq_inner(Node *new_map, Node *old_map)
{
    if(old_map != NULL)
    {
        new_map->left    = NULL;
        new_map->right   = NULL;
        new_map->key     = old_map->key;
        new_map->value   = old_map->value;
        new_map->comment = old_map->comment;
        m_count++;
    }
    if(old_map->left != NULL)
    {
        new_map->left = new Node;
        new_map->left = operator_eq_inner(new_map->left, old_map->left);
    }
    if(old_map->right != NULL)
    {
        new_map->right = new Node;
        new_map->right = operator_eq_inner(new_map->right, old_map->right);
    }
    return new_map;
}

template <typename A, typename B, typename C>
int CMap<A, B, C>::size()
{
   return m_count;
}


template <typename A, typename B, typename C>
CMap<A, B, C> &CMap<A, B, C>::operator=(const CMap &map)
{
    root = new Node;
    root = operator_eq_inner(root, map.root);
    return *this;
}
