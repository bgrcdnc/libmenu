#include <stdio.h>
#include <stdlib.h>
#include "conio.h"

#define ENTER 10
#define CONS_COMM 27
#define CONS_COMM_PREF 91
#define UP 65
#define DOWN 66
#define RIGHT 67
#define LEFT 68
#define QUIT 113
#define CLSLINE "                                    "

void printMenu(const size_t menuItemCount, char** menuItems, int index) {
    gotoxy(0,0);
    for(int i = 0; i < menuItemCount; i++) {
        printf(RESET"%s\r", CLSLINE);
        if(i == index) printf(BWHT FBLK "*");
        printf("%s\n"RESET, menuItems[i]);
    }
    printf("\n(q)uit (enter)select :");
}

int main(void) {
    //loopkeys();
    clear();
    char *menuItems[] = {"test1", "test2", "test3"};
    const size_t menuItemCount = sizeof(menuItems) / sizeof(menuItems[0]);
    int menuIndex = 0;

    int q = 1;
    while(q > 0) {
        printMenu(menuItemCount, menuItems, menuIndex);
        switch((int)getch()) {
        case QUIT:
        case to_upper(QUIT):
            q = 0;
            break;
        case ENTER:
            q = -1;
        case CONS_COMM:
            int c1, c2;
            c1 = (int)getch();
            c2 = (int)getch();
            if(c1 == CONS_COMM_PREF) {
                switch(c2) {
                case UP:
                    menuIndex--;
                    if(menuIndex < 0) menuIndex = menuItemCount-1;
                    break;
                case DOWN:
                    menuIndex++;
                    if(menuIndex > menuItemCount-1) menuIndex = 0;
                    break;
                }
            }
            break;
        }
    
    }
    if(q<0) {
        printf("\nSelected: %d", menuIndex);
    }
    return 0;
}
