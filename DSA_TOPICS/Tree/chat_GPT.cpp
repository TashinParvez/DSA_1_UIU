#include <iostream>
using namespace std;

#define CRACKED return 0;
#define nl endl // NewLine
#define null NULL

typedef struct Node {
    int data;
    struct Node* leftNode = null;
    struct Node* rightNode = null;
} node;

node* insert(node* root, int key) {
    node* newNode = new node; // Use 'new' for memory allocation
    newNode->data = key;
    newNode->leftNode = newNode->rightNode = null;

    if (root == null) {
        return newNode;
    }

    node* parent = null;
    node* current = root;

    while (current != null) {
        parent = current;
        if (current->data < key)
            current = current->rightNode;
        else
            current = current->leftNode;
    }

    if (parent->data < key)
        parent->rightNode = newNode;
    else
        parent->leftNode = newNode;

    return root;
}

void postOrderTraversal(node* root) {
    if (root == null)
        return;
    postOrderTraversal(root->leftNode);
    postOrderTraversal(root->rightNode);
    cout << root->data << " "; // Print the node data
}

int32_t main() {
    node* root = NULL;

    // input
    //  4 5 1 2 3 6 -1

    int data;
    while (1) {
        cout << "enter data: ";
        cin >> data;
        if (data == -1) {
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
