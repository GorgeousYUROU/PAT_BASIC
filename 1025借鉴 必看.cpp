//1025. 反转链表 (25)
//
//给定一个常数K以及一个单链表L，请编写程序将L中每K个结点反转。例如：给定L为1→2→3→4→5→6，K为3，则输出应该为3→2→1→6→5→4；如果K为4，则输出应该为4→3→2→1→5→6，即最后不到K个元素不反转。
//
//输入格式：
//
//每个输入包含1个测试用例。每个测试用例第1行给出第1个结点的地址、结点总个数正整数N(<= 105)、以及正整数K(<=N)，即要求反转的子链结点的个数。结点的地址是5位非负整数，NULL地址用-1表示。
//
//接下来有N行，每行格式为：
//
//Address Data Next
//
//其中Address是结点地址，Data是该结点保存的整数数据，Next是下一结点的地址。
//
//输出格式：
//
//对每个测试用例，顺序输出反转后的链表，其上每个结点占一行，格式与输入相同。
//
//输入样例：
//00100 6 4
//00000 4 99999
//00100 1 12309
//68237 6 -1
//33218 3 00000
//99999 5 68237
//12309 2 33218
//输出样例：
//00000 4 33218
//33218 3 12309
//12309 2 00100
//00100 1 99999
//99999 5 68237
//68237 6 -1

//包含不能形成链表的节点
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iterator>
#include<utility>
using namespace std;
typedef pair<int,int> P;
vector<P> col(100000);
struct node
{
    int address;
    int content;
    int next;
    node(int a,int b,int c):address(a),content(b),next(c){};
};
vector<node> vec;
int main()
{
#ifdef ONLINE_JUDGE
#else
freopen("E:\\in.txt","r",stdin);
freopen("E:\\out.txt","w",stdout);
#endif
    int first,n,k;
    int address,data,next;
    while(scanf("%d%d%d",&first,&n,&k)!=EOF)
    {
        while(n--)
        {

           scanf("%d%d%d",&address,&data,&next);
            P p;
            p.first = data;
            p.second = next;
            col[address] = p;
        }
        int r=first;
        int cnt=0;
        while(r!=-1)
        {
            cnt++;
            vec.push_back(node(r,col[r].first,col[r].second));
            r=col[r].second;
        }
        int t=cnt/k;//需要对t次k个变量翻转
        for(int i=0;i<t;i++)
        {
            std::reverse(vec.begin()+i*k,vec.begin()+(i+1)*k);
        }

        for(int i=0;i<vec.size()-1;i++)
        {
            printf("%05d %d %05d\n",vec[i].address,vec[i].content,vec[i+1].address);//此处为vec[i+1].address
        }
        printf("%05d %d %d\n",vec[vec.size()-1].address,vec[vec.size()-1].content,-1);
    }
    return 0;
}
