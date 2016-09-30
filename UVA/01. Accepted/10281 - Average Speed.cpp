#include<iostream>
#include<string>
#include<stdio.h>
#include<map>
#include<sstream>
#include<string.h>
using namespace std;
int main()
{
    char a[1000];
    int speed;
    char c=' ';
    bool flag;
    int hh, mm, ss, th=0, tm=0, ts=0, tspeed=0, t1, t2, time;
    double sum=0, distance;
    while(gets(a))
    {
        flag=false;

        for(int i=0;i<strlen(a);i++)
            if(a[i]==c)
                flag=true;
        if(flag)
        {
            sscanf(a, "%d:%d:%d %d", &hh, &mm, &ss, &speed);
            t2 = hh*3600+mm*60+ss;
            t1 = th*3600+tm*60+ts;
            time=t2-t1;
            distance = time * (double)tspeed/3600.0;
            sum+=distance;
            th=hh;
            tm=mm;
            ts=ss;
            tspeed=speed;


        }
        else
        {
            sscanf(a, "%d:%d:%d %d", &hh, &mm, &ss);
            t2 = hh*3600+mm*60+ss;
            t1 = th*3600+tm*60+ts;
            time=t2-t1;
            distance = time * (double)tspeed/3600.0;
            sum+=distance;
            th=hh;
            tm=mm;
            ts=ss;
            printf("%d%d:%d%d:%d%d %.2lf km\n", hh / 10, hh % 10, mm / 10, mm % 10, ss / 10, ss % 10, sum);

        }


    }
    return 0;
}
