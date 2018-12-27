// 1014. 福尔摩斯的约会 (20)

// 大侦探福尔摩斯接到一张奇怪的字条：“我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm”。大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间“星期四 14:04”，因为前面两字符串中第1对相同的大写英文字母（大小写有区分）是第4个字母'D'，代表星期四；第2对相同的字符是'E'，那是第5个英文字母，代表一天里的第14个钟头（于是一天的0点到23点由数字0到9、以及大写字母A到N表示）；后面两字符串第1对相同的英文字母's'出现在第4个位置（从0开始计数）上，代表第4分钟。现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。

// 输入格式：

// 输入在4行中分别给出4个非空、不包含空格、且长度不超过60的字符串。

// 输出格式：

// 在一行中输出约会的时间，格式为“DAY HH:MM”，其中“DAY”是某星期的3字符缩写，即MON表示星期一，TUE表示星期二，WED表示星期三，THU表示星期四，FRI表示星期五，SAT表示星期六，SUN表示星期日。题目输入保证每个测试存在唯一解。

// 输入样例：
// 3485djDkxh4hhGE 
// 2984akDfkkkkggEdsb 
// s&hgsfdk 
// d&Hyscvnm
// 输出样例：
// THU 14:04
#include<iostream>
using namespace std;
int main()
{
    char a[4][62];
    char* day[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
    int count=0,flag=1,min;
    for(int i=0;i<4;i++)
    {
        cin>>a[i];
    }
    int i=0;
    for(i=0;i!=-1;i++)
    {
        if(a[0][i]=='\0') break;
        if(a[1][i]=='\0') break;
        if(a[2][i]=='\0') break;
        if(a[3][i]=='\0') break;
        if((a[0][i]==a[1][i])&&(count<2))
        {
            if('A'<=a[0][i]&&a[0][i]<='N'&&(count==1))
            {cout<<a[0][i]-'A'+10<<":";count++;}
            if('0'<=a[0][i]&&a[0][i]<='9'&&(count==1))
            {cout<<"0"<<a[0][i]-'0'<<":";count++;}
            if('A'<=a[0][i]&&a[0][i]<='G'&&(count==0))
            {cout<<day[a[0][i]-'A']<<" ";count++;}
        }
        if((a[2][i]==a[3][i])&&(flag==1))
        {
           if(('a'<=a[2][i]&&a[3][i]<='z')||('A'<=a[2][i]&&a[3][i]<='Z'))
           {
           min=i;
           flag=0;
           }
        }
        if((count==2)&&(flag==0)) break;
    }
    if(count<2)
    {
        for(int j=i;j!=-1;j++)
        {
        if(a[0][j]=='\0') break;
        if(a[1][j]=='\0') break;
        if(a[0][j]==a[1][j])
        {
            if('A'<=a[0][j]&&a[0][j]<='N'&&(count==1))
            {cout<<a[0][j]-'A'+10<<":";count++;continue;}
            if('0'<=a[0][j]&&a[0][j]<='9'&&(count==1))
            {cout<<"0"<<a[0][j]-'0'<<":";count++;continue;}
            if('A'<=a[0][j]&&a[0][j]<='G'&&(count==0))
            {cout<<day[a[0][j]-'A']<<" ";count++;continue;}

        }
        if(count==2) break;
        }
    }
    if(flag)
    {
        for(int j=i;j!=-1;j++)
        {
        if(a[2][j]=='\0') break;
        if(a[3][j]=='\0') break;
        if((a[2][j]==a[3][j])&&(flag==1))
        {
            if(('a'<=a[2][j]&&a[3][j]<='z')||('A'<=a[2][j]&&a[3][j]<='Z'))
           {
           min=j;
           flag=0;
           continue;
           }
        }
        if(flag==0) break;
        }
    }
    if(count==2)
        {
        if(min<10) cout<<"0"<<min;
           else cout<<min;
        }
    return 0;
}