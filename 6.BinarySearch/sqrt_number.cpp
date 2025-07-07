#include <iostream>
#include <math.h>

using namespace std;

int sqrtBrute(int n)
{
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        if (i * i <= n)
        {
            ans = i;
        }
        else
        {
            break;
        }
    }
    return ans;
}

int floorSqrt(int n)
{
    int res = sqrt(n);
    return res;
}
int sqrtBinarySearch(int n)
{
    int low = 0, high = n - 1;
    int ans = 1;

    while (low <= high)
    {
        long long mid = (low + high) / 2;

        if ((mid * mid) <= n)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int n = 19;
    // int ans = sqrtBrute(n);
    // int ans = floorSqrt(n);
    int ans = sqrtBinarySearch(n);
    cout << "Answer is: " << ans << endl;
}