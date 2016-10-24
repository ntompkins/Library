import random
def main():
        i = str(input("What is your favourite color? "))
        test = random.randint(0,1)
        if test == 1:
            result = "you were telling the truth."
        elif test == 0:
            result = "that was a lie."
        print("You said your favorite color is ",i,". \nThe lie detector determined...\n",result,sep="")
main()