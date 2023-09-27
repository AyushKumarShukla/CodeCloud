lines=int(input("Enter the number of lines in the pattern: "))
for i in range(lines):
	for j in range(lines):
		if(j in range(1,lines) and (i!=0 or i!=lines)):
			print(" ")
		else:
			print("* ")
