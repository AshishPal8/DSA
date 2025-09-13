#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

string frequencySort_bruteforce(string s)
{
    int n = s.size();
    vector<bool> used(n, false);

    cout << "Used: ";
    for (bool val : used)
    {
        cout << val;
    }
    cout << "\n";

    vector<pair<char, int>> pairs;

    for (int i = 0; i < n; i++)
    {
        if (used[i])
            continue;
        char c = s[i];
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (!used[j] && s[j] == c)
            {
                used[j] = true;
                cnt++;

                cout << "Used for J: " << used[j] << endl;
            }
        }
        pairs.push_back({c, cnt});
        cout << "Found char '" << c << "' with count " << cnt << "\n";
    }

    cout << "\nBefore sort (char,count): ";
    for (auto &p : pairs)
        cout << "(" << p.first << ", " << p.second << ")";
    cout << "\n";

    sort(pairs.begin(), pairs.end(), [](auto &a, auto &b)
         { return a.second > b.second; });

    cout
        << "\nAfter sort (char,count): ";
    for (auto &p : pairs)
        cout << "(" << p.first << ", " << p.second << ")";
    cout << "\n";

    string ans;
    for (auto &p : pairs)
    {
        ans.append(p.second, p.first);

        cout << "Appending '" << p.first << "' x " << p.second
             << " -> ans = " << ans << "\n";
    }

    return ans;
}

string frequencySort_optimal(string s)
{
    unordered_map<char, int> freq;

    for (char c : s)
        freq[c]++;

    cout << "Frequency map:\n";
    for (auto &kv : freq)
    {
        cout << " " << kv.first << "' -> " << kv.second << "\n";
    }

    vector<pair<char, int>> arr(freq.begin(), freq.end());

            cout
        << "\nVector before sort (char,count): ";
    for (auto &p : arr)
    {
        cout << "(" << p.first << "," << p.second << ") ";
    }
    cout << "\n";

    sort(arr.begin(), arr.end(), [](auto &a, auto &b)
         { return a.second > b.second; });

            cout
        << "Vector after  sort (char,count): ";
    for (auto &p : arr)
        cout << "(" << p.first << "," << p.second << ") ";
    cout << "\n";

    string ans;
    for (auto &p : arr)
    {
        ans.append(p.second, p.first);
        cout << "Appending '" << p.first << "' x " << p.second
             << " -> result = " << ans << "\n";
    }

    return ans;
}
int main()
{
    cout << frequencySort_optimal("tree") << endl;
}