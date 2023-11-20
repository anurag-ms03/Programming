#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void push(struct node **top, int ele)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = ele;
    p->next = NULL;
    if (*top == NULL)
    {
        *top = p;
        return;
    }
    else
    {
        p->next = *top;
        *top = p;
    }
}

int pop(struct node **top)
{
    int ele;
    struct node *t;
    if (*top == NULL)
    {
        printf("Stack Underflow cannot delete\n");
        return -1; 
    }
    t = *top;
    ele = t->data;
    *top = t->next;
    t->next = NULL;
    free(t);
    return ele;
}

void display(struct node *top)
{
    struct node *t;
    t = top;
    while (t != NULL)
    {
        printf("%d \n", t->data);
        t = t->next;
    }
    printf("\n");
}

int main()
{
    struct node *top = NULL;
    int n, ele, x;
    while (1)
    {
        printf("Enter the option below:\n");
        printf("1. Push  2. Pop  3. Display 4. Exit\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Enter the element to be pushed:\n");
            scanf("%d", &ele);
            push(&top, ele);
            break;
        case 2:
            x = pop(&top);
            if (x != -1)
                printf("The element that was popped is %d\n", x);
            break;
        case 3:
            display(top);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Enter a valid choice\n");
        }
    }
    return 0;
}
