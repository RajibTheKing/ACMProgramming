#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<set>
#include<bitset>
#include<algorithm>
#include<list>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
using namespace std;

#define pb push_back
#define PI acos(-1.0)
#define SZ(a) (int)a.size()
#define csprnt printf("Case %d: ", ++kase)
#define EPS 1e-9
#define MAX 110000
#define LL long long
#define INF (1LL<<55)

int main()
{
    //freopen("testOutput.txt", "w", stdout);
    int goat, cow, mohish, mx=0;

    //while(true)
    {
        for(int i=1,goat=4;goat<=100;i++, goat+=4)
            for(cow=1;cow<=100;cow++)
                for(mohish=1;mohish<=100;mohish++)
                    if(goat+cow+mohish == i+cow+mohish*5 && i+cow+mohish*5==100){
                        //cout<<"Found"<<endl;

                        cout<<goat<<", "<<cow<<", "<<mohish<<endl;
                        mx = max(mx, goat+cow+mohish);
                        //goto Next;
                    }
        cout<<mx<<endl;

        //Next:
//        int picchi, old, khadok;
//
//        for(int i=1,picchi=7;picchi<=700;i++, picchi+=7)
//            for(old=1;old<=50;old++)
//                for(khadok=1;khadok<=100;khadok++)
//                    if(picchi+old+khadok == i+old+khadok*3 && i+old+khadok*3==100){
//                        //cout<<"Found"<<endl;
//                        cout<<picchi<<", "<<old<<", "<<khadok<<endl;
//                        //goto End;
//                    }
//        cout<<"Result Proccesing completed"<<endl;


    }


    return 0;
}

