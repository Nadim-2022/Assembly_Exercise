"push { r4, lr } \n" // we need to save return address because we call another subroutine
"mov r4, r0 \n"
"loop: \n"
"ldrb r0, [r4]\n" // load the byte and increment the pointer
"cmp r0, #0\n" // check for null terminator
"beq end\n" // if null terminator, end
"cmp r0, #0x41 \n" // check for 'A'
"blt notAlpha\n" // if less than 'A', not 'A'
"cmp r0, #0x5A \n" // check for 'Z'
"ble Alpha\n" // if greater than 'Z', not 'A'
"cmp r0, #0x61 \n" // check for 'a'
"blt notAlpha\n" // if less than 'a', not 'A'
"cmp r0, #0x7A \n" // check for 'z'
"bgt Alpha\n" // if greater than 'z', not 'A'
"Alpha: \n"
"add r0, r0, #13\n" // increment the character
"cmp r0, #0x7A \n" // check for 'z'
"bgt outOffScope\n" // if less than 'z', not 'A'
"cmp r0, #0x5A\n" // check for 'Z'
"bgt outOffScope\n" // if less than 'Z', not 'A'
"add r4, r4, #1\n"
"bl putchar\n"
"b loop\n" // loop
"outOffScope: \n"
"sub r0, r0, #26\n" // if greater than 'z', subtract 26
"add r4, r4, #1\n"
"bl putchar\n"
"notAlpha: \n"
"bl putchar\n" // call putchar
"add r4, r4, #1\n" // increment the pointer
"b loop\n" // loop
"end: \n"
"bx lr\n" // return
"pop { r4, pc } \n" // cortex-M0 requires popping to PC if LR was pushed
// popping to PC will cause return from subroutine (~same as "bx lr")
);