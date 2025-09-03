#include <iostream>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& s) {
    if(s.empty()) return "";

    string prefix = s[0];

    for (int i = 1; i < s.size(); i++){
        while(s[i].find(prefix) != 0){
            cout << prefix << ", " << s[i] << endl;
            prefix = prefix.substr(0, prefix.size()-1);
            if(prefix.empty()) return "";
        }
    }

    return prefix;
}

int main()
{
    vector<string> s = {"flower", "flow", "flight"};

    string result = longestCommonPrefix(s);

    cout << result << endl;
}