import random # Hashkey generator

a = {0:"0",1:"1",2:"2",3:"3",4:"4",5:"5",6:"6",7:"7",8:"8",9:"9",10:"a",11:"b",12:"c",13:"d",14:"e",15:"f",16:"g",17:"h",18:"i",19:"j",20:"k",21:"l",22:"m",23:"n",24:"p",25:"q",26:"r",27:"s",28:"t",29:"u",30:"v",31:"w",32:"x",33:"y",34:"z"}
b = int(input("Desired length: "))
c = ""

while len(c) < b:
	d = a[random.randrange(0,len(a))]
	# Possible capitalization
	if d.isalpha():
		e = random.randrange(1,4)
		if e == 1:
			d = d.upper()
	c += d
print("\n",c)																																								