#ifndef TREE_ABL_H
#define TREE_ABL_H

#include <iostream>
using namespace std;

class tree_ABL
{
private:
    struct node
    {
        int   info;
        node* left;
        node* right;
        int   balance; //высота правого поддерева- высота левого поддерева
    };
    node* root;
public:
    tree_ABL() { root = nullptr; }

    void insert(int d);
    bool  find(int d)
    {
        if(root == nullptr)
            return false;
        cout << "root->info = " << root->info << endl;
        if( root->info == d)
            return true;
        if(d < root->info )
        {
            return find(root->left, d);
        }
        if( d > root->info )
        {
            return find(root->right, d);
        }
        return true;
    }
    bool find(node* (&root_node), int d)
    {
        if(root_node == nullptr)
            return false;
        cout << "node->info = " << root_node->info << endl;
        if( root_node->info == d)
            return true;
        if(  d < root_node->info)
        {
            return find(root_node->left, d);
        }
        if( d > root_node->info)
        {
            return find(root_node->right, d);
        }

    }

    node* findmin(node* p) // поиск узла с минимальным ключом в дереве p
    {
        return p->left?findmin(p->left):p;
    }

    void Clear();

    void output();
    //распечатка дерева по уровням
    void print( );

private:

    void insert(node* (&root),int d);
    void Clear(node** p);
    void output(node* p); // симметричный порядок
    void print( node* p);
    //печать n уровня
    void print_n(const node* p, int n, int level, int prob);

    int Height(node* root);

    void SetBalance(node* (&root));
    /*
                  root
                /       \
            leftSubtree  XXX
           / \
          XX   leftSubtreeRightSubtree
         /
        X

        Станет

                        leftSubtree
                        /         \
                    XX                root
                /                  /              \
               X         leftSubtreeRightSubtree  XXX
     */
    void TurnRight(node* (&root));

    void TurnLeft(node* (&root));
};















#endif // TREE_ABL_H
