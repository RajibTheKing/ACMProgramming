#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<double> side;
    double temp;
    while(n--)
    {
        side.clear();
        for(int i=0;i<4;i++)
        {
            cin>>temp;
            side.push_back(temp);
        }
        sort(side.begin(), side.end());
        if(side[0]==side[1]&&side[1]==side[2]&&side[2]==side[3])
            cout<<"square"<<endl;
        else if(side[0]==side[1]&&side[2]==side[3])
            cout<<"rectangle"<<endl;
        else if(side[0]+side[1]+side[2]>side[3])
            cout<<"quadrangle"<<endl;
        else
            cout<<"banana"<<endl;

    }
}
