//1050. 螺旋矩阵(25)
//
//本题要求将给定的N个正整数按非递增的顺序，填入“螺旋矩阵”。所谓“螺旋矩阵”，是指从左上角第1个格子开始，按顺时针螺旋方向填充。要求矩阵的规模为m行n列，满足条件：m*n等于N；m>=n；且m-n取所有可能值中的最小值。
//
//输入格式：
//
//输入在第1行中给出一个正整数N，第2行给出N个待填充的正整数。所有数字不超过104，相邻数字以空格分隔。
//
//输出格式：
//
//输出螺旋矩阵。每行n个数字，共m行。相邻数字以1个空格分隔，行末不得有多余空格。
//
//输入样例：
//12
//37 76 20 98 76 42 53 95 60 81 58 93
//输出样例：
//98 95 93
//42 37 81
//53 20 76
//58 60 76
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
bool comp(int a,int b)
{
    if(a>b) return true;
    else return false;
}
int main()
{
   /*input*/
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++)
   {
      scanf("%d",&a[i]);
   }
   sort(a,a+n,comp);
   double s=sqrt(n);
   int column=(int)(s),row;
   if(s==column) {row=column;}
   else
   {
       for(;column>=1;column--)
       {
           if(n%column==0) break;
       }
       row=n/column;
   }
   int output[row][column];
   int row1=0,row2=row-1,col1=0,col2=column-1;
   for(int i=0;i<n;)
   {
       for(int j=col1;j<=col2;j++) output[row1][j]=a[i++];
       if(i==n) break;
       for(int k=row1+1;k<=row2;k++) output[k][col2]=a[i++];
       if(i==n) break;
       for(int j=col2-1;j>=col1;j--) output[row2][j]=a[i++];
       if(i==n) break;
       for(int k=row2-1;k>=row1+1;k--) output[k][col1]=a[i++];
       if(i==n) break;
       row1++;col1++;col2--;row2--;
   }
   for(int i=0;i<row;i++)
   {
       for(int j=0;j<column-1;j++)
       printf("%d ",output[i][j]);
       printf("%d\n",output[i][column-1]);
   }
}
