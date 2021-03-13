#include "tree_abl.h"


void tree_ABL::insert(CString d)
{
    insert(root, d);
}

void tree_ABL::insert(node* (&root),CString d)
{
    if(root == nullptr)
    {
        root = new node;
        root->info = d;
        root->balance = 0;
        root->left = nullptr;
        root->right = nullptr;
    }
    else
    {
        if( d > root->info )
        {
            insert(root->right, d);
            //Если баланс нарушен - выполняем вращение
            if( Height(root->right) - Height(root->left) > 1 )
            {
                if(Height(root->right->right) < Height(root->right->left))
                    TurnRight(root->right);
                TurnLeft(root);
            }
        }
        else
            if( d < root->info )
            {
                insert(root->left, d);
                if(Height(root->left)-Height(root->right) > 1)
                {
                    if(Height(root->left->left) < Height(root->left->right))
                        TurnLeft(root->left);
                    TurnRight(root);
                }
            }
        SetBalance(root);
    }
}

void tree_ABL::Clear()
{
    Clear(&root);
}
void tree_ABL::Clear(node** p)
{
    if((*p) != nullptr)
    {
        Clear(&(*p)->left);
        Clear(&(*p)->right);

        delete* p;
        *p = nullptr;
    }
}
void tree_ABL::output()
{
    cout << root->info.data() << endl;
    output(root);
}
void tree_ABL::output(node* p) // симметричный порядок
{
    if( p != nullptr )
    {
        output(p->left);
        cout << p->info.data() << " ";
        output(p->right);
    }
}

//печать n уровня
void tree_ABL::print_n( node* p, int n, int level, int prob)
{
    if(p)
    {
        if(level == n)
        {
            for(int i = 1; i <= prob; i++)
                cout << " ";
            cout << p->info.data();
        }
        else
        {
            print_n(p->left, n, level + 1, prob);
            print_n(p->right, n, level + 1, prob);
        }
    }
}
//распечатка дерева по уровням
void tree_ABL::print( )
{
   print(root);
}
void tree_ABL::print( node* p)
{
    int h = Height(p);
    int prob = 3;
    if(p)
    {
        for(int i = 0; i <= h; i++)
        {
            print_n(p,i,0, prob*(h-i));
            cout << endl;
        }
    }
}

int tree_ABL::Height(node* root)
{
    if(root == nullptr)
        return 0;
    int hLeft  = Height(root->left);
    int hRight = Height(root->right);

    if(hLeft > hRight)
        return hLeft + 1;
    return hRight + 1;
}

void tree_ABL::SetBalance(node* (&root))
{
    if(root != nullptr)
        root->balance = Height(root->right) - Height(root->left);
}

void tree_ABL::TurnRight(node* (&root))
{
    node* leftSubtree;
    node* leftSubtreeRightSubtree; //правое поддерево для левого
    leftSubtree = root->left;
    leftSubtreeRightSubtree = leftSubtree->right;

    leftSubtree->right = root;
    root->left = leftSubtreeRightSubtree;
    root = leftSubtree;

    SetBalance(root->right);
    SetBalance(root);
}

void tree_ABL::TurnLeft(node* (&root))
{
    node* rightSubtree;
    node* rightSubtreeLeftSubtree; //правое поддерево для левого
    rightSubtree = root->right;
    rightSubtreeLeftSubtree = rightSubtree->left;

    rightSubtree->left = root;
    root->right = rightSubtreeLeftSubtree;
    root = rightSubtree;

    SetBalance(root->left);
    SetBalance(root);
}
