#include <iostream>
#include <vector>

using namespace std;

bool isAnagram(string s, string t)
{
    if (s.size() != t.size())
        return false;

    vector<int> freq(26, 0);

    for (char c : s)
    {
        freq[c - 'a']++;
    }

    for (char c : t)
    {
        freq[c - 'a']--;
    }

    for (int count : freq)
    {
        if (count != 0)
            return false;
    }

    return true;
}
int main()
{
    cout << (isAnagram("anagram", "nagarsm") ? "True" : "False");
}