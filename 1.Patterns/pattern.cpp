#include <iostream>
using namespace std;

void square(int n)

{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "*";
        };
        cout << endl;
    }
}

void rightTrialgle(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void rightTriangleNumber(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void rightTriangleNumber2(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

void rightTriangleOpposite(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void rightTriangleOppositeNumber(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void equilateralTriangle(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }

        cout << endl;
    }
}

void equilateralTriangleOpposite(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < 2 * n - (2 * i + 1); j++)
        {
            cout << "*";
        }
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }

        cout << endl;
    }
}

void rightInvertedTriangle(int n)
{

    /* first you have to go 2n - i (n = 5, you have to to go 9)
       after you have to check if it exceds the n the you go 2n - i
    */

    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int stars = i;
        if (i > n)
            stars = 2 * n - i;
        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }

        cout << endl;
    }
}

void binaryRightAngleTriangle(int n){
    /*
    for first column check for odd rows print 0 for even rows print 0
    first take variable start the start value is 1
    for j go to the i so it became right angle triangle
    flip the 0 and 1; 1 = 1-1 = 0;
    */
    int start = 1;
    for(int i = 0; i< n; i++){
        if(i % 2 == 0) start = 1;
        else start = 0;

        for(int j = 0; j<= i; j++){
            cout << start;
            start = 1-start;
        }

        cout << endl;
    }

}

void innerSpaceInvertedTrialgle(int n){
    int space = 2 * (n - 1);
    for (int i = 1; i <= n; i++){
        // start
        for(int j = 1; j <= i; j++){
            cout << j;
        }
        // space
        for (int j = 1; j <= space; j++)
        {
            cout << " ";
        }
        // stars
        for (int j = i; j >=1; j--)
        {
            cout << j;
        }

        cout << endl;
        space -= 2;
    }
}

void rightAngleTriangleNumber(int n){
    int num = 1;
    for(int i = 1; i < n; i++){
        for (int j = 1; j <= i; j++){
            cout << num << " ";
            num++;
        }

        cout << endl;
    }
}

void rightAngleAlphabet(int n){
    for(int i = 0; i< n; i++ ){
        for(char ch = 'a'; ch <= 'a' + i; ch++){
            cout << ch<< " ";
        }

        cout << endl;
    }
}
void InvertedRightAngleAlphabet(int n){
    for(int i = 0; i< n; i++ ){
        for(char ch = 'A'; ch < 'A' + (n -i); ch++){
            cout << ch<< " ";
        }

        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    InvertedRightAngleAlphabet(n);
}