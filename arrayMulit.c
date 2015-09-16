/* 
    从数组中N元素中找出N-1个子元素得出相乘最大值 
    不是通过排序得到结果，而是从数据游标切割获得最大值
*/

#include <stdio.h>

int getValue(int a[], int begin, int end)
{
    int result = 1;

    while (begin < end)
        result *= a[begin++];

    return result;
}

int main()
{
    int a[] = {3, 22, 10, 7, 2, 9, 8};
    int len = sizeof(a) / sizeof(int);
    int left = 0;
    int right = 0;
    int max = 0;
    int index = -1;
    int pivot = 0;

    for (; pivot<len; pivot++)
    {
        left = getValue(a, 0, pivot);
        right = getValue(a, pivot+1, len);

        if (left*right > max)
        {
            max = left * right;
            index = pivot;
        }
    }

    printf("%d, index %d \n", max, index);

    return 0;
}
