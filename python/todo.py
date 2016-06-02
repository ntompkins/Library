def main():
    quit = False
    while quit == False:
        menu()
        quitter()

def menu():
    valid = False
    while valid == False:
        print("Todo List Menu\n1) New todo\n2) Read todo list\n3) Mark todo")
        choice = str(input("Choice: "))
        # Act accordingly
        
        # New todo
        if choice == "1":
            # Open document
            LIST = open("todo_list.py","a")
            # Create loop to allow multiple entries
            end = False
            while end == False:
                new_item = str(input("New Todo: "))
                check = str(input("Add another? (y/n) ")).lower()
                if check == "y":
                    end = False
                else:
                    end = True
        else:
            print("Error.")
            valid = True
        
def quitter():
    choice = str(input("Quit? (y/n)")).lower()
    if choice == "y":
        quit()
    elif choice == "n":
        quit = False
        return quit
    else:
        print("Please try again.")
main()
