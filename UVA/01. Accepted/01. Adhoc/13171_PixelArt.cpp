#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int Megenta, Yellow, Cyan;
	string pixels;

	while(n--)
	{
		cin>>Megenta>>Yellow>>Cyan;
		cin>>pixels;
		for(int i=0; i<pixels.size(); i++)
		{
			if(pixels[i] == 'M') Megenta--;
			else if(pixels[i] == 'Y') Yellow--;
			else if(pixels[i] == 'C') Cyan--;
			else if(pixels[i] == 'R') Megenta--, Yellow--;
			else if(pixels[i] == 'B') Megenta--, Yellow--, Cyan--;
			else if(pixels[i] == 'G') Yellow--, Cyan--;
			else if(pixels[i] == 'V') Megenta--, Cyan--;
			else
			{
				//do nothing
			}
		}
		if(Megenta>=0 && Yellow>=0 && Cyan>=0)
		{
			printf("YES %d %d %d\n", Megenta, Yellow, Cyan);
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}