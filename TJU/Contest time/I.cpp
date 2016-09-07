#include<iostream.h>
#include<math.h>
main()
{
    int i, n, iso, scalen, right, obtuse, acute ;
    cin>>n;
    i=0;
    while(n)
    {
        i++;

        double x1, x2, x3, y1, y2, y3, a, b, c, s, flag, A, B, C, area;
        scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
        a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        b=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
        c=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));

        A=acos((b*b+c*c-a*a)/(2*b*c));
        B=acos((a*a+c*c-b*b)/(2*a*c));
        C=acos((b*b+a*a-c*c)/(2*b*a));
        s=(a+b+c)/2;
        A=A*180/3.14159;
        B=B*180/3.14159;
        C=C*180/3.14159;

        A=int(A); B=int(B); C=int(C);

        iso=0; scalen=0; right=0; obtuse=0; acute=0;
        area=sqrt(s*(s-a)*(s-b)*(s-c));
        if(area<=0)
        {
            flag=7;
            goto end;
        }

        if(a==b||b==c||a==c)
            iso=1;
        else
            scalen=1;

        if(A==90||B==90||C==90)
            right=1;

        if(A<90&&B<90&&C<90)
            acute=1;

        if(A>90||B>90||C>90)
            obtuse=1;

        if(iso==1&&obtuse==1) flag=1;
        if(iso==1&&acute==1) flag=2;
        if(iso==1&&right==1) flag=3;
        if(scalen==1&&obtuse==1) flag=4;
        if(scalen==1&&acute==1) flag=5;
        if(scalen==1&&right==1) flag=6;
end:

        if(flag==7) printf("Case #%d: not a triangle\n", i);
        if(flag==1) printf("Case #%d: isosceles obtuse triangle\n", i);
        if(flag==2) printf("Case #%d: isosceles acute triangle\n", i);
        if(flag==3) printf("Case #%d: isosceles right triangle\n", i);
        if(flag==4) printf("Case #%d: scalene obtuse triangle\n", i);
        if(flag==5) printf("Case #%d: scalene acute triangle\n", i);
        if(flag==6) printf("Case #%d: scalene right triangle\n", i);




        n--;
    }

}
