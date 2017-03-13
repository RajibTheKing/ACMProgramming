#include <stdio.h>
#include <string.h>
int main()
{
	int mod,i;
	char inp[10000];
	scanf("%s",inp);
	while(inp[0]!='0'||strlen(inp)>1)
	{
		mod = 0;
		for(i=0;inp[i];i++)
			mod = (mod*10 + inp[i]-'0')%11;
		if(!mod)
			printf("%s is a multiple of 11.\n",inp);
		else
			printf("%s is not a multiple of 11.\n",inp);
		scanf("%s",inp);
	}
	return 0;
}
