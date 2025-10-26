#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> asteroidCollision(vector<int> &astroids){
    int n = astroids.size();

    vector<int> st;

    for(int i = 0; i< n; i++){
        if(astroids[i] > 0){
            st.push_back(astroids[i]);
        } else {
            while(!st.empty() && st.back() > 0 && st.back() < abs(astroids[i])){
                st.pop_back();
            }

            if(!st.empty() && st.back() == abs(astroids[i])){
                st.pop_back();
            }
            else if(st.empty() || st.back() < 0){
                st.push_back(astroids[i]);
            }
        }

    }

    return st;
}

int main(){
    vector<int> arr = {8,-8};

    vector<int> ans = asteroidCollision(arr);

    for(int i=0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}