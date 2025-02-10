section .data
    arr db 10, 20, 30, 40, 50  
    len equ ($ - arr) - 1       

section .text
    global _start

_start:
    mov rsi, arr
    lea rdi, [rsi + 1]
    movzx rax, byte [rdi]
    mov rdi, rax
    call printf

    jmp exit_program

exit_program:
    mov rax, 60
    xor rdi, rdi
    syscall
