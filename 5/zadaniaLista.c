#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int val;
    struct node * next;
} node_t;

void printList(node_t * head)
{
    node_t * current = head;
    int index = 0;
    while (current != NULL)
    {
        printf("%d [%d]\n", current->val, index);
        current = current->next;
        index++;
    }
}

void addFirst(node_t ** head, int value)
{
    node_t *new_node;
    new_node = (node_t *) malloc(sizeof(node_t));

    new_node->val = value;
    new_node->next = *head;
    *head = new_node;
}

void pop(node_t** head)
{
    node_t * next_node = NULL;

    if (*head == NULL)
    {
        return;
    }

    next_node = (*head)->next;
    free(*head);
    *head = next_node;
}

void removeLast(node_t * head)
{
    node_t * current = head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}

void removeByIndex(node_t ** head, int n)
{
    int i = 0;
    node_t * current = *head;
    node_t * temp_node = NULL;

    if (n == 0)
    {
        pop(head);
        return;
    }

    for (i = 0; i < n-1; i++)
    {
        if (current->next == NULL)
        {
            return;
        }
        current = current->next;
    }

    temp_node = current->next;
    current->next = temp_node->next;
    free(temp_node);
}

void removeByValue(node_t ** head, int value)
{
    node_t * current = *head;
    node_t * temp_node = NULL;

    if (current->val == value)
    {
        pop(head);
        return;
    }

    while (current->next != NULL)
    {
        if (current->next->val == value)
        {
            temp_node = current->next;
            current->next = temp_node->next;
            free(temp_node);
            return;
        }
        current = current->next;
    }
}

void addOnIndex(node_t ** head, int value, int n)
{
    int i = 0;
    node_t * current = *head;
    node_t * temp_node = NULL;

    if (n == 0)
    {
        addFirst(head, value);
        return;
    }

    for (i = 0; i < n-1; i++)
    {
        if (current->next == NULL)
        {
            return;
        }
        current = current->next;
    }

    temp_node = (node_t *) malloc(sizeof(node_t));
    temp_node->val = value;
    temp_node->next = current->next;
    current->next = temp_node;
}

int main()
{
    node_t * head = NULL;
    head = (node_t *) malloc(sizeof(node_t));
    if (head == NULL)
    {
        return 1;
    }

    head->val = 1;
    head->next = NULL;

    printf("\n1. Dodawanie elementów na początek listy\n");
    printf("====================\n\n");

    for (int i = 2; i < 8; i++)
    {
        addFirst(&head, i*10);
    }
    printList(head);

    printf("\n2. Usuwanie pierwszego elementu\n");
    printf("====================\n\n");
    pop(&head);
    printList(head);

    printf("\n3. Usuwanie ostatniego elementu\n");
    printf("====================\n\n");
    removeLast(head);
    printList(head);

    printf("\n4. Usuwanie elementu o indeksie 3\n");
    printf("====================\n\n");
    removeByIndex(&head, 3);
    printList(head);

    printf("\n5. Usuwanie elementu o wartości 40\n");
    printf("====================\n\n");
    removeByValue(&head, 40);
    printList(head);

    printf("\n6. Dodawanie elementu o wartości 15 na indeks 1\n");
    printf("====================\n\n");
    addOnIndex(&head, 15, 1);
    printList(head);

    return 0;
}
