#include<stdio.h>
#include<string.h>
long long a[150],fib[150],j,mx,i,test,n,k;
char ans[115],b[115];

main()
{
	fib[0]=1;fib[1]=1;
	for(i=2;i<=47;i++)
		fib[i]=fib[i-1]+fib[i-2];
	scanf("%lld",&test);

	while(test--)
	{
		memset(ans,32,sizeof(ans));
		memset(a,0,sizeof(a));

		scanf("%lld",&n);

		for(i=1;i<=n;i++)
			scanf("%lld\n",&a[i]);

		i=1;
		mx=0;
		gets(b);

		for(k=0;b[k]!=NULL;k++)
		{
			if( b[k]>='A'&& b[k]<='Z')
			{

				for(j=1; j<48;j++ )
					if(a[i]==fib[j])
					{
						ans[j-1]=b[k];
						mx++;
						break;
					}
				i++;
			}
		}


		i=0;

		for(j=0;i<mx;j++)
		{
			if( ans[j]>='A' && ans[j]<='Z' )
			{
				printf("%c",ans[j]);
				i++;
			}
			else printf("%c",ans[j]);
        }
		printf("\n");
    }

}


