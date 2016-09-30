#include<iostream>
#include<string>
#include<string.h>

using namespace std;
int max(int p, int q, int r)
{
    if(p>q)
    {
        if(p>r) return p;
        else return r;
    }
    else
    {
        if(q>r) return q;
        else return r;
    }
}
int lcs(string x, string y, string z)
{
    int board[51][51][51];
    int m, n, o, i, j, k;
    m = x.length();
    n = y.length();
    o = z.length();

    memset(board, 0, sizeof(board));

    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            for(k=1;k<=o;k++)
            {

                if(x[i-1]==y[j-1]&&y[j-1]==z[k-1])
                    board[i][j][k] = board[i-1][j-1][k-1] + 1;
                else
                    board[i][j][k] = max(board[i-1][j][k], board[i][j-1][k], board[i][j][k-1]);
            }
        }
    }

    return board[m][n][o];

}
int main()
{
    int i, j, k;
    int kase = 0;
    string a, b, c;
    bool f1, f2;
    int T, ans;
    cin>>T;
    while(T--)
    {
        cin>>a>>b>>c;

        ans = lcs(a, b, c);
        printf("Case %d: %d\n",++kase, ans);

    }
    return 0;
}
