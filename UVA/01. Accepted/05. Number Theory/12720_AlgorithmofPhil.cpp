#include<iostream>
#include<string>
#include<stdio.h>
#include<string.h>

using namespace std;


#define MOD 1000000007

int indxS;

char tempA[100005];
char tempS[100005];
int pre[100005];

void precalculate()
{
    int now=1;

    for(int i=0;i<100003;i++)
    {
        if(i)
            now*=2;

        now%=MOD;
        pre[i]=now;
    }

}
int BinaryToDecimal()
{
    int p = indxS;
    int ret = 0;
    for(int i=0;i<indxS;i++)
    {
        p--;
        if(tempS[i]=='1')
        {
            //long long now = (1<<p);
            int now = pre[p];

            now%=MOD;
            ret%=MOD;
            ret+=now;
            ret%=MOD;
        }
    }
    return ret;
}


int main()
{
    ios::sync_with_stdio(false);

    precalculate();
    string A,S;

    int n;
    cin>>n;

    for(int kase=1;kase<=n;kase++)
    {
        cin>>tempA;

        int aLen = strlen(tempA);

        int gs = 0;
        int left,right;
        indxS = 0;
        if(aLen%2==1)
        {
            left = aLen/2;
            right = aLen/2;
        }
        else
        {
            right = aLen/2;
            left =  right-1;
        }

        int ret = 0;
        int p = aLen;

        while(gs<aLen)
        {
            if(left==right)
            {
                char bitc = tempA[left];
                left--;
                right++;


                gs++;
                p--;
                if(bitc=='1')
                {
                    //long long now = (1<<p);
                    int now = pre[p];
                    ret+=now;
                    ret%=MOD;
                }

            }
            else
            {
                if(tempA[left]>tempA[right])
                {
                    char bitc = tempA[left];

                    gs++;
                    p--;
                    if(bitc=='1')
                    {
                        //long long now = (1<<p);
                        int now = pre[p];
                        ret+=now;
                        ret%=MOD;
                    }


                    bitc =  tempA[right];
                    gs++;
                    p--;
                    if(bitc=='1')
                    {
                        //long long now = (1<<p);
                        int now = pre[p];
                        ret+=now;
                        ret%=MOD;
                    }




                }
                else
                {
                    char bitc =  tempA[right];
                    gs++;
                    p--;
                    if(bitc=='1')
                    {
                        //long long now = (1<<p);
                        int now = pre[p];
                        ret+=now;
                        ret%=MOD;
                    }

                    bitc = tempA[left];

                    gs++;
                    p--;
                    if(bitc=='1')
                    {
                        //long long now = (1<<p);
                        int now = pre[p];
                        ret+=now;
                        ret%=MOD;
                    }

                }

                left--;
                right++;

            }
        }

        //int ans = BinaryToDecimal();

        cout<<"Case #"<<(kase)<<": ";
        cout<<ret<<"\n";
        //printf("Case #%d: %d\n", kase, ans);

    }
    return 0;
}
