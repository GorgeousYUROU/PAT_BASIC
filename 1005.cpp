//1005. 继续(3n+1)猜想 (25)
//
//卡拉兹(Callatz)猜想已经在1001中给出了描述。在这个题目里，情况稍微有些复杂。
//
//当我们验证卡拉兹猜想的时候，为了避免重复计算，可以记录下递推过程中遇到的每一个数。例如对n=3进行验证的时候，我们需要计算3、5、8、4、2、1，则当我们对n=5、8、4、2进行验证的时候，就可以直接判定卡拉兹猜想的真伪，而不需要重复计算，因为这4个数已经在验证3的时候遇到过了，我们称5、8、4、2是被3“覆盖”的数。我们称一个数列中的某个数n为“关键数”，如果n不能被数列中的其他数字所覆盖。
//
//现在给定一系列待验证的数字，我们只需要验证其中的几个关键数，就可以不必再重复验证余下的数字。你的任务就是找出这些关键数字，并按从大到小的顺序输出它们。
//
//输入格式：每个测试输入包含1个测试用例，第1行给出一个正整数K(<100)，第2行给出K个互不相同的待验证的正整数n(1<n<=100)的值，数字间用空格隔开。
//
//输出格式：每个测试用例的输出占一行，按从大到小的顺序输出关键数字。数字间用1个空格隔开，但一行中最后一个数字后没有空格。
//
//输入样例：
//6
//3 5 6 7 8 11
//输出样例：
//7 6
#include<iostream>
using namespace std;
int partion(int i,int j,int a[])
{
    int key=a[j];
    int n=i-1;
    int k,temp;
    for(k=i;k<j;k++)
    {
        if(a[k]<key)
        {
            n++;
            temp=a[n];
            a[n]=a[k];
            a[k]=temp;
        }
    }
    temp=a[n+1];
    a[n+1]=key;
    a[j]=temp;
    return n+1;
}
void quicksort(int i,int j,int a[])
{
    if(i<=j)
    {
        int k=partion(i,j,a);
        quicksort(i,k-1,a);
        quicksort(k+1,j,a);
    }
}
int main()
{
int n;
cin>>n;
int a[n],b[n],key[n],flag[n];
for(int i=0;i<n;i++)
{
    cin>>a[i];
    b[i]=a[i];
    flag[i]=0;
}
int m=0;
for(int i=0;i<n;i++)
{
    while(b[i]!=1)
    {
        if(b[i]%2==0){b[i]=b[i]/2;}
        else{b[i]=(3*b[i]+1)/2;}
        for(int j=0;j<n;j++)
        {
            if(b[i]==a[j]) {flag[j]=1;break;}
        }
    }
}
for(int i=0;i<n;i++)
{
    if(flag[i]==0) key[m++]=a[i];
}
quicksort(0,m-1,key);
for(int i=m-1;i>=1;i--)
{
    cout<<key[i]<<" ";
}
cout<<key[0];
return 0;
}
