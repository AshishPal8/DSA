#include <iostream>
#include <vector>

using namespace std;

//-------------------------GFG----------------------------
// https://www.geeksforgeeks.org/problems/sort-a-string2943/1

string sortString(string s)
{
    vector<int> alpha(26, 0);
    for (int i = 0; i < s.size(); i++)
    {
        alpha[s[i] - 'a']++;
    }
    string ans;
    for (int i = 0; i < 26; i++)
    {
        char C = 'a' + i;
        while (alpha[i])
        {
            ans += C;
            alpha[i]--;
        }
    }
    return ans;
}

int main()
{
    string s = "aabbddcc";
    string ans = sortString(s);
    cout << "The answer is: " << ans << endl;
}