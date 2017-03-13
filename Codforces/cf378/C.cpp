#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int s[3], pos;
    Node()
    {

    }
    Node(int a, int b, int c)
    {
        if (a > c)
            swap(a, c);
        if (a > b)
            swap(a, b);
        if (b > c)
            swap(b, c);
        s[0]=a;
        s[1]=b;
        s[2]=c;
    }

    void print(){
        cout<<s[0]<<" "<<s[1]<<" "<<s[2]<<", "<<pos<<endl;
    }

    int getMin()
    {
        return s[0];
    }

};

Node Data[100010];
bool color[3];

int isMatch(Node p, Node q)
{
    int knt = 0;
    color[0]=color[1] = color[2] = false;

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(p.s[i]==q.s[j] && color[j]==false)
            {
                color[j] = true;
                knt++;
            }
        }
    }
    if(knt>=2)
    {
        for(int i=0;i<3;i++)
        {
            if(color[i]==false) return i;
        }

        return 3;
    }

    return -1;
}

bool cmp(Node p, Node q)
{
    return p.getMin()>q.getMin();
}

int main()
{

    int n;
    while(cin>>n)
    {
        int a, b, c;

        Node mx;

        for(int i=0;i<n;i++)
        {
            scanf("%d %d %d", &a, &b, &c);
            Data[i] = Node(a,b,c);
            Data[i].pos =i;
        }

        sort(&Data[0], &Data[n], cmp);
        for(int i=0;i<n;i++)
        {
            Data[i].print();
        }


        mx = Data[0];
        int singleStoneAns = 0, d1 = -1, d2 = -1;
        for(int i=1;i<n;i++)
        {
            int temp = Data[i].getMin();
            if(mx.getMin() < temp)
            {
                mx = Data[i];
                singleStoneAns = Data[i].pos;
            }
        }

        //mx.print();

        for(int i=0;i<n;i++)
        {

            for(int j=i+1;j<n;j++)
            {
                if((Data[i].getMin()+Data[j].getMin()) < mx.getMin()) break;

                int ret = isMatch(Data[i], Data[j]);
                if(ret == -1) continue;

                if(ret<3)
                {
                    Node now = Node(Data[i].s[0],Data[i].s[1], Data[i].s[2]);
                    now.s[ret] = Data[i].s[ret]+Data[j].s[ret];
                    now = Node(now.s[0], now.s[1], now.s[2]);
                    //now.print();
                    if(mx.getMin() < now.getMin())
                    {

                        mx = now;
                        d1 = Data[i].pos;
                        d2 = Data[j].pos;

                        cout<<"Here 2 same"<<endl;
                        Data[i].print();
                        Data[j].print();

                    }
                }
                else
                {
                    Node now = Node(Data[i].s[0],Data[i].s[1], Data[i].s[2]);
                    now.s[0] = Data[i].s[0]+Data[j].s[0];
                    now = Node(now.s[0], now.s[1], now.s[2]);
                    if(mx.getMin() < now.getMin())
                    {
                        mx = now;
                        d1 = Data[i].pos;
                        d2 = Data[j].pos;

                        cout<<"Here 3 same"<<endl;
                        Data[i].print();
                        Data[j].print();

                    }
                }

            }
        }


        if(d1!=-1)
        {
            //cout<<"2"<<endl;
            //cout<<d1+1<<" "<<d2+1<<endl;
            printf("2\n%d %d\n", d1+1, d2+1);
        }
        else
        {
            //cout<<"1"<<endl;
            //cout<<singleStoneAns+1<<endl;
            printf("1\n%d\n", singleStoneAns+1);
        }



    }

    return 0;
}

/*
3
10 5 4
4 6 10
7 7 7

*/


