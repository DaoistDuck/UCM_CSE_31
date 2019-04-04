.data
n:       .word 25
str1:      .asciiz "Less than\n"
str2:      .asciiz "Less than or equal to\n"
str3:      .asciiz "Greater than\n"
str4:      .asciiz "Greater than or equal to\n"

.text

#load n to $s0 some register
la $t0, n
lw $s0, 0($t0) #loading address from n to $s0

# store user input in $s1
li $v0, 5
syscall
move $s1, $v0

# s1 < s0
#slt $t0, $s1, $s0 

#check if $t0 is NOT $zero (s1 < s0)
#bne $t0, $zero, LESS

#if t0 is $zero(s1 >= s0
#beq $t0, $zero, GREATER

slt $t0, $s0, $s1

bne $t0, $zero, GREATERTHAN

beq $t0, $zero, LESSTHAN


LESS:
	la $a0, str1
	li $v0, 4
	syscall
	j END


GREATER:
	la  $a0, str4
	li $v0, 4
	syscall
	j END
	
GREATERTHAN:
	la $a0, str3
	li $v0, 4
	syscall
	j END
	

LESSTHAN:
	la $a0, str2
	li $v0, 4
	syscall
	j END
	
END:
	li $v0, 10
	syscall
	
	
	
	
	
	
	
	
	
	
	