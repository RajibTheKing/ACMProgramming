#include<stdio.h>
#include<iostream.h>
#include<string.h>
int a[1000];
int main()
{
        int c;
        cin>>c;
        while(c)
        {
                memset(a, 0, 1000*sizeof(int));
                int N, M, i, A, B, t, temp, j, ans, flag=1;
                cin>>N;
                for(i=1; i<=N; i++)
                        a[i]=i;
                cin>>M;
                if(M==0)
                {
                        flag=0;
                        goto end;
                }
                while(M)
                {
                        scanf("%d %d", &A, &B);
                        if(B<A)
                        {
                                temp=A;
                                A=B;
                                B=temp;
                        }
                        t=a[B];
                        a[B]=a[A];
                        for(i=1; i<=N; i++)
                                if(a[i]==t)
                                        a[i]=a[A];
                        M--;
                }
                for(i=1; i<=N; i++)
                        for(j=i+1; j<=N; j++)
                                if(a[i]>a[j])
                                {
                                        temp=a[i];
                                        a[i]=a[j];
                                        a[j]=temp;
                                }

                ans=1;
                t=a[1];
                for(i=1; i<=N; i++)
                {
                        if(t!=a[i])
                        {
                                t=a[i];
                                ans++;
                        }
                }
end:
                if(flag==0)
                        cout<<N;
                else
                        cout<<ans;


                cout<<"\n";
                c--;
        }
        return 0;
}
