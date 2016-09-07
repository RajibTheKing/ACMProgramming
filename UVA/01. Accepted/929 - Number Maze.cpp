#include<stdio.h>
#define INF 914748364;


typedef struct node
{
    int u;
    int p;
    int q;
};

int a[1010][1010];
int board[1010][1010];
int n, m, size;
node A[1000020];


void input(void)
{
    int i, j;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d", &a[i][j]);
}
void initialize(void)
{
    int i, j, k;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            board[i][j]=INF;

        }
}

void Min_Heapify(int i)
{
    int smallest;
    node temp;

    if((2*i)<=size && A[2*i].u < A[i].u)
        smallest=2*i;
    else
        smallest = i;

    if((2*i+1)<=size&&A[2*i+1].u < A [smallest].u)
        smallest = 2*i+1;


    if(smallest!=i)
    {
        temp=A[i];
        A[i]=A[smallest];
        A[smallest]=temp;
        Min_Heapify(smallest);
    }

}

node Extract_Min(void)
{
    node min;
    min=A[1];
    A[1]=A[size];
    size--;
    Min_Heapify(1);

    return min;
}
void insert(node key)
{
    size++;
    int i;
    i=size;
    while(i>1&&A[i/2].u>key.u)
    {
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=key;
}
main()
{
    int flag, t;
    scanf("%d", &t);
    while(t--)
    {

        scanf("%d %d", &n, &m);
        flag = n*m;
        input();
        initialize();
        board[1][1]=a[1][1];
        A[1].u=board[1][1];
        A[1].p=1;
        A[1].q=1;
        size=1;


        while(flag>0)
        {
            int x, y;
            node min , key;


            min = Extract_Min();

            flag--;
            x=min.p;
            y=min.q;

            if(x+1<=n)
            if((a[x+1][y]+board[x][y])<board[x+1][y])
            {
                board[x+1][y]= a[x+1][y]+board[x][y];

                key.p=x+1;
                key.q=y;
                key.u=board[x+1][y];
                insert(key);

            }

            if(y+1<=m)
            if((a[x][y+1]+board[x][y])<board[x][y+1])
            {
                board[x][y+1]= a[x][y+1]+board[x][y];

                key.p=x;
                key.q=y+1;
                key.u=board[x][y+1];
                insert(key);
            }

            if(x-1>=1)
            if((a[x-1][y]+board[x][y])<board[x-1][y])
            {
                board[x-1][y]= a[x-1][y]+board[x][y];

                key.p=x-1;
                key.q=y;
                key.u=board[x-1][y];
                insert(key);
            }
            if(y-1>=1)
            if((a[x][y-1]+board[x][y])<board[x][y-1])
            {
                board[x][y-1]= a[x][y-1]+board[x][y];

                key.p=x;
                key.q=y-1;
                key.u=board[x][y-1];

                insert(key);

            }
        }

        printf("%d\n", board[n][m]);

    }

}
