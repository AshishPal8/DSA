#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;

    Node(int data1, Node *next1, Node *back1){
        data = data1;
        next = next1;
        back = back1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertArr2DLL(vector<int> arr)
{
    Node *head = new Node(arr[0]);

    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void PrintNode(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << "->";
        head = head->next;

    }
    cout << endl;
}

Node* insertAtTail(Node* head, int k){
    Node* newNode = new Node(k);

    if(head == nullptr){
        return newNode;
    }

    Node* tail = head;
    while(tail->next != nullptr){
        tail = tail->next;
    }

    tail->next = newNode;
    newNode->back = tail;

    return head;
}

Node * deleteFromTail(Node* head){
    if(head == nullptr || head->next == nullptr){
        return NULL;
    }

    Node* tail = head;
    while(tail->next != nullptr){
        tail = tail-> next;
    }
    Node* prev = tail->back;
    prev->next = nullptr;
    delete tail;

    return head;
}

Node* reverseDDLBrute(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    stack<int> st;
    Node* temp = head;

     while (temp != NULL) {
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;

    while(temp != NULL){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }

    return head;

}

Node* reverseDDLOptimal(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* prev = NULL;

    Node* current = head;

    while(current != NULL){
        prev = current->back;
        current->back = current->next;
        current->next = prev;
        current = current->back;
    }

    return prev->back;
}

int main()
{
    vector<int> arr = {22, 43, 43, 2, 6, 7};

    Node* head = convertArr2DLL(arr);

    cout << "Double linked list: " << endl;

    PrintNode(head);

    cout << "After insert" << endl;

    head = insertAtTail(head, 10);
    head = insertAtTail(head, 11);

    PrintNode(head);

    cout << "After insert" << endl;

    head = deleteFromTail(head);
    PrintNode(head);

    cout << "Reverse DDL Brute" << endl;
    head = reverseDDLBrute(head);
    PrintNode(head);

    cout << "Reverse DDL Optimal: " << endl;
    head = reverseDDLOptimal(head);
    PrintNode(head);
}