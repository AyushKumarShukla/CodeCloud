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

def primes_in_range(begin,end):
    for i in range(begin,end+1):
        if is_prime_1(i) and is_prime_2(i):
            print(i,end=" ")
    
begin = int(sys.argv[1])
end = int(sys.argv[2])
primes_in_range(begin,end)
print()
