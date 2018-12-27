// 1037. 在霍格沃茨找零钱（20）

// 如果你是哈利·波特迷，你会知道魔法世界有它自己的货币系统 —— 就如海格告诉哈利的：“十七个银西可(Sickle)兑一个加隆(Galleon)，二十九个纳特(Knut)兑一个西可，很容易。”现在，给定哈利应付的价钱P和他实付的钱A，你的任务是写一个程序来计算他应该被找的零钱。

// 输入格式：

// 输入在1行中分别给出P和A，格式为“Galleon.Sickle.Knut”，其间用1个空格分隔。这里Galleon是[0, 107]区间内的整数，Sickle是[0, 17)区间内的整数，Knut是[0, 29)区间内的整数。

// 输出格式：

// 在一行中用与输入同样的格式输出哈利应该被找的零钱。如果他没带够钱，那么输出的应该是负数。

// 输入样例1：
// 10.16.27 14.1.28
// 输出样例1：
// 3.2.1
// 输入样例2：
// 14.1.28 10.16.27
// 输出样例2：
// -3.2.1

#include<stdio.h>
#include<iostream>
using namespace std;
int compute(int g1,int s1,int k1,int g2,int s2,int k2,int &g3,int &s3,int &k3)
{
     if(k2-k1<0)
            {
                k3=k2+29-k1;
                s2--;
            }
            else {k3=k2-k1;}
            if(s2-s1<0)
            {
                s3=s2+17-s1;
                g2--;
            }
            else {s3=s2-s1;}
            g3=g2-g1;
}
int main()
{
    int g1,s1,k1,g2,s2,k2;
    scanf("%d.%d.%d",&g1,&s1,&k1);
    scanf("%d.%d.%d",&g2,&s2,&k2);
    int g3,s3,k3;
    //十七个银西可(Sickle)兑一个加隆(Galleon)，二十九个纳特(Knut)兑一个西可
    int flag=1;
    /*判断零钱是否为负*/
    if(g2<g1) flag=-1;
    else
    {
        if(g2==g1)
        {
            if(s2<s1) flag=-1;
            else if((s2==s1) && (k2<k1)) flag=-1;
        }
    }

    if(flag==1) compute(g1,s1,k1,g2,s2,k2,g3,s3,k3);
    else compute(g2,s2,k2,g1,s1,k1,g3,s3,k3);



    //output
    printf("%d.%d.%d",g3*flag,s3,k3);
}
