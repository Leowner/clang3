#include <stdio.h>

int main () {
    for (int i = 1; i <= 9; i++) {
        printf("i = %d . x =  %d . y = %d\n", i, (i - 1) / 3 + 1, (i - 1) % 3 + 1);
    }

    return 0;
}