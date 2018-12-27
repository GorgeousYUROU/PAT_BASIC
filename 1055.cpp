//1055. 集体照 (25)
//
//拍集体照时队形很重要，这里对给定的N个人K排的队形设计排队规则如下：
//
//每排人数为N/K（向下取整），多出来的人全部站在最后一排；
//后排所有人的个子都不比前排任何人矮；
//每排中最高者站中间（中间位置为m/2+1，其中m为该排人数，除法向下取整）；
//每排其他人以中间人为轴，按身高非增序，先右后左交替入队站在中间人的两侧（例如5人身高为190、188、186、175、170，则队形为175、188、190、186、170。这里假设你面对拍照者，所以你的左边是中间人的右边）；
//若多人身高相同，则按名字的字典序升序排列。这里保证无重名。
//现给定一组拍照人，请编写程序输出他们的队形。
//
//输入格式：
//
//每个输入包含1个测试用例。每个测试用例第1行给出两个正整数N（<=10000，总人数）和K（<=10，总排数）。随后N行，每行给出一个人的名字（不包含空格、长度不超过8个英文字母）和身高（[30, 300]区间内的整数）。
//
//输出格式：
//
//输出拍照的队形。即K排人名，其间以空格分隔，行末不得有多余空格。注意：假设你面对拍照者，后排的人输出在上方，前排输出在下方。

//总结规律，尽量写成函数，后面不能有空格，可控制除第一个每个前面都有1空格
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
struct student{
int height;
char name[9];
};
bool comp(struct student a,struct student b)
{
    if(a.height<b.height) return true;
    else if(a.height==b.height)
    {
        if((strcmp(a.name,b.name)>0))
        return true;
    }
    return false;
}
int main()
{

int n,k;
cin>>n>>k;
struct student stu[n];
int per=n/k;
int last=n-per*(k-1);
for(int i=0;i<n;i++)
{
    scanf("%s%d",&stu[i].name,&stu[i].height);
}
sort(stu,stu+n,comp);
int mid=last/2;
int j;
for(int i=0;i<last;i++)
{
   if(i!=0) printf(" ");
   if(i<mid)
   {
          j=2*(mid-i)-1;
          printf("%s",stu[n-1-j].name);
   }
   else
   {
        if(i==mid) {printf("%s",stu[n-1].name);continue;}
        j=2*(i-mid);
        printf("%s",stu[n-1-j].name);

   }

}
printf("\n");
mid=per/2;
n=n-last-1;
for(int i=1;i<k;i++)
{
    for(int m=0;m<per;m++)
    {
        if(m!=0) printf(" ");
       if(m<mid)
   {
          j=2*(mid-m)-1;
          printf("%s",stu[n-j].name);
   }
   else
   {
        if(m==mid) {printf("%s",stu[n].name);continue;}
        j=2*(m-mid);
        printf("%s",stu[n-j].name);

   }

    }
   printf("\n");
    n=n-per;

}
}
