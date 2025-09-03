#include <iostream>
#include <vector>

using namespace std;

bool isIsomorphic(string s, string t)
{
    if (s.length() != t.length())
        return false;

    vector<int> mapS(256, -1);
    vector<int> mapT(256, -1);

    for (int i = 0; i < s.length(); i++)
    {
        char c1 = s[i];
        char c2 = t[i];

        if (mapS[c1] != -1 && mapS[c1] != c2)
            return false;
        if (mapT[c2] != -1 && mapT[c2] != c1)
            return false;

        mapS[c1] = c2;
        mapT[c2] = c1;
    }

    return true;
}

int main()
{
    string s = "egg";
    string t = "add";

    bool result = isIsomorphic(s, t);
    if (result)
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
}