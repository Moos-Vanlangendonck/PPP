section .data
    a db 15               

section .text
    global _start

_start:
    mov rdi, a            
    not al                
    mov [result], al      

result:
    mov rdi, result
    call printf

    jmp exit_program

exit_program:
    mov rax, 60
    xor rdi, rdi
    syscall
