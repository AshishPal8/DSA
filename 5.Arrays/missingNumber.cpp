#include <iostream>
#include <vector>

using namespace std;

// int missingNumber(vector<int> &arr, int n ){

//     for (int i = 1; i <= n; i++)
//     {
//         int flag = 0;

//         for(int j = 0; j < n-1; j++){
//             if(arr[j] == i){
//                 flag = 1;
//                 break;
//             }

//         }
//         if(flag == 0) return i;
//     }

//     return -1;

// }

// int missingNumber(vector<int> &arr, int n)
// {
//     vector<int> hash(n + 1, 0);

//     for (int i = 0; i < n; i++)
//     {
//         hash[arr[i]]++;
//     }

//     for (int i = 0; i <= n-1; i++)
//     {
//         if (hash[i] == 0)
//         {
//             return i;
//         }
//     }

//     return -1;
// }

// int missingNumber(vector<int> &arr, int n){
//     int sum = (n * (n + 1)) / 2;

//     int s2 = 0;
//     for(int i = 0; i< n-1; i++){
//         s2 += arr[i];
//     }

//     int missingNumber = sum - s2;
//     return missingNumber;
// }

int missingNumber(vector<int> &arr, int n){
    int xor1 = 0, xor2 = 0;

    for(int i = 0; i < n-1; i++){
        xor2 = xor2 ^ arr[i];
        xor1 = xor1 ^ (i + 1);
    }

    xor1 = xor1 ^ n;

    return (xor1 ^ xor2);
}

int main()
{
    int N = 8;
    vector<int> a = {1, 2, 3, 4, 5, 6, 8};

    int ans = missingNumber(a, N);

    cout << "Missing element is: " << ans << endl;

    return 0;
}