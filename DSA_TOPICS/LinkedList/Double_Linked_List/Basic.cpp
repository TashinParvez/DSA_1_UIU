//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    22-06-23     *************************\

#include <iostream>
#define faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define CRACKED return 0;
#define nl endl; // NewLine

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
// typedef struct Node
// {
//     int value;
//     Node *nextNode;
// } Node;

// by using class
class Node
{
public:
    Node *prevNode;
    int data;
    Node *nextNode;

    // constructor
    Node(int data)
    {
        this->prevNode = NULL;
        this->data = data;
        this->nextNode = NULL;
    }
};

void printLinkedList(Node *&head)
{
    Node *traveler = head;
    // while (traveler != NULL)
    {
        cout << traveler->data << " ";
        traveler = traveler->nextNode;
    }
    cout << nl;
}
int getLengthOfLinkedList(Node *&head)
{
    Node *traveller = head;
    int cnt = 0;
    while (traveller != NULL)
    {
        cnt++;
        traveller = traveller->nextNode;
    }

    return cnt;
}

int32_t main()
{
    faster;

    Node *head = NULL;
    Node *node1 = new Node(12);

    head = node1;

    printLinkedList(head);
    getLengthOfLinkedList(head);

    CRACKED;
}
