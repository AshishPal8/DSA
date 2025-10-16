#include <iostream>
#include <queue>

using namespace std;

class StackUsingSingleQueue {
    private: 
     queue<int> q;
    public: 
        void push(int x) {
            q.push(x);
            int n = q.size();
            for(int i = 0; i < n-1; i++){
                int v = q.front();
                q.pop();
                q.push(v);
            }
        }

        void pop(){
            if(q.empty()){
                cout << "Stack is empty" << endl;
            }
            q.pop();
        }

        int top(){
            if(q.empty()){
                cout << "Stack is empty" << endl;
                return -1;
            }
            return q.front();
        }
        
        bool empty(){
            return q.empty();
        }
        int size(){
            return q.size();
        }
};

int main(){
    StackUsingSingleQueue s;

    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Size is: " << s.size() << endl;
    s.pop();
    cout << "Size is: " << s.size() << endl;
}