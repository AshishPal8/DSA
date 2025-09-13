#include <iostream>

using namespace std;

int maxDepthParenthesis(string s)
{
    int depth = 0;
    int maxDepth = 0;

    for (char c : s)
    {
        if (c == '(')
        {
            depth++;
            if (depth > maxDepth)
            {
                maxDepth = depth;
            }
        }
        else if (c == ')')
        {
            depth--;
        }
    }

    return maxDepth;
}

int main()
{
    string s = "(1+(2*3)+((8)/4))+1";

    int result = maxDepthParenthesis(s);

    cout << "Max depth: " << result << endl;
}