// 1059. C语言竞赛(20)

// C语言竞赛是浙江大学计算机学院主持的一个欢乐的竞赛。既然竞赛主旨是为了好玩，颁奖规则也就制定得很滑稽：

// 0. 冠军将赢得一份“神秘大奖”（比如很巨大的一本学生研究论文集……）。
// 1. 排名为素数的学生将赢得最好的奖品 —— 小黄人玩偶！
// 2. 其他人将得到巧克力。

// 给定比赛的最终排名以及一系列参赛者的ID，你要给出这些参赛者应该获得的奖品。

// 输入格式：

// 输入第一行给出一个正整数N（<=10000），是参赛者人数。随后N行给出最终排名，每行按排名顺序给出一位参赛者的ID（4位数字组成）。接下来给出一个正整数K以及K个需要查询的ID。

// 输出格式：

// 对每个要查询的ID，在一行中输出“ID: 奖品”，其中奖品或者是“Mystery Award”（神秘大奖）、或者是“Minion”（小黄人）、或者是“Chocolate”（巧克力）。如果所查ID根本不在排名里，打印“Are you kidding?”（耍我呢？）。如果该ID已经查过了（即奖品已经领过了），打印“ID: Checked”（不能多吃多占）。

// 输入样例：
// 6
// 1111
// 6666
// 8888
// 1234
// 5555
// 0001
// 6
// 8888
// 0001
// 1111
// 2222
// 8888
// 2222
// 输出样例：
// 8888: Minion
// 0001: Chocolate
// 1111: Mystery Award
// 2222: Are you kidding?
// 8888: Checked
// 2222: Are you kidding?


#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int N;
    cin>>N;
    int people[10030]={0};
    int num;
    for(int i=0;i<N;i++)
    {
        scanf("%d",&num);
        if(i==0)
        {
            people[num]=9999;
        }
        else
        {
            int m=i+1;
            if(m==1) people[num]=2;
            if(m%2==0)
            {
                people[num]=1;
                if(m==2) people[num]=2;
            }

            else
            {
                double s=sqrt(m);
                int j;
                for(j=3;j<=s;j+=2)
                {
                    if(m%j==0) break;
                }
                if(j*j>m)
                {
                    people[num]=2;
                }
                else
                {
                    people[num]=1;
                }
            }
        }

    }
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        scanf("%d",&num);
        switch(people[num])
        {
            case 9999:printf("%04d: Mystery Award\n",num);people[num]=3;break;
            case 3:printf("%04d: Checked\n",num);break;
            case 2:printf("%04d: Minion\n",num);people[num]++;break;
            case 1:printf("%04d: Chocolate\n",num);people[num]=3;break;
            case 0:printf("%04d: Are you kidding?\n",num);break;
        }
    }
}
