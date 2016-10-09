// Using whatever programming techniques you know, write the cleanest possible
// function you can think of to print a singly linked list in reverse. The
// format for the node should be a struct containing an integer value, val,
// and a next pointer to the following node.

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

const int MAX_VALUE = 100;

typedef struct Node
{
    int val;
    Node* next;
} Node;

Node* create(int numNodes)
{
    int idx = 0;
    Node* curr = NULL, *prev = NULL;
    while (idx < numNodes)
    {
        curr = (Node *)malloc(sizeof(Node));
        curr->val = rand() % MAX_VALUE;
        curr->next = prev;
        prev = curr;

        idx++;
    }

    return curr;
}

void printNode(Node* node)
{
    cout << node->val << " ";
}

void printForward(Node* node)
{
    Node* iter = node;
    while(iter != NULL)
    {
        printNode(iter);
        iter = iter->next;
    }
}

void printReverse(Node* node)
{
    Node* iter = node;
    if(iter)
    {
        printReverse(iter->next);
        printNode(iter);
    }
}

int main()
{
    srand(time(NULL));

    int numNodes;
    cout << "Enter number of nodes: ";
    cin >> numNodes;

    Node* head;
    head = create(numNodes);

    cout << "Printing list forward: ";
    printForward(head);
    cout << endl;

    cout << "Printing list in reverse: ";
    printReverse(head);
    cout << endl;

    return 0;
}