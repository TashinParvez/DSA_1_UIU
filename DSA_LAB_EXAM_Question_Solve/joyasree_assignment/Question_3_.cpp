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
{ // needs assignment
    Node *newNode = new Node();
    newNode->data = newData;
    newNode->next = head;
    head->prev = newNode;
    newNode->prev = NULL;
    return newNode;
}

void LL_insert_to_beginning(Node **head, int newData)
{ // One without assignment needed
    Node *newNode = new Node();
    Node *temp = *head;
    newNode->data = newData;
    newNode->prev = NULL;
    newNode->next = temp;
    temp->prev = newNode;
    *head = newNode;
}

void LL_insert_after(Node *head, int newData, int target)
{
    Node *temp = head;
    while (temp->next != NULL && temp->data != target)
    {
        temp = temp->next;
    }
    Node *newNode = new Node();
    newNode->data = newData;

    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

void LL_insert_at_end(Node *head, int newData)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *newNode = new Node();
    newNode->data = newData;
    temp->next = newNode;
    newNode->prev = temp;
}

void LL_delete_node(Node **head, int hasValue)
{
    Node *temp = *head;
    if (temp->data == hasValue)
    {
        *head = temp->next;
        Node *first = *head;
        first->prev = NULL;
        free(temp);
        return;
    }
    Node *prevNode;
    while (temp != NULL && temp->data != hasValue)
    {
        prevNode = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "The item doesn't exist \n";
        return;
    }
    prevNode->next = temp->next;
    temp->next->prev = prevNode;
    free(temp);
}

bool searchngitems(Node *head, int data)  
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