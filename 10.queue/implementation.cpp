#include <iostream>

using namespace std;

// ------------------------QUEUE WITH ARRAY ------------------------------
// class Queue {
//   int * arr;
//   int start, end, currSize, maxSize;
//   public:
//     Queue() {
//       arr = new int[16];
//       start = -1;
//       end = -1;
//       currSize = 0;
//     }

//   Queue(int maxSize) {
//     ( * this).maxSize = maxSize;
//     arr = new int[maxSize];
//     start = -1;
//     end = -1;
//     currSize = 0;
//   }
  
//   void push(int newElement) {
//     if (currSize == maxSize) {
//       cout << "Queue is full\nExiting..." << endl;
//       exit(1);
//     }
//     if (end == -1) {
//       start = 0;
//       end = 0;
//     } else
//       end = (end + 1) % maxSize;
//     arr[end] = newElement;
//     cout << "The element pushed is " << newElement << endl;
//     currSize++;
//   }
//   int pop() {
//     if (start == -1) {
//       cout << "Queue Empty\nExiting..." << endl;
//     }
//     int popped = arr[start];
//     if (currSize == 1) {
//       start = -1;
//       end = -1;
//     } else
//       start = (start + 1) % maxSize;
//     currSize--;
//     return popped;
//   }
//   int top() {
//     if (start == -1) {
//       cout << "Queue is Empty" << endl;
//       exit(1);
//     }
//     return arr[start];
//   }
//   int size() {
//     return currSize;
//   }

// };

//----------------------------------QUEUE WITH LINKEDLIST----------------------------------------
class QueueNode {
  public : 
    int val;
    QueueNode *next;

    QueueNode (int x){
      val = x;
      next = NULL; 
    }
};

QueueNode * Front = NULL, *Rare = NULL;

class Queue {
  public: 
    int size = 0;
    bool Empty();
    void Enqueue(int value);
    void Dequeue();
    int Peek();
};

bool Queue :: Empty()  {
  return Front == NULL;
}

int Queue :: Peek() {
  if(Empty()){
    cout << "Queue is empty" << endl;
    return -1;
  }

  return Front->val;
}

void Queue :: Enqueue(int x){
  QueueNode *Temp;
    Temp = new QueueNode(x);
    if(Temp == NULL){
      cout << "Queue is full" << endl;
    }
    else if(Front == NULL){
      Front = Temp;
      Rare = Temp;
    } else {
      Rare->next = Temp;
      Rare = Temp;
    }

    cout << x << " inserted into queue" << endl;
    size++;
}

void Queue :: Dequeue(){
  if(Front == NULL){
    cout << "Queue is empty" << endl;
  }
  cout << Front->val << " Removed from queue" << endl;
  QueueNode * Temp = Front;
  Front = Front->next;
  delete Temp;
  size--;
}


int main() {
  Queue q;
  q.Enqueue(4);
  q.Enqueue(14);
  q.Enqueue(24);
  q.Enqueue(34);
  q.Dequeue();
  // cout << "The peek of the queue before deleting any element " << q.top() << endl;
  // cout << "The size of the queue before deletion " << q.size() << endl;
  // cout << "The first element to be deleted " << q.pop() << endl;
  // cout << "The peek of the queue after deleting an element " << q.top() << endl;
  // cout << "The size of the queue after deleting an element " << q.size() << endl;

   cout<<"The size of the Queue is "<<q.size<<endl;
    cout<<"The Peek element of the Queue is "<<q.Peek()<<endl;
    return 0;
    
}