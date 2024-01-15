def gcd(a,b):
    while a % b != 0:
        temp=b
        b=a%b
        a=temp
    return b

num1 = int(input("Enter the first number: "))
num2 = int(input("Enter the second number: "))

print("SUM: ",num1+num2)
print("DIFFERENCE: ",num1-num2)
print("PRODUCT: ",num1*num2)
print("GCD: ",gcd(num1,num2))


