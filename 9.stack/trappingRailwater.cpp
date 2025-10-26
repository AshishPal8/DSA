#include <iostream>
#include <vector>

using namespace std;

int trappingRainwaterBrute(vector<int> &height){
    int n = height.size();
    vector<int> lmax(n, 0);
    vector<int> rmax(n, 0);

    lmax[0] = height[0];
    rmax[n-1] = height[n-1];

    for(int i = 1; i <= n; i++){
        lmax[i] = max(lmax[i-1], height[i]);
    }
    for(int i = n-2; i >=0; i--){
        rmax[i] = max(rmax[i+1], height[i]);
    }

    int ans = 0; 
    for(int i = 0; i<= n; i++){
        ans += min(lmax[i], rmax[i]) - height[i];
    }

    return ans;
}

// int trappingRainwaterOptimal(vector<int> &height){
//     int n = height.size();
//     int l = 0, r = n-1;
//     int lmax = 0, rmax = 0;
//     int ans = 0;
    
//     while(l < r){
//         lmax = max(lmax, height[l]);
//         rmax = max(rmax, height[r]);

//         if(lmax < rmax){
//             ans += lmax - height[l];
//             l++;
//         } else {
//             ans += rmax - height[r];
//             r--;
//         }
//     }

//     return ans;


// }

int main(){
    vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};

    int ans = trappingRainwaterBrute(arr);
    // int ans1 = trappingRainwaterOptimal(arr);

    cout << "Answer is: " << ans << endl;
    // cout << "Answer 1 is: " << ans1 << endl;
}