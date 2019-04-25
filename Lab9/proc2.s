        .data
str1: .asciiz "Greater than\n"
str2: .asciiz "Less than or equal to\n"

	.text
	
	addi $s0, $zero, -15   # opcode 8 01000 00 000  10000 1111 1111 1111 0001 
				#            2  0    1    0   f     f    f     1
	
	li $v0, 5	#read value from user
	syscall
	move $s1, $v0	

	# Tps 2 part 2
	slt $t0, $s0, $s1     # 000 00 10 000 1 0001 0100 0 000 00 10 1010
			      #   0 2 1 1 4 0 2a		
	
	# Tps 2 part 3
	beq $t0, $zero, LEEQ # 001 00 01 000 0 0000 0000 0000 0000 0110
				#     11000006
	
	# Tps 2 part 4
	j GRT                #    000 1000 00 01 00 00 00 00 00 00 00 00 01 11
				# 0 8 1 0 0 0 0 7

GRT:	li $v0, 4             #address is 0x0040001c
	la $a0, str1 
	syscall 	
	j END

LEEQ:	li $v0, 4 
	la $a0, str2 
	syscall 	
	j END
			
END:	li $v0, 10		
	syscall

