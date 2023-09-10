"""
perform add,sub,mult,div,intdiv,moddiv on two floats
"""
a=float(input("Enter the first number: "))
b=float(input("Enter the second number: "))
out="SUM:{}\nDIFF:{}\nPROD:{}\nQUOT:{}\nFLOORQUOT:{}\nMOD:{}"
print(out.format(a+b,a-b,a*b,a/b,a//b,a%b))
