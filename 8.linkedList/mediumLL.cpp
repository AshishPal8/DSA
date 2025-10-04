#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Node {
    public: 
        int data;
        Node* next;

        Node(int data1, Node* next1){
            data = data1;
            next = next1;
        }

        Node(int data1){
            data = data1;
            next = nullptr;
        }
};

Node* convertArr2LL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node* tail = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        tail->next = temp;
        tail = temp;
    }
    return head;
}

void PrintList(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
        cout << "NULL" << endl;
}

Node* findMiddleNodeBrute(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* temp = head;
    int counter = 0;
    Node* middleNode = NULL;

    while(temp != NULL){
        counter += 1;
        temp = temp->next;
    }

    int mid = 0;
    temp = head;

    if(counter % 2 == 0){
        mid =  counter/2;
    } else {
        mid = (counter/2) + 1;
    }

    cout << "Mid: " << mid << endl;

    while(temp != NULL){
       mid = mid-1;


       if(mid == 0){
        break;
       }

       temp = temp-> next;
    }

    return temp;
}

Node* findMiddleNodeOptimal(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* reverseLLStack(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    //step 1: insert temp->data into stack

    stack<int> st;
    Node* temp = head;

    while(temp != NULL){
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;

    //step 2: pop stack data and put back to temp
    while(temp != NULL){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }

    return head;
}

Node* reverseLLOptimal(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* temp = head;
    Node* prev = NULL;

    while(temp != NULL){
      Node*  front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    return prev;
}

Node* reverseLLRecursion(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* newHead = reverseLLRecursion(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    
    return newHead;
}

bool detachLoopHashing(Node* head){
        Node* temp = head;
        unordered_map<Node*, int> mpp;

        while(temp != NULL){
            if(mpp.find(temp) != mpp.end()){
                return true;
            }
            mpp[temp] = 1;
            temp = temp->next;
        }

        return false;
}

bool detachLoopOptimal(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) return true;

    }
    return false;
}

Node* findStartingPointHashing(Node* head){
        Node* temp = head;
        unordered_map<Node*, int> mpp;

        while(temp != NULL){
            if(mpp.find(temp) != mpp.end()){
                return temp;
            }
            mpp[temp] = 1;
            temp = temp->next;
        }

        return NULL;

}

Node* findStartingPointOptimal(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            slow = head;

            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        };
    }
    return NULL;
}

int lengthOfLoopBrute(Node* head){
    unordered_map<Node*, int> mpp;
    Node* temp = head;
    int timer = 0;

    while(temp != NULL){
        if(mpp.find(temp) != mpp.end()){
            int loopLength = timer - mpp[temp];
            return loopLength;
        }
        mpp[temp] = timer;
        temp = temp->next;
        timer++;
    }
    return 0;
}

int findLenth(Node* slow, Node* fast){
    int cnt = 1;
    fast = fast->next;
    while(slow != fast){
        cnt++;
        fast = fast->next;
    }

    return cnt;
}
int lengthOfLoopOptimal(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return findLenth(slow, fast);
        }
    }
    return 0;
}

int main(){
    // vector<int> arr = {22, 43, 43, 2, 6, 7};

    // Node* head = convertArr2LL(arr);

    // PrintList(head);

    // cout << "Middle node Brute: " << " ";
    // Node* middleNodeBrute = findMiddleNodeBrute(head);
    // cout << middleNodeBrute->data << endl;

    // cout << "Middle node optimal: " << " ";
    // Node* middlenodeOptimal = findMiddleNodeOptimal(head);
    // cout << middlenodeOptimal->data << endl;

    // cout << "Reverse linkedlist using stack" << endl;
    // head = reverseLLStack(head); // time: 0(2n), spack: 0(n) taking extra stack space;
    // PrintList(head);

    // cout << "Reverse linkedlist using prev, back" << endl;
    // head = reverseLLOptimal(head);
    // PrintList(head);

    // cout << "Reverse linkedlist using recursion" << endl;
    // head = reverseLLRecursion(head);
    // PrintList(head);

    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth-> next = fourth;

    // if(detachLoopOptimal(head)){
    //     cout << "True" << " ";
    // } else {
    //     cout << "False" << " ";
    // }

    // Node* result = findStartingPointOptimal(head);
    // int length = lengthOfLoopBrute(head);
    int length = lengthOfLoopOptimal(head);

    cout << length << endl;
}