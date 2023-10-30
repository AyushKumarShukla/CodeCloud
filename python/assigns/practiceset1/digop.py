num=input("Enter a number: ")
add=0
prod=1
for i in list(num):
    add+=int(i)
    prod*=int(i)
print(f"sum = {add}, product = {prod}")
