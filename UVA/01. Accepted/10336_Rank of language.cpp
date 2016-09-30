#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;


typedef struct node
{
    char item;
    int num;
};


node ans[26];

string x[105];

bool flag[1005][1005];
int a[10005], b[10005];
int count, kase;


bool comp(node p, node q)
{
    if(p.num==q.num)
        return p.item<q.item;
    return p.num>q.num;
}

void BFS(int i, int j)
{
    int front=1, rear=0;
    a[++rear]=i;
    b[rear]=j;
    flag[i][j]=false;



    while(front<=rear)
    {
        i=a[front];
        j=b[front];



        if(flag[i+1][j]==true)
        {
            flag[i+1][j]=false;

            a[++rear]=i+1;
            b[rear]=j;
        }

        if(flag[i][j+1]==true)
        {
            flag[i][j+1]=false;
            a[++rear]=i;
            b[rear]=j+1;
        }

        if(flag[i-1][j]==true&&i-1>=0)
        {
            flag[i-1][j]=false;
            a[++rear]=i-1;
            b[rear]=j;
        }

        if(flag[i][j-1]==true&&j-1>=0)
        {
            flag[i][j-1]=false;
            a[++rear]=i;
            b[rear]=j-1;
        }


        front++;
    }
}

void find(int i, int j, int h, int w)
{
    char c = x[i][j];
    ans[c-'a'].num = 0;
    ans[c-'a'].item = c;

    for(i=0;i<h;i++)
    {
        for(j=0;j<w;j++)
        {
            if(x[i][j]==c)
            {
                flag[i][j]=true;
                x[i][j]='.';
            }
            else            flag[i][j]=false;


        }
    }

    for(i=0;i<h;i++)
        for(j=0;j<w;j++)
            if(flag[i][j]==true)
            {
                ans[c-'a'].num++;
                BFS(i, j);
            }
}

void input(int h, int w)
{
    int  i, j, k;
    for(i=0;i<h;i++)
        cin>>x[i];

    for(i=0;i<h;i++)
        for(j=0;j<w;j++)
            if(x[i][j]>='a'&&x[i][j]<='z')
                find(i, j, h, w);

}

int main()
{
    int n;
    kase=0;
    int t, h, w;
    cin>>t;
    while(t--)
    {
        cin>>h>>w;
        input(h, w);

        sort(&ans[0], &ans[26], comp);


        printf("World #%d\n", ++kase);

        for(int i=0;i<26;i++)
        {
            if(ans[i].num!=0)
                printf("%c: %d\n", ans[i].item, ans[i].num);
        }


        for(int i=0;i<26;i++)
        {
            ans[i].item=NULL;
            ans[i].num=NULL;
        }
    }
    return 0;
}

