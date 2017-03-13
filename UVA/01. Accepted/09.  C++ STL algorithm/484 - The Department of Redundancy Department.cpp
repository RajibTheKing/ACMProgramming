#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    map<int, int> M;
    vector<int> R;
    int n;

    M.clear();
    R.clear();

    while(cin>>n)
    {
        if(M[n]>=1)
            M[n]++;
        else
        {
            R.push_back(n);
            M[n]=1;

        }
    }

    for(int i=0;i<R.size();i++)
    {
        cout<<R[i]<<" "<<M[R[i]]<<endl;
    }

}
