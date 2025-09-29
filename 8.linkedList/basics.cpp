#include <iostream>

using namespace std;

struct ListNode
{
    int data;
    ListNode *next;

    ListNode(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtHead(ListNode *&head, int val)
{
    ListNode *newNode = new ListNode(val);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(ListNode *&head, int val)
{
    ListNode *newNode = new ListNode(val);
    if (head == NULL)
    {
        head = newNode;
    }

    ListNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

ListNode *deleteHeadNode(ListNode *head)
{
    ListNode *temp = head;
    if (head == NULL)
        return NULL;
    temp = head;
    head = head->next;
    delete temp;

    return head;
}

ListNode *deleteTailNode(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        delete head;
        return NULL;
    }

    ListNode *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    return head;
}

void printList(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void LengthOfLinkedlist(ListNode *head)
{
    int length = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        length++;
    }
    cout << "Count: " << length << endl;
}

ListNode *deleteAtIndex(ListNode *head, int index)
{
    if (head == NULL)
        return NULL;
    if (index == 0)
    {
        ListNode *temp = head;
        temp->next = head;
        delete temp;

        return head;
    }

    ListNode *prev = head;
    int i = 0;
    while (prev != NULL && i < index - 1)
    {
        prev = prev->next;
        i++;
    }

    if (prev == NULL || prev->next == NULL)
    {
        return head;
    }
    ListNode *toDelte = prev->next;
    prev->next = toDelte->next;
    delete toDelte;

    return head;
}

ListNode *deleteValue(ListNode *head, int val)
{
    if (head == NULL)
        return NULL;
    if (val == head->data)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;

        return head;
    }

    ListNode *prev = head;
    ListNode *curr = head->next;
    while (curr != NULL && curr->data != val)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL)
    {
        return head;
    }
    prev->next = curr->next;
    delete curr;

    return head;
}

bool searchElement(ListNode* head, int val){
    while(head->next !=NULL){
        if(head->data == val) return true;
        head = head->next;
    }

    return false;
}

int main()
{
    ListNode *head = NULL;

    insertAtHead(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 50);
    insertAtTail(head, 60);
    // head = deleteTailNode(head);
    // head = deleteAtIndex(head, 3);
    // head = deleteValue(head, 30);

    printList(head);
    LengthOfLinkedlist(head);
    bool result = searchElement(head, 80);

    cout << "Result: " << (result == true ? "True" : "False" );
    
}