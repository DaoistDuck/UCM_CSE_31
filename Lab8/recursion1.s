  
        .data
        str1:      .asciiz "Please enter a number "
        
        .text
        
main:		
		addi $sp, $sp, -4	# Moving stack pointer to make room for storing local variables (push the stack frame)
		# TPS 2 #3 (display statement)
		la  $a0, str1
		li $v0, 4
		syscall
		
		# TPS 2 #4 (read user input)
		li $v0, 5
		syscall
		move $a0, $v0
		
		jal recursion	# Call recursion(x)
		
		# TPS 2 #6 (read user input)
		move $a0, $v0
		li $v0, 1
		syscall
		
		j end		# Jump to end of program

recursion:	
		addi $sp, $sp, -12
		
		sw $ra, 0($sp)
		
		addi $t0, $zero, 10
		
		bne $a0, $t0, not_ten
		
		addi $v0, $zero, 2
		
		j end_recur
		
not_ten:	
		addi $t1, $zero, 11
		bne $a0, $t1, not_eleven
		addi $v0, $zero, 1
		
		j end_recur
		
not_eleven:	
		sw $a0, 4($sp)
		addi $a0, $a0, 2
		
		jal recursion
		
		sw $v0 , 8($sp)
		
		lw $a0, 4($sp)
		addi $a0, $a0, 1
		
		jal recursion
		
		lw $t2, 4($sp)
		lw $t3, 8($sp)
		
		add $v0, $v0, $t2
		add $v0, $v0, $t3
		
		j end_recur
		
end_recur:	
		lw $ra , 0($sp)		
		addi $sp, $sp, 12	
		jr $ra
		
		
end:		
		addi $sp, $sp, 4
		li $v0, 10
		syscall
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		