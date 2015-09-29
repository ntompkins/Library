# Introduction to the program.
puts "This is a reference angle finder."
puts" "
# Our first question asks whether your angle is sin, cos, or tan, with 'sin', 'cos', and 'tan' becoming variables.
puts "To begin, is your starting angle sin, cos, or tan?"

# Designates your function as 'trig'
trig = gets.chomp

	# We begin with the 'sin' function. 
	if 	trig == 'sin'
		# After beginning with 'sin', we move to the value of the angle.
		puts "And what is the given angle?"
		angle = gets.chomp

		# This section determines the quadrant that the angle can be found in.
		if 		angle > '0' && angle < '90' # The 1st quadrant
				quadrant = gets.chomp
				
				quadrant == "Q = 1st,"
				quadrant = gets.chomp
				
		elsif 	
				angle > '90' && angle < '180'
				quadrant = gets.chomp
				quadrant = "Q = 2nd,"
		
		elsif	
				angle > '180' && angle < '270'
				quadrant = gets.chomp
				quadrant = "Q = 3rd,"
				
		else 	
				angle > '270' && angle < '360'
				quadrant = gets.chomp
				quadrant = "Q = 4th,"
		end

	elsif 
		trig == 'cos'
		puts "What is the angle?"
		angle = gets.chomp
		

	else 
		trig == 'tan'
		puts "What is the angle?"
		angle = gets.chomp

	
	end
