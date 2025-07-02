#include <iostream>
#include <vector>

using namespace std;

int upperBoundBrute(vector<int> arr, int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > x)
        {
            return i;
        }
    }
    return n;
}

int upperBoundOptimal(vector<int> arr, int n, int x)
{
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] > x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> a = { 3, 5, 8, 9, 15, 19};
    int n = a.size();
    int x = 9;
    // int res = upperBoundBrute(a, n, x);
    int res = upperBoundOptimal(a, n, x);

    cout << "Index is: " << res << endl;
}