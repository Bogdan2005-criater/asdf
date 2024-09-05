//Реализовать программу 3-го практического задания более эффективным способом со сложностью О(n) (см. код в лекции).
//Пример №1
//Данные на вход:
//don't_panic
//nick_is_a_mastodon
//Данные на выход: 3
//Пример №2
//Данные на вход:
//monty_python
//python_has_list_comprehensions
//Данные на выход: 6

#include <stdio.h>
#include <string.h>

void calculateZ(char *str, int Z[]) {
    int n = strlen(str);
    int L, R, K;
    L = R = 0;
    for (int i = 1; i < n; ++i) {
        if (i > R) {
            L = R = i;
            while (R < n && str[R] == str[R - L])
                R++;
            Z[i] = R - L;
            R--;
        } else {
            K = i - L;
            if (Z[K] < R - i + 1)
                Z[i] = Z[K];
            else {
                L = i;
                while (R < n && str[R] == str[R - L])
                    R++;
                Z[i] = R - L;
                R--;
            }
        }
    }
}

int main() {
    char str1[MAX], str2[MAX];
    printf("Введите первую строку: ");
    scanf("%s", str1);
    printf("Введите вторую строку: ");
    scanf("%s", str2);

    int n1 = strlen(str1);
    int n2 = strlen(str2);
    
    char combined[MAX];
    snprintf(combined, sizeof(combined), "%s#%s", str2, str1);
    
    int Z[MAX] = {0};
    calculateZ(combined, Z);

    int maxMatch = 0;
    for (int i = n2 + 1; i < n1 + n2 + 1; i++) {
        if (Z[i] > maxMatch) {
            maxMatch = Z[i];
        }
    }

    printf("Максимальная длина совпадения: %d\n", maxMatch);
    return 0;
}
