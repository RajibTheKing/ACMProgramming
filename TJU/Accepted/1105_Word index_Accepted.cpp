#include<stdio.h>
#include<string.h>
#include<iostream.h>
int main()
{

    while(1){
        char a[6];
        char t[6];
        int i, j, k, flag, ans, count, f;
        gets(a);
        k=strlen(a);

        flag=1;
        for(i=0; ; i++)
        {
            if(a[i+1]=='\0')
                break;
            if(a[i]>=a[i+1])
                {
                    flag=0;
                    break;
                }
        }


        ans=0;
        if(flag==0)
            printf("%d\n", ans);
        else
        {
            if(k==1)
            {
                count=1;
                for(t[0]='a'; ;t[0]++)
                {
                    ans=count;
                    if(a[0]==t[0])
                        break;
                    count++;
                }
            }
            count=27;
            f=0;
            if(k==2)
            {
                for(t[0]='a'; ;t[0]++)
                {
                    for(t[1]=t[0]+1;t[1]<='z';t[1]++)
                    {
                        ans=count;
                        if(t[0]==a[0]&&t[1]==a[1])
                        {
                            f=1;
                            break;
                        }
                        count++;

                    }

                    if(f==1)
                        break;
                }

            }
            count=352;
            f=0;
            if(k==3)
            {
                for(t[0]='a'; ;t[0]++)
                {
                    for(t[1]=t[0]+1;t[1]<='z';t[1]++)
                    {
                        for(t[2]=t[1]+1;t[2]<='z';t[2]++)
                        {
                            ans=count;
                            if(t[0]==a[0]&&t[1]==a[1]&&t[2]==a[2])
                            {
                                f=1;
                                break;
                            }
                            count++;
                        }
                    }

                    if(f==1)
                        break;
                }

            }
            count=2952;
            f=0;
            if(k==4)
            {
                for(t[0]='a'; ;t[0]++)
                {
                    for(t[1]=t[0]+1;t[1]<='z';t[1]++)
                    {
                        for(t[2]=t[1]+1;t[2]<='z';t[2]++)
                        {
                            for(t[3]=t[2]+1; t[3]<='z'; t[3]++)
                            {
                                ans=count;
                                if(t[0]==a[0]&&t[1]==a[1]&&t[2]==a[2]&&t[3]==a[3])
                                {
                                    f=1;
                                    break;
                                }
                                count++;
                            }
                        }
                    }

                    if(f==1)
                        break;
                }


            }
            count=17902;
            f=0;
            if(k==5)
            {
                for(t[0]='a'; ;t[0]++)
                {
                    for(t[1]=t[0]+1;t[1]<='z';t[1]++)
                    {
                        for(t[2]=t[1]+1;t[2]<='z';t[2]++)
                        {
                            for(t[3]=t[2]+1; t[3]<='z'; t[3]++)
                            {
                                for(t[4]=t[3]+1; t[4]<='z'; t[4]++)
                                {
                                    ans=count;
                                    if(t[0]==a[0]&&t[1]==a[1]&&t[2]==a[2]&&t[3]==a[3]&&t[4]==a[4])
                                    {
                                        f=1;
                                        break;
                                    }
                                    count++;
                                }
                            }
                        }
                    }

                    if(f==1)
                        break;
                }


            }



            printf("%d\n", ans);
        }




    }


        return 0;
}
