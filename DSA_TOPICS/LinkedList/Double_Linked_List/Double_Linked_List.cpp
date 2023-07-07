//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    22-06-23     *************************\

#include <iostream>
#define faster                          \
      ios_base::sync_with_stdio(false); \
      cin.tie(0);                       \
      cout.tie(0);
#define CRACKED return 0;
#define nl endl; // NewLine

#define output(x) cout << x << nl // out
#define printarray(arr, len)        \
      for (int i = 0; i < len; i++) \
      {                             \
            cout << arr[i] << " ";  \
            if (i + 1 == len)       \
                  cout << endl;     \
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

void printLinkedList(Node *&head)
{
      Node *traveler = head;
      while (traveler != NULL)
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

void InsertAtFirst(Node *&head, int data)
{
      Node *newNode = new Node(data);
      head->prevNode = newNode;
      newNode->nextNode = head;
      head = newNode;
}
void InsertAtLast(Node *&tail, int data)
{
      Node *newNode = new Node(data);
      newNode->prevNode = tail;
      tail->nextNode = newNode;
      tail = newNode;
}
void InsertAtposition(Node *&head, Node *&tail, int position, int data)
{
      if (position == 1)
      {
            InsertAtFirst(head, data);
            return;
      }
      else
      {
            Node *traveler = head;
            Node *newNode = new Node(data);
            int cnt = 1;

            while (cnt < position - 1)
            {
                  traveler = traveler->nextNode;
                  cnt++;
            }
            if (traveler->nextNode == NULL)
            {
                  InsertAtLast(tail, data);
                  return;
            }
            newNode->nextNode = traveler->nextNode;
            traveler->nextNode->prevNode = newNode;
            traveler->nextNode = newNode;
      }
}

void deleteNodeByPosition(Node *&head, Node *&tail, int position)
{
      if (position == 1)
      {
            Node *nodeToDelete = head;
            nodeToDelete->nextNode->prevNode = NULL;
            head = head->nextNode;
            nodeToDelete->nextNode = NULL;
            delete nodeToDelete;
            return;
      }
      int cnt = 0;
      Node *traveller = head;
      while (cnt < position - 1)
      {
            traveller = traveller->nextNode;
            cnt++;
      }
      if (traveller->nextNode == NULL)
      {
            tail = traveller->prevNode;
            traveller->prevNode->nextNode = NULL;
            traveller->prevNode = NULL;
            delete traveller;
            return;
      }

      traveller->prevNode->nextNode = traveller->nextNode;
      traveller->nextNode->prevNode = traveller->prevNode;
      traveller->nextNode = NULL;
      traveller->prevNode = NULL;
      delete traveller;
}

int32_t main()
{
      faster;

      int data = 1000;

      Node *head = NULL;
      Node *newNode = new Node(data);
      Node *tail = newNode;

      head = newNode;

      printLinkedList(head);

      InsertAtFirst(head, 2000);
      printLinkedList(head);

      InsertAtLast(tail, 100);
      printLinkedList(head);

      InsertAtposition(head, tail, 4, 10);
      printLinkedList(head);

      InsertAtposition(head, tail, 2, 1500);
      printLinkedList(head);

      InsertAtposition(head, tail, 6, 555);
      printLinkedList(head);

      //---------------------- deletion

      deleteNodeByPosition(head, tail, 6);
      printLinkedList(head);
      cout << "---------> " << (head->data) << "  " << (tail->prevNode->data) << nl; // tashin

      CRACKED;
}
