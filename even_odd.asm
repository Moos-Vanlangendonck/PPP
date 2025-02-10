section .data
    even_msg db 'The number is even.', 0
    odd_msg db 'The number is odd.', 0
    prompt db 'Enter a number: ', 0
    number db 0

section .text
    global _start

_start:
    mov rax, 1
    mov rdi, 1
    mov rsi, prompt
    mov rdx, 17
    syscall

    ; Read number
    mov rax, 0          
    mov rdi, 0          
    mov rsi, number     
    mov rdx, 1          
    syscall

    movzx rax, byte [number]
    and rax, 1          
    cmp rax, 0
    je is_even
    jmp is_odd

is_even:
    mov rax, 1
    mov rdi, 1
    mov rsi, even_msg
    mov rdx, 23
    syscall
    jmp exit_program

is_odd:
    mov rax, 1
    mov rdi, 1
    mov rsi, odd_msg
    mov rdx, 21
    syscall

exit_program:
    mov rax, 60         
    xor rdi, rdi        
    syscall
