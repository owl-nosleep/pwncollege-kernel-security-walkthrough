#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define FLAG_LENGTH 0x100

char password[] = "spdsyrdgiowkyntw";
char flag[FLAG_LENGTH];

int main() {

  int fd = open("/proc/pwncollege", O_RDWR);

  write(fd, password, strlen(password));
  read(fd, flag, FLAG_LENGTH);
  write(STDOUT_FILENO, flag, FLAG_LENGTH);

  return 0;
}
