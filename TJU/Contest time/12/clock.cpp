#include<iostream.h>
int main()
{
     double hour1,hour2, t=0.0833333333;
     int min, count;
     int i, j, h1, h2, m1, m2, flag, flag2;
     while(scanf("%d %d %d %d", &h1, &m1, &h2, &m2)==4)
     {
          min=m1;
          hour1=h1*5+t*m1;
          hour2=h2*5+t*m2;
          if(hour2>=60)
               hour2=0;

          count=0;
          flag=0; flag2=0;
          for(; ;)
          {
               if(min==int(hour1))
               {
                    flag=1;
                    flag2=1;
               }
               if(min>hour1&&flag==1)
               {
                    count++;
                    flag=0;
               }

               min++;
               hour1=hour1+t;
               if(min==60)
                    min=0;
               if(hour1>=60)
                    hour1=0;

               if(hour1>=hour2&&flag2==1)
                    break;
          }

          cout<<count<<endl;

     }
}
