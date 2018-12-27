// 1035. 插入与归并(25)

// 根据维基百科的定义：

// 插入排序是迭代算法，逐一获得输入数据，逐步产生有序的输出序列。每步迭代中，算法从输入序列中取出一元素，将之插入有序序列中正确的位置。如此迭代直到全部元素有序。

// 归并排序进行如下迭代操作：首先将原始序列看成N个只包含1个元素的有序子序列，然后每次迭代归并两个相邻的有序子序列，直到最后只剩下1个有序的序列。

// 现给定原始序列和由某排序算法产生的中间序列，请你判断该算法究竟是哪种排序算法？

// 输入格式：

// 输入在第一行给出正整数N (<=100)；随后一行给出原始序列的N个整数；最后一行给出由某排序算法产生的中间序列。这里假设排序的目标序列是升序。数字间以空格分隔。

// 输出格式：

// 首先在第1行中输出“Insertion Sort”表示插入排序、或“Merge Sort”表示归并排序；然后在第2行中输出用该排序算法再迭代一轮的结果序列。题目保证每组测试的结果是唯一的。数字间以空格分隔，且行末不得有多余空格。
// 输入样例1：
// 10
// 3 1 2 8 7 5 9 4 6 0
// 1 2 3 7 8 5 9 4 6 0
// 输出样例1：
// Insertion Sort
// 1 2 3 5 7 8 9 4 6 0
// 输入样例2：
// 10
// 3 1 2 8 7 5 9 4 0 6
// 1 3 2 8 5 7 4 9 0 6
// 输出样例2：
// Merge Sort
// 1 2 3 8 4 5 7 9 0 6

#include<iostream>
using namespace std;
int sum=0;
void merge(int arr[],int low,int mid,int high)//递归和非递归均一样
{//将两个有序区归并为一个有序区
    int i=low,j=mid+1,k=0;
    int *temp=new(nothrow) int[high-low+1];
    while(i<=mid&&j<=high)
    {
        if(arr[i]<=arr[j])
            temp[k++]=arr[i++];
        else
            temp[k++]=arr[j++];
    }
    while(i<=mid) temp[k++]=arr[i++];
    while(j<=high) temp[k++]=arr[j++];
    for(i=low,k=0;i<=high;i++,k++)
        arr[i]=temp[k];
    delete []temp;
}

void print(int a[],int n)
{
    for(int i=0;i<n-1;i++) cout<<a[i]<<" ";
    cout<<a[n-1]<<endl;
}

//非递归算法
void non_mergesort(int a[],int i,int j,int b[])
{
    //总共m层 归并操作 log(j-i)=m
    int k,n=i,m,flag=0;
    for(m=1;m<=(j-i)+1;m*=2)
    {
        n=i;
        //if(m*2<=j) cout<<"我是把数组分成每"<<m*2<<"归并"<<endl;
        //else cout<<"归并所有"<<endl;
        while(n<=j)
        {
            if(n+m*2-1<=j)
            {
            merge(a,n,n+m-1,n+m*2-1);
            //cout<<"归并序号为"<<n<<" ~ "<<n+m*2-1<<endl;
            }
            else if((j-n+1)<m*2 && (j-n+1)>=m)  /*剩余个数为j-n  最后剩余(m,2m)的个数需要sort*/
            {
                merge(a,n,n+m-1,j);
                //cout<<"划分后不足"<<2*m<<" ";
               // cout<<"归并序号为"<<n<<" ~ "<<j<<endl;
            }
            n=n+m*2;
        }
        //cout<<"每轮结果是：";
        int k;
        if(flag==1) {print(a,j+1);return ;}
        for(k=i;k<=j;k++)
	{

      if(a[k]!=b[k])  break;

	}

    if(k>j) flag=1;
    }
}



int main()
{
    /*input*/
    int n;
    cin>>n;
    int origin[n],sort[n];
    for(int i=0;i<n;i++) cin>>origin[i];
    for(int i=0;i<n;i++) cin>>sort[i];
    /* judge isInsertSort*/
    /*找到第一个无序，并比较后面无序序列与原数是否相同*/
    int i;
    for(i=0;(i<n-1)&&(sort[i]<=sort[i+1]) ;i++);
    int j;
    for(j=i+1;(j<n)&&(origin[j]==sort[j]) ;j++);
    if(j==n) {
        cout<<"Insertion Sort"<<endl;
        //把无序的第一个ai插入有序列
        int m=i;
        while(m>=0 && sort[m]>origin[i+1])
        {
            sort[m+1]=sort[m];
            m--;
        }
        sort[m+1]=origin[i+1];//此处sort[m]已改变
        print(sort,n);
        }
    else{
         cout<<"Merge Sort"<<endl;
         non_mergesort(origin,0,n-1,sort);
    }
	 //judge isMergeSort


}
