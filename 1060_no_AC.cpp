#include<iostream>
#include<stdio.h>

using namespace std;
int main()
{
    int a[200000]={0};
    int max=0;
    int N,temp;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        scanf("%d",&temp);
        a[temp]++;
    }
    temp=0;
    for(int i=1;i<200000;i++)
    {
        if(a[i]!=0)
        {
        a[i]+=a[temp];
        temp=i;
            if(N-a[i] >= i)
            {
                max=i;
            }
        }
    }
    printf("%d",max);
    return 0;
}
