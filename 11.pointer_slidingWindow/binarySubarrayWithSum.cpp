#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int numSubarraysWithSum(vector<int> &arr, int k){
    int count = 0;

    for(int start = 0; start < arr.size(); start++){
        int sum = 0;

        for(int end = start; end < arr.size(); end++){
            sum += arr[end];

            if(sum == k){
                count++;
            }
        }
    }
    return count;
}

int numSubarraysWithSumBetter(vector<int> &arr, int k){
    unordered_map<int, int> prefixSumCount;

    int count = 0, sum = 0;
    prefixSumCount[0] = 1;

    for (int a : arr){
        sum += a;

        if(prefixSumCount.find(sum - k) != prefixSumCount.end()){
            count += prefixSumCount[sum-k];
        }

        prefixSumCount[sum]++;
    }

    return count;
}

int atMost(vector<int> &arr, int k){
    if(k < 0) return 0;

    int left = 0, sum = 0, count = 0;

    for(int right = 0; right < arr.size(); right++){
        sum += arr[right];

        while( sum > k){
            sum -= arr[left];
            left++;
        }
        count += (right - left + 1);
    }

    return count;
}

int numSubarraysWithSumOptimal(vector<int> &arr, int k){
    return atMost(arr, k) - atMost(arr, k -1);
}

int main(){
    vector<int> nums = {1, 0, 1, 0, 1};
    int k = 2;
    // cout << numSubarraysWithSum(nums, k) << endl;
    // cout << numSubarraysWithSumBetter(nums, k) << endl;
    cout << numSubarraysWithSumOptimal(nums, k) << endl;
    return 0;
}