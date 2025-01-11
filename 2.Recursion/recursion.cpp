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

void printNumber(int i, int n)
{
    if (i >= n)
        return;
    cout << n - i << endl;

    printNumber(i + 1, n);
}

void printNumberUsingBacktracking(int i, int n)
{
    if (i > 1)
        return;

    printNumberUsingBacktracking(i + 1, n);
    cout << i << endl;
}

void sumOfNNumbersParameterised(int i, int sum)
{
    if (i < 0)
    {
        cout << sum;
        return;
    }

    sumOfNNumbersParameterised(i - 1, sum + i);
}

int sumOfNNumbersFunctional(int n)
{
    if (n == 0)
        return 0;

    return n + (sumOfNNumbersFunctional(n - 1));
}

int factorialOfNNumbers(int n)
{
    if (n == 0)
        return 1;

    return n * (factorialOfNNumbers(n - 1));
}

int main()
{
    int n;
    string s;
    cin >> n;
    cin >> s;

    cout << factorialOfNNumbers(n);
}