// 题目内容：

// 有兩個序列 S1 和 S2，各有 N 個元素。當我們在 S1,S2 各取一個數字時，總共會有 N*N 這麼多可能的” 和”(sum)。請找出這 N*N 這麼多和裡最小的 N 個值，並將它們加總後輸出。

// 输入格式:
// 只有一筆測資。
	// 測試資料第一行為一個正整數 N。
	// 第二行有 N 個數字，以空白隔開，代表序列 S1。
	// 第二行有 N 個數字，以空白隔開，代表序列 S2。
 // 數字範圍：
// 0 < N < 10000
// 输出格式：

// 輸出一行，N 個最小的可能的和的加總。
// 输入样例：
// 5
// 1 3 5 7 9
// 2 4 6 8 10
// 输出样例：

// 27

#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
void HeapAdjust(int a[],int size,int i)
{
    int max;
    //只调整非叶子结点
     if(i<=size/2)
     {
         int left=i*2,right=i*2+1;
         if(a[left-1]>a[i-1]) max=left;
         else max=i;
         if(a[right-1]>a[i-1]) max=right;
         if(max!=i)
         {
             swap(a[max-1],a[i-1]);
             HeapAdjust(a,size,max);
         }
     }
}
void insert(int a[],int i)
{
    int parent=i/2;
    while(parent>=1)
    {
        if(a[i-1]>a[parent-1]) {swap(a[i-1],a[parent-1]);i=parent;}
        parent=parent/2;
    }
}
int main()
{
    /*input*/
    int n;
    scanf("%d",&n);
    int a[2*n];
    int sum[n];
    scanf("%d",&a[0]);
    int temp;
    for(int i=1;i<n*2;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    sort(a+n,a+2*n);
    /*create N heap*/
    if(a[0]>a[n])
       for(int i=0;i<n;i++) {sum[i]=a[i]+a[n];insert(sum,i+1);}
    else
    {
       for(int i=0;i<n;i++)
       {sum[i]=a[i+n]+a[0];
       insert(sum,i+1);}
    }

    if(a[0]>a[n])
       for(int i=0;i<n;i++)
       {
           int j;
           for(j=n+1;j<2*n;j++)
           {
               temp=a[i]+a[j];
               if(a[i]>sum[0] || a[j]>sum[0]) break;
               //如果比当前堆的最大值小调整
               if(temp<sum[0]) {sum[0]=temp;HeapAdjust(a,n,1);}
               //后面已经没有可调整的和
               if(temp>sum[0]) break;
           }
           if(j<n) break;
       }
    else
    for(int i=1;i<n;i++)
       {
           int j;
           for(j=n;j<2*n;j++)
           {
               temp=a[i]+a[j];
               if(a[i]>sum[0] || a[j]>sum[0]) break;
               //如果比当前堆的最大值小调整
               if(temp<sum[0]) {sum[0]=temp;HeapAdjust(a,n,1);}
               //后面已经没有可调整的和
               if(temp>sum[0]) break;
           }
           if(j<n) break;
       }



    /*output*/
    temp=0;
    for(int i=0;i<n;i++) {temp+=sum[i];}
    printf("%d",temp);

}


