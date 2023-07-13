#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct double_linked_list
{
    node *head;
    node *tail;

    double_linked_list()
    {
        head = NULL;
        tail = NULL;
        // head->data = 0;
        // head->next = nullptr;
    }

    node *search_in_list(int val)
    {
        node *temp = head;
        while (temp->next != nullptr)
        {
            if (temp->data == val)
                return temp;
            else
                temp = temp->next;
        }
        return nullptr;
    }

    node *search_in_list_reverse(int val)
    {
        node *temp = tail;
        while (temp != NULL)
        {
            if (temp->data == val)
                return temp;
            else
                temp = temp->prev;
        }
        return NULL;
    }

    void insert_first(int val)
    {
        if (head != NULL)
        {
            node *newNode = new node;
            newNode->data = val;
            newNode->prev = NULL;
            newNode->next = head;

            head->prev = newNode;

            head = newNode;
        }
        else
        {
            node *newNode = new node;
            newNode->data = val;
            newNode->prev = NULL;
            newNode->next = NULL;

            head = newNode;
            tail = newNode;
        }
    }

    void insert_last(int val)
    {
        if (tail != NULL)
        {
            node *newNode = new node;
            newNode->data = val;
            newNode->next = NULL;
            newNode->prev = tail;

            tail->next = newNode;

            tail = newNode;
        }
        else
        {
            node *newNode = new node;
            newNode->data = val;
            newNode->prev = NULL;
            newNode->next = NULL;

            head = newNode;
            tail = newNode;
        }
    }

    void insert_middle(int new_val, int prev_val)
    {
        node *newNode = new node;
        newNode->data = new_val;

        node *temp = search_in_list(prev_val);
        node *temp1 = temp->next;

        newNode->next = temp1;
        newNode->prev = temp;

        temp->next = newNode;
        temp1->prev = newNode;
    }

    void insert_in_order(int val)
    {
    }

    void delete_first()
    {
        if (head == NULL)
        {
            return;
        }
        else if (head->next == NULL)
        {
            node *temp = head;
            head = NULL;
            tail = NULL;

            delete temp;
        }
        else
        {
            node *temp = head;
            head = head->next;
            head->prev = NULL;

            delete temp;
        }
    }

    void delete_last()
    {
        if (tail == NULL)
        {
            return;
        }
        else if (tail->prev == NULL)
        {
            node *temp = tail;
            tail = NULL;
            head = NULL;

            delete temp;
        }
        else
        {
            node *temp = tail;
            tail = tail->prev;
            tail->next = NULL;

            delete temp;
        }
    }

    void convert_to_circular_list()
    {
        tail->next = head;
        head->prev = tail;
    }

    void show_list()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << ", ";
            temp = temp->next;
        }
        cout << endl;
    }

    void show_list_circular()
    {
    }

    void findMax()
    {
        int m = head->data;
        node *temp = head;
        while (temp->next != NULL)
        {
            if (temp->data > m)
            {
                m = temp->data;
            }
            temp = temp->next;
        }
        cout << "maximum value is " << m << endl;
    }

    void insertInKthPosition(int value, int position)
    {
        int cnt = 1;
        node *temp = head;
        while (position != cnt)
        {
            temp = temp->next;
            cnt++;
        }
        if (position == 1)
        {
            node *newNode = new node;
            newNode->data = value;

            newNode->next = head;
            newNode->prev = head->prev;
            head->prev = newNode;
            head = newNode;
        }
        else
        {
            if (temp == NULL)
            {
                node *newNode = new node;
                newNode->data = value;

                newNode->next = NULL;
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
            }
            else
            {
                node *newNode = new node;
                newNode->data = value;

                newNode->next = temp;
                newNode->prev = temp->prev;
                temp->prev->next = newNode;
                temp->prev = newNode;
            }
        }
    }
    void insertSecondlastPos(int value)
    {
        node *newNode = new node;
        newNode->data = value;
        newNode->prev = tail->prev;
        newNode->next = tail;
        tail->prev->next = newNode;
    }

    void deleteAllOddelements()
    {
        node *temp = head;
        while (temp!= NULL)
        {
            int num = temp->data;
            if (num % 2 != 0)
            {
                if (temp == head)
                {
                    node *nodeTofree = head;
                    temp = temp->next;
                    head = head->next;
                    nodeTofree->next = NULL;
                    free(nodeTofree);
                }
                else if (temp == tail)
                {
                    node *nodeTofree = tail;
                    tail = tail->prev;
                    tail->next = NULL;
                    nodeTofree->next = NULL;
                    nodeTofree->prev = NULL;
                    free(nodeTofree);
                    break;
                }
                else
                {
                    node *nodeTofree = temp;
                    temp = temp->next;

                    nodeTofree->prev->next = nodeTofree->next;
                    nodeTofree->next->prev = nodeTofree->prev;
                    nodeTofree->next = NULL;
                    nodeTofree->prev = NULL;
                    free(nodeTofree);
                }
                continue;
            }
            temp = temp->next;
        }
        return;
    }

    void searchElementoccurrences(int value)
    {
        int cnt = 0;
        node *temp = head;
        while (temp!= NULL)
        {
            if (temp->data == value)
                cnt++;

            temp = temp->next;
            
        }
        cout << "occurrences of << value "
             << " is " << cnt << endl;
    }
};

// 5, 4, 3, 2, 1

int main()
{
    double_linked_list linked_list;
    int ch;
    int val, prev_val;
    node *y = new node;

    while (1)
    {
        cout << endl;
        cout << "---MENU---" << endl;
        cout << "1. Insert First" << endl;
        cout << "2. Show All " << endl;
        cout << "3. Search " << endl;
        cout << "4. Insert Last " << endl;
        cout << "5. Insert Middle " << endl;
        cout << "6. Insert In Order " << endl;
        cout << "7. Exit " << endl;
        cout << "8. insert in kth position " << endl;
        cout << "9. insert insertSecondlast position " << endl;
        cout << "10. find maximum value " << endl;
        cout << "11. delete all odd elements " << endl;
        cout << "12. Search all occurrences of a specific element " << endl;

        cin >> ch;
        cout << endl;

        switch (ch)
        {
        case 1:
            cout << "Enter the value of data: ";

            cin >> val;
            linked_list.insert_first(val);
            break;

        case 2:
            linked_list.show_list();
            break;

        case 3:
            cout << "Enter a value to search in the list: ";

            cin >> val;

            y = linked_list.search_in_list(val);
            if (y != nullptr)
            {
                cout << "Node found!" << endl;
                cout << y->data << endl;
            }
            else
            {
                cout << "Node not found!" << endl;
            }
            break;

        case 4:
            cout << "Enter the value of data: ";
            cin >> val;
            linked_list.insert_last(val);
            break;

        case 5:
            cout << "Enter the new value of data: ";
            cin >> val;
            cout << "Enter the prev value of data: ";
            cin >> prev_val;
            linked_list.insert_middle(val, prev_val);
            break;

        case 6:
            cout << "Enter the value of data: ";
            cin >> val;
            linked_list.insert_in_order(val);
            break;

        case 7:
            return 0;
            break;

        case 8:
            cout << "Enter the value You want to insert: " << endl;
            int value;
            cin >> value;
            cout << "Enter the position You want to insert: " << endl;
            int pos;
            cin >> pos;
            linked_list.insertInKthPosition(value, pos);
            break;
        case 9:
            cout << "Enter the value You want to insert in 2nd last position: " << endl;
            int val;
            cin >> val;
            linked_list.insertSecondlastPos(val);
            break;
        case 10:
            linked_list.findMax();
            break;
        case 11:
            linked_list.deleteAllOddelements();
            break;

        case 12:
            int v;
            cout << "Enter the element: " << endl;
            cin >> v;
            linked_list.searchElementoccurrences(v);
            break;

        default:
            cout << "Wrong input!" << endl;
        }
    }

    return 0;
}