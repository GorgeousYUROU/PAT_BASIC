#include<stdio.h>
#include<stdlib.h>
typedef struct node{
int key;
struct node *next;
}Node;

Node *head=NULL;


void Insert_and_Sort(int x)
{
    Node *new_node=(Node *)malloc(sizeof(Node));
    new_node->key=x;
    if(head==NULL || head->key > x)
    {
        new_node->next=head;
        head=new_node;
    }
    else
    {
        Node* current=head;
        while(1)
        {
            if(current->next == NULL || current->next->key > x)
            {
                new_node->next=current->next;
                current->next=new_node;
                break;
            }
            else
            {
                current=current->next;
            }
        }
    }
}

void print()
{
    Node * current=head;
    while(current!=NULL)
    {
        printf("%d ",current->key);
        current=current->next;
    }
}

int main()
{
    Insert_and_Sort(12);
    Insert_and_Sort(15);
    Insert_and_Sort(13);
    Insert_and_Sort(2);
    Insert_and_Sort(1);
    print();

}
