#include<iostream.h>
#include<math.h>
main()
{
    int t, flag;
    cin>>t;
    while(t--)
    {
        flag=0;
        double x1, x2, x3, x4, y1,y2 , y3, y4, ac, bd, ad, bc, ab, cd;
        cin>>x1>>y1; cin>>x3>>y3;
        cin>>x2>>y2; cin>>x4>>y4;
        ac=(x1-x3)*(x1-x3)+(y1-y3)*(y1-y3);
        bd=(x2-x4)*(x2-x4)+(y2-y4)*(y2-y4);

        ad=(x1-x4)*(x1-x4)+(y1-y4)*(y1-y4);
        bc=(x2-x3)*(x2-x3)+(y2-y3)*(y2-y3);

        ab=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
        cd=(x3-x4)*(x3-x4)+(y3-y4)*(y3-y4);

        if(ac==bd)
            flag=1;

        if(ad!=bc)
            flag=1;

        if(ab!=cd)
            flag=1;

        if(ab==bc==cd==ad)
            flag=1;

        if(flag==0)
            printf("Yes\n");
        if(flag==1)
            printf("No\n");
    }
}
