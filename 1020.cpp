//1020. 月饼 (25)
//
//月饼是中国人在中秋佳节时吃的一种传统食品，不同地区有许多不同风味的月饼。现给定所有种类月饼的库存量、总售价、以及市场的最大需求量，请你计算可以获得的最大收益是多少。
//
//注意：销售时允许取出一部分库存。样例给出的情形是这样的：假如我们有3种月饼，其库存量分别为18、15、10万吨，总售价分别为75、72、45亿元。如果市场的最大需求量只有20万吨，那么我们最大收益策略应该是卖出全部15万吨第2种月饼、以及5万吨第3种月饼，获得 72 + 45/2 = 94.5（亿元）。
//
//输入格式：
//
//每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N表示月饼的种类数、以及不超过500（以万吨为单位）的正整数D表示市场最大需求量。随后一行给出N个正数表示每种月饼的库存量（以万吨为单位）；最后一行给出N个正数表示每种月饼的总售价（以亿元为单位）。数字间以空格分隔。
//
//输出格式：
//
//对每组测试用例，在一行中输出最大收益，以亿元为单位并精确到小数点后2位。
//
//输入样例：
//3 20
//18 15 10
//75 72 45
//输出样例：
//94.50
#include<stdio.h>
#include<iostream>
using namespace std;
int partion(int i,int j,float price[],int b[],float count[])
{
    int m=b[j];
    double key=price[m];
    int n=i-1;
    for(int k=i;k<j;k++)
    {
        int m1=b[k];
        if(price[m1]>key)
        {
            n++;
            int temp=b[k];
            b[k]=b[n];
            b[n]=temp;
        }
        if(price[m1]==key)
        {
            if(count[m1]>count[m])
            {
            n++;
            int temp=b[k];
            b[k]=b[n];
            b[n]=temp;
            }
        }
    }
    int temp=b[n+1];
    b[n+1]=m;
    b[j]=temp;
    return n+1;

}

void quicksort(int i,int j,float price[],int b[],float count[])
{
    if(i<=j)
    {
        int k=partion(i,j,price,b,count);
        quicksort(i,k-1,price,b,count);
         quicksort(k+1,j,price,b,count);
    }
}
int main()
{
    int type;
    float need;
    cin>>type>>need;
    float count[type],profit[type];
    float price[type];
    int b[type];
    for(int i=0;i<type;i++) scanf("%f",&count[i]);
    for(int i=0;i<type;i++)
    {
        scanf("%f",&profit[i]);
        price[i]=profit[i]/count[i];
        b[i]=i;
    }
quicksort(0,type-1,price,b,count);
float sum=0;
float sumprice=0;
for(int i=0;i<type;i++)
{
   int m=b[i];
   sum+=count[m];
   if(sum<need) sumprice+=profit[m];
   if(sum>=need)
   {
       sumprice+=(need-sum+count[m])*price[m];
       printf("%.2f",sumprice);
      return 0;
   }
}
printf("%.2f",sumprice);//需求量大于所有库存
}
