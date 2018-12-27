//1017. A除以B (20)
//
//本题要求计算A/B，其中A是不超过1000位的正整数，B是1位正整数。你需要输出商数Q和余数R，使得A = B * Q + R成立。
//
//输入格式：
//
//输入在1行中依次给出A和B，中间以1空格分隔。
//
//输出格式：
//
//在1行中依次输出Q和R，中间以1空格分隔。
//
//输入样例：
//123456789050987654321 7
//输出样例：
//17636684150141093474 3
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int main()
{
    char a[1010],b[1010];
    int p,m,front,flag=0,t=0,q,r=0;
    cin>>a>>p;
    front=0;
    for(int i=0;i<strlen(a);i++)
    {
       int temp=a[i]-'0';
       front=r*10+temp;
       q=front/p;
       r=front%p;
       if(q&&(flag==0))
       {
           flag=1;
       }
       if(flag) b[t++]=char(q+'0');
    }
    if(t==0) cout<<0;
    for(int i=0;i<t;i++)
    {
        printf("%c",b[i]);
    }
    cout<<' '<<r;
}
