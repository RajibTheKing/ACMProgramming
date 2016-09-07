#include<iostream.h>
#include<string.h>


char a1[10]={"BFPV"};
char a2[10]={"CGJKQSXZ"};
char a3[10]={"DT"};
char a4[10]={"L"};
char a5[10]={"MN"};
char a6[10]={"R"};
char a7[10]={"AEIOUHWY"};

main()
{
    char a[30];
    int i, j, k, t1=0, t2=0;
    while(scanf("%s", a)==1)
    {
        t1=0;
        t2=99;
        for(i=0; i<strlen(a); i++)
        {
            for(j=0; j<10; j++)
            {
                if(a[i]==a1[j])
                {
                    t1=t2;
                    t2=1;
                    if(t1!=t2)
                        printf("1");
                    break;
                }
                if(a[i]==a2[j])
                {
                    t1=t2;
                    t2=2;
                    if(t1!=t2)
                        printf("2");
                    break;
                }
                if(a[i]==a3[j])
                {
                    t1=t2;
                    t2=3;
                    if(t1!=t2)
                        printf("3");
                    break;
                }
                if(a[i]==a4[j])
                {
                    t1=t2;
                    t2=4;
                    if(t1!=t2)
                        printf("4");
                    break;
                }
                if(a[i]==a5[j])
                {
                    t1=t2;
                    t2=5;
                    if(t1!=t2)
                        printf("5");
                    break;
                }
                if(a[i]==a6[j])
                {
                    t1=t2;
                    t2=6;
                    if(t1!=t2)
                        printf("6");
                    break;
                }
                if(a[i]==a7[j])
                {
                    t1=t2;
                    t2=0;
                    break;
                }


            }
        }
        cout<<endl;


        for(i=0; i<30 ; i++)
            a[i]=NULL;
    }

}
