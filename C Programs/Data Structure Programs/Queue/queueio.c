/*Implementation Of Queue input output*/

#include <stdio.h>
#include <stdlib.h>

void display(int *arr, int *front, int *rear)
{
    int i;
    if (*front > *rear)
    {
        printf("Queue is empty");
        return;
    }
    printf("\nQueue Elements: ");
    for (i = *front; i <= *rear; i++)
        printf("%d ", arr[i]);
}

void qinsert(int *arr, int *front, int *rear, int item)
{
    (*rear)++;
    arr[*rear] = item;
    printf("INSERTED: %d", item);
    if (*front == -1)
        (*front)++;
    display(arr, front, rear);
}

int qremove(int *arr, int *front, int *rear)
{
    int val;
    val = arr[*front];
    (*front)++;
    display(arr, front, rear);
    if (*front > *rear)
        *front = *rear = -1;
    return val;
}

int main(void)
{
    int *arr, max, ch, front, rear, item;
    printf("Enter the size of the queue: ");
    scanf("%d", &max);
    arr = (int *)calloc(max, sizeof(int));
    front = rear = -1;
    while (1)
    {
        printf("\nMENU:");
        printf("\n1.INSERT\n2.REMOVE\n3.DISPLAY\n4.EXIT");
        printf("\nEnter Your Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if (rear == max - 1)
            {
                printf("Queue Is Full");
                break;
            }
            else
            {
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                qinsert(arr, &front, &rear, item);
            }
            break;
        case 2:
            if (rear == -1)
            {
                printf("Queue is already empty...cannot remove");
                break;
            }
            else
            {
                item = qremove(arr, &front, &rear);
                printf("\nREMOVED: %d", item);
            }
            break;
        case 3:
            display(arr, &front, &rear);
            break;
        case 4:
            return 0;
        }
    }
}