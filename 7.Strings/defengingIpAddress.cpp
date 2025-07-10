#include <iostream>
#include <vector>

using namespace std;
string defengingString(string address)
{
    int index = 0;
    string ans;

    while (index < address.size())
    {
        if (address[index] == '.')
        {
            ans += "[.]";
            index++;
        }
        else
        {
            ans += address[index];
            index++;
        }
    }

    return ans;
}
// -----------------------LEETCODE--------------------------
//    https://leetcode.com/problems/defanging-an-ip-address/description/

int main()
{
    string s = "1.1.1.1";
    string res = defengingString(s);
    cout << "The result is: " << res << endl;
}