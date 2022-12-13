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

int pop()
{
    int i;
    if (top == NULL)
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        node *temp = top;
        i = top->data;
        top = top->next;
        free(temp);
        return i;
    }
}

void display()
{
    if (top == NULL)
    {
        printf("\nStack Underflow!\n");
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
        printf("NULL\n\n");
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
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit");
        printf("\n--------------------------------------------");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the value to insert: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            printf("Popped element : %d\n", pop());
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nWrong Choice!\n");
        }
    }
    // getch();
    return 0;
}