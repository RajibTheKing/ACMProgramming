
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
using namespace std;


typedef struct Node
{
    int volume;
    float acc;

};

Node data[505];


bool cmp(Node a, Node b)
{
    if( fabs(a.acc - b.acc) <= 0.000001)
        return a.volume>b.volume;

    return a.acc>b.acc;

}

int main()
{

    int n, l, w, h;
    while(cin>>n)
    {
        if(n==0) break;

        int indx = 0;
        for(int i=0;i<n;i++)
        {
            cin>>l>>w>>h;
            data[indx].volume = l*w*h;
            data[indx++].acc = 9.8 - 9.8/(2*1.0*h);
        }

        sort(&data[0], &data[indx], cmp);

        printf("%d\n", data[0].volume);

    }

    return 0;
}
