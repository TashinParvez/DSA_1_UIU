//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    22-06-23     *************************\

#include <iostream>
#define faster                          \
      ios_base::sync_with_stdio(false); \
      cin.tie(0);                       \
      cout.tie(0);
#define CRACKED return 0;
#define nl endl; // NewLine

#define int long long
#define output(x) cout << x << nl // out
#define printarray(arr, len)        \
      for (int i = 0; i < len; i++) \
      {                             \
            cout << arr[i] << " ";  \
            if (i + 1 == len)       \
                  cout << endl;     \
      } // array print
using namespace std;

#define nl endl; // NewLine

struct node // make node for linked list using structure
{
      int value;         // value part of node contains the element
      struct node *next; // the next part of node contains the address of next element of list
};

struct node *head; // contains the address of first element of linked list

void init()
{
      head = NULL; // initialize the beginning(head) of list to NULL
}

void insertfirst(int element) // inserts element in linked list
{
      struct node *New;
      New = (struct node *)malloc(sizeof(struct node)); // New named node declared with size of node declared before
      New->value = element;                             // inserts the new element to the value part of node New
      New->next = NULL;                                 // makes the next part of node New NULL so that no garbage value remains
      New->next = head;                                 // the address of previously first node, which was stored in head is now assigned to next part of node New
      head = New;                                       // the address of new first element which is present in node New is assigned to head node
}

void print()
{
      if (head == NULL) // condition to check whether list is empty
      {
            printf("list is empty\n");
            return;
      }
      struct node *traveller = head;
      int count;
      count = 0;
      while (traveller != NULL) // the loop traverse until it gets any NULL node
      {
            printf("%d->", traveller->value);
            count++;                     // counts the number of nodes or elements present in list
            traveller = traveller->next; // moves cur pointer to next node to check and get value
      }
      printf("NULL\n");
      printf("number of nodes %d\n", count);
      cout << endl;
}

void deleteitem(int ele)
{
      struct node *cur = head;
      struct node *prev = NULL;

      while (cur->value != ele)
      {
            prev = cur;
            cur = cur->next;
      }

      prev->next = cur->next;
      cur->next = NULL;
      free(cur);
      return;
}

int searchitem(int ele)
{
      struct node *temp;
      temp = head;
      while (temp != 0)
      {
            if (temp->value == ele)
                  return 1; // element is found
            temp = temp->next;
      }
      return 0;
}

void insertlast(int val) // insert at the last of linked list
{

      struct node *New;
      New = (struct node *)malloc(sizeof(struct node));
      New->value = val; // inserts the new element to the value part of node New
      New->next = NULL;

      struct node *traveller = head;
      if (head == NULL)
      {
            head = New;
            return;
      }
      else
      {
            while (traveller->next != NULL)
            {
                  traveller = traveller->next;
            }
            traveller->next = New;
            return;
      }
}

void deletelast() // delete the last element
{
      if (head == NULL)
      {
            printf("list is empty and nothing to delete\n");
      }

      struct node *cur = head;
      struct node *prev = NULL;
      while (cur->next != NULL)
      {
            prev = cur;
            cur = cur->next;
      }
      if (prev->next != NULL)
            prev->next = NULL;
      free(cur);
}

void deletefirst() // delete the first element
{
      // struct node *New;
      // New = (struct node *)malloc(sizeof(struct node));
      // New->value = elem;
      struct node *cur;
      if (head == NULL)
            printf("list is empty and nothing to delete\n");
      cur = head;
      head = head->next;
      free(cur);
}

void insertafter(int elem, int num) // inserts element for any given element present in linked list
{
      struct node *New;
      New = (struct node *)malloc(sizeof(struct node));
      New->value = elem;

      struct node *traveller = head;
      while (traveller->value != num && traveller->next != NULL)
      {
            traveller = traveller->next;
      }

      if (traveller->next == NULL && traveller->value != num)
      {
            cout << "Num not found " << endl;
            return;
      }

      New->next = traveller->next;
      traveller->next = New;
}

void printReverse(struct node *head) // print the linked list in reverse way using recursion
{
      if (head == NULL)
            return;
      printReverse(head->next);
      printf("%d->", head->value);
}

void reverselist() // reverse the linked list
{
      struct node *prev = NULL;
      struct node *cur = head;
      struct node *nxt;
      while (cur != NULL)
      {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
      }
      head = prev; // points the head pointer to prev as it the new head or beginning in reverse list
}

void sum() // sum of elements of the linked list
{
      // struct node *New;
      // New = (struct node *)malloc(sizeof(struct node)); // New named node declared with size of node declared before
      // New->value = element;                             // inserts the new element to the value part of node New
      // New->next = NULL;                                 // makes the next part of node New NULL so that no garbage value remains
      // New->next = head;                                 // the address of previously first node, which was stored in head is now assigned to next part of node New
      // head = New;

      int sumValue = 0;
      struct node *traveller = head;
      while (traveller != NULL)
      {
            sumValue += traveller->value;
            traveller = traveller->next;
      }

      cout << "Sum of lndList " << sumValue << endl;
}

// 5. Replace a node at first/last/after some value/before some value

void replaceNode(node *&head, int position, int value)
{
      if (position == 1)
      {
            node *nodeToRemove = head;
            node *newNode;
            newNode->value = (value);
            newNode->next = head->next;
            if (head->next == NULL)
            {
                  // tail = newNode;
            }
            head = newNode;
            nodeToRemove->next = NULL;
            delete nodeToRemove;
            return;
      }
      int cnt = 1;
      node *traveller = head;
      while (cnt < position - 1)
      {
            traveller = traveller->next;
            cnt++;
      }
      node *newNode;
      newNode->value = (value);
      newNode->next = traveller->next->next;
      // if (traveller->next == tail)
      // {
      //     tail = newNode;
      // }
      traveller->next->next = NULL;
      node *nodeToRemove = traveller->next;
      traveller->next = newNode;
      delete nodeToRemove;
}

int getLengthOfLinkedList(node *&head)
{
      int cnt = 1;
      node *traveller = head;
      while (traveller->next != NULL)
      {
            cnt++;
            traveller = traveller->next;
      }
}

// 6. Insert at kth position
void insertAtPosition(node *&head, int position, int value)
{
      node *newNode;
      newNode->value = value;
      newNode->next = NULL;

      if (position == 1)
      {
            newNode->next = head;
            head = newNode;
            return;
      }
      int cnt = 1;
      node *traveller = head;
      while (cnt < position - 1)
      {
            traveller = traveller->next;
            cnt++;
      }
      newNode->next = traveller->next;
      traveller->next = newNode;
}

// 7.Insert at the mid position of a linked list.

void insertAtMiddle(node *&head, int value)
{
      int position = getLengthOfLinkedList(head);
      position /= 2;
      insertAtPosition(head, position, value);
}

int32_t main()
{
      init(); // make head NULL

      int ch, element;
      while (1)
      {
      printf("\
        \n 1. Insert new item. \
        \n 4. Insert Last. \
        \n 8. Insert After \
        \n15. insert kth position\
        \n14. insert all elements \
        \n16. Insert at Middle\
        \n 2. Delete item. \
        \n 6. Delete Last \
        \n 7. Delete First \
        \n 3. Search item.\
        \n 5. PrintLinked List. \
        \n 9. Print Linked List in Reverse way. \
        \n10. Sum \
        \n11. Reverse \
        \n12. Length Of Linked List  \
        \n13. Replace a Node \
        \n17. Delete before some value \
        \n18. Exit\
        \n--------------------------------------------------------------------------------------\n");
            printf("enter choice of input: ");
            scanf("%d", &ch);

            if (ch == 1)
            {
                  printf("enter element to list: ");
                  scanf("%d", &element);
                  insertfirst(element);
            }
            else if (ch == 2)
            {
                  int de;
                  printf("enter element to delete ");
                  scanf("%d", &de);
                  deleteitem(de);
            }
            else if (ch == 3)
            {
                  int se, reply;
                  printf("enter element to search ");
                  scanf("%d", &se);
                  reply = searchitem(se);
                  if (reply == 1)
                        printf("element found\n");
                  else
                        printf("element not found\n");
            }
            else if (ch == 4)
            {
                  int le;
                  printf("enter element to insert at last ");
                  scanf("%d", &le);
                  insertlast(le);
            }
            else if (ch == 5)
            {
                  print();
            }
            else if (ch == 6)
            {
                  deletelast();
            }
            else if (ch == 7)
            {
                  deletefirst();
            }
            else if (ch == 8)
            {
                  int ie, p;
                  printf("enter element to insert: ");
                  scanf("%d", &ie);
                  printf("enter after which element to insert: ");
                  scanf("%d", &p);
                  insertafter(ie, p);
            }
            else if (ch == 9)
            {
                  printReverse(head);
            }
            else if (ch == 10)
            {
                  sum();
            }
            else if (ch == 11)
            {
                  reverselist();
            }
            else if (ch == 12)
            {
                  cout << "Length of linked List " << getLengthOfLinkedList(head) << endl;
            }
            else if (ch == 13)
            {
                  int p, v;
                  cout << "Enter postion ";
                  cin >> p;
                  cout << "Enter value ";
                  cin >> v;
                  replaceNode(head, p, v);
            }
            else if (ch == 14)
            {
                  cout << "Enter how many elements you want to add ";
                  int t;
                  cin >> t;
                  cout << "Enter all numbers ";
                  while (t--)
                  {
                        int num;
                        cin >> num;
                        insertlast(num);
                  }
            }
            else if (ch == 15)
            {
                  int position, value;
                  cout << "Enter the position you want to add ";
                  cin >> position;
                  cout << "enter value ";
                  cin >> value;
                  insertAtPosition(head, position, value);
            }
            else if (ch == 16)
            {
                  int value;
                  cin >> value;
                  insertAtMiddle(head, value);
            }
            else if (ch == 17)
                  return 0;
            else
                  return 0;
      }
      return 0;
}