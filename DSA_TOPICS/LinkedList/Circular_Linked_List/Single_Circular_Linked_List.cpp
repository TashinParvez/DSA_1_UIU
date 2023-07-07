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

// by using class
class Node
{
public:
    int data = 0;
    Node *nextNode = this;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->nextNode = this;
    }

    // distructor
    ~Node()
    {
        int value = this->data;
        // memory free
        if (this->nextNode != NULL)
        {
            delete nextNode;
            this->nextNode = NULL;
        }
        // cout << "Memory is free for node with data " << data << nl;
    }
};

void insertNode(Node *&tail, int element, int data)
{
    Node *nodeToInsert = new Node(data);
    if (tail == NULL)
    {
        tail = nodeToInsert;
        return;
    }

    Node *traveller = tail;
    while (traveller->data != element)
    {
        traveller = traveller->nextNode;
    }
    nodeToInsert->nextNode = traveller->nextNode;
    traveller->nextNode = nodeToInsert;
}

void deleteNode(Node *&tail, int value)
{
    if (tail == NULL)
    {
        return;
    }
    Node *traveller = tail;
    while (traveller->nextNode->data != value)
    {
        traveller = traveller->nextNode;
        if (traveller == tail)
        {
            cout << "notFound" << nl;
            return;
        }
    }
    Node *nodeToDelete = traveller->nextNode;
    if (nodeToDelete == tail)
    {
        if (tail->nextNode == tail)
        {
            tail->nextNode = NULL;
        }
        tail = tail->nextNode;
    }
    traveller->nextNode = traveller->nextNode->nextNode;
    nodeToDelete->nextNode = NULL;
    delete nodeToDelete;
}

void printLinkedList(Node *&tail)
{
    Node *traveller = tail;
    cout << traveller->data << " ";
    traveller = traveller->nextNode;
    while (traveller->nextNode != tail->nextNode)
    {
        cout << traveller->data << " ";
        traveller = traveller->nextNode;
    }
    cout << nl;
}

int32_t main()
{
    faster;
    Node *tail = NULL;
    insertNode(tail, 2, 12);
    printLinkedList(tail);

    insertNode(tail, 12, 24);
    printLinkedList(tail);

    insertNode(tail, 24, 48);
    printLinkedList(tail);

    insertNode(tail, 48, 96);
    printLinkedList(tail);

    insertNode(tail, 96, 192);
    insertNode(tail, 192, 192 * 2);
    insertNode(tail, 192 * 2, 192 * 2 * 2);

    insertNode(tail, 24, 124);
    printLinkedList(tail);

    deleteNode(tail, 124);
    printLinkedList(tail);

    deleteNode(tail, 400);
    printLinkedList(tail);

    cout << tail->data << nl;

    deleteNode(tail, 12);
    printLinkedList(tail);

    cout << tail->data << nl;

    CRACKED;
}
