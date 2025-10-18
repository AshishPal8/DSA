#include <iostream>
#include <stack>

using namespace std;

int precedence(const string &op)
{
    if (op == "^")
        return 3;
    if (op == "*" || op == "/")
        return 2;
    if (op == "+" || op == "-")
        return 2;
    return 0;
}

void infixToPostfix(string s)
{
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'B') || (c >= '0' && a <= '9'))
        {
            result += c;
        }
        else if (c == '(')
        {
            st.push('(');
        }
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && precedence(s[i]) <= precedence(st.top()))
            {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    cout << "Prefix Expression: " << result << endl;
}

string prefixToInfix(string prefix)
{
    stack<string> st;
    int n = prefix.size();

    for (int i = n - 1; i >= 0; i--)
    {
        char c = prefix[i];

        if (isalnum(c))
        {
            st.push(string(1, c));
        }
        else
        {
            string opt1 = st.top();
            st.pop();
            string opt2 = st.top();
            st.pop();

            st.push("(" + opt1 + c + opt2 + ")");
        }
    }

    return st.top();
}

string prefixToPostfix(string prefix)
{
    stack<string> st;
    int n = prefix.size();

    for (int i = n - 1; i >= 0; i--)
    {
        char c = prefix[i];

        if (isalnum(c))
        {
            st.push(string(1, c));
        }
        else
        {
            string opt1 = st.top();
            st.pop();
            string opt2 = st.top();
            st.pop();

            st.push(opt1 + opt2 + c);
        }
    }
    return st.top();
}

string postfixToPrefix(string postfix)
{
    stack<string> st;
    int n = postfix.size();

    for (int i = 0; i < n; i++)
    {
        char c = postfix[i];

        if (isalnum(c))
        {
            st.push(string(1, c));
        }
        else
        {
            string opt1 = st.top();
            st.pop();
            string opt2 = st.top();
            st.pop();

            st.push(c + opt2 + opt1);
        }
    }
    return st.top();
}

string postfixToInfix(string postfix)
{
    stack<string> st;
    int n = postfix.size();

    for (int i = 0; i < n; i++)
    {
        char c = postfix[i];

        if (isalnum(c))
        {
            st.push(string(1, c));
        }
        else
        {
            string opt2 = st.top();
            st.pop();
            string opt1 = st.top();
            st.pop();

            st.push("(" + opt1 + c + opt2 + ")");
        }
    }
    return st.top();
}

int main()
{
    // string prefix = "*-A/BC-/AKL";
    string postfix = "ABC/-AK/L-*";
    // cout << "Infix Expression: " << prefixToInfix(prefix) << endl;
    // cout << "Postfix Expression: " << prefixToPostfix(prefix) << endl;
    cout << "Prefix Expression: " << postfixToPrefix(postfix) << endl;
    cout << "Infix Expression: " << postfixToInfix(postfix) << endl;
    return 0;
}