#include <windows.h>
#include <process.h>
#include <io.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

void exit_func(void)
{
  printf("Exit function called\n\n");
  printf("Close Window to return to program... It will beep if able to read from file");
}

int main(void)
{
  int fd;
  char c;

  if ((fd = open("_cexit.c",O_RDONLY)) < 0)
  {
	printf("Unable to open _cexit.c for reading\n");
	return 1;
  }
  atexit(exit_func);
  if (read(fd,&c,1) != 1)

printf("Unable to read from open file handle %d before _cexit\n",fd);
  else
	printf("Successfully read from open file handle %d before _cexit\n",fd);
  _cexit();
  if (read(fd,&c,1) == 1)
	  MessageBeep(0);
  return 0;
}
