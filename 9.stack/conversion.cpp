#include <iostream>
#include <stack>

using namespace std;

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

string prefixToPostfix(string prefix){
    stack<string> st;
    int n = prefix.size();

    for(int i = n-1; i >= 0; i--){
        char c = prefix[i];

        if(isalnum(c)){
            st.push(string(1, c));
        } else {
            string opt1 = st.top(); st.pop();
            string opt2 = st.top(); st.pop();

            st.push(opt1 + opt2 + c);
        }
    }
    return st.top();
}

string postfixToPrefix(string postfix){
    stack<string> st;
    int n = postfix.size();

    for(int i = 0; i < n; i++){
        char c = postfix[i];

        if(isalnum(c)){
            st.push(string(1, c));
        } else {
            string opt1 = st.top(); st.pop();
            string opt2 = st.top(); st.pop();

            st.push(c + opt2 + opt1);
        }
    }
    return st.top();
}

string postfixToInfix(string postfix){
    stack<string> st;
    int n = postfix.size();

    for(int i = 0; i< n; i++){
        char c = postfix[i];

        if(isalnum(c)){
            st.push(string(1, c));
        } else {
            string opt2 = st.top(); st.pop();
            string opt1 = st.top(); st.pop();

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