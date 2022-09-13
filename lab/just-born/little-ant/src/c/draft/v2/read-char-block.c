#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

static struct termios _c7dcd41c_oldt, _c7dcd41c_newt;

void reset_terminal(int _)
{
  (void)_;
  tcsetattr(STDIN_FILENO, TCSANOW, &_c7dcd41c_oldt);
}

char read_char_block(int dummy)
{
  signal(SIGINT, reset_terminal);
  char ch;
  tcgetattr( STDIN_FILENO, &_c7dcd41c_oldt );
  _c7dcd41c_newt = _c7dcd41c_oldt;
  _c7dcd41c_newt.c_lflag &= ~( ICANON | ECHO );
  tcsetattr( STDIN_FILENO, TCSANOW, &_c7dcd41c_newt );
  ch = getchar();
  reset_terminal(0);
  return ch;
}

