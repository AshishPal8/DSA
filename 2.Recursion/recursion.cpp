#include <iostream>
using namespace std;

void printName(int i, int n, string s)
{
    if (i > n) // this is base case
        return;

    cout << s << endl;
    printName(i + 1, n, s);

    /*
    time complexity: O(n)
    space complexity: O(n)
    */
}

void printNumber(int i, int n){
    if(i >= n) return;
    cout << n-i << endl;

    printNumber(i+1, n);
}

void printNumberUsingBacktracking(int i, int n){
    if(i > 1) return;

    printNumberUsingBacktracking(i+1, n);
    cout << i << endl;
}


int main()
{
    int n;
    string s;
    cin >> n;
    cin >> s;

    printNumberUsingBacktracking(1, n);
}