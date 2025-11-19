#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int smallestElement(vector<int>arr, int k){
    priority_queue<int> minPq;

    for(int i = 0; i < arr.size(); i++){
        minPq.push(arr[i]);
        if(minPq.size() > k){
            minPq.pop();
        }
    }

    return minPq.top();
}

void kElements(vector<int> arr, int k){
    priority_queue<int, vector<int>, greater<int>> minPq;

    for(int i = 0; i < arr.size(); i++) {
        minPq.push(arr[i]);
        if(minPq.size() > k) {
            minPq.pop();
        }
    }

    while(minPq.size() > 0){
        cout << minPq.top() << " ";
        minPq.pop();
    }
}

void kth_Largest_And_Smallest_By_AscendingOrder(vector<int> &arr, int k){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for (int a: arr){
        cout << a << " ";
    }

    cout << "Largest: " << arr[n-k] << endl;
    cout << "Smallest: " << arr[n-1] << endl;
}

int main(){
    vector<int> arr = {7, 10, 4, 3, 20, 15};

    // int result = smallestElement(arr, 3);
    // cout << "Result: " << result << endl;>
    // kElements(arr, 3);
    kth_Largest_And_Smallest_By_AscendingOrder(arr, 3);

    return 0;
}