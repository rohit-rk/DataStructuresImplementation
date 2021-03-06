#include <stdio.h>
#define MAXSIZE 5
struct stack
{
    int stk[MAXSIZE];
    int top;
};
typedef struct stack STACK;
STACK s;
void push(void);
int  pop(void);
void display(void);
void main ()
{
    int choice;
    int option = 1;
    s.top = -1;

    printf("\t\t\t\tSTACK OPERATION\n");
    while (option)
    {
        printf("\n");
        printf("1-->PUSH\n");
        printf("2-->POP\n");
        printf("3-->DISPLAY\n");
        printf("\n");

        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            system("clear");
            printf("\t\t\t\tSTACK OPERATION\n");
            push();
            break;
        case 2:
            system("clear");
            printf("\t\t\t\tSTACK OPERATION\n");
            pop();
            break;
        case 3:
            system("clear");
            printf("\t\t\t\tSTACK OPERATION\n");
            display();
            break;
        case 4:
            system("clear");
            printf("\t\t\t\tSTACK OPERATION\n");
            return;
        }

    }
}
void push ()
{
    int num;
    if (s.top == (MAXSIZE - 1))
    {
        printf("Stack is Full\n");
        return;
    }
    else
    {
        printf("Enter the element to be pushed\n");
        scanf("%d", &num);
        s.top = s.top + 1;
        s.stk[s.top]=num;
    }
    return;
}
int pop ()
{
    int num;
    if (s.top == - 1)
    {
        printf("Stack is Empty\n");
        return (s.top);
    }
    else
    {
        num = s.stk[s.top];
        printf("poped element is = %d", s.stk[s.top]);
        s.top = s.top - 1;
    }
    return(num);
}
void display ()
{
    int i;
    if (s.top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    else
    {
        printf("\n The status of the stack is \n");
        for (i = s.top; i >= 0; i--)
        {
            printf("%d\n", s.stk[i]);
        }
    }
    printf("\n");
}
