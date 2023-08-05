//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    22-06-23     *************************\

#include <iostream>
#define nl endl; // NewLine
using namespace std;

#define size 100
int queue[size];
int n = 100, front = -1, rear = -1;

void enqueue()
{
    int val;
    if ((rear + 1) % size == front)
        cout << "Queue Overflow" << endl;
    else
    {
        if (front == -1)
            front = 0;
        cout << "Insert the element in queue : " << endl;
        cin >> val;
        rear++;
        rear %= size;
        queue[rear] = val;
    }
}
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        cout << "Queue Underflow";
        return;
    }
    else
    {
        cout << "Element deleted from queue is : " << queue[front] << endl;
        front++;
        front %= size;
    }
}
void Display()
{
    if (front == -1)
        cout << "Queue is empty" << endl;
    else
    {
        cout << "Queue elements are : ";
        for (int i = front; i != rear;)
        {
            cout << queue[i] << " ";
            i++;
            i %= size;
        }
        cout << queue[rear];
        cout << endl;
    }
}
int main()
{
    int ch;
    cout << "1) Insert element to queue" << endl;
    cout << "2) Delete element from queue" << endl;
    cout << "3) Display all the elements of queue" << endl;
    cout << "4) Exit" << endl;

    while (ch != 4)
    {
        cout << "Enter your choice : " << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            Display();
            break;
        case 4:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}