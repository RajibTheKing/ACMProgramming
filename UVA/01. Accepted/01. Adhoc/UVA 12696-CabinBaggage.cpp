#include<stdio.h>

int main(){
    //freopen("in.txt","r",stdin);
    int n ,i ;
    while( scanf("%d",&n) != EOF ){
        int Cnt = 0 ;
        for(i=0;i<n;i++)
        {
            double len , wid , dep , wgth ;
            scanf("%lf %lf %lf %lf",&len , &wid , &dep ,&wgth);
            if( ( (len <= 56.00 && wid <= 45.00 && dep <= 25.00 ) || ( len + wid + dep <= 125.00 ) ) && wgth <= 7.00  )
            {
                  Cnt++ ; puts("1");
            }
            else puts("0");
        }
        printf("%d\n",Cnt);
    }
}
