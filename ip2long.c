//在PHP中是ip2long，long2ip，对应的C实现代码

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//gcc -lm

long ip2long(char *address)
{
    long result = 0;

    char *s = strdup(address);
    char *token = NULL;
    int i = 0;
    int ip[4] = {0};

    while ((token = strsep(&s, ".")) != NULL)
    {
        int v = atoi(token);
        ip[i++] = v;
    }

    i = 0;

    do
    {
        result += pow(256, 3-i) * ip[i];
        i++;

    }while(i<4);

    return result;
}

int main()
{
    char ip[] = "111.13.89.118";
    long val = ip2long(ip);
    printf("%ld\n", val);

    return 0;
}
