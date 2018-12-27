// 1032. 挖掘机技术哪家强(20)
// 为了用事实说明挖掘机技术到底哪家强，PAT组织了一场挖掘机技能大赛。现请你根据比赛结果统计出技术最强的那个学校。

// 输入格式：

// 输入在第1行给出不超过105的正整数N，即参赛人数。随后N行，每行给出一位参赛者的信息和成绩，包括其所代表的学校的编号（从1开始连续编号）、及其比赛成绩（百分制），中间以空格分隔。

// 输出格式：

// 在一行中给出总得分最高的学校的编号、及其总分，中间以空格分隔。题目保证答案唯一，没有并列。

// 输入样例：
// 6
// 3 65
// 2 80
// 1 100
// 2 70
// 3 40
// 3 0
// 输出样例：
//2 150


#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int n;
    double sum[100200]={0};
    cin>>n;
    int school;
    double grade;
    double max=-1;
    int num;
    while(n--)
    {
        scanf("%d%lf",&school,&grade);
        sum[school]+=grade;
        if(sum[school]>max) {max=sum[school];num=school;}
    }
    cout<<num<<" "<<max;
}