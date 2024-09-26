#include <stdio.h>

void printFabonacci(int n)
{
    int first = 0, second = 1, next;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            next = first;
        }
        else if (i == 1)
        {
            next = second;
        }
        else
        {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%d ", next);
    }
}

int main()
{
    int n;

    scanf("%d", &n);
    printf("Fabonacci series: \n");

    printFabonacci(n);
}