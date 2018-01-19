// 1002. 写出这个数 (20)

// 读入一个自然数n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

// 输入格式：每个测试输入包含1个测试用例，即给出自然数n的值。这里保证n小于10100。

// 输出格式：在一行内输出n的各位数字之和的每一位，拼音数字间有1 空格，但一行中最后一个拼音数字后没有空格。

// 输入样例：
// 1234567890987654321123456789
// 输出样例：
// yi san wu
//大数要用字符串
#include <iostream>

using namespace std;

int main()
{
    char n[101];
    cin>>n;
    int sum=0,a[3]={-1,-1,-1},i=0,r;
    for(int i=0;n[i]!='\0';i++)
    {
        sum+=int(n[i])-48;
    }
    int m=sum;//防止出现900
    if(m>100) {r=sum/100;a[2]=r;sum=sum-r*100;}
    if(m>10) {r=sum/10;a[1]=r;sum=sum-r*10;}
    a[0]=sum;
    for(i=2;i>=0;i--)
    {
        if(a[i]!=-1)
        {
           switch(a[i])
        {
            case 1:cout<<"yi";break;
            case 2:cout<<"er";break;
            case 3:cout<<"san";break;
            case 4:cout<<"si";break;
            case 5:cout<<"wu";break;
            case 6:cout<<"liu";break;
            case 7:cout<<"qi";break;
            case 8:cout<<"ba";break;
            case 9:cout<<"jiu";break;
            case 0:cout<<"ling";break;
        }
        if(i!=0) cout<<' ';
        }
    }
return 0;
}