#include <fcntl.h>
#include <string.h>
#include <unistd.h>

char password[] = "zvcjxwvydfmyjyhl";
// char flag[0x100];

int main() {
  int fd = open("/proc/pwncollege", O_RDWR);

  write(fd, password, strlen(password));
  // read(fd, flag, 0x100);
  // write(STDOUT_FILENO, flag, 0x100);

  return 0;
}
