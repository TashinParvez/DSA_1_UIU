//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    22-06-23     *************************\

#include <bits/stdc++.h>
#define CRACKED return 0;
#define nl endl; // NewLine
using namespace std;

struct node
{
    int val;
    struct node *next = NULL;
};

struct node *head;

void push(int data)
{
    int val = data;
    struct node *ptr;

    if (head == NULL)
    {
        ptr->val = val;
        ptr->next = head;
        head = ptr;
    }
    else
    {
        ptr->val = val;
        ptr->next = head;
        head = ptr;
    }
    cout << " DATA pushed " << nl;
}

void pop()
{
    int item;
    struct node *ptr;
    if (head == NULL) 
    {
        printf("Underflow");
    }
    else
    {
        item = head->val;
        ptr = head;
        head = head->next;
        free(ptr);
        printf("Item popped");
    }
}

void display()
{
    int i;
    struct node *ptr;
    ptr = head;
    if (ptr == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Printing Stack elements \n");
        while (ptr != NULL)
        {
            printf("%d\n", ptr->val);
            ptr = ptr->next;
        }
    }
}

int main()
{
    int choice;
    while (choice != 4)
    {
        cout << "\n1.Push \n2.Pop \n3.Show \n4.Exit" << nl;
        cout << "Enter your choice \n"  << nl;

        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int data;
            cout << "Enter the value you want to push : ";

            cin >> data;
            push(data);
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            printf("Exiting....");
            break;
        }
        default:
        {
            printf("Please Enter valid choice ");
        }
        };
    }

    return 0;
}
