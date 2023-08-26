#include <iostream>
using namespace std;

struct node
{
    int key;
    node *left, *right;
    node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

node *Insert(node *root, int key)
{
    if (root == NULL)
        return new node(key);

    if (key < root->key)
        root->left = Insert(root->left, key);
    else if (key > root->key)
        root->right = Insert(root->right, key);

    return root;
}

node *DeleteNode(node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = DeleteNode(root->left, key);
    else if (key > root->key)
        root->right = DeleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }

        node *inPre = root->left;
        while (inPre->right != NULL)
            inPre = inPre->right;

        root->key = inPre->key;
        root->left = DeleteNode(root->left, inPre->key);
    }
    return root;
}

node *Search(node *root, int key)
{
    if (root == NULL || root->key == key)
        return root;

    if (key < root->key)
        return Search(root->left, key);
    return Search(root->right, key);
}

void inOrder(node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

void preOrder(node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->key << " ";
    }
}

int main()
{
    node *root = NULL;

    while (true)
    {
        cout << "Choose an operation:" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Search" << endl;
        cout << "4. Print In-order Traversal" << endl;
        cout << "5. Print Pre-order Traversal" << endl;
        cout << "6. Print Post-order Traversal" << endl;
        cout << "7. Exit" << endl;

        int choice;
        cin >> choice;

        if (choice == 1)
        {
            int key;
            cout << "Enter the key to insert: ";
            cin >> key;
            root = Insert(root, key);
        }
        else if (choice == 2)
        {
            int key;
            cout << "Enter the key to delete: ";
            cin >> key;
            root = DeleteNode(root, key);
        }
        else if (choice == 3)
        {
            int key;
            cout << "Enter the key to search: ";
            cin >> key;
            if (Search(root, key) == NULL)
                cout << key << " not found" << endl;
            else
                cout << key << " found" << endl;
        }
        else if (choice == 4)
        {
            cout << "In-order Traversal: ";
            inOrder(root);
            cout << endl;
        }
        else if (choice == 5)
        {
            cout << "Pre-order Traversal: ";
            preOrder(root);
            cout << endl;
        }
        else if (choice == 6)
        {
            cout << "Post-order Traversal: ";
            postOrder(root);
            cout << endl;
        }
        else if (choice == 7)
        {
            break;
        }
        else
        {
            cout << "Invalid choice. Please choose a valid option." << endl;
        }
    }

    return 0;
}