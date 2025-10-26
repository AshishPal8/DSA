#include <iostream>
#include <vector>

using namespace std;

int longestSubarray(vector<int> &arr, int k){
    int n = arr.size();
    int l = 0, r = 0; 
    int sum =0, maxlen = 0;

    while(r < n){
        sum = sum + arr[r];
        if(sum > k){
            sum = sum - arr[l];
            l = l+1;
        } 
         if(sum <= k) {
            maxlen = max(maxlen, r - l + 1);
            r = r+1;
        }
    }

    return maxlen;
}

int main(){
    vector<int> arr = {2, 5,1, 8,10};

    int result = longestSubarray(arr, 14);
    cout << result << endl;

    return 0;

}