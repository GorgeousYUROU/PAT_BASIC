//1057. 数零壹(20)
//
//给定一串长度不超过105的字符串，本题要求你将其中所有英文字母的序号（字母a-z对应序号1-26，不分大小写）相加，得到整数N，然后再分析一下N的二进制表示中有多少0、多少1。例如给定字符串“PAT (Basic)”，其字母序号之和为：16+1+20+2+1+19+9+3=71，而71的二进制是1000111，即有3个0、4个1。
//
//输入格式：
//
//输入在一行中给出长度不超过105、以回车结束的字符串。
//
//输出格式：
//
//在一行中先后输出0的个数和1的个数，其间以空格分隔。
//
//输入样例：
//PAT (Basic)
//输出样例：
//3 4
#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    /*input*/
    int sum=0;
    char c;
    while((c=getchar())!='\n')
    {
        if(65<=c && c<=90)
        {
           c=c+32;
        }
        if(97<=c && c<=122)
        {
            sum+=(int)(c-96);
        }
    }

    /*judge how much 0 1*/
    int n=sum;
    int count0=0,count1=0;
    while(n!=0)
    {
        if(n%2==0) count0++;
        else count1++;
        n=n/2;
    }
    /*output count of 0 1*/
    cout<<count0<<" "<<count1<<endl;
}
