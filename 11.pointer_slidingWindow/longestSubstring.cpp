#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int longestSubstringBrute(string str){
    if(str.size() == 0) return 0;
    int maxlen = INT_MIN;

    for(int i = 0; i < str.length(); i++){
        unordered_set<int> set;

        for(int j = i; j <= str.length(); j++){
            if(set.find(str[j]) != set.end()){
                maxlen = max(maxlen, j -i);
                break;
            }
            set.insert(str[j]);
        }
    }

    return maxlen;
}

int longestSubstringBrute1(string str){
    if(str.size() == 0) return 0;
    int maxlen = INT_MIN;
    unordered_set<int> set;
    int l = 0;

    for(int r = 0;r < str.length(); r++){
        if(set.find(str[r]) != set.end()){
            while(l < r && set.find(str[r]) != set.end()){
                set.erase(str[l]);
                l++;
            }
        }
        set.insert(str[r]);
        maxlen = max(maxlen, r-l+1);
    }

    return maxlen;
}

int main (){
    string s = "abcaabcda";
    int result = longestSubstringBrute1(s);

    cout << result << endl;
    return 0;
}