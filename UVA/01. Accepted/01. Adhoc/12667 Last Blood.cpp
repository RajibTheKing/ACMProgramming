#include<iostream>
#include<math.h>
#include<stdio.h>
#include<string.h>
using namespace std;


typedef struct Data
{
    int time;
    int teamID;
    string problemID;
    string status;

};

int main()
{
    int n, t, m;
    Data data[1000];

    Data temp;

    while(cin>>n>>t>>m)
    {
        for(int i=0;i<m;i++)
        {
            cin>>temp.time;
            cin>>temp.teamID;
            cin>>temp.problemID;
            cin>>temp.status;

            data[i] = temp;
        }

        for(int i=0;i<n;i++)
        {
            string nowProblem = "";
            nowProblem+=('A'+i);

            int tm = -1;
            int selectedTeam;
            bool color[300];
            memset(color, 0, sizeof(color));

            for(int j=0;j<m;j++)
            {
                int nowTeam = data[j].teamID;
                if(data[j].problemID == nowProblem && data[j].status == "Yes" && color[nowTeam]==false)
                {
                    //cout<<"Entered for teamID = "<<nowTeam<<endl;
                    color[nowTeam] = true;
                    if(tm<=data[j].time)
                    {
                        tm = data[j].time;
                        selectedTeam = nowTeam;
                    }
                }
            }

            if(tm==-1)
                cout<<nowProblem<<" - -"<<endl;
            else
                cout<<nowProblem<<" "<<tm<<" "<<selectedTeam<<endl;

        }

    }

    return 0;
}
