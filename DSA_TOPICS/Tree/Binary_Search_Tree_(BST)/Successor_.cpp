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

node *minimumOfTheTree(node *root)
{
    while (root->leftNode != null)
        root = root->leftNode;

    return root;
}

node *successor(node *ptr)
{
    // case 1:
    // have right child
    if (ptr->rightNode != null)
    {
        return minimumOfTheTree(ptr->rightNode);
    }

    // case 2:
    // have no roght child
    else
    {
        /****  My logic not checked yet *****/
        // node *traveller = ptr->parent;
        // while (traveller->data <= ptr->data)
        // {
        //     traveller = traveller->parent;
        // }
        // return traveller;

        node *traveller = ptr->parent;
        while (traveller != null && traveller->rightNode == ptr)
        {
            ptr = traveller;
            traveller = ptr->parent;
        }

        return traveller;
    }
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
