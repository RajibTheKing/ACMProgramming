#include<stdio.h>
int main()
{
     double a,b,x[2],y[2],d1,d2;
     int n;
     while(5==scanf("%d %lf %lf %lf %lf",&n,&x[0],&y[0],&x[1],&y[1]))
     {
	   while(n--)
	   {
		 scanf("%lf %lf",&a,&b);
		 d1=(x[0]-a)*(x[0]-a)+(y[0]-b)*(y[0]-b);
		 d2=(x[1]-a)*(x[1]-a)+(y[1]-b)*(y[1]-b);
		 if(4*d1<=d2){
		      printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n",a,b);
		      while(n--)
			    scanf("%lf %lf",&a,&b);
		      n=0;
		      break;
		 }
	   }
	   if(n==-1)
	       printf("The gopher cannot escape.\n");
     }
     return 0;
}
