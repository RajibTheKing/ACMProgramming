#include<stdio.h>

#define MAX 2003

int main()
{
	int n,m,i,j,minn,diff,total;
	int songs[MAX];

	while (scanf("%d%d", &n,&m) == 2)
	{
		int countt[MAX] = { 0 };

		for (i = 1; i <= n; i++)
		{
			scanf("%d", &songs[i]);

			if (songs[i]<=m)
				countt[songs[i]]++;
		}

		minn = n / m;

		printf("%d ", minn);

		total = 0;

		for (i = 1; i <= m; i++)
		{
			if (countt[i] < minn)
			{
				diff = minn - countt[i];

				for (j = 1; j <= n && diff > 0; j++)
				{
					if (songs[j]>m)
					{
						songs[j] = i;
						diff--;
						total++;
					}
				}

				for (j = 1; j <= n && diff > 0; j++)
				{
					if (countt[songs[j]]>minn)
					{
						songs[j] = i;
						diff--;
						total++;
					}
				}
			}
		}

		printf("%d\n", total);

		for (i = 1; i <= n; i++)
		{
			if (i < n)
				printf("%d ", songs[i]);
			else
				printf("%d\n", songs[i]);
		}

	}
}
