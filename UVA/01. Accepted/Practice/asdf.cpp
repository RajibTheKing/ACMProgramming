#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char maze[150];
    register int n = 0, k, c = 0;
    while(gets(maze))
    {
        int L = strlen(maze);
        c = 0;

        for(n = 0; n<L; n++)
        {
            if(isdigit(maze[n]))
                c += maze[n] - '0';
            if(maze[n]=='b')
            {
                for(k=1;k<=c;k++)
                    printf(" ");
                c=0;
            }
            else if(isalpha(maze[n]))
            {
                for(k = 1; k <= c; k++)
                    printf("%c", maze[n]);

                c = 0;
            }
            else if(maze[n] == '!')
                printf("\n");
            else if(maze[n]=='*')
            {
                for(k = 1; k <= c; k++)
                    printf("%c", maze[n]);
                c=0;
            }
        }
        printf("\n");
    }
    return 0;
}
