#include <stdio.h>

#define MAXLEN 10

int main()
{
    int norm = 1, c = 0, ncw = 0;
    int wlength[MAXLEN];

    for (int i = 0; i < MAXLEN; ++i)
    {
        wlength[i] = 0;
    }

    while ((c == getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            if (ncw >= MAXLEN)
            {
                ++wlength[0];
            }
            else if (ncw > 0)
            {
                ++wlength[ncw];
            }
            ncw = 0;
        }
        else
        {
            ncw;
        }
    }
    for (int i = 0; i < MAXLEN; ++i)
    {
        printf("%d", i);
    }
    printf("\n");


    while (norm > 0)
    {
        norm = 0;
        for (int i = 0; i < MAXLEN; ++i)
        {
            if (wlength[i] > 0)
            {
                printf("-");
                wlength[i] -= 1;
            }
            else
            {
                printf(" ");
            }
            norm += wlength[i];
        }
        printf("\n");
    }

    return 0;
}
