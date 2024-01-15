import sys
seq = list(set([int(arg) for arg in sys.argv[1:]]))
print([int(arg) for arg in sys.argv[1:]])

first,second,third = 0,0,0

for i in range(1,len(seq)):
    if seq[i]>seq[first]:
        first,second,third = i,first,second
    elif seq[i]>seq[second]:
        first,second,third = first,i,second
    elif seq[i]>seq[third]:
        first,second,third = first,second,i
print(f"Third Largest Number: {seq[third]}")
        
