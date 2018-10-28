#include <iostream>
#include <string>
#include <map>
#include <stack>


using namespace std;
map <int, int> mp;
stack<int> blocks[30];

void SendToInitial(int position, int value)
{
	int temp;
	while(true)
	{
		temp = blocks[position].top();
		if(temp == value) break;
		blocks[position].pop();
		blocks[temp].push(temp);
		mp[temp] = temp;
	}
}
int main()
{
	int N;
	string input;
	string operation, task;
	int a, b;


	while(cin >> N)
	{
		for(int i=0; i<N; i++)
		{
			while(!blocks[i].empty()) blocks[i].pop();
		}
		mp.clear();
		for(int i=0; i<N; i++)
		{
			mp[i] = i;
			blocks[i].push(i);
		}

		while(cin >> operation)
		{		
			if(operation == "quit")	break;

			cin >> a >> task >> b;
			if (a == b || mp[a] == mp[b])
			{
				//do nothing
			}
			else if( operation == "move")
			{
				int x = mp[a];
				int y = mp[b];
				if(task == "onto")
				{
					SendToInitial(x, a);
					SendToInitial(y, b);
					blocks[x].pop();
					blocks[y].push(a);
					mp[a] = y;
				}
				if(task == "over")
				{
					SendToInitial(x, a);
					blocks[x].pop();
					blocks[y].push(a);
					mp[a] = y;
				}
			}
			else if( operation == "pile")
			{
				int x = mp[a];
				int y = mp[b];
				if(task == "onto")
				{
					SendToInitial(y, b);
					stack<int> tempStack;
					while(!blocks[x].empty()) 
					{
						tempStack.push(blocks[x].top());
						blocks[x].pop();
						if(tempStack.top() == a) break;
					}
					while(!tempStack.empty())
					{
						int temp = tempStack.top(); tempStack.pop();
						blocks[y].push(temp);
						mp[temp] = y;
					}
				}
				else if(task == "over")
				{
					stack<int> tempStack;
					while(!blocks[x].empty())
					{
						tempStack.push(blocks[x].top());
						blocks[x].pop();
						if(tempStack.top() == a) break;
					}
					while(!tempStack.empty())
					{
						int temp = tempStack.top(); tempStack.pop();
						blocks[y].push(temp);
						mp[temp] = y;
					}
				}
			}
		}

		for(int i=0; i<N; i++)
		{
			cout<<i<<":";
			stack<int> tempStack;
			while(!blocks[i].empty())
			{
				tempStack.push(blocks[i].top());
				blocks[i].pop();
			}

			while(!tempStack.empty())
			{
				cout<<" "<<tempStack.top();
				tempStack.pop();
			}
			cout<<endl;
		}

	}


	return 0;
}