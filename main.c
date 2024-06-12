#include <stdio.h>
#include <stdlib.h>
#include "libmenu.h"

int main(void) {
    menuItems items[] = {"Badem", "Lokum", "Waffle"};
    menuItemLen c = menuGetLen(items);
    menuIndex i = 0;
    menuLoop(c, items, &i);
    printf("Selected index: %d\nSelected item: %s\n\n", i, items[i]);
}