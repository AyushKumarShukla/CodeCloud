"""Write a program to enter an number and display its hex, octal and square root values"""
num=int(input("Enter a number in base 10: "))
output="Octal: {}, \nHex: {}, \nRoot: {}"
print(output.format(oct(num),hex(num),num**0.5))
