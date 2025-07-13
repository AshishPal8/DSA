#include <iostream>
#include <vector>

using namespace std;

struct Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *convertToLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

//------------------CODING NINJAS----------------------
// https://www.naukri.com/code360/problems/count-nodes-of-linked-list_5884
int lengthOfLL(Node *head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp)
    {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

int checkIfPresent(Node *head, int val)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->data == val)
            return 1;
        temp = temp->next;
    }
    return 0;
}

//------------------CODING NINJAS----------------------
// https : // www.naukri.com/code360/problems/search-in-a-linked-list_975381

int main()
{
    vector<int> arr = {2, 3, 4, 5};
    Node *head = convertToLL(arr);
    // Node* temp = head;
    // while(temp){
    //     cout << temp-> data << " ";
    //     temp = temp-> next;
    // }

    // cout << lengthOfLL(head);
    cout << checkIfPresent(head, 1);
}