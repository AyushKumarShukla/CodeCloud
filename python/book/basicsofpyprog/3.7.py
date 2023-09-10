"""
Demonstrate the use of relational operators
"""
a=int(input("Enter first number: "))
b=int(input("Enter second number: "))
out="A=B:{}\nA>B:{}\nA<B:{}\nA>=B:{}\nA<=B:{}\nA!=B:{}"
print(out.format(a==b,a>b,a<b,a>=b,a<=b,a!=b))


