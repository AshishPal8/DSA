#include <iostream>
#include <string>

using namespace std;

string largestOdd(string s)
{
    for (int i = s.size() - 1; i >= 0; i--)
    {
        int digit = s[i] - '0';

        if (digit % 2 == 1)
        {
            return s.substr(0, i + 1);
        }
    }
    return "";
}

int main()
{
    string s = "12345";

    string result = largestOdd(s);

    cout << result << endl;
}