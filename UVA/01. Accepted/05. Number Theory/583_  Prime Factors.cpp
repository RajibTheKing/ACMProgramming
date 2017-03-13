#include<stdio.h>
#include<cmath>
using namespace std;
#define s 100000


int prime[60000],i=0,j=0,root,temp,l,e,n,y;
bool flag[100100];
int factor[1000];
int r, k=sqrt(s);

int main()
{
    prime[j++]=2;
	for(i=3;i<=s;i+=2)
	{
		if(flag[i]==0)
		{
			prime[j++]=i;
			if(i<=k)
			{
				r=i<<1;
				for(y=i*i;y<=s;y+=r)
					flag[y]=1;
			}
		}
	}


	while(1)
	{
	    scanf("%d", &n);
	    if(n==0)
            break;
		printf("%d = ",n);
		if(n<0)
		{
			temp=(-1*n);
			printf("-1 x ");
		}
		else
			temp=n;
		root=sqrt(temp);
		for(i=0,k=0;prime[i]<=root;i++)
		{
			while(temp%prime[i]==0)
			{
				factor[k]=prime[i];
				k++;
				temp=temp/prime[i];
			}
			if(temp<2)
				break;
		}
		if(temp>=2)
		{
			factor[k]=temp;
			k++;
		}
		for(i=0;i<k;i++)
		{
			printf("%d",factor[i]);
			if(i!=k-1)
				printf(" x ");
		}
		printf("\n");
	}

	return 0;
}



