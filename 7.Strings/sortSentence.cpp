#include <iostream>
#include <vector>
#include <string>

using namespace std;

string sortSentence(string s)
{
    vector<string> ans(10);
    string temp;
    int count = 0, index = 0;

    while (index < s.size())
    {
        if (s[index] == ' ')
        {
            int pos = temp[temp.size() - 1] - '0';
            ans[pos] = temp;
            temp.clear();
            count++;
        }
        else
        {
            temp += s[index];
            index++;
        }
    }
    int pos = temp[temp.size() - 1] - '0';
    ans[pos] = temp;
    temp.clear();
    count++;

    for (int i = 0; i <= count; i++)
    {
        temp = ans[i];
        temp += " ";
    }
    temp.pop_back();
    return temp;
}

// https://leetcode.com/problems/sorting-the-sentence/description/
int main()
{
    string s = "is2 sentence4 This1 a3";

    string res = sortSentence(s);

    cout << "The result is: " << res << endl;
}