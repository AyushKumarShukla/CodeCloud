import math
def isPrime(num):
    if num==2:
        return True
    if num==0 or num==1:
        return False
    for i in range(2,math.ceil(math.sqrt(num))+1):
        if num % i == 0:
            return False
    return True

prime_cnt=0
comp_cnt=0
while True:
    inp = int(input("Enter a number: "))
    if inp == -1:
        print(f"Primes: {prime_cnt} ; Composites: {comp_cnt}")
        break
    if isPrime(inp):
        prime_cnt += 1
        print("prime:",inp)
    else:
        print("comp:",inp)
        comp_cnt += 1
        
