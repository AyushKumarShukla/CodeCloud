usrval=int(input("Enter a number: "))
add=0
for i in range(1,usrval):
    if usrval%i==0:
        add+=i
if add == usrval:
    print(f"{usrval} is a perfect number")
else:
    print(f"{usrval} is NOT a perfect number")
    
