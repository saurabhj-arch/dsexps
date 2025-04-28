#include <stdio.h>
#define SIZE 10

void push(int);
void pop();
void display();
void peek();

int stack[SIZE], top = -1;

void main() {
    int value, choice;

    do {
        printf("\n\n***** MENU *****\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Peek\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
        }
    } while (choice != 5);
}

void push(int value) {
    if (top == SIZE - 1)
        printf("\nStack is Full!!! Insertion is not possible!!!");
    else {
        top++;
        stack[top] = value;
        printf("\nInsertion success!!!");
    }
}

void pop() {
    if (top == -1)
        printf("\nStack is Empty!!! Deletion is not possible!!!");
    else {
        printf("\nDeleted : %d", stack[top]);
        top--;
    }
}

void peek() {
    if (top == -1)
        printf("\nStack is Empty!!!");
    else
        printf("\nStack top is %d", stack[top]);
}

void display() {
    if (top == -1)
        printf("\nStack is Empty!!!");
    else {
        int i;
        printf("\nStack elements are:\n");
        for (i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}

