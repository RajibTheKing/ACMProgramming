#include<stdio.h>
#include<string.h>
int m,n,rear,front;
bool flag[100][100];int a[10000],b[10000];
char x[100][100];
void bfs();
void input();
int main()
{
    char c;
    while(scanf("%d%d",&m,&n)==2&&m&&n)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(x,0,sizeof(x));
        memset(flag,0,sizeof(flag));

        scanf("%c", &c);
        input();
    }
}
void input()
{
    int i,j;
    char c;
    for(i=0;i<n;i++)
    {
        gets(x[i]);
        //c=getchar();

    }

    for(i=0;i<m;i++)
        for(j=0;j<m;j++)
        {
            if(x[i][j]=='@'){
                a[rear]=i;
                b[rear++]=j;
                //printf("%d",i);
                //printf(" %d",j);
            }
            else if(x[i][j]=='#')
                flag[i][j]=1;
        }



        bfs();



    printf("%d %d\n",a[0],b[0]);
}
void bfs()
{
    int s,t,i,count=0;
    while(front<rear)
    {
        for(i=front;i<rear;i++)
        {
            s=a[i];t=b[i];
            flag[s][t]=1;
            if(flag[s+1][t]==0&&x[s+1][t]=='.')
            {
                a[rear]=s+1;b[rear++]=t;count++;flag[s+1][t]=1;
            }
            if(flag[s][t+1]==0&&x[s][t+1]=='.')
            {
                a[rear]=s;b[rear++]=t+1;count++;flag[s][t+1]=1;
            }
            if((t-1)>=0&&flag[s][t-1]==0&&x[s][t-1]=='.')
            {
                a[rear]=s;b[rear++]=t-1;count++;flag[s][t-1]=1;
            }
            if((s-1)>=0&&flag[s-1][t]==0&&x[s-1][t]=='.')
            {
                a[rear]=s-1;b[rear++]=t;count++;flag[s-1][t]=1;
            }
        }
        front++;
    }
    printf("%d\n",count+1);
}
