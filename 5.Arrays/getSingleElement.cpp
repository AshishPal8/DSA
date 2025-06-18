#include<iostream>
#include <vector>

using namespace std;

int getSingleElement(vector<int> &a){
    int n = a.size();

    for(int i = 0; i< n; i++){
        int num = a[i];
        int cnt = 0;

        for(int j = 0; j< n; j++){
            if(a[j] == num){
                cnt++;
            }
        }

        if(cnt == 1) return num;
    }

    return -1;
}

int main() {
    vector<int> a = {1, 2, 1, 2, 3, 4, 4};
    int res = getSingleElement(a);
    cout << "Element is: " << res << endl;
}