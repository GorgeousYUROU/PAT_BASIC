#include<stdio.h>
int top,num;
char s[100];
void push(char c)
{
    if(num==0)
    {
        num++;
        top=0;
        s[top] = c;
    }
    else
    {
       num++;
       top++;
       s[top] = c;
    }
}

void pop()
{
    top--;
    num--;
}

char getTop()
{
    return s[top];
}

char IsEmpty()
{
    if(num==0) return 1;
    else return 0;
}
int main()
{
    char c;
    while((c=getchar())!='\n')
    {
        if(c=='(' || c=='{' || c=='[') push(c);
        else if(c==')')
        {
            if(IsEmpty() || getTop()!='(')  {printf("false\n");return 0;}
            else pop();
        }
        else if(c==']')
        {
            if(IsEmpty() || getTop()!='[')  {printf("false\n");return 0;}
            else pop();
        }
        else if(c=='}')
        {
            if(IsEmpty() || getTop()!='{')  {printf("false\n");return 0;}
            else pop();
        }
    }

    if(IsEmpty()) {printf("True\n");return 0;}
    else {printf("false\n");return 0;}
}
