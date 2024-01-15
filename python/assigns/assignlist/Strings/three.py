name = input("Enter Your Full Name: ")
firstspace = name.find(" ",0)
secondspace = name.find(" ",firstspace+1)
print("First Name: ",name[0:firstspace])
if secondspace != -1:
    print("Middle Name: ",name[firstspace+1:secondspace])
    print("Last Name: ",name[secondspace+1:])
else:
    print("Last Name: ",name[firstspace+1:])

print(f"Reversed Name: {name[::-1]}")

