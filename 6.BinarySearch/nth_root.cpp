#include <iostream>

using namespace std;

int func(int b, int exp){
    long long ans = 1;
    long long base = b;

    while(exp >0){
        if(exp%2){
            exp--;
            ans = ans*base;
        } else {
            exp /=2;
            base = base*base;
        }
    }
    return ans;
}

int nthRoot(int n, int m){
    for(int i = 1; i <=m; i++){
        long long val = func(i, n);
        if(val == m) return i;
        else if(val > m) break;
    }
    return -1;
}

int funcBinary(int mid, int n, int m){
    long long ans = 1;
    for(int i = 1; i<=n; i++){
        ans = ans*mid;
        if(ans>m) return 2;
    }
    if(ans == m) return 1;

    return 0;
}

int nthRootBinary(int n, int m){
    int low = 1, high = m;
    while (low<=high)       
    {
        int mid = (low+high)/2;
        int midN = funcBinary(mid, n, m);
        if(midN == 1) return mid;
        else if(midN == 0) low = mid+1;
        else high = mid-1;
    }

    return -1;
}

int main(){
    int n = 3, m = 27;
    int ans = nthRootBinary(n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}