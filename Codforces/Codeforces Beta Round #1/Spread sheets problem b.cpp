#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<sstream>
using namespace std;
string ans[1000010];
int p=0;

void calculate(void)
{
    int i, j, k, l, m;
    string temp;
    char c, d, e, f, g;
    for(i=0;i<26;i++)
    {
        temp="";
        c=i+65;
        temp+=c;
        ans[++p]="";
        ans[p]+=temp;
    }
    for(i=0;i<26;i++)
    {
        temp="";
        c=i+65;
        temp+=c;
        for(j=0;j<26;j++)
        {
            d=j+65;
            temp+=d;
            ans[++p]="";
            ans[p]+=temp;
            temp="";
            temp+=c;
        }
    }
    for(i=0;i<26;i++)
    {
        temp="";
        c=i+65;
        temp+=c;
        for(j=0;j<26;j++)
        {
            d=j+65;
            temp+=d;
            for(k=0;k<26;k++)
            {
                e=k+65;
                temp+=e;
                ans[++p]="";
                ans[p]+=temp;
                temp="";
                temp+=c;
                temp+=d;
            }
        }
    }

    for(i=0;i<26;i++)
    {
        temp="";
        c=i+65;
        temp+=c;
        for(j=0;j<26;j++)
        {
            d=j+65;
            temp+=d;
            for(k=0;k<26;k++)
            {
                e=k+65;
                temp+=e;
                for(l=0;l<26;l++)
                {
                    f=l+65;
                    temp+=f;
                    ans[++p]="";
                    ans[p]=temp;
                    temp="";
                    temp+=c;
                    temp+=d;
                    temp+=e;
                }
            }
        }
    }

    for(i=0;i<26;i++)
    {
        temp="";
        c=i+65;
        temp+=c;
        for(j=0;j<26;j++)
        {
            d=j+65;
            temp+=d;
            for(k=0;k<26;k++)
            {
                e=k+65;
                temp+=e;
                for(l=0;l<26;l++)
                {
                    f=l+65;
                    temp+=f;
                    for(m=0;m<26;m++)
                    {
                        g=m+65;
                        temp+=g;
                        ans[++p]="";
                        ans[p]=temp;
                        if(p>1000002) return;
                        temp="";
                        temp+=c;
                        temp+=d;
                        temp+=e;
                        temp+=f;
                    }
                }
            }
        }
    }

}

main()
{
    calculate();
    //cout<<"P: "<<p<<endl;
    stringstream ss;
    int n, num1, num2, i;
    string a;
    bool f1, f2;
    char c,d;
    cin>>n;
    while(n--)
    {
        cin>>a;
        int k;
        k=a.size();
        f1=false;
        f2=false;

        for( i=0;i<k;i++)
        {
            if(a[i]>='0'&&a[i]<='9'&&f1==false)
                f1=true;

            if(a[i]>='A'&&a[i]<='Z'&&f1==true)
                f2=true;

        }

        if(f1==true&&f2==true)
        {
            ss.clear();
            ss<<a;
            ss>>c>>num1>>d>>num2;
            cout<<ans[num2]<<num1<<endl;
        }
        else
        {
            string temp="";

            for(i=0;i<k;i++)
            {
                if(a[i]>='A'&&a[i]<='Z')
                    temp+=a[i];
                else
                    break;
            }
            num1=i;
            for(i=1;i<1000002;i++)
                if(ans[i]==temp) break;
            num2=i;

            temp="";

            for(i=num1;i<k;i++)
                temp+=a[i];
            ss.clear();
            ss<<temp;
            ss>>num1;


            printf("R%dC%d\n", num1, num2);
        }
    }
}
