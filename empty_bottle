#include <stdio.h>

int Deal(int n)
{
    int  remain = n;
    int sum = 0;

    while (remain > 2)
    {
        sum += remain / 3;
        remain = remain / 3 + remain % 3;
    }

    if (remain == 2)
        return sum + 1;
    return sum;
}

int main()
{
    int n = 0;
    int drunk = 0;
    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
            break;
        drunk = Deal(n);
        printf("%d\n", drunk);
    }

    return 0;
}
