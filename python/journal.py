# Minimal Journal
import time
localtime = time.asctime(time.localtime(time.time()))
print("MNML JRNL\n========")
def main():
    passThrough = True
    while passThrough == True:
        title = str(input("Title: "))
        entry = str(input("Entry: "))
        database = open("entry.txt","a")
        fixed_entry = "\n"+title+"\t"+localtime+"\n________\n"+entry+"\n"
        database.write(fixed_entry)
        database.close()
        repeat = str(input("Submit another entry? (Y/N): ")).lower()
        if repeat == "y":
            passThrough = True
        else:
            passThrough = False
main()
print("Program closing...")
quit()
