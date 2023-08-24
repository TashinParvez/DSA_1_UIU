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

node *buildTree(int pre[], int in[], int index)
{
    node *root = new node(pre[index]);
    index++;
    root->leftNode = buildTree();
    root->rightNode = buildTree();

    return root;
}

int32_t main()
{
    node *root = NULL;

    CRACKED;
}
