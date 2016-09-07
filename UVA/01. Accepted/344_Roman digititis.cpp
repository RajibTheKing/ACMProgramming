#include<iostream.h>
int main()
{
    int n, temp;

    while(1)
    {
        temp=1;
        int i=0, v=0, x=0, l=0, c=0;
        int xp=0, lp=0, cp=0;
        cin>>n;
        if(n==0)
            break;
        if(n<=100)
        {
            for(temp=1; temp<=n; temp++){
                if(temp==40)
                {
                    lp++;
                    xp=1;
                }

                if(temp==50)
                {
                    lp=1;
                    xp=0;
                }
                if(temp==90)
                {
                    cp++;
                    lp=0;
                    xp=1;
                }
                if(temp==100)
                {
                    c++;
                    break;
                }

            if(temp%10==1)
            {
                i++;
                x=x+xp;
                l=l+lp;
                c=c+cp;
            }
            else if(temp%10==2)
            {
                i=i+2;
                x=x+xp;
                l=l+lp;
                c=c+cp;
            }
            else if(temp%10==3)
            {
                i=i+3;
                x=x+xp;
                l=l+lp;
                c=c+cp;
            }
            else if(temp%10==4)
            {
                i++;  v++;
                x=x+xp;
                l=l+lp;
                c=c+cp;
            }
            else if(temp%10==5)
            {
                v++;
                x=x+xp;
                l=l+lp;
                c=c+cp;
            }
            else if(temp%10==6)
            {
                i++;
                v++;
                x=x+xp;
                l=l+lp;
                c=c+cp;
            }
            else if(temp%10==7)
            {
                x=x+xp;
                i=i+2;
                v++;
                l=l+lp;
                c=c+cp;
            }
            else if(temp%10==8)
            {
                x=x+xp;
                i=i+3;
                v++;
                l=l+lp;
                c=c+cp;
            }
            else if(temp%10==9)
            {
                xp++;
                x=x+xp;
                i++;
                l=l+lp;
                c=c+cp;
            }
            else
            {

                x=x+xp;
                l=l+lp;
                c=c+cp;
            }
            }
        }

        printf("%d: %d i, %d v, %d x, %d l, %d c\n",n, i, v, x, l, c  );
    }
    return 0;
}
