// 1019. 数字黑洞 (20)
// 给定任一个各位数字不完全相同的4位正整数，如果我们先把4个数字按非递增排序，再按非递减排序，然后用第1个数字减第2个数字，将得到一个新的数字。一直重复这样做，我们很快会停在有“数字黑洞”之称的6174，这个神奇的数字也叫Kaprekar常数。

// 例如，我们从6767开始，将得到

// 7766 - 6677 = 1089
// 9810 - 0189 = 9621
// 9621 - 1269 = 8352
// 8532 - 2358 = 6174
// 7641 - 1467 = 6174
// ... ...

// 现给定任意4位正整数，请编写程序演示到达黑洞的过程。

// 输入格式：

// 输入给出一个(0, 10000)区间内的正整数N。

// 输出格式：

// 如果N的4位数字全相等，则在一行内输出“N - N = 0000”；否则将计算的每一步在一行内输出，直到6174作为差出现，输出格式见样例。注意每个数字按4位数格式输出。

// 输入样例1：
// 6767
// 输出样例1：
// 7766 - 6677 = 1089
// 9810 - 0189 = 9621
// 9621 - 1269 = 8352
// 8532 - 2358 = 6174
// 输入样例2：
// 2222
// 输出样例2：
// 2222 - 2222 = 0000

#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
    char c[5];
    cin>>c;
    int count=0;
    int k;
    while(1)
    {
        k=0;
        int t=strlen(c);
        if(t<4)
        {
            for(k=t;k<4;k++) c[k]='0';
            c[k]='\0';
        }
    sort(c,c+4);
    char a[5],b[5];
    int besub,sub;
    int flag=0;
    for(int i=0,j=3;i<4;i++,j--)
    {
        a[i]=c[j];
        if(flag==0) besub=c[i]-'0';
        else besub=c[i]-'0'-1;
        sub=c[j]-'0';
        if(besub>=sub) {b[j]=(char)(besub-sub+'0');flag=0;}
        else
        {
           b[j]=(char)(besub+10-sub+'0');
           flag=1;
        }
    }
    a[4]='\0';b[4]='\0';
    if(!strcmp(a,c)) {printf("%s - %s = 0000\n",a,c);break;}
    else
    {
        printf("%s - %s = %s\n",a,c,b);
        strcpy(c,b);
        if(!strcmp(b,"6174")) break;
    }
    }
}
