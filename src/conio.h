#include <termios.h>
#include <stdio.h>

#define console_command(x) printf("\x1B[%dm", x) 

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


#define gotoxy(x, y) printf("%c[%d;%df",0x1B,y,x)

#define clear() printf("\033[H\033[J")

static struct termios old, current;

// Flip the 5th position of the char using XOR operator
#define convert_case(c)    c^(1<<5)

// Set the 5th position of the char
#define to_lower(c)        c|(1<<5)

// clear the 5th position of the char
#define to_upper(c)        c&~(1<<5)

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
  ch = getchar();
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
