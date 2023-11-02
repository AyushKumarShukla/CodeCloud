def fibo(n):
    if n==2:
        return 1
    elif n==1:
        return 0
    else:
        return fibo(n-1)+fibo(n-2)

terms=int(input("Enter the number of terms: "))
for i in range(1,terms+1):
    print(fibo(i))
