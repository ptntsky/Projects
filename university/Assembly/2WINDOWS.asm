bits 64
default rel

segment .data
prompt    db "Введіть числа a та b: ", 0
fin      db "%lf %lf", 0
fout_max db "Максимум: %f", 10, 0
f_out_eq  db "Числа рівні: %f", 10, 0
a         dq 0.0
b         dq 0.0
max_val   dq 0.0

segment .text
extern printf, scanf, ExitProcess
global main

main:
    sub rsp, 40          

    lea rcx, [prompt]   
    call printf

    lea rcx, [f_in]     
    lea rdx, [a]       
    lea r8, [b]         
    call scanf

    movsd xmm0, [a]
    movsd xmm1, [b]

    ucomisd xmm0, xmm1
    je .equal

    maxsd xmm0, xmm1
    movsd [max_val], xmm0
    
    lea rcx, [fout_max]
    movq rdx, xmm0      
    movaps xmm1, xmm0   
    call printf
    jmp .exit

.equal:
    movsd [max_val], xmm0
    lea rcx, [fout_eq]
    movq rdx, xmm0
    call printf

.exit:
    xor ecx, ecx
    call ExitProcess
    add rsp, 40
    ret
