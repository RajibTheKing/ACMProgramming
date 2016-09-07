#include<iostream.h>
#include<string.h>
int main()
{
     char x[100], y[100], t[100];
     int n, a, i, j, k, l, temp1, temp2;
     scanf("%d", &n);
     while(n--)
     {
          scanf(" %s", x);
          scanf(" %s", y);
          k=strlen(x);
          l=strlen(y);
          for(i=0; i<k; i++)
          {
               t[i]=x[i];
          }
          j=-1;
          for(i=k-1; i>=0; i--)
          {
               x[++j]=t[i];
          }
          for(i=0; i<l; i++)
          {
               t[i]=y[i];
          }
          j=-1;
          for(i=l-1; i>=0; i--)
          {
               y[++j]=t[i];
          }
          temp1=atoi(x);
          temp2=atoi(y);
          a=temp1+temp2;

          cout<<a<<endl;

          cout<<endl;


     }
}
