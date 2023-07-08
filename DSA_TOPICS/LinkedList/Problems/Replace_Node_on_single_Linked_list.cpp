//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    22-06-23     *************************\

#include <iostream>
#define faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define CRACKED return 0;
#define nl endl; // NewLine

#define int long long
#define output(x) cout << x << nl // out
#define printarray(arr, len)      \
    for (int i = 0; i < len; i++) \
    {                             \
        cout << arr[i] << " ";    \
        if (i + 1 == len)         \
            cout << endl;         \
    } // array print
using namespace std;

// by using structure
/*
typedef struct Node
{
    int value;
    Node *nextNode;

} Node;
*/

// by using class
class Node
{
public:
    int value = 0;
    Node *nextNode = NULL;

    // constructor
    Node(int value)
    {
        this->value = value;
        this->nextNode = NULL;
    }
};

void InsertAtFirst(Node *&head, int data)
{
    Node *newNode = new Node(data);
    newNode->nextNode = head;
    head = newNode;
}

void InsertAtLast(Node *&tail, int data)
{
    Node *newNode = new Node(data);
    tail->nextNode = newNode;
    tail = newNode;
    // tail = tail->nextNode;  // another way
}

void InsertAtposition(Node *&head, Node *&tail, int position, int data)
{
    // Insert in the fist postion
    if (position == 1)
    {
        InsertAtFirst(head, data);
        return;
    }

    Node *traveler = head;
    Node *nodeToInsert = new Node(data);
    int cnt = 1;

    while (cnt < position - 1)
    {
        traveler = traveler->nextNode;
        cnt++;
    }

    // inserting at last position
    if (traveler->nextNode == NULL)
    {
        InsertAtLast(tail, data);
        return;
    }

    nodeToInsert->nextNode = traveler->nextNode;
    traveler->nextNode = nodeToInsert;
}

void printLinkedList(Node *&head)
{
    Node *tempHead = head;
    while (tempHead != NULL)
    {
        cout << tempHead->value << " ";
        tempHead = tempHead->nextNode;
    }
    cout << nl;
}

// Question Answer
// 5. Replace a node at first/last/after some value/before some value

void replaceNode(Node *&head, Node *&tail, int position, int value)
{
    if (position == 1)
    {
        Node *nodeToRemove = head;
        Node *newNode = new Node(value);
        newNode->nextNode = head->nextNode;
        if (head->nextNode == NULL)
        {
            tail = newNode;
        }
        head = newNode;
        nodeToRemove->nextNode = NULL;
        delete nodeToRemove;
        return;
    }
    int cnt = 1;
    Node *traveller = head;
    while (cnt < position - 1)
    {
        traveller = traveller->nextNode;
        cnt++;
    }
    Node *newNode = new Node(value);
    newNode->nextNode = traveller->nextNode->nextNode;
    if (traveller->nextNode == tail)
    {
        tail = newNode;
    }
    traveller->nextNode->nextNode = NULL;
    Node *nodeToRemove = traveller->nextNode;
    traveller->nextNode = newNode;
    delete nodeToRemove;
}

int32_t main()
{
    faster;

    Node *head = NULL;
    Node *newNode = new Node(100);
    head = newNode;

    Node *tail = newNode;
    InsertAtLast(tail, 190);
    InsertAtLast(tail, 1);
    InsertAtLast(tail, 12);
    InsertAtLast(tail, 13);
    InsertAtposition(head, tail, 6, 2);

    printLinkedList(head);

    replaceNode(head, tail, 1, 200);
    printLinkedList(head);

    replaceNode(head, tail, 6, 14);
    printLinkedList(head);

    replaceNode(head, tail, 3, 11);
    printLinkedList(head);

    CRACKED;
}