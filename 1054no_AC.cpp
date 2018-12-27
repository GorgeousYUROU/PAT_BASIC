1054. 求平均值 (20)
本题的基本要求非常简单：给定N个实数，计算它们的平均值。但复杂的是有些输入数据可能是非法的。一个“合法”的输入是[-1000，1000]区间内的实数，并且最多精确到小数点后2位。当你计算平均值的时候，不能把那些非法的数据算在内。

输入格式：

输入第一行给出正整数N（<=100）。随后一行给出N个实数，数字间以一个空格分隔。

输出格式：

对每个非法输入，在一行中输出“ERROR: X is not a legal number”，其中X是输入。最后在一行中输出结果：“The average of K numbers is Y”，其中K是合法输入的个数，Y是它们的平均值，精确到小数点后2位。如果平均值无法计算，则用“Undefined”替换Y。如果K为1，则输出“The average of 1 number is Y”。

输入样例1：
7
5 -3.2 aaa 9999 2.3.4 7.123 2.35
输出样例1：
ERROR: aaa is not a legal number
ERROR: 9999 is not a legal number
ERROR: 2.3.4 is not a legal number
ERROR: 7.123 is not a legal number
The average of 3 numbers is 1.38
输入样例2：
2
aaa -9999
输出样例2：
ERROR: aaa is not a legal number
ERROR: -9999 is not a legal number
The average of 0 numbers is Undefined

#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int main()
{
    int N;
    cin>>N;
    double sum=0,num=0;
    char c;
    int flag=1,count=0,figure=-1;
    string str="";
    getchar();
    for(int i=0;i<N;i++)
    {
            num=0;
            str="";
            figure=-1;
            flag=1;
            c=getchar();
            str+=c;
            if(c=='-') {flag=-1;c=getchar();str+=c;}

            if('0'<=c && c<='9')
            {
                num=num*10+c-'0';
                while((c=getchar())!=' ' && (c!='\n'))
                {
                     str+=c;
                     if('0'<=c&&c<='9')
                     {
                         num=num*10+c-'0';
                         if(figure>-1) figure++;
                     }
                     else
                     {
                         if(c=='.')
                         {
                           figure++;
                           //两个以上'.'
                           if(figure>=1) figure=3;
                         }
                         else
                         {
                             figure=3;
                         }

                     }

                }
                //如果小数位数不符合，或出现非字符
                if(figure>2 ) {printf("ERROR: ");
                    cout<<str;
                     printf(" is not a legal number\n");
                    }
                else
                {
                    if(flag==-1) num=num*-1;
                    if(figure>0) num=(double)num*(pow(0.1,figure));
                    if((-1000<=num) && (num<=1000))
                    {
                        sum+=num;count++;
                    }
                    else
                    {printf("ERROR: ");
                    cout<<str;
                     printf(" is not a legal number\n");
                    }
                }
            }
            else
            {
                    printf("ERROR: ");
                    cout<<str;
                    while((c=getchar())!=' ' && (c!='\n'))
                {
                    printf("%c",c);
                }
                printf(" is not a legal number\n");
            }

    }
    if(count==0)
    {
       printf("The average of 0 numbers is Undefined\n");
    }
    else
    {
        printf("The average of %d numbers is %.2lf\n",count,sum/count);
    }
}
