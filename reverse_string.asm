section .data
    prompt db 'Enter a string: ', 0
    result_msg db 'Reversed string: ', 0

section .bss
    str resb 256        
    str_reverse resb 256   
    len resb 1          

section .text
    extern printf, scanf
    global _start

_start:
    lea rdi, [prompt]
    call printf

    lea rsi, [str]
    lea rdx, [len]
    call scanf

    mov rsi, str
    mov rdi, str_reverse
    mov rcx, rdx         
    sub rcx, 1           
loop_reverse:
    movzx rax, byte [rsi + rcx] 
    mov [rdi + rcx], rax    
    dec rcx                
    jge loop_reverse

    lea rdi, [result_msg]
    call printf
    mov rdi, str_reverse
    call printf

    mov rax, 60
    xor rdi, rdi
    syscall
