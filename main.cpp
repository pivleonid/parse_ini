#include <iostream>
#include <CString.h>
#include <CVector.h>
#include <tree_abl.h>
#include <gtest/include/gtest/gtest.h>

using namespace std;
TEST(test001, test_at)
{
    CString a = "something";
    char b = a.at(4);
    ASSERT_EQ('t', b);
    char c = a.at(100);
    ASSERT_EQ('\0', c);
    char d = a.at(-10);
    ASSERT_EQ('\0', d);
    a.at(5) = 'z';
    char e = a.at(5);
    ASSERT_EQ('z', e);
    a.at(90) = 'x';
    char f = a.at(90);
    ASSERT_EQ('\0', f);
    a.at(-1) = 'r';
    char g = a.at(-1);
    ASSERT_EQ('\0', g);
}


struct node
{
    int   info;
    node* left;
    node* right;
    int   balance; //высота правого поддерева- высота левого поддерева
};

int Height(node* root)
{
    if(root == nullptr)
        return 0;
    int hLeft  = Height(root->left);
    int hRight = Height(root->right);

    if(hLeft > hRight)
        return hLeft + 1;
    return hRight + 1;
}

void SetBalance(node* (&root))
{
    if(root != nullptr)
        root->balance = Height(root->right) - Height(root->left);
}
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
                    /                \
                XX                  root
            /                  /              \
           X         leftSubtreeRightSubtree  XXX
 */
void TurnRight(node* (&root))
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

void TurnLeft(node* (&root))
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

void insert(node* (&root), int d)
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

void Clear(node** p)
{
    if((*p) != nullptr)
    {
        Clear(&(*p)->left);
        Clear(&(*p)->right);

        delete* p;
        *p == nullptr;
    }
}

void output(node* p) // симметричный порядок
{
    if( p != nullptr )
    {
        output(p->left);
        cout << p->info << " ";
        output(p->right);
    }
}

//печать n уровня
void print_n(const node* p, int n, int level, int prob)
{
    if(p)
    {
        if(level == n)
        {
            for(int i = 1; i <= prob; i++)
                cout << " ";
            cout << p->info;
        }
        else
        {
            print_n(p->left, n, level + 1, prob);
            print_n(p->right, n, level + 1, prob);
        }
    }
}
//распечатка дерева по уровням
void print( node* p)
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

int main(int argc, char* argv[])
{

    node* root;
    root = nullptr;
    insert(root, 500);

    for(int i = 0 ; i < 20; i++)
    {
        int d;
        cin >> d;
        insert(root, d);
    }
    output(root);
    cout << endl;

    print(root);
    Clear(&root);

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    return 0;
}
