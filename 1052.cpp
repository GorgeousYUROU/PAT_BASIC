//1052. 卖个萌 (20)
//
//萌萌哒表情符号通常由“手”、“眼”、“口”三个主要部分组成。简单起见，我们假设一个表情符号是按下列格式输出的：
//
//[左手]([左眼][口][右眼])[右手]
//现给出可选用的符号集合，请你按用户的要求输出表情。
//
//输入格式：
//
//输入首先在前三行顺序对应给出手、眼、口的可选符号集。每个符号括在一对方括号[]内。题目保证每个集合都至少有一个符号，并不超过10个符号；每个符号包含1到4个非空字符。
//
//之后一行给出一个正整数K，为用户请求的个数。随后K行，每行给出一个用户的符号选择，顺序为左手、左眼、口、右眼、右手——这里只给出符号在相应集合中的序号（从1开始），数字间以空格分隔。
//
//输出格式：
//
//对每个用户请求，在一行中输出生成的表情。若用户选择的序号不存在，则输出“Are you kidding me? @\/@”。
//
//输入样例：
//[╮][╭][o][~\][/~]  [<][>]
// [╯][╰][^][-][=][>][<][@][⊙]
//[Д][▽][_][ε][^]  ...
//4
//1 1 2 2 2
//6 8 1 5 5
//3 3 4 3 3
//2 10 3 9 3
//输出样例：
//╮(╯▽╰)╭
//<(@Д=)/~
//o(^ε^)o
//Are you kidding me? @\/@
#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
char hand[10][5];
char eye[10][5];
char mouse[10][5];
char c;
int count=-1,s1=0,s2=0,s3=0;
for(int i=0;i<3;i++)
{
    int j=0;
    while((c=getchar())!='\n')
    {
        if(c=='[')
        {

           count=0;continue;
        }
        if(c==']')
        {
       if(count==0) {count=-1;continue;}
       if(i==0) {s1++;hand[j][count]='\0';}
       if(i==1) {s2++;eye[j][count]='\0';}
       if(i==2) {s3++;mouse[j][count]='\0';}
       j++;
       count=-1;
       continue;
        }
        if(count!=-1)
        {
       if(i==0) hand[j][count++]=c;
       if(i==1) eye[j][count++]=c;
       if(i==2) mouse[j][count++]=c;
        }
    }
}

int N,lh,le,m,re,rh;
cin>>N;
for(int i=0;i<N;i++)
{
scanf("%d%d%d%d%d",&lh,&le,&m,&re,&rh);
if(lh<=0 || le<=0 || m<=0 || re<=0 || rh<=0) {printf("Are you kidding me? @\\/@\n");continue;}
if(lh>s1 || le>s2 || m>s3 || re>s2 || rh>s1) {printf("Are you kidding me? @\\/@\n");continue;}
printf("%s",hand[lh-1]);
printf("(%s",eye[le-1]);
printf("%s",mouse[m-1]);
printf("%s)",eye[re-1]);
printf("%s",hand[rh-1]);
printf("\n");
}

}
