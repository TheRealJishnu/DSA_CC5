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
    while (expr[i] != NULL) {
        if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/' || expr[i] == '^') {
            if (tos == -1) {
                push(expr[i++]);
            }
            else{
                if (priority(expr[i] > priority(pop()))) {
                    push(expr[i++]);
                }
                else {
                    while (tos != -1) {
                        output[j++] = pop();
                    }
                }
            }
        }
        else {
            expr[i++] = output[j++];
        }
        //i++;
        //j++;
    }

    while (tos != -1) {
        output[i] = pop();
    }

    printf("Postfix is ");
    int k = 0;
    while (output[k] != NULL) {
        printf("%c ", output[k++]);
    }

    
}
