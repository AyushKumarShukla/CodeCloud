"""
find average and print deviation
"""

a=float(input("Enter the first number: "))
b=float(input("Enter the second number: "))
avg=(a+b)/2
dev1=avg-a
dev2=avg-b
out="Average:{}\nDeviation of {}:{}\nDeviation of {}:{}"
print(out.format(avg,a,-dev1,b,-dev2))

