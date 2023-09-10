"""
Calculate area of triangle using Heron's Formula:
a,b,c are the length of the sides
s=(a+b+c)/2
area=sqrt(s*(s-a)*(s-b)*(s-c)
"""
a=float(input("Enter the first side of the triange: "))
b=float(input("Enter the second side of the triange: "))
c=float(input("Enter the third side of the triange: "))
s=(a+b+c)/2
area=(s*(s-a)*(s-b)*(s-c))**0.5
print("Area Of Triangle: "+str(area))
