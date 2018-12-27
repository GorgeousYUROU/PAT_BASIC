#include<stdio.h>
int num,head,tail;
int a[101];
void Enqueue(int x){
    if(num==0)
    {
       head=tail=0;
       a[tail]=x;
       num++;
    }
    else
    {
       tail=(tail+1)%100;
       a[tail]=x;
       num++;
    }
}

int Dequeue()
{
    int z=a[head];
    head=(head+1)%100;
    num--;
    return z;
}

int main()
{
    int i,j,answer,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        Enqueue(i);
    }
    for(i=1;i<=n-1;i++)
    {
        j=Dequeue();
        Dequeue();
        Enqueue(j);
    }
    printf("%d",a[head]);
}
