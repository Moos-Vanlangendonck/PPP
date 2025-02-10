section .data
    nums db 10, 20, 30, 40, 50  
    len db 5                     
    prompt db 'Average: ', 0 

section .bss
    sum resb 4                   
    avg resb 4                   

section .text
    global _start

_start:
    xor rax, rax                 
    mov rcx, [len]                   
.loop:
    cmp rcx, 0                   
    je .calculate_average          

    movzx rbx, byte [nums + rcx - 1] 
    add rax, rbx                 
    dec rcx                       
    jmp .loop                    

.calculate_average:
    movzx rbx, byte [len]        
    xor rdx, rdx                 
    mov rdx, rax                 
    xor rax, rax                 
    div rbx                       

    ; Print result
    lea rsi, [avg]
    call printf                   
    jmp exit_program

exit_program:
    mov rax, 60
    xor rdi, rdi
    syscall
