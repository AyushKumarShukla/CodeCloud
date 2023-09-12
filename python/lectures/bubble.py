"""
Bubble Sort program to sort a list of floating point numbers in ascending order
"""
seq=[]
size=int(input("Enter the number of elements in the array: "))

#List Input
for i in range(size):
    item=float(input("Enter the item: "))
    seq.append(item)

#Bubble Sort Algo
for i in range(size):
    for j in range(size-1-i):
        if(seq[j]>seq[j+1]):
            seq[j],seq[j+1]=seq[j+1],seq[j]
print("SORTED LIST: ",seq)
#CHECKPOINT

