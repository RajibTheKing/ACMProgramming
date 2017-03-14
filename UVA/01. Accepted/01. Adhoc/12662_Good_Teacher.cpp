
#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    string str;
    string input_pure[150];
    int testCase, now, posLeft, posRight;


    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>str;
            input_pure[i] = str;
        }

        cin>>testCase;

        for(int i=0;i<testCase;i++)
        {
            cin>>now;
            now--;
            if(input_pure[now]!="?")
            {
                printf("%s\n", input_pure[now].c_str());
            }
            else
            {
                posLeft = -1;
                posRight = -1;
                for(int i=now;i>=0;i--) if(input_pure[i]!="?") {posLeft = i; break;}
                for(int i=now;i<n;i++) if(input_pure[i]!="?") {posRight = i; break;}

                //cout<<"PosLeft = "<<posLeft<<", "<<"PosRight = "<<posRight<<endl;


                if(posLeft == -1)
                {
                    for(int i=posRight;i>now;i--)
                    {
                        printf("left of ");
                    }
                    printf("%s\n", input_pure[posRight].c_str());
                }
                else if(posRight == -1)
                {
                    for(int i=posLeft;i<now;i++)
                    {
                        printf("right of ");
                    }
                    printf("%s\n", input_pure[posLeft].c_str());
                }
                else
                {
                    int diffLeft = now - posLeft;
                    int diffRight = posRight - now;
                    if(diffLeft == diffRight)
                    {
                        printf("middle of %s and %s\n", input_pure[posLeft].c_str(), input_pure[posRight].c_str());
                    }
                    else if(diffLeft>diffRight)
                    {
                        for(int i=posRight;i>now;i--)
                        {
                            printf("left of ");
                        }
                        printf("%s\n", input_pure[posRight].c_str());
                    }
                    else
                    {
                        for(int i=posLeft;i<now;i++)
                        {
                            printf("right of ");
                        }
                        printf("%s\n", input_pure[posLeft].c_str());
                    }
                }


            }


        }


    }
}

/*
10
A ? ? D ? ? ? H ? ?
4
3
8
6
10

*/


