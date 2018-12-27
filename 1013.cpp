//1013. 数素数 (20)
//
//令Pi表示第i个素数。现任给两个正整数M <= N <= 104，请输出PM到PN的所有素数。
//
//输入格式：
//
//输入在一行中给出M和N，其间以空格分隔。
//
//输出格式：
//
//输出从PM到PN的所有素数，每10个数字占1行，其间以空格分隔，但行末不得有多余空格。
//输入样例：
//
//5 27
//
//输出样例：
//
//11 13 17 19 23 29 31 37 41 43
//47 53 59 61 67 71 73 79 83 89
//97 101 103

#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n,m,count=1;
    cin>>n>>m;
    if(m==1)
    {
        cout<<"2";return 0;
    }
    if(n==1) cout<<"2 ";
    for(int i=3;i!=0;i+=2)
    {
      int s=sqrt(i);
      int j;
      for(j=2;j<=s;j++)
      {
          if(i%j==0) break;
      }
      if(j>s)
      {
          count++;
          if(count>=n&&count<=m)
          {
              cout<<i;
              if((count-n+1)%10==0)
              cout<<endl;
              else
              {
                  if(count!=m) cout<<" ";
              }
          }
      }
      if(count==m) break;
    }
}
