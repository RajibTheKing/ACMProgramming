#include<iostream.h>
int main()
{
    int category;
    int h, w,i, j, k;
    while(1<2)
    {
        cin>>category;
        if(category==1)
        {
            cin>>h;

            cout<<"\n";
            for(i=0;i<h; i++)
            {
                for(j=i+1; j<h; j++)
                {
                    cout<<" ";
                }
                for(k=0; k<=i+i; k++)
                {
                    cout<<"*";
                }
                cout<<"\n";
            }


        }
        if(category==2)
        {
            cin>>w;
            cin>>h;
            cout<<"\n";
            for(i=0; i<h; i++)
            {
                for(j=i+1; j<h; j++)
                    cout<<" ";
                for(k=0; k<w; k++)
                    cout<<"*";
                cout<<"\n";
            }
        }
        if(category==3)
        {
            cin>>w;
            cin>>h;
            cout<<"\n";
            for(i=0; i<h; i++)
            {
                for(j=0; j<w; j++)
                    cout<<"*";
                cout<<"\n";
            }
        }

        if(category==-1)
            goto finish;

    }

finish:
    return 0;
}
