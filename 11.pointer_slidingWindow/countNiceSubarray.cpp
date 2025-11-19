#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int atMost(vector<int> &arr, int k){
    if(k < 0) return 0;

    int left = 0, res = 0;

    for(int right = 0; right < arr.size(); right++){
        if(arr[right] % 2 != 2) k--;

        while(  k < 0){
            if(arr[left] % 2 != 0) k--;
            left++;
        }
        res += (right - left + 1);
    }

    return res;
}

int numNiceSubarraysOptimal(vector<int> &arr, int k){
    return atMost(arr, k) - atMost(arr, k -1);
}

int main(){
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 2;
    // cout << numSubarraysWithSum(nums, k) << endl;
    // cout << numSubarraysWithSumBetter(nums, k) << endl;
    cout << numNiceSubarraysOptimal(nums, k) << endl;
    return 0;
}