#include <stdio.h>
#define MAX 100

int main() {
    int queue[MAX], front = -1, rear = -1;
    int dequeue[MAX], left = -1, right = -1;
    int n, i, value;

   
    printf("Queue Operations\n");

   
    printf("Enter number of elements to insert into Queue: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &value);
        if (rear == MAX - 1) {
            printf("Queue Overflow\n");
            break;
        }
        if (front == -1) front = 0;
        rear++;
        queue[rear] = value;
    }

 
    printf("Queue: ");
    for(i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");

    if (front != -1 && front <= rear) {
        printf("Dequeued: %d\n", queue[front]);
        front++;
    } else {
        printf("Queue Underflow\n");
    }

    printf("Queue after Dequeue: ");
    for(i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");

    
    printf("\n Dequeue Operations\n");

    
    printf("Enter number of elements to insert at RIGHT of Dequeue: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &value);
        if (right == MAX - 1) {
            printf("Dequeue Overflow at Right\n");
            break;
        }
        if (left == -1) {
            left = 0;
            right = 0;
        } else {
            right++;
        }
        dequeue[right] = value;
    }

    
    printf("Enter number of elements to insert at LEFT of Dequeue: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &value);
        if (left <= 0) {
            printf("Dequeue Overflow at Left\n");
            break;
        }
        left--;
        dequeue[left] = value;
    }

    
    printf("Dequeue: ");
    for(i = left; i <= right; i++) {
        printf("%d ", dequeue[i]);
    }
    printf("\n");

    
    if (left <= right) {
        printf("Deleted from RIGHT: %d\n", dequeue[right]);
        right--;
    } else {
        printf("Dequeue Underflow at Right\n");
    }

    
    if (left <= right) {
        printf("Deleted from LEFT: %d\n", dequeue[left]);
        left++;
    } else {
        printf("Dequeue Underflow at Left\n");
    }

    
    printf("Dequeue after deletions: ");
    for(i = left; i <= right; i++) {
        printf("%d ", dequeue[i]);
    }
    printf("\n");

    return 0;
}

	
