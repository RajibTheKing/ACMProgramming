#include<iostream>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct node
{
    string name;
    int age;

};

vector<node> A;
bool comp(node p, node q)
{

    if(p.age==q.age)
    {
        return p.name<q.name;
    }
    return p.age>q.age;

}
int main()
{
    string a;
    int n;
    node t;
    //freopen("test.txt",  "r", stdin);
    while(cin>>a>>n)
    {
        t.name=a;
        t.age=n;
        A.push_back(t);
    }
    sort(&A[0] , &A[A.size()], comp);
    for(int i=0;i<A.size();i++)
        cout<<A[i].name<<endl;


}

