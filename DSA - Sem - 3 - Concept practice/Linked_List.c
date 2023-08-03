#include <stdio.h>
#include <stdlib.h>
struct node
{
    int val;
    struct node *next;
};
void append(struct node *head)
{
    int value;
    printf("Enter the value to be entered for the next list element ");
    scanf("%d", &value);
    struct node *p = head;
    while (p->next != NULL)
        p = p->next;
    struct node *temp = malloc(sizeof(struct node));
    temp->next = NULL;
    temp->val = value;
    p->next = temp;
}
void printList(struct node *head)
{
    for (struct node *p = head->next; p != NULL; p = p->next)
        printf("%d ", p->val);
    printf("\n");
}
struct node *search(struct node *head, int pos)
{
    struct node *p = head;
    for (; p->next != NULL; p = p->next)
    {
        if (pos == 0)
            return p;
        pos--;
    }
    if (p->next == NULL)
        return p;
    return NULL;
}
void insertAtPosition(struct node *head, int pos)
{
    struct node *p = search(head, pos);
    if (p == NULL)
        printf("Invalid position!!\n");
    else if (pos == 0)
    {
        struct node *temp = malloc(sizeof(struct node));
        temp->next = head->next;
        head->next = temp;
        printf("Enter the value\n");
        scanf("%d", &temp->val);
    }
    else
    {
        p = search(head, pos - 1);
        struct node *temp = malloc(sizeof(struct node));
        printf("Enter the value\n");
        scanf("%d", &temp->val);
        temp->next = p->next;
        p->next = temp;
    }
}
int main()
{
    struct node *head = malloc(sizeof(struct node));
    head->next = NULL;
    int choice;
    int pos;
    while (1)
    {
        printf("Enter your choice of operations -- \n1.Append\n2.Insert at a given position\n3.PrintList\n4.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            append(head);
            break;
        case 2:
            printf("Enter the position to be inserted\n");
            scanf("%d", &pos);
            insertAtPosition(head, pos);
            break;
        case 3:
            printList(head);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!!\n");
        }
    }
}