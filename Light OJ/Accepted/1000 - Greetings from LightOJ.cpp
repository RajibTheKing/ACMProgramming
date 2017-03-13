#include<iostream>
using namespace std;
main()
{
  int a, b, n, kase=0;
  cin>>n;
  while(n--)
  {
      cin>>a>>b;
      cout<<"Case "<<++kase<<": "<<a+b<<endl;
  }
}
