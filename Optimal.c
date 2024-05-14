#include <stdio.h>
#include <stdlib.h>

int search(int key, int *fr, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (fr[i] == key)
        {
            return 1;
        }
    }
    return 0;
}

int predict(int *pg, int *fr, int pn, int index, int size)
{
    int res = -1, farthest = index;
    for (int i = 0; i < size; i++)
    {
        int j;
        for (j = index; j < pn; j++)
        {
            if (fr[i] == pg[j])
            {
                if (j > farthest)
                {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        if (j == pn)
            return i;
    }
    return (res == -1) ? 0 : res;
}

void optimalPage(int *pg, int pn, int fn)
{
    int *fr = (int *)malloc(fn * sizeof(int));
    int hit = 0;
    for (int i = 0; i < pn; i++)
    {
        if (search(pg[i], fr, fn))
        {
            hit++;
            continue;
        }
        if (fn > 0)
        {
            fr[fn - 1] = pg[i];
            fn--;
        }
        else
        {
            int j = predict(pg, fr, pn, i + 1, fn);
            fr[j] = pg[i];
        }
    }
    printf("No. of hits = %d\n", hit);
    printf("No. of misses = %d\n", pn - hit);
    free(fr);
}

int main()
{
    int pn, fn;

    printf("Enter the number of pages in the sequence: ");
    scanf("%d", &pn);

    int *pg = (int *)malloc(pn * sizeof(int));

    printf("Enter the page sequence:\n");
    for (int i = 0; i < pn; i++)
    {
        printf("Page %d: ", i + 1);
        scanf("%d", &pg[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &fn);

    optimalPage(pg, pn, fn);

    free(pg);
    return 0;
}
