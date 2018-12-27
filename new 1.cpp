题目内容：
实作Joseph problem.
假设一开始有N个人，编号1~N，
按照顺序以顺时针围成一个圆圈。
游戏开始时，编号1的人拿刀。
之后每一轮刀子会被往下传M个人，
而当轮最后拿到刀子的人会将他的下一个人杀掉，
杀完后刀子会再传给被杀的下一个人。
这样一轮就算结束。
游戏会进行许多轮，直到只剩下最后一个人。


范例1：N=5, M=2
第一轮：刀子传给3号，4号被杀，刀子再传给5号 (1 2 3 5)
第二轮：刀子传给2号，3号被杀，刀子再传给5号 (1 2 5)
第三轮：刀子传给2号，5号被杀，刀子再传给1号 (1 2)
第四轮：刀子传给1号，2号被杀，最后1号存活。
范例2：N=4, M=3
第一轮：刀子传给4号，1号被杀，刀子再传给2号 (2 3 4)
第二轮：刀子传给2号，3号被杀，刀子再传给4号 (2 4)
第三轮：刀子传给2号，4号被杀，最后2号存活。


输入格式:
输入第一行为一个数字T，代表测资的笔数。
接下来会有T笔测资，每一笔测资一行，
会有两个数字N,M，数字间以空格区隔。
数字范围：
T < 1000
0 < N <= 1000
0 < M <= 1000


输出格式：
输出一行数字，将每笔测资最后存活下来的人的编号加总。
输入样例：
3
5 2
4 3
8 4
输出样例：
4

/*循环链表法*/
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct node{
    int x;
    struct node *next;
}Node;

struct node* a[2000];

void kill(int n,int m)
{
    a[n-1]=(Node *)malloc(sizeof(Node));
    a[n-1]->x=n;
    for(int i=n-2;i>=0;i--)
    {
      a[i]=(Node *)malloc(sizeof(Node));
      a[i]->x=i+1;
      a[i]->next=a[i+1];
    }
    a[n-1]->x=n;
    a[n-1]->next=a[0];
    int killer=1;
    Node* d;
    int count=0;
    for(int i=0;i<n-1;i++)
    {
        d=a[killer-1];
        count=0;
        while(count++<m)
        {
            d=d->next;
        }
        d->next=d->next->next;
        killer=d->next->x;
    }
    cout<<killer<<endl;
}
int main()
{
    int N;
    cin>>N;
    int n,m;
    while(N--)
    {

        cin>>n>>m;
        kill(n,m);
    }
}

//递归解法
#include <stdio.h>

int main() {
    int N, M, T, sum = 0;
    int i, s;

    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &N, &M);
        s = 0;
        for(i = 2; i <= N; i ++){
            s = (s + M + 2) % i; //因为题目中要求是从当前位置的M个位置的下一个人出列，所以这里要加2
            //http://blog.csdn.net/lecepin/article/details/50752025
        }
        sum += s+1;
    }


    printf ("%d", sum);


    return 0;
}
