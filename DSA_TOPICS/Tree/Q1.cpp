//        ****************  Author :  Tashin.Parvez  *************************\

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl // NewLine
#define null NULL
using namespace std;

// class node
// {
// public:
//     int data;
//     node *leftNode;
//     node *rightNode;
//     node(int data)
//     {
//         this->data = data;
//         leftNode = null;
//         rightNode = null;
//     }
// };

typedef struct Node
{
    int data;
    Node *leftNode = null, *rightNode = null;
    Node *parent = null;
    Node(int k)
    {
        data = k;
    }
} node;

// insertion
node *insert(node *root, int key)
{
    node *newNode = new node(key);
    node *traveller = root;
    if (traveller == null)
    {
        // empty tree
        return newNode;
    }

    while (true)
    {
        if (traveller->data <= key)
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
    newNode->parent = traveller;
    return root;
}

// for deletion
node *transplant(node *root, node *nodeToBeReplaced, node *newNode)
{
    if (nodeToBeReplaced->parent == null)
    {
        root = newNode;
        return root;
    }
    else
        newNode->parent = nodeToBeReplaced->parent;

    if (nodeToBeReplaced->parent->leftNode == nodeToBeReplaced)
        nodeToBeReplaced->parent->leftNode = newNode;
    else
        nodeToBeReplaced->parent->rightNode = newNode;

    return root;
}

node *findMinimumNode(node *root) // Find minimum node of a tree
{
    if (root->leftNode == null)
        return root;

    return findMinimumNode(root->leftNode);
}

node *deletion(node *root, int key)
{
    node *traveller = root;
    while (traveller != null)
    {
        if (traveller->data == key)
        {
            if (traveller->leftNode == null && traveller->rightNode == null)
            {
                if (traveller->parent->leftNode == traveller)
                    traveller->parent->leftNode = null;
                else
                    traveller->parent->rightNode = null;
            }

            else if (traveller->leftNode == null)
                root = transplant(root, traveller, traveller->rightNode);
            else if (traveller->rightNode == null)
                root = transplant(root, traveller, traveller->leftNode);
            else
            {
                node *minimumNode = findMinimumNode(traveller->rightNode);

                if (minimumNode != traveller->rightNode)
                {
                    if (minimumNode->rightNode != null)
                        root = transplant(root, minimumNode, minimumNode->rightNode);
                    else
                    {
                        minimumNode->parent->leftNode = null;
                        root = minimumNode;
                    }

                    minimumNode->rightNode = traveller->rightNode;
                    minimumNode->rightNode->parent = minimumNode;
                }
                root = transplant(root, traveller, minimumNode);
                minimumNode->leftNode = traveller->leftNode;
                minimumNode->leftNode->parent = minimumNode;
                minimumNode->parent = traveller->parent;
            }
            break;
        }
        else if (traveller->data > key)
            traveller = traveller->leftNode;
        else
            traveller = traveller->rightNode;
    }
    free(traveller);

    return root;
}

// find
bool find(node *root, int value)
{
    if (root == null)
        return false;
    if (root->data == value)
        return true;
    else
    {
        if (value < root->data)
            return find(root->leftNode, value);
        else
            return find(root->rightNode, value);
    }
}

// traversal
void postOrderTraversal(node *root)
{
    if (root == null)
    {
        // cout << "parvez" << nl;
        return;
    }
    postOrderTraversal(root->leftNode);
    postOrderTraversal(root->rightNode);
    // cout << "tashin" << nl;
    cout << root->data << " ";
}

void preOrderTraversal(node *root)
{
    // first print
    // then left node visit 
    // then right node visit

    if (root == null)
        return;
    cout << root->data << " ";
    preOrderTraversal(root->leftNode);
    preOrderTraversal(root->rightNode);
}

void InOrderTraversal(node *root)
{
    if (root == null)
        return;
    InOrderTraversal(root->leftNode);
    cout << root->data << " ";
    InOrderTraversal(root->rightNode);
}

/*

int heightOfTree(node *root)
{
    if (root == null)
        return 0;

    int leftChild = heightOfTree(root->leftNode);
    int rightChild = heightOfTree(root->rightNode);

    return max(leftChild, rightChild) + 1;
}

*/

int heightCount(node *root) // levelOrderTraversal
{
    int height = 0;
    queue<node *> q;
    q.push(root);
    q.push(null);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == null)
        {
            // cout << nl;
            height++;
            if (!q.empty())
            {
                q.push(null);
            }
        }
        else
        {
            // cout << temp->data << " ";
            if (temp->leftNode)
            {
                q.push(temp->leftNode);
            }
            if (temp->rightNode)
            {
                q.push(temp->rightNode);
            }
        }
    }
    return height - 1;
}

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(null);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == null)
        {
            cout << nl;
            if (!q.empty())
            {
                q.push(null);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->leftNode)
            {
                q.push(temp->leftNode);
            }
            if (temp->rightNode)
            {
                q.push(temp->rightNode);
            }
        }
    }
}

int main()
{
    node *root = null; // Initializing an empty BST

    int choice;
    while (true)
    {
        // options
        cout << "\nChoose an option:\
            \n1. Insertion \
            \n2. Deletion \
            \n3. Search \
            \n4. Print Traversals \
            \n5. Height of the tree\
            \n6. level Order Traversal\
            \nYour Option : ";

        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the data to insert: ";
            int value;
            cin >> value;
            root = insert(root, value);
            break;

        case 2:
            cout << "Enter the data to delete: ";
            int deletevalue;
            cin >> deletevalue;
            root = deletion(root, deletevalue);
            break;

        case 3:
            cout << "Enter the data to search: ";
            int searchValue;
            cin >> searchValue;
            if (find(root, searchValue))
                cout << "Data Exists int the tree." << nl;
            else
                cout << "Data Doesn't exists in the tree." << nl;
            break;

        case 4:
            cout << "Choose a traversal: \n1. post-order \n2. pre-order \n3. in-order\n";
            int option;
            cin >> option;

            if (option == 1)
            {
                cout << "Post Order Traversal: ";
                postOrderTraversal(root);
            }
            else if (option == 2)
            {
                cout << "Pre Order Traversal: ";
                preOrderTraversal(root);
            }
            else if (option == 3)
            {
                cout << "In Order Traversal: ";
                InOrderTraversal(root);
            }
            else
            {
                cout << "Try again";
            }
            cout << nl;
            break;

        case 5:
            cout << "The height of the tree: " << heightCount(root) << nl;
            break;

        case 6:
            cout << "Level Order traversal : \nl";
            levelOrderTraversal(root);
            break;

        default:
            cout << "Please, choose a valid option!" << nl;
        }
    }
    // 20 15 10 18 25 23 30 25

    return 0;
}
