#include <stdio.h>
#include <stdlib.h>

typedef struct term {
    int coeff;
    int expo;
    struct term *next;
} TERM;

// Function to insert at the end
void insertend(TERM **p, int c, int e) {
    TERM *temp = (TERM *)malloc(sizeof(TERM));
    temp->coeff = c;
    temp->expo = e;
    temp->next = NULL;

    if (*p == NULL) {
        *p = temp;
    } else {
        TERM *t = *p;
        while (t->next != NULL) {
            t = t->next;
        }
        t->next = temp;
    }
}

// Function to display a polynomial
void display(TERM *p) {
    if (p == NULL) {
        printf("0");
        return;
    }
    while (p != NULL) {
        printf("%dx^%d", p->coeff, p->expo);
        p = p->next;
        if (p != NULL) printf(" + ");
    }
    printf("\n");
}

// Function to add two polynomials
TERM* addPoly(TERM *p1, TERM *p2) {
    TERM *result = NULL;
    while (p1 != NULL && p2 != NULL) {
        if (p1->expo == p2->expo) {
            insertend(&result, p1->coeff + p2->coeff, p1->expo);
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->expo > p2->expo) {
            insertend(&result, p1->coeff, p1->expo);
            p1 = p1->next;
        } else {
            insertend(&result, p2->coeff, p2->expo);
            p2 = p2->next;
        }
    }
    // Add remaining terms
    while (p1 != NULL) {
        insertend(&result, p1->coeff, p1->expo);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        insertend(&result, p2->coeff, p2->expo);
        p2 = p2->next;
    }
    return result;
}

int main() {
    TERM *poly1 = NULL, *poly2 = NULL, *sum = NULL;
    int n, coeff, expo;

    // First polynomial
    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &coeff, &expo);
        insertend(&poly1, coeff, expo);
    }

    // Second polynomial
    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &coeff, &expo);
        insertend(&poly2, coeff, expo);
    }

    printf("\nFirst Polynomial: ");
    display(poly1);

    printf("Second Polynomial: ");
    display(poly2);

    // Addition
    sum = addPoly(poly1, poly2);

    printf("\nSum of Polynomials: ");
    display(sum);

    return 0;
}
