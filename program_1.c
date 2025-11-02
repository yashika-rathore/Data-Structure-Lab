#include <stdio.h>
#define size 10
int main()
{
    char undo[size],redo[size],text;
    int topundo=-1,topredo=-1,choice,i;
    printf("\n----Text Editor Menu:----\n\t1.Type\n\t2.Undo\n\t3.Redo\n\t4.Display\n\t5.Exit");
    do
    {
        printf("\n\tEnter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                if(topundo==size-1)
                {
                    printf("\nMemory full! Can't type text");
                }
                else
                {
                    printf("\nType the text:");
                    scanf(" %c",&text);
                    topundo++;
                    undo[topundo]=text;
                }
                break;
            case 2:
                if(topundo==-1)
                {
                    printf("\nNothing to Undo");
                }
                else
                {
                    topredo++;
                    redo[topredo]=undo[topundo];
                    topundo--;
                    printf("\nUndo successfull!");
                }
                break;
            case 3:
                if(topredo==-1)
                {
                    printf("\nNothing to Redo");
                }
                else
                {
                    topundo++;
                    undo[topundo]=redo[topredo];
                    topredo--;
                    printf("\nRedo successfull!");
                }
                break;
            case 4:
                if(topundo==-1)
                {
                    printf("\nNothing to display!");
                }
                else
                {
                    for(i=0;i<=topundo;i++)
                    {
                        printf("\n%c",undo[i]);
                    }
                }
                break;
            case 5:
                printf("\nExiting....");
                return 0;
                break;
            default:
                printf("\nInvalid choice!");
                break;
            }

    }while(1);
}