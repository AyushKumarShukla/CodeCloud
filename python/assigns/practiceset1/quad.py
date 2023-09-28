#PROGRAM TO FIND ROOTS OF A QUADRATIC EQUATION

import cmath
def quad_roots(A,B,C):
	disc=cmath.sqrt((B**2)-4*A*C)
	#if(isinstance(disc,complex)):
	#	print("Imaginary Roots")
	#elif(disc==0):
	#	print("Equal Roots:")
	print("Disc",disc)
	root1=((-B+disc)/(2*A))
	root2=((-B-disc)/(2*A))
	return root1,root2

print("TO SOLVE A QUADRATIC EQUATION OF TYPE Ax^2 + Bx + C = 0")
A=float(input("Enter A: "))
B=float(input("Enter B: "))
C=float(input("Enter C: "))

root1,root2=quad_roots(A,B,C)
print(f"ROOTS: {root1},{root2}")
"""
OUTPUT
SET 1:
TO SOLVE A QUADRATIC EQUATION OF TYPE Ax^2 + Bx + C = 0
Enter A: 1
Enter B: 2
Enter C: 5
Disc 4j
ROOTS: (-1+2j),(-1-2j)

SET 2:
TO SOLVE A QUADRATIC EQUATION OF TYPE Ax^2 + Bx + C = 0
Enter A: 1
Enter B: 4
Enter C: 4
Disc 0j
ROOTS: (-2+0j),(-2+0j)

"""
