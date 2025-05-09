#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findElementsBruteForce(int arr[], int n)
{
    if (n == 0 || n == 1)
    {
        cout << -1 << " " << -1 << endl;
    }
    sort(arr, arr + n);

    int small = arr[1];
    int largest = arr[n - 2];

    cout << "the smallest element is " << small << endl;
    cout << "the largest element is " << largest << endl;
}

void findElementsBetter(int arr[], int n)
{
    if (n == 0 || n == 1)
    {
        cout << -1 << " " << -1;
    }

    int small = INT_MAX, secondSmall = INT_MAX;
    int large = INT_MIN, secondLarge = INT_MIN;

    int i;
    for (i = 0; i < n; i++)
    {
        small = min(small, arr[i]);
        large = max(large, arr[i]);
    }
    for (i = 0; i < n; i++)
    {
        if (arr[i] < secondSmall && arr[i] != small)
        {
            secondSmall = arr[i];
        }
        if (arr[i] > secondLarge && arr[i] != large)
        {
            secondLarge = arr[i];
        }
    }
    cout << "Second smallest is " << secondSmall << endl;
    cout << "Second largest is " << secondLarge << endl;
}

int secondSmallest(int arr[], int n)
{
    if (n < 2)
    {
        return -1;
    }

    int small = INT_MAX;
    int secondSmall = INT_MAX;

    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] < small)
        {
            secondSmall = small;
            small = arr[i];
        }
        else if (arr[i] < secondSmall && arr[i] != small)
        {
            secondSmall = arr[i];
        }
    }

    return secondSmall;
}

int secondLargest(int arr[], int n)
{
    if (n < 2)
    {
        return -1;
    }
    int large = INT_MIN;
    int secondLarge = INT_MIN;

    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] > large)
        {
            secondLarge = large;
            large = arr[i];
        }
        else if (arr[i] > secondLarge && arr[i] != large)
        {
            secondLarge = arr[i];
        }
    }
    return secondLarge;
}

int main()
{
    int arr[] = {7, 6, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    // findElementsBruteForce(arr, n);
    // findElementsBetter(arr, n);

    int sS = secondSmallest(arr, n);
    int lL = secondLargest(arr, n);

    cout << "The smallest element is " << sS << endl;
    cout << "The largest element is " << lL << endl;

    return 0;
}