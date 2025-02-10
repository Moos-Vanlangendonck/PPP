section .data
    a db -15               

section .text
    global _start

_start:
    ; Perform bitwise arithmetic shift right (SAR)
    mov cl, 2            
    sar ax, cl           
    mov [result], ax

result:
    mov rdi, result
    call printf

jmp exit_program

exit_program:
mov rax, 60    
xor rdi, rdi    
syscall
