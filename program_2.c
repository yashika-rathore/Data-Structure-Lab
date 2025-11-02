#include <stdio.h>
#define max 20
int main()
{
    int que[max],stk1[max],stk2[max];
    int ch,i,j,top1=-1,top2=-1,front=0,rare=-1,val;
    char resp;
    do{
    printf("\n1.Insertion\n2.Deletion\n3.Display\n Enter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        //insertion
        if(top1==max-1)
            printf("\nQueue is full.");
        else
            top1++;
            printf("\nEnter the element:");
            scanf("%d",&val);
            stk1[top1]=val;
        break;
    case 2:
        //deletion
        if(top1==-1)
            printf("\nQueue is empty.");
        else
        {
            while(top1!=-1)
            {
                top2++;
                stk2[top2]=stk1[top1];
                top1--;
            }
            printf("\n%d is deleted",stk2[top2]);
            top2--;
            while(top2!=-1)
            {
                top1++;
                stk1[top1]=stk2[top2];
                top2--;
            }
        }
        break;
    case 3:
        //display
        printf("\nElements are:\n");
        for(i=0;i<=top1;i++)
        {
            printf("\n%d",stk1[i]);
        }
        break;
    }
    printf("\nDo you want to continue(y/n): ");
    scanf(" %c",&resp);
    }while (resp=='y');
    return 0;
}