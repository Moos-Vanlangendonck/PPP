section .data
    hello db 'Hello, World!', 0

section .text
    global _start

_start:
    mov rax, 1          ; syscall: write
    mov rdi, 1          ; file descriptor: stdout
    mov rsi, hello      ; pointer to message
    mov rdx, 13         ; message length
    syscall              ; call kernel

    mov rax, 60         ; syscall: exit
    xor rdi, rdi        ; exit code 0
    syscall              ; call kernel
