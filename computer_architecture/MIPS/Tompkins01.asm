# Palindrome Checker | Nathan Tompkins	#
# Computer Architecture | 04.15.19	#
.eqv NRBYTES 1024

.data

# Prompt to print to the user
.align 2 
prompt:		.asciiz "Please enter a string: "

# String/array to hold user's input
.align 2 
usrString:	.space NRBYTES	

.align 2
palindrome:	.space NRBYTES

.align 2
palindromeNoSpaces: .space NRBYTES

.align 2
cleanUsr:	.space NRBYTES

.align 2
length:		.word 0

.align 2
isPalindrome:	.asciiz " is a palindrome."

.align 2
isntPalindrome:	.asciiz " is not a palindrome."

.text

# Main function of the program
main:
	# Get input from user
	jal input
	
	# Cleanup
	jal cleanString
	
	# Check for palindrome
	jal palindromeCheck
	
	move $a0, $v0
	li $v0, 1
	syscall
	
	# End program
	j end
	
# User Input Function
input:
	# Print prompt
	la $a0, prompt
	li $v0, 4
	syscall

	# Get input string
	li $a1, 1024
	li $v0, 8
	la $a0, usrString 
	syscall
	
	la $s0, palindrome
	lb $t0, 0($s0)
	beq $t0, 10, end
	la $s1, palindromeNoSpaces
	lw $s3, length	
	
	# Return to main
	jr $ra

# Clean the user string
cleanString:
	la $s0, usrString
	
cleanStringLoop:
	lb $a0, 0($s0)
	addi $s0, $s0, 1
	# Check for space
	beq $a0, 32, cleanStringLoop
	# Check for enter
	beq $a0, 10, cleanStringLoop
	# Check for end of string
	beq $a0, $zero, cleanStringReturn
	
	# Save the current byte
	sb $a0, ($s1)
	addi $s1, $s1, 1
	addi $s3, $s3, 1
	j cleanStringLoop
	
cleanStringReturn:
	sub $s1, $s1, $s3
	jr $ra


# Palindrome process function
palindromeCheck:
	li $0, 0
	li $t2, 1
	li $v0, 1
	div $t3, $s3, 2
	addi $t3, $t3, 1

palindromeLoop:
	bge $t2, $t3, palindromeTrue
	add $t1, $t0, $s1
	lb $t4, ($t1)
	
	sub $t5, $s3, $t2
	add $t6, $t5, $s1
	lb $t7, ($t6)

checkShifted:
	bgt $t4, 96, shiftLeft
	bgt $t7, 96, shiftRight
	
	beq $t4, $t7, palindromeContinue
	li $v0, 0
	j palindromeFalse

palindromeContinue:
	# Shift pointer 
	addi $a0, $a0, 1
	# Increment counter value
	addi $t2, $t2, 1
	# Return to loop
	j palindromeLoop

palindromeTrue:
	la $a0, usrString
	li $v0, 4
	syscall
	
	jal printString
	
	la $a0, isPalindrome
	li $v0, 4
	syscall

palindromeFalse:
	la $a0, usrString
	li $v0, 4
	syscall
	
palindromeReturn:
	# Load return address
	lw $ra, 0($sp)
	# Clear stack
	addi $sp, $sp, 8
	# Return
	jr $ra

	
	jal printString
	
	la $a0, isntPalindrome
	li $v0, 4
	syscall
	j end

shiftLeft:
	subi $t4, $t4, 32
	j checkShifted

shiftRight:
	subi $t7, $t4, 32
	j checkShifted		
	
# Length counter function beginning
lengthStart: 
	# Clear $v0 to begin
	li $v0, 0
	
# Count usrString characters
lengthLoop:
	# Load the first/next letter into $t0
	lb $t0, 0($a0)
	# If the the current letter is \0, jump to return
	beq $t0, $0, lengthReturn
	# Move pointer one byte right
	addi $a0, $a0, 1
	# Increment return value
	addi $v0, $v0, 1
	# Run loop again
	j lengthLoop

# Return to main
lengthReturn: 
	sw $t0, length
	jr $ra

printString:
	la $a0, usrString
	li $v0, 4
	syscall
	
	jr $ra
	
# End the program
end:
	li $v0, 10
	syscall
