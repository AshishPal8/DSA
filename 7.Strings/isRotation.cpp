#include <iostream>

using namespace std;

bool isRotation(const string& s, const string&t){
    if(s.size() != t.size()) return false;
    cout << "s & t: " << s << ", " << t << endl;
    if(s.empty()) return true;

    string doubled = s + s;
    cout << "doubed " << doubled << endl;

    return doubled.find(t) != string::npos;


}
int main(){
    cout << (isRotation("abcde", "bcdea") ? "True" : "False");
}