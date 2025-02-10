section .data
    a db 15               
    b db 10               

section .text
    global _start

_start:
    mov rdi, a            
    imul rsi, 1           
    and al, [b]           
    mov [result], al      

result:
    mov rdi, result
    call printf

    jmp exit_program

exit_program:
    mov rax, 60
    xor rdi, rdi
    syscall
