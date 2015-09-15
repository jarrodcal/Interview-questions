/* Remove comments from a program */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_MAX_CHAR 1024 * 1024
#define LINE_MAX_CHAR 1024

void delmulitLine(char *p);
void delLine(char *p);

char * recomment(char *str)
{
    char *p = str;
    char *pval = (char *)malloc(sizeof(char) * FILE_MAX_CHAR);
    char *pval1 = pval;

    do
    {
        if (*p == '/')
        {
            p++;

            if (*p == '*')
            {
                delmulitLine(p);
            }
            else if (*p == '/')
            {
                delLine(p);
            }
            else
            {
                *(++pval1) = '/';
                *(++pval1) = *p;
            }
        }
        else
        {
            *(++pval1) = *p;
        }

    }while(p++);

    return pval;
}

void delmulitLine(char *p)
{
    char p1 = *++p;
    char p2 = *++p;

    while ((p1 != '*') || (p2 != '/'))
    {
        printf("%c", p1);
        p1 = p2;
        p2 = *(++p);
    }
}

void delLine(char *p)
{
    while (*p++ != '\n');
}

int main()
{
    char *file = "redis-2.6.17/src/intset.c";
    FILE *pFile = fopen(file, "r");
    char content[FILE_MAX_CHAR] = {0};
    char *pcontent = content;

    char line[LINE_MAX_CHAR] = {0};
    char *pline = line;

    if (pFile == NULL)
    {
        printf("Open file error");
        return 1;
    }

    int lastlen = 0;

    while ((fgets(pline, LINE_MAX_CHAR, pFile)) != NULL)
    {
        int len = strlen(pline);
        memcpy(pcontent+lastlen, pline, len);
        memset(pline, 0, LINE_MAX_CHAR);
        lastlen += len;
    }

    fclose(pFile);
    
    char *pval = recomment(content);
    printf("%s\n", pval);

    return 0;
}
