#include<iostream>
#include<stdio.h>
using namespace std;

int b[505];
int ans[505];
char Side[505];
class Node
{
public:
    int item;
    Node *next;

    Node(int a)
    {
        item = a;
        next = NULL;
    }
};

int main()
{
    int n, k, temp;
    Node *Head = NULL, *newNode=NULL, *LastNode=NULL;

    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d", &temp);
            newNode = new Node(temp);
            if(Head==NULL)
            {
                Head = newNode;
                LastNode = newNode;
            }
            else
            {
                LastNode->next = newNode;
                LastNode = newNode;
            }
        }

        scanf("%d", &k);
        for(int i=0;i<k;i++)
        {
            scanf("%d", &b[i]);
        }

        int indx = 0;
        int ansIndx = 0;
        while(indx<k)
        {
            if(Head->item == b[indx])
            {
                indx++;
                Head = Head->next;
            }

            Node *ptr = Head;
            Node *prev = NULL;
            int kounter = indx;

            bool flag = false;

            while(ptr!=NULL)
            {
                kounter++;
                if(prev==NULL)
                {
                    prev=ptr;
                    ptr=ptr->next;
                    continue;
                }
                else
                {
                    if(prev->item != ptr->item)
                    {

                        if(prev->item < ptr->item)
                        {
                            ans[ansIndx] = kounter;
                            Side[ansIndx++] = 'L';
                        }
                        else
                        {
                            ans[ansIndx] = kounter-1;
                            Side[ansIndx++] = 'R';
                        }

                        prev->item += ptr->item;
                        prev->next = ptr->next;



                        flag = true;
                        break;
                    }

                    prev=ptr;
                    ptr=ptr->next;

                }
            }
            if(flag==false)
            {
                break;
            }

        }
        if(indx!=k)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
            for(int i=0;i<ansIndx;i++)
            {
                cout<<ans[i]<<" "<<Side[i]<<endl;
            }
        }


    }

    return 0;
}
