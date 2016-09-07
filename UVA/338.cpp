#include<stdio.h>

int main(){
    long long int a, b, mult;
    while(scanf("%lld %lld", &a, &b)!=EOF)
    {
        long long int c[10], d[20], len[20], temp[20], b1, a1, mult1;
        int len_a, len_b, len_mult;
        b1=b;
        a1=a;
        mult=a*b;
        mult1=mult;

        for(len_b=0; ; len_b++){
            c[len_b]=b1%10;
            b1=b1/10;
            if(b1<1)
                break;
        }
        c[len_b+1]=b1;

        for(len_a=0; ; len_a++){
            a1=a1/10;
            if(a1<1)
                break;
        }
        for(len_mult=0; ; len_mult++){
            mult1=mult1/10;
            if(mult1<1)
                break;
        }
        int temp_mult=len_mult;
        for(int j=0; j<=len_b; j++){
            d[j]=a*c[j];
        }

        if(b<10||a<10){
            if(a==0 && b==0)
                printf("%lld\n%lld\n-\n%lld\n", a, b, a*b);
            else if(a==0||b==0){
                if(a>b){
                    printf("%lld\n", a);
                    for(int j=0; j<len_a-len_b; j++)
                        printf(" ");
                    printf("%lld\n", b);
                    for(int j=0; j<=len_a; j++)
                        printf("-");
                    printf("\n");
                    for(int j=0; j<len_a-len_mult; j++)
                        printf(" ");
                    printf("%lld\n", mult);
                }
                if(b>a){
                    for(int j=0; j<len_b-len_a; j++)
                        printf(" ");
                    printf("%lld\n", a);
                    printf("%lld\n", b);
                    for(int j=0; j<=len_b; j++)
                        printf("-");
                    printf("\n");
                    for(int j=0; j<len_b-len_mult; j++)
                        printf(" ");
                    printf("%lld\n", mult);
                }
            }

            else{
                for(int j=0; j<len_mult-len_a; j++)
                    printf(" ");
                printf("%lld\n", a);
                for(int j=0; j<len_mult-len_b; j++)
                    printf(" ");
                printf("%lld\n", b);
                if(len_a>=len_b){
                    for(int j=0; j<len_mult-len_a; j++)
                        printf(" ");
                    for(int j=0; j<=len_a; j++)
                        printf("-");
                }
                else if(len_b>=len_a){
                    for(int j=0; j<len_mult-len_b; j++)
                        printf(" ");
                    for(int j=0; j<=len_b; j++)
                        printf("-");
                }
                printf("\n%lld\n", mult);
            }
        }

        else{
            for(int j=0; j<len_mult-len_a; j++)
                printf(" ");
            printf("%lld\n", a);
            for(int j=0; j<len_mult-len_b; j++)
                printf(" ");
            printf("%lld\n", b);
            temp[0]=d[0];
            if(len_a>=len_b){
                for(int j=0; j<len_mult-len_a; j++)
                    printf(" ");
                for(int j=0; j<=len_a; j++)
                        printf("-");
            }
            else if(len_b>=len_a){
                for(int j=0; j<len_mult-len_a; j++)
                    printf(" ");
                for(int j=0; j<=len_b; j++)
                        printf("-");
            }
            printf("\n");
            for(int j=0; j<=len_b; j++){
                temp[j]=d[j];
                for(len[j]=0; ; len[j]++){
                    temp[j]=temp[j]/10;
                    if(temp[j]<1)
                        break;
                }
                for(int k=0; k<temp_mult-len[j]; k++){
                    printf(" ");
                }
                temp_mult--;
                printf("%lld\n", d[j]);
            }
            for(int j=0; j<=len_mult; j++)
                printf("-");
            printf("\n%lld\n", mult);
        }
    }
    return 0;
}

