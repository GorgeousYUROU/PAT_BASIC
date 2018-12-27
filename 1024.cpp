//1024. 科学计数法 (20)
//
//科学计数法是科学家用来表示很大或很小的数字的一种方便的方法，其满足正则表达式[+-][1-9]"."[0-9]+E[+-][0-9]+，即数字的整数部分只有1位，小数部分至少有1位，该数字及其指数部分的正负号即使对正数也必定明确给出。
//
//现以科学计数法的格式给出实数A，请编写程序按普通数字表示法输出A，并保证所有有效位都被保留。
//
//输入格式：
//
//每个输入包含1个测试用例，即一个以科学计数法表示的实数A。该数字的存储长度不超过9999字节，且其指数的绝对值不超过9999。
//
//输出格式：
//
//对每个测试用例，在一行中按普通数字表示法输出A，并保证所有有效位都被保留，包括末尾的0。
//
//输入样例1：
//+1.23400E-03
//输出样例1：
//0.00123400
//输入样例2：
//-1.2E+10
//输出样例2：
//-12000000000
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
    char c[10010],a[10010],exp;
    int m=0;
    cin>>c;
    int len=strlen(c);
    if(c[0]=='-')
    cout<<c[0];
    int flag=1;
    int mul=0;
    for(int i=1;i<len;i++)
    {
       if(i==2) continue;
       if(c[i]=='E') {flag=0;exp=c[i+1];i++;a[m]='\0';}
       else
       {
       if(flag) a[m++]=c[i];
       else
       {
           mul=mul*10+(c[i]-'0');
       }
       }
    }
    if(exp=='+')
    {
       if(mul>=m-1)
       {
       printf("%s",a);
       mul=mul-m+1;
       while(mul--) printf("0");
       }
       else
       {
         for(int i=0;i<=mul;i++)
         printf("%c",a[i]);
         printf(".");
         for(int i=mul+1;i<m;i++)
         printf("%c",a[i]);
       }
    }
    else
    {
       cout<<"0.";
       for(int i=0;i<mul-1;i++)
       printf("0");
       printf("%s",a);
    }
}
