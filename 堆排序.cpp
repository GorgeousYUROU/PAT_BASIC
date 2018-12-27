#include<stdio.h>
#include<iostream>

void swap(long long &a,long long &b)
{
long long temp;
temp=a;
a=b;
b=temp;
}

void heapAjust(long long a[],int size,int i)
{
    int left,right,max;
    if(i<=size/2)
    {
        left=i*2;right=i*2+1;
        if(left<=size && a[left-1]>a[i-1]) {max=left;}
        else max=i;
        if(right<=size && a[right-1]>a[max-1]) {max=right;}
        if(max!=i)
        {
            swap(a[i-1],a[max-1]);
            heapAjust(a,size,max);
        }
    }
}

void insert(long long a[],int n)
{
   int i=n;
   int parent;
   while(i>=1)
   {
       parent=i/2;
       if(a[i]>a[parent]) swap(a[i],a[parent]);
       i=i/2;
   }
}

void pop(long long a[],int n)
{
   int i;
   int parent;
   /*extract_min*/
   swap(a[n],a[0]);
   n=n-1;
   heapAjust(a,n+1,1);
}


int main()
{
    long long sum=0;
    /*input*/
    int n;
    scanf("%d",&n);
    int instruct;
    long long num;
    long long a[n];
    int i=0;
    while(n--)
    {
        scanf("%d",&instruct);
        if(instruct==0) scanf("%ld",&num);
        /*push*/
        if(instruct==0)
        {
            a[i++]=num;
            insert(a,i-1);
            for(int j=0;j<i;j++) printf("%ld ",a[j]);
        }

        /*pop*/

        if(instruct==1)
        {
            pop(a,i-1);
            i--;
        }


        /*top sum*/

         if(instruct==2)
        {
            sum+=a[0];
        }
    }

    /*output*/
    printf("%ld\n",sum);
    for(int j=0;j<i;j++) printf("%ld ",a[j]);
}
