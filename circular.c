#include <stdio.h>

#define SIZE 5  

int queue[SIZE];
int front = -1;
int rear = -1;

int isFull() {
    return (front == (rear + 1) % SIZE);
}

int isEmpty() {
    return front == -1;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot enqueue %d\n", value);
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }

    queue[rear] = value;
    printf("Enqueued: %d\n", value);
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Cannot dequeue\n");
        return -1;
    }

    int item = queue[front];

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }

    return item;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        // Display menu
        printf("\nCircular Queue Operations\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                printf("Dequeued: %d\n", dequeue());
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

