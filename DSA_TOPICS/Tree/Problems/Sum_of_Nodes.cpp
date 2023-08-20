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

    if (root == null)
        return newNode;

    node *traveller = root;
    while (true)
    {
        if (traveller->data < key)
        {
            if (traveller->rightNode == null)
            {
                traveller->rightNode = newNode;
                break;
            }
            traveller = traveller->rightNode;
        }
        else
        {
            if (traveller->leftNode == null)
            {
                traveller->leftNode = newNode;
                break;
            }
            traveller = traveller->leftNode;
        }
    }
    return root;
}

 
int countAllNodesValue(node *root)
{
    if (root == null)
        return 0;

    int left = countAllNodesValue(root->leftNode);
    int right = countAllNodesValue(root->rightNode);

    return left + right + root->data;
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
            break;
        root = insert(root, data);
    }

    cout << nl;
    cout << "Total nodes Sum = ";
    cout << countAllNodesValue(root);
    cout << nl;

    CRACKED;
}
