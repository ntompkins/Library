# Sieve of Eratosthenes
# Nathan Tompkins | 4.26.19

.data
	.align 2
	prompt:		.asciiz "Please enter an upper limit (max 15,000): "
	.align 2
	resultA:	.asciiz "The number of primes from 1 to "
	.align 2
	resultB:	.asciiz " is "
	
	p:		.word 2		# prime value
	maxNum:		.word 15000	# max range
	usrNum:		.word 0		# user's range
	address:	.word 0		# array address
	primeCount:	.word 0		# current prime
	primeTally:	.word 0		# total number of primes

.text
input:
	la 	$a0, prompt 		# Prompt for input
	li 	$v0, 4			
	syscall

	li 	$v0, 5			# Gets range value
	syscall
	
	sw 	$v0, usrNum		# Stores range
	lw 	$s0, maxNum		# Stores maxnum

	bgt 	$v0, $s0, input		# Loop if > 15,000
	blt 	$v0, 3, input 		# Loop if <= 3

malloc:
	subi 	$a0, $s0, 1		# Sub 1 from max value
	mul 	$a0, $a0, 4		# Multiply by 4 for array size
	li	$v0, 9			# Allocate memory
	syscall
	
	sw 	$v0, address		# Store array address

populate:
	lw 	$s1, p			# Start primes at 2
	lw 	$s0, usrNum		# Load user's range

useMalloc:
	sw 	$s1, ($v0)		# Load prime number
	addi 	$s1, $s1, 1		# Increment index
	addi 	$v0, $v0, 4		# Increase size
	ble 	$s1, $s0, useMalloc	# Loop until index > maxnum

sieveA:
	lw 	$t2, usrNum		# Load range
	li 	$a2, 4			# Load 4
	lw 	$v0, address		# Load address
	move 	$v1, $v0		# Create duplicate pointer

sieveB:
	lw 	$t1, ($v0)		# Loads prime
	addi 	$v0, $v0, 4		# Increment index
	
	bgt 	$t1, $t2, prime		# Branch when done
	beqz 	$t1, sieveB 		# Branch if zero
	
	mul 	$t3, $t1, $t1		# Square prime
	bgt 	$t3, $t2, prime		# Branch if square > range
	
	move 	$t5, $t3		# Square prime

sieveC:
	bgt 	$t5 $t2, sieveB		# Branch when done
	subi 	$a3, $t5, 2		# Subtract original prime (2)
	mul 	$a3, $a3, $a2		# Find next multiple
	add 	$a3, $a3, $v1		# Store in $t3
	sw 	$zero, ($a3)		# Overwright value with 0
	add 	$t5, $t5, $t1		# Store in $t5
	j 	sieveC			# Loop

prime:
	lw 	$v0, address		# Load address
	lw 	$s2, primeCount		# Load count
	
primeLoop:
	addi 	$s3, $s3, 1		# Increment counter
	lw 	$s1, ($v0)		# Create a duplicate
	addi 	$v0, $v0, 4		# Increment index
	
	bge  	$s3, $t2, output	# Print results when done
	
	beqz 	$s1, primeLoop		# Restart at zeros
	addi 	$s2, $s2, 1		# Increment counter
	j primeLoop

output: 
	la 	$a0, resultA		# "The total number of primes from 1 to "
	li 	$v0, 4			
	syscall
	
	lw 	$a0, usrNum		# Print user's range
	li 	$v0, 1			
	syscall
	
	la 	$a0, resultB		# " is "	
	li 	$v0, 4			
	syscall
	
	sw 	$s2, primeTally		# Store result in tally
	lw 	$a0, primeTally		# Print total prime numbers
	li 	$v0, 1			
	syscall

	li 	$v0, 10			# Exit program
	syscall
