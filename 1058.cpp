//1058. 选择题(20)
//
//批改多选题是比较麻烦的事情，本题就请你写个程序帮助老师批改多选题，并且指出哪道题错的人最多。
//
//输入格式：
//
//输入在第一行给出两个正整数N（<=1000）和M（<=100），分别是学生人数和多选题的个数。随后M行，每行顺次给出一道题的满分值（不超过5的正整数）、选项个数（不少于2且不超过5的正整数）、正确选项个数（不超过选项个数的正整数）、所有正确选项。注意每题的选项从小写英文字母a开始顺次排列。各项间以1个空格分隔。最后N行，每行给出一个学生的答题情况，其每题答案格式为“(选中的选项个数 选项1 ……)”，按题目顺序给出。注意：题目保证学生的答题情况是合法的，即不存在选中的选项数超过实际选项数的情况。
//
//输出格式：
//
//按照输入的顺序给出每个学生的得分，每个分数占一行。注意判题时只有选择全部正确才能得到该题的分数。最后一行输出错得最多的题目的错误次数和编号（题目按照输入的顺序从1开始编号）。如果有并列，则按编号递增顺序输出。数字间用空格分隔，行首尾不得有多余空格。如果所有题目都没有人错，则在最后一行输出“Too simple”。
//
//输入样例：
//3 4 
//3 4 2 a c
//2 5 1 b
//5 3 2 b c
//1 5 4 a b d e
//(2 a c) (2 b d) (2 a c) (3 a b e)
//(2 a c) (1 b) (2 a b) (4 a b d e)
//(2 b d) (1 e) (2 b c) (4 a b c d)
//输出样例：
//3
//6
//5
//2 2 3 4

#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
struct item{
int order;
int score;
int total;
int right;
char c[120];
int wrong;
};
bool comp(struct item a,struct item b)
{
    if(a.wrong>b.wrong) return true;
    else
    {
        if(a.wrong==b.wrong)
        {
            if(a.order<b.order) return true;
        }
    }
    return false;
}
int main()
{
    int M,N;
    cin>>M>>N;
    struct item items[120];

    for(int i=0;i<N;i++)
    {
       scanf("%d%d%d",&items[i].score,&items[i].total,&items[i].right);
       getchar();
       int j=0;
       items[i].order=i+1;
       items[i].wrong=0;
       while((items[i].c[j++]=getchar())!='\n'){}
       items[i].c[j-1]='\0';
    }
    int answer=-1;
    char temp[120];
    int grade=0;
    for(int i=0;i<M;)
    {

       getchar();
       int op;
       scanf("%d",&op);
       answer++;
       getchar();
       int j=0;
       while((temp[j++]=getchar())!=')'){}
       temp[j-1]='\0';
       if(strncmp(temp,items[answer].c,op+op-1)==0)
       {
           grade+=items[answer].score;
       }
       else{items[answer].wrong++;}
       if(getchar()=='\n') {i++;printf("%d\n",grade);answer=-1;grade=0;}
    }
    sort(items,items+N,comp);
    if(items[0].wrong==0) printf("Too simple\n");
    else
    {
        printf("%d ",items[0].wrong);
        int i=0;
        printf("%d",items[i].order);
        i++;
        while(items[0].wrong==items[i].wrong)
        {
            printf(" %d",items[i].order);
            i++;
        }
    }
    return 0;

}
