#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};

Node *LL_insert_to_beginning(Node *head, int newData)
{

    Node *newNode = new Node(); // creat new node
    newNode->data = newData;    // assign value to the new node

    newNode->prev = NULL; // this is a double ll so to set new node as head its head prev should be null
    newNode->next = head; // new node er next e head point kora
    head->prev = newNode; // ar jehetu head er aage new node bosche so head er prev e new node assign korechi

    return newNode;
}

void LL_insert_to_beginning(Node **head, int newData)
{                               // One without assignment needed
    Node *newNode = new Node(); // creat new node
    newNode->data = newData;    // assign value to the new node

    Node *temp = *head;   // head er ekta copy node banano
    newNode->prev = NULL; // this is a double ll so to set new node as head its head prev should be null
    newNode->next = temp; // new node er next e head point kora
    temp->prev = newNode; // ar jehetu head er aage new node bosche so head er prev e new node assign korechi
    *head = newNode;
}

void LL_insert_after(Node *head, int newData, int target)
{
    Node *temp = head; // head er ekta copy node banano
    while (temp->next != NULL && temp->data != target)
    {
        temp = temp->next; // to find the target node
    }

    Node *newNode = new Node(); // creat new node
    newNode->data = newData;    // assign value to the new node

    newNode->next = temp->next; // new node er next e je target node tar poer node assign
    temp->next->prev = newNode; // target node er porer noder er prev e new node assign
    temp->next = newNode;       // target node er next e new node assigh
    newNode->prev = temp;       // sesh s new node er aage target node assign
}

void LL_insert_at_end(Node *head, int newData)
{
    Node *temp = head; // head er ekta copy node banano
    while (temp->next != NULL)
    {
        temp = temp->next; // sesh node e powchano
    }
    Node *newNode = new Node(); // creat new node
    newNode->data = newData;    // assign value to the new node

    temp->next = newNode; // sesh node er pore new node ke point kora
    newNode->prev = temp; // sesh node er aage aager last node ke point kora
    newNode->next = NULL; // new node jeetu last node so er next e null pioint kora
}

void LL_delete_node(Node **head, int hasValue)
{
    Node *temp = *head;         // head er ekta copy node banano
    if (temp->data == hasValue) // node jodi prothom node hoy
    {
        *head = temp->next;  //  head sorano karon head e remove hobe
        Node *first = *head; // new head er copy node banano
        first->prev = NULL;  // head er aage null point kora
        free(temp);          // node free kora
        return;
    }

    Node *prevNode; // je node delete hobe setar aager node jate easily pete pari tar jonno eta
    while (temp != NULL && temp->data != hasValue)
    {
        prevNode = temp;   // previous node e current node assign
        temp = temp->next; // current node ne porer node e assign
    }
    if (temp == NULL)
    {
        cout << "The item doesn't exist \n";
        return;
    }
    prevNode->next = temp->next; // prev node ke je node delete hobe tar poer node ke point kora
    temp->next->prev = prevNode; // je node delete hobe tar porer node er prev ke je node delete hobe tar aager node ke point kora
    free(temp);
}

bool searchngitems(Node *head, int data) // Question 1
{
    Node *traveller = head;
    while (traveller->next != NULL)

    {
        if (traveller->data == data)
            return true;
        traveller = traveller->next;
    }
    return false;
}

int main()
{
    Node *head;

    head = new Node();
    head->data = 1;

    head = LL_insert_to_beginning(head, 3);
    LL_insert_to_beginning(&head, 4);

    LL_insert_after(head, 2, 3);

    LL_insert_at_end(head, 0);

    LL_delete_node(&head, 10);
    Node *Cursor;
    Cursor = head;
    while (Cursor)
    {
        cout << Cursor->data << endl;
        Cursor = Cursor->next;
    }
    return 0;
}