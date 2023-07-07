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

    // distructor
    ~Node()
    {
        int data = this->value;
        // memory free
        if (this->nextNode != NULL)
        {
            delete nextNode;
            this->nextNode = NULL;
        }
        // cout << "Memory is free for node with data " << data << nl;
    }
};

void InsertAtFirst(Node *&head, int data)
{
    Node *newNode = new Node(data);
    newNode->nextNode = head;
    head = newNode;
}

void deleteNodeByPosition(Node *&head, Node *&tail, int postition)
{
    // deleting first node
    if (postition == 1)
    {
        Node *nodeToDelete = head;
        head = head->nextNode;

        // memory free
        nodeToDelete->nextNode = NULL;
        delete nodeToDelete;
        return;
    }
    // last and middle node
    else
    {
        int cnt = 1;
        Node *traveler = head;
        while (true)
            if (cnt == postition - 1)
            {
                Node *nodeToDelete = traveler->nextNode;

                traveler->nextNode = traveler->nextNode->nextNode;

                // memory free
                nodeToDelete->nextNode = NULL;
                if (nodeToDelete->nextNode == tail->nextNode)
                {
                    // cout << "this is the last node" << nl;
                    tail = traveler;
                }
                delete nodeToDelete;
                break;
            }
            else
            {
                cnt++;
                traveler = traveler->nextNode;
            }
    }
}

void deleteNodeByValue(Node *&head, Node *&tail, int value)
{
    int cnt = 1;
    Node *traveler = head;
    Node *followTraveler = NULL;
    while (true)
    {
        if (traveler->value == value)
        {
            if (cnt == 1) // first element
            {
                head = traveler->nextNode;
                traveler->nextNode = NULL;
                delete traveler;
                break;
            }
            else
            {
                if (traveler->nextNode == NULL) // last node
                {
                    tail = followTraveler;
                    followTraveler->nextNode = NULL;
                    traveler->nextNode = NULL;
                    delete traveler;
                    break;
                }
                else
                {
                    followTraveler->nextNode = traveler->nextNode;
                    traveler->nextNode = NULL;
                    delete traveler;
                    break;
                }
            }
        }
        else
        {
            cnt++;
            followTraveler = traveler;
            traveler = traveler->nextNode;
        }
    }
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

int32_t main()
{
    faster;

    // creat head & tail
    Node *head = NULL;
    Node *tail = NULL;

    // new node creat
    Node *newNode = new Node(100);
    head = newNode;
    tail = newNode;

    InsertAtFirst(head, 200);
    InsertAtFirst(head, 300);
    InsertAtFirst(head, 400);
    InsertAtFirst(head, 500);
    InsertAtFirst(head, 600);

    cout << "In the beginning           : ";
    printLinkedList(head);
    cout << "Head value = " << head->value;
    cout << "  &&  Tail value = " << tail->value << nl;

    //--------------------------------------------- deletion by position
    // deleteNodeByPosition(head,tail, 1);  // first
    // deleteNodeByPosition(head,tail, 3);   // middle
    // deleteNodeByPosition(head, tail, 6); // last

    //--------------------------------------------- deletion by Value
    deleteNodeByValue(head, tail, 600); // first
    deleteNodeByValue(head, tail, 300); // middle
    deleteNodeByValue(head, tail, 100); // last

    cout << "After deleteNodeBy         : ";
    printLinkedList(head);

    cout << "Head value = " << head->value;
    cout << "  &&  Tail value = " << tail->value << nl;

    CRACKED;
}