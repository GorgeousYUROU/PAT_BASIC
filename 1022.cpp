//1022. D进制的A+B (20)
//
//输入两个非负10进制整数A和B(<=230-1)，输出A+B的D (1 < D <= 10)进制数。
//
//输入格式：
//
//输入在一行中依次给出3个整数A、B和D。
//
//输出格式：
//
//输出A+B的D进制数。
//
//输入样例：
//123 456 8
//输出样例：
//110

#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int a,b;
    char c[100];
    cin>>a>>b;
    int sum=a+b;
    int d,i=0;
    cin>>d;
    int r=sum;
    if(sum==0) {printf("0");return 0;}
    while(r)
    {
        c[i++]=(char)(r%d+'0');
        r=r/d;
    }
    for(int j=i-1;j>=0;j--)
    {
        printf("%c",c[j]);
    }
}
