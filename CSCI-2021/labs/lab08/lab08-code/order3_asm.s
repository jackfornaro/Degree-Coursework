### SOLUTION
### order3_asm.s: assembly version of order3_c.c; complete the main()
### function which requires expanding the stack for local variables
### which need main memory addresses and making function calls to
### order() and printf().

.text
.globl  main
main:
        ## stack layout will be
        ## |----------+-----+------|
        ## |    Stack |     |      |
        ## | Location | C   | init |
        ## |  rsp + N | Var |  val |
        ## |----------+-----+------|
        ## |        0 | r   |   17 |
        ## |        4 | t   |   12 |
        ## |        8 | v   |   13 |
        ## |       12 | q   |    5 |
        ## |       16 | e   |    9 |
        ## |       20 | d   |    2 |
        ## |       24 | i   |   24 |
        ## |       28 | j   |   27 |
        ## |       32 | k   |   29 |
        ## |----------+-----+------|
        ## 
        ## Total space for local vars: 36 bytes (9 x 4-byte integers)
        ## Expand stand stack by 40 bytes so that additional 8 bytes of return address
        ## leaves %rsp divisible by 16 (aligned for function calls);
        ## e.g. 36b locals + 4b padding + 8b return address = 48b divisible by 16
	
        ## COMPLETE: expand stack for locals
        # expand stack for locals + alignment padding
        
        ## Sample setup for first call to order3(&r, &t, &v);
        movl    $17, 0(%rsp)           # r=17
        movl    $12, 4(%rsp)           # t=12
        movl    $13, 8(%rsp)           # v=13
        movq    %rsp, %rdi             # arg1 &r 
        leaq    4(%rsp), %rsi          # arg2 &t
        leaq    8(%rsp), %rdx          # arg3 &v
        call    order3                 # function call
        
        ## COMPLETE THIS BLOCK for order3(&q, &e, &d);
        # q=5
        # e=9
        # d=2
        # arg1 &q
        # arg2 &e
        # arg2 &d
        # function call
        
        ## COMPLETE THIS BLOCK for order3(&i, &j, &k);
        # i=24
        # j=27
        # k=29
        # arg1 &i
        # arg2 &j
        # arg2 &k
        # function call

        ## Sample setup for first printf("..",r,t,v) call
        leaq    .FORMAT1(%rip), %rdi   # arg1 .FORMAT1
        movl    (%rsp), %esi           # arg2 r
        movl    4(%rsp), %edx          # arg3 t
        movl    8(%rsp), %ecx          # arg4 v
        movl    $0, %eax               # special setup for printf
        call    printf@PLT             # function call
        
        ## COMPLETE THIS BLOCK for printf("..",q,e,d);
        # arg1 .FORMAT2
        # arg2 q
        # arg3 e                  
        # arg4 d                  
        # special setup for printf
        # function call
        
        ## COMPLETE THIS BLOCK for printf("..",i,j,k);
        # arg1 .FORMAT3
        # arg2 i
        # arg3 j                  
        # arg4 k                  
        # special setup for printf
        # function call
        
        ## COMPLETE: undo stack changes, shrink stack
        # restore the stack before returning
        
        movl    $0, %eax
        ret

.data
.FORMAT1:                       # format strings for printf calls
        .string "r t v: %2d %2d %2d\n"
.FORMAT2:
        .string "q e d: %2d %2d %2d\n"
.FORMAT3:
        .string "i j k: %2d %2d %2d\n"
        
        

.text
.globl  order3                  # THIS FUNCTION IS CORRECT: do not modify it
order3:                         # a in %rdi, b in %rsi, c in %rdx
        movl    (%rdi), %eax    # load a
        movl    (%rsi), %ecx    # load b
        cmpl    %ecx, %eax      # if *a > *b
        jle     .AB_ORDERED1    # false: don't swap
        movl    %ecx, (%rdi)    # true, swap a/b
        movl    %eax, (%rsi)
.AB_ORDERED1:
        movl    (%rsi), %eax    # load b
        movl    (%rdx), %ecx    # load c
        cmpl    %ecx, %eax      # if *b > *c
        jle     .BC_ORDERED     # false: don't swap
        movl    %ecx, (%rsi)    # true: swap b/c
        movl    %eax, (%rdx)
.BC_ORDERED:                    # c now largest, check a/b
        movl    (%rdi), %eax    # load a
        movl    (%rsi), %edx    # load b
        cmpl    %edx, %eax      # if *a > *b
        jle     .ABC_ORDERED    # false: don't swap
        movl    %edx, (%rdi)    # true: swap a/b
        movl    %eax, (%rsi)
.ABC_ORDERED:
        ret
        
