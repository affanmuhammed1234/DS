#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int coeff;
    int expo;
    struct Node* next;
} Node;

// Create new node
Node* createNode(int coeff, int expo) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->expo = expo;
    newNode->next = NULL;
    return newNode;
}

// Insert node at end (skip zero coeff)
void insertEnd(Node** head, int coeff, int expo) {
    if (coeff == 0) return;  // skip zero coefficient

    Node* newNode = createNode(coeff, expo);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Display polynomial nicely
void displayPoly(Node* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }

    Node* temp = head;
    int firstTerm = 1;

    while (temp) {
        if (temp->coeff != 0) {
            if (!firstTerm && temp->coeff > 0)
                printf(" + ");

            if (temp->expo == 0)
                printf("%d", temp->coeff);
            else if (temp->expo == 1)
                printf("%dx", temp->coeff);
            else
                printf("%dx^%d", temp->coeff, temp->expo);

            firstTerm = 0;
        }
        temp = temp->next;
    }
    printf("\n");
}

// Free linked list memory
void freeList(Node* head) {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Add polynomials
Node* addPolynomials(Node* P1, Node* P2) {
    Node* ptr1 = P1;
    Node* ptr2 = P2;
    Node* RESULT = NULL;

    while (ptr1 && ptr2) {
        if (ptr1->expo == ptr2->expo) {
            int coeff = ptr1->coeff + ptr2->coeff;
            insertEnd(&RESULT, coeff, ptr1->expo);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        } else if (ptr1->expo > ptr2->expo) {
            insertEnd(&RESULT, ptr1->coeff, ptr1->expo);
            ptr1 = ptr1->next;
        } else {
            insertEnd(&RESULT, ptr2->coeff, ptr2->expo);
            ptr2 = ptr2->next;
        }
    }

    // Add remaining terms
    while (ptr1) {
        insertEnd(&RESULT, ptr1->coeff, ptr1->expo);
        ptr1 = ptr1->next;
    }
    while (ptr2) {
        insertEnd(&RESULT, ptr2->coeff, ptr2->expo);
        ptr2 = ptr2->next;
    }

    return RESULT;
}

int main() {
    Node* P1 = NULL;
    Node* P2 = NULL;
    Node* RESULT = NULL;
    int n, coeff, expo;

    // Input for Polynomial 1
    do {
        printf("Enter number of terms in Polynomial 1 (positive integer): ");
        scanf("%d", &n);
    } while (n <= 0);

    printf("Enter terms (coeff exponent) in descending order of exponent:\n");
    for (int i = 0; i < n; i++) {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &coeff, &expo);
        insertEnd(&P1, coeff, expo);
    }

    // Input for Polynomial 2
    do {
        printf("\nEnter number of terms in Polynomial 2 (positive integer): ");
        scanf("%d", &n);
    } while (n <= 0);

    printf("Enter terms (coeff exponent) in descending order of exponent:\n");
    for (int i = 0; i < n; i++) {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &coeff, &expo);
        insertEnd(&P2, coeff, expo);
    }

    printf("\nPolynomial 1: ");
    displayPoly(P1);

    printf("Polynomial 2: ");
    displayPoly(P2);

    RESULT = addPolynomials(P1, P2);

    printf("Sum: ");
    displayPoly(RESULT);

    // Free memory
    freeList(P1);
    freeList(P2);
    freeList(RESULT);

    return 0;
}

