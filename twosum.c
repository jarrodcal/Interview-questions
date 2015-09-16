/*  Two Sum问题，可以先进行排序，然后再进行双向查找*/

#include <stdio.h>

void getIndex(int a[], int sum, int *index1, int *index2)
{
    int i = 0;
    int j = sizeof(a) - 1;

    while (i<j)
    {
        int val = a[i] + a[j];

        if (val == sum)
        {
            *index1 = i;
            *index2 = j;
        }

        //走一遍，肯定会走到那
        if (val<sum)
            i++;
        else
            j--;
    }
}

int main()
{
    int a[] = {1, 3, 6, 9, 20, 22, 59, 100, 230};
    int sum = 31;
    int index1 = -1;
    int index2 = -1;

    getIndex(a, sum, &index1, &index2);

    printf("Sum is %d, index is %d, %d, val is %d, %d \n", sum, index1, index2, a[index1], a[index2]);

    return 0;
}
