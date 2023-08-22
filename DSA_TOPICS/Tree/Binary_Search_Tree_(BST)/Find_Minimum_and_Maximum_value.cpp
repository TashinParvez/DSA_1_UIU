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

//********  Iteratively  *********

int minimumOfTheTree(node *root)
{
    while (root->leftNode != null)
        root = root->leftNode;

    return root->data;
}

/* //******* Recursively *********

int minimumOfTheTree(node *root)
{
        if (root->leftNode == null)
            return root->data;
        else
            minimumOfTheTree(root->leftNode);
}

*/



//********  Iteratively  *********

int maximumOftheTree(node *root)
{
    while (root->rightNode != null)
        root = root->rightNode;

    return root->data;
}

/* //******* Recursively *********

    int maximumOftheTree(node *root)
    {
        if (root->leftNode == null)
            return root->data; 
        else
            maximumOftheTree(root->leftNode);
    }

*/

int32_t main()
{
    node *root = NULL;

    // creating tree
    root = buildTree(root);

    // input
    // 1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1

    CRACKED;
}
