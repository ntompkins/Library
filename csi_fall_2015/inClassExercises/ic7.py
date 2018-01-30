# nathan_tompkins_ic7.py
# Nathan Tompkins | 11.2.15

print("1 & 2)")
names = ['Einstein','Newton','Copernicus','Kepler']
pos = 0
for x in names:
    print(names[pos])
    pos += 1
    
print("3)")
contents = 0
numbers1 = [0]*100

while contents < 100:
    numbers1[contents] = contents + 1
    contents += 1
    
numbers2 = []
numbers2 += numbers1
print(numbers2)

print("5)")
def main():
    numbers = [2, 4, 6, 8, 10]
    total = 0
    
    for value in numbers:
        total += value
    print("The total of the elements is",total)
main()

print("6)")
ruby = str(input("Insert Ruby into the list? (y/n) ")).lower()
if ruby == "y":
    ruby = "Ruby"
else:
    ruby = ""
    
names = ["James","Tyler","Alexandria","Carl",ruby]
if "Ruby" in names:
    print("I found Ruby!")
else:
    print("I can't find Ruby!")

print("7)")

list1 = [40, 50, 60]
list2 = [10, 20, 30]
list3 = list1+list2
print(list3)
