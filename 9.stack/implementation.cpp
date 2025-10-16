#include <iostream>
#include <stack>

using namespace std;

struct stackNode {
    int val;
    stackNode* next;
    int size;
    stackNode(int d){
        val = d;
        next = NULL;
    }

};

// class Stack {
//     int size;
//     int *arr;
//     int top;
    
//     public : 
//         Stack(){
//             top: -1;
//             size: 1000;
//             arr = new int[size];
//         }
//         void push(int x){
//             top++;
//             arr[top] = x;
//         }
//         int pop(){
//             int x = arr[top];
//             top--;
//             return x;
//         }
//         int Top(){
//             return arr[top];
//         }
//         int Size(){
//               return top + 1;
//         }
// };

class StackLinkedlist {
    stackNode* top = NULL;
    int size = 0;

    public: 
       void stackPush(int x){
            stackNode * newNode = new stackNode(x);
            newNode->next = top;
            top = newNode;
            size++;
        }

        int stackPop(){
            if(top == NULL) return -1;
            int val = top->val;
            stackNode* temp = top;
            top = top->next;
            delete temp;
            size--;
            return val;
        }

        int getTop(){
            if(top == NULL) return -1;

            return top->val;
        }

        int stackSize(){
            return size;
        }
};


int main(){
    StackLinkedlist s;

    s.stackPush(6);
    s.stackPush(3);
    s.stackPush(7);
    s.stackPush(71);
    s.stackPush(6);

    cout << "Top of stack is before deleting any element " << s.getTop() << endl;
    cout << "Size of stack is before deleting any element " << s.stackSize() << endl;
    cout << "Element deleted: " << s.stackPop() << endl;
     cout << "Size of stack after deleting an element " << s.stackSize() << endl;
//   cout << "Top of stack after deleting an element " << s.Top() << endl;
  return 0;
}