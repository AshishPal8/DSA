#include <iostream>
#include <vector>

using namespace std;

bool isMinHeap(vector<int> & arr){
    int n = arr.size();
    if(n <= 1) return true;
    
    for(int i = 0; i < n; i++){
        int l = 2 * i + 1; 
        int r = 2 * i + 2;

        if(l < n && arr[i] > arr[l]) return false;
        if(r < n && arr[i] > arr[r]) return false;
    }

    return true;
}
int main(){
    vector<int> arr = {3, 6, 4, 5, 7};
    cout << (isMinHeap(arr) ? "True" : "False") << endl;
    return 0;

}