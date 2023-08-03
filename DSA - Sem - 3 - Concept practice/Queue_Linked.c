#include<stdio.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node *next;
};
void Insertion(struct node *front,struct node *rear)
{
    if(front->next==NULL&&rear->next==NULL)
    {
        struct node *temp = malloc(sizeof(struct node));
        front->next=rear->next=temp;
        temp->next=NULL;
        scanf("%d",&temp->val);
    }
    else
    {
        struct node *temp=malloc(sizeof(struct node));
        rear->next->next=temp;
        temp->next=NULL;
        scanf("%d",&temp->val);
    }
}
void Deletion(struct node *front, struct node *rear)
{
    if(front->next==rear->next&&front->next==NULL)
    printf("Queue Underflow");
    else if(front->next==rear->next)
    {
        struct node *temp=front;
        front->next=rear->next=NULL;
        free(temp);
    }
    else
    {
        struct node *p=front->next;
        front=p->next;
        free(p);
    }
}
void printQueue(struct node *front,struct node *rear)
{
    for(struct node *p=front->next;p!=NULL;p=p->next)
    printf("%d ",p->val);
    printf("\n");
}
int main()
{
    struct node *front=malloc(sizeof(struct node));
    struct node *rear=malloc(sizeof(struct node));
    front->next=rear->next=NULL;
    Insertion(front,rear);
    Insertion(front,rear);
    Insertion(front,rear);
    printQueue(front,rear);
}