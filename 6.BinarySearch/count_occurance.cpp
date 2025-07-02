#include <iostream>
#include <vector>

using namespace std;

int countBrute(vector<int>&a, int n, int t){
    int count = 0;
    for(int i = 0; i<= n-1; i++){
        if(a[i] == t) count++;
    }
    return count;
}

int firstOccurance(vector<int>&arr, int n, int t){
    int low = 0, high = n-1;
    int first = -1;

    while(low <=high){
        int mid = (low+high)/2;
        if(arr[mid] == t){
            first = mid;
            high = mid-1;
        } else if(arr[mid] < t){
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    return first;
}
int lastOccurance(vector<int>&arr, int n, int t){
    int low=0,high=n-1;
    int last = -1;

    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] == t){
            last = mid;
            low = mid+1;
        } else if(arr[mid] < t){
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    return last;
}

pair<int, int> firstAndLastOccurance(vector<int>&arr, int n, int t){
    int first = firstOccurance(arr, n, t);
    if(first == -1) return {-1, -1};
    int last = lastOccurance(arr, n, t);
    return {first, last};
}

int count(vector<int>&arr, int n, int t){
    pair<int, int> ans = firstAndLastOccurance(arr, n, t);
    if(ans.first == -1) return 0;

    return (ans.second - ans.first+1);
}
int main(){
    vector<int> a = {2, 4, 6, 8, 8, 8, 11, 13};
    int n = a.size();
    int t = 8;

    // int result = countBrute(a, n, t);
    int result = count(a, n, t);

    cout << "Count is: " << result << endl;
}