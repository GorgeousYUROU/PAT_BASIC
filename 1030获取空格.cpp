// 1033. 旧键盘打字(20)
// 旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、以及坏掉的那些键，打出的结果文字会是怎样？

// 输入格式：

// 输入在2行中分别给出坏掉的那些键、以及应该输入的文字。其中对应英文字母的坏键以大写给出；每段文字是不超过105个字符的串。可用的字符包括字母[a-z, A-Z]、数字0-9、以及下划线“_”（代表空格）、“,”、“.”、“-”、“+”（代表上档键）。题目保证第2行输入的文字串非空。

// 注意：如果上档键坏掉了，那么大写的英文字母无法被打出。

// 输出格式：

// 在一行中输出能够被打出的结果文字。如果没有一个字符能被打出，则输出空行。

// 输入样例：
// 7+IE.
// 7_This_is_a_test.
// 输出样例：
// _hs_s_a_tst

// 需要获取空格

#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int main()
{
    int miss[100]={0};
    char loss[100];
    char pre[100000];
//    char *m1="_,.-+";
//    for(int i=0;i<5;i++)
//    cout<<(int)(m1[i])<<" ";
     gets(loss);
     gets(pre);
     int m;
    for(int i=0;loss[i]!='\0';i++)
    {
        miss[(int)(loss[i]-43)]++;
    }
    int input=1;
    if(strchr(loss,'+')) input=0;
    for(int i=0;pre[i]!='\0';i++)
    {
        if('A'<=pre[i]&&pre[i]<='Z')
        {
            if(input==0) continue;
        }
        m=(int)(pre[i]-43);
        if('a'<=pre[i]&&pre[i]<='z') m-=32;
        if( miss[m]) continue;
        printf("%c",pre[i]);
    }

}