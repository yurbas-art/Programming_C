#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* add_spaces(const char* s) {
    int length = strlen(s);
    char* result = (char*)malloc((2 * length + 1) * sizeof(char));
    int j = 0;

    for (int i = 0; i < length; i++) {
        if (s[i] == '+' || s[i] == '-') {
            result[j++] = ' ';
            result[j++] = s[i];
            result[j++] = ' ';
        } else {
            result[j++] = s[i];
        }
    }
    result[j] = '\0';
    return result;
}

double add(double a, double b) {
    return a + b;
}

double diff(double a, double b) {
    return a - b;
}

double unary_minus(double number) {
    return -number;
}

int main() {
    char expression[50];
    char *expression1;
    double result = 0;
    char *ch;
    
    printf("Введите арифметическое выражение: ");
    fgets(expression, 50, stdin);
    expression1 = add_spaces(expression);
    double operand = 0;

    double (*operation)(double, double) = NULL;
    ch = strtok(expression1, " ");
    while (ch != NULL) {
        if (strcmp(ch, "+") == 0) {
            operation = add;
        } else if (strcmp(ch, "-") == 0) {
            operation = diff;
        } else {
            double number = atof(ch);

            if (ch[0] == '-' && isdigit(ch[1])) {
                number = unary_minus(number);
            }

            if (operation != NULL) {
                operand = operation(operand, number);
                operation = NULL;
            } else {
                operand = number;
            }
        }
        ch = strtok(NULL, " ");
    }

    printf("Результат: %.2f\n", operand);

    return 0;
    
}
