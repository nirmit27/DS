#include <stdio.h>
// #include <conio.h>
#include <stdlib.h>
#define size 10
int front = -1, rear = -1;
int arr[size];
void enqueue(){
    int item;
    if (rear == size - 1)
        printf("Overflow \n");
    else{
        if (front == -1)
            front = 0;
        printf("Element to be inserted in the Queue:\t");
        scanf("%d", &item);
        arr[++rear] = item;
}    }
void dequeue(){
    if (front == -1 || front > rear){
        printf("Underflow \n");
        return;
    }
    else
        printf("Element deleted from the Queue: %d\n", arr[front++]);
}
void display()
{
    if (front == -1)
        printf("The Queue is empty.\n");
    else{
        int i;
	printf("Queue :\n");
	for (i = front; i <= rear; i++)
            printf("%d\t", arr[i]);
        printf("\n");
}    }
int main(){
    int ch;
    // clrscr();
    while (1){
        printf("\n-----------------Queue Operations----------------\n");
        printf("1. Enqueue operation\n");
        printf("2. Dequeue operation\n");
        printf("3. Display the Queue\n");
        printf("4. Exit\n");
        printf("\nEnter your choice of operation: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice of operation!\n");
    }    }
    return 0;
}