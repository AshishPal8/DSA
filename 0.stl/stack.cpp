#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<string> s;

    s.push("Hello");
    s.push("there");
    s.push("How are you!");

    cout << "Element on top: " << s.top() << endl;

    s.pop();
    cout << "Element on top: " << s.top() << endl;

    cout << "Size of stack: " << s.size() << endl;

    // s.pop();
    // s.pop();
    cout << "Empty or not: " << s.empty() << endl;
}