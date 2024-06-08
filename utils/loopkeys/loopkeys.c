#include "../../src/conio.h"
#include <stdio.h>

int main(void) {
    while(1) {
        char c = getch();
        printf("%c : %d\n", c, c);
    }
}
