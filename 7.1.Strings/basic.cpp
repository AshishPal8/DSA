#include <iostream>
#include <vector>
#include <string>

using namespace std;

void swapChar(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}

string reverse(string s)
{
    int i = 0;
    int j = s.length() - 1;

    while (i < j)
    {
        swapChar(s[i], s[j]);
        i++;
        j--;
    }
    return s;
}

bool palindromeString(string s)
{
    int i = 0;
    int j = s.length() - 1;

    while (i < j)
    {
        if (!isalnum(s[i]))
        {
            i++;
            continue;
        }

        if (!isalnum(s[j]))
        {
            j--;
            continue;
        }

        if (tolower(s[i]) != tolower(s[j]))
            return false;

        i++;
        j--;
    }
    return true;
}

int nonRepeatingChar(string s)
{
    vector<int> freq(26, 0);

    for (int i = 0; i < s.size(); i++)
    {
        freq[s[i] - 'a']++;
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (freq[s[i] - 'a'] == 1)
            return i;
    }

    return -1;
}

bool isAnagram(string s, string t)
{
    vector<int> freq(26, 0);

    if (s.length() != t.length())
    {
        return false;
    }

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
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s = "anagram", t = "nagarama";

    cout << s.length() << endl;
    cout << s[0] << endl;

    // reverse string
    string reversedString = reverse(s);
    cout << reversedString << endl;

    // is palindrome
    bool palindrome = palindromeString(s);
    cout << palindrome << endl;

    // non-repeating charactor in a string
    int index = nonRepeatingChar(s);
    cout << "Non-Repeating Char: " << index << endl;

    bool anagram = isAnagram(s, t);
    cout << "is Strigns anagram: " << anagram << endl;
}