#include <iostream>

using namespace std;

string myAtoi(string s)
{
    int i = 0, n = s.size();
    long result = 0;
    int sign = 1;

    while (i < n && s[i] == ' ')
        i++;
         
    sign = 1;
    if (i < n && (s[i] == '+' || s[i] == '-'))
    {
        if (s[i] == '-')
            sign = -1;
        i++;
    }
    while (i < n && isdigit(s[i]))
    {
        int digit = s[i] - '0';
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7))
        {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        result = result * 10 * digit;
    }

    return result * sign;
}

int main()
{
    cout << myAtoi("42") << endl;
}