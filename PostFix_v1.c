#include <stdio.h>
#include <stdlib.h>

char *expr, *output, *stack;
int tos = -1;
int size;

char pop(){
    if (tos == -1) {
        printf("Stack Underflow\t\t ↓↓↓↓↓\n");
        return;
    }
    else {
        return stack[tos--];
    }
}

void push(char ch){
    if (tos == size -1){
        printf("Stack Overflow\t\t ↑↑↑↑↑\n");
        return;
    }
    else {

        stack[++tos] = ch;
    }
}

int peek(){
    if(tos == -1) {
        printf("Stack is Empty  :(\n");
        return;
    }
    else {
        return stack[tos];
    }
}

int priority (char a) {
    switch (a)
    {
    case '+':
    case '-':
        return 1;
        break;
    case '*':
    case '/':
        return 2;
        break;
    case '^':
        return 3;
        break;
    default:
        break;
    }
}

int main() {
    printf("Enter Maximum Size of Expression");
    scanf("%d", &size);
    expr = (char*)malloc((size+5) * sizeof(char));
    output = (char*)malloc((size+5) * sizeof(char));
    stack = (char*)malloc((size+5) * sizeof(char));
    printf("Enter Expression Without Space: ");
    scanf("%s", expr);


    //Real Work
    int i = 0, j = 0;
    while (expr[i] != '\0') {
        if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/' || expr[i] == '^') {
            if (tos == -1) {
                push(expr[i]);
                i++;
            }
            else{
                if (priority(expr[i] > priority(peek()))) {
                    push(expr[i]);
                    i++;
                }
                else {
                    while (priority(expr[i] <= priority(peek()))) {
                        output[j] = pop();
                        j++;
                    }
                }
            }
        }
        else {
            output[j]=expr[i];
            j++;
            i++;
            //output[j++]=expr[i++] ;
        }
        //i++;
        //j++;
    }

    while (tos != -1) {
        output[j] = pop();
        j++;
    }

    printf("Postfix is ");
    int k = 0;
    while (output[k] != '\0') {
        printf("%c ", output[k]);
        k++;
    }


}
