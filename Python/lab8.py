# nathan_tompkins_lab8.py
# Nathan Tompkins | 11.16.15
# Date calculator

def main():
    # Program introduction
    print("Date calculator\n")
    # Create error counter that assumes one error
    errors = 1
    # Request information from user and loop
    while errors != 0:
        user = str(input("Enter a date in the format mm/dd/yy: "))
        ORIGINAL_STRING = user
        validate(user)
        rerun()
                
# Validate information
def validate(user):
    errors = 0

    # Attempt to clean string, else return an error
    try:
        split = user.split("/")
    except:
        errors = 1
        print("Error! The string could not be cleaned.")
        return errors

    # Check length of whole string
    counter = 0
    for d in split:
        counter+=1
    if counter > 3:
        print("Error! Your date is too long. Please only insert 2 digits for each section.")
        errors = 1
        return errors
    elif counter < 3:
        print("Error! Your date is too short. Please insert more information.")
        errors = 1
        return errors
    else:
        # Confirm that input is digits
        counter = 0
        for item in split[:]:
            counter+=1
            
            if item.isdigit():
                # Convert string to int to compare value
                item = int(item)
               
                # Verify value of month
                if counter == 1:
                    if item > 12 or item < 1:
                        errors = 1
                        print("Error! Please check the value of your month and try again.")
                        return errors
                    else:
                    
                        month = "*"
                        mode = 0
                        # Convert month
                        if item == 1:
                            month = "January"
                            mode = 31
                        
                        elif item == 2 :
                            month = "February"
                            mode = 28
                        
                        elif item == 3:
                            month = "March"
                            mode = 31
                        
                        elif item == 4:
                            month = "April"
                            mode = 30
                        
                        elif item == 5:
                            month = "May"
                            mode = 31
                        
                        elif item == 6:
                            month = "June"
                            mode = 30
                            
                        elif item == 7:
                            month = "July"
                            mode = 31
                        
                        elif item == 8:
                            month = "August"
                            mode = 31
                            
                        elif item == 9:
                            month = "September"
                            mode = 30
                        
                        elif item == 10:
                            month = "October"
                            mode = 31
                        
                        elif item == 11:
                            month = "November"
                            mode = 30
                            
                        elif item == 12:
                            month = "December"
                            mode = 31
                        
                        else:
                            month = "err"
                            mode = "err"
                
                # Verify value of days for month
                if counter == 2:
                    if item > mode:
                        errors = 1
                        print("Error!",month,"only has",mode,"days.")
                        return errors
                    
                    elif item <= 0:
                        errors = 1
                        print("Error! You must enter a value for the day.")
                        return errors
                    
                    else:
                        day = item
                
                if counter == 3:
                    if item != 2015 and item != 15:
                        errors = 1
                        print("Error! Your year is invalid. 2015 or 15 are the only acceptable values.")
                        return errors
                    else:
                        year = "2015"
                    
                    # Return results
                    print(month," ",day,", ",year,sep="")
                        
            else:
                errors = 1
                print("Error! Please make sure that your input is only whole numbers.")
                return errors

def rerun():
    # Continue menu
    confirm = False
    while confirm == False:
        choice = str(input("Would you like to convert another date? (y/n) ")).lower()
        if choice == "y":
            confirm == True
            return
        elif choice == "n":
            print("Program closing...")
            quit()
        else:
            print("Error, please try again.")
main()