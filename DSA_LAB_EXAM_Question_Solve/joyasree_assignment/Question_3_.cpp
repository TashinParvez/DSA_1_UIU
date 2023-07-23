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
    newNode->prev = head->prev;
    head->prev = newNode;
    return newNode;
}

void LL_insert_to_beginning(Node **head, int newData)
{ // One without assignment needed
    Node *newNode = new Node();
    newNode->data = newData;
    Node *temp = *head;

    newNode->prev = temp->prev;
    newNode->next = temp;
    temp->prev = newNode;
    *head = newNode;
}

void LL_insert_after(Node *head, int newData, int target)
{
    Node *temp = head;
    while (temp->next != head && temp->data != target)
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
    while (temp->next != head)
    {
        temp = temp->next;
    }
    Node *newNode = new Node();
    newNode->data = newData;
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void LL_delete_node(Node **head, int hasValue)
{
    Node *temp = *head;
    if (temp->data == hasValue)
    {
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        *head = temp->next;
        free(temp);
        return;
    }
    temp = temp->next;
    Node *prevNode;
    while (temp != *head && temp->data != hasValue)
    {
        prevNode = temp;
        temp = temp->next;
    }
    if (temp == *head)
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
    if (traveller->data == data)
        return true;
    traveller = traveller->next;
    while (traveller->next != head)
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