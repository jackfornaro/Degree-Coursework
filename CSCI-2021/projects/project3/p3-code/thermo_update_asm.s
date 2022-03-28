### Begin with functions/executable code in the assmebly file via '.text' directive
.text
.global  set_temp_from_ports

## ENTRY POINT FOR REQUIRED FUNCTION
set_temp_from_ports:
.MAIN:
        ## assembly instructions here
        movq    $0, %rax                        ##%rax = 0
        movw    THERMO_SENSOR_PORT(%rip), %ax   ##THERMO_SENSOR_PORT = %ax
        cmpw    $64000, %ax                     ##if(THERMO_SENSOR_PORT > 64000)
        ja      .RETURN1                        ##jump to Error case

        cqto                                    ##Prepare for division
        movl    $64, %esi                       ##%esi = 64
        idivl   %esi                            ##%ax / %esi
        cmpl    $31, %edx                       ##if(rem > 31) (%edx = rem)
        jg      .ADD1                           ##jump to .ADD1 case

.N1:
        subl    $500, %eax                      ##tempTemp = tempTemp - 500;
        movb    THERMO_STATUS_PORT(%rip), %cl   ##THERMO_STATUS_PORT = %cl
        andb    $1, %cl                         ##if(THERMO_STATUS_PORT & mask)
        je      .CELSIUS
        jmp     .FAHRENHEIT

.END:
        movl    $0, %eax                        ##%eax = 0
        ret

.ADD1:
        addl    $1, %eax                        ##%eax = %eax + 1
        jmp     .N1

.FAHRENHEIT:
        imull   $90, %eax                       ##%eax = %eax * 90
        cltq                                    ##Prepare for division
        cqto                                    ##Prepare for division
        movl    $50, %esi                       ##%esi = 50
        idivl   %esi                            ##%eax / %edx
        addl    $320, %eax                      ##%eax = %eax + 320

        movl    %eax, 0(%edi)                   ##temp->is_fahrenheit = 1
        movb    $1, 2(%edi)                     ##temp->tenths_degrees = (tempTemp*90) / 50 + 320
        jmp     .END

.CELSIUS:
        movl    %eax, 0(%edi)                   ##temp->is_fahrenheit = 0
        movb    $0, 2(%edi)                     ##temp->tenths_degrees = tempTemp
        jmp     .END

.RETURN1:
        movl    $1, %eax                        ##%eax = 1
        ret

        ## a useful technique for this problem
        ##movX    SOME_GLOBAL_VAR(%rip), %reg  # load global variable into register
                                             ## use movl / movq / movw / movb
                                             ## and appropriately sized destination register

### Change to definint semi-global variables used with the next function
### via the '.data' directive
.data

##my_int:                         # declare location an single integer named 'my_int'
##        .int 1234               # value 1234

d:
        .int 0

my_array:                       #maskArray[10]
        .int 0b1111110          #zero
        .int 0b0001100          #one
        .int 0b0110111          #two
        .int 0b0011111          #three
        .int 0b1001101          #four
        .int 0b1011011          #five
        .int 0b1111011          #six
        .int 0b0001110          #seven
        .int 0b1111111          #eight
        .int 0b1011111          #nine

                                # each are spaced by 4 bytes

### Change back to defining functions/execurable instructions
.text
.global  set_display_from_temp

## ENTRY POINT FOR REQUIRED FUNCTION
set_display_from_temp:
        ## assembly instructions here
.MAIN2:
        movq    $0, %rax              ##%rax = 0
        movl    $0, (%esi)            ##(%esi) = 0
        shll    $31, (%esi)           ##*display = 0

        movl    %edi, %ecx
        andl    $0xFFFF, %ecx         ##ecx = temp.tenths_degrees

        movl    %ecx, %eax
        cwtl                          ##converting word to long
        cltq                          ##converting long to quad
        movq    %rax, %rcx

        movq    $0, %rax

        sarl    $16, %edi          ##Getting temp.is_fahrenheit by shifting 16 bits in
        andl    $0xFF, %edi        ##edi = temp.is_fahrenheit

        cmpl    $0, %edi           ##if(temp.is_fahrenheit < 0)
        jl      .ERROR_RET1
        cmpl    $0, %edi           ##if(temp.is_fahrenheit = 0)
        je      .TESTC
        jmp     .NEXT1

.NEXT1:
        cmpl    $1, %edi            ##if(temp.is_fahrenheit > 1)
        jg      .ERROR_RET1
        cmpl    $1, %edi            ##if(temp.is_fahrenheit = 1)
        je      .TESTF
        jmp     .N2

.N2:
        movq    %rcx, %rax          ##temp.tenths_degrees = iterator

.N3:
        ##system that returns the digit of the _______'s place (tens, ones, etc)
        cqto                       ##Prepare for division
        movq    $10, %r11
        idivq   %r11               ##iterator / %r11
        movq    %rdx, %r8          ##temp_tenths, iterator = iterator / 10
        cmpq    $0, %r8            ##(*)If the value is negative, temp_tenths will come back negative
                                   ##We must make this value positive, so jump to .MAKEPOSITIVEr8
        jl      .MAKEPOSITIVEr8

.B1:
        cqto
        movq    $10, %r11
        idivq   %r11               ##iterator / %r11
        movq    %rdx, %r9          ##temp_ones
        cmpq    $0, %r9            ##(*)
        jl      .MAKEPOSITIVEr9

.B2:
        cqto
        movq    $10, %r11
        idivq   %r11               ##iterator / %r11
        movq    %rdx, %r10         ##temp_tens
        cmpq    $0, %r10           ##(*)
        jl      .MAKEPOSITIVEr10

.B3:
        movq    %rax, %r11         ##temp_hundreds
        cmpq    $0, %r11           ##(*)
        jl      .MAKEPOSITIVEr11

.B4:
        leaq    my_array(%rip), %rax  ##Load effective address of my_array(%rip)
        cmpq    $0, %rcx              ##if(temp.tenths_degrees < 0)
        jl      .NEG_CASE
        jmp     .POS_CASE

.N4:
        movl    (%rax, %r9, 4), %edx   ##%edx = temp_ones
        shll    $7, %edx               ##%edx<<7
        orl     %edx, (%esi)           ##*display = *display | %edx

        movl    (%rax, %r8, 4), %edx   ##%edx = temp_tenths
        orl     %edx, (%esi)           ##*display = *display | %edx

        cmpl    $0, %edi               ##if(temp.is_fahrenheit == 0)
        je      .CELSIUS_CASE
        jmp     .FAHRENHEIT_CASE

.END2:
        movq    $0, %rax                ##%rax = 0
        ret

.TESTC:
        ##Ensuring temp.tenths_degrees meets the bounds when it is in celcius
        cmpq    $-500, %rcx           ##if(temp.tenths_degrees < -500)
        jl      .ERROR_RET1
        cmpq    $500, %rcx            ##if(temp.tenths_degrees > 500)
        jg      .ERROR_RET1
        jmp     .NEXT1

.TESTF:
        ##Ensuring temp.tenths_degrees meets the bounds when it is in fahrenheit
        cmpq    $-580, %rcx           ##if(temp.tenths_degrees < -580)
        jl      .ERROR_RET1
        cmpq    $1220, %rcx           ##if(temp.tenths_degrees > 1220)
        jg      .ERROR_RET1
        jmp     .N2

.NEG_CASE:
        cmpq    $0, %r11              ##if(temp_hundreds == 0)
        je      .NEG1
        jmp     .N4

.POS_CASE:
        cmpq    $0, %r11              ##if(temp_hundreds != 0)
        jne     .POS1
        jmp     .N4

.MAKEPOSITIVEr8:
        negq    %r8                  ##temp_tenths = -temp_tenths
        jmp     .B1

.MAKEPOSITIVEr9:
        negq    %r9                  ##temp_ones = -temp_ones
        jmp     .B2

.MAKEPOSITIVEr10:
        negq    %r10                 ##temp_tens = -temp_tens
        jmp     .B3

.MAKEPOSITIVEr11:
        negq    %r11                 ##temp_hundreds = -temp_hundreds
        jmp     .B4

.CELSIUS_CASE:
        movl    $0b01, %edx           ##%edx = 0b01
        shll    $28, %edx             ##%edx<<28
        orl     %edx, (%esi)          ##*display = *display | %edx
        jmp     .END2

.FAHRENHEIT_CASE:
        movl    $0b10, %edx           ##%edx = 0b10
        shll    $28, %edx             ##%edx<<28
        orl     %edx, (%esi)          ##*display = *display | %edx
        jmp     .END2

.NEG1:
        cmpq    $0, %r10              ##if(temp_tens == 0)
        je      .NEG2

        movl    $0b0000001, %edx      ##moving the negative symbol to %edx
        shll    $21, %edx             ##%edx<<21
        orl     %edx, (%esi)          ##*display = *display | %edx

        movl    (%rax, %r10, 4), %edx ##%edx = temp_tens
        shll    $14, %edx             ##%edx<<14
        orl     %edx, (%esi)          ##*display = *display | %edx
        jmp     .N4

.NEG2:
        movl    $0b0000001, %edx      ##moving the negative symbol to %edx
        shll    $14, %edx             ##%edx<<14
        orl     %edx, (%esi)          ##*display = *display | %edx
        jmp     .N4

.POS1:
        cmpq    $0, %r10              ##if(temp_tens != 0)
        jne     .POS2

        movl    (%rax, %r11, 4), %edx ##%edx = temp_hundreds
        shll    $21, %edx             ##%edx<<21
        orl     %edx, (%esi)          ##*display = *display | %edx

        jmp     .N4

.POS2:
        movl    (%rax, %r11, 4), %edx ##%edx = temp_hundreds
        shll    $21, %edx             ##%edx<<21
        orl     %edx, (%esi)          ##*display = *display | %edx

        movl    (%rax, %r10, 4), %edx ##%edx = temp_tens
        shll    $14, %edx             ##%edx<<14
        orl     %edx, (%esi)          ##*display = *display | %edx
        jmp     .N4


.ERROR_RET1:
        movq    $1, %rax              ##%rax = 1
        ret

	## two useful techniques for this problem
  ##      movl    my_int(%rip),%eax    # load my_int into register eax
  ##      leaq    my_array(%rip),%edx  # load pointer to beginning of my_array into edx


.text
.global thermo_update

## ENTRY POINT FOR REQUIRED FUNCTION
thermo_update:
	## assembly instructions here
.MAIN3:
          movq    $0, %rax
          leaq    3(%rsp), %rdi

          pushq   %rdx
          call    set_temp_from_ports

          cmpq    $1, %rax
          je      .ERROR2

          leaq    8(%rsp), %rsi

          call    set_display_from_temp

          cmpq    $1, %rax
          je      .ERROR2

          popq    %rdx
          movq    %rsi, THERMO_DISPLAY_PORT(%rip)
          ret

.ERROR2:
          movq    $1, %rax
          ret
