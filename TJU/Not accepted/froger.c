#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    while(1<2){
    int n,i,min=0, j, count;
    float x[201], y[201];
    float distance[90000], c;
    scanf("%d", &n);
    if(n==0)
        goto end;

    static int scene=1;

    for(i=0;i<n ; i++)
        scanf("%f %f", &x[i], &y[i]);
    count=-1;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            {
                if(i==j)
                continue;

                count++;
                distance[count]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));

            }

    }

    for(i=0; i<=count; i++)
    {
        for(j=i+1; j<=count; j++)
        {
            if(distance[i]>distance[j])
                {
                    c=distance[i];
                    distance[i]=distance[j];
                    distance[j]=c;
                }


        }
    }
    printf("Scenario #%d\n", scene);
    printf("Frog Distance = %.3f\n", distance[0]);

    scene++;

    }
end:
    return 0;

}
