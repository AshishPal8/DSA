#include <iostream>

using namespace std;

string removeOutermostParenthesis(string s)
{
    string result = "";
    int count = 0;

    for (char c : s)
    {
        if (c == '(')
        {
            if (count > 0)
                result = result + c;
            count++;
        }
        else
        {
            count--;
            if (count > 0)
                result = result + c;
        }
    }

    return result;

    /*
        time complexity: O(n) - one pass through the string
        space complexity: O(1) - just the counter, not counting result string.
    */
}
int main()
{
    string s = "(()())(())(()())";

    string result = removeOutermostParenthesis(s);

    cout << result << endl;
}