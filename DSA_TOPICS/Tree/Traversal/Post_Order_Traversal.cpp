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

void postOrderTraversal(node *root)
{
    if (root == null)
        return;
    postOrderTraversal(root->leftNode);
    postOrderTraversal(root->rightNode);
    cout << root->data << " ";
}
 
int32_t main()
{
    node *root = NULL;

    // creating tree
    root = buildTree(root);

    // input:     1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1
    // In order:  4 2 5 1 3 6
    // Pre Order: 1 2 4 5 3 6
    // postOrder: 4 5 2 6 3 1

    // another input: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // Pre Order:     1 3 7 11 5 17

    // level order traversal

    cout << nl << "Pre-Order Traversal : ";
    postOrderTraversal(root);
    cout << nl;

    CRACKED;
}
