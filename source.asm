.CODE

; ecx <- int a
; edx <- int b
; r8d <- int c
zad1_asm PROC
	mov eax, ecx        ; eax <- a
	cmp ecx, edx        ; compare a and b
	cmovg eax, edx      ; if a>b : eax <- b
	cmp eax, r8d        ; compare min(a,b) and c
	cmovg eax, r8d      ; if min(a,b)>c : eax <- c
	movsxd rax, eax     ; sign-extend eaxt to rax
	ret
zad1_asm ENDP

; ecx <- int a
; edx <- int b
; r8d <- int c
; r9d <- int i
; [rsp + 40] <- x
zad2_asm PROC
	xor rax, rax
	cmp r9d, 10
	je _10
	cmp r9d, 11
	je _11
	cmp r9d, 12
	je _12
	jmp _end
_10:
    mov rax, rcx                        ; rax <- a
    imul rax, qword ptr [rsp + 40]      ; rax <- a*x
    add rax, rdx                        ; rax <- a*x+b
    add rax, r8                         ; rax <- a*x+b+c
    add rax, r9                         ; rax <- a*x+b+i
    jmp _end

_11:
    mov     rax, rdx                  ; rax <- b
    mov     rbx, r9                   ; rbx <- i
    imul    rbx, 200                  ; rbx <- i * 200
    sub     rax, rbx                  ; rax <- b - (i * 200)

    mov     rbx, rcx                  ; rbx <- a
    shl     rbx, 1                    ; rbx <- a * 2
    imul    rbx, qword ptr [rsp + 40] ; rbx <- a * 2 * x
    inc     rbx                       ; rbx <- a * 2 * x + 1
    cqo                               ; sign-extend rax  rdx:rax
    idiv    rbx                       ; rax <- rax/rbx
    jmp     _end

_12:
    mov     rax, qword ptr [rsp + 40] ; rax <- x
    imul    rax, rax                  ; rax <- x^2
    imul    rax, rcx                  ; rax <- x^2 * a

    mov     rbx, r8                   ; rbx <- c
    shl     rbx, 2                    ; rbx <- c * 4
    sub     rax, rbx                  ; rax <- rax - (c * 4)
    jmp     _end

_end:
    ret
zad2_asm ENDP

; RCX <- int* vec
; EDX <_ uint n
zad3_asm PROC
    movsxd rdx, edx
    mov r9, rdx             ; r9 <- n
    xor rbx, rbx            ; rbx <- 0
_loop:
    movsxd rax, dword ptr [rcx+4*r9-4]   ; rax <- vec[i]
    sar rax, 1              ; CF = bit 0
    jnc _skip               
    inc rbx                 ; if CF=1 rbx++
    _skip:          
    dec r9                  ; n--
    jnz _loop

    mov rax, rbx
    ret
zad3_asm ENDP

; rcx <- INT64* a
; rdx <- INT64* b
; r8d <- uint n
zad4_asm PROC USES RSI RDI
    movsxd r8, r8d
_loop:
    mov rax, qword ptr [rcx+8*r8-8]
    mov rbx, qword ptr [rdx+8*r8-8]
    imul rbx, 7
    add rax, rbx
    mov qword ptr [rcx+8*r8-8], rax
    dec r8
    jnz _loop
    ret
zad4_asm ENDP

; rcx <- int** A
; edx <- uint n
; r8d <- uint m
zad5_asm PROC
    movsxd r9, edx
    movsxd r8, r8d
    cmp rdx, r8
    cmovg rdx, r8
_loop:
    mov rbx, qword ptr [rcx+8*r9-8]
    mov eax, dword ptr [rbx+4*r9-4]
    shr eax, 1
    mov dword ptr [rbx+4*r9-4], eax
    dec r9
    jnz _loop
    ret 
zad5_asm ENDP

END