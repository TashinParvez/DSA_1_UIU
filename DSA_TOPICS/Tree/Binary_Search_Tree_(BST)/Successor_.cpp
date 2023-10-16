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

node *minimumOfTheTree(node *root)
{
    while (root->leftNode != null)
        root = root->leftNode;

    return root;
}

// from left to parent means  = choto theke boro-te jaowa
// from right to parent means = boro theke choto-te jaowa

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
        /****  My logic *****/
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

    // input
    // 1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1

    CRACKED;
}
