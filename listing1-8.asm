	option casemap:none
n1 = 10
maxLen = 256

	.data
titleStr byte 'Listing 1-8', 0
prompt   byte 'Enter a string: ', 0
fmtStr   byte "User entered: '%s'", n1, 0
input    byte maxLen dup (?)

	.code
	externdef printf:proc
	externdef readLine:proc

	public getTitle
getTitle proc
	lea rax, titleStr
	ret
getTitle endp

	public asmMain
asmMain proc
	sub rsp, 56 ; setup some stack for us, C++ calls into this
	lea rcx, prompt
	call printf
	
	; Ensure the input string is zero-terminated (really?)
	mov input, 0
	lea rcx, input
	mov rdx, maxLen
	call readLine

	lea rcx, fmtStr
	lea rdx, input
	call printf

	add rsp, 56
	ret
asmMain endp
	end