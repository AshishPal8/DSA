#include <iostream>
#include <vector>

using namespace std;

string reverseWords(string s)
{
    vector<string> words;
    string word = "";

    for (char c : s)
    {
        if (c == ' ')
        {
            if (!word.empty())
            {
                words.push_back(word);
                word = "";
                cout << "First: " << word << endl;
            }
        }
        else
        {
            word = word + c;
            cout << "Second: " << word << endl;
        }
    }

    if (!word.empty())
        words.push_back(word);

    reverse(words.begin(), words.end());
    cout << "third: ";
    for (const auto &w : words)
    {
        cout << w << " ";
    }
    cout << endl;

    string result = "";
    for (int i = 0; i < words.size(); i++)
    {
        result += words[i];
        if (i != words.size() - 1)
            result += " ";
    }

    return result;
}

int main()
{
    string s = "the sky is blue";

    string result = reverseWords(s);

    cout << result << endl;
}