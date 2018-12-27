//1011. A+B和C (15)
//
//给定区间[-231, 231]内的3个整数A、B和C，请判断A+B是否大于C。
//
//输入格式：
//
//输入第1行给出正整数T(<=10)，是测试用例的个数。随后给出T组测试用例，每组占一行，顺序给出A、B和C。整数间以空格分隔。
//
//输出格式：
//
//对每组测试用例，在一行中输出“Case #X: true”如果A+B>C，否则输出“Case #X: false”，其中X是测试用例的编号（从1开始）
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long a,b,c;
    for(int i=0;i<n;i++)
    {
      cin>>a>>b>>c;
      if(a+b>c)
    cout<<"Case #"<<i+1<<": true"<<endl;
    else
    cout<<"Case #"<<i+1<<": false"<<endl;
    }

    return 0;
}

