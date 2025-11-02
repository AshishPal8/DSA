#include <iostream>
#include <vector>

using namespace std;

int longestOnesBrute(vector<int> &arr, int k){
    int maxlen = 0; 
    for(int i = 0; i < arr.size(); i++){
        int zeros = 0;

        for(int j = i; j < arr.size(); j++){
            if(arr[j] == 0){
                zeros++;
            }

            if(zeros > k){
                break;
            }

            int currLen = j-i+1;
            maxlen = max(maxlen, currLen);
        }
    }

    return maxlen;
}

int longestOnesBetter(vector<int> &arr, int k){
    int l = 0; 
    int zeros = 0; 
    int maxlen = 0; 

    for(int r = 0; r < arr.size(); r++){
        if(arr[r] == 0){
            zeros++;
        }

        while(zeros > k){
            if(arr[l] == 0){
                zeros--;
            }
            l++;
        }

        maxlen = max(maxlen, r - l +1);
    }

    return maxlen;
}

int longestOnesOptimal(vector<int> &arr, int k){
    int l = 0; 
    int zeros = 0; 
    int maxlen = 0; 

    for(int r = 0; r < arr.size(); r++){
        if(arr[r] == 0){
            zeros++;
        }

        //update while to if
        if(zeros > k){
            if(arr[l] == 0){
                zeros--;
            }
            l++;
        }

        maxlen = max(maxlen, r - l +1);
    }

    return maxlen;
}

int main(){
    vector<int> nums = {1, 1, 0, 0, 1, 1, 1};
    int k = 2;

    // int result = longestOnesBrute(nums, k);
    // int result = longestOnesBetter(nums, k);
    int result = longestOnesOptimal(nums, k);

    cout << "Result: " << result << endl;

    return 0;
}