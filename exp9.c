#include <stdio.h>
#include <ctype.h>
#define max 100

float st[max];
int top = -1;

void push(float st[], float val);
float pop(float st[]);
float evaluatePostfixExp(char exp[]);

int main()
{
    float val;
    char exp[100];

    printf("\nEnter any postfix expression: ");
    scanf("%s", exp);

    val = evaluatePostfixExp(exp);
    printf("\nValue of the postfix expression = %.2f\n", val);

    return 0;
}

float evaluatePostfixExp(char exp[])
{
    int i = 0;
    float op1, op2, value;

    while (exp[i] != '\0')
    {
        if (isdigit(exp[i]))
        {
            push(st, exp[i] - '0');  // char '5' -> int 5
        }
        else
        {
            op2 = pop(st);
            op1 = pop(st);
            switch (exp[i])
            {
                case '+':
                    value = op1 + op2;
                    break;
                case '-':
                    value = op1 - op2;
                    break;
                case '*':
                    value = op1 * op2;
                    break;
                case '/':
                    value = op1 / op2;
                    break;
                case '%':
                    value = (int)op1 % (int)op2;
                    break;
            }
            push(st, value);
        }
        i++;
    }
    return pop(st);
}

void push(float st[], float val)
{
    if (top == max - 1)
        printf("\nStack overflow");
    else
    {
        top++;
        st[top] = val;
    }
}

float pop(float st[])
{
    float val = -1;
    if (top == -1)
    {
        printf("\nStack underflow");
    }
    else
    {
        val = st[top];
        top--;
    }
    return val;
}