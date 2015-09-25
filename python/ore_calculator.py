rnd = int(input("ORE VALUE\nWhich round is it: "))

if rnd < 6:
    ore = str(input("Which ore would you like to calculate: ")).lower()

def results():
    print("Your points at initial value:",points)

if ore == "coal":
    x = float(input("How many pieces did you collect: "))
    points  = 6 * x
    results()
elif ore ==  "magnetite" or "iron":
    x = float(input("How many pieces did you collect: "))
    points = 7 * x
    results()
elif ore == "bauxite" or "aluminum":
    x = float(input("How many pieces did you collect: "))
    points = 10 * x
    results()
elif ore == "chalcopyrite" or "copper":
    x = float(input("How many pieces did you collect: "))
    points = 15 * x
    results()
elif ore == "spodumene" or "lithium":
    x = float(input("How many pieces did you collect: "))
    points = 25 * x
    results()
else:
    print("Please try again. That ore is invalid.")