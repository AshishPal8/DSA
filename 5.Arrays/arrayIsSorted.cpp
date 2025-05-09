#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isSortedBrute(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                return false;
            }
        }
    }
    return true;
}

bool isSortedOptimal(int arr[], int n)
{
    if (n < 2)
    {
        return true;
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10}, n = 5;

    // bool ans = isSortedBrute(arr, n);
    bool ans = isSortedOptimal(arr, n);

    if (ans)
        cout << "True" << endl;
    else
        cout << "False" << endl;
}