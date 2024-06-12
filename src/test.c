#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "libmenu.h"

int main(void) {
    /* Menu pseudo-object */
    Menu catMenu;

    /* MenuItem array filled with items, later to be referenced by Menu */
    MenuItem cats[] = {{"Badem"}, {"Lokum"}, {"Waffle"}, {""}}; 

    /* Initializes the menu by calculating Menu.len and setting default index,
    then references the passed items to the Menu */
    initMenu(&catMenu, cats);

    /* If you would like to change the default starting index, use initMenui() */
    // initMenui(&catMenu, cats); 

    /* Simple loop to print the menu dialog and handle arrow key inputs */
    MenuIndex returned_index = menuLoop(&catMenu); 
        
    /* When user selects the menu option either by pressing Enter or q (to quit),
    the last selected MenuIndex is returned by menuLoop() and also set inside Menu object */
    printf("Selected index: %d\nSelected item: %s\n\n", 
            catMenu.index,      catMenu.items[catMenu.index].name);
    printf("Returned index: %d\nSelected item: %s\n\n", 
            returned_index,     catMenu.items[catMenu.index].name);
}