#include <iostream>
#include <vector>

using namespace std;

int longestPalindrome(string s)
{
    vector<int> upper(26, 0);
    vector<int> lower(26, 0);

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a')
            lower[s[i] - 'a']++;
        else
            upper[s[i] - 'A']++;
    }

    int count = 0;
    bool odd = 0;

    for (int i = 0; i < 26; i++)
    {
        if (lower[i] % 2 == 0)
        {
            count += lower[i];
        }
        else
        {
            count += lower[i] - 1;
            odd = 1;
        }

        if (upper[i] % 2 == 0)
        {
            count += upper[i];
        }
        else
        {
            count += upper[i] - 1;
            odd = 1;
        }
    }
    return count + odd;
}

bool isValid(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char toLowercase(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
    {
        return ch;
    }
    else
    {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

bool checkPalindrome(string s)
{
    int start = 0;
    int end = s.length() - 1;

    while (start < end)
    {
        if (s[start] != s[end])
        {
            return false;
        }
        else
        {
            start++;
            end--;
        }
    }
    return 1;
}

int main()
{
    string s = "namam";
    string temp = "";

    for (int i = 0; i < s.length(); i++)
    {
        if (isValid(s[i]))
        {
            temp.push_back(s[i]);
        }
    }

    for (int i = 0; i < s.length(); i++)
    {
        temp[i] = toLowercase(s[i]);
    }

    bool result = checkPalindrome(s);

    cout << result << endl;
}