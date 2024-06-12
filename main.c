#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "libmenu.h"
#include "utils.h"

int main(void) {
    Menu catMenu;
    MenuItem cats[] = {{"Badem"}, {"Lokum"}, {"Waffle"}, {""}};
    if(!initMenu(&catMenu, cats)) return SIG_ERR;
    menuLoop(&catMenu);
    printf("Selected index: %d\nSelected item: %s\n\n", catMenu.index, catMenu.items[catMenu.index].name);
}