#include <iostream>
#include <vector>

using namespace std;

int findTarget(vector<int> arr, int n, int target)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int findTargetRecursion(vector<int> arr, int low, int high, int target)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;
    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
    {
        return findTargetRecursion(arr, mid + 1, high, target);
    }
    else
    {
        return findTargetRecursion(arr, low, mid - 1, target);
    }
}

int search(vector<int> arr, int n, int target)
{
    return findTargetRecursion(arr, 0, n - 1, target);
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = a.size();
    int target = 8;
    // int ans = findTarget(a, n, target);
    int ans = search(a, n, target);

    cout << "Index is: " << ans << endl;
}