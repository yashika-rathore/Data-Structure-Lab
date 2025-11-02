#include <stdio.h>
#define size 10
int hash(int key)
{
    return key%size;
}
void insert(int table[],int key)
{
    int index=hash(key);
    while(table[index]!=-1)
    {
        index=(index+1)%size;
    }
    table[index]=key;
}
void display(int table[])
{
    printf("HASH TABLE");
    for(int i=0;i<size;i++)
    {
        printf("\n Index %d=%d",i,table[i]);
    }
}
int main()
{
    int hashtable[size];
    for(int i=0;i<size;i++)
    {
        hashtable[i]=-1;
    }
    int key[]={20,25,30,40,46,50,23,68,70};
    int n=sizeof(key)/sizeof(key[0]);
    for(int i=0;i<n;i++)
    {
        insert(hashtable,key[i]);
    }
    display(hashtable);
    return 0;
}