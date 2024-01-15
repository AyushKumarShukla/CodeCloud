seq = (59,45,67,83,23,91,12)
print("Iterable ",seq)

#the key keyword argument decides the values that will be taken into consideration when sorting
#logically, the given condition is used to sort the elements, but physically, the elements themselves
#are sorted in the ouput
greatest = max(seq,key=lambda i:i if i%2==0 else float('-inf'))
print("Largest even number: ",greatest)

smallest = min(seq,key = lambda i : i if i%2!=0 else float('inf'))
print("Smallest odd number: ",smallest)

addition = sum(seq)
print("Sum of all numbers = ",addition)
order=list(seq)
order.sort(key=lambda i:i%10)
print("Sorted list based on unit place: ",order)


