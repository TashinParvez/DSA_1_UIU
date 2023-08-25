//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    22-06-23     *************************\

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl; // NewLine
#define null NULL
using namespace std;

class node
{
public:
    int data;
    node *leftNode;
    node *rightNode;
    node *parent;
    node(int data)
    {
        this->data = data;
        leftNode = NULL;
        rightNode = NULL;
        parent = NULL;
    }
};

node *buildTree(node *root)
{
    cout << "Enter the value of root: ";
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter  left child of " << data << " " << nl;
    root->leftNode = buildTree(root->leftNode);

    cout << "Enter  right child of " << data << " " << nl;
    root->rightNode = buildTree(root->rightNode);

    return root;
}

node *transplant(node *root, node *u, node *v)
{
    if (u->parent->leftNode == u)
    {
        u->parent->leftNode = v;
        v->parent = u->parent;
    }
    else if (u->parent->rightNode == u)
    {
        u->parent->rightNode = v;
        v->parent = u->parent;
    }
    else
        root = v;
    return v;
}

int32_t main()
{
    node *root = NULL;

    // creating tree
    root = buildTree(root);

    // input
    // 1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1

    CRACKED;
}
