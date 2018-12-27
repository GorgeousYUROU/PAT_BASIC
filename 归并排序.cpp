#include<iostream>
using namespace std;
int sum=0;
void Merge(int arr[],int low,int mid,int high)//递归和非递归均一样   
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
    for(i=low,k=0;i<=high;i++,k++)  //注意k从0开始
        arr[i]=temp[k];   
    delete []temp;  
}  

//递归算法
void mergeSort(int a[],int i,int j)
{
    if(i<j)
    {
        int k=(i+j)/2;
        mergeSort(a,i,k);
        mergeSort(a,k+1,j);
        merge(a,i,k,j);
    }
}

//非递归算法
void non_mergesort(int a[],int i,int j)
{
    //总共m层 归并操作 log(j-i)=m
    int k,n=i,m;
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
//        for(int k=i;k<=j;k++)
//	{
//
//      cout<<a[k];
//
//	}
//	cout<<endl;

    }
}
int main()
{
int n;cin>>n;

	//int a[10000];
int a[n];
	for(int k=0;k<n;k++)

	{

		cin>>a[k];
	}

	non_mergesort(a,0,n-1);


}
