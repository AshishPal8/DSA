#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *convertArr2LL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *tail = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        tail->next = temp;
        tail = temp;
    }
    return head;
}

void PrintList(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

bool palindromeLLBrute(Node *head)
{
    stack<int> st;
    Node *temp = head;

    while (temp != NULL)
    {
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;

    while (temp != NULL)
    {
        if (temp->data != st.top())
            return false;
        temp = temp->next;
        st.pop();
    }

    return true;
}

Node *reverseLL(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *newHead = reverseLL(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = NULL;

    return newHead;
}

// NOT WORKING AGAIN REVIEW AND FIX
bool palindromeLLOptimal(Node *head)
{
    if (head == NULL || head->next == NULL)
        return true;

    Node *slow = head;
    Node *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *newhead = reverseLL(slow->next);
    Node *first = head;
    Node *second = newhead;

    while (second != NULL)
    {
        if (first->data != second->data)
        {
            reverseLL(newhead);
            return false;
        }
    }

    reverseLL(newhead);
    return true;
}

Node *evenOddLLBrute(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    vector<int> arr;
    Node *temp = head;

    while (temp != NULL && temp->next != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next->next;
    }

    if (temp)
        arr.push_back(temp->data);

    temp = head->next;
    while (temp != NULL && temp->next != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next->next;
    }

    if (temp)
        arr.push_back(temp->data);

    int i = 0;
    temp = head;

    while (temp != NULL)
    {
        temp->data = arr[i];
        i++;
        temp = temp->next;
    }

    return head;
}

int main()
{
    vector<int> arr = {1, 4, 2, 5, 3};
    Node *head = convertArr2LL(arr);

    PrintList(head);

    // bool result = palindromeLLOptimal(head);
    // cout << (result ? "True" : "False") << endl;

    Node *result = evenOddLLBrute(head);
    PrintList(result);
}