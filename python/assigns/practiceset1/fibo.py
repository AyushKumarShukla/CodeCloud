
terms=int(input("Enter the number of terms: "))
first=0
second=1
print(first,second,sep="\n")
for i in range(1,terms):
    third=first+second
    print(third,end="\n")
    first=second
    second=third
    
