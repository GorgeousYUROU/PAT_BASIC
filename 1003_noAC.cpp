//1003. 我要通过！(20)

// “答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于PAT的“答案正确”大派送 —— 只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。

// 得到“答案正确”的条件是：

// 1. 字符串中必须仅有P, A, T这三种字符，不可以包含其它字符；
// 2. 任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
// 3. 如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a, b, c 均或者是空字符串，或者是仅由字母 A 组成的字符串。

// 现在就请你为PAT写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。
// 输入格式： 每个测试输入包含1个测试用例。第1行给出一个自然数n (<10)，是需要检测的字符串个数。接下来每个字符串占一行，字符串长度不超过100，且不包含空格。

// 输出格式：每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出YES，否则输出NO。

// 输入样例：
// 8
// PAT
// PAAT
// AAPATAA
// AAPAATAAAA
// xPATx
// PT
// Whatever
// APAAATAA
// 输出样例：
// YES
// YES
// YES
// YES
// NO
// NO
// NO
// NO
//解题思路：m为a中A的个数，n为p和T之间A的个数，正确字符串为mA P nA T m*nA  (m可以为0)
#include <iostream>
#include<string.h>
using namespace std;

int main()
{
   char a[100];
   int n1;
   cin>>n1;
   int answer[n1];
   for(int k=0;k<n1;k++)
   {
       cin>>a;
       int m=0;//a中A的个数
       int n=0;//p和T之间A的个数
       for(int i=0,j=strlen(a)-1;i<=j;i++,j--)
       {
           if((a[i]=='A')||(a[i]=='P')||(a[i]=='T'))//限定开始结尾都只能在PAT这三个字母之间
           {
              if((a[j]=='A')||(a[j]=='P')||(a[j]=='T'))
               {
                   if((a[i]==a[j])&&(a[j]=='A')) {m++;continue;}//检测满足XPATX的情况
                   else
                   if(a[i]=='P')
                   {
                       if(a[j]=='T')
                       {
                           if((a[i+1]=='A')&&(i+1==j-1)) {answer[k]=1;break;}//满足XPATX的情况,并排除PATPAT的情况
                           int count=0;
                           if((m==0)&&(a[i+1]=='A'))
                           {
                           for(int s=i+1;s<j;s++)//pnAT的情况
                           {
                             if(a[s]=='A') count++;
                           }
                            if(count==j-i-1){answer[k]=1;break;}
                              else {answer[k]=0;break;}
                           }
                           else{answer[k]=0;break;}//P之后一定为字母A
                       }
                       if(a[j]=='A')//m个APn个ATmn个A
                       {
                           int count=0;//c中包含多少个A
                           int v=j;
                           for(v=j;v>i;v--)
                           {
                               if(a[v]=='A') count++;
                               if(a[v]=='T') break;
                           }
                           if(a[v]=='T')
                           {
                           if((m!=0)&&(count%m==0))
                           {
                               int s;
                              for(s=i+1;s<v;s++)
                              {
                                 if(a[s]=='A') n++;
                                 else break;
                              }
                              if((n==count/m+1)&&(s==v)){answer[k]=1;break;}
                              else {answer[k]=0;break;}
                           }
                           else {answer[k]=0;break;}
                           }
                           else {answer[k]=0;break;}
                       }
                        if((a[j]=='k')) {answer[k]=0;break;}
                   }
               }
               else {answer[k]=0;break;}
           }
           else {answer[k]=0;break;}
       }
   }
   for(int k=0;k<n1;k++)
   {
       if(answer[k]==1) cout<<"YES"<<endl;
       else cout<<"NO"<<endl;
   }
return 0;
}

// 链接：https://www.nowcoder.com/questionTerminal/6d1dc30b18b14dedb1728d1cf956b56d
// 来源：牛客网

// #include<stdio.h>
// #include<string.h>
// int main()
// {
//     char s[1001];
//     int i,n,a,b,c;
//     char *p;
//     scanf("%d",&n); 
//     for(i=0;i<n;i++)
//     {
//         scanf("%s",&s);
//         if(!strcmp(s,"PAT")){printf("YES\n");continue;}   //条件一
//   
//                 a=b=c=0;
//                 p=s;
//                 while(*p=='A'){a++;p++;}   //a为第一个p前a的个数
//                 if(*p=='P'){
//                         p++;
//                         while(*p=='A'){b++;p++;}   //b为夹在p和t之间的a的个数
//                         if(*p=='T'){
//                                 p++;
//                                 while(*p=='A'){c++;p++;}   //c为t之后的a的个数
//                                 if(!(*p) && b>0 && c==a*b){printf("YES\n");continue;}  //条件三
//                         }
//                 }
//                 printf("NO\n");
//           
//     }
//     return 0;
// }
