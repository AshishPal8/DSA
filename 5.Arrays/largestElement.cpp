#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// int sortArray(vector<int> &arr)
// {
//     sort(arr.begin(), arr.end());
//     return arr[arr.size() - 1];
// }

int largestElement(int arr[], int n)
{
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

int main()
{
    // vector<int> arr1 = {1, 2, 5, 3, 8, 4};
    // vector<int> arr2 = {10, 20, 50, 30, 80, 40};

    int arr1[] = {1, 4, 5, 8, 3, 2};
    int n = 6;

    int max = largestElement(arr1, n);

    cout << "The largest element or arr1 is " << max << endl;

    // cout << "The largest element or arr1 is " << sortArray(arr1) << endl;
    // cout << "The largest element or arr2 is " << sortArray(arr2) << endl;
}