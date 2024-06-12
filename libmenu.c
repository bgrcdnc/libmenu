#include "libmenu.h"
#include "utils.h"
#include <stdio.h>
#include <signal.h>

#define CLSLINE "                                    "
#define FALSE (0)
#define TRUE (1)
#define SELECTED -1
#define KEY_ENTER 10
#define KEY_CONS_COMM 27
#define KEY_CONS_COMM_PREF 91
#define KEY_UP 65
#define KEY_DOWN 66
#define KEY_RIGHT 67
#define KEY_LEFT 68
#define KEY_QUIT 113

size_t menuGetLen(MenuItem items[]) {
    size_t len = 0;
    while (items[len].name[0] != '\0') {
        len++;
    }
    return len;
}

int initMenui(Menu *menu, MenuItem items[], int index)
{
    if(menu == NULL) return SIGSEGV;

    menu->items = items;
    menu->len = menuGetLen(items);
    menu->index = index;
    printf("len:'%lu'\nindex:'%d'", menu->len, menu->index);
    return 0;
}

int initMenu(Menu *menu, MenuItem items[]) {
    return initMenui(menu, items, 0);
}

void printMenu(Menu *menu) {
    gotoxy(0,0);
    for(MenuIndex i = 0; i < (MenuIndex)menu->len; i++) {
        printf(RESET"%s\r", CLSLINE);
        if(i == menu->index) printf(BWHT FBLK "*");
        printf("%s\n"RESET, menu->items[i].name);
    }
}

int menuLoop(Menu *menu) {
    clear();
    int loop = TRUE, ch, c1, c2;
    while(loop > FALSE) {
        printMenu(menu);
        ch = (int)getch();
        switch(ch) {
        case KEY_QUIT:
        case to_upper(KEY_QUIT):
            loop = FALSE;
            break;
        case KEY_ENTER:
            loop = SELECTED;
            break;
        case KEY_CONS_COMM:
            c1 = (int)getch();
            c2 = (int)getch();
            if(c1 == KEY_CONS_COMM_PREF) {
                switch(c2) {
                case KEY_UP:
                    menu->index++;
                    if(menu->index < 0) menu->index = ((int)menu->len-1);
                    break;
                case KEY_DOWN:
                    menu->index++;
                    if(menu->index > ((int)menu->len-1)) menu->index = 0;
                    break;
                }
            }
            break;
        }
    }
    return 0;
}
