// 1044. 火星数字(20)
// 火星人是以13进制计数的：

// 地球人的0被火星人称为tret。
// 地球人数字1到12的火星文分别为：jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec。
// 火星人将进位以后的12个高位数字分别称为：tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou。
// 例如地球人的数字“29”翻译成火星文就是“hel mar”；而火星文“elo nov”对应地球数字“115”。为了方便交流，请你编写程序实现地球和火星数字之间的互译。

// 输入格式：

// 输入第一行给出一个正整数N（<100），随后N行，每行给出一个[0, 169)区间内的数字 —— 或者是地球文，或者是火星文。

// 输出格式：

// 对应输入的每一行，在一行中输出翻译后的另一种语言的数字。

// 输入样例：
// 4
// 29
// 5
// elo nov
// tam
// 输出样例：
// hel mar
// may
// 115
// 13

#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    char low[13][5]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
    char high[12][4]={"tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};

    /*input*/
    int N,i,j,n;
    char a[4],b[4];
    cin>>N;
    getchar();
    while(N--)
    {
       cin>>a;
       if(getchar()!='\n') cin>>b;
       else b[0]='\0';
        i=0;
       if('0'<=a[0] && a[0]<='9')
       {
           int m=0;
           int num=0;
           while(a[m]!='\0')
           {
               num=a[m++]-'0'+num*10;
           }
           if(num/13)
           {
               cout<<high[num/13-1];
               if(num%13) cout<<" ";
               else cout<<endl;
           }
           if(num%13)
           {
               cout<<low[num%13]<<endl;
           }
           if(num==0) {cout<<"tret"<<endl;}

       }
       else
       {
           //for(j=0;j<12;j++) if(s[0]==high[j][0] && s[1]==high[j][1] && s[2]==high[j][2]) break;
           for(j=0;j<12;j++) if(!strcmp(a,high[j])) break;
           if(b[0]!='\0')
           {
            //for(n=0;n<13;n++) if(s[4]==low[j][0] && s[5]==low[j][1] && s[6]==low[j][2]) break;
            for(n=0;n<13;n++) if(!strcmp(b,low[n])) break;
            cout<<(j+1)*13+n<<endl;
           }
           else
           {
               if(j<12) {cout<<(j+1)*13<<endl;}
               else
               {
                   //for(n=0;n<13;n++) if(s[0]==low[n][0] && s[1]==low[n][1] && s[2]==low[n][2]) break;
                   for(n=0;n<13;n++) if(!strcmp(a,low[n])) break;
                   cout<<n<<endl;
               }

           }
       }
    }



}
