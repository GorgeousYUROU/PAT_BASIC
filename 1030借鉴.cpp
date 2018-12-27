#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
int N;
double p;
cin>>N>>p;
double a[N];
for(int i=0;i<N;i++)
scanf("%lf",&a[i]);
sort(a,a+N);
int max=0;
//int i=0;
//int m=N-1;//m表示当前最大值要满足的最大的最小值的索引
//for(int j=N-1;j>=0;j--)//从最大值开始寻找
//{
//   while((i<=m)&&(a[j]>a[i]*p)){i++;}//从最小值开始寻找数量最大的完美数列
//   if(max<j-i+1) max=j-i+1;//max为当前完美数列最大个数
//   if(max>=j+1) break;//如果当前max不能再增加
//   m=j-1-max;//下次循环满足个数的最大最小值的位置
//   i=0;
//}
for(int i=0;i<N;i++)//从最大值开始寻找
{
  for(int j=i+max;j<N;j++)
  {
      if(a[j]>a[i]*p) break;
       if(j-i+1>max)         //如果此次的长度大于上一次，更新数列长度
       max=j-i+1;
  }

}
cout<<max<<endl;
return 0;
} 


