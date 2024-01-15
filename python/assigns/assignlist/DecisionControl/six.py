startday = int(input("Enter the start day of the month: "))
num = int(input("Enter the number of days in the month: "))
print("SUN\tMON\tTUE\tWED\tTHU\tFRI\tSAT")
for i in range(startday-1):
    print("\t",end="")
count=startday-1
for i in range(1,num+1):
    print(i,"\t",end="")
    count +=1
    if count>6:
        print()
        count=0
print()
