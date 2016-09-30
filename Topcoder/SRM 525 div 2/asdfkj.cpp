#include<iostream>
using namespace std;
int mm = 99999;
int k = 12;
bool flag = false;
int find(char b[30][30])
{
    int f=0;
    for(int i=0;i<5;i++)
        for(int j=0;j<7;j++)
            if(b[i][j]=='o')
                f++;
    return f;
}

void rec(int n, char board[30][30])
{
    int c = find(board);
    cout<<"c: "<<c<<endl;
    for(int i=0;i<5;i++){
        for(int j=0;j<7;j++)
            cout<<board[i][j];
        cout<<endl;
    }

    if(c<k) return;
    cout<<"MM: "<<mm<<endl;
    if(c==k)
    {
        flag=true;
        cout<<"Yes i found the answer"<<endl;
        if(mm>n)
            mm=n;
        return;

    }

    char b[30][30];

    for(int i=0;i<5;i++)
    {
        for(int j=1;j<7;j++)
            b[i][j]=board[i][j-1];
        b[i][0]='.';
    }

    rec(n+1,b);

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<6;j++)
            b[i][j]=board[i][j+1];
        b[i][6]='.';
    }
    rec(n+1, b);

    for(int j=0;j<7;j++)
    {
        for(int i=0;i<4;i++)
            b[i][j]=board[i+1][j];
        b[4][j]='.';

    }

    rec(n+1, b);
    for(int j=0;j<7;j++)
    {
        for(int i=1;i<4;i++)
            b[i][j]=board[i-1][j];
        b[0][j]='.';

    }
    rec(n+1, b);
}

int main()
{
    freopen("sample.txt", "r", stdin);
    int i, j;
    char b[30][30];
    for(i=0;i<5;i++)
        for(j=0;j<7;j++)
            cin>>b[i][j];

    rec(0, b);



}
