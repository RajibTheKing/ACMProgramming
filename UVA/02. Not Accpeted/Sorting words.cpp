#include<iostream>
using namespace std;

void getData(char names[][30], int& sizeOfArray);
void BubbleSort (char names[][30], int size);
void showArray(char names[][30], int size);
void strcpy(char x[], char y[]);

int main()
{
	const char TOTALNAMES = 20;
	char names[TOTALNAMES];
	int numberOfNames = 0;

	//getData(names, numberOfNames);

	// Display the values
	cout << "The unsorted values are:\n";
//	showArray(names, 20);

	// Sort the values
//	BubbleSort(names, 20);

	// Display them again
	cout << "The sorted values are:\n";
//	showArray(names, 20);

	return 0;
}

void getData (char names[][30], int& sizeOfArray)
{
	int pos = 0;
	char name[30];
	int value = 0;

	cout << "Please enter a last name" << endl;
	cin >> name;

	while (pos < 20)
	{
//		names[pos] = value;
		pos++;

		cout << "Please enter another last name: " << endl;
		cin >> name;
	}
	sizeOfArray = pos;
}

void BubbleSort (char names[][30], int size)
{	int k = 0;
	 bool done = false;
	 int limit = 0;
	 char name[30];
	  while (!done)
	  {	  done = true;
			  for (int n=0; n<size-1-limit; n++)
		  if (strcmp(names[k], names[k+1]) > 0)
//		   {	  Swap (name, n, n+1);
				  done = false;
		   }
		limit++;
	  }
//}

void Swap (char names[][30], int n, int k)
{	char temp[30];
	 strcpy(temp,names[n]);
	 strcpy(names[n], names[k]);
	 strcpy(names[k], temp);
}

void strcpy(char x[], char y[])
{
	int n=0;
	while(y[n] != '\0')
	{
		x[n] = y[n];
		n++;
	}
	x[n] = '\0';
}

//void showArray (char names[][30], int size)
//{
//	int count = 0;

//	for (int count=0; count < size; count++)
//		cout << names[] << " " << endl;
//}
