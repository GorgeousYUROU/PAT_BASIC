
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
    /*input*/
    char A[102],B[202];
    char *c="0123456789JQK";
    cin>>A>>B;
    int ta=strlen(A),tb=strlen(B);
    int i,j;
    if(tb>ta)
    {
        for(int j=0;j<tb-ta;j++) printf("%c",c[B[j]-'0']);
        i=0;
        j=tb-ta;
    }
    if(ta>tb)
    {
        for(int j=0;j<ta-tb;j++)
        {
        if((ta-j)%2!=0)
        {
        printf("%c",c[A[j]-'0']);
        }
        else
        {
            printf("%c",c['0'-A[j]+10]);
        }
        }
        j=0;
        i=ta-tb;
    }
    if(ta==tb)
    {
        j=0;
        i=0;
    }


    for(;i<=ta-1;i++,j++)
    {
        if((ta-i)%2==0)
        {
            if((int)(B[j]-A[i])>=0)
            {
                printf("%c",c[B[j]-A[i]]);
            }
            else
            {
                printf("%c",c[B[j]-A[i]+10]);
            }
        }
        else
        {
             printf("%c",c[ (B[j]+A[i]-'0'-'0')%13 ]);
        }
    }

return 0;
}
