#include <fcntl.h>
#include <string.h>
#include <unistd.h>

char password[] = "mwzzvrrouvgtskoz";

int main() {
  int fd = open("/proc/pwncollege", O_RDWR);

  write(fd, password, strlen(password));

  return 0;
}
