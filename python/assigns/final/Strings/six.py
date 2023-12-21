#import pdb
#pdb.set_trace() 
msg = input("Enter a message: ")
msg=msg.lower()
off=1
secret=""
for char in msg:
    #msg=msg.replace(char,chr(ord(char)+1))
    asc = ord(char)
    asc = asc + off
    mod = asc%122
    if mod<97:
        asc = (122-26)+mod
        if mod == 0:
            asc = 122
    asc = chr(asc)
    secret += asc

print("Original message",msg)
print("Secret word:",secret)
