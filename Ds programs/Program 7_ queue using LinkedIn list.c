
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue()
{
    struct Node *newNode;
    int value;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = NULL;

    if (front == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    printf("Element inserted\n");
}

void dequeue()
{
    struct Node *temp;

    if (front == NULL)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        temp = front;

        printf("Deleted element: %d\n", front->data);

        front = front->next;

        if (front == NULL)
        {
            rear = NULL;
        }

        free(temp);
    }
}

void display()
{
    struct Node *temp = front;

    if (front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements: ");

        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }

        printf("\n");
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
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
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
