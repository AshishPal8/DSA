#include <iostream>

using namespace std;

int search(int arr[], int n, int k)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == k)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

    int ans = search(arr, n, k);
    cout << ans << " ";
}