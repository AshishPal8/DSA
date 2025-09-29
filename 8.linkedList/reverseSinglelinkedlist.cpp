#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtEnd(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

Node *reverseLinkedList(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;

    while (curr != NULL)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

Node *reverseLinkedListRecursively(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *newHead = reverseLinkedListRecursively(head->next);

    head->next->next = head;
    head->next = NULL;

    return newHead;
}

int main()
{
    Node *head = NULL;
    insertAtEnd(head, 2);
    insertAtEnd(head, 4);
    insertAtEnd(head, 6);
    insertAtEnd(head, 8);
    insertAtEnd(head, 10);

    printList(head);

    head = reverseLinkedListRecursively(head);

    printList(head);

    return 0;
}