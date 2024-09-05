//Написать алгоритм перевода из инфиксной записи в обратную польскую. Для его реализации нужны данные по приоритетам операций. Реализовать алгоритм, используя побитовые операции (&, |, ^).

//Пример №1
//Данные на вход: ( 3 & 5 ) ^ 4 | 9
//Данные на выход: 3 5 & 4 ^ 9 |

//Пример №2
//Данные на вход: 8 ^ 2 & 5 | ( 6 & 1 )
//Данные на выход: 8 2 5 & ^ 6 1 & |

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int precedence(char op) {
    if (op == '&') return 1;
    if (op == '^') return 2;
    if (op == '|') return 3;
    return 0;
}

void infixToPostfix(char* expression) {
    char stack[MAX];
    int top = -1;
    int i, k = 0;
    char output[MAX];

    for (i = 0; i < strlen(expression); i++) {
        if (isdigit(expression[i])) {
            output[k++] = expression[i];
        } else if (expression[i] == '(') {
            stack[++top] = expression[i]; 
        } else if (expression[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                output[k++] = stack[top--];
            }
            top--; // Удаление '(' из стека
        } else if (expression[i] == '&' || expression[i] == '|' || expression[i] == '^') {
            while (top != -1 && precedence(stack[top]) <= precedence(expression[i])) {
                output[k++] = stack[top--]; 
            }
            stack[++top] = expression[i]; 
        }
    }

    while (top != -1) {
        output[k++] = stack[top--];
    }

    output[k] = '\0'; 
    printf("Обратная польская запись: %s\n", output);
}

int main() {
    char expression[MAX];
    printf("Введите выражение: ");
    fgets(expression, MAX, stdin);
    infixToPostfix(expression);
    return 0;
}
