#include <stdio.h>
// #include<conio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100
char st[MAX];
int top = -1;

int getP(char op)
{
    if (op == '*' || op == '/' || op == '%')
        return 1;
    else if (op == '+' || op == '-')
        return 0;
}

void push(char st[], char val)
{
    if (top == (MAX - 1))
        printf("\n STACK OVERFLOW!");
    else
    {
        top++;
        st[top] = val;
    }
} 

char pop(char st[])
{
    char val = ' ';
    if (top == -1)
        printf("\n STACK UNDERFLOW!");
    else
    {
        val = st[top];
        top--;
    }
    return val;
}

void InfixToPostfix(char src[], char tgt[])
{
    char temp;
    int i = 0, j = 0;
    strcpy(tgt, "");
    while (src[i] != '\0')
    {
        if (src[i] == '(') // src[i] represents the scanned operand from the infix expression
        {
            push(st, src[i]);
            i++;
        }
        else if (src[i] == ')')
        {
            while ((top != -1) && (st[top] != '('))
            {
                tgt[j] = pop(st);
                j++;
            }
            if (top == -1)
            {
                printf("\n Incorrect Expression");
                // exit(1); 
                break;
            }
            temp = pop(st); // remove ')'
            i++;
        }
        else if (isdigit(src[i]) || isalpha(src[i]))
        {
            tgt[j] = src[i];
            j++;
            i++;
        }
        else if (src[i] == '+' || src[i] == '-' || src[i] == '*' || src[i] == '/' || src[i] == '%')
        {
            while ((top != -1) && (st[top] != '(') && (getP(st[top]) > getP(src[i])))
            {
                tgt[j] = pop(st); // when we scan a lower priority operator, we pop the higher priority operator from the stack
                j++;
            }
            push(st, src[i]);
            i++;
        }
        else
        {
            printf("\n Incorrect Element in Expression");
            // exit(1);
            break;
        }
    }
    while ((top != -1) && (st[top] != '('))
    {
        tgt[j] = pop(st);
        j++;
    }
    tgt[j] = '\0';
}

int main()
{
    char in[MAX], po[MAX];
    // clrscr();
    printf("\n Enter the infix expression : ");
    gets(in);
    strcpy(po, "");
    InfixToPostfix(in, po);
    printf("\n The correspoding postfix expresion : ");
    puts(po);
    // getch();
    return 0;
}

// A-(B/C+(D%E*F)/G)*H