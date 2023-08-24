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

node *maximumOfatree(node *root)
{
    while (root->rightNode != null)
        root = root->rightNode;

    return root;
}

// from left to parent means  = choto theke boro-te jaowa
// from right to parent means = boro theke choto-te jaowa 

node *predecessor(node *ptr)
{
    if (ptr->leftNode)
    {
        return maximumOfatree(ptr->leftNode);
    }
    else
    {
        // my logic *** not checked yet
        /*
            node *parent = ptr->parent;
             while (parent != null && parent->data > ptr->data)
             {
                 parent = parent->parent;
             }
            return parent;
        */

        node *traveller = ptr->parent;
        while (traveller != null && traveller == traveller->parent->leftNode)
        {
            traveller = traveller->parent;
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
