// This challenge, similar to the last linked list challenge, involves
// reversing a singly linked list--but this time, you must not out the list
// but actually reverse the entire list in place. By in-place, I mean that
// no memory can be allocated. The resulting code should be function that
// takes the head of a list and returns a the new head of the reversed list.

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

void print(Node* node)
{
    Node* iter = node;
    while(iter != NULL)
    {
        printNode(iter);
        iter = iter->next;
    }
}

Node* reverse(Node* curr, Node* prev)
{
    Node* newHead = NULL;
    if(curr != NULL)
    {
        newHead = reverse(curr->next, curr);
        curr->next = prev;
    }
    else
    {
        newHead = prev;
    }

    return newHead;
}

int main()
{
    srand(time(NULL));

    int numNodes;
    cout << "Enter number of nodes: ";
    cin >> numNodes;

    Node* head;
    head = create(numNodes);

    cout << "Printing initial list: ";
    print(head);
    cout << endl;

    head = reverse(head, NULL);
    cout << "Printing reversed list: ";
    print(head);
    cout << endl;

    return 0;
}
