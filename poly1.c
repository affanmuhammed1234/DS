#include <stdio.h>

#define MAX_TERMS 50

// Function to input a polynomial
void inputPoly(int poly[MAX_TERMS][2], int *n) {
    printf("Enter number of terms in the polynomial: ");
    scanf("%d", n);

    for (int i = 0; i < *n; i++) {
        printf("Enter exponent and coefficient for term %d: ", i + 1);
        scanf("%d %d", &poly[i][0], &poly[i][1]);  // [0] = exponent, [1] = coefficient
    }
}

// Function to add two polynomials
void addPolynomials(int p1[MAX_TERMS][2], int n1, int p2[MAX_TERMS][2], int n2, int result[MAX_TERMS][2], int *nRes) {
    int i, j, k = 0;

    // Copy all terms from p1 to result
    for (i = 0; i < n1; i++) {
        result[k][0] = p1[i][0];
        result[k][1] = p1[i][1];
        k++;
    }

    // Add terms from p2
    for (i = 0; i < n2; i++) {
        int found = 0;
        for (j = 0; j < k; j++) {
            if (p2[i][0] == result[j][0]) {
                result[j][1] += p2[i][1];  // Add coefficients if exponents match
                found = 1;
                break;
            }
        }
        if (!found) {
            result[k][0] = p2[i][0];
            result[k][1] = p2[i][1];
            k++;
        }
    }

    *nRes = k;
}

// Sort terms by exponent descending (optional but makes result look better)
void sortPoly(int poly[MAX_TERMS][2], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (poly[i][0] < poly[j][0]) {
                int tempExp = poly[i][0];
                int tempCoef = poly[i][1];
                poly[i][0] = poly[j][0];
                poly[i][1] = poly[j][1];
                poly[j][0] = tempExp;
                poly[j][1] = tempCoef;
            }
        }
    }
}

// Print the final polynomial
void printPoly(int poly[MAX_TERMS][2], int n) {
    for (int i = 0; i < n; i++) {
        if (poly[i][1] == 0) continue;  // Skip zero coefficients
        if (i > 0) printf(" + ");
        if (poly[i][0] == 0) {
            printf("%d", poly[i][1]);  // Constant term
        } else {
            printf("%dx^%d", poly[i][1], poly[i][0]);
        }
    }
    printf("\n");
}

int main() {
    int p1[MAX_TERMS][2], p2[MAX_TERMS][2], result[MAX_TERMS][2];
    int n1, n2, nRes;

    printf("Enter First Polynomial:\n");
    inputPoly(p1, &n1);

    printf("\nEnter Second Polynomial:\n");
    inputPoly(p2, &n2);

    addPolynomials(p1, n1, p2, n2, result, &nRes);
    sortPoly(result, nRes);

    printf("\nResultant Polynomial after Addition: ");
    printPoly(result, nRes);

    return 0;
}

