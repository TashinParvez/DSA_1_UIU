//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    18-08-23     *************************\

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl // NewLine
#define null NULL
using namespace std;

class node
{
public:
    int data;
    node *leftNode;
    node *rightNode;
    node(int data)
    {
        this->data = data;
        leftNode = NULL;
        rightNode = NULL;
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

void InOrderTraversal(node *root)
{
    if (root == null)
        return;
    InOrderTraversal(root->leftNode);
    cout << root->data << " ";
    InOrderTraversal(root->rightNode);
}

//************* basic Logic of In-Order *************
/*
// it also works

void InOrderTraversal(node *root)
{
    if (root->leftNode)                     // if leftNode != null --> (LPR call)
    {
        InOrderTraversal(root->leftNode);
    }

    cout << root->data << " ";             // it is printing all values

    if (root->rightNode)
    {
        InOrderTraversal(root->rightNode); // same as leftNode
    }
}

*/

int32_t main()
{
    node *root = NULL;

    // creating tree
    root = buildTree(root);

    // input:     1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1
    // In order:  4 2 5 1 3 6
    // Pre Order: 1 2 4 5 3 6

    // another input: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // Pre Order:     1 3 7 11 5 17

    // level order traversal

    cout << nl << "Inorder Traversal : ";
    InOrderTraversal(root);
    cout << nl;

    CRACKED;
}
