#include <bits/stdc++.h>
#include <iostream>
#define CRACKED return 0;
#define nl endl // NewLine
#define null NULL
using namespace std;

typedef struct TreeNode
{
    int val;
    TreeNode *left = null;
    TreeNode *right = null;
} Node;
using namespace std;

TreeNode *createNode(int value)
{
    TreeNode *newNode = new TreeNode;
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode *insert(TreeNode *root, int key)
{
    if (root == NULL)
    {
        return createNode(key);
    }

    if (key < root->val)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->val)
    {
        root->right = insert(root->right, key);
    }

    return root;
}

TreeNode *findMin(TreeNode *node)
{
    while (node->left != NULL)
    {
        node = node->left;
    }
    return node;
}

TreeNode *removeNode(TreeNode *root, int key)
{
    if (root == NULL)
    {
        return root;
    }

    if (key < root->val)
    {
        root->left = removeNode(root->left, key);
    }
    else if (key > root->val)
    {
        root->right = removeNode(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            TreeNode *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            TreeNode *temp = root->left;
            delete root;
            return temp;
        }

        TreeNode *temp = findMin(root->right);
        root->val = temp->val;
        root->right = removeNode(root->right, temp->val);
    }

    return root;
}

void printPostOrder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->val << " ";
}

// vector<int> putSum;

// root wantSum inHand [  , ,  0]
bool isSumPossible(Node *root, int sum, vector<int> &vect)
{
    // now += root->val;
    // cout << "Tshain works "    << nl;

    vect.push_back(root->val);

    for (auto i : vect)
    {
        if (i == sum)
            return true;
        else
        {
            if (i + root->val == sum)
            {
                return true;
            }
        }
    }

    // if (now == sum)
    //     return true;
    // if (now > sum)
    // {
    //     return;
    // }

    if (root->left != null)
        isSumPossible(root->left, sum, vect);

    if (root->right != null)
        isSumPossible(root->right, sum, vect);

    return false;
}

void interactiveProgram()
{
    TreeNode *root = NULL;
    int choice = 0;

    while (choice != 8)
    {
        cout << "1. Insert\n2. Delete\n3. Search\n4. Print Post-Order\n5. Print Pre-Order\n6. Print In-Order\n7. Get Height\n8. Quit\n";
        cout << "9. Call isSumPossible Function" << nl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int value;
            cout << "Enter value to insert: ";
            cin >> value;
            root = insert(root, value);
        }
        else if (choice == 2)
        {
            int value;
            cout << "Enter value to delete: ";
            cin >> value;
            root = removeNode(root, value);
        }
        else if (choice == 3)
        {
             
        }
        else if (choice == 4)
        {
            cout << "Post-Order Traversal: ";
            printPostOrder(root);
            cout << endl;
        }
        else if (choice == 5)
        { 
        }
        else if (choice == 6)
        { 
        }
        else if (choice == 7)
        {
         }
        else if (choice == 8)
        {
            cout << "Exiting program." << nl;
        }
        else if (choice == 9)
        {
            cout << nl;
            cout << "isSumnPossible Function Called" << nl;
            cout << "Which Sum you want to get : " << nl;
            int sum;
            cin >> sum;
            vector<int> vect;

            if (isSumPossible(root, sum, vect))
            {
                cout << "Yes, Sum found " << nl;
            }
            else
            {
                cout << "No, Sum not found " << nl;
            }

            cout << nl;
        }

        else
        {
            cout << "Invalid choice. Please enter a valid option." << nl;
        }
    }
}

int main()
{
    interactiveProgram();
    return 0;
}