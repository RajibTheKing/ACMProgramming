#include<stdio.h>
#include<algorithm>
#include<iostream.h>
#include<string.h>
int main()
{
    char x[100][100], y[100][100];
    int n, i, j, count1[100], count2[100], ans[100], flag;
    scanf("%d ", &n);

    for(i=0; i<n; i++)
    {
        count1[i]=-1;
        count1[i]=-1;

        for(j=0; ; j++)
        {
            count1[i]++;

            scanf("%c", &x[i][j]);

            if(x[i][j]==' ')
                break;

        }

        for(j=0; ; j++)
        {
            count2[i]++;
            scanf("%c", &y[i][j]);
            if(y[i][j]==' ')
            {
                count2[i]=count2[i]-1;
                j=j-1;
                    continue;
            }
            if(y[i][j]=='\n')
            {
                count2[i]--;
                break;

            }

        }


    }



    for(i=0; i<n; i++)
    {
        for(j=0; j<count1[i]; j++)
        {


            if('A'<=x[i][j]&&x[i][j]<='Z')
                x[i][j]=x[i][j]+'a'-'A';

        }
        for(j=0; j<count2[i]; j++)
        {
            if('A'<=y[i][j]&&y[i][j]<='Z')
                y[i][j]=y[i][j]+'a'-'A';
        }

    }
    for(i=0; i<n;  i++)
    {
       std::sort(x[i], x[i]+count1[i]);
       std::sort(y[i], y[i]+count2[i]);
    }



    for(i=0; i<n; i++)
    {
        flag=1;
        if(count1[i]!=count2[i])
            {
                flag=0;
                goto ans;
            }
        for(j=0; j<count1[i]; j++)
        {
            if(x[i][j]!=y[i][j])
            {
                flag=0;
                break;
            }
        }
ans:
        if(flag==0)
            ans[i]=0;
        else
            ans[i]=1;
    }

    for(i=0; i<n; i++)
    {
        if(ans[i]==0)
            printf("No\n");
        else
            printf("Yes\n");
    }






    return 0;

}
