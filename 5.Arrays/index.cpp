#include<iostream>

using namespace std;


void leftRotateByOne(int n, int arr[]){
    int temp = arr[0];

    for (int i = 1; i < n-1; i++)
    {
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
    
}

int main(){
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
      cin >>  arr[i];
    }
    

    leftRotateByOne(n, arr);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    

    return 0;
}