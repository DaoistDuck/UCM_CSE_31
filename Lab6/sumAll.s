.data
str1:      .asciiz "Please enter a number "
str2:      .asciiz "Sum of positive numbers is "
str3:      .asciiz "Sum of negative numbers is "
str4:      .asciiz "\n"
.text

main: 
	#loading the str file
	la  $a0, str1
	li $v0, 4
	syscall

	#storing user input

	li $v0, 5
	syscall
	move $s1, $v0
	
	#conditions where $s1 will go	
	bgtz $s1, POS
	bltz $s1, NEG
	beq $s1, $zero, END
	move $s3, $zero
	move $s4, $zero

POS:
	move $s5, $s3
	add $s3, $s1, $s5
	
	j main
	
NEG:
	move $s6,$s4
	add $s4, $s1, $s6
	j main

END:
	la $a0, str2
	li $v0, 4
	syscall
	la $a0, ($s3)
	li $v0, 1
	syscall
	
	la $a0, str4
	li $v0, 4
	syscall
	
	la $a0, str3
	li $v0, 4
	syscall
	la $a0, ($s4)
	li $v0, 1
	syscall
