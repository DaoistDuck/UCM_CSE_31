.data 
str0: .asciiz "Welcome to BobCat Candy, home to the famous BobCat Bars! \n"
str1: .asciiz "Please enter the price of a BobCat Bar: \n"
str2: .asciiz "Please enter the number of wrappers needed to exchange for a new bar: \n"
str3: .asciiz "How, how much do you have? \n"
str4: .asciiz "Good! Let me run the number ... \n"
str5: .asciiz "You first buy "
str6: .asciiz "Then, you will get another "
str7: .asciiz " bars.\n"
str8: .asciiz "With $"
str9: .asciiz ", you will receive a maximum of "
str10: .asciiz " BobCat Bars!"
# Declare any necessary data here



.text

main:
		#This is the main program.
		#It first asks user to enter the price of each BobCat Bar.
		#It then asks user to enter the number of bar wrappers needed to exchange for a new bar.
		#It then asks user to enter how much money he/she has.
		#It then calls maxBars function to perform calculation of the maximum BobCat Bars the user will receive based on the information entered. 
		#It then prints out a statement about the maximum BobCat Bars the user will receive.
		
		
		addi $sp, $sp -20	# Feel free to change the increment if you need for space.
		sw $ra, 0($sp)
		# Implement your main here
		
		#introduces the user to BobCat Candy
		la  $a0, str0
		li $v0, 4
		syscall
		
		#askes the user for the price of a BobCat Bar
		la  $a0, str1
		li $v0, 4
		syscall
		
		#stores the user input in t0
		li $v0, 5
		syscall
		move $t0, $v0
		
		#askes the user for the exchange rate of wrapper to get a new bar
		la  $a0, str2
		li $v0, 4
		syscall
		
		#stores the user input in a1
		li $v0, 5
		syscall
		move $t1, $v0
		
		#askes the user for how much money they have for a BobCat Bar
		la  $a0, str3
		li $v0, 4
		syscall
		
		#stores the user input in a2
		li $v0, 5
		syscall
		move $t2, $v0
		
		#tells the user that the code is running the numbers
		la  $a0, str4
		li $v0, 4
		syscall
		
		move $a0, $t0
		move $a1, $t1
		move $a2, $t2	
		
		move $s6, $zero		
		
		jal maxBars 	# Call maxBars to calculate the maximum number of BobCat Bars

		# Print out final statement here
		
		#tells user with the amount of money
		la  $a0, str8
		li $v0, 4
		syscall
		
		#displaying the money they have
		li $v0, 1
		move $a0, $a2
		syscall
		
		#almost finishes the sentence
		la  $a0, str9
		li $v0, 4
		syscall
		
		#displaying amount of candy 
		li $v0, 1
		move $a0, $s6
		syscall
		
		# finishes the sentence
		la  $a0, str10
		li $v0, 4
		syscall	
		



		j end			# Jump to end of program



maxBars:
		# This function calculates the maximum number of BobCat Bars.
		# It takes in 3 arguments ($a0, $a1, $a2) as n, price, and money. It returns the maximum number of bars
		
		#a0 is the price of BobCat Bar
		
		#a1 is the exchange rate
		
		#a2 is the money they have	
		sw $ra, 12($sp)	
		move $s0, $a0
		move $s1, $a1
		move $s2, $a2
		
		blt $s2, $s0, amountOfBars
		
		
		div $s3, $s2, $s0		
		
		#intro max candy amount
		la  $a0, str5
		li $v0, 4
		syscall
		
		#number of bars you can buy right now
		li $v0, 1
		move $a0, $s3
		syscall
		
		#finishes it out
		la  $a0, str7
		li $v0, 4
		syscall		
		
		add $s6, $s6, $s3	
				
		move $a0, $s1
		move $a1, $s3
		
		jal newBars 	# Call a helper function to keep track of the number of bars.
		
		jr $ra
		
		# End of maxBars
		
newBars: #while $s4 > $a0
		# This function calculates the number of BobCat Bars a user will receive based on n.
		# It takes in 2 arguments ($a0, $a1) as number of wrappers left so far and n.
		
	
		#s3 is the inital amount of BobCat bars you start withs
		sw $a0, 4($sp)
		sw $ra, 8($sp)
		
		div $s4, $a1, $a0	
		
		
		beq $s4, $zero, amountOfBars			
		#intro exchange amount
		la  $a0, str6
		li $v0, 4
		syscall
		
		#number of bars you can exchange right now
		li $v0, 1
		move $a0, $s4
		syscall
		
		#finishes it out
		la  $a0, str7
		li $v0, 4
		syscall		
		
		add $s6, $s6, $s4
		
		lw $a0, 4($sp)
		move $a1, $s4
		
		
		j newBars
		
		
		
		jr $ra
		
		# End of newBars				

amountOfBars:
		lw $ra, 12($sp)
		jr $ra		
end: 
		# Terminating the program
		lw $ra, 0($sp)
		addi $sp, $sp 20
		li $v0, 10 
		syscall
