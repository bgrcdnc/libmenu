#include <termios.h>
#include <stdio.h>

void initTermios(int); /* Initialize new terminal i/o settings */
void resetTermios(void); /* Restore old terminal i/o settings */
char getch_(int); /* Read 1 character - echo defines echo mode */
char getch(void); /* Read 1 character without echo */
char getche(void); /* Read 1 character with echo */

//Useful commands for console
#define console_command(x) printf("\x1B[%dm", x)
#define gotoxy(x, y) printf("%c[%d;%df",0x1B,y,x)
#define clear() printf("\033[H\033[J")

#define FB_COLORS 1
#define FBLK   "\x1B[30m"
#define FRED   "\x1B[31m"
#define FGRN   "\x1B[32m"
#define FYEL   "\x1B[33m"
#define FBLU   "\x1B[34m"
#define FMAG   "\x1B[35m"
#define FCYN   "\x1B[36m"
#define FWHT   "\x1B[37m"
#define BBLK   "\x1B[40m" 
#define BRED   "\x1B[41m"
#define BGRN   "\x1B[42m"
#define BYEL   "\x1B[43m"
#define BBLU   "\x1B[44m"
#define BMAG   "\x1B[45m"
#define BCYN   "\x1B[46m"
#define BWHT   "\x1B[47m"
#define BOLD   "\x1B[1m"
#define RESET  "\x1B[0m"


//String manipulation commands
// Flip the 5th position of the char using XOR operator
#define convert_case(c)    c^(1<<5)

// Set the 5th position of the char
#define to_lower(c)        c|(1<<5)

// clear the 5th position of the char
#define to_upper(c)        c&~(1<<5)