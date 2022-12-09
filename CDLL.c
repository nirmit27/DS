#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct circ_doubly_ll
{
    struct circ_doubly_ll *prev;
    int data;
    struct circ_doubly_ll *next;
} cdll;

cdll *start = NULL;

cdll *getnode()
{
    cdll *node = (cdll *)malloc(sizeof(cdll));
    printf("\nEnter the data to be inserted : ");
    scanf("%d", &(node->data));
    node->next = node->prev = NULL;
    return node;
}

cdll *create(cdll *start){
    
}

int main()
{
    int option;
    // clrscr();
    do
    {
        printf("\n\n----------------MAIN MENU----------------");
        printf("\n 1. Create a list");
        printf("\n 2. Display the list");
        printf("\n 3. Add a node at the beginning");
        printf("\n 4. Add a node at the end");
        printf("\n 5. Delete a node from the beginning");
        printf("\n 6. Delete a node from the end");
        printf("\n 7. Delete a given node");
        printf("\n 8. Delete the entire list");
        printf("\n 9. EXIT");
        printf("\n-------------------------------------------");
        printf("\nEnter your option : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            start = create_cll(start);
            printf("\nCircular Doubly Linked List CREATED!");
            break;
        case 2:
            start = display(start);
            break;
        case 3:
            start = insert_beg(start);
            printf("\nNode inserted successfully!\n");
            break;
        case 4:
            start = insert_end(start);
            printf("\nNode inserted successfully!\n");
            break;
        case 5:
            start = delete_beg(start);
            printf("\nNode deleted successfully!\n");
            break;
        case 6:
            start = delete_end(start);
            printf("\nNode deleted successfully!\n");
            break;
        case 7:
            start = delete_node(start);
            printf("\nNode deleted successfully!\n");
            break;
        case 8:
            start = delete_list(start);
            printf("\nCircular Doubly Linked List DELETED!");
        }
    } while (option != 9);
    // getch();
    return 0;
}