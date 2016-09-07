#include<stdio.h>
#include<math.h>
int main()
{
    float u, a, t, v, s, n, f1=0, f2=0, f3=0, f4=0;
    int count=0;
    while(scanf("%f", &n)==1){
    count++;
    if(n==1)
    {
        f1=1;
        scanf("%f %f %f", &u, &v, &t);
        a=(v-u)/t;
        s=(u*t)+0.5*a*(t*t);
    }
    else if(n==2)
    {
        f2=1;
        scanf("%f %f %f", &u, &v, &a);
        t=(v-u)/a;
        s=(u*t)+0.5*a*(t*t);

    }
    else if(n==3)
    {
        f3=1;
        scanf("%f %f %f", &u, &a, &s);
        v=sqrt((u*u)+(2*a*s));
        t=(v-u)/a;

    }
    else if(n==4)
    {
        f4=1;
        scanf("%f %f %f", &v, &a, &s);
        u=sqrt((v*v)-(2*a*s));
        t=(v-u)/a;

    }
    else if(n==0)
        goto end;

    printf("Case %d:", count);
    if(f1==1)
        printf(" %0.3f %0.3f\n", s, a);
    if(f2==1)
        printf(" %0.3f %0.3f\n", s, t);
    if(f3==1)
        printf(" %0.3f %0.3f\n", v, t);
    if(f4==1)
        printf(" %0.3f %0.3f\n", u, t);

    f1=0; f2=0; f3=0; f4=0;
}

end:
    return 0;

}
