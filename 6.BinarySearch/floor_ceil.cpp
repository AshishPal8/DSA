#include <iostream>
#include <vector>

using namespace std;

int findFloor(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] <= x)
        {
            ans = arr[mid];
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int findCeil(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= x)
        {
            ans = arr[mid];
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

pair<int, int> getFloorAndCeil(int arr[], int n, int x)
{
    int f = findFloor(arr, n, x);
    int c = findCeil(arr, n, x);
    return make_pair(f, c);
}

int main()
{
    int a[] = {2, 3, 4, 7, 8};
    int n = 5;
    int x = 2;

    pair<int, int> ans = getFloorAndCeil(a, n, x);

    cout << "The floor and ceil are: " << ans.first
         << " " << ans.second << endl;
    return 0;
}