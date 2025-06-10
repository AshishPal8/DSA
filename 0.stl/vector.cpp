#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;

    cout << "Capacity: " << v.capacity() << endl;

    v.push_back(1);
    cout << "Capacity: " << v.capacity() << endl;

    v.push_back(2);
    cout << "Capacity: " << v.capacity() << endl;

    v.push_back(3);
    cout << "Capacity: " << v.capacity() << endl;
    cout << "Size: " << v.size() << endl;

    cout << "Element at 2th index: " << v.at(2) << endl;
    cout << "Front: " << v.front() << endl;
    cout << "Back: " << v.back() << endl;

    cout << "Element before pop" << endl;
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    v.pop_back();

    cout << "Element after pop" << endl;
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}