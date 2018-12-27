//1018. 锤子剪刀布 (20)
//
//大家应该都会玩“锤子剪刀布”的游戏：两人同时给出手势，胜负规则如图所示：
//
//
//现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。
//
//输入格式：
//
//输入第1行给出正整数N（<=105），即双方交锋的次数。随后N行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。C代表“锤子”、J代表“剪刀”、B代表“布”，第1个字母代表甲方，第2个代表乙方，中间有1个空格。
//
//输出格式：
//
//输出第1、2行分别给出甲、乙的胜、平、负次数，数字间以1个空格分隔。第3行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有1个空格。如果解不唯一，则输出按字母序最小的解。
//
//输入样例：
//10
//C J
//J B
//C B
//B B
//B C
//C C
//C B
//J B
//B C
//J J
//输出样例：
//5 3 2
//2 3 5
//B B
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int n;
    char a,b;
    //甲方的情况
    int a1=0,a2=0;
    char c[3]={'C','J','B'};
    //C代表“锤子”、J代表“剪刀”、B代表“布”
    int amax[3]={0,0,0},bmax[3]={0,0,0};
    cin>>n;
    int count=n;
    while(count--)
    {
       cin>>a>>b;
       if(a==b) {a2++;continue;}
       else
       {
           if((a=='C')&&(b=='J')) {a1++;amax[0]++;continue;}
           if((a=='J')&&(b=='B')) {a1++;amax[1]++;continue;}
           if((a=='B')&&(b=='C')) {a1++;amax[2]++;continue;}
           if(b=='C') bmax[0]++;
           else if(b=='J') bmax[1]++;
           else if(b=='B') bmax[2]++;
       }
    }
   cout<<a1<<" "<<a2<<" "<<n-a1-a2<<endl;
   cout<<n-a1-a2<<" "<<a2<<" "<<a1<<endl;
   int max=amax[0],k=0;
   for(int i=1;i<3;i++)
   {
       if(max==amax[i]) {
           if(c[k]>c[i])
           k=i;}
       if(max<amax[i]) {k=i;max=amax[i];}
   }
    cout<<c[k]<<" ";
    max=bmax[0],k=0;
   for(int i=1;i<3;i++)
   {
       if(max==bmax[i]) {
           if(c[k]>c[i])
           k=i;}
       if(max<bmax[i]) {k=i;max=bmax[i];}
   }
    cout<<c[k];
}
