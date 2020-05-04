	.arch msp430g2553

	.data 			;next is a static variable
n:
	.word 1 		;storecs the beginning case
	.align 2
	
	.text			;Jump Table will be stored
jt:
	.word default	  	;default case j[0]
	.word option1		;turn on LED green and red go to the next case jt[1]
	.word option2		;turn on LED red only go to next case jt[2]
	.word option3		;turn off both LEDS jt[3]
	.word option4		;turn on LED red jt[4]

	.text
	;; now we are going to run the selector
	.global stateBegin	

stateBegin:
	cmp #5, &n		;comparison to check within the range
	jc default		;jump if there is a no carry

	;; find the index we go to
	mov &n, r12		;store into a register
	add r12, r12		;double the source so we can go to correct location
	mov jt(r12), r0		;move the selected place in jt to program counter

default:
	jmp end			;go directly to our out method
option1:	
	mov.b #1, &green_on;turns on our green LED                
	mov.b #1, &red_on  ;turns on our red LED
	mov #2, &n		;puts a new value to our next value
	jmp end		;to end 

option2:
	mov.b #0, &green_on	;turns off our green LED
	mov #3, &n		;indicates our next state
	jmp end			;break

option3:
	mov.b #0, &red_on			;turn off red LED 
	mov #4, &n		;indicate the next state
	jmp end			;break
	
option4:
	mov.b #1, &red_on	;turn on red led
	mov #1, &n		;now we go back to first state to repeat
	jmp end			;break
	
end:
	pop r0			;follow the program counter
