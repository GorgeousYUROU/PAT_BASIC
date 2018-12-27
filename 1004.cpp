//1004. 成绩排名 (20)
//
//读入n名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。
//
//输入格式：每个测试输入包含1个测试用例，格式为
//
//  第1行：正整数n
//  第2行：第1个学生的姓名 学号 成绩
//  第3行：第2个学生的姓名 学号 成绩
//  ... ... ...
//  第n+1行：第n个学生的姓名 学号 成绩
//其中姓名和学号均为不超过10个字符的字符串，成绩为0到100之间的一个整数，这里保证在一组测试用例中没有两个学生的成绩是相同的。
//输出格式：对每个测试用例输出2行，第1行是成绩最高学生的姓名和学号，第2行是成绩最低学生的姓名和学号，字符串间有1空格。
//
//输入样例：
//3
//Joe Math990112 89
//Mike CS991301 100
//Mary EE990830 95
//输出样例：
//Mike CS991301
//Joe Math990112
//该题使用了快速排序，略显麻烦
#include<iostream>
using namespace std;
int partion(int i,int j,int* a,int *b)
{
    int key=a[j];
    int n=i-1;
    int temp;
    for(int m=i;m<=j-1;m++)
    {
        if(a[m]<key)
        {
            n++;
            temp=a[n];
            a[n]=a[m];
            a[m]=temp;
            temp=b[n];
            b[n]=b[m];
            b[m]=temp;
        }
    }
    temp=a[n+1];
    a[n+1]=key;
    a[j]=temp;
     temp=b[n+1];
    b[n+1]=b[j];
    b[j]=temp;
    return n+1;
}
void quicksort(int i,int j,int* a,int *b)
{
    if(i<=j)
    {
    int k=partion(i,j,a,b);
    quicksort(i,k-1,a,b);
    quicksort(k+1,j,a,b);
    }
}
struct stu{
char name[11];
char num[11];
int grade;
};
int main()
{
int n;
cin>>n;
int a[n],b[n];
struct stu student[n];
for(int i=0;i<n;i++)
{
    cin>>student[i].name;
    cin>>student[i].num;
    cin>>student[i].grade;
    a[i]=student[i].grade;
    b[i]=i;
}
quicksort(0,n-1,a,b);
cout<<student[b[n-1]].name<<" "<<student[b[n-1]].num<<endl;
cout<<student[b[0]].name<<" "<<student[b[0]].num;
}
