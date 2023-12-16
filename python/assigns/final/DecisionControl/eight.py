userstr = input("Enter a string: ")
low_char_count=0
upp_char_count=0
dig_count=0
for char in userstr:
    if char.isdigit():
        dig_count +=1
    elif char.isupper():
        upp_char_count +=1
    elif char.islower():
        low_char_count +=1

print(f"No. of Uppercase Letters {upp_char_count}")
print(f"No. of Lowercase Letters {low_char_count}")
print(f"No. of Digits {dig_count}")
        
