# Simple exit program
.section __DATA,__data
str:
    .asciz "Hello World!\n"
.section __TEXT,__text
.globl _main
_main:
    movl $0x2000004, %eax           # preparing system call 4 
    movl $1, %edi                   # STDOUT file descriptor is 1
    movq str@GOTPCREL(%rip), %rsi   # The value to print
    movq $100, %rdx                 # The size of the value to print
    syscall

    #movl $0x2000001, %eax  # system call $1 with $x2000000 offset
    movl $0, %ebx          # set the exit code to $0
    syscall
