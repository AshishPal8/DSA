#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> findNextGreater1(vector<int> &nums)
{
    stack<int> st;
    int n = nums.size();
    vector<int>
        res(n);

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums[i])
            st.pop();

        if (st.empty())
            res[i] = -1;

        else
            res[i] = st.top();
        st.push(nums[i]);
    }

    return res;
}

vector<int> findNextGreater2(vector<int> &nums)
{
    int n = nums.size();
    vector<int> res(n, -1);

    for (int i=0; i< n; i++)
    {
        int currEle = nums[i];
        for(int j = 1; j < n; j++){
            int ind = (j+i) % n;

            if(nums[ind] > currEle){
                res[i] = nums[ind];
                break;
            }
        }
    }



    return res;
}

vector<int> findNextSmall(vector<int> &nums)
{
    stack<int> st;
    int n = nums.size();
    vector<int>
        res(n);

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() >= nums[i])
            st.pop();

        if (st.empty())
            res[i] = -1;

        else
            res[i] = st.top();
        st.push(nums[i]);
    }

    return res;
}


int main()
{
    vector<int> arr = {4, 8, 5, 2, 25};
    vector<int> result = findNextSmall(arr);
    for (int x : result)
    {
        cout << x << " ";
    }

    return 0;
}