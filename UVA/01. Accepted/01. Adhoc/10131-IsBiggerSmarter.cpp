#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <stdio.h>
#include <limits.h>
using namespace std;


class Node
{
public: 
	int weight;
	int IQ;
	int pos;
};

Node arr[1005];
int n = 0;
vector<int> ans;


bool cmp(Node p, Node q)
{
	if(p.weight == q.weight)
		return p.IQ<q.IQ;
	return p.weight<q.weight;
}


int LDS()
{

   int i, j, max_val = 0, max_index = 0;
   int printHandler[n+1];
   int dp[1005];

   for ( i = 0; i < n; i++ )
   {
      dp[i] = 1;
      printHandler[i] = -1;
   }

   for ( i = 1; i < n; i++ )
   {
   		for ( j = 0; j < i; j++ )
   		{
   			if ( arr[i].IQ < arr[j].IQ && dp[i] < dp[j] + 1)
	        {
	            dp[i] = dp[j] + 1;
	            printHandler[i] = j;
	        }	
   		}
        
   }
      
   for ( i = 0; i < n; i++ )
   {
      if ( max_val < dp[i] )
      {
        	max_val = dp[i];
        	max_index = i;
      }
    }
    
    cout<<max_val<<endl;
    vector<int> positions;
    while(max_index >=0){
        positions.push_back(arr[max_index].pos);
        max_index = printHandler[max_index];
    }
    for(int i=positions.size()-1; i>=0; i--)
    {
        printf("%d\n", positions[i]);
    }

   return max_val;

}

int main()
{
	//freopen("in.txt", "r", stdin);
	while(scanf("%d %d", &arr[n].weight, &arr[n].IQ) == 2)
	{
		arr[n].pos = n+1;
		n++; 
	}
	sort(arr, arr+n, cmp);
	int len = LDS();
	return 0;
}