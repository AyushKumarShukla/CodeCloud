import math
import sys

def is_prime_1(num):
    start = 2
    end = math.floor(math.sqrt(num)) + 1
    for i in range(start,end):
        if num % i == 0 :
            return False
    return True

def is_prime_2(num):
    i = 2
    end = math.floor(math.sqrt(num)) + 1
    while i != end:
        if num % i == 0 :
            return False
        i += 1
    return True
    
num = int(sys.argv[1])
print(is_prime_1(num),is_prime_2(num))
