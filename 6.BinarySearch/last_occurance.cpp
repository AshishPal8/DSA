#include <iostream>
#include <vector>

using namespace std;

int solve(int n, int key, vector<int> &a){
    int res = -1;
    for(int i = n-1; i >=0; i--){
        if(a[i] == key){
            res = i;
            break;
        }
    }
    return res;
}

int usingBinarySearch(int n, int key, vector<int>&a){
    int low = 0;
    int high = n-1;
    int res = -1;

    while(low <=high){
        int mid = (low + high)/2;

        if(a[mid] == key){
            res = mid;
            low = mid+1;
        } else if(a[mid] > key){
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    return res;
}

int main(){
    vector<int> a = {3, 4, 13, 13, 13, 20, 40};
    int key = 13;
    int n = a.size();

    // int result = solve(n, key, a);
    int result = usingBinarySearch(n, key, a);

    cout << "The index is: " << result << endl;
}