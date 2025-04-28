#include <stdio.h>
#include <stdlib.h>

struct stack 
{
    int data;
    struct stack *next;
};

struct stack *top = NULL;

struct stack *push(struct stack *, int);
struct stack *display(struct stack *);
struct stack *pop(struct stack *);
int peek(struct stack *);

int main()
{
    int val, option;
    do 
    {
        printf("\n***** MAIN MENU *****");
        printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. PEEK");
        printf("\n4. DISPLAY");
        printf("\n5. EXIT");
        printf("\nEnter your option: ");
        scanf("%d", &option);
        
        switch(option)
        {
            case 1:
                printf("\nEnter the number to be pushed on the stack: ");
                scanf("%d", &val);
                top = push(top, val);
                break;
            case 2:
                top = pop(top);
                break;
            case 3:
                val = peek(top);
                if(val != -1)
                    printf("\nThe value at the top of the stack is %d", val);
                else
                    printf("\nStack is empty");
                break;
            case 4:
                top = display(top);
                break;
            case 5:
                printf("\nExiting...");
                break;
            default:
                printf("\nInvalid choice");
        }
    } while(option != 5);

    return 0;
}

struct stack *push(struct stack *top, int val)
{
    struct stack *ptr;
    ptr = (struct stack *)malloc(sizeof(struct stack));
    if(ptr == NULL)
    {
        printf("\nMemory not allocated.");
        return top;
    }
    ptr->data = val;
    ptr->next = top;
    top = ptr;
    return top;
}

struct stack *display(struct stack *top)
{
    struct stack *ptr;
    ptr = top;
    if(top == NULL)
        printf("\nStack is empty");
    else
    {
        printf("\nStack elements are:");
        while(ptr != NULL)
        {
            printf("\n%d", ptr->data);
            ptr = ptr->next;
        }
    }
    return top;
}

struct stack *pop(struct stack *top)
{
    struct stack *ptr;
    if(top == NULL)
    {
        printf("\nStack is empty");
    }
    else
    {
        ptr = top;
        printf("\nThe value being deleted is %d", ptr->data);
        top = top->next;
        free(ptr);
    }
    return top;
}

int peek(struct stack *top)
{
    if(top == NULL)
        return -1;
    else 
        return top->data;
}
