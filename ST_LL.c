#include <stdio.h>
// #include<conio.h>
#include <stdlib.h>

typedef struct stack_ll
{
    int data;
    struct stack_ll *next;
} node;
node *top = NULL;

void push(int value)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = value; // assign value to the node
    if (top == NULL)
    {
        new_node->next = NULL;
    }
    else
    {
        new_node->next = top; // Make the node as top
    }
    top = new_node; // top always points to the newly created node
    printf("Node pushed successfully!\n");
}

void pop()
{
    int i;
    if (top == NULL)
    {
        printf("\nStack Underflow!");
    }
    else
    {
        node *temp = top;
        i = top->data;
        printf("\nPopped element : %d", i);
        top = top->next;
        free(temp);
    }
}

void peek()
{
    if (top != NULL)
        printf("\nTop of Stack : %d\n", top->data);
    else
        printf("\nStack Underflow!");
}

void display()
{
    if (top == NULL)
    {
        printf("\nStack Underflow!");
    }
    else
    {
        printf("\nStack status :\n");
        node *temp = top;
        while (temp != NULL)
        {
            printf("%d-->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    int choice, value;
    // clrscr();
    printf("\nImplementation of Stack using Linked List:-");
    while (1)
    {
        printf("\n--------------------------------------------");
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit");
        printf("\n--------------------------------------------");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the value to be pushed: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("\nWrong Choice!\n");
        }
    }
    // getch();
    return 0;
}