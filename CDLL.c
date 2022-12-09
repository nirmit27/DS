#include <stdio.h>
// #include <conio.h>
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
    node->prev = NULL;
    node->next = NULL;
    return node;
}

cdll *create(cdll *start)
{
    int num;
    cdll *new_node, *temp;
    printf("\nEnter 0 to stop.");
    while (num)
    {
        new_node = getnode();
        if (start == NULL)
        {
            new_node->next = new_node;
            start = new_node;
        }
        else
        {
            temp = start;
            while (temp->next != start)
                temp = temp->next;
            new_node->prev = temp;
            temp->next = new_node;
            new_node->next = start;
            start->prev = new_node;
        }
        printf("More nodes? (0/1) : ");
        scanf("%d", &num);
    }
    return start;
}

cdll *display(cdll *start)
{
    cdll *temp = start;
    while (temp->next != start)
    {
        printf(" %d =>", temp->data);
        temp = temp->next;
    }
    printf(" %d =>", temp->data);
    printf(" NULL");
    return start;
}

cdll *insert_beg(cdll *start)
{
    cdll *temp = start;
    cdll *new_node = getnode();
    while (temp->next != start)
        temp = temp->next;
    temp->next = new_node;
    new_node->prev = temp;
    new_node->next = start;
    start->prev = new_node;
    start = new_node;
    return start;
}

cdll *insert_end(cdll *start)
{
    cdll *temp = start;
    cdll *new_node = getnode();
    while (temp->next != start)
        temp = temp->next;
    temp->next = new_node;
    new_node->prev = temp;
    new_node->next = start;
    start->prev = new_node;
    return start;
}

cdll *delete_beg(cdll *start)
{
    cdll *temp2;
    cdll *temp = start;
    while (temp->next != start)
        temp = temp->next;
    temp->next = start->next;
    temp2 = start;
    start = start->next;
    start->prev = temp;
    free(temp2);
    return start;
}

cdll *delete_end(cdll *start)
{
    cdll *temp = start;
    while (temp->next != start)
        temp = temp->next;
    temp->prev->next = start;
    start->prev = temp->prev;
    free(temp);
    return start;
}

cdll *delete_node(cdll *start)
{
    int val;
    cdll *temp = start;
    printf("\nEnter the data of the node to be deleted : ");
    scanf("%d", &val);
    while (temp->data != val)
        temp = temp->next;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    return start;
}

cdll *delete_list(cdll *start)
{
    cdll *temp = start;
    while (temp->next != start)
        start = delete_end(start);
    free(start);
    return start;
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
            start = create(start);
            printf("\nCircular Doubly Linked List CREATED!");
            break;
        case 2:
            printf("Linked List status : \n");
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