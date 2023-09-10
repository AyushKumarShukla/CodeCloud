"""
perform add,sub,mult,div,intdiv,moddiv on two integers
"""
a=int(input("Enter the first number: "))
b=int(input("Enter the second number: "))
out="SUM:{}\nDIFF:{}\nPROD:{}\nQUOT:{}\nFLOORQUOT:{}\nMOD:{}"
print(out.format(a+b,a-b,a*b,a/b,a//b,a%b))
