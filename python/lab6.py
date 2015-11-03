# Nathan Tompkins | 10.19.15
# nathan_tompkins_lab6.py
# Vending Machine

# Define function to use for each item in the vending machine, rather than define 6 separate modules
def item(snackname,cost): # Pass snackname and cost as arguments for each item

	# Print name, cost, and request confirmation of purchase
	print("\n",snackname,", cost: $",format(cost,"1.2f"),sep="")
	confirmation()

	# Payment checker and error managers
	pass_through = False
	while pass_through == False:
		money_in = 0
		if money_in != 1 or 2 or 3 or 4:
			money_in = float(input("Dollars to insert (1 - 4): "))
			print("Please enter whole bills between 1 and 4.")

		if money_in > 4:
			print("\nError, you inserted",format(money_in - cost,"2.2f"),"bills too many.")
			print(money_in,"bills returned")
			print("Please try again.\n")
		elif money_in < 1 and cost < money_in:
			print("\nError, you inserted",round(money_in + cost),"bills too few.")
		elif money_in < cost:
			print("Error, insufficient funds. Please enter more money or eject your change.")
			menu = int(input("1) Insert more money\n2) Eject change\n: "))
			if menu == 1:
				pass_through = False
			elif menu == 2:
				print("$",money_in," returned",sep="")
				repeat_all()
			else:
				print("Error, please try again.")
		else:
			pass_through = True

	# Dispense item
	print("\nDispensing your item now...")

	# Calulate change
	cash_back = money_in - cost

	# Add money_in and cash_back to the receipt
	receipt = "\nOrder Receipt\n-------------\nSnack name: %s\tCost: $%s\nAmount paid: $%s\tChange: $%s\n" % (snackname,cost,format(money_in,"1.2f"),format(cash_back,"1.2f"))
	print(receipt)

	repeat_all()

# Item confirmation
def confirmation():
	pass_through = False
	while pass_through == False:
		confirm = str(input("Confirm? (Y/N) ")).upper()

		if confirm == "Y":
			pass_through = True

		elif confirm =="N":
			pass_through = True
			main()
		else:
			print("Invalid option! Try again.")

# Repeat purchase process
def repeat_all():
	repeat = str(input("Would you like to purchase another item? (Y/N) ")).upper()

	pass_through = False
	while pass_through == False:
		if repeat == "Y":
			pass_through = True
			main()
		elif repeat == "N":
			pass_through = True
			print("Program ending...")
			quit()
		else:
			print("Error, please try again.")
def main():
	# List menu of snacks
	print("\nSnickers\t\tM&M\'s\t\t\tKitKat\nCost: $0.89\t\tCost: $1.39\t\tCost: $1.39\nA1\t\t\tA2\t\t\tA3")
	print("\nLays\t\t\tDoritos\t\t\tCheetos\nCost: $0.50\t\tCost: $0.50\t\tCost: $1.49\nB1\t\t\tB2\t\t\tB3")
	print("\nTicTac\t\t\tStarbursts\t\tSkittles\nCost: $1.04\t\tCost: $0.79\t\tCost: $2.49\nC1\t\t\tC2\t\t\tC3")

	# Menu outcomes
	choice = str(input("Enter snack code (0 to quit): ")).upper()

	pass_through = False
	while pass_through == False:
		# Quit path
		if choice == "0":
			pass_through = True
			print("Program ending...")
			quit()

		# Snickers, .89
		elif choice == "A1":
			pass_through = True
			snackname = "Snickers"
			cost = 0.89
			item(snackname,cost)
		# M&M's, 1.39
		elif choice == "A2":
			pass_through = True
			snackname = "M&M's"
			cost = 1.39
			item(snackname,cost)
		# KitKat, 1.39
		elif choice == "A3":
			pass_through = True
			snackname = "KitKat"
			cost = 1.39
			item(snackname,cost)
		# Lays, .50
		elif choice == "B1":
			pass_through = True
			snackname = "Lays"
			cost = 0.50
			item(snackname,cost)
		# Doritos, .50
		elif choice == "B2":
			pass_through = True
			snackname = "Doritos"
			cost = 0.50
			item(snackname,cost)
		# Cheetos, 1.49
		elif choice == "B3":
			pass_through = True
			snackname = "Cheetos"
			cost = 1.49
			item(snackname,cost)
		# TicTac, 1.04
		elif choice == "C1":
			pass_through = True
			snackname = "Tic-Tacs"
			cost = 1.04
			item(snackname,cost)
		# Starburst, .79
		elif choice == "C2":
			pass_through = True
			snackname = "Starbursts"
			cost = 0.79
			item(snackname,cost)
		# Skittles, 2.49
		elif choice == "C3":
			pass_through = True
			snackname = "Skittles"
			cost = 2.49
			item(snackname,cost)
		# Invalid input
		else:
			pass_through = True
			choice_error = True
			print("Error, invalid input. Try again.")

	if choice_error == True:
		repeat_all()
main()
