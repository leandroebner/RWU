/* strldr_asm.asm 23.8.2023						*/

/* X1 = address/pointer = 0x7ffffff334 (could differ) */

        .global  strldr_asm

strldr_asm:
	MOV X6,X0
	MOV X7,X1                /* Address for storing the value; tabe address from X1 */
	ADD X7,X7,#8             /* ... and add 8. (X7=0x7ffffff33c) */
	MOV X9,#0x8              /* Could act as an address offset */
	/* do your work*/
	STR X8,[X1]              /* Write the stored/read value to the variable pointer */
	MOV X0,#0
	BR LR
