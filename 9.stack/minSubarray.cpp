#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int sumSubarrayMinsBrute(vector<int> &arr){
    int n = arr.size();

    int mod = 1e7 + 7;

    int sum = 0;

    for(int i = 0; i< n; i++){
        int mini = arr[i];
        cout << "Outer loop i: " << mini << " " << i << endl;
        for(int j = i; j < n; j++){
            cout << "Inner loop j: " <<  j << endl;
            mini = min(arr[j], mini);
            cout << "mini inner j: " << mini << endl;
            sum = (sum + mini) % mod;
            cout << "sum inner j: " << sum << endl;

        }
    }
    return sum;
}

vector<int> findNSE(vector<int> &arr){
    int n = arr.size();
    vector<int>ans(n);
    stack<int> st;

    for(int i = n-1; i >=0; i--){
        int currEle = arr[i];

        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }

        ans[i] = !st.empty() ? st.top() : n;

        st.push(i);
    }

    for(auto a: ans){
        cout << "Find NSE: " <<  a << endl;
    }

    return ans;
}

vector<int> findPSSE(vector<int> &arr){
    int n = arr.size();
    vector<int>ans(n);
    stack<int> st;

    for(int i = 0; i <n; i++){
        int currEle = arr[i];

        while(!st.empty() && arr[st.top()] > arr[i]){
            st.pop();
        }

        ans[i] = !st.empty() ? st.top() : -1;

        st.push(i);
    }

    for(auto a: ans){
        cout << "Find PSEE: " <<  a << endl;
    }

    return ans;
}
int sumbSubarrayMinsOptimal(vector<int> &arr){
    vector<int> nse = findNSE(arr);
    vector<int> psee = findPSSE(arr);

    int n = arr.size();
    int mod = 1e9 + 7;
    int sum = 0;

    for(int i = 0; i < n; i++){
        int left = i - psee[i];
        int right =  nse[i]- i;

        long long freq = left*right*1LL;
         int val = (freq*arr[i]*1LL) % mod;
          sum = (sum + val) % mod;
    }
    return sum;


}
int main(){
    vector<int> arr = {3, 1, 2, 5};

    // int result = sumSubarrayMinsBrute(arr);
    int result = sumbSubarrayMinsOptimal(arr);
    cout << result << endl;

}