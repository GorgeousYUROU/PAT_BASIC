//1028. 人口普查(20)
//某城镇进行人口普查，得到了全体居民的生日。现请你写个程序，找出镇上最年长和最年轻的人。
//
//这里确保每个输入的日期都是合法的，但不一定是合理的——假设已知镇上没有超过200岁的老人，而今天是2014年9月6日，所以超过200岁的生日和未出生的生日都是不合理的，应该被过滤掉。
//
//输入格式：
//
//输入在第一行给出正整数N，取值在(0, 105]；随后N行，每行给出1个人的姓名（由不超过5个英文字母组成的字符串）、以及按“yyyy/mm/dd”（即年/月/日）格式给出的生日。题目保证最年长和最年轻的人没有并列。
//
//输出格式：
//
//在一行中顺序输出有效生日的个数、最年长人和最年轻人的姓名，其间以空格分隔。
//
//输入样例：
//5
//John 2001/05/12
//Tom 1814/09/06
//Ann 2121/01/30
//James 1814/09/05
//Steve 1967/11/20
//输出样例：
//3 Tom John

//可能存在没有有效人数
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    int n;
    scanf("%d",&n);
    char name[n][6],birth[11];
    char minB[11]={'2','0','1','4','/','0','9','/','0','6'};
    char maxB[11]={'1','8','1','4','/','0','9','/','0','6'};
    char current[11]={'2','0','1','4','/','0','9','/','0','6'};
    char out[11]={'1','8','1','4','/','0','9','/','0','6'};
    int count=0,max,min;
    for(int i=0;i<n;i++)
    {
        scanf("%s%s",&name[i],&birth);
        if((strcmp(current,birth)>=0)&&(strcmp(out,birth)<=0))
        {
            if(strcmp(minB,birth)>=0) {strcpy(minB,birth);min=i;}
            if(strcmp(maxB,birth)<=0) {strcpy(maxB,birth);max=i;}
            count++;
        }
    }
    if(count!=0)
    cout<<count<<" "<<name[min]<<" "<<name[max];
    else cout<<count;

}
