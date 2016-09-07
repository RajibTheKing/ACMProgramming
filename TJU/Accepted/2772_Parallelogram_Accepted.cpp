#include<iostream.h>
#include<math.h>
int main()
{

    double x1, y1, x2, y2, x3, y3, x4, y4;
    double ac, bd, ab, dc, ad, bc;
    int n, flag;
    int i, j;
    cin>>n;
    for(i=0;i<n; i++)
    {
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &x1, &y1, &x3, &y3, &x2, &y2, &x4, &y4);
        ac=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
        bd=sqrt((x2-x4)*(x2-x4)+(y2-y4)*(y2-y4));
        if(ac==bd)
        {
            flag=0;
        }
        else
        {
            ab=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
            dc=sqrt((x4-x3)*(x4-x3)+(y4-y3)*(y4-y3));
            ad=sqrt((x1-x4)*(x1-x4)+(y1-y4)*(y1-y4));
            bc=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
            if(ab==dc&&ad==bc&&ab==ad)
            {
                flag=0;
            }
            else if(ab==dc&&ad==bc)
            {
                flag=1;
            }
            else
             flag=0;

        }
        if(flag==1)
            cout<<"Yes\n";
        else
            cout<<"No\n";
        flag==0;

    }
    return 0;
}
