
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "stringStack.c"

#define MAX_LINE 256

extern char *pop();
extern void push(char *);

int main(int argc, char *argv[])
{
    char str[20], check;
    int s, strLength = 0, tagCounter = 0;
    bool add, doesPush, good = true;

    printf("Enter tags: \n");

    while ((s = getchar()) != EOF)
    {
        if (s == '/' && check == '<')
        {
            strLength = -1;
            add = true;
            doesPush = false;
        }

        if (s == '<')
        {
            check = '<';
            strLength = -1;
            add = true;
            doesPush = true;
        }
        else if (s == '>')
        {
            check = '0';
            add = false;
            str[strLength] = '\0';

            if (doesPush)
            {
                push(str);
                tagCounter++;
            }
            else
            {
                tagCounter--;
                if (strcmp(str, pop()) != 0)
                {
                    good = false;
                    break;
                }
            }
        }

        if (add)
        {
            if (strLength == -1)
                strLength++;
            else
                str[strLength++] = s;
        }
    }

    if (tagCounter != 0 || !good)
        printf("Invalid\n");
    else
        printf("Valid\n");

    exit(0);
}