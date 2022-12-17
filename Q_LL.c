#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct node // Linked List to store queue entries
{
    int data;
    struct node *next;
} node;

typedef struct queue // Queue pointers
{
    struct node *front, *rear;
} queue;

queue *create()
{ // Initialising the queue pointers
    queue *q = (queue *)malloc(sizeof(queue));
    q->front = q->rear = NULL;
    return q;
}

node *getnode(int val)
{ // Initialising the queue nodes
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = val;
    new_node->next = NULL;
    return new_node;
}

queue *enqueue(queue *q, int val)
{
    node *new_node = getnode(val);
    if (q->front == NULL) // for empty queue
        q->front = q->rear = new_node;
    else
    {
        q->rear->next = new_node; // enqueue at the rear end
        q->rear = new_node;
    }
    return q;
}

void peek(queue *q)
{
    if (q->front == NULL)
        printf("\n\tUNDERFLOW!\n");
    else
    {
        printf("\n Front : %d", q->front->data);
        printf("\n Rear : %d\n", q->rear->data);
    }
}

void display(queue *q)
{
    node *temp = q->front;
    if (temp == NULL)
        printf("\n\tUNDERFLOW!\n");
    else
    {
        while (temp->next != NULL)
        {
            printf(" %d ->", temp->data);
            temp = temp->next;
        }
        printf(" %d\n", temp->data);
    }
}

queue *dequeue(queue *q)
{
    node *temp = q->front;
    if (q->front == NULL)
        printf("\n\tUNDERFLOW!\n");
    else
    {
        q->front = q->front->next;
        printf("\n Dequeued Value : %d\n", temp->data);
        free(temp);
    }
    return q;
}

void main()
{
    int ch, val;
    clrscr();
    queue *q = create(); // Initialising the queue pointers
    do
    {
        printf("\n *******MAIN MENU*******");
        printf("\n 1. Enqueque\n 2. Peek\n 3. Display\n 4. Dequeue\n 5. Exit");
        printf("\n ***********************");
        printf("\n Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\n Enter the value to be enqueued : ");
            scanf("%d", &val);
            q = enqueue(q, val);
            break;
        case 2:
            peek(q);
            break;
        case 3:
            printf("\n Queue Status :\n");
            display(q);
            break;
        case 4:
            q = dequeue(q);
            break;
        default:
            ch = 5;
        }
    } while (ch != 5);
    getch();
}