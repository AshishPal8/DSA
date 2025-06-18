#include <iostream>
#include <vector>

using namespace std;

int findMaxConsicutiveOnes(vector<int> &a)
{
    int cnt = 0;
    int maxi = 0;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == 1)
        {
            cnt++;
        }
        else
        {
            cnt = 0;
        }

        maxi = max(maxi, cnt);
    }

    return maxi;
}

int main()
{
    vector<int> a = {1, 1, 1, 1, 1, 0, 0, 0, 1, 1};
    int ans = findMaxConsicutiveOnes(a);

    cout << "Maximum consicutive ones are: " << ans << endl;
    return 0;
}