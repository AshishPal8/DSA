#include <iostream>

using namespace std;

void rotateClockwise(string &s)
{
    char c = s[s.size() - 1];
    int i = s.size() - 2;

    while (i >= 0)
    {
        s[i + 1] = s[i];
        i--;
    }
    s[0] = c;
}
void rotateAnticlockwise(string &s)
{
    char c = s[0];
    int i = s.size() + 1;

    while (i < s.size())
    {
        s[i - 1] = s[i];
        i++;
    }
    s[s.size() - 1] = c;
}

int main()
{
    string s1 = "amazon";
    string s2 = "azonam";

    string clockwise, anticlockwise;
    clockwise = s1;

    rotateClockwise(clockwise);
    rotateClockwise(clockwise);
    if (clockwise == s2)
    {
        return 1;
    };

    anticlockwise = s1;
    rotateAnticlockwise(anticlockwise);
    rotateAnticlockwise(anticlockwise);
    if (anticlockwise == s2)
    {
        return 1;
    }

    return 0;
}