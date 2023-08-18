//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    18-08-23     *************************\

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl; // NewLine
#define null NULL
using namespace std;

typedef struct Node
{
    int data;
    struct Node *leftNode;
    struct Node *rightNode;
} node;

node *insert(node *&root, int key)
{
    node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->leftNode = null;
    newNode->rightNode = null;

    node *traveller = root;
    if (traveller == null)
    {
        return newNode;
    }
    cout << "ROOT " << root->data << nl;
    while (true)
    {
        if (traveller == null)
        {
            traveller = newNode;
            cout << "Tashin" << nl;
            break;
        }
        else
        {
            if (traveller->data < key)
            {
                traveller = traveller->rightNode;
            }
            else
            {
                traveller = traveller->leftNode;
            }
        }
    }

    return root;
}

void postOrderTraversal(node *root)
{
    if (root == null)
        return;
    postOrderTraversal(root->leftNode);
    postOrderTraversal(root->rightNode);
}

int32_t main()
{
    node *root = NULL;

    // input
    //  4 5 1 2 3 6 -1

    int data;
    while (1)
    {
        cout << "enter data: ";
        cin >> data;
        if (data == -1)
        {
            break;
        }
        root = insert(root, data);
    }

    cout << nl;
    cout << "Tree Traversal: ";
    postOrderTraversal(root);
    cout << nl;

    CRACKED;
}
