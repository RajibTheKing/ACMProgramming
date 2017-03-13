#include<stdio.h>
#include<string>
#include<iostream>
#include<string.h>
using namespace std;

string x[105];
bool flag[105][105];
int a[1005], b[1005];
int count, kase;


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
        if(flag[i+1][j+1]==true)
        {
            flag[i+1][j+1]=false;
            a[++rear]=i+1;
            b[rear]=j+1;
        }
        if(flag[i][j+1]==true)
        {
            flag[i][j+1]=false;
            a[++rear]=i;
            b[rear]=j+1;
        }
        if(flag[i-1][j+1]==true&&i-1>=0)
        {
            flag[i-1][j+1]= false;
            a[++rear]=i-1;
            b[rear]=j+1;
        }
        if(flag[i-1][j]==true&&i-1>=0)
        {
            flag[i-1][j]=false;
            a[++rear]=i-1;
            b[rear]=j;
        }
        if(flag[i-1][j-1]==true&&i-1>=0&&j-1>=0)
        {
            flag[i-1][j-1]=false;
            a[++rear]=i-1;
            b[rear]=j-1;
        }
        if(flag[i][j-1]==true&&j-1>=0)
        {
            flag[i][j-1]=false;
            a[++rear]=i;
            b[rear]=j-1;
        }
        if(flag[i+1][j-1]==true&&j-1>=0)
        {
            flag[i+1][j-1]=false;
            a[++rear]=i+1;
            b[rear]=j-1;
        }

        front++;
    }
}

void input(int n)
{
    int  i, j, k;
    for(i=0;i<n;i++)
        cin>>x[i];

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(x[i][j]=='1')
                flag[i][j]=1;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(flag[i][j]==true)
            {
                count++;
                BFS(i, j);
            }
        }
    }
}

int main()
{
    int n;
    kase=0;
    while(cin>>n)
    {
        count=0;
        input(n);
        printf("Image number %d contains %d war eagles.\n",++kase, count);

    }
    return 0;
}
