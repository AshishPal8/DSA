#include <iostream>
#include <deque>

using namespace std;

int main()
{

    deque<int> a;

    a.push_back(1);
    a.push_front(2);

    // a.pop_front();

    cout << endl;

    cout << a.front() << endl;
    cout << a.back() << endl;

    cout << "Element size" <<  a.size() << endl;
    a.erase(a.begin(), a.begin() + 1);
    cout << "Element size" << a.size() << endl;
}