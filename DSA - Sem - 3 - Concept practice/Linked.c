#include <stdio.h>
#include <stdlib.h>
struct node
{
    int val;
    struct node *next;
};
struct node *Search(struct node *head, int pos)
{
    for (struct node *p = head; p != NULL; p = p->next)
        if (pos-- == 1)
            return p;
    return NULL;
}
void Insert(struct node *head, int pos)
{
    struct node *p = Search(head, pos);
    if (p == NULL)
        printf("Invalid position!!\n");
    else
    {
        struct node *temp = malloc(sizeof(struct node));
        temp->next = p->next;
        p->next = temp;
        printf("Enter the value\n");
        scanf("%d", &temp->val);
    }
}
void printList(struct node *head)
{
    for (struct node *p = head->next; p != NULL; p = p->next)
        printf("%d ", p->val);
    printf("\n");
}
int main()
{
    struct node *head = malloc(sizeof(struct node));
    head->next = NULL;
    Append(head);
    Append(head);
    Append(head);
    Append(head);
    printList(head);
}