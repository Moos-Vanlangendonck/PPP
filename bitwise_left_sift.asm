section .data
    a db 15               

section .text
    global _start

_start:
    mov cl, 2            
    shl al, cl           
    mov [result], al      

result:
    mov rdi, result
    call printf

    jmp exit_program

exit_program:
    mov rax, 60
    xor rdi, rdi
    syscall
