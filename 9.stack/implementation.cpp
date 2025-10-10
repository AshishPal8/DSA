#include <iostream>
#include <stack>

using namespace std;

struct Node {
    int val;
    Node* next;
}

class Stack {
    int size;
    int *arr;
    int top;
    
    public : 
        Stack(){
            top: -1;
            size: 1000;
            arr = new int[size];
        }
        void push(int x){
            top++;
            arr[top] = x;
        }
        int pop(){
            int x = arr[top];
            top--;
            return x;
        }
        int Top(){
            return arr[top];
        }
        int Size(){
              return top + 1;
        }
};

class StackLinkedlist {
    Node* top = NULL;
    int size = 0;

    public: 
       void push(int x){
            newNode = new Node(x);
            newNode->next = top;
            top = newNode;
            size++;
        }

        int pop(){
            if(!top) return NULL;
            int val = top->val;
            temp = top;
            top = top->next;
            free(temp);
            size--;
            return val;
        }

        int top(){
            if(!top) return NULL;

            return top->val;
        }

        int size(){
            return size;
        }
}



int main(){
    StackLinkedlist s;

    s.push(6);
    s.push(3);
    s.push(7);
    s.push(71);
    s.push(6);

    cout << "Top of stack is before deleting any element " << s.top() << endl;
    cout << "Size of stack is before deleting any element " << s.size() << endl;
    cout << "Element deleted: " << s.pop() << endl;
     cout << "Size of stack after deleting an element " << s.size() << endl;
//   cout << "Top of stack after deleting an element " << s.Top() << endl;
//   return 0;
}