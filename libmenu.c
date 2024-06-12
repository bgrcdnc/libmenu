#include "libmenu.h"
#include "utils.h"
#include <termios.h>
#include <stdio.h>

static struct termios old, current;

/* Initialize new terminal i/o settings */
void initTermios(int echo)
{
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  current = old; /* make new settings same as old settings */
  current.c_lflag &= ~ICANON; /* disable buffered i/o */
  if (echo) {
      current.c_lflag |= ECHO; /* set echo mode */
  } else {
      current.c_lflag &= ~ECHO; /* set no echo mode */
  }
  tcsetattr(0, TCSANOW, &current); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void)
{
  tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo)
{
  char ch;
  initTermios(echo);
  ch = (char)getchar();
  resetTermios();
  return ch;
}

/* Read 1 character without echo */
char getch(void)
{
  return getch_(0);
}

/* Read 1 character with echo */
char getche(void)
{
  return getch_(1);
}

#define CLSLINE "                                    "

#define KEY_ENTER 10
#define KEY_CONS_COMM 27
#define KEY_CONS_COMM_PREF 91
#define KEY_UP 65
#define KEY_DOWN 66
#define KEY_RIGHT 67
#define KEY_LEFT 68
#define KEY_QUIT 113

void printMenu(menuItemLen len, menuItems *items, menuIndex index) {
    gotoxy(0,0);
    for(size_t i = 0; i < len; i++) {
        printf(RESET"%s\r", CLSLINE);
        if(i == index) printf(BWHT FBLK "*");
        printf("%s\n"RESET, items[i]);
    }
}

int menuLoop(menuItemLen len, menuItems *items, menuIndex *index) {
    clear();
    int loop = TRUE, ch, c1, c2;
    while(loop > FALSE) {
        printMenu(len, items, (*index));
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
                    (*index)--;
                    if((*index) < 0) (*index) = ((int)len-1);
                    break;
                case KEY_DOWN:
                    (*index)++;
                    if((*index) > ((int)len-1)) (*index) = 0;
                    break;
                }
            }
            break;
        }
    }
    return 0;
}
