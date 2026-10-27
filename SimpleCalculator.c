
#include <stdio.h>

int main()
{
    double num1, num2, result;
    char operator;

    printf("Enter first number: ");
    scanf("%lf", &num1);

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &operator);

    printf("Enter second number: ");
    scanf("%lf", &num2);

    switch (operator)
    {
        case '+':
            result = num1 + num2;
            break;

        case '-':
            result = num1 - num2;
            break;

        case '*':
            result = num1 * num2;
            break;

        case '/':
            if (num2 == 0)
            {
                printf("Error: Division by zero.\n");
                return 0;
            }
            result = num1 / num2;
            break;
            

        default:
            printf("Invalid operator.\n");
            return 0;
    }

    printf("Result: %.2lf\n", result);

    return 0;
}