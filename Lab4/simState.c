/*
Hello

Your personalized state machine description for Lab 4 (coe 428) follows:

A F E   0 5 4
B C F   1 2 5
C A G   2 0 6
D B D   3 1 3
E G H   4 6 7
F H C   5 7 2
G D A   6 3 0
H E D   7 4 3

Your starting state is: E
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct state
{
    // There are 8 state and each has a stateName and address when input is 0 and 1.
    struct state *nextState1;
    struct state *nextState0;
    char stateName;
    int currState;
};

// printing state
void printState(struct state s[], int del[])
{
    // int size = ;
    for (int i = 0; i < 8; i++)
    {
        if (del[i] == 0)
            printf("%c %c %c\n", s[i].stateName, s[i].nextState0->stateName, s[i].nextState1->stateName);
    }
}

void removeSpaces(char *s)
{
    char *d = s;
    do
    {
        while (*d == ' ')
        {
            ++d;
        }
    } while (*s++ = *d++);
}

int main(int argc, char *argv[])
{
    struct state s[8];               // all states
    struct state *start = &s[4];     // starting state
    struct state *currState = start; // current state
    int deleted[] = {0, 0, 0, 0, 0, 0, 0, 0};
    int size = 8;

    // setting state names', and nextState1 and nextState0 state
    // State A
    s[0].stateName = 'A';
    s[0].nextState0 = &s[5];
    s[0].nextState1 = &s[4];
    // State B
    s[1].stateName = 'B';
    s[1].nextState0 = &s[2];
    s[1].nextState1 = &s[5];
    // State C
    s[2].stateName = 'C';
    s[2].nextState0 = &s[0];
    s[2].nextState1 = &s[6];
    // State D
    s[3].stateName = 'D';
    s[3].nextState0 = &s[1];
    s[3].nextState1 = &s[3];
    // State E : current state
    s[4].stateName = 'E';
    s[4].nextState0 = &s[6];
    s[4].nextState1 = &s[7];
    // State F
    s[5].stateName = 'F';
    s[5].nextState0 = &s[7];
    s[5].nextState1 = &s[2];
    // State G
    s[6].stateName = 'G';
    s[6].nextState0 = &s[3];
    s[6].nextState1 = &s[0];
    // State H
    s[7].stateName = 'H';
    s[7].nextState0 = &s[4];
    s[7].nextState1 = &s[3];

    printf("Starting point is: %c\n\n: ", start->stateName);

    char in[3]; // input
    while (scanf("%[^\n]%*c", in) != EOF)
    {
        removeSpaces(in);
        int length = strlen(in);

        if (length == 1)
        {
            if (in[0] == '0')
            {
                printf("%c\n", (currState->nextState0)->stateName);
                currState = (currState->nextState0);
            }
            else if (in[0] == '1')
            {
                printf("%c\n", (currState->nextState1)->stateName);
                currState = (currState->nextState1);
            }
            else if (in[0] == 'p' || in[0] == 'P')
            {
                printState(s, deleted);
            }
            else if (in[0] == 'G' || in[0] == 'g' || in[0] == 'D' || in[0] == 'd')
            {
                int check[] = {0, 0, 0, 0, 0, 0, 0, 0};
                int garbage = 0;

                for (int i = 0; i < size; i++)
                {
                    if (deleted[i] == 0 && ((s[i].nextState0->stateName) == 'A' || (s[i].nextState1->stateName) == 'A'))
                    {
                        check[0]++;
                    }
                    if (deleted[i] == 0 && ((s[i].nextState0->stateName) == 'B' || (s[i].nextState1->stateName) == 'B'))
                    {
                        check[1]++;
                    }
                    if (deleted[i] == 0 && ((s[i].nextState0->stateName) == 'C' || (s[i].nextState1->stateName) == 'C'))
                    {
                        check[2]++;
                    }
                    if (deleted[i] == 0 && ((s[i].nextState0->stateName) == 'D' || (s[i].nextState1->stateName) == 'D'))
                    {
                        check[3]++;
                    }
                    if (deleted[i] == 0 && ((s[i].nextState0->stateName) == 'E' || (s[i].nextState1->stateName) == 'E'))
                    {
                        check[4]++;
                    }
                    if (deleted[i] == 0 && ((s[i].nextState0->stateName) == 'F' || (s[i].nextState1->stateName) == 'F'))
                    {
                        check[5]++;
                    }
                    if (deleted[i] == 0 && ((s[i].nextState0->stateName) == 'G' || (s[i].nextState1->stateName) == 'G'))
                    {
                        check[6]++;
                    }
                    if (deleted[i] == 0 && ((s[i].nextState0->stateName) == 'H' || (s[i].nextState1->stateName) == 'H'))
                    {
                        check[7]++;
                    }
                }

                for (int i = 0; i < size; i++)
                {
                    if (check[i] > 0)
                    {
                        garbage++;
                    }
                }

                if (in[0] == 'g' || in[0] == 'G')
                {
                    if (garbage < size)
                    {
                        printf("Garbage is: ");

                        if (check[0] < 1)
                        {
                            printf("A ");
                        }
                        if (check[1] < 1)
                        {
                            printf("B ");
                        }
                        if (check[2] < 1)
                        {
                            printf("C ");
                        }
                        if (check[3] < 1)
                        {
                            printf("D ");
                        }
                        if (check[4] < 1)
                        {
                            printf("E ");
                        }
                        if (check[5] < 1)
                        {
                            printf("F ");
                        }
                        if (check[6] < 1)
                        {
                            printf("G ");
                        }
                        if (check[7] < 1)
                        {
                            printf("H ");
                        }

                        printf("\n");
                    }
                    else
                    {
                        printf("No Garbage\n");
                    }
                }
                else if (in[0] == 'd' || in[0] == 'D')
                {
                    if (garbage < size)
                    {
                        printf("Deleted: ");

                        if (check[0] < 1)
                        {
                            printf("A ");
                            deleted[0] = 1;
                            size--;
                        }
                        if (check[1] < 1)
                        {
                            printf("B ");
                            deleted[1] = 1;
                            size--;
                        }
                        if (check[2] < 1)
                        {
                            printf("C ");
                            deleted[2] = 1;
                            size--;
                        }
                        if (check[3] < 1)
                        {
                            printf("D ");
                            deleted[3] = 1;
                            size--;
                        }
                        if (check[4] < 1)
                        {
                            printf("E ");
                            deleted[4] = 1;
                            size--;
                        }
                        if (check[5] < 1)
                        {
                            printf("F ");
                            deleted[5] = 1;
                            size--;
                        }
                        if (check[6] < 1)
                        {
                            printf("G ");
                            deleted[6] = 1;
                            size--;
                        }
                        if (check[7] < 1)
                        {
                            printf("H ");
                            deleted[7] = 1;
                            size--;
                        }

                        printf("\n");
                    }
                }
            }
        }
        else if (length == 3)
        {
            if (in[0] == 'c')
            {
                if (in[1] == '0')
                {
                    if (in[2] == 'A' || in[2] == 'a')
                    {
                        (currState->nextState0) = &s[0];
                    }
                    else if (in[2] == 'B' || in[2] == 'b')
                    {
                        (currState->nextState0) = &s[1];
                    }
                    else if (in[2] == 'C' || in[2] == 'c')
                    {
                        (currState->nextState0) = &s[2];
                    }
                    else if (in[2] == 'D' || in[2] == 'd')
                    {
                        (currState->nextState0) = &s[3];
                    }
                    else if (in[2] == 'E' || in[2] == 'd')
                    {
                        (currState->nextState0) = &s[4];
                    }
                    else if (in[2] == 'F' || in[2] == 'f')
                    {
                        (currState->nextState0) = &s[5];
                    }
                    else if (in[2] == 'G' || in[2] == 'g')
                    {
                        (currState->nextState0) = &s[6];
                    }
                    else if (in[2] == 'H' || in[2] == 'h')
                    {
                        (currState->nextState0) = &s[7];
                    }
                }
                else if (in[1] == '1')
                {
                    if (in[2] == 'A' || in[2] == 'a')
                    {
                        (currState->nextState1) = &s[0];
                    }
                    else if (in[2] == 'B' || in[2] == 'b')
                    {
                        (currState->nextState1) = &s[1];
                    }
                    else if (in[2] == 'C' || in[2] == 'c')
                    {
                        (currState->nextState1) = &s[2];
                    }
                    else if (in[2] == 'D' || in[2] == 'd')
                    {
                        (currState->nextState1) = &s[3];
                    }
                    else if (in[2] == 'E' || in[2] == 'd')
                    {
                        (currState->nextState1) = &s[4];
                    }
                    else if (in[2] == 'F' || in[2] == 'f')
                    {
                        (currState->nextState1) = &s[5];
                    }
                    else if (in[2] == 'G' || in[2] == 'g')
                    {
                        (currState->nextState1) = &s[6];
                    }
                    else if (in[2] == 'H' || in[2] == 'h')
                    {
                        (currState->nextState1) = &s[7];
                    }
                }
            }
        }

        printf("\n: ");
    }

    exit(0);
}