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
    cout << "NULL" << endl;
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

Node*  deleteAllOccurance(Node* head, int key){
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == key){
            if(temp == head) {
                head = temp->next;
            }

            Node* nextNode = temp->next;
            Node* prevNode = temp->back;
            if(nextNode != NULL) nextNode->back = prevNode;
            if(prevNode != NULL) prevNode->next = nextNode;

            free(temp);
            temp = nextNode;
        } else {
            temp = temp->next;
        }
    }
    return head;
}

Node* findTail(Node* head){
    Node* tail = head;
    while(tail->next != NULL) tail = tail->next;

    return tail;
}

vector<pair<int, int>> findAllPairs(Node* head, int key){
    vector<pair<int, int>>ans;
    Node* left = head;
    Node* right = findTail(head);

    cout << "Right: " << right->data << endl;

    while(left->data < right->data){
        if(left->data + right->data == key){
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->back;
        } else if(left->data + right->data < key){
            left = left->next;
        } else {
            right = right->back;
        }
    }

    return ans;
}

Node* removeDuplicates(Node* head){
    Node* temp = head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 9};

    Node* head = convertArr2DLL(arr);

    cout << "Double linked list: " << endl;

    PrintNode(head);

    // cout << "After insert" << endl;

    // head = insertAtTail(head, 10);
    // head = insertAtTail(head, 11);

    // PrintNode(head);

    // cout << "After insert" << endl;

    // head = deleteFromTail(head);
    // PrintNode(head);

    // cout << "Reverse DDL Brute" << endl;
    // head = reverseDDLBrute(head);
    // PrintNode(head);

    // cout << "Reverse DDL Optimal: " << endl;
    // head = reverseDDLOptimal(head);
    // PrintNode(head);

    // cout << "Remove all occurance: " << endl;
    // head = deleteAllOccurance(head, 6);
    // PrintNode(head);

    cout << "Find all pairs: " << endl;
    vector<pair<int, int>>ans = findAllPairs(head, 5);
    for(auto &p : ans ){
        cout << p.first << ", " << p.second << endl;
    }
    
}