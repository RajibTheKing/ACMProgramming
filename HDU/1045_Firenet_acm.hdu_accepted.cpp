#include<stdio.h>
#include<string.h>
#include<time.h>
typedef struct node
{
    int x;
    int y;
};


char board[10][10], temp[10][10];
int  binary[66000][100], max, flag, m , o, p;
int n, i, j, k, l;
char c;
node co_ordinate_1[1],co_ordinate_2[4],co_ordinate_3[9], co_ordinate_4[16];

int check(void)
{
	m=i;
	o=j;

	p=0;
	for(j=0; j<n*n; j++)
		p+=binary[i][j];



	if(p<=max)
	{
		return 0;
	}
	else
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				c=temp[i][j];
				if(c=='F')
				{
					flag=1;
					for(k=i,l=j+1;l<n;l++)
						if(temp[k][l]=='F')
						{
							flag=0;
							goto result;
						}
						else if(temp[k][l]=='X')
							break;
					for(k=i,l=j-1;l>=0;l--)
						if(temp[k][l]=='F')
						{
							flag=0;
							goto result;
						}
						else if(temp[k][l]=='X')
							break;
					for(k=i+1,l=j;k<n;k++)
							if(temp[k][l]=='F')
						{
							flag=0;
							goto result;
						}
						else if(temp[k][l]=='X')
							break;
					for(k=i-1,l=j;k>=0;k--)
						if(temp[k][l]=='F')
						{
							flag=0;
							goto result;
						}
						else if(temp[k][l]=='X')
							break;

				}
			}
		}
result:
		if(flag==1)
		{
			i=m;
			j=o;
			max=p;


			return 1;
		}
		else
		{
			i=m;
			j=o;
			return 0;
		}
	}
}

void initiate_again()
{
    for(k=0; k<n;k++)
        for(l=0; l<n;l++)
            temp[k][l]=board[k][l];
}


void make_co_ordinate()
{
    int i, j, k=-1;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            co_ordinate_3[++k].x=i;
            co_ordinate_3[k].y=j;
        }
    }
	k=-1;
	for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            co_ordinate_4[++k].x=i;
            co_ordinate_4[k].y=j;
        }
    }
	k=-1;

	for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            co_ordinate_2[++k].x=i;
            co_ordinate_2[k].y=j;
        }
    }
	k=-1;
	for(i=0;i<1;i++)
	{
		for(j=0;j<1;j++)
		{
            co_ordinate_1[++k].x=i;
            co_ordinate_1[k].y=j;
        }
	}

}
int main()
{

    make_co_ordinate();

    time_t start, end;

    time(&start);
    for(i=0; i<=65540; i++)
    {
        k=-1;
        for(j=0; j<=16; j++)
        {
            binary[i][++k]=i>>j&1;
        }
    }



    time(&end);

    while(1)
    {
        max=0;

        scanf("%d", &n);
        scanf("%c", &c);
        if(n==0) break;
        for(i=0; i<n;i++)
            gets(board[i]);


		for(i=1; i<(1<<(n*n)); i++)
        {
start:
			initiate_again();
			if(i>(1<<(n*n)))
				break;


            for(j=0; j<n*n; j++)
            {
				if(n==3)
                {
					if(binary[i][j]==1)
					{
						if(temp[co_ordinate_3[j].x][co_ordinate_3[j].y]=='X')
						{

							i++;
							goto start;
						}
						temp[co_ordinate_3[j].x][co_ordinate_3[j].y]='F';
					}
				}
				if(n==4)
                {
					if(binary[i][j]==1)
					{
						if(temp[co_ordinate_4[j].x][co_ordinate_4[j].y]=='X')
						{

							i++;
							goto start;
						}
						temp[co_ordinate_4[j].x][co_ordinate_4[j].y]='F';
					}
				}
				if(n==2)
                {
					if(binary[i][j]==1)
					{
						if(temp[co_ordinate_2[j].x][co_ordinate_2[j].y]=='X')
						{

							i++;
							goto start;
						}
						temp[co_ordinate_2[j].x][co_ordinate_2[j].y]='F';
					}
				}
				if(n==1)
                {
					if(binary[i][j]==1)
					{
						if(temp[co_ordinate_1[j].x][co_ordinate_1[j].y]=='X')
						{

							i++;
							goto start;
						}
						temp[co_ordinate_1[j].x][co_ordinate_1[j].y]='F';
					}
				}
			}



			flag=check();
        }
		printf("%d\n", max);


    }

    return 0;
}
