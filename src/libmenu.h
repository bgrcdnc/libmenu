#include <stddef.h>

typedef struct {
    char name[80];
} MenuItem; /*typedef for the items kept in a Menu*/

typedef size_t MenuItemsLen; /*typedef for the items length in a Menu*/

typedef int MenuIndex; /*typedef for the current index in a Menu*/

typedef struct {
    MenuItem *items;
    MenuItemsLen len;
    MenuIndex index;
} Menu;

int initMenui(Menu*, MenuItem[], int index);
int initMenu(Menu*, MenuItem[]);
int menuLoop(Menu*); /* Iterates through the menuItems until one is selected*/