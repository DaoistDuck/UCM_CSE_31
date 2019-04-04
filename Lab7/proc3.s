		.data
x:		.word 5
y:		.word 10

		.text
MAIN:	
		la $t0, x
		lw $s0, 0($t0)	# s0 = x
		la $t0, y
		lw $s1, 0($t0) 	# s1 = y
		
		add $a0, $zero, $s0	# Set a0 as input argument for SUM is m
		add $a1, $zero, $s1     # a1 = n
		jal SUM
		
		add $t0, $s0, $s1
		add $s1, $t0, $v0
		addi $a0, $s1, 0
		li $v0, 1		 
		syscall	
		j END



SUM:		
		addi $sp, $sp -16 #push stack frame to local storage
		sw $ra, 0($sp)		
		sw $a0, 4($sp)    #back up p
		sw $a1, 8($sp)    #back up q
		move $t0, $a1
		addi $a1, $a0, 1  #a1 is n so its n+1
		addi $a0, $t0, 1  #a0 is m so its m+1	 
			
		jal SUB
		
		sw $v0, 12($sp)   #back up return value to 12
		
		lw $a0, 4($sp)   #get back value from before
		lw $a1, 8($sp)
		sub $a0, $a0, 1  #now we subtract 1;
		sub $a1, $a1, 1
		
		jal SUB          #v0 is equal to q #v0
		
		lw $t0, 12($sp)
		add $v0, $t0, $v0
		
		
		lw $ra , 0($sp)		
		addi $sp, $sp, 16	# Pop stack frame 
		jr $ra
	


SUB:
		sub $v0, $a1, $a0
		jr $ra
		



END: