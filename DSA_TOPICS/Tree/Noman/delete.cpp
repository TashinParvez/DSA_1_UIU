//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    18-08-23     *************************\

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl // NewLine
#define null NULL
using namespace std;

int32_t main()
{

    CRACKED;
}

/*

node* Delete(node* root, node* keyNode)
{
    if(keyNode->left == NULL)
    {
        if(keyNode->parent == NULL)
            root = keyNode->right; 
        else
            transplant(keyNode, keyNode->right);
    }
    else if(keyNode->right == NULL)
    {
        if(keyNode->parent == NULL)
            root = keyNode->left;
        else
          transplant(keyNode, keyNode->left);
    }
    else
    {
        node* successorNode = successor(keyNode->right); // successor

        if(keyNode->parent == NULL)
            root = successorNode;

        if(successorNode == keyNode->right)
        {
            transplant(keyNode, successorNode);

            successorNode->left = keyNode->left;
            successorNode->left->parent = successorNode;
        }
        else
        {
            transplant(successorNode, successorNode->right);

            successorNode->left = keyNode->left;
            successorNode->left->parent = successorNode;

            successorNode->right = keyNode->right;
            successorNode->right->parent = successorNode;
        }
    }
    free(keyNode);
    return root;
}



*/