//        ****************  Author :  Tashin.Parvez  *************************\
//        ****************  Updated:    22-06-23     *************************\

#include <iostream>
#define CRACKED return 0;
#define nl endl; // NewLine 
using namespace std;

// by using structure
typedef struct Node
{
    int value;
    Node *nextNode;
} Node;

// by using class
class LinkedNode
{
public:
    int value = 0;
    LinkedNode *nextNode = NULL;

    // constructor
    LinkedNode(int value)
    {
        this->value = value;
        this->nextNode = NULL;
    }

    LinkedNode() // default
    {
    }
};

int32_t main()
{

    LinkedNode *node1 = new LinkedNode();
    cout << node1->value << nl;
    cout << node1->nextNode << nl;

    LinkedNode *node2 = new LinkedNode(10);
    cout << node2->value << nl;
    cout << node2->nextNode << nl;

    CRACKED;
}
