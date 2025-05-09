#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int removeDuplicatesBrute(int arr[], int n)
{
    set<int> set;
    for (int i = 0; i < n; i++)
    {
        set.insert(arr[i]);
    }

    int k = set.size();

    int j = 0;
    for (int x : set)
    {
        arr[j++] = x;
    }

    return k;
}

int removeDuplicatesOptimal(int arr[], int n)
{
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (arr[i] != arr[j])
        {
            i++;
            arr[i] = arr[j];
        }
    }
    return i + 1;
}

int main()
{
    int arr[] = {1, 1, 2, 2, 2, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    // int k = removeDuplicatesBrute(arr, n);
    int k = removeDuplicatesOptimal(arr, n);
    cout << "The elements are after removing: " << endl;

    for (int i = 0; i < k; i++)
    {
        cout << arr[i] << " ";
    }
}