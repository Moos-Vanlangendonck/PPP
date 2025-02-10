section .data
    filename db 'numbers.txt', 0
    num_fmt db "%d", 0

section .text
    extern fopen, fprintf, fclose
    global _start

_start:
    ; Open file
    lea rdi, [filename]
    mov rsi, 'w'               
    call fopen

    ; Writing numbers
    mov rax, 1                 
.write_loop:
    cmp rax, 11
    jge .close_file
    push rax                   
    lea rsi, [num_fmt]
    call fprintf               
