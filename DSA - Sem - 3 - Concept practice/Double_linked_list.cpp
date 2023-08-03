#include <bits/stdc++.h>
using namespace std;
struct node
{
    int val;
    struct node *prev;
    struct node *next;
};
struct node *Search(struct node *head, int pos)
{
    struct node *p = head;
    for (; p->next != NULL; p = p->next)
        if (pos-- == 0)
            return p;
    if (p->next == NULL)
        return p;
    return NULL;
}
void Insert(struct node *head, int pos)
{
    struct node *p = Search(head, pos);
    if (p == NULL)
        cout << "Invalid position entered!!\n";
    else
    {
        struct node *temp = new struct node;
        cin >> temp->val;
        temp->next = p->next;
        p->next = temp;
        temp->prev = p;
        if (temp->next != NULL)
            temp->next->prev = temp;
    }
}
void Deletion(struct node *head, int pos)
{
}
void printList(struct node *head)
{
    for (struct node *p = head->next; p != NULL; p = p->next)
        cout << p->val << " ";
}
int main()
{
    struct node *head = new struct node;
    head->next = head->prev = NULL;
    Insert(head, 0);
    Insert(head, 1);
    Insert(head, 2);
    Insert(head, 1);
    printList(head);
}