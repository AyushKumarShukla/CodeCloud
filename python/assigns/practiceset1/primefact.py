def isprime(val):
    for i in range(2,val):
        if val%i == 0:
            return False
    return True;

num=int(input("Enter the number: "))
fact=[]
for i in range(1,num+1):
    if num%i == 0 and isprime(i): #is a divisor and is prime = is a prime divisor
        fact.append(i)
print(fact)
        
