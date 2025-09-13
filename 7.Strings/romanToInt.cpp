#include <iostream>
#include <unordered_map>

using namespace std;

int romanToInt(string s){
    unordered_map<char, int> val = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

    int total = 0;

    for (int i = 0; i < s.size(); i++)
    {
        int cur = val.at(s[i]);
        cout << i << "Current: " << cur << endl;
        int nxt = (i + 1 < s.size()) ? val.at(s[i + 1]) : 0;

        if (cur < nxt)
        {
            total -= cur;

            cout << "  char '" << s[i] << "' (" << cur << ") is < next '"
                 << s[i + 1] << "' (" << nxt << ") -> subtract: total = " << total << "\n";
        }
        else
        {
            total += cur;
            cout << "  char '" << s[i] << "' (" << cur << ") >= next ("
                 << nxt << ") -> add: total = " << total << "\n";
        }
    }

    return total;
}
int main(){
    string s = "LVIII";

    int result = romanToInt(s);
    cout << "Result: " << result << endl;
}