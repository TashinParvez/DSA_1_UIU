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
//***********  recursively    *********
node *search(node *root, int value)
{
    if (root == null || root->data == value)
        return root;
    else
    {
        if (value < root->data)
            return search(root->leftNode, value);
        else
            return search(root->rightNode, value);
    }
}

/* //**********  Iteratively  **************

    node *search(node *root, int value)
    {
        while (root != null && root->data != value)
         {
              if (root->data > value)
                  root = root->leftNode;
              else
                  root = root->rightNode;
          }
      return root;
    }

*/

int32_t main()
{
    node *root = NULL;

    // creating tree
    root = buildTree(root);

    // input
    // 1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1

    node *ptr = search(root, 5);
    if (ptr != null)
    {
        cout << "5 found on the tree" << nl;
    }
    else
        cout << "5 didnt find on the tree" << nl;

    CRACKED;
}
