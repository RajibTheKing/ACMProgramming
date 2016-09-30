#include<iostream>
#include<stack>
#include<sstream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<vector>
using namespace std;

vector<int> ParseString(string s)
{
    vector<int> res;
    res.clear();
    stringstream sin(s);
    for (int n; sin >> n; res.push_back(n));
    return res;
}

bool SolveMatrioshkas(vector<int> a)
{
    stack<int> stk;
    int n=a.size(), sum;
    if(n%2!=0) return false;
    for(int i=0;i<n;i++)
    {
        if(a[i]<0)
        {
            stk.push(a[i]);
            //cout<<"here1: "<<stk.top()<<endl;
        }
        else
        {
            sum = 0;
            while(!stk.empty())
            {
                if(stk.top()<0)
                {
                    if(stk.top()==-a[i])
                    {
                        //cout<<"here2: "<<stk.top()<<endl;
                        stk.top()=-stk.top();
                        break;
                    }
                    else
                        return false;
                }
                sum+=abs(stk.top());
                stk.pop();
            }

            if(sum>=a[i]) return false;

        }
    }

    for (; !stk.empty(); stk.pop())
    {
        //cout<<stk.top()<<endl;
        if (stk.top() < 0)
            return false;
    }
    return true;
}

main()
{
    //freopen("in.txt", "r", stdin);
    string s;
    vector<int> a;
    bool flag;
    while(getline(cin, s))
    {
        a.clear();
        a = ParseString(s);
        flag = SolveMatrioshkas(a);
        if(flag)
            cout<<":-) Matrioshka!"<<endl;
        else
            cout<<":-( Try again."<<endl;
    }
}

