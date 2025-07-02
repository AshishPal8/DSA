#include <iostream>
#include <vector>

using namespace std; 

int searchInsertPosition(vector<int> arr, int n, int x){
    int low = 0, high = n-1;
    int ans = n;

    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] >= x){
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid+1;
        }
    }
    return ans;
}


int main(){
    vector<int> a = {1,2, 3, 4, 5, 7};
    int n = a.size();
    int x = 6;

    int res = searchInsertPosition(a, n, x);

    cout << "Position is: " << res << endl;
}