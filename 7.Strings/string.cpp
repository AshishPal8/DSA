#include <iostream>

using namespace std;

int getLength(char name[]){
    int count = 0;
    for(int i = 0; name[i] != '\0'; i++){
        count++;
    }
    return count;
}

void reverse(char name[], int n){
    int start = 0; 
    int end = n-1;

    while(start<end){
        swap(name[start++], name[end--]);
    }
}
int main()
{
    char name[20];
    cin >> name;

    int len = getLength(name);
    cout << "Your name length is " << getLength(name) << endl;

    reverse(name, len);
    cout << "Reverse is " << name << endl;
}