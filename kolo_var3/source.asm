.CODE

; ECX <- a
; EDX <- b
; R8D <- c
; R9 <- *d
zad1_asm PROC
	mov eax, edx
	imul eax, eax
	mov ebx, ecx
	shl ebx, 2
	imul ebx, r8d
	sub eax, ebx
	mov dword ptr [r9], eax
	ret
zad1_asm ENDP

; ecx <- a
; edx <- b
; r8 <- *i
zad2_asm PROC
	inc edx
	mov eax, edx
	cdq
	idiv ecx
	mov dword ptr [r8], eax
	ret
zad2_asm ENDP

; ECX <- a
; EDX <- b
zad3_asm PROC USES RBX
	movsxd rcx, ecx
	movsxd rdx, edx

	mov rax, rcx
	mov rbx, rdx
	cmp rcx, rdx
	cmovl rax, rdx
	cmovl rbx, rcx
	sub rax, rbx
	ret
zad3_asm ENDP

; rcx <- a1
; rdx <- b1
; r8 <- a2
; r9 <- b2
; stack a3, b3
zad4_asm PROC dummy_a1:qword, dummy_b1:qword, dummy_a2:qword, dummy_b2:qword, a3:qword, b3:qword
	imul rcx, rdx
	mov rax, rcx
	imul r8, r9
	add rax, r8
	mov r10, a3
	imul r10, b3
	add rax, r10
	ret
zad4_asm ENDP

; RCX <- int**
; EDX <- uint n
; R8D <- uint m
zad5_asm PROC
	movsxd rdx, edx
	mov r8, rdx
	mov r9, r8
_loop_n:
	mov r10, r9
	mov r11, qword ptr [rcx+8*rdx-8]
	_loop_m:
		cmp r10, rdx
		jng _skip
		mov dword ptr [r11+4*r10-4], 0
		_skip:
		dec r10
		jnz _loop_m
	dec rdx
	jnz _loop_n
	ret
zad5_asm ENDP

END
