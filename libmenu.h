#include <termios.h>
#include <stdio.h>

#define FALSE (0)
#define TRUE (1)
#define SELECTED -1

#define menuGetLen(x) sizeof(x) / sizeof(x[0]);

typedef char* menuItems;
typedef size_t menuItemLen;
typedef int menuIndex; 

void initTermios(int); /* Initialize new terminal i/o settings */
void resetTermios(void); /* Restore old terminal i/o settings */
char getch_(int); /* Read 1 character - echo defines echo mode */
char getch(void); /* Read 1 character without echo */
char getche(void); /* Read 1 character with echo */
void printMenu(menuItemLen, menuItems*, menuIndex); /* Prints the supplied menuItems*/
int menuLoop(menuItemLen, menuItems*, menuIndex*); /* Iterates through the menuItems until one is selected*/