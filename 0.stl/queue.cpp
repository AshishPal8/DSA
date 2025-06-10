#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<string> q;

    q.push("Hello");
    q.push("There");
    q.push("How are you !");

    cout << "Element on first: " << q.front() << endl;

    q.pop();

    cout << "Element on first: " << q.front() << endl;

    cout << "Size of queue: " << q.size() << endl;
}