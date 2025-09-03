#include <iostream>
#include <vector>

using namespace std;

//----------------------LEETCODE-------------------------
// https://leetcode.com/problems/check-if-the-sentence-is-pangram/

bool checkIsPangram(string s){
    vector<bool>alpha(26, 0);

    for(int i = 0; i<s.size(); i++){
        alpha[s[i] - 'a'] = 1;
    }

    for(int i = 0; i<26; i++){
        if(alpha[i] == 0) return 0;
    }
    return 1;
}


int main()
{
    string s = "thequickbrownfoxjumpsoverthelazydog";

    bool result = checkIsPangram(s);

    cout << "Result is: " << result << endl;
}