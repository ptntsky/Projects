extern printf, scanf

section .data
    fin  db "%lf %lf", 0
    fout db "Результат: A = %lf, B = %lf", 10, 0
    prompt  db "Введіть два числа (A та B): ", 0

section .bss
    a resq 1 
    b resq 1 

section .text
    global main

main:
    push rbp
    mov rbp, rsp

    mov rdi, prompt
    xor rax, rax       
    call printf

    mov rdi, fin
    mov rsi, a         
    mov rdx, b         
    xor rax, rax
    call scanf

 
    movsd xmm0, [a]    
    movsd xmm1, [b]    

    ucomisd xmm0, xmm1 
    je .equal          

 
    maxsd xmm0, xmm1  
    movsd xmm1, xmm0   
    jmp .output

.equal:
    xorpd xmm0, xmm0   
    xorpd xmm1, xmm1  

.output:
  
    mov rdi, fout
    mov rax, 2        
    call printf

    leave
    ret
