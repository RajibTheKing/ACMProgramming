#include<iostream>
#include<string>
#include<map>

using namespace std;

int main()
{
    string arr[10];
    arr[0]=" ";
    arr[1]=".,?\"";
    arr[2]="abc";
    arr[3]="def";
    arr[4]="ghi";
    arr[5]="jkl";
    arr[6]="mno";
    arr[7]="pqrs";
    arr[8]="tuv";
    arr[9]="wxyz";

    int T, L;
    int n;
    cin>>T;

    int a1[101];
    int a2[101];

    while(T--)
    {
        cin>>L;
        int prev=-1;
        int indx=-1;


        for(int i=0;i<L;i++)
        {
            cin>>a1[i];
        }

        for(int i=0;i<L;i++)
        {
            cin>>a2[i];
            cout<<arr[a1[i]][a2[i] - 1];
        }
        cout<<endl;

    }

    return 0;
}
