#include "calc.h"
void display(char *s) {
    char input[255];
    char d[100];
    char e[100];
    char *endptr;
    double a, c, res = 0, check  =0;
    char b;
    bool ansExists = false;
    double ansValue = 0;

  FILE *file = fopen("ans.txt", "r");
  if (file != NULL)
  {
    fscanf(file, "%lf", &ansValue);
    fclose(file);
    if (ansValue != 0)
    {
        ansExists = true;
    }
    }

    while (1) {
        system("clear");
        printf(">> ");

        fgets(input, sizeof(input), stdin);

        if (input[0] == 'E' && input[1] == 'X' && input[2] == 'I' && input[3] == 'T') {
            break;
        }
        if (sscanf(input, "%s %c %s", d, &b, e) != 3) {
            printf("SYNTAX ERROR\n");
            check = 1;
        }
        a = strtod(d, &endptr);
        if (strcmp("ANS", d) == 0 && (check != 1)) {
            a = ansValue;
        }
        else if (*endptr != '\0' && (check != 1)) {
        printf("SYNTAX ERROR\n");
            check = 1;

        }
        if ((errno == ERANGE)
        || (errno != 0 && a == 0) && (check != 1)) {
            printf("SYNTAX ERROR\n");
            check = 1;
        }
        c = strtod(e, &endptr);
        if (strcmp("ANS", e) == 0 && (check != 1)) {
            c = ansValue;
        }
        else if (*endptr != '\0' && (check != 1)) {
        printf("SYNTAX ERROR\n");
            check = 1;
        }
        if ((errno == ERANGE)
        || (errno != 0 && a == 0) && (check != 1)) {
            printf("SYNTAX ERROR\n");
            check = 1;
        }
        if (!((b == '+') || (b == '*') || (b == '-') || (b == '/') || (b == '%')) && (check != 1)) {
            printf("SYNTAX ERROR\n");
            check = 1;
        }
        if( check != 1) {
            switch (b) {
                case '+':
                    res = a + c;
                    printf("%.2lf\n", res);
                    break;
                case '-':
                    res = a - c;
                    printf("%.2lf\n", res);
                    break;
                case '*':
                    res = a * c;
                    printf("%.2lf\n", res);
                    break;
                case '/':
                    if (c == 0) {
                        printf("MATH ERROR\n");
                    }else{
                    res = a / c;
                    printf("%.2lf\n", res);
                    }
                    break;
                case '%':
                    if (c == 0) {
                        printf("MATH ERROR\n");
                    }else{
                    res = (int)a % (int)c;
                    printf("%.2lf\n", res);
                    }
                    break;
                default:
                    continue;
            }
            ansExists = true;
            ansValue = res;
            file = fopen("ans.txt", "w");
            if (file != NULL) {
                fprintf(file, "%.2lf", ansValue);
                fclose(file);
            }
        }
        check = 0;
        printf("Press Enter to continue\n");
        scanf("%c", &b);
        continue;
    }
    return ;
}
