#include<bits/stdc++.h>

using namespace std;

int main()
{

    int test;
    cin>>test;
    int n;
    string s;

    int kase = 0;
    while(test--)
    {
        cin>>n;
        int kntMatches = 0;
        int consecutive = 0;
        bool flag = true;
        for(int i=0;i<n;i++)
        {
            kntMatches++;
            cin>>s;
            if(s!="W")
            {
                consecutive++;
            }
            else
            {
                consecutive=0;
            }

            if(consecutive == 3)
            {
                flag = false;
                break;
            }

        }

        for(int i=kntMatches;i<n;i++) cin>>s;

        printf("Case %d: ", ++kase);
        if(kntMatches==n && flag == true)
        {
            cout<<"Yay! Mighty Rafa persists!"<<endl;
        }
        else
            cout<<kntMatches<<endl;

    }
    getchar();
    getchar();
    getchar();
}
