#include<stdio.h>
#include<string.h>

typedef struct node
{
    char name;
    int color;

};

node vertices[1005][1005];
char stack[10005];

void input(int m, int n)
{

    int i, j, k;
    char c;

    for(i=1;i<=m+1;i++)
        for(j=1;j<=n+1;j++)
            vertices[i][j].name='.';


    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
            scanf("%c", &vertices[i][j].name);
        scanf("%c", &c);
    }

}
void initialize(int m, int n)
{
    int i, j;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            vertices[i][j].color=1;

        }

    }
}

void DFS_visit(int i, int j)
{
    vertices[i][j].color=2;

    if(vertices[i][j-1].name=='@'&&vertices[i][j-1].color==1)
        DFS_visit(i, j-1);
    if(vertices[i-1][j-1].name=='@'&&vertices[i-1][j-1].color==1)
        DFS_visit(i-1, j-1);
    if(vertices[i-1][j].name=='@'&&vertices[i-1][j].color==1)
        DFS_visit(i-1, j);
    if(vertices[i-1][j+1].name=='@'&&vertices[i-1][j+1].color==1)
        DFS_visit(i-1, j+1);
    if(vertices[i][j+1].name=='@'&&vertices[i][j+1].color==1)
        DFS_visit(i, j+1);
    if(vertices[i+1][j+1].name=='@'&&vertices[i+1][j+1].color==1)
        DFS_visit(i+1, j+1);
    if(vertices[i+1][j].name=='@'&&vertices[i+1][j].color==1)
        DFS_visit(i+1, j);
    if(vertices[i+1][j-1].name=='@'&&vertices[i+1][j-1].color==1)
        DFS_visit(i+1, j-1);

    vertices[i][j].color=3;

}
main()
{
    int m, n, count;
    while(1)
    {
        int i, j;
        char c;
        count = 0;
        scanf("%d %d", &m, &n);
        scanf("%c", &c);
        if(m==0) break;
        input(m, n);
        initialize(m, n);
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(vertices[i][j].color==1&&vertices[i][j].name=='@')
                {
                    count++;
                    DFS_visit(i, j);
                }
            }
        }
        printf("%d\n", count);
    }
}
