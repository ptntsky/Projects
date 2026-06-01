Extern printf, scanf

section .data
    msg_a     db "Введіть a: ", 0
    msg_x     db "Введіть числа (літера для стопу): ", 0
    fmt_in    db "%lf", 0
    fmt_out   db 10, "Результат: %d", 10, 0
    zero      dq 0.0

section .bss
    a    resq 1
    temp resq 1

section .text
    global main

main:
    push rbp
    mov rbp, rsp
    sub rsp, 16

    mov rdi, msg_a
    xor rax, rax
    call printf

    mov rdi, fmt_in
    lea rsi, [a]
    xor rax, rax
    call scanf

    mov rdi, msg_x
    xor rax, rax
    call printf

    xor r12, r12

.loop:
    mov rdi, fmt_in
    lea rsi, [temp]
    xor rax, rax
    call scanf
    
    cmp rax, 1
    jne .print_res

    movsd xmm0, [temp]
    movsd xmm1, [zero]
    movsd xmm2, [a]

    ucomisd xmm0, xmm1
    jae .loop

    ucomisd xmm0, xmm2
    jbe .loop

    inc r12
    jmp .loop

.print_res:
    mov rdi, fmt_out
    mov rsi, r12
    xor rax, rax
    call printf

    add rsp, 16
    pop rbp
    xor rax, rax
    ret
