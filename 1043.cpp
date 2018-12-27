//1043. 输出PATest(20)
//给定一个长度不超过10000的、仅由英文字母构成的字符串。请将字符重新调整顺序，按“PATestPATest....”这样的顺序输出，并忽略其它字符。当然，六种字符的个数不一定是一样多的，若某种字符已经输出完，则余下的字符仍按PATest的顺序打印，直到所有字符都被输出。
//
//输入格式：
//
//输入在一行中给出一个长度不超过10000的、仅由英文字母构成的非空字符串。
//
//输出格式：
//
//在一行中按题目要求输出排序后的字符串。题目保证输出非空。
//
//输入样例：
//redlesPayBestPATTopTeePHPereatitAPPT
//输出样例：
//PATestPATestPTetPTePePee
#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    char c;
    //PATest
    int count[6]={0};
    int max=0;
    while((c=getchar())!='\n')
    {
        switch(c)
        {
            case 'P':count[0]++;if(count[0]>max) max=count[0];break;
            case 'A':count[1]++;if(count[1]>max) max=count[1];break;
            case 'T':count[2]++;if(count[2]>max) max=count[2];break;
            case 'e':count[3]++;if(count[3]>max) max=count[3];break;
            case 's':count[4]++;if(count[4]>max) max=count[4];break;
            case 't':count[5]++;if(count[5]>max) max=count[5];break;
        }
    }
    for(int i=0;i<max;i++)
    {
        if(count[0]-->0)cout<<"P";
        if(count[1]-->0)cout<<"A";
        if(count[2]-->0)cout<<"T";
        if(count[3]-->0)cout<<"e";
        if(count[4]-->0)cout<<"s";
        if(count[5]-->0)cout<<"t";
    }

}
