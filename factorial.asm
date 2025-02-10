section .data
    prompt db 'Enter a number: ', 0
    result_msg db 'Factorial: ', 0

section .bss
    num resb 1         
    fact resb 10       

section .text
    extern printf, scanf
    global main

main:
    lea rdi, [prompt]
    call printf

    lea rsi, [num]
    call scanf

    movzx rdi, byte [num] ; Convert char to integer
    call factorial

    lea rdi, [result_msg]
    call printf
    mov rdi, rax
    call printf

    mov rax, 60
    xor rdi, rdi
    syscall

factorial:
    cmp rdi, 1          
    jle .exit           
    push rdi            
    dec rdi             
    call factorial      
    pop rdi             
    imul rax, rdi       
.exit:
    ret
