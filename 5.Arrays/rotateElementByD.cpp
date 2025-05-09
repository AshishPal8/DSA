#include <iostream>

using namespace std;

void rotateElementRightBrute(int arr[], int n, int k)
{
    if (n == 0)
        return;
    k = k % n;
    if (k > n)
        return;
    int temp[k];

    for (int i = n - k; i < n; i++)
    {
        temp[i - n + k] = arr[i];
    }
    for (int i = n - k - 1; i >= 0; i--)
    {
        arr[i + k] = arr[i];
    }
    for (int i = 0; i < k; i++)
    {
        arr[i] = temp[i];
    }
}

void rotateElementLeftBrute(int arr[], int n, int k)
{
    if (n == 0)
        return;
    k = k % n;
    if (k > n)
        return;
    int temp[k];

    for (int i = 0; i < n; i++)
    {
        temp[i] = arr[i];
    }
    for (int i = 0; i < n - k; i++)
    {
        arr[i] = arr[i + k];
    }
    for (int i = n - k; i < n; i++)
    {
        arr[i] = temp[i - n + k];
    }
}

// function to reverse an array
void reverse(int arr[], int start, int end)
{
    while (start <= end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void rotateEleToRightRecursion(int arr[], int n, int k)
{
    // reverse first n - k elements
    reverse(arr, 0, n - k - 1);

    // reverse last k elements
    reverse(arr, n - k, n - 1);

    // reverse whole array;
    reverse(arr, 0, n - 1);
}

void rotateEleToLeftRecursion(int arr[], int n, int k)
{
    // reverse first k elements
    reverse(arr, 0, k - 1);

    // reverse last n - k elements
    reverse(arr, k, n - 1);

    // reverse whole array;
    reverse(arr, 0, n - 1);
}

int main()
{
    int n = 7;
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int k = 2;

    // rotateElementRightBrute(arr, n, k);
    // rotateEleToRightRecursion(arr, n, k);
    // cout << "After Rotating the elements to right " << endl;

    // rotateElementLeftBrute(arr, n, k);
    rotateEleToLeftRecursion(arr, n, k);
    cout << "After Rotating the elements to left " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}